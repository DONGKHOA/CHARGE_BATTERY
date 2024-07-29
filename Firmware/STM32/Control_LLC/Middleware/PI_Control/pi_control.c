/*
 * pi_control.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "pi_control.h"

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Reset a Proportional-Integral (PI) controller to initial values.
 *
 * This function resets the given PI controller structure by setting all
 * relevant fields to zero, preparing it for a new control cycle.
 *
 * @param p_pi Pointer to the PI controller structure to be reset.
 */
void
PIControl_Reset (pi_control_t *p_pi)
{
  p_pi->f_p_part    = 0; /**< @brief Reset proportional part. */
  p_pi->f_i_part    = 0; /**< @brief Reset integral part. */
  p_pi->f_out       = 0; /**< @brief Reset current output. */
  p_pi->f_pre_out   = 0; /**< @brief Reset previous output. */
  p_pi->f_error     = 0; /**< @brief Reset current error. */
  p_pi->f_pre_error = 0; /**< @brief Reset previous error. */
  p_pi->f_setPoint  = 0; /**< @brief Reset set point. */
}

/**
 * @brief Process a Proportional-Integral (PI) control cycle.
 *
 * This function calculates the output of a PI controller based on the
 * current error and previous values.
 *
 * @param f_new_value New input value (feedback).
 * @param p_pi Pointer to the PI controller structure.
 */
void
PIControl_Process (float f_new_value, pi_control_t *p_pi)
{
  /**< @brief Calculate current error. */
  p_pi->f_error = f_new_value - p_pi->f_setPoint;

  /**< @brief Calculate proportional part. */
  p_pi->f_p_part = p_pi->f_Kp * (p_pi->f_error - p_pi->f_pre_error);

  /**< @brief Calculate integral part. */
  p_pi->f_i_part = 0.5 * p_pi->f_Ki * CONTROL_PI_TIME_SAMPLE
                   * (p_pi->f_error + p_pi->f_pre_error);

  /**< @brief Calculate current output. */
  p_pi->f_out = p_pi->f_pre_out + p_pi->f_p_part + p_pi->f_i_part;

  // Update previous error and output for next iteration
  p_pi->f_pre_error = p_pi->f_error; /**< @brief Update previous error. */
  p_pi->f_pre_out   = p_pi->f_out;   /**< @brief Update previous output. */
}
