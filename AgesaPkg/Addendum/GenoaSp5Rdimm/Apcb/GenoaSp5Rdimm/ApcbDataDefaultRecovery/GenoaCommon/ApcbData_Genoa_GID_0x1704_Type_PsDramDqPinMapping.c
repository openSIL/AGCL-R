/*******************************************************************************
*
 * Copyright (C) 2021-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************/

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_MEMORY,                          // GroupId
  APCB_MEM_TYPE_MEM_DRAM_DQ_PIN_MAP,          // TypeId
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

DRAM_DQ_PIN_MAP MemDqToPinMapping [] = {
  // Channel 0
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 1
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 2
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 3
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 4
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 5
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 6
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 7
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 8
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 9
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 10
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  },

  // Channel 11
  {
    // Sub-channel 0
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
    // Sub-channel 1
    { MEM_MX_DATA_00, MEM_MX_DATA_01, MEM_MX_DATA_02, MEM_MX_DATA_03, MEM_MX_DATA_04, MEM_MX_DATA_05, MEM_MX_DATA_06, MEM_MX_DATA_07 },
    { MEM_MX_DATA_08, MEM_MX_DATA_09, MEM_MX_DATA_10, MEM_MX_DATA_11, MEM_MX_DATA_12, MEM_MX_DATA_13, MEM_MX_DATA_14, MEM_MX_DATA_15 },
    { MEM_MX_DATA_16, MEM_MX_DATA_17, MEM_MX_DATA_18, MEM_MX_DATA_19, MEM_MX_DATA_20, MEM_MX_DATA_21, MEM_MX_DATA_22, MEM_MX_DATA_23 },
    { MEM_MX_DATA_24, MEM_MX_DATA_25, MEM_MX_DATA_26, MEM_MX_DATA_27, MEM_MX_DATA_28, MEM_MX_DATA_29, MEM_MX_DATA_30, MEM_MX_DATA_31 },
  }
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();

