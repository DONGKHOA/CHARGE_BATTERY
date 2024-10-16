/*
 * app_control.c
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

#define TIME_LIMIT_STOP_CHARGING 30000 // 5 minute
#define TIME_LIMIT_PHASE_START   60 // 60ms=[Soft-start](55s)+[Operation-PI](5s)

#define KI_VOLTAGE 0.1f
#define KP_VOLTAGE 0.1f

#define KI_CURRENT 0.1f
#define KP_CURRENT 0.1f

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
static void APP_CONTROL_ConvertVoltageOutput(void);
static void APP_CONTROL_ResetData(void);
static void APP_CONTROL_RelayOn(void);
static void APP_CONTROL_RelayOff(void);

/*********************
 *    PRIVATE DATA
 *********************/

static Control_Power_t            s_control_power;
static uint16_t                   u16_time_wait_discharging = 0;
static Control_TaskContextTypedef s_ControlTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,         // taskType;
            SCH_TASK_PRIO_0,       // taskPriority;
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
  // Turn Off Relay
  APP_CONTROL_RelayOff();

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
 * The function `APP_CONTROL_TaskUpdate` implements a state machine for
 * controlling a power system with different charging modes and transitions.
 */
static void
APP_CONTROL_TaskUpdate (void)
{
  switch (*s_control_power.p_state)
  {
    case WAIT_INPUT_VOLTAGE:

      APP_CONTROL_RelayOn();
      *s_control_power.p_state = DISCHARGING;
      break;
    case SOFT_START:

      // Handle soft start initialization
      FCP_PhaseStart(s_control_power.u32_times_change_fre);
      if (s_control_power.u32_times_change_fre == TIME_LIMIT_PHASE_START)
      {
        s_control_power.u32_times_change_fre = 0;
        *s_control_power.p_state             = CC_MODE_CHARGING;
      }
      s_control_power.u32_times_change_fre++;

      break;
    case CC_MODE_CHARGING:

      // Progress of charging
      if (s_control_power.u32_times_change_fre == CONTROL_PI_TIME_SAMPLE)
      {
        // Read voltage channel current
        float value_temp = ADS1115_ReadVoltage(ADS1115_CURRENT_CHANNEL);

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
        s_control_power.u32_times_change_fre = 0;
      }
      s_control_power.u32_times_change_fre++;

      // Read voltage feedback
      *s_control_power.p_output_voltage
          = ADS1115_ReadVoltage(ADS1115_VOLTAGE_CHANNEL);
      APP_CONTROL_ConvertVoltageOutput();

      if (*s_control_power.p_output_voltage > VOLTAGE_END_THRESHOLD)
      {
        if(*s_control_power.p_output_current >= CURRENT_END_THRESHOLD)
        {
          *s_control_power.p_state             = CV_MODE_CHARGING;
          s_control_power.u32_times_change_fre = 0;
        }
        else
        {
          *s_control_power.p_state             = WAIT_UNPLUGGED;
          s_control_power.u32_times_change_fre = 0;
        }
      }
      break;
    case CV_MODE_CHARGING:

      // Progress of charging
      if (s_control_power.u32_times_change_fre == CONTROL_PI_TIME_SAMPLE)
      {
        // PI control
        PIControl_Process(*s_control_power.p_output_voltage,
                          s_control_power.p_control_voltage);

        // Voltage convert frequency
        s_control_power.u32_frequency_operation
            = VCF_Process(s_control_power.p_control_voltage->f_out);

        // Frequency convert pulse
        FCP_PhaseProcess(s_control_power.u32_frequency_operation);
        s_control_power.u32_times_change_fre = 0;
      }
      s_control_power.u32_times_change_fre++;

      // If the charging current <= CURRENT_END_THRESHOLD, wait for 5 minutes,
      // then switch to discharging
      if (*s_control_power.p_output_current <= CURRENT_END_THRESHOLD)
      {
        u16_time_wait_discharging            = TIME_LIMIT_STOP_CHARGING;
        s_control_power.u32_times_change_fre = 0;
        *s_control_power.p_state             = WAIT_DISCHARGING;
      }
      break;

    case WAIT_DISCHARGING:

      // wait for 5 minutes
      if (u16_time_wait_discharging == 0)
      {
        // Turn off PWM
        BSP_PWM_DisableTimer(s_control_power.p_pwm_control_1);
        *s_control_power.p_state = WAIT_UNPLUGGED;
      }
      break;

    case WAIT_UNPLUGGED:

      // Read voltage feedback
      *s_control_power.p_output_voltage
          = ADS1115_ReadVoltage(ADS1115_VOLTAGE_CHANNEL);
      APP_CONTROL_ConvertVoltageOutput();

      if (*s_control_power.p_output_voltage < VOLTAGE_START_THRESHOLD)
      {
        // Turn on PWM
        BSP_PWM_EnableTimer(s_control_power.p_pwm_control_1);

        s_control_power.u32_times_change_fre = 0;
        *s_control_power.p_state             = DISCHARGING;
      }
      break;

    case DISCHARGING:

      // Read voltage feedback
      *s_control_power.p_output_voltage
          = ADS1115_ReadVoltage(ADS1115_VOLTAGE_CHANNEL);
      APP_CONTROL_ConvertVoltageOutput();

      if (*s_control_power.p_output_voltage >= VOLTAGE_START_THRESHOLD)
      {
        // Turn on PWM
        BSP_PWM_EnableTimer(s_control_power.p_pwm_control_1);

        s_control_power.u32_times_change_fre = 0;
        *s_control_power.p_state             = SOFT_START;
      }
      break;
    default:
      break;
  }
}

/**
 * The function `APP_CONTROL_TimeWaitDischarging` decrements the variable
 * `u16_time_wait_discharging` if it is greater than 0.
 */
void
APP_CONTROL_TimeWaitDischarging (void)
{
  if (u16_time_wait_discharging > 0)
  {
    u16_time_wait_discharging--;
  }
}

/**
 * The function `APP_CONTROL_ConvertVoltageOutput` converts the output voltage
 * value using a specific formula.
 */
static void
APP_CONTROL_ConvertVoltageOutput (void)
{
  float value_temp                  = *s_control_power.p_output_voltage;
  *s_control_power.p_output_voltage = (value_temp / 3.09 + 3.3) * 13;
}

/**
 * The function `APP_CONTROL_RelayOn` turns on a relay by resetting the output
 * pin of a specific GPIO port.
 */
static void
APP_CONTROL_RelayOn (void)
{
  LL_GPIO_ResetOutputPin(VOLTAGE_PROTECTION_GPIO_Port, VOLTAGE_PROTECTION_Pin);
}

/**
 * The function `APP_CONTROL_RelayOff` turns off a relay by setting a specific
 * GPIO pin to a high voltage level.
 */
static void
APP_CONTROL_RelayOff (void)
{
  LL_GPIO_SetOutputPin(VOLTAGE_PROTECTION_GPIO_Port, VOLTAGE_PROTECTION_Pin);
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
