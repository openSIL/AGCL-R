/*****************************************************************************
 *
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/

/**
 * @file ApcbData_Genoa_GID_0x1704_Type_PsMaxFreqRDIMMDdr5.c
 *
 * @brief Max Frequency for DDR5 RDIMM declaration in AGESA PSP Customization Block.
 *
 */

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

//UDIMM MAX FREQ DDR5
APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_MEMORY,                          // GroupId
  APCB_MEM_TYPE_PS_RDIMM_DDR5_MAX_FREQ,       // TypeId
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

PSCFG_MAXFREQ_ENTRY MaxFeqRDIMMDdr5 [] = {
  // Max Freq.
  // Format :
  // DimmPerCh,   Dimms,   SR,   DR,   QR,       Speed1_1V,           Speed_TBD1,                Speed_TBD2
  //
  { _1DIMM,         1,      1,    0,    0,   DDR5200_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },
  { _1DIMM,         1,      0,    1,    0,   DDR5200_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },

  { _2DIMM,         1,      1,    0,    0,   DDR5200_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },
  { _2DIMM,         1,      0,    1,    0,   DDR4800_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },

  { _2DIMM,         2,      2,    0,    0,   DDR4400_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },
  { _2DIMM,         2,      1,    1,    0,   DDR4000_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },
  { _2DIMM,         2,      0,    2,    0,   DDR4000_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY, UNSUPPORTED_DDR_FREQUENCY },
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();





