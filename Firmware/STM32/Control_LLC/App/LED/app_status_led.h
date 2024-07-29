/*
 * app_status_led.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef LED_STATUS_LED_H_
#define LED_STATUS_LED_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  void APP_STATUS_LED_Init(void);
  void APP_STATUS_LED_CreateTask(void);

#ifdef __cplusplus
}
#endif

#endif /* LED_STATUS_LED_H_ */
