/*
 * bsp_gpio.c
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "bsp_gpio.h"

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * The function `BSP_GPIO_SetState` sets the state of a GPIO pin based on the
 * specified state value.
 *
 * @param gpio_port GPIO port to which the GPIO pin belongs (e.g., GPIOA, GPIOB,
 * etc.).
 * @param gpio_pin The `gpio_pin` parameter represents the specific pin on the
 * GPIO port that you want to set the state for.
 * @param state The `state` parameter in the `BSP_GPIO_SetState` function is of
 * type `gpio_state_t`, which is used to specify whether the GPIO pin should be
 * set to a low state (`GPIO_LOW`) or a high state (`GPIO_HIGH`).
 */
void
BSP_GPIO_SetState (GPIO_TypeDef *gpio_port,
                   uint32_t      gpio_pin,
                   gpio_state_t  state)
{
  if (state == GPIO_LOW)
  {
    gpio_port->BSRR = gpio_pin;
  }
  else
  {
    gpio_port->BSRR = gpio_pin << 16;
  }
}

/**
 * The function `BSP_GPIO_GetState` returns the state of a GPIO pin as either
 * GPIO_HIGH or GPIO_LOW.
 *
 * @param gpio_port GPIO port pointer (e.g., GPIOA, GPIOB, etc.) where the pin
 * is located.
 * @param gpio_pin The `gpio_pin` parameter is the pin number of the GPIO port
 * for which you want to get the state. It is a 32-bit unsigned integer
 * representing the specific pin on the GPIO port.
 *
 * @return The function `BSP_GPIO_GetState` returns a value of type
 * `gpio_state_t`, which is either `GPIO_HIGH` or `GPIO_LOW` based on the input
 * pin state of the specified GPIO port and pin.
 */
gpio_state_t
BSP_GPIO_GetState (GPIO_TypeDef *gpio_port, uint32_t gpio_pin)
{
  if ((gpio_port->IDR & gpio_pin) == gpio_pin)

  {
    return GPIO_HIGH;
  }
  return GPIO_LOW;
}
