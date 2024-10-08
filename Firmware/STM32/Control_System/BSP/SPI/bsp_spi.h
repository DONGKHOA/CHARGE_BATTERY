/*
 * bsp_spi.h
 *
 *  Created on: Sep 30, 2024
 *      Author: dongkhoa
 */

#ifndef SPI_BSP_SPI_H_
#define SPI_BSP_SPI_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f4xx_ll_spi.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/

  /**
   * @brief Enumeration for SPI operation status.
   *
   * This enum defines the possible statuses for SPI operations, including
   * timeout and successful operation.
   */
  typedef enum _spi_status_t
  {
    SPI_TIMEOUT = 0, /**< @brief SPI operation timed out. */
    SPI_OK           /**< @brief SPI operation successful. */
  } spi_status_t;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  spi_status_t BSP_SPI_Transmit(SPI_TypeDef *p_spi,
                                uint8_t     *p_data,
                                uint32_t     size);
  spi_status_t BSP_SPI_Receive(SPI_TypeDef *p_spi,
                               uint8_t     *p_data,
                               uint32_t     size);
  spi_status_t BSP_SPI_TransmitReceive(SPI_TypeDef *p_spi,
                                       uint8_t     *p_data_tx,
                                       uint8_t     *p_data_rx,
                                       uint32_t     size);

  // Call Function "BSP_SPI_TimeOut" in ISR SysTick
  void BSP_SPI_TimeOut(void);

#ifdef __cplusplus
}
#endif

#endif /* SPI_BSP_SPI_H_ */
