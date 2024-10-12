/*
 * app_data_struct.h
 *
 *  Created on: Jul 27, 2024
 *      Author: dongkhoa
 */

#ifndef DATA_DATA_STRUCT_H_
#define DATA_DATA_STRUCT_H_

/*********************
 *      INCLUDES
 *********************/

#include "bsp_board.h"
#include "stm32f1xx.h"
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
    WAIT_INPUT_VOLTAGE = 0,
    SOFT_START,
    CHARGING,
	WAIT_DISCHARGING,
    DISCHARGING
  } CONTROL_STATE_t;

  typedef struct _CONTROL_LLC_DataTypedef
  {
    CONTROL_STATE_t s_state_data;
    pi_control_t    s_control_voltage;
    pi_control_t    s_control_current;
    pwm_cfg_t       s_control_gate;
    uart_cfg_t      s_uart_cmd;
    float           f_output_voltage;
    float           f_output_current;
  } CONTROL_LLC_DataTypedef;

  extern volatile CONTROL_LLC_DataTypedef s_control_llc_data;

#ifdef __cplusplus
}
#endif

#endif /* DATA_DATA_STRUCT_H_ */
