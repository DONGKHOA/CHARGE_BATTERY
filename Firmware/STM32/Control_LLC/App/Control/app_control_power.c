/*
 * s_control_gate_driver.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "bsp_board.h"
#include "app_control_power.h"

#include "scheduler.h"
#include "app_data_struct.h"
#include "frequency_convert_pulse.h"
#include "voltage_convert_frequency.h"
#include "pi_control.h"
#include "device.h"
#include <stdlib.h>

/*********************
 *    PRIVATE DEFINES
 *********************/

#define TIME_LIMIT_PHASE_START 60 // 60ms=[Soft-start](55s)+[Operation-PI](5s)
#define KI                     0.1
#define KP                     0.1
#define VOLTAGE_OUTPUT         48 // V

#define NUMBER_CHANNEL_ADC            1
#define START_THRESHOLD_INPUT_VOLTAGE 85
#define END_THRESHOLD_INPUT_VOLTAGE   85
#define STORAGE_INPUT_VOLTAGE         s_control_power.s_adc1.p_adc_voltage_data[0]

/*********************
 *    PRIVATE TYPEDEFS
 *********************/

typedef struct _Control_TaskContextTypedef_
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} Control_TaskContextTypedef;

/**
 * @brief Control power data structure.
 *
 * This structure holds various configuration and control parameters
 * for the power control system. It includes state information,
 * PI control configuration, PWM configuration, ADC data,
 * voltage, frequency of operation, and the number of times the
 * frequency has changed.
 */
typedef struct _Control_Power_t
{
  /**
   * @brief Pointer to the current state of the control system.
   *
   * This points to the current state of the power control system.
   */
  CONTROL_STATE_t *state;

  /**
   * @brief Pointer to the PI control configuration.
   *
   * This points to the PI control structure used for regulating
   * the power output.
   */
  pi_control_t *control_power_pi;

  /**
   * @brief Pointer to the PWM configuration.
   *
   * This points to the PWM configuration structure used for controlling
   * the power gate.
   */
  pwm_cfg_t *pwm_control_1;

  /**
   * @brief ADC configuration data.
   *
   * This structure holds the ADC configuration and data used
   * for measuring input voltage.
   */
  adc_data_t s_adc1;

  /**
   * @brief Voltage measurement.
   *
   * The measured output voltage.
   */
  float* f_output_voltage;

  /**
   * @brief Frequency of operation.
   *
   * The operating frequency of LLC.
   */
  uint32_t frequency_operation;

  /**
   * @brief Number of times the frequency has changed.
   *
   * This keeps track of times the frequency has been adjusted in the state is
   * set 'CGT_SOFT_START'.
   */
  uint8_t times_change_fre;

} Control_Power_t;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void  APP_CONTROL_TaskUpdate(void);
static float APP_CONTROL_ConvertVoltageOutput(float voltage);
static void  APP_CONTROL_ResetData(void);
static void  APP_CONTROL_ReadVoltageInput(void);
static void  APP_CONTROL_EnablePFC(void);
static void  APP_CONTROL_DisablePFC(void);

/*********************
 *    PRIVATE DATA
 *********************/

static Control_Power_t            s_control_power;
static uint32_t                   adc_data[NUMBER_CHANNEL_ADC]         = { 0 };
static float                      adc_voltage_data[NUMBER_CHANNEL_ADC] = { 0 };
static Control_TaskContextTypedef s_ControlTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,         // taskType;
            SCH_TASK_PRIO_1,       // taskPriority;
            1,                     // taskPeriodInMS;
            APP_CONTROL_TaskUpdate // taskFunction;
        } };

/**********************
 *   PUBLIC DATA
 **********************/

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Initializes the control system for the application.
 *
 * This function sets up the initial configuration for the control system,
 * including linking pointers to the control data structures, initializing
 * PI control parameters, PWM configuration, ADC configuration, and resetting
 * relevant data.
 */
void
APP_CONTROL_Init (void)
{
  // Link pointer to variable
  s_control_power.state = (CONTROL_STATE_t *)&s_control_llc_data.s_state_data;
  s_control_power.control_power_pi
      = (pi_control_t *)&s_control_llc_data.s_control_system;
  s_control_power.pwm_control_1
      = (pwm_cfg_t *)&s_control_llc_data.s_control_gate;
  s_control_power.f_output_voltage = (float *)&s_control_llc_data.f_output_voltage;
  // Prepare data task control power
  s_control_power.state = CGT_WAIT_INPUT_VOLTAGE;

  // Initialize PI control parameters
  s_control_power.control_power_pi->f_Ki       = KI;
  s_control_power.control_power_pi->f_Kp       = KP;
  s_control_power.control_power_pi->f_setPoint = VOLTAGE_OUTPUT;

  // Initialize PWM control parameters
  s_control_power.pwm_control_1->channel = GATE_DRIVER_TIM_CHANNEL;
  s_control_power.pwm_control_1->output  = GATE_DRIVER_TIM_MODE;
  s_control_power.pwm_control_1->p_tim   = GATE_DRIVER_TIM;

  // Initialize ADC configuration
  s_control_power.s_adc1.p_ADCx             = INPUT_VOTAGE_ADC;
  s_control_power.s_adc1.u32_num_channel    = NUMBER_CHANNEL_ADC;
  s_control_power.s_adc1.p_adc_data         = &adc_data[0];
  s_control_power.s_adc1.p_adc_voltage_data = &adc_voltage_data[0];

  // Reset control data and disable PFC
  APP_CONTROL_ResetData();
  APP_CONTROL_DisablePFC();

  // Configure ADC and enable PWM timer
  BSP_ADC_Config(&s_control_power.s_adc1);
  BSP_PWM_EnableTimer(s_control_power.pwm_control_1);

  // Reset PI control
  PIControl_Reset(s_control_power.control_power_pi);
}

/**
 * @brief Creates the control task for the scheduler.
 *
 * This function creates a control task using the scheduler's task creation
 * function, initializing the task handle and task properties.
 */
void
APP_CONTROL_CreateTask (void)
{
  SCH_TASK_CreateTask(&s_ControlTaskContext.taskHandle,
                      &s_ControlTaskContext.taskProperty);
}

/********************
 *  PRIVATE FUNCTION
 ********************/

/**
 * @brief State machine with 3 states:
 * - CGT_WAIT_INPUT_VOLTAGE: Wait for the input voltage to fit the system.
 * - CGT_SOFT_START: Initialize LLC.
 * - CGT_PROCESS: Control the output LLC.
 *
 * After initialization, the state is set to CGT_WAIT_INPUT_VOLTAGE, which means
 * the system is waiting for the input voltage to be within the range of 85V -
 * 265V.
 *
 * If the input voltage is within the specified range, the state will change to
 * CGT_SOFT_START. After completing the CGT_SOFT_START state, the state will
 * change to CGT_PROCESS.
 */
static void
APP_CONTROL_TaskUpdate (void)
{
  switch (*s_control_power.state)
  {
    case CGT_WAIT_INPUT_VOLTAGE:
      // Waiting for input voltage to be fit range 80V - 265V
      APP_CONTROL_ReadVoltageInput();

      if ((STORAGE_INPUT_VOLTAGE > START_THRESHOLD_INPUT_VOLTAGE)
          && (STORAGE_INPUT_VOLTAGE < END_THRESHOLD_INPUT_VOLTAGE))
      {
        APP_CONTROL_EnablePFC();
        s_control_power.times_change_fre = 0;
        *s_control_power.state           = CGT_SOFT_START;
      }
      break;
    case CGT_SOFT_START:
      // Handle soft start initialization
      FCP_PhaseStart(s_control_power.times_change_fre);
      if (s_control_power.times_change_fre == TIME_LIMIT_PHASE_START)
      {
        s_control_power.times_change_fre = 0;
        *s_control_power.state           = CGT_PROCESS;
      }
      s_control_power.times_change_fre++;

      // Check voltage input
      APP_CONTROL_ReadVoltageInput();
      if ((STORAGE_INPUT_VOLTAGE < START_THRESHOLD_INPUT_VOLTAGE)
          && (STORAGE_INPUT_VOLTAGE > END_THRESHOLD_INPUT_VOLTAGE))
      {
        APP_CONTROL_DisablePFC();
        *s_control_power.state = CGT_WAIT_INPUT_VOLTAGE;
      }
      break;
    case CGT_PROCESS:
      if (s_control_power.times_change_fre == CONTROL_PI_TIME_SAMPLE)
      {
        // Read voltage from ADS1115
        float temp_voltage = ADS1115_Voltage(DEV_ADS1115_CHANNEL_0);

        // Convert from output voltage to input voltage (Circuit read ADC)
        *s_control_power.f_output_voltage
            = APP_CONTROL_ConvertVoltageOutput(temp_voltage);

        // PI control
        PIControl_Process(*s_control_power.f_output_voltage,
                          s_control_power.control_power_pi);

        // Voltage convert frequency
        s_control_power.frequency_operation
            = VCF_Process(s_control_power.control_power_pi->f_out);

        // Frequency convert pulse
        FCP_PhaseProcess(s_control_power.frequency_operation);

        s_control_power.times_change_fre = 0;
      }
      s_control_power.times_change_fre++;

      // Check voltage input
      APP_CONTROL_ReadVoltageInput();
      if ((STORAGE_INPUT_VOLTAGE < START_THRESHOLD_INPUT_VOLTAGE)
          && (STORAGE_INPUT_VOLTAGE > END_THRESHOLD_INPUT_VOLTAGE))
      {
        APP_CONTROL_DisablePFC();
        *s_control_power.state = CGT_WAIT_INPUT_VOLTAGE;
      }
      break;
    default:
      break;
  }
}

static float
APP_CONTROL_ConvertVoltageOutput (float voltage)
{
  float temp_voltage;
  float max_voltage = 54; // Range 43.2V -> 52.8V
  // Convert
  temp_voltage = (voltage * max_voltage) / ADS1115_VREF;
  // Done
  return temp_voltage;
}

static void
APP_CONTROL_ResetData (void)
{
  s_control_power.frequency_operation = 60000000;
  s_control_power.times_change_fre    = 0;
  *s_control_power.f_output_voltage             = 0;
}

static void
APP_CONTROL_ReadVoltageInput (void)
{
//  BSP_ADC_StartConvert(&s_control_power.s_adc1);
//  BSP_ADC_WaitConversion(&s_control_power.s_adc1);
//  if (s_control_power.s_adc1.e_status == BSP_ADC_OK)
//  {
//    BSP_ADC_Read(&s_control_power.s_adc1);
//  }
}

static void
APP_CONTROL_EnablePFC (void)
{
}

static void
APP_CONTROL_DisablePFC (void)
{
}
