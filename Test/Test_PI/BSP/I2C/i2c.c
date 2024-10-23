/*
 * i2c.c
 *
 *  Created on: Jul 13, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "i2c.h"
#include "stm32f1xx_ll_i2c.h"

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
 *   PRIVATE DATA
 **********************/

static volatile uint_fast32_t u32_timer_wait_set = 0;

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static i2c_status_t I2C_MasterStart(I2C_TypeDef *_i2c_reg);
static void         I2C_MastterStop(I2C_TypeDef *_i2c_reg);

static i2c_status_t I2C_SetAddress7B(I2C_TypeDef *_i2c_reg, uint8_t _address);
static i2c_status_t I2C_TransmitData7B(I2C_TypeDef *_i2c_reg,
                                       uint32_t     _size,
                                       uint8_t     *_buffer);
static i2c_status_t I2C_WaitBitRXNE(I2C_TypeDef *_i2c_reg);

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Transmits data over I2C in 7-bit addressing mode.
 *
 * This function handles the complete I2C master transmission sequence,
 * including generating the START condition, transmitting the address and data,
 * and generating the STOP condition.
 *
 * @param p_i2c Pointer to the I2C configuration data structure.
 * @return Status of the I2C operation.
 */
i2c_status_t
BSP_I2C_MasterTransmit7B (i2c_data_t *p_i2c)
{
  // Start Condition
  p_i2c->status = I2C_MasterStart((I2C_TypeDef *)p_i2c->i2c_reg);
  if (p_i2c->status == I2C_TIMEOUT)
  {
    return I2C_TIMEOUT;
  }

  // Transmit Address, Clear ADDR bit
  p_i2c->status = I2C_SetAddress7B((I2C_TypeDef *)p_i2c->i2c_reg,
                                   (uint16_t)p_i2c->address);
  if (p_i2c->status == I2C_TIMEOUT)
  {
    return I2C_TIMEOUT;
  }

  // Transmit Data
  p_i2c->status = I2C_TransmitData7B((I2C_TypeDef *)p_i2c->i2c_reg,
                                     (uint32_t)p_i2c->size_buffer,
                                     (uint8_t *)p_i2c->buffer);
  if (p_i2c->status == I2C_TIMEOUT)
  {
    return I2C_TIMEOUT;
  }

  // Stop Condition
  I2C_MastterStop((I2C_TypeDef *)p_i2c->i2c_reg);

  // Done Transmit Frame
  p_i2c->status = I2C_OK;
  return I2C_OK;
}

/**** STEPS FOLLOWED  ************
1. If only 1 BYTE needs to be Read
    a) Write the slave Address, and wait for the ADDR bit (bit 1 in SR1) to be
       set
    b) The Acknowledge disable is made during EV6 (before ADDR flag is cleared)
       and the STOP condition generation is made after EV6
    c) Wait for the RXNE (Receive Buffer not Empty) bit to set
    d) Read the data from the DR

2. If Multiple BYTES needs to be read
    a) Write the slave Address, and wait for the ADDR bit (bit 1 in SR1) to be
       set
    b) Clear the ADDR bit by reading the SR1 and SR2 Registers
    c) Wait for the RXNE (Receive buffer not empty) bit to set
    d) Read the data from the DR
    e) Generate the Acknowledgment by setting the ACK (bit 10 in SR1)
    f) To generate the non-acknowledge pulse after the last received data byte,
       the ACK bit must be cleared just after reading the second last data byte
       (after second last RxNE event)
    g) In order to generate the Stop/Restart condition, software must set the
       STOP/START bit after reading the second last data byte (after the second
       last RxNE event)
*/

/**
 * @brief Receives data over I2C in 7-bit addressing mode.
 *
 * This function handles the complete I2C master reception sequence, including
 * generating the START condition, transmitting the address, receiving the data,
 * and generating the STOP condition.
 *
 * @param p_i2c Pointer to the I2C configuration data structure.
 * @return Status of the I2C operation.
 */
i2c_status_t
BSP_I2C_MasterReceive7B (i2c_data_t *p_i2c)
{
  uint32_t remaining = p_i2c->size_buffer;
  // Start Condition
  p_i2c->status = I2C_MasterStart((I2C_TypeDef *)p_i2c->i2c_reg);
  if (p_i2c->status == I2C_TIMEOUT)
  {
    return I2C_TIMEOUT;
  }

  // Transmit Address, Clear ADDR bit
  I2C_SetAddress7B((I2C_TypeDef *)p_i2c->i2c_reg, (uint8_t)p_i2c->address);

  // Receive Data
  if (p_i2c->size_buffer == 1)
  {
    goto last_byte;
  }

  while (remaining > 2)
  {
    // Wait for RxNE to set
    p_i2c->status = I2C_WaitBitRXNE((I2C_TypeDef *)p_i2c->i2c_reg);
    if (p_i2c->status == I2C_TIMEOUT)
    {
      return I2C_TIMEOUT;
    }

    // Copy the data into the buffer
    p_i2c->buffer[p_i2c->size_buffer - remaining]
        = LL_I2C_ReceiveData8((I2C_TypeDef *)p_i2c->i2c_reg);

    // Set the ACK bit to Acknowledge the data received
    p_i2c->i2c_reg->CR1 = (p_i2c->i2c_reg->CR1) | I2C_CR1_ACK_Msk;

    remaining--;
  }
  // Read the SECOND LAST BYTE
  // Wait for RxNE to set
  p_i2c->status = I2C_WaitBitRXNE((I2C_TypeDef *)p_i2c->i2c_reg);
  if (p_i2c->status == I2C_TIMEOUT)
  {
    return I2C_TIMEOUT;
  }

  // Copy the data into the buffer
  p_i2c->buffer[p_i2c->size_buffer - remaining]
      = LL_I2C_ReceiveData8((I2C_TypeDef *)p_i2c->i2c_reg);
  remaining--;

last_byte:

  // Clear ACK bit
  p_i2c->i2c_reg->CR1 = (p_i2c->i2c_reg->CR1) & ~I2C_CR1_ACK_Msk;

  // Stop I2C
  I2C_MastterStop((I2C_TypeDef *)p_i2c->i2c_reg);

  // Wait for RxNE to set
  p_i2c->status = I2C_WaitBitRXNE((I2C_TypeDef *)p_i2c->i2c_reg);
  if (p_i2c->status == I2C_TIMEOUT)
  {
    return I2C_TIMEOUT;
  }

  // Copy the data into the buffer
  p_i2c->buffer[p_i2c->size_buffer - remaining]
      = LL_I2C_ReceiveData8((I2C_TypeDef *)p_i2c->i2c_reg);

  // Done Receive Frame
  p_i2c->status = I2C_OK;
  return I2C_OK;
}

/**
 * @brief Decrements the u32_timer_wait_set variable for I2C timeout handling.
 *
 * This function decrements the u32_timer_wait_set variable used for handling
 * I2C timeouts.
 */
void
BSP_I2C_TimeOut (void)
{
  if (u32_timer_wait_set >= 0)
  {
    u32_timer_wait_set--;
  }
}

/**********************
 *   PRIVATE FUNCTIONS
 **********************/

/**
 * @brief Starts the I2C master transmission.
 *
 * This function enables the ACK and generates the START condition for I2C
 * communication.
 *
 * @param _i2c_reg Pointer to the I2C peripheral instance.
 * @return Status of the I2C operation.
 */
static i2c_status_t
I2C_MasterStart (I2C_TypeDef *_i2c_reg)
{
  _i2c_reg->CR1 |= I2C_CR1_ACK_Msk;   // Enable the ACK
  _i2c_reg->CR1 |= I2C_CR1_START_Msk; // Generate START

  // Wait for PE bit to set
  u32_timer_wait_set = TIMEOUT_WAIT_SET;
  while (LL_I2C_IsEnabled(_i2c_reg))
  {
    if (u32_timer_wait_set == 0)
    {
      return I2C_TIMEOUT;
    }
  }
  return I2C_OK;
}

/**
 * @brief Generates the STOP condition for I2C communication.
 *
 * This function generates the STOP condition to end the I2C communication.
 *
 * @param _i2c_reg Pointer to the I2C peripheral instance.
 */
static void
I2C_MastterStop (I2C_TypeDef *_i2c_reg)
{
  LL_I2C_GenerateStopCondition(_i2c_reg);
}

/**** STEPS FOLLOWED  ************
1. Send the Slave Address to the DR Register
2. Wait for the ADDR (bit 1 in SR1) to set. This indicates the end of address
   transmission
3. Clear the ADDR by reading the SR1 and SR2
*/

/**
 * @brief Sets the 7-bit address for the I2C communication.
 *
 * This function sends the 7-bit address to the Data Register (DR), waits for
 * the ADDR bit to be set, and clears the ADDR bit by reading the SR1 and SR2
 * registers.
 *
 * @param _i2c_reg Pointer to the I2C peripheral instance.
 * @param _address 7-bit address of the I2C device.
 * @return Status of the I2C operation.
 */
static i2c_status_t
I2C_SetAddress7B (I2C_TypeDef *_i2c_reg, uint8_t _address)
{
  // Send the address
  I2C1->DR = _address;

  // Wait for ADDR bit to set
  u32_timer_wait_set = TIMEOUT_WAIT_SET;
  while (!LL_I2C_IsActiveFlag_ADDR(_i2c_reg))
  {
    if (u32_timer_wait_set == 0)
    {
      return I2C_TIMEOUT;
    }
  }

  // Read SR1 and SR2 to clear the ADDR bit
  LL_I2C_ClearFlag_ADDR(_i2c_reg);

  return I2C_OK;
}

/**** STEPS FOLLOWED  ************
1. Wait for the TXE (bit 7 in SR1) to set. This indicates that the DR is empty
2. Keep Sending DATA to the DR Register after performing the check if the TXE
   bit is set
3. Once the DATA transfer is complete, Wait for the BTF (bit 2 in SR1) to set.
   This indicates the end of LAST DATA transmission
*/

/**
 * @brief Transmits data over I2C in 7-bit addressing mode.
 *
 * This function waits for the TXE bit to set, indicating the DR is empty, then
 * transmits data from the buffer to the DR register. It waits for the BTF bit
 * to set, indicating the end of the last data transmission.
 *
 * @param _i2c_reg Pointer to the I2C peripheral instance.
 * @param _size    Size of the data buffer.
 * @param _buffer  Pointer to the data buffer.
 * @return Status of the I2C operation.
 */
static i2c_status_t
I2C_TransmitData7B (I2C_TypeDef *_i2c_reg, uint32_t _size, uint8_t *_buffer)
{
  // Wait for TXE bit to set
  u32_timer_wait_set = TIMEOUT_WAIT_SET;
  while (!LL_I2C_IsActiveFlag_TXE(_i2c_reg))
  {
    if (u32_timer_wait_set == 0)
    {
      return I2C_TIMEOUT;
    }
  }

  while (_size > 0)
  {
    // Wait for TXE bit to set
    u32_timer_wait_set = TIMEOUT_WAIT_SET;
    while (!LL_I2C_IsActiveFlag_TXE(_i2c_reg))
    {
      if (u32_timer_wait_set == 0)
      {
        return I2C_TIMEOUT;
      }
    }

    // Transmit Data
    I2C1->DR = (uint32_t)*_buffer++;
    _size--;
  }

  // Wait for BTF to set
  u32_timer_wait_set = TIMEOUT_WAIT_SET;
  while (!LL_I2C_IsActiveFlag_BTF(_i2c_reg))
  {
    if (u32_timer_wait_set == 0)
    {
      return I2C_TIMEOUT;
    }
  }

  return I2C_OK;
}

/**
 * @brief Waits for the RXNE bit to be set.
 *
 * This function waits for the RXNE bit to be set, indicating that data is ready
 * to be read from the Data Register (DR).
 *
 * @param _i2c_reg Pointer to the I2C peripheral instance.
 * @return Status of the I2C operation.
 */
static i2c_status_t
I2C_WaitBitRXNE (I2C_TypeDef *_i2c_reg)
{
  u32_timer_wait_set = TIMEOUT_WAIT_SET;
  while (!LL_I2C_IsActiveFlag_RXNE(_i2c_reg))
  {
    if (u32_timer_wait_set == 0)
    {
      return I2C_TIMEOUT;
    }
  }
  return I2C_OK;
}
