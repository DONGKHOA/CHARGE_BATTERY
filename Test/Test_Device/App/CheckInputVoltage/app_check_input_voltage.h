/*
 * app_check_input_voltage.h
 *
 *  Created on: Oct 20, 2024
 *      Author: dongkhoa
 */

#ifndef CHECKINPUTVOLTAGE_APP_CHECK_INPUT_VOLTAGE_H_
#define CHECKINPUTVOLTAGE_APP_CHECK_INPUT_VOLTAGE_H_

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

#define AC_INPUT_VOLTAGE_MIN 85.0f
#define AC_INPUT_VOLTAGE_MAX 265.0f

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  void APP_CHECK_INPUT_VOLTAGE_Init(void);
  void APP_CHECK_INPUT_VOLTAGE_CreateTask(void);

#ifdef __cplusplus
}
#endif

#endif /* CHECKINPUTVOLTAGE_APP_CHECK_INPUT_VOLTAGE_H_ */
