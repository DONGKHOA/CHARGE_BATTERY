/*
 * control_gate_driver.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef CONTROL_CONTROL_GATE_DRIVER_H_
#define CONTROL_CONTROL_GATE_DRIVER_H_

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/

  void CONTROL_Init(void);
  void CONTROL_CreateTask(void);

#ifdef __cplusplus
}
#endif

#endif /* CONTROL_CONTROL_GATE_DRIVER_H_ */
