/*
 * current_convert_frequency.c
 *
 *  Created on: Oct 10, 2024
 *      Author: dongkhoa
 */


/*********************
 *      INCLUDES
 *********************/

#include "current_convert_frequency.h"

/**********************
 *    PUBLIC FUNCTIONS
 **********************/
uint32_t
CCF_Process(float current)
{
  float temp = -0.172233513 * current + 115.5723622;
  return (uint32_t)temp;
}
