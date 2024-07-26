/*
 * uart.h
 *
 *  Created on: 24-June-2024
 *      Author: dongkhoa
 */

#ifndef UART_UART_H_
#define UART_UART_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"
#include "ring_buffer.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/

  /**
   * @brief Structure to hold UART configuration data.
   */
  typedef struct uart_cfg
  {
    volatile ring_buffer_t rx_buffer; /**< @brief Receive ring buffer. */
    volatile ring_buffer_t tx_buffer; /**< @brief Transmit ring buffer. */
    USART_TypeDef         *uart;      /**< @brief Pointer to UART
                                           peripheral. */
    IRQn_Type uart_irqn;              /**< @brief UART interrupt number. */
  } uart_cfg_t;

  /*********************
   *   PUBLIC FUNCTION
   *********************/

  void    UART_Config(uart_cfg_t    *uartstdio_device,
                      USART_TypeDef *uart,
                      IRQn_Type      uart_irqn);
  uint8_t UART_IsAvailableDataReceive(uart_cfg_t *uartstdio_device);
  void    UART_SendChar(uart_cfg_t *uartstdio_device, char c);
  void    UART_SendString(uart_cfg_t *uartstdio_device, const char *s);
  char    UART_ReadChar(uart_cfg_t *uartstdio_device);

  // Call Function "UART_TimeOut" in ISR SysTick
  void UART_TimeOut(void);

  // Call Function "UART_ISR" in ISR UART
  void UART_ISR(uart_cfg_t *uartstdio_device);

#ifdef __cplusplus
}
#endif

#endif /* UART_UART_H_ */
