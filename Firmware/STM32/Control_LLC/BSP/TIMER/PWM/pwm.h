/*
 * pwm.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"
#include "stm32f1xx_ll_tim.h"

/*********************
 *      DEFINES
 *********************/

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC DEFINES
   **********************/

/**
 * @brief Output modes for PWM.
 */
#define PWM_POSITIVE          0 /**< Positive output mode. */
#define PWM_POSITIVE_NEGATIVE 1 /**< Positive and negative output mode. */
#define PWM_NO_OUTPUT         2 /**< No output. */

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/

  /**
   * @brief Configuration structure for PWM.
   *
   * This structure holds the parameters necessary for configuring a PWM
   * signal on a specified timer. It includes settings for the timer,
   * auto-reload register, compare register, prescaler, and a union for
   * channel and output mode.
   */
  typedef struct _pwm_cfg_t
  {
    /**
     * @brief Pointer to the TIM peripheral used for PWM.
     *
     * This should point to a valid TIM peripheral instance.
     */
    volatile TIM_TypeDef *p_tim;

    /**
     * @brief Auto-Reload Register value.
     *
     * This value determines the period of the PWM signal.
     */
    volatile uint16_t u16_reg_auto_reload;

    /**
     * @brief Compare Register value.
     *
     * This value determines the duty cycle of the PWM signal.
     */
    volatile uint16_t u16_reg_compare;

    /**
     * @brief Prescaler value.
     *
     * This value is used to divide the timer clock frequency.
     */
    volatile uint16_t u16_prescaler;

    /**
     * @brief PWM output mode.
     *
     * Specifies the output mode:
     * - PWM_POSITIVE
     * - PWM_POSITIVE_NEGATIVE
     * - PWM_NO_OUTPUT
     */
    volatile uint8_t output;

    /**
     * @brief PWM dead time
     * This value: 0 - 255
     */
    volatile uint8_t u8_deadTime;

  } pwm_cfg_t;

  /**********************
   *    PUBLIC FUNCTIONS
   **********************/

  void BSP_PWM_SetParameterProcessChannel1(pwm_cfg_t *pwm_cfg);
  void BSP_PWM_EnableTimerChannel1 (pwm_cfg_t *pwm_cfg);
  void BSP_PWM_DisableTimerChannel1 (pwm_cfg_t *pwm_cfg);
  /**
   * @brief Resets PWM parameters in the configuration structure to default
   * values.
   *
   * This function sets the auto-reload register and compare register values
   * to zero in the provided PWM configuration structure.
   *
   * @param pwm_cfg Pointer to a `pwm_cfg_t` structure to reset.
   */
  static inline void BSP_PWM_ResetParameter (pwm_cfg_t *pwm_cfg)
  {
    pwm_cfg->u16_reg_auto_reload = 0;
    pwm_cfg->u16_reg_compare     = 0;
  }

#ifdef __cplusplus
}
#endif

#endif /* PWM_PWM_H_ */
