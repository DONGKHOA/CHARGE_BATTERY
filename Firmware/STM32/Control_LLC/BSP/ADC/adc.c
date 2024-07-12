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

#define TIMEOUT_WAIT_CONVERTION	1000

/**********************
 *   PRIVATE DATA
 **********************/

static volatile uint_fast32_t timer_wait_converstion = 0;
static volatile bool enable_read_data;

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
adc_status_t ADC_Config(adc_data_t *p_data, uint32_t _num_channel,
                uint32_t *_channel_table, uint32_t *_adc_data)
{
    p_data->num_channel     = _num_channel;
    p_data->channel_table   = _channel_table;
    p_data->adc_data        = _adc_data;
    p_data->status			= ADC_OK;

    if (p_data->num_channel > 1)
    {
        LL_ADC_REG_SetDMATransfer(p_data->ADCx,
                                  LL_ADC_REG_DMA_TRANSFER_UNLIMITED);
		LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1,
			  LL_ADC_DMA_GetRegAddr(p_data->ADCx, LL_ADC_DMA_REG_REGULAR_DATA),
			  (uint32_t)&p_data->adc_data, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
		LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, p_data->num_channel);
		LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);
		LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);
    }

    LL_ADC_StartCalibration(p_data->ADCx);
	while( LL_ADC_IsCalibrationOnGoing(p_data->ADCx))
	{
		if(timer_wait_converstion == 0)
		{
			p_data->status = ADC_TIMEOUT;
			return ADC_TIMEOUT;
		}
	}

    LL_ADC_Enable(p_data->ADCx);
    return ADC_OK;
}

adc_status_t ADC_Read(adc_data_t * p_data)
{
	timer_wait_converstion = TIMEOUT_WAIT_CONVERTION;
	LL_ADC_REG_StartConversionSWStart(p_data->ADCx);


//	while(LL_ADC_IsActiveFlag_EOS(p_data->ADCx) != SET)
//	{
//		// Clear the End of Conversion flag
//		LL_ADC_ClearFlag_EOS(ADC1);
//	}

}

adc_status_t ADC_TimeOut(void)
{
	if(timer_wait_converstion >= 0) timer_wait_converstion--;
}

void ADC_DMA_Function(void)
{
	enable_read_data = 1;
}
