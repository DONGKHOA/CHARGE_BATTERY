/*
 * adc.c
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "bsp_adc.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_dma.h"

/**********************
 *   PRIVATE DEFINES
 **********************/

/**
 * @brief Timeout for ADC conversion wait in milliseconds.
 */
#define TIMEOUT_WAIT_CONVERTION 2000 /**< Timeout duration in ms. */

/**
 * @brief Reference analog voltage in millivolts.
 */
#define VREFANALOG 3300 /**< Reference voltage in mV. */

/**********************
 *   PRIVATE DATA
 **********************/

static volatile uint_fast32_t u32_timer_wait_converstion = 0;
static volatile bool          b_enable_read_data;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * @brief Configure ADC parameters in the provided structure.
 *
 * @param p_data Pointer to adc_data_t structure to be configured.
 */
adc_status_t
BSP_ADC_Config (adc_data_t *p_data)
{
//  p_data->e_status = BSP_ADC_OK;
//
//  if (p_data->u32_num_channel > 1)
//  {
//    LL_ADC_REG_SetDMATransfer(p_data->p_ADCx,
//                              LL_ADC_REG_DMA_TRANSFER_UNLIMITED);
//    LL_DMA_ConfigAddresses(
//        DMA1,
//        LL_DMA_CHANNEL_1,
//        LL_ADC_DMA_GetRegAddr(p_data->p_ADCx, LL_ADC_DMA_REG_REGULAR_DATA),
//        (uint32_t)&p_data->p_adc_data,
//        LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
//    LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, p_data->u32_num_channel);
//    LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);
//    LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);
//  }
//
//  LL_ADC_StartCalibration(p_data->p_ADCx);
//  u32_timer_wait_converstion = TIMEOUT_WAIT_CONVERTION;
//  while (LL_ADC_IsCalibrationOnGoing(p_data->p_ADCx))
//  {
//    if (u32_timer_wait_converstion == 0)
//    {
//      p_data->e_status = BSP_ADC_TIMEOUT;
//      return p_data->e_status;
//    }
//  }
//
//  LL_ADC_Enable(p_data->p_ADCx);
//  p_data->e_status = BSP_ADC_OK;
//  return p_data->e_status;
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
  LL_ADC_REG_StartConversionSWStart(p_data->p_ADCx);
  p_data->e_status = BSP_ADC_START_CONVERT;
  return p_data->e_status;
}

/**
 * @brief Waits for ADC conversion to complete.
 *
 * This function waits for the ADC conversion to complete by monitoring the
 * End of Conversion (EOS) flag. If the conversion does not complete within
 * a specified timeout period, it sets the status to `BSP_ADC_TIMEOUT`. If the
 * conversion completes successfully, it clears the EOS flag and sets the
 * status to `BSP_ADC_OK`.
 *
 * @param p_data Pointer to the ADC data structure.
 * @return The status of the ADC conversion.
 */
adc_status_t
BSP_ADC_WaitConversion (adc_data_t *p_data)
{
  u32_timer_wait_converstion = TIMEOUT_WAIT_CONVERTION;

  while (!LL_ADC_IsActiveFlag_JEOS(p_data->p_ADCx))
  {
    if (u32_timer_wait_converstion == 0)
    {
      p_data->e_status = BSP_ADC_TIMEOUT;
      return p_data->e_status;
    }
  }

  // Clear the End of Conversion flag
  LL_ADC_ClearFlag_JEOS(p_data->p_ADCx);

  // Set flag to indicate data ready for processing
  b_enable_read_data = 1;

  p_data->e_status = BSP_ADC_OK;
  return p_data->e_status;
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
adc_status_t BSP_ADC_Read(adc_data_t *p_data)
{
    if (b_enable_read_data == 1)
    {
        if (p_data->u32_num_channel == 1)
        {
            // Read ADC conversion data for a single channel
            p_data->p_adc_data[0] = LL_ADC_REG_ReadConversionData12(p_data->p_ADCx);
            // Calculate the voltage for the single channel
            p_data->p_adc_voltage_data[0] = __LL_ADC_CALC_DATA_TO_VOLTAGE(
                VREFANALOG, p_data->p_adc_data[0], LL_ADC_RESOLUTION_12B);
        }
        else
        {
            // Calculate voltages for multiple channels
            for (uint8_t i = 0; i < p_data->u32_num_channel; i++)
            {
                p_data->p_adc_voltage_data[i] = __LL_ADC_CALC_DATA_TO_VOLTAGE(
                    VREFANALOG, p_data->p_adc_data[i], LL_ADC_RESOLUTION_12B);
            }
        }
        // Disable further reading until enabled again
        b_enable_read_data = 0;
        p_data->e_status = BSP_ADC_OK;
        return p_data->e_status;
    }
    // If reading is not enabled, set status to indicate waiting for conversion
    p_data->e_status = BSP_ADC_WAIT_CONVERT;
    return p_data->e_status;
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
  if (u32_timer_wait_converstion >= 0)
  {
    u32_timer_wait_converstion--;
  }
}

/**
 * @brief DMA completion callback function for ADC data transfer.
 *
 * This function checks if the DMA transfer complete flag is set for ADC DMA
 * channel 1. If the flag is set, it clears the flag and sets a flag
 * (`b_enable_read_data`) to indicate that ADC data is ready to be processed.
 *
 * @param p_data Pointer to the ADC configuration data structure.
 */
void
BSP_ADC_DMA_Function (adc_data_t *p_data)
{
  if (LL_DMA_IsActiveFlag_TC1(DMA1) != RESET)
  {
    // Clear DMA transfer complete flag
    LL_DMA_ClearFlag_TC1(DMA1);

    // Set flag to indicate data ready for processing
    b_enable_read_data = 1;
  }
}
