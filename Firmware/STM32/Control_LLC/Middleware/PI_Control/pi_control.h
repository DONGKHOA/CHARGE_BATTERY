/*
 * pi_control.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef PI_CONTROL_PI_CONTROL_H_
#define PI_CONTROL_PI_CONTROL_H_

/*********************
 *      INCLUDES
 *********************/

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**********************
 *    PUBLIC TYPEDEFS
 **********************/

/**
 * @brief Structure defining a Proportional-Integral (PI) controller parameters.
 */
typedef struct _pi_control_t
{
    float f_p_part;       /**< @brief Proportional part of the controller. */
    float f_i_part;       /**< @brief Integral part of the controller. */
    float f_out;          /**< @brief Current output of the controller. */
    float f_pre_out;      /**< @brief Previous output of the controller. */
    float f_error;        /**< @brief Current error (set point - feedback). */
    float f_pre_error;    /**< @brief Previous error. */
    float f_Kp;           /**< @brief Proportional gain (Kp) of the controller. */
    float f_Ki;           /**< @brief Integral gain (Ki) of the controller. */
    float f_setPoint;     /**< @brief Desired set point for the controller. */
} pi_control_t;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

extern void PIControl_Reset(pi_control_t * p_pi);
extern void PIControl_Process(float f_new_value, pi_control_t * p_pi);

#ifdef __cplusplus
}
#endif

#endif /* PI_CONTROL_PI_CONTROL_H_ */
