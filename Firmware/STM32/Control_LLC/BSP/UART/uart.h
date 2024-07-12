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

#include <stdint.h>
#include "stm32f1xx_ll_usart.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *    PUBLIC DEFINES
 *********************/

#define UART_BUFFER_SIZE     128

/**********************
 *      TYPEDEFS
 **********************/

/**
 * @brief Structure to hold ring buffer data.
 */
typedef struct ring_buffer
{
    volatile uint8_t  buffer[UART_BUFFER_SIZE]; /**< @brief Buffer array. */
    volatile uint32_t in;                       /**< @brief Input index. */
    volatile uint32_t out;                      /**< @brief Output index. */
    volatile uint32_t count;                    /**< @brief Count of items 
                                                      in buffer. */
} ring_buffer_t;

/**
 * @brief Structure to hold UART configuration data.
 */
typedef struct uart_cfg
{
    volatile ring_buffer_t rx_buffer; /**< @brief Receive ring buffer. */
    volatile ring_buffer_t tx_buffer; /**< @brief Transmit ring buffer. */
    USART_TypeDef *        uart;      /**< @brief Pointer to UART 
                                           peripheral. */
    IRQn_Type              uart_irqn; /**< @brief UART interrupt number. */
} uart_cfg_t;

/*********************
 *   PUBLIC FUNCTION
 *********************/

extern void UARTConfig(uart_cfg_t *uartstdio_device, USART_TypeDef * uart, 
                        IRQn_Type uart_irqn);
extern void UARTSendChar(uart_cfg_t *uartstdio_device, char c);
extern void UARTSendString(uart_cfg_t *uartstdio_device, const char *s);
extern char UARTReadChar(uart_cfg_t *uartstdio_device);
extern void UARTTimeOut(void);
extern void UART_ISR (uart_cfg_t *uartstdio_device);


#ifdef __cplusplus
}
#endif

#endif /* UART_UART_H_ */
