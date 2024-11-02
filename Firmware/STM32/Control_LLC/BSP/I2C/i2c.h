/*
 * i2c.h
 *
 *  Created on: Jul 13, 2024
 *      Author: dongkhoa
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef I2C_LL
	#define I2C_LL 0
#endif

#if I2C_LL

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/

  /**
   * @brief Enumeration for I2C operation status.
   *
   * This enum defines the possible statuses for I2C operations, including
   * timeout and successful operation.
   */
  typedef enum _i2c_status_t
  {
    I2C_TIMEOUT = 0, /**< @brief I2C operation timed out. */
    I2C_OK           /**< @brief I2C operation successful. */
  } i2c_status_t;

  /**
   * @brief Structure to hold I2C configuration data.
   *
   * This structure contains the I2C peripheral instance, the buffer for I2C
   * data, the size of the buffer, the status of the I2C operation, and the
   * address of the I2C device.
   */
  typedef struct _i2c_data_t
  {
    I2C_TypeDef *p_i2c_reg; /**< @brief Pointer to the I2C peripheral. */
    uint8_t     *buffer; /**< @brief Pointer to the I2C data buffer. */
    uint32_t size_buffer; /**< @brief Size of the I2C data buffer. */
    i2c_status_t status;  /**< @brief Status of the I2C operation. */
    uint16_t     address; /**< @brief Address of the I2C device. */
  } i2c_data_t;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  i2c_status_t BSP_I2C_MasterTransmit7B(i2c_data_t *p_i2c);
  i2c_status_t BSP_I2C_MasterReceive7B(i2c_data_t *p_i2c);

  // Call Function "I2C_TimeOut" in ISR SysTick
  void BSP_I2C_TimeOut(void);

#endif

#ifdef __cplusplus
}
#endif

#endif /* I2C_I2C_H_ */
