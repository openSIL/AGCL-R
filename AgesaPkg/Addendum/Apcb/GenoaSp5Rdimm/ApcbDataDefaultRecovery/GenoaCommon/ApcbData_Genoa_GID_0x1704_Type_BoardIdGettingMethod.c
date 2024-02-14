/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/*****************************************************************************
 *
 * Warning: BoardIdGettingMethod applies to multiple APCB only, please remove it
 * from ApcbCreate.bat if only 1 APCB instance is needed
 *
 *****************************************************************************
 */

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_PSP,                               // GroupId
  APCB_PSP_TYPE_BOARD_ID_GETTING_METHOD,          // TypeId
  sizeof(ApcbTypeHeader),       // SizeOfType, will be fixed up by tool
  0,                            // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_STRUCT,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_NATIVE_RAW,
    0,
    APCB_PRIORITY_TYPE_MASK_DEFAULT | APCB_PRIORITY_TYPE_MASK_HARD_FORCE, // Priority mask
    0,
    0,
    BLDCFG_APCB_DATA_BOARD_MASK             // Board specific APCB instance mask
  }
};  // SizeOfType will be fixed up by tool

// From I2C EEPROM (IO MUX address 0x70 channel 2)
PSP_GET_BOARD_ID_FROM_I2C_EEPROM_STRUCT_V2 _4BYTE_ALIGN ApcbGettingMethod_0 =
{
  BOARD_ID_METHOD_I2C_EEPROM,   // I2C EEPROM
  5,                            // I2C Bus#
  //
  // I2C Mux info.
  //
  0xE0,                         // 8-Bit I2C Mux address
  _UNUSED_,                     // 8-Bit I2C control reg. address
  0x04,                         // Value filled to switch the channel (2)
  //
  // I2C EEPROM info.
  //
  0xA0,                         // 8-Bit Device address
  0x10,                         // Board ID byte offset
  0x12,                         // Board Revision byte offset
  {
    //{IdRevAndFeatureMask, IdAndFeatureValue, RevAndFeatureValue, ApcbInstanceIndexForBoard}
    {0xFF,     0x41,     _UNUSED_,      0},  // Onyx
    {0,           0,            0,      0},  // Terminator (Only needed when it is not the last getting method)
  }
};

// From I2C EEPROM (IO MUX address 0x71 channel 2)
PSP_GET_BOARD_ID_FROM_I2C_EEPROM_STRUCT_V2 _4BYTE_ALIGN ApcbGettingMethod_1 =
{
  BOARD_ID_METHOD_I2C_EEPROM,   // I2C EEPROM
  5,                            // I2C Bus#
  //
  // I2C Mux info.
  //
  0xE2,                         // 8-Bit I2C Mux address
  _UNUSED_,                     // 8-Bit I2C control reg. address
  0x04,                         // Value filled to switch the channel (2)
  //
  // I2C EEPROM info.
  //
  0xA0,                         // 8-Bit Device address
  0x10,                         // Board ID byte offset
  0x12,                         // Board Revision byte offset
  {
    //{IdRevAndFeatureMask, IdAndFeatureValue, RevAndFeatureValue, ApcbInstanceIndexForBoard}
    {0xFF,     0x41,     _UNUSED_,      0},  // Onyx
    {0,           0,            0,      0},  // Terminator (Only needed when it is not the last getting method)
  }
};

// From I2C EEPROM (IO MUX address 0x71 channel 0)
PSP_GET_BOARD_ID_FROM_I2C_EEPROM_STRUCT_V2 _4BYTE_ALIGN ApcbGettingMethod_2 =
{
  BOARD_ID_METHOD_I2C_EEPROM,   // I2C EEPROM
  5,                            // I2C Bus#
  //
  // I2C Mux info.
  //
  0xE2,                         // 8-Bit I2C Mux address
  _UNUSED_,                     // 8-Bit I2C control reg. address
  0x01,                         // Value filled to switch the channel (0)
  //
  // I2C EEPROM info.
  //
  0xA0,                         // 8-Bit Device address
  0x10,                         // Board ID byte offset
  0x12,                         // Board Revision byte offset
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();
