/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */
#include <MyPorting.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_FCH,                           // GroupId
  APCB_FCH_TYPE_ESPI_INIT,                  // TypeId
  sizeof(ApcbTypeHeader),                   // SizeOfType, will be fixed up by tool
  0,                                        // InstanceId
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
APCB_FCH_ESPI_INIT_STRUCT EspiInitConfig = {
  TRUE,                                 //< EspiEnable - Enable eSPI controller
  1,                                    //< DataBusSelect - eSPI data bus selection
  1,                                    //< ClockPinSelect - eSPI Clock Pin selection
  0,                                    //< CsPinSelect - eSPI CS Pin selection
  ESPI_CLOCKVAL_16MHZ,                  //< ClockFreq - eSPI operating clock frequency
  ESPI_IOMODEVAL_QUAD,                  //< IoMode - eSPI IO mode     set QUAD IO for keeping the orginal value.
  ESPI_ALERT_MODE_VAL_ALERT_PIN,        //< AlertMode - eSPI alert mode
  FALSE,                                //< PltRstDeasrt - eSPI PLTRST# de-assert
  TRUE,                                 //< Io80Enable - eSPI IO80 port decoding
  FALSE,                                //< Io6064Enable - eSPI KBC port IO60/64 decoding
  // IoRangeSize[16] - eSPI IO range size          ABL will use the last two IO range for espi UART
  {    3,        7,      7,     0,       0,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0},
  // IoRangeBase[16] - eSPI IO range base
  //CRB BMC's virtual UART does not need 0x4E or 2E decode, removing it. If your project still need it , please add it back. It's depend on your project.
  {0xCA2,    0x2F8,   0x3F8,    0,      0,       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0},
  // MmioRangeSize[5] - eSPI MMIO range size
  {0, 0, 0, 0, 0},
  // MmioRangeBase[5] - eSPI MMIO range base
  {0, 0, 0, 0, 0},
  0xFFFFFFFF,                           //< IrqMask - eSPI IRQ mask bitmap
  0x00000000,                           //< IrqPolarity - eSPI IRQ polarity bitmap
  FALSE,                                //< CPUTEMP_RTCTIME_VW_EN
  0x00,                                 //< CPUTEMP_RTCTIME_VW_INDEX_SEL
  0x00000000,                           //< MMIO base for Cpu temp
  0x00000000,                           //< MMIO base for RTC Time
  TRUE,                                 //< Bus Master
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();
