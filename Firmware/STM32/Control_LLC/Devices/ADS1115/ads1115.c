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

#define ADS1115_ADDRESS 		0x48
#define ADS1115_MAX_CHANNEL		4

#define ADS1115_VREF			4096	// mV
#define ADS1115_RESOLUTION		16		// bit
#define ADS1115_STEP			(1 << ADS1115_RESOLUTION)

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

static volatile uint8_t i2c_buffer[3];
static volatile i2c_data_t i2c_1 =
{
		.i2c_reg = I2C1,			// Assign register I21
		.buffer = i2c_buffer,		// Assign buffer
		.address = ADS1115_ADDRESS	// Assign address Slave
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
 * @param channel The channel to read from (CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3).
 * @return The data reading from the specified channel. If a timeout occurs, returns 0.
 */
uint16_t ADS1115_GetData(ads1115_channel_t channel)
{
	i2c_1.buffer[0] = 0x01;
	switch (channel)
	{
		case CHANNEL_0:
			i2c_1.buffer[1] = 0xC1;
			break;
		case CHANNEL_1:
			i2c_1.buffer[1] = 0xD1;
			break;
		case CHANNEL_2:
			i2c_1.buffer[1] = 0xE1;
			break;
		case CHANNEL_3:
			i2c_1.buffer[1] = 0xF1;
			break;
	}

	i2c_1.buffer[0] = 0x83;
	i2c_1.size_buffer = 3;
	I2C_MasterTransmit7B((i2c_data_t *)&i2c_1);
	if (i2c_1.status == I2C_TIMEOUT) return 0;

	i2c_1.buffer[0] = 0x00;
	i2c_1.size_buffer = 1;
	I2C_MasterTransmit7B((i2c_data_t *)&i2c_1);
	if (i2c_1.status == I2C_TIMEOUT) return 0;

	LL_mDelay(20);
	i2c_1.size_buffer = 2;
	I2C_MasterReceive7B((i2c_data_t *)&i2c_1);

	data[channel].data_reading = (i2c_1.buffer[0] << 8 | i2c_1.buffer[1]);
	if (data[channel].data_reading < 0)	data[channel].data_reading = 0;

	return data[channel].data_reading;
}

float ADS1115_Voltage(ads1115_channel_t channel)
{
	/**< Read raw Data */
	ADS1115_GetData(channel);

	/**< Calibrate ADC */

	/**< Convert voltage */
	data[0].voltage =
        (float)(data[0].data_reading * ADS1115_VREF) / ADS1115_STEP;

	return data[channel].voltage;
}
