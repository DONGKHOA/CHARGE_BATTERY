/*
 * ssd1963.h
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

#ifndef SSD1963_SSD1963_H_
#define SSD1963_SSD1963_H_

/*********************
 *      INCLUDES
 *********************/

#include "lvgl.h"
#include "lv_conf.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC DEFINES
   **********************/

#define SSD1963_ROTATION 1 // 0 - 0*, 1 - 90*, 2 - 180*, 3 - 270*

#if (SSD1963_ROTATION == 0) || (SSD1963_ROTATION == 2)
#define SSD1963_TFTWIDTH  480 ///< SSD1963 max TFT width
#define SSD1963_TFTHEIGHT 800 ///< SSD1963 max TFT height
#elif (SSD1963_ROTATION == 1) || (SSD1963_ROTATION == 3)
#define SSD1963_TFTWIDTH  800 ///< SSD1963 max TFT width
#define SSD1963_TFTHEIGHT 480 ///< SSD1963 max TFT height

#define HDP 799 // number of pixels horizontally across the display
#define VDP 479 // number of pixels vertically on the display
#endif

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/
  void SSD1963_Init(void);
  void SSD1963_Flush(lv_disp_drv_t   *drv,
                     const lv_area_t *area,
                     lv_color_t      *color_map);

#ifdef __cplusplus
}
#endif

#endif /* SSD1963_SSD1963_H_ */
