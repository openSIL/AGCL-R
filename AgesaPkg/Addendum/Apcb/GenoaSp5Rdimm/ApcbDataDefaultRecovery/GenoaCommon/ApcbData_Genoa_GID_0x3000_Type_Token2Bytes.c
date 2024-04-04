/*****************************************************************************
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/

/* $NoKeywords:$ */
/**
 * @file
 *
 * @e \$Revision:$   @e \$Date:$
 */

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>
#include <ApcbV3TokenUid.h>


APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_TOKEN,           // GroupId
  APCB_TYPE_TOKEN_2BYTES,     // TypeId
  sizeof(ApcbTypeHeader),        // SizeOfType, will be fixed up by tool
  0,                             // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_TOKEN,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_ASCENDING,
    APCB_TYPE_ATTR_UNITSIZE_TOKEN_V3,
    APCB_PRIORITY_TYPE_MASK_DEFAULT,
    APCB_TYPE_ATTR_KEYSIZE_TOKEN_V3,
    APCB_TYPE_ATTR_KEYPOS_TOKEN_V3,
    BLDCFG_APCB_DATA_BOARD_MASK
  }
};  // SizeOfType will be fixed up by tool


APCB_TOKEN_PAIR_UINT16 TokeList[] = {
// Two macros can be used for token definitions
//  APCB_TOKEN_U16 (APCB_TOKEN_UID_NAME, APCB_TOKEN_UID_NAME_VALUE),
//  APCB_TOKEN_VAL_U16(APCB_TOKEN_UID_NAME),  // Expand to use APCB_TOKEN_UID_NAME_VALUE

  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_PSP_SYSHUB_WDT_INTERVAL),
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_ECCSYMBOLSIZE),                                                //< CfgEccSymbolSize -  ECC Symbol Size.
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DIMMSENSORCONF),                                               //< DIMM temperature sensor register index BSU16 (1), Configuration
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DIMMSENSORUPPER),                                              //< DIMM temperature sensor register index BSU16 (2), Alarm temperature upper boundary
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DIMMSENSORLOWER),                                              //< DIMM temperature sensor register index BSU16 (3), Alarm temperature lower boundary
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DIMMSENSORCRITICAL),                                           //< DIMM temperature sensor register index BSU16 (4), Critical temperature
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_FCH_GPP_CLK_MAP),                                              //< FCH GPP CLK MAP
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_ODTSCMDTHROTCYC),                                              //< UMC::CH::ThrottleCtrl[OdtsCmdThrotCyc]
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_ROLLWINDOWDEPTH),                                              //< UMC::CH::ThrottleCtrl [7:0] RollWindowDepth
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_FCH_IC_SDA_TX_HOLD),                                           //< I2C IC_SDA_TX_HOLD time
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L0),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L0
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L1),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L1
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L2),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L2
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L3),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L3
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L0),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L0
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L1),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L1
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L2),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L2
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L3),                                    //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L3
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_CPU_WDT_TIMEOUT),                                              //< CPU WDT Timeout
  APCB_TOKEN_VAL_U16 (APCB_TOKEN_UID_MEM_PMU_BIST_ALGORITHM_BITMASK_DDR),                           //< DDR Healing BIST Algorithm Selection

//  APCB_TOKEN_U16 (0x00000000, 0xFFFF), // Null token, remove this when there's other token defined
};


APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();




