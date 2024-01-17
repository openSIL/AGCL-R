/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define Memory Console Out and Breakpoint header values
 */
#ifndef _APCB_MEM_CONSOLE_OUT_H_
#define _APCB_MEM_CONSOLE_OUT_H_

/**
 * @brief ABL Console Out Header.
*/
typedef struct _ABL_CONSOLE_OUT_HEADER {
  BOOLEAN AblConsoleFilterEnable;                ///< Enable ABL Console output filter
                                                 ///< TRUE - Global Enable of ABL console output filter  (Default)
                                                 ///< FALSE - Disable ABL console output filter
  BOOLEAN AblConsoleFilterMemFlowEnable;         ///< ABL Console out filter for "MEM FLOW" (Default - Enabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Filter is disabled and this console output is removed from the log
  BOOLEAN AblConsoleFilterMemSetRegEnable;       ///< ABL Console out filter to enable "MEM SETREG" (Default - Enabled)
                                                 ///< TRUE - Filter is enabled  and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log (Default)
  BOOLEAN AblConsoleFilterMemGetRegEnable;       ///< ABL Console out filter to enable "MEM GETREG"   (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log(Default)
  BOOLEAN AblConsoleFilterMemStatusEnable;       ///< ABL Console out filter to enable "MEM STATUS"   (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log(Default)
  BOOLEAN AblConsoleFilterMemPmuEnable;          ///< ABL Console out filter to enable "MEM PMU"    (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log(Default)
  BOOLEAN AblConsoleFilterMemPmuSramReadEnable;  ///< ABL Console out filter to enable "MEM PMU SRAM READ" (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log(Default)
  BOOLEAN AblConsoleFilterMemPmuSramWriteEnable; ///< ABL Console out filter to enable "MEM PMU SRAM WRITE" (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed    and this console output is removed from the log(Default)
  BOOLEAN AblConsoleFilterMemTestVerboseEnable;  ///< ABL Console out filter to enable "MEM TEST VERBOSE" (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log(Default)
  BOOLEAN AblConsoleFilterMemBasicOutputEnable;  ///< ABL Console out filter to enable "MEM_PUBLIC_OUTPUT" (Default - disabled)
                                                 ///< TRUE - Filter is enabled and this data will be displayed (Default)
                                                 ///< FALSE - Fitler is diesabed  and this console output is removed from the log(Default)
  UINT16 Reserved1;                              ///< Reserved
  UINT32 AblConsolePort;                         ///< 32 bit ABL Console output port (Default - 0x80)
} ABL_CONSOLE_OUT_HEADER;

/**
 * @brief ABL Breakpoint Control defines if ABL Breakpoints are enabled
 */
typedef struct _ABL_BREAKPOINT_CONTROL {
  BOOLEAN BreakPointEnable;      ///< Enable ABL Console output
                                 ///< TRUE - All dies will stop at the same breakpoints (Default)
                                 ///< FALSE - Master will only stop with breakpoints
  BOOLEAN BreakOnAllDies;        ///< Enable ABL Console output
                                 ///< TRUE - All dies will stop at the same breakpoints  (Default)
                                 ///< FALSE - Master will only stop with breakpoints
} ABL_BREAKPOINT_CONTROL;

/**
 * @brief Psp_console_out data structure is used to control console output support
 */
typedef struct _PSP_CONSOLE_OUT_STRUCT {
  ABL_CONSOLE_OUT_HEADER  ConsoleOutControl;    ///< Control structure for Console out
  ABL_BREAKPOINT_CONTROL  BreakPointControl;    ///< Control structure for Breakpoints
} PSP_CONSOLE_OUT_STRUCT;

#endif // _APCB_MEM_CONSOLE_OUT_H_


