/*****************************************************************************
 *
 * Copyright (C) 2013-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/

/**
 * @file ApcbData_Genoa_GID_0x1704_Type_ConsoleOutControl.c
 *
 * @brief Console Out Control declaration in AGESA PSP Customization Block.
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
  APCB_GROUP_MEMORY,                        // GroupId
  APCB_MEM_TYPE_CONSOLE_OUT_CONTROL,        // TypeId
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
PSP_CONSOLE_OUT_STRUCT ConsoleOutControl = {
  {
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_ENABLE
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_ENABLE,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_FLOW
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_FLOW,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_SET_REG
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_SET_REG,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_GET_REG
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_GET_REG,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_STATUS
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_STATUS,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_PMU
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_PMU,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_PMU_SRAM_READ
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_PMU_SRAM_READ,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_PMU_SRAM_WRITE
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_PMU_SRAM_WRITE,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_TEST_VERBOSE
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_TEST_VERBOSE,
    #else
      FALSE,
    #endif
    #ifdef BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_BASIC_OUTPUT
      BLDCFG_CONOUTCTRL_ABL_CONSOLE_FILTER_MEM_BASIC_OUTPUT,
    #else
      FALSE,
    #endif
    0x0,
    0x80,
  },
  {
    #ifdef BLDCFG_CONOUTCTRL_BREAKPOINT
      BLDCFG_CONOUTCTRL_BREAKPOINT,
    #else
      FALSE,
    #endif

    #ifdef BLDCFG_CONOUTCTRL_BREAKPOINT_ALLDIE
      BLDCFG_CONOUTCTRL_BREAKPOINT_ALLDIE,
    #else
      FALSE,
    #endif
  }
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();





