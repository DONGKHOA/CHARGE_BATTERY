/*
 * data_struct.h
 *
 *  Created on: Jul 27, 2024
 *      Author: dongkhoa
 */

#ifndef DATA_DATA_STRUCT_H_
#define DATA_DATA_STRUCT_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"
#include "board.h"
#include "device.h"
#include "pi_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *   PUBLIC TYPEDEFS
   **********************/

  typedef enum
  {
    CGT_WAIT_INPUT_VOLTAGE = 0,
    CGT_SOFT_START,
    CGT_PROCESS
  } CONTROL_STATE_t;

  typedef struct _CONTROL_LLC_DataTypedef
  {
    CONTROL_STATE_t state_data;
    pi_control_t    control_system;
    pwm_cfg_t       control_gate;
  } CONTROL_LLC_DataTypedef;

  extern CONTROL_LLC_DataTypedef control_llc_data;

#ifdef __cplusplus
}
#endif

#endif /* DATA_DATA_STRUCT_H_ */