/*
 * acs712.h
 *
 *  Created on: Oct 11, 2024
 *      Author: dongkhoa
 */

#ifndef ACS712_ACS712_H_
#define ACS712_ACS712_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  static inline float ACS712_CurrentConverterVoltage(float current)
  {
	  return 2.5f + 0.1f * current;
  }

  static inline float ACS712_VoltageConverterCurrent(float voltage)
  {
	  return (voltage - 2.5f)/0.1f;
  }

#endif /* ACS712_ACS712_H_ */
