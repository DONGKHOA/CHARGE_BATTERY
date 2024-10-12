/*
 * s_control_gate_driver.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "main.h"

#include "app_control_power.h"
#include "app_data_struct.h"

#include "scheduler.h"
#include "frequency_convert_pulse.h"
#include "voltage_convert_frequency.h"
#include "current_convert_frequency.h"
#include "pi_control.h"

#include "device.h"

#include "bsp_board.h"

/*********************
 *    PRIVATE DEFINES
 *********************/

#define TIME_LIMIT_PHASE_START 60 // 60ms=[Soft-start](55s)+[Operation-PI](5s)

#define KI_VOLTAGE 0.1f
#define KP_VOLTAGE 0.1f
#define VOLTAGE_START_THRESHOLD
#define VOLTAGE_END_THRESHOLD 58.0f

#define KI_CURRENT              0.1f
#define KP_CURRENT              0.1f
#define CURRENT_START_THRESHOLD 6.0f
#define CURRENT_END_THRESHOLD   0.1f

#define ADS1115_CURRENT_CHANNEL DEV_ADS1115_CHANNEL_1
#define ADS1115_VOLTAGE_CHANNEL DEV_ADS1115_CHANNEL_2

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
 * PI control configuration, PWM configuration, voltage, frequency of operation,
 * and the number of times the frequency has changed.
 */
typedef struct _Control_Power_t
{
  CONTROL_STATE_t *p_state;
  pi_control_t    *p_control_voltage;
  pi_control_t    *p_control_current;
  pwm_cfg_t       *p_pwm_control_1;
  float           *p_output_current;
  float           *p_output_voltage;
  uint32_t         u32_frequency_operation;
  uint8_t          u32_times_change_fre;
} Control_Power_t;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void APP_CONTROL_TaskUpdate(void);
static void APP_CONTROL_CCCVChager(void);
static void APP_CONTROL_ConvertVoltageOutput(void);
static void APP_CONTROL_ResetData(void);
// static void APP_CONTROL_RelayOn(void);
// static void APP_CONTROL_RelayOff(void);

/*********************
 *    PRIVATE DATA
 *********************/

static Control_Power_t            s_control_power;
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
  s_control_power.p_state = (CONTROL_STATE_t *)&s_control_llc_data.s_state_data;
  s_control_power.p_control_voltage
      = (pi_control_t *)&s_control_llc_data.s_control_voltage;
  s_control_power.p_control_current
      = (pi_control_t *)&s_control_llc_data.s_control_current;
  s_control_power.p_pwm_control_1
      = (pwm_cfg_t *)&s_control_llc_data.s_control_gate;
  s_control_power.p_output_voltage
      = (float *)&s_control_llc_data.f_output_voltage;
  s_control_power.p_output_current
      = (float *)&s_control_llc_data.f_output_current;

  // Prepare data task control power
  *s_control_power.p_state = WAIT_INPUT_VOLTAGE;

  // Initialize PI control parameters of control voltage
  s_control_power.p_control_voltage->f_Ki       = KI_VOLTAGE;
  s_control_power.p_control_voltage->f_Kp       = KP_VOLTAGE;
  s_control_power.p_control_voltage->f_setPoint = VOLTAGE_END_THRESHOLD;

  // Initialize PI control parameters of control current
  s_control_power.p_control_current->f_Ki       = KI_CURRENT;
  s_control_power.p_control_current->f_Kp       = KP_CURRENT;
  s_control_power.p_control_current->f_setPoint = CURRENT_START_THRESHOLD;

  // Initialize PWM control parameters
  s_control_power.p_pwm_control_1->channel = PWM_CHANNEL_1;
  s_control_power.p_pwm_control_1->output  = PWM_POSITIVE_NEGATIVE;
  s_control_power.p_pwm_control_1->p_tim   = TIM1;

  // Reset control data
  APP_CONTROL_ResetData();

  // Enable PWM timer
  BSP_PWM_EnableTimer(s_control_power.p_pwm_control_1);

  // Reset PI control
  PIControl_Reset(s_control_power.p_control_voltage);
  PIControl_Reset(s_control_power.p_control_current);
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
 * - WAIT_INPUT_VOLTAGE: Wait for the input voltage to fit the system.
 * - SOFT_START: Initialize LLC.
 * - DISCHARGING: Discharging charger.
 * - CHARGING: Charging charger.
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
  switch (*s_control_power.p_state)
  {
    case WAIT_INPUT_VOLTAGE:
      break;
    case SOFT_START:
      // Handle soft start initialization
      FCP_PhaseStart(s_control_power.u32_times_change_fre);
      if (s_control_power.u32_times_change_fre == TIME_LIMIT_PHASE_START)
      {
        s_control_power.u32_times_change_fre = 0;
        *s_control_power.p_state             = DISCHARGING;
      }
      s_control_power.u32_times_change_fre++;

      break;
    case DISCHARGING:
      break;
    case CHARGING:

      // Progress of charging
      if (s_control_power.u32_times_change_fre == CONTROL_PI_TIME_SAMPLE)
      {
        APP_CONTROL_CCCVChager();
        s_control_power.u32_times_change_fre = 0;
      }
      s_control_power.u32_times_change_fre++;

      // Check
      if
      {
        break;
      }
    default:
      break;
  }
}

static void
APP_CONTROL_CCCVChager (void)
{
  // Read voltage feedback
  *s_control_power.p_output_voltage = ADS1115_Voltage(ADS1115_VOLTAGE_CHANNEL);
  APP_CONTROL_ConvertVoltageOutput();

  // If voltage feedback <= VOLTAGE REFERENCE System in mode CC
  // If voltage feedback > VOLTAGE REFERENCE System in mode CV

  if (*s_control_power.p_output_voltage <= VOLTAGE_END_THRESHOLD)
  {
    // Read voltage channel current
    float value_temp = ADS1115_Voltage(ADS1115_CURRENT_CHANNEL);

    // Convert from voltage channel current to current
    *s_control_power.p_output_current
        = ACS712_CurrentConverterVoltage(value_temp);

    // PI control
    PIControl_Process(*s_control_power.p_output_current,
                      s_control_power.p_control_current);

    // Current convert frequency
    s_control_power.u32_frequency_operation
        = CCF_Process(s_control_power.p_control_current->f_out);

    // Frequency convert pulse
    FCP_PhaseProcess(s_control_power.u32_frequency_operation);
  }
  else
  {
    // PI control
    PIControl_Process(*s_control_power.p_output_voltage,
                      s_control_power.p_control_voltage);

    // Voltage convert frequency
    s_control_power.u32_frequency_operation
        = VCF_Process(s_control_power.p_control_voltage->f_out);

    // Frequency convert pulse
    FCP_PhaseProcess(s_control_power.u32_frequency_operation);
  }
}

static void
APP_CONTROL_ConvertVoltageOutput (void)
{
  float value_temp                  = *s_control_power.p_output_voltage;
  *s_control_power.p_output_voltage = (value_temp / 3.09 + 3.3) * 13;
}

/**
 * The function `APP_CONTROL_ResetData` resets certain data values related to
 * power control.
 */
static void
APP_CONTROL_ResetData (void)
{
  s_control_power.u32_frequency_operation = 60000000;
  s_control_power.u32_times_change_fre    = 0;
  *s_control_power.p_output_voltage       = 0;
}
