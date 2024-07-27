/*
 * voltage_convert_frequency.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "voltage_convert_frequency.h"

/**********************
 *    PUBLIC FUNCTIONS
 **********************/
uint32_t
VCF_Process (float voltage)
{
  float temp = -0.172233513 * voltage + 115.5723622;
  return (uint32_t)temp;
}
