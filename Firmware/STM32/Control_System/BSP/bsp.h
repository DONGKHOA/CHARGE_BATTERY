/*
 * bsp_board.h
 *
 *  Created on: Jul 17, 2024
 *      Author: dongkhoa
 */

#ifndef BSP_H_
#define BSP_H_

/*********************
 *      INCLUDES
 *********************/

#include "ADC/bsp_adc.h"
#include "GPIO/bsp_gpio.h"
#include "SysTick/bsp_systick.h"
#include "SPI/bsp_spi.h"
#include "UART/bsp_uart.h"
#include "FSMC/bsp_fsmc.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *   PUBLIC DEFINES
 *********************/


  /*********************
   *   PUBLIC FUNCTION
   *********************/

  // Call Function in "SysTick ISR"
  static inline void BSP_BOARD_TimeOut (void)
  {
    BSP_UART_TimeOut();
    BSP_ADC_TimeOut();
  }

#ifdef __cplusplus
}
#endif

#endif /* BSP_H_ */
