/*
 * frequency_convert_pulse.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef FREQUENCY_CONVERT_PULSE_FREQUENCY_CONVERT_PULSE_H_
#define FREQUENCY_CONVERT_PULSE_FREQUENCY_CONVERT_PULSE_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *    PUBLIC TYPEDEFS
   **********************/

  /**
   * @brief Structure to hold frequency conversion data for a timer.
   */
  typedef struct _FCP_data_t
  {
    uint32_t frequency;       /**< @brief Desired frequency to be achieved. */
    uint16_t prescaler_timer; /**< @brief Prescaler value for the timer. */
    uint16_t auto_reload_reg_timer; /**< @brief Auto-reload register value for
                                       the timer. */
  } __attribute__((packed)) FCP_data_t;

  /**********************
   *    PUBLIC FUNCTIONS
   **********************/

  void FCP_PhaseStart(uint8_t time);
  void FCP_PhaseProcess(uint32_t frequency);

#ifdef __cplusplus
}
#endif

#endif /* FREQUENCY_CONVERT_PULSE_FREQUENCY_CONVERT_PULSE_H_ */
