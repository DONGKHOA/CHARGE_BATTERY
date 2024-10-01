/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC1_IN2_S2_Pin LL_GPIO_PIN_2
#define ADC1_IN2_S2_GPIO_Port GPIOE
#define ADC1_IN2_S1_Pin LL_GPIO_PIN_3
#define ADC1_IN2_S1_GPIO_Port GPIOE
#define ADC1_IN2_S0_Pin LL_GPIO_PIN_4
#define ADC1_IN2_S0_GPIO_Port GPIOE
#define ADC1_IN1_S3_Pin LL_GPIO_PIN_5
#define ADC1_IN1_S3_GPIO_Port GPIOE
#define ADC1_IN1_S2_Pin LL_GPIO_PIN_6
#define ADC1_IN1_S2_GPIO_Port GPIOE
#define ADC1_IN1_S1_Pin LL_GPIO_PIN_13
#define ADC1_IN1_S1_GPIO_Port GPIOC
#define ADC1_IN1_S0_Pin LL_GPIO_PIN_14
#define ADC1_IN1_S0_GPIO_Port GPIOC
#define LED_TEST_Pin LL_GPIO_PIN_0
#define LED_TEST_GPIO_Port GPIOC
#define LED_STATUS_Pin LL_GPIO_PIN_1
#define LED_STATUS_GPIO_Port GPIOC
#define DISCHARGE_Pin LL_GPIO_PIN_2
#define DISCHARGE_GPIO_Port GPIOC
#define CHARGE_Pin LL_GPIO_PIN_3
#define CHARGE_GPIO_Port GPIOC
#define TOUCH_IRQ_Pin LL_GPIO_PIN_12
#define TOUCH_IRQ_GPIO_Port GPIOD
#define CONTROL_BACKLIGHT_Pin LL_GPIO_PIN_13
#define CONTROL_BACKLIGHT_GPIO_Port GPIOD
#define BAL_16_Pin LL_GPIO_PIN_6
#define BAL_16_GPIO_Port GPIOC
#define BAL_15_Pin LL_GPIO_PIN_7
#define BAL_15_GPIO_Port GPIOC
#define BAL_14_Pin LL_GPIO_PIN_8
#define BAL_14_GPIO_Port GPIOC
#define BAL_13_Pin LL_GPIO_PIN_9
#define BAL_13_GPIO_Port GPIOC
#define BAL_12_Pin LL_GPIO_PIN_8
#define BAL_12_GPIO_Port GPIOA
#define BAL_11_Pin LL_GPIO_PIN_11
#define BAL_11_GPIO_Port GPIOA
#define BAL_10_Pin LL_GPIO_PIN_12
#define BAL_10_GPIO_Port GPIOA
#define RS485_CONTROL_Pin LL_GPIO_PIN_15
#define RS485_CONTROL_GPIO_Port GPIOA
#define BAL_9_Pin LL_GPIO_PIN_3
#define BAL_9_GPIO_Port GPIOD
#define BAL_8_Pin LL_GPIO_PIN_3
#define BAL_8_GPIO_Port GPIOB
#define BAL_7_Pin LL_GPIO_PIN_4
#define BAL_7_GPIO_Port GPIOB
#define BAL_6_Pin LL_GPIO_PIN_5
#define BAL_6_GPIO_Port GPIOB
#define BAL_5_Pin LL_GPIO_PIN_6
#define BAL_5_GPIO_Port GPIOB
#define BAL_4_Pin LL_GPIO_PIN_7
#define BAL_4_GPIO_Port GPIOB
#define BAL_3_Pin LL_GPIO_PIN_8
#define BAL_3_GPIO_Port GPIOB
#define BAL_2_Pin LL_GPIO_PIN_9
#define BAL_2_GPIO_Port GPIOB
#define BAL_1_Pin LL_GPIO_PIN_0
#define BAL_1_GPIO_Port GPIOE
#define ADC1_IN2_S3_Pin LL_GPIO_PIN_1
#define ADC1_IN2_S3_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
