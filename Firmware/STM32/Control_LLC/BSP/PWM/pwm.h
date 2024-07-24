/*
 * pwm.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

/*********************
 *      DEFINES
 *********************/

#ifdef __cplusplus
extern "C"
{
#endif

/**********************
 *    PUBLIC FUNCTIONS
 **********************/

void PWM_Config();
void PWM_Process(uint32_t prescaler, uint16_t reg_auto_reload, uint8_t duty);

#ifdef __cplusplus
}
#endif

#endif /* PWM_PWM_H_ */
