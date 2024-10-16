/*
 * read_220vac.h
 *
 *  Created on: Oct 15, 2024
 *      Author: dongkhoa
 */

#ifndef READ_220VAC_READ_220VAC_H_
#define READ_220VAC_READ_220VAC_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"
#include "device.h"
#include "bsp_board.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
 *    PUBLIC DATA
 **********************/

  extern uint16_t u16_value_adc_read;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  static inline void read_220VAC_Voltage(void)
  {
    u16_value_adc_read = ADS1115_GetData (DEV_ADS1115_CHANNEL_0);
  }
  void read_valueADC_220VAC(void);

#ifdef __cplusplus
}
#endif

#endif /* READ_220VAC_READ_220VAC_H_ */
