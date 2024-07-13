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
#include "Private/data_private.h"
#include "pwm.h"

/**********************
 *    PRIVATE DEFINE
 **********************/

// Threshold for frequency
#define FRE_START_THRESHOLD     80000	/**< @brief Starting threshold frequency (80 KHz). */
#define FRE_END_THRESHOLD       110000 	/**< @brief Ending threshold frequency (110 KHz). */

// Threshold for pre-scaler
#define PRE_START_THRESHOLD	\
	table_data_process[0].prescaler_timer
#define PRE_END_THRESHOLD	\
	table_data_process[(sizeof(table_data_process) / sizeof(FCP_data_t) - 1)].\
	prescaler_timer

// Threshold for register auto-reload
#define REG_START_THRESHOLD	\
	table_data_process[0].auto_reload_reg_timer
#define REG_END_THRESHOLD	\
	table_data_process[(sizeof(table_data_process) / sizeof(FCP_data_t) - 1)].\
	auto_reload_reg_timer

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static int32_t abs_32(int32_t num);

/**********************
 *    PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Starts the phase of the FCP process based on the provided time.
 *
 * This function sets the PWM parameters using the table_data_start array
 * based on the given time. If the time is less than or equal to 20, it uses
 * the first entry of the table. If the time is greater than 20, it uses the
 * entry at the index (time - 20) of the table.
 *
 * @param time The time value used to determine the PWM parameters.
 */
void FCP_StartPhase (uint8_t time)
{
    if (time <= 20)
    {
        PWM_Process(table_data_start[0].prescaler_timer,
                    table_data_start[0].auto_reload_reg_timer, 50);
    }
    else if (time > 20)
    {
        PWM_Process(table_data_start[time - 20].prescaler_timer,
                    table_data_start[time - 20].auto_reload_reg_timer, 50);
    }
}

/**
 * @brief Processes the phase of the FCP based on the provided frequency.
 *
 * This function adjusts the PWM parameters based on the given frequency.
 * If the frequency exceeds the end threshold or is below the start threshold,
 * it sets the PWM parameters to predefined values. It then calculates the
 * absolute difference between the frequency and the frequencies in the
 * table_data_process array to find the closest match and adjust the PWM
 * parameters accordingly.
 *
 * @param frequency The frequency value used to determine the PWM parameters.
 */
void FCP_ProcessPhase (uint32_t frequency)
{
    if (frequency > FRE_END_THRESHOLD)
        PWM_Process(PRE_END_THRESHOLD, REG_END_THRESHOLD, 50);

    if (frequency < FRE_START_THRESHOLD)
        PWM_Process(PRE_START_THRESHOLD, REG_START_THRESHOLD, 50);

    int32_t delta = 0;
    int32_t sub_delta = \
                abs_32((int32_t)(frequency - table_data_process[0].frequency));
    for (uint_fast32_t i = 0;
         i < (sizeof(table_data_process) / sizeof(FCP_data_t)); i++)
    {
        delta = abs_32((int32_t)(frequency - table_data_process[i].frequency));
        if (delta > sub_delta)
        {
            PWM_Process(table_data_process[i - 1].prescaler_timer,
                        table_data_process[i - 1].auto_reload_reg_timer, 50);
            return;
        }
        else
        {
            sub_delta = delta;
        }
    }
}

/**********************
 *    PRIVATE FUNCTIONS
 **********************/

/**
 * @brief Computes the absolute value of a 32-bit integer.
 *
 * This function returns the absolute value of the given 32-bit integer.
 * If the input number is non-negative, it returns the number as-is.
 * Otherwise, it returns the negated value of the number.
 *
 * @param num The 32-bit integer for which the absolute value is to be computed.
 * @return The absolute value of the input 32-bit integer.
 */
static int32_t abs_32(int32_t num)
{
    if (num >= 0) return num;
    else          return -num;
}
