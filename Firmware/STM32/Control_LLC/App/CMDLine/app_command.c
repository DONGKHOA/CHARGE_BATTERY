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
#include "app_control_power.h"

#include "scheduler.h"
#include "device.h"
#include <stdio.h>
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
            10,                    // taskPeriodInMS;
            APP_COMMAND_TaskUpdate // taskFunction;
        } };

tCmdLineEntry g_psCmdTable[] = {
  { "help", APP_COMMAND_Help, " : Display list of commands, format: help" },

  { "read_current",
    APP_COMMAND_ReadCurrentOutput,
    " : Read Current, format: read_current" },

  { "set_current",
    APP_COMMAND_SetCurrentOutput,
    " : Set Current, format: set_current current(A)" },

  { "set_pi_current",
    APP_COMMAND_SetParaControlCurrent,
    " : set_pi_current, format: set_pi_current kp ki" },

  { "read_voltage",
    APP_COMMAND_ReadVoltageOutput,
    " : Read Voltage, format: read_voltage" },

  { "set_pi_voltage",
    APP_COMMAND_SetParaControlVoltage,
    " : set_pi_voltage, format: set_pi_voltage kp ki" },

  { "monitor_power",
    APP_COMMAND_MonitorPower,
    " : Monitor Power, format: monitor_power" },

  { "monitor_para_pi",
    APP_COMMAND_MonitorParaPI,
    " : Monitor Parameter PI Control, format: monitor_para_pi" }
};

/*********************
 *    PUBLIC DATA
 *********************/

static uart_cfg_t *uart_cfg_cml;

/**********************
 *   PUBLIC FUNCTIONS
 **********************/

/**
 * The function `APP_COMMAND_Init` initializes UART configuration and sends a
 * string message for LLC control firmware.
 */
void
APP_COMMAND_Init (void)
{
  uart_cfg_cml = (uart_cfg_t *)&s_control_llc_data.s_uart_cmd;
  BSP_UART_Config(uart_cfg_cml, USART1, USART1_IRQn);
  BSP_UART_SendString(uart_cfg_cml, "> LLC CONTROL FIRMWARE\r\n");

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

  BSP_UART_SendString(uart_cfg_cml, "\nAvailable commands\r\n");
  BSP_UART_SendString(uart_cfg_cml, "------------------\r\n");

  // Point at the beginning of the command table.
  pEntry = &g_psCmdTable[0];

  while (pEntry->pcCmd)
  {
    // Print the command name and the brief description.
    BSP_UART_SendString(uart_cfg_cml, pEntry->pcCmd);
    BSP_UART_SendString(uart_cfg_cml, pEntry->pcHelp);
    BSP_UART_SendString(uart_cfg_cml, "\r\n");

    // Advance to the next entry in the table.
    pEntry++;
  }

  return (CMDLINE_OK);
}

// Format: read_current
int
APP_COMMAND_ReadCurrentOutput (int argc, char *argv[])
{
  if (argc < 1)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 1)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  char c_msg[30];
  sprintf(c_msg, "Current: %.2f\n\r", s_control_llc_data.f_output_current);

  BSP_UART_SendString(uart_cfg_cml, c_msg);

  return (CMDLINE_OK);
}

// Format: set_current current(A)
int
APP_COMMAND_SetCurrentOutput (int argc, char *argv[])
{
  if (argc < 2)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 2)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }
  float f_value_temp = atof(argv[1]);
  if (f_value_temp > CURRENT_START_THRESHOLD)
  {
    return CMDLINE_INVALID_ARG;
  }
  s_control_llc_data.f_output_current = f_value_temp;

  return (CMDLINE_OK);
}

// Format: set_pi_current kp ki
int
APP_COMMAND_SetParaControlCurrent (int argc, char *argv[])
{
  if (argc < 3)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 3)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  s_control_llc_data.s_control_current.f_Ki = atof(argv[1]);
  s_control_llc_data.s_control_current.f_Kp = atof(argv[2]);

  return (CMDLINE_OK);
}

// Format: read_voltage
int
APP_COMMAND_ReadVoltageOutput (int argc, char *argv[])
{
  if (argc < 1)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 1)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  char c_msg[30];
  sprintf(c_msg, "Voltage: %.2f\n\r", s_control_llc_data.f_output_voltage);

  BSP_UART_SendString(uart_cfg_cml, c_msg);

  return (CMDLINE_OK);
}

// Format: set_pi_voltage kp ki
int
APP_COMMAND_SetParaControlVoltage (int argc, char *argv[])
{
  if (argc < 3)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 3)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  s_control_llc_data.s_control_voltage.f_Ki = atof(argv[1]);
  s_control_llc_data.s_control_voltage.f_Kp = atof(argv[2]);

  return (CMDLINE_OK);
}

// Format: monitor_power
int
APP_COMMAND_MonitorPower (int argc, char *argv[])
{
  if (argc < 1)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 1)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  if ((s_control_llc_data.s_state_data == CC_MODE_CHARGING)
      || (s_control_llc_data.s_state_data == CV_MODE_CHARGING)
      || (s_control_llc_data.s_state_data == WAIT_DISCHARGING))
  {
    char c_msg[30];
    sprintf(c_msg,
            "Power Charging: %.2f\n\r",
            s_control_llc_data.f_output_voltage
                * s_control_llc_data.f_output_current);

    BSP_UART_SendString(uart_cfg_cml, c_msg);
  }
  else
  {
    BSP_UART_SendString(uart_cfg_cml, "NO CHARGING\n\r");
  }

  return (CMDLINE_OK);
}

// Format: monitor_para_pi
int
APP_COMMAND_MonitorParaPI (int argc, char *argv[])
{
  if (argc < 1)
  {
    return CMDLINE_TOO_FEW_ARGS;
  }
  if (argc > 1)
  {
    return CMDLINE_TOO_MANY_ARGS;
  }

  char c_msg[30];

  BSP_UART_SendString(uart_cfg_cml, "PARAMETER PI CONTROL OF CURRENT\n\r");

  sprintf(c_msg,
          "KP: %.2f, KI: %.2f\n\r",
          s_control_llc_data.s_control_current.f_Kp,
          s_control_llc_data.s_control_current.f_Ki);

  BSP_UART_SendString(uart_cfg_cml, c_msg);

  BSP_UART_SendString(uart_cfg_cml, "PARAMETER PI CONTROL OF VOLTAGE\n\r");

  sprintf(c_msg,
          "KP: %.2f, KI: %.2f\n\r",
          s_control_llc_data.s_control_voltage.f_Kp,
          s_control_llc_data.s_control_voltage.f_Ki);

  BSP_UART_SendString(uart_cfg_cml, c_msg);

  return (CMDLINE_OK);
}

/********************
 *  PRIVATE FUNCTION
 ********************/

/**
 * The function `APP_COMMAND_TaskUpdate` reads characters from a UART buffer,
 * processes commands based on the received data, and sends responses back
 * through UART.
 */
static void
APP_COMMAND_TaskUpdate (void)
{
  char   rxData;
  int8_t retVal;

  while (BSP_UART_IsAvailableDataReceive(uart_cfg_cml))
  {
    rxData = BSP_UART_ReadChar(uart_cfg_cml);
    BSP_UART_SendChar(uart_cfg_cml, rxData);
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

        // Send status command in terminal.
        BSP_UART_SendString(uart_cfg_cml, "\r\n> ");
        BSP_UART_SendString(uart_cfg_cml, ErrorCode[retVal]);
        BSP_UART_SendString(uart_cfg_cml, "> ");
      }
      else
      {
        BSP_UART_SendString(uart_cfg_cml, "\r\n> ");
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
