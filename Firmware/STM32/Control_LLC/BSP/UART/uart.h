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

#define UART_BUFFER_SIZE     256

/**********************
 *      TYPEDEFS
 **********************/

typedef struct ring_buffer
{
    volatile uint8_t buffer[UART_BUFFER_SIZE];
    volatile uint32_t  in;
    volatile uint32_t  out;
    volatile uint32_t  count;
} ring_buffer_t;

typedef struct uart_cfg
{
	volatile ring_buffer_t 	rx_buffer;
	volatile ring_buffer_t 	tx_buffer;
	USART_TypeDef * uart;
	IRQn_Type		uart_irqn;
} uart_cfg_t ;

/*********************
 *   PUBLIC FUNCTION
 *********************/

extern void UARTConfig(uart_cfg_t *uartstdio_device, USART_TypeDef * uart, IRQn_Type uart_irqn);
extern void UARTSendChar(uart_cfg_t *uartstdio_device, char c);
extern void UARTSendString(uart_cfg_t *uartstdio_device, const char *s);
extern char UARTReadChar(uart_cfg_t *uartstdio_device);
extern void UARTTimeOut(void);
extern void UART_ISR (uart_cfg_t *uartstdio_device);


#ifdef __cplusplus
}
#endif

#endif /* UART_UART_H_ */
