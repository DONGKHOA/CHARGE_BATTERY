/*
 * adc.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

/*********************
 *      INCLUDES
 *********************/

#include <stdbool.h>
#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**********************
 *    PUBLIC TYPEDEFS
 **********************/

typedef enum
{
    ADC_OK = 0,        /**< @brief ADC operation successful. */
    ADC_TIMEOUT,       /**< @brief ADC operation timed out. */
} adc_status_t;

/**
 * @brief Structure to hold ADC configuration data.
 */
typedef struct _adc_data_t
{
    ADC_TypeDef *       ADCx;           /**< @brief Pointer to the ADC peripheral. */
    adc_status_t        status;         /**< @brief Status of the ADC operation. */
    volatile uint32_t   num_channel;    /**< @brief Number of channels in the ADC sequence. */
    volatile uint32_t * channel_table;  /**< @brief Pointer to the channel table array. */
    volatile uint32_t * adc_data;       /**< @brief Pointer to the ADC data buffer. */
} adc_data_t;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

adc_status_t ADC_Config(adc_data_t *p_data, uint32_t _num_channel,
                uint32_t *_channel_table, uint32_t *_adc_data);
adc_status_t ADC_Read(adc_data_t *p_data);
adc_status_t ADC_TimeOut(void);

void ADC_DMA_Function(void);

#ifdef __cplusplus
}
#endif

#endif /* ADC_ADC_H_ */
