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
  uint8_t          u8_state_all_led : 1;
  uint8_t          u8_flag_enable_timer_100ms : 1;
  uint8_t          u8_flag_enable_timer_500ms : 1;
} __attribute__((packed)) Status_Led_t;

typedef struct _StatusLed_TaskContextTypedef
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} StatusLed_TaskContextTypedef;

typedef struct STATUS_LED_TimerContextTypedef_
{
  SCH_TIMER_HANDLE         timerHandle;
  SCH_TimerPropertyTypedef timerProperty;
} STATUS_LED_TimerContextTypedef_t;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void APP_STATUS_LED_TaskUpdate(void);
static void APP_STATUS_LED_100MS_TimerUpdate(void);
static void APP_STATUS_LED_500MS_TimerUpdate(void);

/*********************
 *    PRIVATE DATA
 *********************/

static Status_Led_t                 s_status_led;
static StatusLed_TaskContextTypedef s_StatusLedTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,            // taskType;
            500,                      // taskPeriodInMS;
            APP_STATUS_LED_TaskUpdate // taskFunction;
        } };

static STATUS_LED_TimerContextTypedef_t s_StatusLedTimerContext[2]
    = { { SCH_INVALID_TIMER_HANDLE, // Will be updated by Scheduler
          {
              SCH_TIMER_PERIODIC,              // timerType;
              100,                             // timerPeriodInMS;
              APP_STATUS_LED_100MS_TimerUpdate // timerCallbackFunction;
          } },

        { SCH_INVALID_TIMER_HANDLE, // Will be updated by Scheduler
          {
              SCH_TIMER_PERIODIC,              // timerType;
              500,                             // timerPeriodInMS;
              APP_STATUS_LED_500MS_TimerUpdate // timerCallbackFunction;
          } } };

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * The function initializes status LEDs by resetting GPIO pins, linking a
 * pointer to a variable, and resetting fields in a structure.
 */
void
APP_STATUS_LED_Init (void)
{
  // Reset GPIO
  LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
  LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
  LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);

  // Link pointer to variable
  s_status_led.p_status_led
      = (CONTROL_STATE_t *)&s_control_llc_data.s_state_data;

  // Reset field of s_status_led
  s_status_led.u8_state_all_led           = 0;
  s_status_led.u8_flag_enable_timer_100ms = 0;
  s_status_led.u8_flag_enable_timer_500ms = 0;
}

/**
 * The function `APP_STATUS_LED_CreateTimer` creates timers for status LED
 * handling.
 */
void
APP_STATUS_LED_CreateTimer (void)
{
  SCH_TIM_CreateTimer(&s_StatusLedTimerContext[0].timerHandle,
                      &s_StatusLedTimerContext[0].timerProperty);
  SCH_TIM_CreateTimer(&s_StatusLedTimerContext[1].timerHandle,
                      &s_StatusLedTimerContext[1].timerProperty);
}

/**
 * The function APP_STATUS_LED_CreateTask creates a task for the status LED.
 */
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
 * @brief Updates the status of LEDs based on the current charging or
 * discharging mode.
 *
 * This function manages the state of LEDs according to the defined operational
 * modes.
 *
 * - **WAIT_INPUT_VOLTAGE**, **SOFT_START**: All LEDs are OFF.
 * - **DISCHARGING**: All LEDs are ON.
 * - **CC_MODE_CHARGING**: LED 1 toggles every 500 ms, others remain OFF.
 * - **CV_MODE_CHARGING**: LED 2 toggles every 500 ms, others remain OFF.
 * - **WAIT_DISCHARGING**: LED 3 toggles every 500 ms, others remain OFF.
 * - **WAIT_UNPLUGGED**: All LEDs toggle every 100 ms.
 */
static void
APP_STATUS_LED_TaskUpdate (void)
{
  switch (*s_status_led.p_status_led)
  {
    case WAIT_INPUT_VOLTAGE:
    case SOFT_START:
      LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      s_status_led.u8_state_all_led = 0;
      SCH_TIM_StopTimer(s_StatusLedTimerContext[0].timerHandle);
      SCH_TIM_StopTimer(s_StatusLedTimerContext[1].timerHandle);
      break;

    case CC_MODE_CHARGING:
    case CV_MODE_CHARGING:
    case WAIT_DISCHARGING:
      if (s_status_led.u8_flag_enable_timer_500ms == 0)
      {
        SCH_TIM_StopTimer(s_StatusLedTimerContext[0].timerHandle);
        SCH_TIM_RestartTimer(s_StatusLedTimerContext[1].timerHandle);
        s_status_led.u8_flag_enable_timer_100ms = 0;
        s_status_led.u8_flag_enable_timer_500ms = 1;
      }
      break;

    case WAIT_UNPLUGGED:
      if (s_status_led.u8_flag_enable_timer_100ms == 0)
      {
        SCH_TIM_StopTimer(s_StatusLedTimerContext[1].timerHandle);
        SCH_TIM_RestartTimer(s_StatusLedTimerContext[0].timerHandle);
        s_status_led.u8_flag_enable_timer_100ms = 1;
        s_status_led.u8_flag_enable_timer_500ms = 0;
      }
      break;

    case DISCHARGING:
      LL_GPIO_SetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_SetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_SetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      s_status_led.u8_state_all_led = 1;
      SCH_TIM_StopTimer(s_StatusLedTimerContext[0].timerHandle);
      SCH_TIM_StopTimer(s_StatusLedTimerContext[1].timerHandle);
      break;

    default:
      break;
  }
}

/**
 * The function `APP_STATUS_LED_100MS_TimerUpdate` toggles the state of three
 * LED pins based on the current state of `state_led`.
 */
static void
APP_STATUS_LED_100MS_TimerUpdate (void)
{
  if (s_status_led.u8_state_all_led == 0)
  {
    LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
    LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
    LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
    s_status_led.u8_state_all_led = 1;
  }
  else
  {
    LL_GPIO_SetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
    LL_GPIO_SetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
    LL_GPIO_SetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
    s_status_led.u8_state_all_led = 0;
  }
}

/**
 * The function `APP_STATUS_LED_500MS_TimerUpdate` toggles different LEDs based
 * on the status of the charging mode.
 */
static void
APP_STATUS_LED_500MS_TimerUpdate (void)
{
  switch (*s_status_led.p_status_led)
  {
    case CC_MODE_CHARGING:
      LL_GPIO_TogglePin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      break;
    case CV_MODE_CHARGING:
      LL_GPIO_TogglePin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      LL_GPIO_ResetOutputPin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      break;
    case WAIT_DISCHARGING:
      LL_GPIO_TogglePin(LED_PROCESS_GPIO_Port, LED_PROCESS_Pin);
      LL_GPIO_ResetOutputPin(LED_SOFT_START_GPIO_Port, LED_SOFT_START_Pin);
      LL_GPIO_ResetOutputPin(LED_WAIT_GPIO_Port, LED_WAIT_Pin);
      break;
    default:
      break;
  }
}
