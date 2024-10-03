/*
 * ssd1963.c
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "stm32f4xx_ll_utils.h"
#include "ssd1963.h"
#include "bsp.h"

/********************
 *  PRIVATE DEFINES
 ********************/

#define MADCTL_MY  0x80 ///< Bottom to top
#define MADCTL_MX  0x40 ///< Right to left
#define MADCTL_MV  0x20 ///< Reverse Mode
#define MADCTL_ML  0x10 ///< LCD refresh Bottom to top
#define MADCTL_RGB 0x00 ///< Red-Green-Blue pixel order
#define MADCTL_BGR 0x08 ///< Blue-Green-Red pixel order
#define MADCTL_MH  0x04 ///< LCD refresh right to left

/********************
 *  PRIVATE FUNCTION
 ********************/

/**
 * The function `SSD1963_SetAddrWindowForLv` sets the address window for the
 * SSD1963 display controller.
 *
 * @param x1 x1 is the starting x-coordinate of the window to be set on the
 * display.
 * @param y1 The `SSD1963_SetAddrWindowForLv` function sets the address window
 * for the SSD1963 display controller. The parameters `x1`, `y1`, `x2`, and `y2`
 * define the coordinates of the window on the display.
 * @param x2 The parameter `x2` represents the x-coordinate of the second point
 * in the window you want to set. It is used in conjunction with `x1` to define
 * the horizontal boundaries of the window on the display.
 * @param y2 The parameter `y2` in the `SSD1963_SetAddrWindowForLv` function
 * represents the y-coordinate of the bottom-right corner of the window that
 * will be set for the display. It defines the vertical position of the lower
 * boundary of the window.
 */
static void
SSD1963_SetAddrWindowForLv (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
  BSP_FSMC_Send_Command(0x002A);
  BSP_FSMC_Send_Data(x1 >> 8);
  BSP_FSMC_Send_Data(x1 & 0x00ff);
  BSP_FSMC_Send_Data(x2 >> 8);
  BSP_FSMC_Send_Data(x2 & 0x00ff);

  BSP_FSMC_Send_Command(0x002B);
  BSP_FSMC_Send_Data(y1 >> 8);
  BSP_FSMC_Send_Data(y1 & 0x00ff);
  BSP_FSMC_Send_Data(y2 >> 8);
  BSP_FSMC_Send_Data(y2 & 0x00ff);

  BSP_FSMC_Send_Command(0x2C);
}

/**
 * The function `SSD1963_SendData` sends data stored in a buffer to a display
 * controller using the BSP_FSMC_Send_Data function.
 *
 * @param buff The `buff` parameter is a pointer to a uint16_t type, which is
 * essentially an array of 16-bit unsigned integers.
 * @param dataSize The `dataSize` parameter represents the number of elements in
 * the `buff` array that need to be sent using the `BSP_FSMC_Send_Data`
 * function.
 */
static void
SSD1963_SendData (uint16_t *buff, uint16_t dataSize)
{
  for (uint32_t i = 0; i < dataSize; i++)
  {
    BSP_FSMC_Send_Data(*(buff + i));
  }
}

static void
SSD1963_SetRotation (uint8_t rotation)
{
  switch (rotation)
  {
    case 0:
      rotation = (MADCTL_MX | MADCTL_BGR);
      break;
    case 1:
      rotation = (MADCTL_MV | MADCTL_BGR);
      break;
    case 2:
      rotation = (MADCTL_MY | MADCTL_BGR);
      break;
    case 3:
      rotation = (MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR);
      break;
  }
  BSP_FSMC_Send_Command(0x0036); // rotation
  BSP_FSMC_Send_Data((uint16_t) rotation);    // RGB=BGR
}

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * The function `SSD1963_Init` initializes an SSD1963 display controller with
 * specific configuration settings.
 */
void
SSD1963_Init (void)
{
  BSP_FSMC_Send_Command(0x00E2); // PLL multiplier, set PLL clock to 120M
  BSP_FSMC_Send_Data(0x0023);    // N=0x36 for 6.5M, 0x23 for 10M crystal
  BSP_FSMC_Send_Data(0x0002);
  BSP_FSMC_Send_Data(0x0054);
  BSP_FSMC_Send_Command(0x00E0); // PLL enable
  BSP_FSMC_Send_Data(0x0001);
  LL_mDelay(10);
  BSP_FSMC_Send_Command(0x00E0);
  BSP_FSMC_Send_Data(0x0003); // now, use PLL output as system clock
  LL_mDelay(10);
  BSP_FSMC_Send_Command(0x0001); // software reset
  LL_mDelay(20);
  BSP_FSMC_Send_Command(0x00E6); // PLL setting for PCLK, depends on resolution
  BSP_FSMC_Send_Data(0x0003);
  BSP_FSMC_Send_Data(0x0033);
  BSP_FSMC_Send_Data(0x0033);

  BSP_FSMC_Send_Command(0x00B0);  // LCD SPECIFICATION
  BSP_FSMC_Send_Data(0x0020);     // 24 bit TFT panel
  BSP_FSMC_Send_Data(0x0000);     // Hsync+Vsync +DE mode  TFT mode
  BSP_FSMC_Send_Data((HDP >> 8)); // Set HDP
  BSP_FSMC_Send_Data(HDP);
  BSP_FSMC_Send_Data(VDP >> 8); // Set VDP
  BSP_FSMC_Send_Data(VDP);
  BSP_FSMC_Send_Data(0x0000);

  BSP_FSMC_Send_Command(0x00B4); // HSYNC
  BSP_FSMC_Send_Data(0x04);      // Set HT
  BSP_FSMC_Send_Data(0x1f);
  BSP_FSMC_Send_Data(0x00); // Set HPS
  BSP_FSMC_Send_Data(0xd2);
  BSP_FSMC_Send_Data(0x00); // Set HPW
  BSP_FSMC_Send_Data(0x00); // Set HPS
  BSP_FSMC_Send_Data(0x00);
  BSP_FSMC_Send_Data(0x00);

  BSP_FSMC_Send_Command(0x00B6); // VSYNC
  BSP_FSMC_Send_Data(0x02);      // Set VT
  BSP_FSMC_Send_Data(0x0c);
  BSP_FSMC_Send_Data(0x00); // Set VPS
  BSP_FSMC_Send_Data(0x22);
  BSP_FSMC_Send_Data(0x00); // Set VPW
  BSP_FSMC_Send_Data(0x00); // Set FPS
  BSP_FSMC_Send_Data(0x00);

  BSP_FSMC_Send_Command(0x00B8);
  BSP_FSMC_Send_Data(0x000f); // GPIO is controlled by host GPIO[3:0]=output
                              // GPIO[0]=1  LCD ON  GPIO[0]=1  LCD OFF
  BSP_FSMC_Send_Data(0x0001); // GPIO0 normal

  BSP_FSMC_Send_Command(0x00BA);
  BSP_FSMC_Send_Data(0x0001); // GPIO[0] out 1 --- LCD display on/off control
                              // PIN

  SSD1963_SetRotation(SSD1963_ROTATION);

  BSP_FSMC_Send_Command(
      0x003A);                // Set the current pixel format for RGB image data
  BSP_FSMC_Send_Data(0x0050); // 16-bit/pixel

  BSP_FSMC_Send_Command(0x00F0); // Pixel Data Interface Format
  BSP_FSMC_Send_Data(0x0003);    // 16-bit(565 format) data

  BSP_FSMC_Send_Command(0x00BC);
  BSP_FSMC_Send_Data(0x0040); // contrast value
  BSP_FSMC_Send_Data(0x0080); // brightness value
  BSP_FSMC_Send_Data(0x0040); // saturation value
  BSP_FSMC_Send_Data(0x0001); // Post Processor Enable

  LL_mDelay(5);

  BSP_FSMC_Send_Command(0x0029); // display on

  BSP_FSMC_Send_Command(0x00BE); // set PWM for B/L
  BSP_FSMC_Send_Data(0x0006);
  BSP_FSMC_Send_Data(0x0080);
  BSP_FSMC_Send_Data(0x0001);
  BSP_FSMC_Send_Data(0x00f0);
  BSP_FSMC_Send_Data(0x0000);
  BSP_FSMC_Send_Data(0x0000);

  BSP_FSMC_Send_Command(0x00d0);
  BSP_FSMC_Send_Data(0x000d);
}

/**
 * The function `SSD1963_Flush` sets the address window for a display area,
 * sends color data to the SSD1963 controller, and notifies the display driver
 * that flushing is complete.
 *
 * @param drv The `drv` parameter in the `SSD1963_Flush` function is a pointer
 * to a display driver structure of type `lv_disp_drv_t`. This structure
 * typically contains information and function pointers related to the display
 * driver that is being used with the LittlevGL graphics library.
 * @param area The `area` parameter in the `SSD1963_Flush` function represents
 * the area on the display where the flushing operation will be performed. It is
 * of type `lv_area_t` which typically contains the coordinates `(x1, y1)` as
 * the top-left corner and `(x2
 * @param color_map The `color_map` parameter in the `SSD1963_Flush` function is
 * a pointer to an array of `lv_color_t` type, which represents the color data
 * to be displayed on the screen within the specified area. The function uses
 * this color map data to update the display with the
 */
void
SSD1963_Flush (lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
  SSD1963_SetAddrWindowForLv((uint16_t)area->x1,
                             (uint16_t)area->y1,
                             (uint16_t)area->x2,
                             (uint16_t)area->y2);
  uint32_t size = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1);
  SSD1963_SendData((uint16_t *)color_map, size);
  lv_disp_flush_ready(drv);
}