/*
 * gpio.h
 *
 *  Created on: Oct 1, 2024
 *      Author: dongkhoa
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx_ll_gpio.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/
  typedef enum gpio_state
  {
    GPIO_LOW = 0,
    GPIO_HIGH = 1,
  }gpio_state_t;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  void BSP_GPIO_SetState(GPIO_TypeDef *gpio_port, uint32_t gpio_pin, gpio_state_t state);
  gpio_state_t BSP_GPIO_GetState(GPIO_TypeDef *gpio_port, uint32_t gpio_pin);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_GPIO_H_ */
