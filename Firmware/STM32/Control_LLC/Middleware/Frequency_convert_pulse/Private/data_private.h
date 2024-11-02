/*
 * data_private.h
 *
 *  Created on: Jul 12, 2024
 *      Author: dongkhoa
 */

#ifndef FREQUENCY_CONVERT_PULSE_PRIVATE_DATA_PRIVATE_H_
#define FREQUENCY_CONVERT_PULSE_PRIVATE_DATA_PRIVATE_H_

#ifdef __cplusplus
extern "C"
{
#endif

  /*********************
   *      INCLUDES
   *********************/

#include "frequency_convert_pulse.h"

  /**********************
   *    PRIVATE DATA
   **********************/

#define SIZE_TABLE_DATA_PROCESS 198

  extern const FCP_data_t table_data_process[];
  extern const FCP_data_t table_data_start[];

#ifdef __cplusplus
}
#endif

#endif /* FREQUENCY_CONVERT_PULSE_PRIVATE_DATA_PRIVATE_H_ */
