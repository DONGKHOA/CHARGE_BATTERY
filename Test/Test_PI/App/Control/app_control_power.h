/*
 * app_control.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef CONTROL_s_control_gate_DRIVER_H_
#define CONTROL_s_control_gate_DRIVER_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /*********************
   *    PUBLIC DEFINES
   *********************/

#define VOLTAGE_START_THRESHOLD 43.0f
#define VOLTAGE_END_THRESHOLD   58.0f

#define CURRENT_START_THRESHOLD 6.0f
#define CURRENT_END_THRESHOLD   0.5f

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  void APP_CONTROL_Init(void);
  void APP_CONTROL_CreateTask(void);

  // Call Function "APP_CONTROL_TimeWaitDischarging" in ISR SysTick
  void APP_CONTROL_TimeWaitDischarging(void);

#ifdef __cplusplus
}
#endif

#endif /* CONTROL_s_control_gate_DRIVER_H_ */
