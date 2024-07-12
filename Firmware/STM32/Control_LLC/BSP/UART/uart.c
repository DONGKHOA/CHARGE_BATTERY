/*
 * uart.c
 *
 *  Created on: 24-June-2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "uart.h"
#include <stdbool.h>

/*********************
 *    PRIVATE DEFINES
 *********************/

#define ATOMIC_BLOCK_START(uart) 	LL_USART_DisableIT_RXNE(uart)
#define ATOMIC_BLOCK_END(uart)		LL_USART_EnableIT_RXNE(uart)
#define LIMIT_WAIT_BUFFER			1000UL

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

// API for Queue
static inline void QUEUE_Init(ring_buffer_t *rb);
static bool QUEUE_Is_Empty(ring_buffer_t *rb);
static bool QUEUE_Is_Full(ring_buffer_t *rb);
static void QUEUE_Push_Data(ring_buffer_t *rb, char element);
static uint8_t QUEUE_Pull_Data(ring_buffer_t *rb);
static inline uint8_t QUEUE_Peek_Data(ring_buffer_t *rb);

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * @brief Timeout value for waiting for the buffer to empty.
 */
static volatile uint32_t timeout = 0;

/*********************
 *   PUBLIC FUNCTION
 *********************/

/**
 * @brief Configures the UART and initializes its buffers.
 *
 * @param uartstdio_device Pointer to the UART configuration structure.
 * @param uart             Pointer to the UART peripheral.
 * @param uart_irqn        UART interrupt number.
 */
void UARTConfig(uart_cfg_t *uartstdio_device, USART_TypeDef *uart, 
                IRQn_Type uart_irqn)
{
    uartstdio_device->uart = uart;
    uartstdio_device->uart_irqn = uart_irqn;

    QUEUE_Init((ring_buffer_t *)&uartstdio_device->tx_buffer);
    QUEUE_Init((ring_buffer_t *)&uartstdio_device->rx_buffer);

    /**
     * Enable the UART Error Interrupt:
     * (Frame error, noise error, overrun error)
     */
    LL_USART_EnableIT_ERROR(uart);

    /* Enable the UART Data Register not empty Interrupt */
    LL_USART_EnableIT_RXNE(uart);
}

/**
 * The function `UARTSendChar` sends a character over UART with error handling for a full transmit
 * buffer.
 * 
 * @param uartstdio_device The `uartstdio_device` parameter is a pointer to a structure of type
 * `uart_cfg_t`. This structure likely contains configuration settings and buffers related to a UART
 * (Universal Asynchronous Receiver-Transmitter) communication interface.
 * @param c The parameter `c` in the `UARTSendChar` function is the character that you want to send via
 * UART communication.
 * 
 * @return If the timeout reaches 0, the function will return without sending the character.
 */
void UARTSendChar(uart_cfg_t *uartstdio_device, char c)
{
	timeout = LIMIT_WAIT_BUFFER;
	while (QUEUE_Is_Full((ring_buffer_t *)&uartstdio_device->tx_buffer))
	{
		if (timeout == 0) return;
	}

    ATOMIC_BLOCK_START(uartstdio_device->uart);
	QUEUE_Push_Data((ring_buffer_t *)&uartstdio_device->tx_buffer, c);
    ATOMIC_BLOCK_END(uartstdio_device->uart);
}

/**
 * The function UARTSendString sends a string over UART one character at a time.
 * 
 * @param uartstdio_device The `uartstdio_device` parameter is a pointer to a structure of type
 * `uart_cfg_t`, which likely contains configuration settings for a UART (Universal Asynchronous
 * Receiver-Transmitter) device. This structure may include information such as baud rate, data bits,
 * stop bits, parity settings, and other
 * @param s The parameter `s` in the `UARTSendString` function is a pointer to a constant character
 * array (string) that you want to send via UART. The function iterates over each character in the
 * string and sends it using the `UARTSendChar` function.
 */
void UARTSendString(uart_cfg_t *uartstdio_device, const char *s)
{
	while (*s)
	{
		UARTSendChar (uartstdio_device, *s++);
	}
}

/**
 * The function `UARTReadChar` reads a character from a UART device's receive buffer if it is not
 * empty.
 * 
 * @param uartstdio_device The `uartstdio_device` parameter is a pointer to a structure of type
 * `uart_cfg_t`. This structure likely contains configuration settings and information related to a
 * UART (Universal Asynchronous Receiver-Transmitter) device, such as baud rate, data bits, parity,
 * stop bits, and pointers to buffers
 * 
 * @return The function `UARTReadChar` returns a character that is read from the UART receive buffer.
 * If the receive buffer is not empty, it pulls a character from the buffer and returns it. If the
 * buffer is empty, it returns the null character '\0'.
 */
char UARTReadChar(uart_cfg_t *uartstdio_device)
{
	register char c = '\0';
	if (!QUEUE_Is_Empty ((ring_buffer_t *)&uartstdio_device->rx_buffer))
	{
		ATOMIC_BLOCK_START(uartstdio_device->uart);
		c = (char)QUEUE_Pull_Data((ring_buffer_t *)&uartstdio_device->rx_buffer);
		ATOMIC_BLOCK_END(uartstdio_device->uart);
		return c;
	}
	return c;
}

/**
 * The function `UARTTimeOut` decrements the variable `timeout` if it is not equal to 0.
 */
void UARTTimeOut(void)
{
	if (timeout != 0) timeout--;
}

/********************
 *  PRIVATE FUNCTION
 ********************/

/**
 * The function `QUEUE_Init` initializes a ring buffer by setting the input and output indices to 0 and
 * the count to 0.
 * 
 * @param rb The parameter `rb` is a pointer to a `ring_buffer_t` structure, which is used to implement
 * a queue data structure.
 */
static inline void QUEUE_Init(ring_buffer_t *rb)
{
    rb->in = 0;
    rb->out = 0;
    rb->count = 0;
}

/**
 * The function `QUEUE_Is_Empty` checks if a ring buffer is empty.
 * 
 * @param rb The parameter `rb` is a pointer to a `ring_buffer_t` structure.
 * 
 * @return The function `QUEUE_Is_Empty` returns a boolean value indicating whether the ring buffer
 * `rb` is empty or not. It returns `true` if the count of elements in the ring buffer is 0, indicating
 * that the buffer is empty, and `false` otherwise.
 */
static bool QUEUE_Is_Empty(ring_buffer_t *rb)
{
	return (rb->count == 0);
}

/**
 * The function checks if a ring buffer is full based on its count and size.
 * 
 * @param rb The `rb` parameter is a pointer to a `ring_buffer_t` structure, which is likely used to
 * implement a ring buffer data structure for managing data in a circular buffer fashion.
 * 
 * @return The function `QUEUE_Is_Full` is returning a boolean value, either `true` or `false`, based
 * on whether the count of elements in the ring buffer `rb` is equal to the predefined size
 * `UART_BUFFER_SIZE`.
 */
static bool QUEUE_Is_Full(ring_buffer_t *rb)
{
	return (rb->count == (uint32_t)UART_BUFFER_SIZE);
}

/**
 * The function `QUEUE_Push_Data` adds an element to a ring buffer and updates the buffer's internal
 * variables.
 * 
 * @param rb The parameter `rb` is a pointer to a structure of type `ring_buffer_t`.
 * @param element The `element` parameter in the `QUEUE_Push_Data` function represents the data element
 * that needs to be added to the ring buffer. It is of type `char`, which means it can store a single
 * character (1 byte) of data.
 */
static void QUEUE_Push_Data(ring_buffer_t *rb, char element)
{
	*(rb->buffer + rb->in) = element;
	
    rb->in = (rb->in + 1) & ((uint32_t)UART_BUFFER_SIZE - 1);
    rb->count++;
}

/**
 * The function `QUEUE_Pull_Data` pulls data from a ring buffer and updates the buffer's out index and
 * count.
 * 
 * @param rb The parameter `rb` is a pointer to a structure of type `ring_buffer_t`.
 * 
 * @return The function `QUEUE_Pull_Data` is returning a `uint8_t` data value from the ring buffer
 * pointed to by the `rb` parameter.
 */
static uint8_t QUEUE_Pull_Data(ring_buffer_t *rb)
{
	register uint8_t data = *(rb->buffer + rb->out);

	rb->out = (rb->out + 1) & ((uint32_t)UART_BUFFER_SIZE - 1);
    rb->count--;

	return data;
}

/**
 * The function `QUEUE_Peek_Data` returns the data at the current output position of a ring buffer.
 * 
 * @param rb The parameter `rb` is a pointer to a `ring_buffer_t` structure, which likely represents a
 * ring buffer data structure.
 * 
 * @return The function `QUEUE_Peek_Data` is returning the data at the current output position in the
 * ring buffer `rb`.
 */
static inline uint8_t QUEUE_Peek_Data(ring_buffer_t *rb)
{
	return rb->buffer[rb->out];
}

/*********************
 * INTERRUPT FUNCTION
 *********************/

void UART_ISR (uart_cfg_t *uartstdio_device)
{
    /* if DR is not empty and the Rx Int is enabled */
    if ((LL_USART_IsActiveFlag_RXNE(uartstdio_device->uart) != RESET) &&
    			(LL_USART_IsEnabledIT_RXNE(uartstdio_device->uart) != RESET))
    {
        LL_USART_ReceiveData8(uartstdio_device->uart);
        uint8_t c = LL_USART_ReceiveData8(uartstdio_device->uart);

        if ((LL_USART_IsActiveFlag_ORE(uartstdio_device->uart) != RESET) ||
            (LL_USART_IsActiveFlag_FE(uartstdio_device->uart) != RESET) ||
            (LL_USART_IsActiveFlag_NE(uartstdio_device->uart) != RESET))
        {
          // if error, delete flag
          LL_USART_ClearFlag_ORE(uartstdio_device->uart);
          LL_USART_ClearFlag_FE(uartstdio_device->uart);
          LL_USART_ClearFlag_NE(uartstdio_device->uart);
        }
        else
        {
        	QUEUE_Push_Data ((ring_buffer_t *)&uartstdio_device->rx_buffer, c);
        }

        return;
    }

    /*If interrupt is caused due to Transmit Data Register Empty */
    if ((LL_USART_IsActiveFlag_TXE(uartstdio_device->uart) != RESET) &&
    			(LL_USART_IsEnabledIT_TXE(uartstdio_device->uart) != RESET))
    {
    	if (QUEUE_Is_Empty ((ring_buffer_t *)&uartstdio_device->tx_buffer))
    	{
    		LL_USART_DisableIT_TXE(uartstdio_device->uart);
    	}
    	else
    	{
    		uint8_t c = QUEUE_Pull_Data((ring_buffer_t *)&uartstdio_device->tx_buffer);
    		LL_USART_TransmitData8(uartstdio_device->uart, c);
    	}
        return;
    }
}
