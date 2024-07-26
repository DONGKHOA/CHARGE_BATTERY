/*
 * command.c
 *
 *  Created on: Jul 8, 2024
 *      Author: dongkhoa
 */

/*********************
 *      INCLUDES
 *********************/

#include "command.h"
#include "cmdline.h"

#include "scheduler.h"
#include "board.h"
#include "device.h"
#include <stdlib.h>

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

static void COMMAND_TaskUpdate(void);

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
            SCH_TASK_SYNC,     // taskType;
            SCH_TASK_PRIO_0,   // taskPriority;
            10,                // taskPeriodInMS;
            COMMAND_TaskUpdate // taskFunction;
        } };

tCmdLineEntry g_psCmdTable[] = {
  { "help", COMMAND_help, " : Display list of commands, format: help" },
  { "read_voltage_llc",
    COMMAND_ReadVoltageLLC,
    "Read Voltage, format: read_voltage_llc channel" },
};

/*********************
 *    PUBLIC DATA
 *********************/

uart_cfg_t uart_cfg_cml;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

void
COMMAND_Init (void)
{
  UART_Config(&uart_cfg_cml, COMMAND_LINE_UART, COMMAND_LINE_IRQ);
  UART_SendString(&uart_cfg_cml, "> LLC CONTROL FIRMWARE\r\n");

  /** Reset Data*/
  s_commandBufferIndex = 0;
}

void
COMMAND_CreateTask (void)
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
COMMAND_help (int argc, char *argv[])
{
  tCmdLineEntry *pEntry;

  UART_SendString(&uart_cfg_cml, "\nAvailable commands\r\n");
  UART_SendString(&uart_cfg_cml, "------------------\r\n");

  /**< Point at the beginning of the command table. */
  pEntry = &g_psCmdTable[0];

  while (pEntry->pcCmd)
  {
    /**< Print the command name and the brief description. */
    UART_SendString(&uart_cfg_cml, pEntry->pcCmd);
    UART_SendString(&uart_cfg_cml, pEntry->pcHelp);
    UART_SendString(&uart_cfg_cml, "\r\n");

    /**< Advance to the next entry in the table. */
    pEntry++;
  }

  return (CMDLINE_OK);
}

int
COMMAND_ReadVoltageLLC (int argc, char *argv[])
{
  if (argc < 2)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 2)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  uint8_t channel = atoi(argv[1]);
  if (channel > PWM_CHANNEL_3)
  {
    return CMDLINE_INVALID_ARG;
  }

  ADS1115_Voltage((ads1115_channel_t)channel);

  return (CMDLINE_OK);
}

/********************
 *  PRIVATE FUNCTION
 ********************/

static void
COMMAND_TaskUpdate (void)
{
  char   rxData;
  int8_t retVal;

  while (UART_IsAvailableDataReceive(&uart_cfg_cml))
  {
    rxData = UART_ReadChar(&uart_cfg_cml);
    UART_SendChar(&uart_cfg_cml, rxData);
    /**< Check rxData is ESC key */
    if (rxData == 27)
    {
    }

    if ((rxData == '\r') || (rxData == '\n'))
    {
      if (s_commandBufferIndex > 0)
      {
        /**< Processing command form terminal */
        s_commandBuffer[s_commandBufferIndex] = 0;
        s_commandBufferIndex++;
        retVal               = CmdLineProcess(s_commandBuffer);
        s_commandBufferIndex = 0;

        /**< Send status command in terminal */
        UART_SendString(&uart_cfg_cml, "\r\n> ");
        UART_SendString(&uart_cfg_cml, ErrorCode[retVal]);
        UART_SendString(&uart_cfg_cml, "> ");
      }
      else
      {
        UART_SendString(&uart_cfg_cml, "\r\n> ");
      }
    }
    else if ((rxData == 8)
             || (rxData == 127)) /**< ASCII code for key del, Backspace */
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
