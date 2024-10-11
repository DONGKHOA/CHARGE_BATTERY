/*
 * ads1115.h
 *
 *  Created on: Jul 13, 2024
 *      Author: dongkhoa
 */

#ifndef ADS1115_ADS1115_H_
#define ADS1115_ADS1115_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**********************
 *    PUBLIC DEFINE
 **********************/

#define ADS1115_VREF       4096 // mV

/**********************
 *    PUBLIC TYPEDEFS
 **********************/

  typedef enum _ads1115_channel_t
  {
    DEV_ADS1115_CHANNEL_0 = 0,
    DEV_ADS1115_CHANNEL_1,
    DEV_ADS1115_CHANNEL_2,
    DEV_ADS1115_CHANNEL_3
  } ads1115_channel_t;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  uint16_t ADS1115_GetData(ads1115_channel_t channel);
  float    ADS1115_Voltage(ads1115_channel_t channel);

#ifdef __cplusplus
}
#endif

#endif /* ADC_EX_ADS1115_H_ */
