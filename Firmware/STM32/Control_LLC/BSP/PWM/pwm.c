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
  // Set value for PSC (Prescaler)
  LL_TIM_SetPrescaler((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->prescaler);

  // Set value for ARR (Auto-Reload Register)
  LL_TIM_SetAutoReload((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->reg_auto_reload);

  // Set value for CRR (Compare Register)
  LL_TIM_OC_SetCompareCH1((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->reg_compare);
}