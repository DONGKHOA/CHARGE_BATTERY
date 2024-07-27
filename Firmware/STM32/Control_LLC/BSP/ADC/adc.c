/*
 * adc.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "adc.h"
#include "stm32f1xx_ll_adc.h"
#include "stm32f1xx_ll_dma.h"

/**********************
 *   PRIVATE DEFINES
 **********************/

/**
 * @brief Timeout for ADC conversion wait in milliseconds.
 */
#define TIMEOUT_WAIT_CONVERTION 1000 /**< Timeout duration in ms. */

/**
 * @brief Reference analog voltage in millivolts.
 */
#define VREFANALOG 3300 /**< Reference voltage in mV. */

/**********************
 *   PRIVATE DATA
 **********************/

static volatile uint_fast32_t timer_wait_converstion = 0;
static volatile bool          enable_read_data;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Configure ADC parameters in the provided structure.
 *
 * @param p_data Pointer to adc_data_t structure to be configured.
 * @param _num_channel Number of channels in the ADC sequence.
 * @param _channel_table Pointer to the channel table array.
 * @param _adc_data Pointer to the ADC data buffer.
 */
adc_status_t
BSP_ADC_Config (adc_data_t *p_data,
                uint32_t    _num_channel,
                uint32_t   *_channel_table,
                uint32_t   *_adc_data)
{
  p_data->num_channel   = _num_channel;
  p_data->channel_table = _channel_table;
  p_data->adc_data      = _adc_data;
  p_data->status        = ADC_OK;

  if (p_data->num_channel > 1)
  {
    LL_ADC_REG_SetDMATransfer(p_data->ADCx, LL_ADC_REG_DMA_TRANSFER_UNLIMITED);
    LL_DMA_ConfigAddresses(
        DMA1,
        LL_DMA_CHANNEL_1,
        LL_ADC_DMA_GetRegAddr(p_data->ADCx, LL_ADC_DMA_REG_REGULAR_DATA),
        (uint32_t)&p_data->adc_data,
        LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
    LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, p_data->num_channel);
    LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);
    LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);
  }

  LL_ADC_StartCalibration(p_data->ADCx);
  while (LL_ADC_IsCalibrationOnGoing(p_data->ADCx))
  {
    if (timer_wait_converstion == 0)
    {
      p_data->status = ADC_TIMEOUT;
      return p_data->status;
    }
  }

  LL_ADC_Enable(p_data->ADCx);
  p_data->status = ADC_OK;
  return p_data->status;
}

/**
 * @brief Starts the ADC conversion process.
 *
 * This function initiates the ADC conversion using software start and updates
 * the status of the ADC operation to indicate that conversion has started.
 *
 * @param p_data Pointer to the ADC configuration data structure.
 * @return The status of the ADC operation after starting the conversion.
 */
adc_status_t
BSP_ADC_StartConvert (adc_data_t *p_data)
{
  LL_ADC_REG_StartConversionSWStart(p_data->ADCx);
  p_data->status = ADC_START_CONVERT;
  return p_data->status;
}

/**
 * @brief Reads the ADC conversion data and calculates the corresponding
 * voltages.
 *
 * This function checks if ADC data reading is enabled. If enabled, it reads the
 * ADC data from the specified channels and calculates the corresponding
 * voltages. The status is then updated to indicate a successful read operation.
 * If reading is not enabled, the status is updated to indicate that the ADC is
 * waiting for conversion.
 *
 * @param p_data Pointer to the ADC configuration data structure.
 * @return The status of the ADC operation after attempting to read the data.
 */
adc_status_t
BSP_ADC_Read (adc_data_t *p_data)
{
  if (enable_read_data == 1)
  {
    __disable_irq();
    for (uint8_t i = 0; i < p_data->num_channel; i++)
    {
      p_data->adc_voltage_data[i] = __LL_ADC_CALC_DATA_TO_VOLTAGE(
          VREFANALOG, p_data->channel_table[i], LL_ADC_RESOLUTION_12B);
    }
    enable_read_data = 0;
    p_data->status   = ADC_OK;
    __enable_irq();
    return p_data->status;
  }
  p_data->status = ADC_WAIT_CONVERT;
  return p_data->status;
}

/**
 * @brief Decrements the ADC conversion timeout timer.
 *
 * This function decrements the timer used for ADC conversion timeout
 * if the timer value is greater than or equal to zero.
 */
void
BSP_ADC_TimeOut (void)
{
  if (timer_wait_converstion >= 0)
  {
    timer_wait_converstion--;
  }
}

/**
 * @brief DMA completion callback function for ADC data transfer.
 *
 * This function checks if the DMA transfer complete flag is set for ADC DMA
 * channel 1. If the flag is set, it clears the flag and sets a flag
 * (`enable_read_data`) to indicate that ADC data is ready to be processed.
 *
 * @param p_data Pointer to the ADC configuration data structure.
 */
void
BSP_ADC_DMA_Function (adc_data_t *p_data)
{
  if (LL_DMA_IsActiveFlag_TC1(DMA1) != RESET)
  {
    /* Clear DMA transfer complete flag */
    LL_DMA_ClearFlag_TC1(DMA1);

    /* Set flag to indicate data ready for processing */
    enable_read_data = 1;
  }
}
