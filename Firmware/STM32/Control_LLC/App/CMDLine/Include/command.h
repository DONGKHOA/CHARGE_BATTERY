/*
 * command.h
 *
 *  Created on: Jul 8, 2024
 *      Author: dongkhoa
 */

#ifndef CMDLINE_COMMAND_H_
#define CMDLINE_COMMAND_H_

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

  void COMMAND_Init(void);
  void COMMAND_CreateTask(void);

  /**
   * @brief List of command
   */
  int COMMAND_help(int argc, char *argv[]);
  int COMMAND_ReadVoltageLLC(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif

#endif /* CMDLINE_COMMAND_H_ */
