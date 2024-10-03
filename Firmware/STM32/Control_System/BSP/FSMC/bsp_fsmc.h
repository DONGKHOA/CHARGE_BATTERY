/*
 * bsp_fsmc.h
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

#ifndef FSMC_BSP_FSMC_H_
#define FSMC_BSP_FSMC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *   PUBLIC DEFINE
   **********************/

#define LCD_REG  ((uint32_t)0x60000000)
#define LCD_DATA ((uint32_t)0x60020000)

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  static __inline void BSP_FSMC_Send_Command (uint8_t cmd)
  {
    *(uint8_t *)(LCD_REG) = cmd;
  }

  static __inline void BSP_FSMC_Send_Data (uint16_t data)
  {
    *(uint16_t *)(LCD_DATA) = data;
  }

#ifdef __cplusplus
}
#endif

#endif /* FSMC_BSP_FSMC_H_ */
