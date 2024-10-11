/*
 * app_command.c
 *
 *  Created on: Jul 8, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "bsp_board.h"
#include "app_command.h"
#include "app_cmdline.h"
#include "app_data_struct.h"

#include "scheduler.h"
#include "device.h"
#include <stdlib.h>
#include <stdio.h>

/*********************
 *    PRIVATE TYPEDEFS
 *********************/

typedef struct _Command_TaskContextTypedef_
{
  SCH_TASK_HANDLE         taskHandle;
  SCH_TaskPropertyTypedef taskProperty;
} Command_TaskContextTypedef;

/*********************
 *    PRIVATE DEFINES
 *********************/

#define COMMAND_MAX_LENGTH 255

/******************************
 *  PRIVATE PROTOTYPE FUNCTION
 ******************************/

static void APP_COMMAND_TaskUpdate(void);

/*********************
 *    PRIVATE DATA
 *********************/

static const char *ErrorCode[6] = { "OK\r\n",
                                    "CMDLINE_BAD_CMD\r\n",
                                    "CMDLINE_TOO_MANY_ARGS\r\n",
                                    "CMDLINE_TOO_FEW_ARGS\r\n",
                                    "CMDLINE_INVALID_ARG\r\n",
                                    "CMD_OK_BUT_PENDING...\r\n" };

static char    s_commandBuffer[COMMAND_MAX_LENGTH];
static uint8_t s_commandBufferIndex = 0;

static Command_TaskContextTypedef s_CommandTaskContext
    = { SCH_INVALID_TASK_HANDLE, // Will be updated by Scheduler
        {
            SCH_TASK_SYNC,         // taskType;
            SCH_TASK_PRIO_0,       // taskPriority;
            10,                    // taskPeriodInMS;
            APP_COMMAND_TaskUpdate // taskFunction;
        } };

tCmdLineEntry g_psCmdTable[] = {
  { "help", APP_COMMAND_Help, " : Display list of commands, format: help" },
  { "read_voltage_llc",
    APP_COMMAND_ReadVoltageLLC,
    "Read Voltage, format: read_voltage_llc" },
  { "set_parameter_pi",
    APP_COMMAND_SetParameterPiControl,
    "Set parameter, format: set_parameter_pi kp ki" }
};

/*********************
 *    PUBLIC DATA
 *********************/

uart_cfg_t uart_cfg_cml;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
APP_COMMAND_Init (void)
{
  BSP_UART_Config(&uart_cfg_cml, USART1, USART1_IRQn);
  BSP_UART_SendString(&uart_cfg_cml, "> LLC CONTROL FIRMWARE\r\n");

  // Reset Data
  s_commandBufferIndex = 0;
}

void
APP_COMMAND_CreateTask (void)
{
  SCH_TASK_CreateTask(&s_CommandTaskContext.taskHandle,
                      &s_CommandTaskContext.taskProperty);
}

/**
 * @brief Prints a list of available commands and their descriptions.
 *
 * This function iterates through the command table and prints each command's
 * name and description to the UART. It is intended to be called when the user
 * requests help.
 *
 * @param argc The number of arguments.
 * @param argv The argument list.
 * @return CMDLINE_OK on success.
 */
int
APP_COMMAND_Help (int argc, char *argv[])
{
  tCmdLineEntry *pEntry;

  BSP_UART_SendString(&uart_cfg_cml, "\nAvailable commands\r\n");
  BSP_UART_SendString(&uart_cfg_cml, "------------------\r\n");

  // Point at the beginning of the command table.
  pEntry = &g_psCmdTable[0];

  while (pEntry->pcCmd)
  {
    // Print the command name and the brief description.
    BSP_UART_SendString(&uart_cfg_cml, pEntry->pcCmd);
    BSP_UART_SendString(&uart_cfg_cml, pEntry->pcHelp);
    BSP_UART_SendString(&uart_cfg_cml, "\r\n");

    // Advance to the next entry in the table.
    pEntry++;
  }

  return (CMDLINE_OK);
}

// Format: read_voltage_llc
int
APP_COMMAND_ReadVoltageLLC (int argc, char *argv[])
{
	if (argc < 1) return CMDLINE_TOO_FEW_ARGS;
	if (argc > 1) return CMDLINE_TOO_MANY_ARGS;

	char voltage[10];
	sprintf(voltage, "%.2f", s_control_llc_data.f_output_voltage);

	BSP_UART_SendString(&uart_cfg_cml, voltage);

  return (CMDLINE_OK);
}

// Format: set_parameter_pi kp ki
int
APP_COMMAND_SetParameterPiControl (int argc, char *argv[])
{
	if (argc < 3) return CMDLINE_TOO_FEW_ARGS;
	if (argc > 3) return CMDLINE_TOO_MANY_ARGS;

	float f_kp_temp = atof(argv[1]);
	float f_ki_temp = atof(argv[2]);

//	s_control_llc_data.s_control_system.f_Ki = f_ki_temp;
//	s_control_llc_data.s_control_system.f_Kp = f_kp_temp;

  return (CMDLINE_OK);
}

/********************
 *  PRIVATE FUNCTION
 ********************/

static void
APP_COMMAND_TaskUpdate (void)
{
  char   rxData;
  int8_t retVal;

  while (BSP_UART_IsAvailableDataReceive(&uart_cfg_cml))
  {
    rxData = BSP_UART_ReadChar(&uart_cfg_cml);
    BSP_UART_SendChar(&uart_cfg_cml, rxData);
    // Check rxData is ESC key.
    if (rxData == 27)
    {
    }

    if ((rxData == '\r') || (rxData == '\n'))
    {
      if (s_commandBufferIndex > 0)
      {
        // Processing command form terminal.
        s_commandBuffer[s_commandBufferIndex] = 0;
        s_commandBufferIndex++;
        retVal               = CmdLineProcess(s_commandBuffer);
        s_commandBufferIndex = 0;

        //Send status command in terminal.
        BSP_UART_SendString(&uart_cfg_cml, "\r\n> ");
        BSP_UART_SendString(&uart_cfg_cml, ErrorCode[retVal]);
        BSP_UART_SendString(&uart_cfg_cml, "> ");
      }
      else
      {
        BSP_UART_SendString(&uart_cfg_cml, "\r\n> ");
      }
    }
    else if ((rxData == 8)
             || (rxData == 127)) // ASCII code for key Delete, Backspace.
    {
      if (s_commandBufferIndex > 0)
      {
        s_commandBufferIndex--;
      }
    }
    else
    {
      s_commandBuffer[s_commandBufferIndex] = rxData;
      s_commandBufferIndex++;

      if (s_commandBufferIndex > COMMAND_MAX_LENGTH)
      {
        s_commandBufferIndex = 0;
      }
    }
  }
}
