/*
 * voltage_convert_frequency.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef VOLTAGE_CONVERT_FREQUENCY_VOLTAGE_CONVERT_FREQUENCY_H_
#define VOLTAGE_CONVERT_FREQUENCY_VOLTAGE_CONVERT_FREQUENCY_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC FUNCTIONS
   **********************/
  uint32_t VCF_Process(float voltage);

#ifdef __cplusplus
}
#endif

#endif /* VOLTAGE_CONVERT_FREQUENCY_VOLTAGE_CONVERT_FREQUENCY_H_ */
