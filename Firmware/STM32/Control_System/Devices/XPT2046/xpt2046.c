/*
 * xpt2046.c
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "xpt2046.h"
#include "main.h"

/**********************
 *    PRIVATE DEFINES
 **********************/

#define MAX_SAMPLES     8
#define SAMPLE_INTERVAL 1

/**********************
 *    PRIVATE DATA
 **********************/

static uint16_t Xread, Yread;

static uint8_t ChannelSettingsX, ChannelSettingsY;
static uint8_t SendBuffer[5];
static uint8_t ReceiveBuffer[5];

uint16_t TouchSamples[2][MAX_SAMPLES];
uint8_t  SampleCounter;
uint32_t SampleTimer;

/**
 * @brief  Calibration data for calculating new coordinates.
 *
 * This structure stores the coefficients needed for touch screen calibration.
 */
typedef struct
{
  long double alpha_x; /**< Calibration coefficient for X-axis (alpha_x). */
  long double beta_x;  /**< Calibration coefficient for X-axis (beta_x). */
  long double delta_x; /**< Calibration offset for X-axis (delta_x). */
  long double alpha_y; /**< Calibration coefficient for Y-axis (alpha_y). */
  long double beta_y;  /**< Calibration coefficient for Y-axis (beta_y). */
  long double delta_y; /**< Calibration offset for Y-axis (delta_y). */
} CalibData_t;

/**
 * @brief  Current state of the touch screen.
 */
volatile XPT2046_State
    TouchState; /**< The current state of the touch screen. */

/**
 * @brief  Indicates whether calibration mode is active.
 */
static uint8_t CalibrationMode; /**< Flag to indicate if calibration mode is
                                   active (1 for active, 0 for inactive). */

#if (TOUCH_ROTATION == 0)
/**
 * @brief  Default calibration data for rotation 0.
 */
CalibData_t CalibrationData
    = { -.0009337, -.0636839, 250.342, -.0889775, -.00118110, 356.538 };
#endif

#if (TOUCH_ROTATION == 1)
/**
 * @brief  Default calibration data for rotation 1.
 */
CalibData_t CalibrationData
    = { -.0885542, -.0016532, 350.800, .00173, -.06543699, 249.7890 };
#endif

#if (TOUCH_ROTATION == 2)
/**
 * @brief  Default calibration data for rotation 2.
 */
CalibData_t CalibrationData
    = { .0006100, .0647828, -13.634, .0890609, .0001381, -35.73 };
#endif

#if (TOUCH_ROTATION == 3)
/**
 * @brief  Default calibration data for rotation 3.
 */
CalibData_t CalibrationData
    = { .0902216, .0006510, -38.657, -.0010005, -.0667030, 258.08 };
#endif

/**
 * @brief  Calibration pattern points for TOUCH_ROTATION 0 and 2.
 */
#if (TOUCH_ROTATION == 0 || TOUCH_ROTATION == 2)
uint16_t calA[] = { 10, 10 };   /**< Calibration point A for rotation 0/2. */
uint16_t calB[] = { 80, 280 };  /**< Calibration point B for rotation 0/2. */
uint16_t calC[] = { 200, 170 }; /**< Calibration point C for rotation 0/2. */
#endif

/**
 * @brief  Calibration pattern points for TOUCH_ROTATION 1 and 3.
 */
#if (TOUCH_ROTATION == 1 || TOUCH_ROTATION == 3)
uint16_t calA[] = { 20, 25 };   /**< Calibration point A for rotation 1/3. */
uint16_t calB[] = { 160, 220 }; /**< Calibration point B for rotation 1/3. */
uint16_t calC[] = { 300, 110 }; /**< Calibration point C for rotation 1/3. */
#endif

/**
 * @brief  Raw calibration points read from the panel.
 */
uint16_t calA_raw[] = { 0, 0 }; /**< Raw data for calibration point A. */
uint16_t calB_raw[] = { 0, 0 }; /**< Raw data for calibration point B. */
uint16_t calC_raw[] = { 0, 0 }; /**< Raw data for calibration point C. */

/**********************
 *   PRIVATE FUNCTIONS
 **********************/

static void
XPT2046_GetRawData (void)
{
  BSP_GPIO_SetState(GPIOB, LL_GPIO_PIN_12, GPIO_LOW);
  // Send Control bytes and receive raw ADC values from controler
  BSP_SPI_TransmitReceive(SPI1, SendBuffer, ReceiveBuffer, 5);
  BSP_GPIO_SetState(GPIOB, LL_GPIO_PIN_12, GPIO_HIGH);
}

static void XPT2046_GetTouchPoint(uint16_t *X, uint16_t *Y)
{
	uint32_t AverageX = 0, AverageY = 0;
	uint8_t i;

	for(i = 0; i < MAX_SAMPLES; i++)
	{
		AverageX += TouchSamples[0][i];
		AverageY += TouchSamples[1][i];
	}

	*X = AverageX / MAX_SAMPLES;
	*Y = AverageY / MAX_SAMPLES;
}

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
XPT2046_Init (SPI_TypeDef *p_spi)
{

  // Default State
  TouchState = XPT2046_IDLE;
  BSP_GPIO_SetState(GPIOB, LL_GPIO_PIN_12, GPIO_HIGH);
//   HAL_GPIO_WritePin(
//       SPI1_CS_Touch_GPIO_Port, SPI1_CS_Touch_Pin, GPIO_PIN_SET); // CS Idle

  //
  // Prepare Send Buffer
  //

  //     (     X    )           (     Y 	 )
  // (000 10010)(000 00000) (000 11010)(000 00000) (00000000)
  //	SendBuffer
  // (    0    )(    1    ) (    2    )(    3    ) (    4   )
  ChannelSettingsX = 0b10010000;
  ChannelSettingsY = 0b11010000;

  SendBuffer[0] = 0x80; // Clear settings in IC
  XPT2046_GetRawData(); // Send clearing command
  LL_mDelay(1);         // Wait for clear

  // Fulfill Send Buffer with Channel control bytes
  SendBuffer[0] = (ChannelSettingsX >> 3);
  SendBuffer[1] = (ChannelSettingsX << 5);
  SendBuffer[2] = (ChannelSettingsY >> 3);
  SendBuffer[3] = (ChannelSettingsY << 5);
  SendBuffer[4] = 0;
}

void XPT2064_Read(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
	if(TouchState==XPT2046_TOUCHED)
	{
		XPT2046_GetTouchPoint(&Xread,&Yread);
		 data->state = LV_INDEV_STATE_PRESSED;
		    data->point.x = Xread;
		    data->point.y = Yread;
	}
	else {
	    data->state = LV_INDEV_STATE_RELEASED;
	  }
}