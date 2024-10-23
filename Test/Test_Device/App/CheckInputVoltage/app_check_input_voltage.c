/*
 * app_check_input_voltage.c
 *
 *  Created on: Oct 20, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "main.h"
#include "app_check_input_voltage.h"
#include "app_data_struct.h"
#include "scheduler.h"
#include "device.h"
#include "bsp_board.h"

/*********************
 *    PRIVATE DEFINES
 *********************/

#define ADC_SAMPLES (uint8_t)200 // Number of ADC samples taken
#define ADC_GAIN_HW (float)10

/*********************
 *    PRIVATE TYPEDEFS
 *********************/

typedef struct _Control_TaskContextTypedef_
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} Control_TaskContextTypedef;

/**
 * The Check_Input_Voltage_t struct represents input voltage data with RMS
 * value, sample count, and ADC sum ready flag.
 * @property {float} p_input_voltage - The `p_input_voltage` property in the
 * `Check_Input_Voltage_t` struct is a pointer to a float value representing the
 * Root Mean Square (RMS) input voltage.
 * @property {uint8_t} u8_samples_count - The `u8_samples_count` property in the
 * `Check_Input_Voltage_t` struct is a `uint8_t` type variable that represents
 * the number of samples taken for checking the input voltage. It is used to
 * track the count of samples collected for analysis or processing related to
 * input voltage checking.
 * @property {uint8_t} u8_adc_sum_ready_flag - The `u8_adc_sum_ready_flag`
 * property is a flag that indicates whether the sum of the analog-to-digital
 * converter (ADC) samples is ready for processing or not. It is of type
 * `uint8_t`, which typically represents an 8-bit unsigned integer. This flag
 * can be used
 */
typedef struct _Check_Input_Voltage_t
{
  float   *p_input_voltage; // RMS
  float    f_sum_adc_value_sqr_avg;
  float    f_adc_voltage;
  uint32_t u32_sum_adc_value_sqr;
  uint16_t u16_adc_value;
  uint8_t  u8_samples_count;
} Check_Input_Voltage_t;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void  APP_CHECK_INPUT_VOLTAGE_TaskUpdate(void);
static float sqrt_newton(float n);

/*********************
 *    PRIVATE DATA
 *********************/

static Control_TaskContextTypedef s_CheckInputVoltageTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_ASYNC, // taskType;
            1,
            APP_CHECK_INPUT_VOLTAGE_TaskUpdate, // taskFunction;
        } };

static Check_Input_Voltage_t s_check_input_voltage;
/**********************
 *    PUBLIC FUNCTIONS
 **********************/

/**
 * The function initializes variables related to checking input voltage.
 */
void
APP_CHECK_INPUT_VOLTAGE_Init (void)
{
  s_check_input_voltage.u8_samples_count        = 0;
  s_check_input_voltage.u16_adc_value           = 0;
  s_check_input_voltage.u32_sum_adc_value_sqr   = 0;
  s_check_input_voltage.f_sum_adc_value_sqr_avg = 0;
  s_check_input_voltage.f_adc_voltage           = 0;
  s_check_input_voltage.p_input_voltage
      = (float *)&s_control_llc_data.f_input_voltage;
}

/**
 * The function APP_CHECK_INPUT_VOLTAGE_CreateTask creates a task for checking
 * input voltage.
 */
void
APP_CHECK_INPUT_VOLTAGE_CreateTask (void)
{
  SCH_TASK_CreateTask(&s_CheckInputVoltageTaskContext.taskHandle,
                      &s_CheckInputVoltageTaskContext.taskProperty);
}

/********************
 *  PRIVATE FUNCTION
 ********************/

/**
 * The function `APP_CHECK_INPUT_VOLTAGE_TaskUpdate` checks input voltage levels
 * and calculates the RMS voltage based on ADC samples.
 */
static void
APP_CHECK_INPUT_VOLTAGE_TaskUpdate (void)
{
  if ((s_control_llc_data.f_input_voltage < AC_INPUT_VOLTAGE_MIN)
      || (s_control_llc_data.f_output_voltage > AC_INPUT_VOLTAGE_MAX))
  {
    s_control_llc_data.s_state_data = WAIT_INPUT_VOLTAGE;
  }

  if (s_check_input_voltage.u8_samples_count >= ADC_SAMPLES)
  {
    // Calculate RMS Voltage
    s_check_input_voltage.f_sum_adc_value_sqr_avg
        = (float)s_check_input_voltage.u32_sum_adc_value_sqr / ADC_SAMPLES;

    s_check_input_voltage.f_adc_voltage = ADS1115_GetVoltage(
        (uint16_t)s_check_input_voltage.f_sum_adc_value_sqr_avg);

    *s_check_input_voltage.p_input_voltage
        = sqrt_newton(s_check_input_voltage.f_adc_voltage) * ADC_GAIN_HW;

    s_check_input_voltage.u8_samples_count = 0;
    s_check_input_voltage.u32_sum_adc_value_sqr = 0;
  }

  s_check_input_voltage.u16_adc_value = ADS1115_GetData(DEV_ADS1115_CHANNEL_0);

  s_check_input_voltage.u32_sum_adc_value_sqr
      += s_check_input_voltage.u16_adc_value
        * s_check_input_voltage.u16_adc_value;

  s_check_input_voltage.u8_samples_count++;
}

/**
 * The function `sqrt_newton` uses the Newton-Raphson method to approximate the
 * square root of a given number with a specified error tolerance.
 *
 * @param number The `number` parameter in the `sqrt_newton` function represents
 * the non-negative number for which you want to calculate the square root using
 * the Newton-Raphson method. If the input number is negative, the function
 * returns -1 as an error value. The function iteratively refines an initial
 *
 * @return The function `sqrt_newton` returns the square root of the input
 * number using the Newton-Raphson method. If the input number is negative, it
 * returns -1 as an error value.
 */
static float
sqrt_newton (float number)
{
  if (number < 0)
  {
    return -1; // Error value
  }

  float x       = number; // Initial value
  float epsilon = 0.0001; // Allowed error

  while ((x * x - number) > epsilon || (number - x * x) > epsilon)
  {
    x = 0.5 * (x + number / x); // Newton-Raphson formula
  }
  return x;
}
