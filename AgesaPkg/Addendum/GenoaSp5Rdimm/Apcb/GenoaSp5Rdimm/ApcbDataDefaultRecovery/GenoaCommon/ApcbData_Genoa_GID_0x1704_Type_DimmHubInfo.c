/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/


#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_MEMORY,                    // GroupId
  APCB_MEM_TYPE_DIMM_INFO_SMBUS,        // TypeId
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

//
// Following channel column is the platform DDR channel index

DIMM_HUB_INFO DimmHubInfo [24] =
{
  // Socket 0
  // socket  channel  dimm  DimmAddr  FchI2cI3cCtrlIndex
       {0,      0,      0,    0xA0,           0},
       {0,      1,      0,    0xA2,           0},
       {0,      2,      0,    0xA4,           0},
       {0,      3,      0,    0xA6,           0},
       {0,      4,      0,    0xA8,           0},
       {0,      5,      0,    0xAA,           0},
       {0,      6,      0,    0xA0,           1},
       {0,      7,      0,    0xA2,           1},
       {0,      8,      0,    0xA4,           1},
       {0,      9,      0,    0xA6,           1},
       {0,     10,      0,    0xA8,           1},
       {0,     11,      0,    0xAA,           1},

       {1,      0,      0,    0xA0,           0},
       {1,      1,      0,    0xA2,           0},
       {1,      2,      0,    0xA4,           0},
       {1,      3,      0,    0xA6,           0},
       {1,      4,      0,    0xA8,           0},
       {1,      5,      0,    0xAA,           0},
       {1,      6,      0,    0xA0,           1},
       {1,      7,      0,    0xA2,           1},
       {1,      8,      0,    0xA4,           1},
       {1,      9,      0,    0xA6,           1},
       {1,     10,      0,    0xA8,           1},
       {1,     11,      0,    0xAA,           1},
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();

