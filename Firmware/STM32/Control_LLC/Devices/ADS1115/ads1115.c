/*
 * ads1115.c
 *
 *  Created on: Jul 13, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "main.h"
#include "ads1115.h"
#include "i2c.h"

/**********************
 *    PRIVATE DEFINE
 **********************/

#define ADS1115_MAX_CHANNEL 4

#define ADS1115_RESOLUTION 16 // bit
#define ADS1115_STEP       (1 << (ADS1115_RESOLUTION - 1))

/**********************
 *    PRIVATE DATA
 **********************/

static uint8_t             i2c_buffer[3];
#if I2C_LL
static volatile i2c_data_t i2c_1;
#endif

/**********************
 *    EXTERN DATA
 **********************/

#if !I2C_LL
  extern I2C_HandleTypeDef hi2c1;
#endif

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
ADS1115_SetPara (void)
{
#if I2C_LL
  i2c_1.p_i2c_reg = I2C1;                   // Assign register I21
  i2c_1.buffer    = (uint8_t *)&i2c_buffer; // Assign buffer
  i2c_1.address   = ADS_ADDR_GND << 1;      // Assign address Slave
#endif
}

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
ADS1115_GetData (ads1115_channel_t channel, ads1115_gain_t gain)
{
  // Start with default values
  uint16_t config
      = ADS1015_REG_CONFIG_CQUE_NONE |   // Disable the comparator (default val)
        ADS1015_REG_CONFIG_CLAT_NONLAT | // Non-latching (default val)
        ADS1015_REG_CONFIG_CPOL_ACTVLOW
        |                               // Alert/Rdy active low   (default val)
        ADS1015_REG_CONFIG_CMODE_TRAD | // Traditional comparator (default val)
        ADS1015_REG_CONFIG_DR_1600SPS | // 1600 samples per second (default)
        ADS1015_REG_CONFIG_MODE_SINGLE; // Single-shot mode (default)

  // Set PGA/voltage range
  config |= gain;
  switch (channel)
  {
    case DEV_ADS1115_CHANNEL_0:
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_0;
      break;
    case DEV_ADS1115_CHANNEL_1:
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_1;
      break;
    case DEV_ADS1115_CHANNEL_2:
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_2;
      break;
    case DEV_ADS1115_CHANNEL_3:
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_3;
      break;
  }

  // Set 'start single-conversion' bit
  config |= ADS1015_REG_CONFIG_OS_SINGLE;
  i2c_buffer[0]     = ADS1015_REG_POINTER_CONFIG;
  i2c_buffer[1]     = (uint8_t)(config >> 8);
  i2c_buffer[2]     = (uint8_t)(config & 0xFF);
#if I2C_LL
  i2c_1.size_buffer = 3;
  BSP_I2C_MasterTransmit7B((i2c_data_t *)&i2c_1);
  if (i2c_1.status == I2C_TIMEOUT)
  {
    return 0;
  }
#else
  HAL_I2C_Master_Transmit(&hi2c1, ADS_ADDR_GND << 1, i2c_buffer, 3, 10);
#endif


  // Read data
  i2c_buffer[0]     = ADS1015_REG_POINTER_CONVERT;
#if I2C_LL
  i2c_1.size_buffer = 1;
  BSP_I2C_MasterTransmit7B((i2c_data_t *)&i2c_1);
  if (i2c_1.status == I2C_TIMEOUT)
  {
    return 0;
  }
#else
  HAL_I2C_Master_Transmit(&hi2c1, ADS_ADDR_GND << 1, &i2c_buffer[0], 1, 10);
#endif


#if I2C_LL
  i2c_1.size_buffer = 2;
  BSP_I2C_MasterReceive7B((i2c_data_t *)&i2c_1);
  if (i2c_1.status == I2C_TIMEOUT)
  {
    return 0;
  }
#else
  HAL_I2C_Master_Receive(&hi2c1, ADS_ADDR_GND << 1, i2c_buffer, 2, 10);
#endif

  return (uint16_t)(i2c_buffer[0] << 8 | i2c_buffer[1]);
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
ADS1115_ReadVoltage (ads1115_channel_t channel, ads1115_gain_t gain)
{
  /**< Read raw Data */
  uint16_t value = ADS1115_GetData(channel, gain);

  /**< Calibrate ADC */

  /**< Convert voltage */
  return (float)(value * ADS1115_VREF) / ADS1115_STEP;
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
