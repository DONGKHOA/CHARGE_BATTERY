/*
 * current_convert_frequency.h
 *
 *  Created on: Oct 10, 2024
 *      Author: dongkhoa
 */

#ifndef CURRENT_CONVERT_FREQUENCY_CURRENT_CONVERT_FREQUENCY_H_
#define CURRENT_CONVERT_FREQUENCY_CURRENT_CONVERT_FREQUENCY_H_

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
  uint32_t CCF_Process(float current);

#ifdef __cplusplus
}
#endif

#endif /* CURRENT_CONVERT_FREQUENCY_CURRENT_CONVERT_FREQUENCY_H_ */
