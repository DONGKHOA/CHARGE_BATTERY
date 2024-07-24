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
PWM_EnableTimer (pwm_cfg_t *pwm_cfg)
{
  uint32_t u32_mode;

  if ((pwm_cfg->output == PWM_POSITIVE) || (pwm_cfg->output == PWM_POSITIVE_NEGATIVE))
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
      u32_mode|= TIM_CCER_CC1NE;
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
PWM_SetParameterProcess (pwm_cfg_t *pwm_cfg)
{
  // Set value for PSC (Prescaler)
  LL_TIM_SetPrescaler((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->prescaler);

  // Set value for ARR (Auto-Reload Register)
  LL_TIM_SetAutoReload((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->reg_auto_reload);

  // Set value for CRR (Compare Register)
  LL_TIM_OC_SetCompareCH1((TIM_TypeDef *)pwm_cfg->p_tim, pwm_cfg->reg_compare);

void PWM_Config()
{
    
  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};
  LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM3, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM3);
  LL_TIM_SetClockSource(TIM3, LL_TIM_CLOCKSOURCE_INTERNAL);
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH1);
  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
  TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH1);
  LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM3);
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
  /**TIM3 GPIO Configuration
  PA0-WKUP   ------> TIM3_CH1
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}


void PWM_Process(uint32_t prescaler, uint16_t reg_auto_reload, uint8_t duty)
{  
	/* Config Prescaler */
	LL_TIM_SetPrescaler(TIM3, prescaler);

	/* Config Autoreload */
	LL_TIM_SetAutoReload(TIM3, reg_auto_reload);

	/* Config Duty Cycle */
	LL_TIM_OC_SetCompareCH1(TIM3, ((duty*reg_auto_reload)/100));

	  LL_TIM_EnableCounter(TIM3); // Enable Timer TIM3
	  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1); // Enable channel PWM

}
