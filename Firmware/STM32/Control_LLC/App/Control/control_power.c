/*
 * control_gate_driver.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_power.h"

#include "scheduler.h"
#include "data_struct.h"
#include "frequency_convert_pulse.h"
#include "voltage_convert_frequency.h"
#include "pi_control.h"
#include "board.h"
#include "device.h"
#include <stdlib.h>

/*********************
 *    PRIVATE DEFINES
 *********************/

#define TIME_LIMIT_PHASE_START 60 // ms
#define KI                     0.1
#define KP                     0.1
#define VOLTAGE_OUTPUT         48 // V
/*********************
 *    PRIVATE TYPEDEFS
 *********************/

typedef struct _Control_TaskContextTypedef_
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} Control_TaskContextTypedef;

typedef struct _Control_Power_t
{
	CONTROL_STATE_t *state;
  pi_control_t    *control_power_pi;
  pwm_cfg_t       *pwm_control_1;
  float            voltage;
  uint32_t         frequency_operation;
  uint8_t          times_change_fre;
} Control_Power_t;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void  APP_CONTROL_TaskUpdate(void);
static float APP_CONTROL_ConvertVoltageOutput(float voltage);

static void APP_CONTROL_ResetData(Control_Power_t *control_data)
{
  control_data->frequency_operation = 60000000;
  control_data->times_change_fre    = 0;
  control_data->voltage             = 0;
}

/*********************
 *    PRIVATE DATA
 *********************/

static Control_Power_t            s_control_power;
static Control_TaskContextTypedef s_ControlTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,     // taskType;
            SCH_TASK_PRIO_1,   // taskPriority;
            1,                 // taskPeriodInMS;
			APP_CONTROL_TaskUpdate // taskFunction;
        } };

/**********************
 *   PUBLIC DATA
 **********************/

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
APP_CONTROL_Init (void)
{
  // Link pointer to variable
  s_control_power.state            = &control_llc_data.state_data;
  s_control_power.control_power_pi = &control_llc_data.control_system;
  s_control_power.pwm_control_1    = &control_llc_data.control_gate;

  // Prepare data task control power
  s_control_power.state = CGT_WAIT_INPUT_VOLTAGE;

  s_control_power.control_power_pi->f_Ki       = KI;
  s_control_power.control_power_pi->f_Kp       = KP;
  s_control_power.control_power_pi->f_setPoint = VOLTAGE_OUTPUT;

  s_control_power.pwm_control_1->channel = GATE_DRIVER_TIM_CHANNEL;
  s_control_power.pwm_control_1->output  = GATE_DRIVER_TIM_MODE;
  s_control_power.pwm_control_1->p_tim   = GATE_DRIVER_TIM;

  APP_CONTROL_ResetData(&control_llc_data);

  BSP_PWM_EnableTimer(s_control_power.pwm_control_1);
  PIControl_Reset(s_control_power.control_power_pi);
}

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
      // Handle waiting for input voltage to be fit range 80V - 265V

      break;
    case CGT_SOFT_START:
      // Handle soft start initialization
      FCP_PhaseStart(s_control_power.times_change_fre);
      s_control_power.times_change_fre++;
      if (s_control_power.times_change_fre == TIME_LIMIT_PHASE_START)
      {
        *s_control_power.state = CGT_PROCESS;
      }
      break;
    case CGT_PROCESS:
      // Handle LLC output control

      // Read voltage from ADS1115
      float temp_voltage = ADS1115_Voltage(DEV_ADS1115_CHANNEL_0);

      // Convert from output voltage to input voltage (Circuit read ADC)
      s_control_power.voltage = APP_CONTROL_ConvertVoltageOutput(temp_voltage);

      // PI control
      PIControl_Process(s_control_power.voltage,
                        s_control_power.control_power_pi);

      // Voltage convert frequency
      s_control_power.frequency_operation
          = VCF_Process(s_control_power.control_power_pi->f_out);

      // Frequency convert pulse
      FCP_PhaseProcess(s_control_power.frequency_operation);
      break;
    default:
      break;
  }
}

static float
APP_CONTROL_ConvertVoltageOutput (float voltage)
{
  float temp_voltage;
  // Convert

  // Done
  return temp_voltage;
}
