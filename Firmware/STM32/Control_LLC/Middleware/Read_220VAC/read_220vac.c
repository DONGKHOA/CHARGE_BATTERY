/*
 * read_220vac.c
 *
 *  Created on: Oct 15, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "read_220vac.h"
#include "app_data_struct.h"

/**********************
 *   PRIVATE DATA
 **********************/

static float * f_value_220VAC = (float *)&s_control_llc_data.f_input_voltage;

/**********************
 *    PUBLIC DATA
 **********************/

uint16_t u16_value_adc_read = 0;

/**********************
 *    PUBLIC FUNCTIONS
 **********************/

// void
// read_valueADC_220VAC(void)
// {
//   f_value_220VAC =
// }