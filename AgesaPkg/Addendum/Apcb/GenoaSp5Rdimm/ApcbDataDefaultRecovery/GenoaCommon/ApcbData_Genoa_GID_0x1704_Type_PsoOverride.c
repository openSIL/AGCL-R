/*****************************************************************************
 *
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/
/**
 * @file ApcbData_Genoa_GID_0x1704_Type_PsoOverride.c
 *
 * @brief Platform configuration declaration in AGESA PSP Customization Block.
 * @details Platform board and memory configuration declaration in AGESA PSP Customization Block.
 *
 */

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_MEMORY,                          // GroupId
  APCB_MEM_TYPE_PSO_DATA,                     // TypeId
  sizeof(ApcbTypeHeader),        // SizeOfType, will be fixed up by tool
  0,                             // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_STRUCT,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_NATIVE_RAW,
    0,
    APCB_PRIORITY_TYPE_MASK_DEFAULT,    // Priority mask
    0,
    0,
    BLDCFG_APCB_DATA_BOARD_MASK         // Board specific APCB instance mask
  }
};  // SizeOfType will be fixed up by tool

///< Platform Specific Overrides
PSO_ENTRY PlatformMemoryConfiguration[] = {
  //-----------------------------------------
  // Platform Memory Configuration Data Block
  //-----------------------------------------
    BLDCFG_NUM_DIMMS_SUPPORTED_12_CHANNEL
    BLDCFG_NUM_CHNL_SUPPORTED
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();





