/*
 * bsp_board.h
 *
 *  Created on: Jul 17, 2024
 *      Author: dongkhoa
 */

#ifndef BSP_BOARD_H_
#define BSP_BOARD_H_

/*********************
 *      INCLUDES
 *********************/

#include "gpio.h"
#include "i2c.h"
#include "pwm.h"
#include "timer_irq.h"
#include "systick.h"
#include "uart.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /*********************
   *   PUBLIC FUNCTION
   *********************/

  // Call Function in "SysTick ISR"
  static inline void BSP_BOARD_TimeOut (void)
  {
    BSP_UART_TimeOut();
#if I2C_LL
    BSP_I2C_TimeOut();
#endif
  }

#ifdef __cplusplus
}
#endif

#endif /* BSP_BOARD_H_ */
