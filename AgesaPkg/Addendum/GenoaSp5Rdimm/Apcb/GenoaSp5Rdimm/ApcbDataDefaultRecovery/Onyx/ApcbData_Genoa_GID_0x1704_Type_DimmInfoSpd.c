/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/

/**
 * @file ApcbData_Genoa_GID_0x1704_Type_DimmInfoSpd.c
 *
 **/

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

//
// Helper Marco
//
#define  SOCKET_0     0x00
#define  SOCKET_1     0x01
#define  DIMM_SLOT_A  0x00
#define  DIMM_SLOT_B  0x01
#define  DIMM_SLOT_C  0x02
#define  DIMM_SLOT_D  0x03
#define  DIMM_SLOT_E  0x04
#define  DIMM_SLOT_F  0x05
#define  DIMM_SLOT_G  0x06
#define  DIMM_SLOT_H  0x07
#define  DIMM_SLOT_I  0x08
#define  DIMM_SLOT_J  0x09
#define  DIMM_SLOT_K  0x0A
#define  DIMM_SLOT_L  0x0B
#define  DIMM_0       0x00
#define  DIMM_1       0x01
#define  I2C_0        0x00
#define  I2C_1        0x01
#define  I2C_2        0x02
#define  I2C_3        0x03

#define  __ANONYMOUS1(type, var, line)  type  var##line
#define  _ANONYMOUS0(type, line)  __ANONYMOUS1(type, _anonymous, line)
#define  ANONYMOUS(type)  _ANONYMOUS0(type, __LINE__)
#define  MAKE_ID(Socket, Channel, Dimm, Block)  ((((UINT16) (Socket)) << 12) | (((UINT16)(Channel)) << 8) | (((UINT16)(Dimm)) << 4) | ((UINT16)(Block)))
#define  MAKE_DIMM_INFO_REVISION(Revision)  ANONYMOUS(DIMM_INFO_REVISION_S)={{0,sizeof(DIMM_INFO_REVISION_S)},Revision};
/**
 *  @brief      Macro for DIMM topology
 *  @param[in]  Socket   Socket of this DIMMe is on
 *  @param[in]  Channel  DDR slot (slot name on the board, not SoC channel number) of this DIMM is on,
 *                       DIMM_SLOT_A, DIMM_SLOT_B .. DIMM_SLOT_L
 *  @param[in]  Dimm     DIMM slot of this DIMM is on, DIMM_0 or DIMM_1
 *  @param[in]  BusID    SoC I2C/I3C controller number this DIMM is on
 *  @param[in]  DevID    Smbus address of this DIMM, 8 bits format
 *  @details    This macro covers DIMM routed to I2C or I3C.
 *              This macro does not declares I2C or I3C used on SOC. Use following token instead for each controller:
 *              APCB_TOKEN_UID_I2C_I3C_SMBUS_0
 *              APCB_TOKEN_UID_I2C_I3C_SMBUS_1
 *              APCB_TOKEN_UID_I2C_I3C_SMBUS_2
 *              APCB_TOKEN_UID_I2C_I3C_SMBUS_3
 *              APCB_TOKEN_UID_I2C_I3C_SMBUS_4
 *              APCB_TOKEN_UID_I2C_I3C_SMBUS_5
 */
#define  MAKE_DIMM_ADDR_I2C(Socket, Channel, Dimm, BusID, DevID)  ANONYMOUS(DIMM_INFO_DEV_ADDR_S)={{1,sizeof(DIMM_INFO_DEV_ADDR_S)},MAKE_ID(Socket, Channel, Dimm, 0),BusID,DevID};

//
// Blob structures
//
typedef struct {
  UINT16 Type;
  UINT16 Length;
} DIMM_INFO_COMMON_HEADER;

typedef struct {
  DIMM_INFO_COMMON_HEADER Header;
  UINT32                  Revision;
} DIMM_INFO_REVISION_S;

typedef struct {
  DIMM_INFO_COMMON_HEADER Header;     // Type --> I2C, I3C, SMBUS
  UINT16                  Key;        // <4:4:4:4> = <Socket:Channel:Dimm:Reserve>
  UINT8                   BusID;      // 0:I2C0, 1:I2C1, 2:I2C3, 3:I2C4
                                      // 1:SMBUS0, 1:SMBUS1(ASF)
                                      // 2:I3C0, 1:I3C1, 2:I3C3, 3:I3C4
  UINT8                   DevID;      // 7-bit Address of SPD5 Hub Device <4:3:1> = <1010b(LID):xxxb(HID):0b>
} DIMM_INFO_DEV_ADDR_S;

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


MAKE_DIMM_INFO_REVISION (0)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_A, DIMM_0, I2C_0, 0xA0)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_B, DIMM_0, I2C_0, 0xA2)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_C, DIMM_0, I2C_0, 0xA4)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_D, DIMM_0, I2C_0, 0xA6)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_E, DIMM_0, I2C_0, 0xA8)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_F, DIMM_0, I2C_0, 0xAA)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_G, DIMM_0, I2C_1, 0xA0)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_H, DIMM_0, I2C_1, 0xA2)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_I, DIMM_0, I2C_1, 0xA4)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_J, DIMM_0, I2C_1, 0xA6)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_K, DIMM_0, I2C_1, 0xA8)
MAKE_DIMM_ADDR_I2C (SOCKET_0, DIMM_SLOT_L, DIMM_0, I2C_1, 0xAA)

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();

