/*****************************************************************************
 * Copyright (C) 2021-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/

/* $NoKeywords:$ */
/**
 * @file
 *
 * @e \$Revision:$   @e \$Date:$
 */
/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */
#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include <ApcbDfCxlConfig.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_DF,              ///< GroupId
  APCB_DF_TYPE_CXL_CONFIG,  ///< TypeId
  sizeof(ApcbTypeHeader),     ///< SizeOfType, will be fixed up by tool
  0,                          ///< InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_STRUCT,         ///< context type struct
    APCB_TYPE_ATTR_CONTEXT_FORMAT_NATIVE_RAW,   ///< apcb type attribute context format
    0,                            ///<
    APCB_PRIORITY_TYPE_MASK_LOW,  ///< Priority mask
    0,                            ///<
    0,                            ///<
    APCB_BOARD_INSTANCE_ALL_KNOWN     ///< apcb control instance
  }
};  // SizeOfType will be fixed up by tool

  UINT64        Size;          ///< Raw size.  A value of zero means the entry should be ignored.
  UINT8         Alignment;     ///< Required alignment.
  UINT8         Socket;        ///< Zero means socket 0, One means socket 1
  UINT8         PhysNbioMap;   ///< Bit n set means NBIO n should be included in this region.
  UINT8         IntlvSize;     ///< see DF_MEM_INTLV_SIZE_VALIDVAL
  UINT8         SubIntlvMap[4];///< sub-link interleave bitfield
  UINT8         SubIntlvSize;  ///< sub-link interleave size
  UINT8         Type;          ///< 0 - Volatile; 1 - Persistent
  UINT8         DsmasCount;           ///< The number of DSMAS
  UINT8         DsisCount;            ///< The number of DSIS
  CXL_DSMAS     Dsmas[MAX_CXL_DSMAS]; ///< CXL CDAT DSMAS
  CXL_DSIS      Dsis[MAX_CXL_DSIS];   ///< CXL CDAT DSIS
  CXL_PCI_SBDF  Sbdf;                 ///< PCI SBDF

CXL_REGION_DESCRIPTOR  CxlConfig[] =
{
  ///< {Size, Alignment, Socket, PhysNbioMap, IntlvSize, SubIntlvMap[4], SubIntlvSize, Type, DsmasCount, DsisCount, Dsmas[2], Dsis[2], Sbdf}
  ///<
  ///< P0-CXL0
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P0-CXL1
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P0-CXL2
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P0-CXL3
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P1-CXL0
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P1-CXL1
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P1-CXL2
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
  ///<
  ///< P1-CXL3
  ///<
  {0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, {{0,0,0,0}, {0,0,0,0}}, {{0,0}, {0,0}}, {0,0,0,0}},
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();
