/*
 * ads1115.c
 *
 *  Created on: Jul 13, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx_ll_utils.h"
#include "ads1115.h"
#include "i2c.h"

/**********************
 *    PRIVATE DEFINE
 **********************/

#define ADS1115_ADDRESS     0x48
#define ADS1115_MAX_CHANNEL 4

#define ADS1115_RESOLUTION 16 // bit
#define ADS1115_STEP       (1 << ADS1115_RESOLUTION)

/*********************
 *    PRIVATE TYPEDEFS
 *********************/

/**
 * @brief Structure to hold ADS1115 sensor data.
 */
typedef struct _ads1115_data_t
{
  /**
   * @brief The raw data reading from the IC.
   */
  volatile uint16_t data_reading;

  /**
   * @brief The converted voltage value from the IC.
   */
  volatile float voltage;
} ads1115_data_t;

/**********************
 *    PRIVATE DATA
 **********************/

/**
 * @brief Storage Data read from IC.
 */
static volatile ads1115_data_t data[ADS1115_MAX_CHANNEL];

static volatile uint8_t    i2c_buffer[3];
static volatile i2c_data_t i2c_1 = {
  .i2c_reg = I2C1,           // Assign register I21
  .buffer  = i2c_buffer,     // Assign buffer
  .address = ADS1115_ADDRESS // Assign address Slave
};

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Reads data from the ADS1115 sensor for a specified channel.
 *
 * This function configures the ADS1115 sensor to read data from a specified
 * channel, waits for the data to be ready, and then reads the data from the
 * sensor. It handles I2C communication and checks for timeouts.
 *
 * @param channel The channel to read from (DEV_ADS1115_CHANNEL_0,
 * DEV_ADS1115_CHANNEL_1, DEV_ADS1115_CHANNEL_2, DEV_ADS1115_CHANNEL_3).
 * @return The data reading from the specified channel. If a timeout occurs,
 * returns 0.
 */
uint16_t
ADS1115_GetData (ads1115_channel_t channel)
{
  i2c_1.buffer[0] = 0x01;
  switch (channel)
  {
    case DEV_ADS1115_CHANNEL_0:
      i2c_1.buffer[1] = 0xC1;
      break;
    case DEV_ADS1115_CHANNEL_1:
      i2c_1.buffer[1] = 0xD1;
      break;
    case DEV_ADS1115_CHANNEL_2:
      i2c_1.buffer[1] = 0xE1;
      break;
    case DEV_ADS1115_CHANNEL_3:
      i2c_1.buffer[1] = 0xF1;
      break;
  }

  i2c_1.buffer[0]   = 0x83;
  i2c_1.size_buffer = 3;
  BSP_I2C_MasterTransmit7B((i2c_data_t *)&i2c_1);
  if (i2c_1.status == I2C_TIMEOUT)
  {
    return 0;
  }

  i2c_1.buffer[0]   = 0x00;
  i2c_1.size_buffer = 1;
  BSP_I2C_MasterTransmit7B((i2c_data_t *)&i2c_1);
  if (i2c_1.status == I2C_TIMEOUT)
  {
    return 0;
  }

  LL_mDelay(20);
  i2c_1.size_buffer = 2;
  BSP_I2C_MasterReceive7B((i2c_data_t *)&i2c_1);

  data[channel].data_reading = (i2c_1.buffer[0] << 8 | i2c_1.buffer[1]);
  if (data[channel].data_reading < 0)
  {
    data[channel].data_reading = 0;
  }

  return data[channel].data_reading;
}

/**
 * The function ADS1115_ReadVoltage reads raw data from a specified channel,
 * calibrates the ADC, converts the voltage, and returns the voltage value.
 *
 * @param channel The `channel` parameter in the `ADS1115_ReadVoltage` function
 * represents the specific channel of the ADS1115 analog-to-digital converter
 * from which you want to read the voltage. It is of type `ads1115_channel_t`,
 * which is likely an enumeration or a defined type that specifies
 *
 * @return The function `ADS1115_ReadVoltage` is returning the voltage value
 * read from the specified channel after converting the raw data reading to
 * voltage using the ADC reference voltage and step size.
 */
float
ADS1115_ReadVoltage (ads1115_channel_t channel)
{
  /**< Read raw Data */
  ADS1115_GetData(channel);

  /**< Calibrate ADC */

  /**< Convert voltage */
  data[0].voltage = (float)(data[0].data_reading * ADS1115_VREF) / ADS1115_STEP;

  return data[channel].voltage;
}

/**
 * The function ADS1115_GetVoltage converts a raw ADC value to voltage using a
 * specific formula.
 *
 * @param value_adc The `value_adc` parameter represents the raw ADC
 * (Analog-to-Digital Converter) value read from the ADS1115 ADC module.
 *
 * @return The function `ADS1115_GetVoltage` returns the voltage value
 * calculated based on the input `value_adc` using the formula `(value_adc *
 * ADS1115_VREF) / ADS1115_STEP`.
 */
float
ADS1115_GetVoltage (uint16_t value_adc)
{
  /**< Convert voltage */
  float voltage = (float)(value_adc * ADS1115_VREF) / ADS1115_STEP;
  return voltage;
}