/*
 * frequency_convert_pulse.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "frequency_convert_pulse.h"

/**********************
 *    PRIVATE DATA
 **********************/

/**
 * @brief Table for frequency conversion process with a range from 80KHz to 110KHz, step is 50Hz.
 */
static volatile FCP_data_t table_data_process[] =
{
		{80000, 375, 2},
		{80050, 375, 2},
};

static volatile FCP_data_t table_data_start[] =
{
		{80000, 375, 2},
		{80050, 375, 2},
};

/**********************
 *    PUBLIC FUNCTIONS
 **********************/

void FSC_Process(uint32_t frequency)
{
	// find parameter for timer operating
	uint32_t delta = 0;
	for(uint_fast32_t i = 0;
		i < (sizeof(table_data_process) / sizeof(FCP_data_t)); i++)
	{

	}
}
