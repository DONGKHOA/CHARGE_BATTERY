/*
 * status_led.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "app_status_led.h"
#include "app_data_struct.h"
#include "scheduler.h"

#include "main.h"

#include "bsp_board.h"

/*********************
 *    PRIVATE TYPEDEFS
 *********************/

typedef struct _Status_Led_t
{
  CONTROL_STATE_t *p_status_led;
} Status_Led_t;

typedef struct _StatusLed_TaskContextTypedef_
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} StatusLed_TaskContextTypedef;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void APP_STATUS_LED_TaskUpdate(void);

/*********************
 *    PRIVATE DATA
 *********************/

static Status_Led_t                 s_status_led;
static StatusLed_TaskContextTypedef s_StatusLedTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,            // taskType;
            SCH_TASK_PRIO_2,          // taskPriority;
            100,                      // taskPeriodInMS;
            APP_STATUS_LED_TaskUpdate // taskFunction;
        } };

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
APP_STATUS_LED_Init (void)
{
  LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
  LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
  LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
  s_status_led.p_status_led
      = (CONTROL_STATE_t *)&s_control_llc_data.s_state_data;
}
void
APP_STATUS_LED_CreateTask (void)
{
  SCH_TASK_CreateTask(&s_StatusLedTaskContext.taskHandle,
                      &s_StatusLedTaskContext.taskProperty);
}

/********************
 *  PRIVATE FUNCTION
 ********************/

/**
 * @brief Updates the status of the LEDs based on the current system state.
 *
 * This function sets the status LEDs according to the current control state.
 * The LEDs provide a visual indication of the system's status:
 * - WAIT_INPUT_VOLTAGE: LED 1 ON, LED 2 OFF, LED 3 OFF
 * - SOFT_START: LED 1 OFF, LED 2 ON, LED 3 OFF
 * - DISCHARGING: LED 1 OFF, LED 2 OFF, LED 3 ON
 * - CHARGING: LED 1 OFF, LED 2 OFF, LED 3 TOGGLE with frequency 500Hz
 */
static void
APP_STATUS_LED_TaskUpdate (void)
{
  switch (*s_status_led.p_status_led)
  {
    case WAIT_INPUT_VOLTAGE:
      LL_GPIO_SetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      break;

    case SOFT_START:
      LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_SetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      break;

    case CHARGING:
    case WAIT_DISCHARGING:
      LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_TogglePin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      break;

    case DISCHARGING:
      LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_SetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      break;
    default:
      break;
  }
}
