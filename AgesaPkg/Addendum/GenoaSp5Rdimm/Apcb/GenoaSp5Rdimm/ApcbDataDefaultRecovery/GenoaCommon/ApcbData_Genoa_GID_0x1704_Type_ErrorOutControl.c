/*****************************************************************************
 *
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/

/**
 * @file ApcbData_Genoa_GID_0x1704_Type_ErrorOutControl.c
 *
 * @brief Error Out Control declaration in AGESA PSP Customization Block.
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
  APCB_GROUP_MEMORY,                            // GroupId
  APCB_MEM_TYPE_ERROR_OUT_EVENT_CONTROL,        // TypeId
  sizeof(ApcbTypeHeader),       // SizeOfType, will be fixed up by tool
  0,                            // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_STRUCT,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_NATIVE_RAW,
    0,
    APCB_PRIORITY_TYPE_MASK_DEFAULT,        // Priority mask
    0,
    0,
    BLDCFG_APCB_DATA_BOARD_MASK             // Board specific APCB instance mask
  }
};  // SizeOfType will be fixed up by tool


///< Platform Specific Overrides
PSP_ERROR_OUT_CONTROL_STRUCT PspEventOutControl = {
  FALSE,
  FALSE,
  FALSE,
  FALSE,
  0x84,
  15000,
  0x80,
  FALSE,
  4,
  4,
  6,
  6,
  FALSE,
  {
    85,
    0x01,
    0xC0
  },
  {
    {BEEP_ERROR_TYPE_GENERAL|BEEP_ERROR_OPERATION_MASK,     1,   1000},
    {BEEP_ERROR_TYPE_MEMORY|BEEP_ERROR_OPERATION_MASK,      2,    500},
    {BEEP_ERROR_TYPE_DF|BEEP_ERROR_OPERATION_MASK,          3,    500},
    {BEEP_ERROR_TYPE_CCX|BEEP_ERROR_OPERATION_MASK,         4,    500},
    {BEEP_ERROR_TYPE_GNB|BEEP_ERROR_OPERATION_MASK,         5,    500},
    {BEEP_ERROR_TYPE_PSP|BEEP_ERROR_OPERATION_MASK,         6,    500},
    {BEEP_ERROR_TYPE_SMU|BEEP_ERROR_OPERATION_MASK,         7,    500},
    {BEEP_ERROR_TYPE_UNKNOW|BEEP_ERROR_OPERATION_MASK,      2,    100}
  },
  FALSE
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();





