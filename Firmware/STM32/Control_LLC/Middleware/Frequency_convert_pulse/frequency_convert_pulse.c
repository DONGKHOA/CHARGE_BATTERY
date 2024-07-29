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

#include "app_data_struct.h"

#include <stdio.h>

/**********************
 *    PRIVATE DEFINE
 **********************/

/**
 * @brief Duty cycle for PWM.
 *
 * Specifies the duty cycle percentage for the PWM signal.
 */
#define DUTY_CYCLE 50 /**< Duty cycle percentage (50%). */

#define FRE_START_THRESHOLD                                                  \
  76000                          /**< Starting threshold frequency (80 KHz). \
                                  */
#define FRE_END_THRESHOLD 133000 /**< Ending threshold frequency (110 KHz). */

/**
 * @brief Thresholds for pre-scaler.
 *
 * These thresholds are defined using values from the `table_data_process`
 * array.
 */
#define PRE_START_THRESHOLD \
  table_data_process[0]     \
      .prescaler_timer /**< Starting threshold prescaler value. */

#define PRE_END_THRESHOLD                           \
  table_data_process[(SIZE_TABLE_DATA_PROCESS - 1)] \
      .prescaler_timer /**< Ending threshold prescaler value. */

/**
 * @brief Thresholds for register auto-reload.
 *
 * These thresholds are defined using values from the `table_data_process`
 * array.
 */
#define REG_START_THRESHOLD                                      \
  table_data_process[0]                                          \
      .auto_reload_reg_timer /**< Starting threshold auto-reload \
                                register value. */

#define REG_END_THRESHOLD                                               \
  table_data_process[(SIZE_TABLE_DATA_PROCESS - 1)]                     \
      .auto_reload_reg_timer /**< Ending threshold auto-reload register \
                                value. */

/**********************
 *   PRIVATE DATA
 **********************/

static pwm_cfg_t *pwm_control_1 = (pwm_cfg_t *)&s_control_llc_data.s_control_gate;

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
 * This function sets the PWM parameters using the `table_data_start` array
 * based on the given time. If the time is less than or equal to 20, it uses
 * the first entry of the table. If the time is greater than 20, it uses the
 * entry at the index (time - 20) of the table.
 *
 * @param time The time value used to determine the PWM parameters.
 */
void
FCP_PhaseStart (uint8_t time)
{
  time = time > 20 ? (time - 20) : 0;

  // Set the prescaler value
  pwm_control_1->u16_prescaler = table_data_start[time].prescaler_timer - 1;
  // Set the auto-reload register value
  pwm_control_1->u16_reg_auto_reload
      = table_data_start[time].auto_reload_reg_timer - 1;
  // Set the compare register value
  pwm_control_1->u16_reg_compare
      = table_data_start[time].auto_reload_reg_timer * DUTY_CYCLE / 100;

  // Apply the PWM parameters
  BSP_PWM_SetParameterProcess(pwm_control_1);
}

/**
 * @brief Processes the phase of the FCP based on the provided frequency.
 *
 * This function adjusts the PWM parameters based on the given frequency.
 * If the frequency exceeds the end threshold or is below the start threshold,
 * it sets the PWM parameters to predefined values. It then calculates the
 * absolute difference between the frequency and the frequencies in the
 * `table_data_process` array to find the closest match and adjust the PWM
 * parameters accordingly.
 *
 * @param frequency The frequency value used to determine the PWM parameters.
 */
void
FCP_PhaseProcess (uint32_t frequency)
{
  if (frequency > FRE_END_THRESHOLD)
  {
    // Set the prescaler value
    pwm_control_1->u16_prescaler = PRE_END_THRESHOLD - 1;
    // Set the auto-reload register value
    pwm_control_1->u16_reg_auto_reload = REG_END_THRESHOLD - 1;
    // Set the compare register value
    pwm_control_1->u16_reg_compare = REG_END_THRESHOLD * DUTY_CYCLE / 100;
  }
  else if (frequency < FRE_START_THRESHOLD)
  {
    // Set the prescaler value
    pwm_control_1->u16_prescaler = PRE_START_THRESHOLD - 1;
    // Set the auto-reload register value
    pwm_control_1->u16_reg_auto_reload = REG_START_THRESHOLD - 1;
    // Set the compare register value
    pwm_control_1->u16_reg_compare = REG_START_THRESHOLD * DUTY_CYCLE / 100;
  }
  else
  {
    uint32_t i;
    int32_t  delta_1 = 0;
    int32_t  delta_2 = 0;
    for (i = 0; i < SIZE_TABLE_DATA_PROCESS - 1; i++)
    {
      delta_1 = abs_32((int32_t)(frequency - table_data_process[i].frequency));
      delta_2
          = abs_32((int32_t)(frequency - table_data_process[i + 1].frequency));

      if (delta_1 <= delta_2)
      {
        // Set the prescaler value
        pwm_control_1->u16_prescaler
            = table_data_process[i - 1].prescaler_timer - 1;
        // Set the auto-reload register value
        pwm_control_1->u16_reg_auto_reload
            = table_data_process[i - 1].auto_reload_reg_timer - 1;
        // Set the compare register value
        pwm_control_1->u16_reg_compare
            = table_data_process[i - 1].auto_reload_reg_timer * DUTY_CYCLE
              / 100;
        break;
      }
    }
  }

  BSP_PWM_SetParameterProcess(pwm_control_1);
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
static int32_t
abs_32 (int32_t num)
{
  if (num >= 0)
  {
    return num;
  }
  else
  {
    return -num;
  }
}
