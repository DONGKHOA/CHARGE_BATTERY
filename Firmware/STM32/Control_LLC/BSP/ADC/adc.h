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

  /**
   * @brief Enumeration for ADC operation status.
   *
   * This enum defines the possible statuses for ADC operations, including
   * success, starting conversion, waiting for conversion, and timeout.
   */
  typedef enum _adc_status_t
  {
    BSP_ADC_OK = 0,        /**< @brief ADC operation successful. */
    BSP_ADC_START_CONVERT, /**< @brief ADC is starting conversion. */
    BSP_ADC_WAIT_CONVERT,  /**< @brief ADC is waiting for conversion. */
    BSP_ADC_TIMEOUT,       /**< @brief ADC operation timed out. */
  } adc_status_t;

  /**
   * @brief Structure to hold ADC configuration data.
   */
  typedef struct _adc_data_t
  {
    ADC_TypeDef *p_ADCx;   /**< @brief Pointer to the ADC peripheral. */
    adc_status_t e_status; /**< @brief Status of the ADC operation. */
    uint32_t *p_adc_data; /**< @brief Pointer to the ADC data buffer. */
    float    *p_adc_voltage_data; /**< @brief Pointer to the ADC voltage data
                                     buffer. */
    uint32_t
        u32_num_channel; /**< @brief Number of channels in the ADC sequence. */
  } adc_data_t;

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  adc_status_t BSP_ADC_Config(adc_data_t *p_data);
  adc_status_t BSP_ADC_StartConvert(adc_data_t *p_data);
  adc_status_t BSP_ADC_WaitConversion(adc_data_t *p_data);
  adc_status_t BSP_ADC_Read(adc_data_t *p_data);

  // Call Function "ADC_TimeOut" in ISR SysTick
  void BSP_ADC_TimeOut(void);

  // Call Function "ADC_DMA_Function" in ISR DMA_ADC
  void BSP_ADC_DMA_Function(adc_data_t *p_data);

#ifdef __cplusplus
}
#endif

#endif /* ADC_ADC_H_ */
