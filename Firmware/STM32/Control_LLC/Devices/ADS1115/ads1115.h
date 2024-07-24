/*
 * ads1115.h
 *
 *  Created on: Jul 13, 2024
 *      Author: dongkhoa
 */

#ifndef ADC_EX_ADS1115_H_
#define ADC_EX_ADS1115_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**********************
 *    PUBLIC TYPEDEFS
 **********************/

typedef enum _ads1115_channel_t
{
	CHANNEL_0 = 0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3
} ads1115_channel_t;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

extern uint16_t ADS1115_GetData(ads1115_channel_t channel);
extern float	ADS1115_Voltage(ads1115_channel_t channel);


#ifdef __cplusplus
}
#endif

#endif /* ADC_EX_ADS1115_H_ */
