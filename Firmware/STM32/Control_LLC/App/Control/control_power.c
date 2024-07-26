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
#include "frequency_convert_pulse.h"
#include "voltage_convert_frequency.h"
#include "pi_control.h"
#include "board.h"
#include "device.h"
#include <stdlib.h>

/*********************
 *    PRIVATE DEFINES
 *********************/

#define TIME_LIMIT_PHASE_START  60  //ms
#define KI                      0.1
#define KP                      0.1
#define VOLTAGE_OUTPUT          48  // V
/*********************
 *    PRIVATE TYPEDEFS
 *********************/

typedef struct _Control_TaskContextTypedef_
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} Control_TaskContextTypedef;

typedef enum
{
  CGT_WAIT_INPUT_VOLTAGE = 0,
  CGT_SOFT_START,
  CGT_PROCESS
} state_control_t;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void CONTROL_TaskUpdate(void);
static float CONTROL_ConvertVoltageOutput(float voltage);

/*********************
 *    PRIVATE DATA
 *********************/

static volatile state_control_t            state;
static volatile uint8_t times_change_fre = 0;
static volatile float voltage; 
static volatile uint32_t frequency_operation = 0;
static volatile pi_control_t control_power_pi = 
{
  .f_Ki = KI,
  .f_Kp = KP,
  .f_setPoint = VOLTAGE_OUTPUT
};
static Control_TaskContextTypedef s_ControlTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,     // taskType;
            SCH_TASK_PRIO_1,   // taskPriority;
            1,                 // taskPeriodInMS;
            CONTROL_TaskUpdate // taskFunction;
        } };

/**********************
 *   PUBLIC DATA
 **********************/

pwm_cfg_t pwm_control_1 = {
  .channel = GATE_DRIVER_TIM_CHANNEL,
  .output  = GATE_DRIVER_TIM_MODE,
  .p_tim   = GATE_DRIVER_TIM,
};

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
CONTROL_Init (void)
{
  PWM_EnableTimer(&pwm_control_1);
  state = CGT_WAIT_INPUT_VOLTAGE;
  times_change_fre = 0;
  PIControl_Reset((pi_control_t *)&control_power_pi);
}

void
CONTROL_CreateTask (void)
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
CONTROL_TaskUpdate (void)
{
  switch (state)
  {
    case CGT_WAIT_INPUT_VOLTAGE:
      // Handle waiting for input voltage to be fit range 80V - 265V
      
      break;
    case CGT_SOFT_START:
      // Handle soft start initialization
      FCP_PhaseStart(times_change_fre);
      times_change_fre++;
      if (times_change_fre == TIME_LIMIT_PHASE_START)
      {
        state = CGT_PROCESS;
      }
      break;
    case CGT_PROCESS:
      // Handle LLC output control

      // Read voltage from ADS1115
      float temp_voltage = ADS1115_Voltage(DEV_ADS1115_CHANNEL_0);

      // Convert from output voltage to input voltage (Circuit read ADC) 
      voltage = CONTROL_ConvertVoltageOutput (temp_voltage);

      // PI control
      PIControl_Process(voltage, (pi_control_t *)&control_power_pi);

      // Voltage convert frequency
      frequency_operation = VCF_Process(control_power_pi.f_out);

      // Frequency convert pulse
      FCP_PhaseProcess(frequency_operation);
      break;
    default:
      break;
  }
}

static float CONTROL_ConvertVoltageOutput(float voltage)
{
  float temp_voltage;
  // Convert

  // Done
  return temp_voltage;
}
