/*****************************************************************************
*
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
**/
/**
 *
 * @file ApcbCustomizedBoardDefinitions.h
 *
 * @brief Platform configuration parameter declaration in AGESA PSP Customization Block.
 * @details Customer controllable platform configuration parameter declaration in AGESA PSP Customization Block.
 *
 **/

//
// OEM CUSTOMIZABLE BOARD SPECIFIC DEFINITIONS. Any changes must be done here...
//

#ifndef _APCB_CUSTOMIZED_BOARD_DEFINITIONS_H_
#define _APCB_CUSTOMIZED_BOARD_DEFINITIONS_H_

// =================================================================================================
// IMPORTANT: Define board mask
//            If this file is copied to a board folder, then it applies to data files build for that board folder
// =================================================================================================
/**
 * @brief Board specific APCB instance mask
 * @details Possible value of board mask could be:
 * 1. Apply to single board:
 *    - APCB_BOARD_INSTANCE_0, APCB_BOARD_INSTANCE_1, ... or APCB_BOARD_INSTANCE_15
 * 2. Apply to multiple boards:
 *    - APCB_BOARD_INSTANCE_0 + APCB_BOARD_INSTANCE_1 + APCB_BOARD_INSTANCE_10
 * 3. Apply to all boards:      APCB_BOARD_INSTANCE_ALL_KNOWN
 */
#define BLDCFG_APCB_DATA_BOARD_MASK     APCB_BOARD_INSTANCE_ALL_KNOWN

#if defined(APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE) && APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE == 0

#undef ESPI_UART_IO_ADDR_1
#define ESPI_UART_IO_ADDR_1 0x2F8

#undef ESPI_UART_IO_ADDR_2
#define ESPI_UART_IO_ADDR_2 0x3F8

#undef ESPI_UART_IO_SIZE
#define ESPI_UART_IO_SIZE 0x7

#else

#undef ESPI_UART_IO_ADDR_1
#define ESPI_UART_IO_ADDR_1 0x0

#undef ESPI_UART_IO_ADDR_2
#define ESPI_UART_IO_ADDR_2 0x0

#undef ESPI_UART_IO_SIZE
#define ESPI_UART_IO_SIZE 0
#endif // #if defined(APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE) && APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE == 0

// =================================================================================================
// APCB Token Value Customization
// =================================================================================================
/*
  To customize board specific setting, do undefine and redo define of the definition

  #undef APCB_TOKEN_UID_<CONTROL_NAME>_VALUE
  #define APCB_TOKEN_UID_<CONTROL_NAME>_VALUE  NewValue
*/


// =================================================================================================
// APCB Type Data Structure Member Customization
// =================================================================================================
/*
  To customize board specific setting, do undefine and redo define of the definition

  #undef BLDCFG_APCB_<DATA_CONTROL_NAME>
  #define BLDCFG_APCB_<DATA_CONTROL_NAME>  NewValue
*/

#endif   //ifndef  _APCB_CUSTOMIZED_BOARD_DEFINITIONS_H_


