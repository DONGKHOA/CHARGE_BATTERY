/*
 * status_led.h
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

void status_led_init(void);
void status_led_create_task(void);

#ifdef __cplusplus
}
#endif

#endif /* LED_STATUS_LED_H_ */
