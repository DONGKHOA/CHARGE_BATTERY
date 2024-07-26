/*
 * board.h
 *
 *  Created on: Jul 17, 2024
 *      Author: dongkhoa
 */

#ifndef BOARD_H_
#define BOARD_H_

/*********************
 *      INCLUDES
 *********************/

#include "adc.h"
#include "i2c.h"
#include "pwm.h"
#include "systick.h"
#include "uart.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *   PUBLIC DEFINES
 *********************/

// Port-Pin Led status
#define LED_STATUS_1_PORT GPIOB
#define LED_STATUS_2_PORT GPIOB
#define LED_STATUS_3_PORT GPIOB

#define LED_STATUS_1_PIN LL_GPIO_PIN_0
#define LED_STATUS_2_PIN LL_GPIO_PIN_1
#define LED_STATUS_3_PIN LL_GPIO_PIN_2

// Port - Pin Detect have power Supply
#define DETECT_POWER_PORT GPIOA
#define DETECT_POWER_PIN  LL_GPIO_PIN_4

// Port - Pin - I2C for ADS1115
#define ADS1115_ALERT_PORT GPIOB
#define ADS1115_ALERT_PIN  LL_GPIO_PIN_5
#define ADS1115_I2C        I21

// UART for command line
#define COMMAND_LINE_UART USART1
#define COMMAND_LINE_IRQ  USART1_IRQn

// Port - Pin - Timer for gate driver
#define GATE_DRIVER_TIM         TIM1
#define GATE_DRIVER_TIM_CHANNEL PWM_CHANNEL_1
#define GATE_DRIVER_TIM_MODE    PWM_POSITIVE_NEGATIVE

  /*********************
   *   PUBLIC FUNCTION
   *********************/

  // Call Function in "SysTick ISR"
  static inline void BOARD_TimeOut (void)
  {
    UART_TimeOut();
    ADC_TimeOut();
    I2C_TimeOut();
  }

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ */
