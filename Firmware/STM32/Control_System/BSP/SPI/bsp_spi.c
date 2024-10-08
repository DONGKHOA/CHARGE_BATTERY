/*
 * bsp_spi.c
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "bsp_spi.h"

/**********************
 *   PRIVATE DEFINES
 **********************/

/**
 * @brief Timeout for waiting in milliseconds.
 *
 * This macro defines the timeout duration for waiting operations in
 * milliseconds.
 */
#define TIMEOUT_WAIT_SET 1000 /**< Timeout duration in ms. */

/**********************
 *  PRIVATE DATA
 **********************/

/**
 * @brief Timeout value for waiting for the buffer to empty.
 */
static volatile uint32_t u32_spi_timeout = 0;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief  Transmits data via SPI.
 *
 * This function transmits data to the SPI peripheral. It waits for the TXE bit
 * to set before writing data to the Data Register (DR) and then waits for the
 * BSY bit to reset after transmission. The overrun flag is cleared by reading
 * both DR and SR.
 *
 * @param  p_spi: Pointer to the SPI peripheral (SPI_TypeDef).
 * @param  p_data: Pointer to the buffer containing the data to be transmitted.
 * @param  size: Number of bytes to transmit.
 *
 * @retval spi_status_t: Status of the SPI communication.
 *         - SPI_OK: Transmission successful.
 *         - SPI_TIMEOUT: Timeout occurred during SPI transmission.
 *
 * @note  Ensure that the SPI peripheral is properly configured before calling
 *        this function. It waits for the TXE bit to set, indicating that the
 *        transmit buffer is empty, then writes data. After the last
 * transmission, the function waits for the BSY bit to reset before proceeding.
 */
spi_status_t
BSP_SPI_Transmit (SPI_TypeDef *p_spi, uint8_t *p_data, uint32_t size)
{
  for (uint32_t i = 0; i < size; i++)
  {
    u32_spi_timeout = TIMEOUT_WAIT_SET;

    // Wait for the TXE bit to set in the status register (SR)
    // This indicates that the transmit buffer is empty and ready for new data.
    while (!((p_spi->SR) & (1 << 1)))
    {
      if (u32_spi_timeout == 0)
      {
        return SPI_TIMEOUT;
      }
    };

    // Write data to the data register (DR)
    p_spi->DR = p_data[i];
  }

  /**
   * During discontinuous communications, there is a 2 APB clock period delay
   * between the write operation to the SPI_DR register and the BSY bit setting.
   * It is mandatory to wait first until TXE is set and then until BSY is
   * cleared after writing the last data.
   */
  u32_spi_timeout = TIMEOUT_WAIT_SET;

  // Wait for the TXE bit to set after the last data transmission
  while (!((p_spi->SR) & (1 << 1)))
  {
    if (u32_spi_timeout == 0)
    {
      return SPI_TIMEOUT;
    }
  };

  u32_spi_timeout = TIMEOUT_WAIT_SET;

  // Wait for the BSY bit to reset in the status register (SR)
  // This indicates that the SPI is not busy in communication.
  while (((p_spi->SR) & (1 << 7)))
  {
    if (u32_spi_timeout == 0)
    {
      return SPI_TIMEOUT;
    }
  };

  // Clear the Overrun flag by reading DR and SR
  volatile uint32_t tmpreg;
  tmpreg = p_spi->DR;
  (void)tmpreg;
  tmpreg = p_spi->SR;
  (void)tmpreg;

  return SPI_OK;
}

/**
 * @brief  Receives data via SPI.
 *
 * This function receives data from the SPI peripheral by sending dummy data
 * and reading the response from the data register. It waits for the BSY bit
 * to reset and the RXNE bit to set before reading the data.
 *
 * @param  p_spi: Pointer to the SPI peripheral (SPI_TypeDef).
 * @param  p_data: Pointer to the buffer where received data will be stored.
 * @param  size: Number of bytes to receive.
 *
 * @retval spi_status_t: Status of the SPI communication.
 *         - SPI_OK: Communication successful.
 *         - SPI_TIMEOUT: Timeout occurred during SPI communication.
 *
 * @note  Ensure that the SPI peripheral is properly configured before calling
 *        this function. The function waits for the BSY bit to reset, indicating
 *        that the SPI peripheral is not busy. Then it sends dummy data and
 * waits for the RXNE bit to set before reading the data register.
 */
spi_status_t
BSP_SPI_Receive (SPI_TypeDef *p_spi, uint8_t *p_data, uint32_t size)
{
  uint32_t index = 0;
  while (size)
  {
    u32_spi_timeout = TIMEOUT_WAIT_SET;

    // Wait for the BSY bit to reset in the status register (SR)
    // This indicates that the SPI peripheral is not busy in communication.
    while (((p_spi->SR) & (1 << 7)))
    {
      if (u32_spi_timeout == 0)
      {
        return SPI_TIMEOUT;
      }
    };

    // Send dummy data to initiate SPI reception
    p_spi->DR = 0;

    u32_spi_timeout = TIMEOUT_WAIT_SET;

    // Wait for the RXNE bit to set in the status register (SR)
    // This indicates that the Rx buffer is not empty and data is ready to be
    // read.
    while (!((p_spi->SR) & (1 << 0)))
    {
      if (u32_spi_timeout == 0)
      {
        return SPI_TIMEOUT;
      }
    };

    // Read the received data from the data register (DR)
    *(p_data + index) = (p_spi->DR);
    index++;
    size--;
  }
  return SPI_OK;
}

spi_status_t
BSP_SPI_TransmitReceive (SPI_TypeDef *p_spi,
                         uint8_t     *p_data_tx,
                         uint8_t     *p_data_rx,
                         uint32_t     size)
{
  uint32_t index = 0;
  while (size)
  {
    u32_spi_timeout = TIMEOUT_WAIT_SET;

    // Wait for the BSY bit to reset in the status register (SR)
    // This indicates that the SPI peripheral is not busy in communication.
    while (((p_spi->SR) & (1 << 7)))
    {
      if (u32_spi_timeout == 0)
      {
        return SPI_TIMEOUT;
      }
    };

    // Write data to the data register (DR)
    p_spi->DR = *(p_data_tx + index);

    u32_spi_timeout = TIMEOUT_WAIT_SET;

    // Wait for the RXNE bit to set in the status register (SR)
    // This indicates that the Rx buffer is not empty and data is ready to be
    // read.
    while (!((p_spi->SR) & (1 << 0)))
    {
      if (u32_spi_timeout == 0)
      {
        return SPI_TIMEOUT;
      }
    };

    // Read the received data from the data register (DR)
    *(p_data_rx + index) = (p_spi->DR);
    index++;
    size--;
  }
  return SPI_OK;
}

/**
 * The function `BSP_SPI_TimeOut` decrements the variable `u32_uart_timeout` if
 * it is not equal to 0.
 */
void
BSP_SPI_TimeOut (void)
{
  if (u32_spi_timeout != 0)
  {
    u32_spi_timeout--;
  }
}
