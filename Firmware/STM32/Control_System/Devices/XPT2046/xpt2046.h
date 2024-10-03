/*
 * xpt2046.h
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

#ifndef XPT2046_XPT2046_H_
#define XPT2046_XPT2046_H_

/*********************
 *      INCLUDES
 *********************/

#include <stdint.h>
#include "ssd1963.h"
#include "bsp.h"
#include "stm32f407xx.h"
#include "lv_drv.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC DEFINES
   **********************/

#define TOUCH_ROTATION SSD1963_ROTATION
#define DISPLAY_HEIGHT SSD1963_TFTHEIGHT
#define DISPLAY_WIDTH  SSD1963_TFTWIDTH

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/

  /**
   * @brief  Touch Screen States for the State Machine.
   *
   * This enumeration defines the different states of the XPT2046 touch screen.
   */
  typedef enum
  {
    XPT2046_IDLE, /**< 0: The touch screen is in idle state, no touch detected.
                   */
    XPT2046_PRESAMPLING, /**< 1: Pre-sampling state, the touch screen is
                            preparing to detect touch. */
    XPT2046_TOUCHED,     /**< 2: Touch detected on the screen. */
    XPT2046_RELEASED     /**< 3: Touch has been released from the screen. */
  } XPT2046_State;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  void XPT2046_Init(SPI_TypeDef *p_spi);

  void XPT2064_Read(lv_indev_drv_t * drv, lv_indev_data_t*data)

#ifdef __cplusplus
}
#endif

#endif /* XPT2046_XPT2046_H_ */
