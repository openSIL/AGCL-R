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
 * @details Customer controllable platform configuration parameter declaration in AGESA PSP Customization Block,
 * specific for Onyx evaluation board.
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
#define BLDCFG_APCB_DATA_BOARD_MASK     APCB_BOARD_INSTANCE_0


// =================================================================================================
// APCB Token Value Customization
// =================================================================================================
/*
  To customize board specific setting, do undefine and redo define of the definition

  #undef APCB_TOKEN_UID_<CONTROL_NAME>_VALUE
  #define APCB_TOKEN_UID_<CONTROL_NAME>_VALUE  NewValue
*/
#if defined(SLT_BIOS_SUPPORT)&&(SLT_BIOS_SUPPORT==1)
#undef APCB_TOKEN_UID_THIRD_PCIE_LINK_START_LANE_VALUE
#define APCB_TOKEN_UID_THIRD_PCIE_LINK_START_LANE_VALUE   132

#undef APCB_TOKEN_UID_THIRD_PCIE_LINK_END_LANE_VALUE
#define APCB_TOKEN_UID_THIRD_PCIE_LINK_END_LANE_VALUE     133
#endif
// =================================================================================================
// APCB Type Data Structure Member Customization
// =================================================================================================
/*
  To customize board specific setting, do undefine and redo define of the definition

  #undef BLDCFG_APCB_<DATA_CONTROL_NAME>
  #define BLDCFG_APCB_<DATA_CONTROL_NAME>  NewValue
*/

#endif   //ifndef  _APCB_CUSTOMIZED_BOARD_DEFINITIONS_H_


