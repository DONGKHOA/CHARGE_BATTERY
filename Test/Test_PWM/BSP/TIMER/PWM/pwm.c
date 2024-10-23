/*
 * pwm.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "pwm.h"

/**********************
 *    PUBLIC FUNCTIONS
 **********************/

/**
 * The function `BSP_PWM_EnableTimer` enables PWM timer channels based on the
 * configuration provided.
 *
 * @param pwm_cfg The `pwm_cfg` parameter is a pointer to a structure of type
 * `pwm_cfg_t`. This structure likely contains configuration settings for a PWM
 * (Pulse Width Modulation) signal, such as output type (positive, negative, or
 * both), channel number, and timer information. The function
 */
void
BSP_PWM_EnableTimer (pwm_cfg_t *pwm_cfg)
{
  uint32_t u32_mode;

  if ((pwm_cfg->output == PWM_POSITIVE)
      || (pwm_cfg->output == PWM_POSITIVE_NEGATIVE))
  {
    if (pwm_cfg->channel == PWM_CHANNEL_1)
    {
      u32_mode = TIM_CCER_CC1E;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_2)
    {
      u32_mode = TIM_CCER_CC2E;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_3)
    {
      u32_mode = TIM_CCER_CC3E;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_4)
    {
      u32_mode = TIM_CCER_CC4E;
    }
  }
  if (pwm_cfg->output == PWM_POSITIVE_NEGATIVE)
  {
    if (pwm_cfg->channel == PWM_CHANNEL_1)
    {
      u32_mode |= TIM_CCER_CC1NE;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_2)
    {
      u32_mode |= TIM_CCER_CC2NE;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_3)
    {
      u32_mode |= TIM_CCER_CC3NE;
    }
  }

  // Configure Channel of Timer PWM Mode
  LL_TIM_OC_SetMode(
      (TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->channel, LL_TIM_OCMODE_PWM1);

  // Enable Channel of Timer
  LL_TIM_CC_EnableChannel((TIM_TypeDef *)pwm_cfg->p_tim, u32_mode);

  // Enable Main output
  LL_TIM_EnableAllOutputs((TIM_TypeDef *)pwm_cfg->p_tim);

  // Enable Timer
  LL_TIM_EnableCounter((TIM_TypeDef *)pwm_cfg->p_tim);
}

/**
 * The function `BSP_PWM_DisableTimer` disables the timer, channels, and main
 * output of a PWM configuration.
 *
 * @param pwm_cfg The function `BSP_PWM_DisableTimer` takes a pointer to a
 * structure `pwm_cfg_t` as a parameter. This structure likely contains
 * configuration settings for a PWM (Pulse Width Modulation) timer, such as
 * output type, channel, and timer peripheral.
 */
void
BSP_PWM_DisableTimer (pwm_cfg_t *pwm_cfg)
{
  uint32_t u32_mode;

  if ((pwm_cfg->output == PWM_POSITIVE)
      || (pwm_cfg->output == PWM_POSITIVE_NEGATIVE))
  {
    if (pwm_cfg->channel == PWM_CHANNEL_1)
    {
      u32_mode = TIM_CCER_CC1E;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_2)
    {
      u32_mode = TIM_CCER_CC2E;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_3)
    {
      u32_mode = TIM_CCER_CC3E;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_4)
    {
      u32_mode = TIM_CCER_CC4E;
    }
  }
  if (pwm_cfg->output == PWM_POSITIVE_NEGATIVE)
  {
    if (pwm_cfg->channel == PWM_CHANNEL_1)
    {
      u32_mode |= TIM_CCER_CC1NE;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_2)
    {
      u32_mode |= TIM_CCER_CC2NE;
    }
    else if (pwm_cfg->channel == PWM_CHANNEL_3)
    {
      u32_mode |= TIM_CCER_CC3NE;
    }
  }
  // Disable Channel of Timer
  LL_TIM_CC_DisableChannel((TIM_TypeDef *)pwm_cfg->p_tim, u32_mode);

  // Disable Main output
  LL_TIM_DisableAllOutputs((TIM_TypeDef *)pwm_cfg->p_tim);

  // Disable Timer
  LL_TIM_DisableCounter((TIM_TypeDef *)pwm_cfg->p_tim);
}

/**
 * @brief Configures PWM parameters using the provided configuration structure.
 *
 * This function sets the prescaler, auto-reload register, and compare value
 * for the PWM timer based on the parameters provided in the configuration
 * structure.
 *
 * @param pwm_cfg Pointer to a `pwm_cfg_t` structure containing the PWM
 * configuration parameters.
 *
 * @note Ensure that the `pwm_cfg` structure is properly initialized before
 * calling this function.
 */
void
BSP_PWM_SetParameterProcess (pwm_cfg_t *pwm_cfg)
{
  // Set dead time for BDTR
  LL_TIM_OC_SetDeadTime((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->u8_deadTime);

  // Set value for PSC (Prescaler)
  pwm_cfg->p_tim->PSC = pwm_cfg->u16_prescaler;

  // Set value for ARR (Auto-Reload Register)
  pwm_cfg->p_tim->ARR = pwm_cfg->u16_reg_auto_reload;

  // Set value for CRR (Compare Register)
  pwm_cfg->p_tim->CCR1 = pwm_cfg->u16_reg_compare;
}
