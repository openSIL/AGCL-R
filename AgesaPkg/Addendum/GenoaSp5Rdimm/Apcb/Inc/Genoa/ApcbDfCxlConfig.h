/*****************************************************************************
 *
 * Copyright (C) 2019-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_DF_CXL_CONFIG_H_
#define _APCB_DF_CXL_CONFIG_H_

//
// @APCB_START
//

//
// @CONSTANT
//
#define MAX_CXL_REGIONS  8
#define MAX_CXL_DSMAS    2
#define MAX_CXL_DSIS     2

#pragma pack (push, 1)

typedef struct {
  UINT8 Seg;
  UINT8 Bus;
  UINT8 Dev;
  UINT8 Func;
} CXL_PCI_SBDF;

typedef struct {
  UINT8  Handle;    /// The handle used to refer to this DSMAD
  UINT8  Flags;     /// Bits 1:0 reserved; Bit 2 set represents non-volatile memory; Bits 7:3 reserved
  UINT64 DpaBase;   /// The lowest DPA address associated with this DSMAD
  UINT64 DpaLength; /// Length in bytes of this DSMAD
} CXL_DSMAS;

typedef struct {
  UINT8  Flags;     /// Bit 0 set indicates Initiator has memory attached; Bits 7:1 reserved
  UINT8  Handle;    /// If Flags is 1, DSMAS handle associated with this initiator
} CXL_DSIS;

typedef struct _CXL_REGION_DESCRIPTOR {
  UINT64        Size;                 ///< Raw size.  A value of zero means the entry should be ignored.
  UINT8         Alignment;            ///< Required alignment.
  UINT8         Socket;               ///< Zero means socket 0, One means socket 1
  UINT8         PhysNbioMap;          ///< Bit n set means NBIO n should be included in this region.
  UINT8         IntlvSize;            ///< see DF_MEM_INTLV_SIZE_VALIDVAL
  UINT8         SubIntlvMap[4];       ///< sub-link interleave bitfield
  UINT8         SubIntlvSize;         ///< sub-link interleave size
  UINT8         Type;                 /// 0 - Volatile; 1 - Persistent, 2 - Cache
  UINT8         DsmasCount;           /// The number of DSMAS
  UINT8         DsisCount;            /// The number of DSIS
  CXL_DSMAS     Dsmas[MAX_CXL_DSMAS]; /// CXL CDAT DSMAS
  CXL_DSIS      Dsis[MAX_CXL_DSIS];   /// CXL CDAT DSIS
  CXL_PCI_SBDF  Sbdf;                 /// PCI SBDF
} CXL_REGION_DESCRIPTOR;


/** CXL_CONFIG
*    @GROUPID: APCB_GROUP_DF
*    @TYPEID: APCB_DF_TYPE_CXL_CONFIG
*    This data structure is used to CXL region info
*/
typedef struct _CXL_CONFIG {
  CXL_REGION_DESCRIPTOR  Region[MAX_CXL_REGIONS];
} CXL_CONFIG;

#pragma pack (pop)

#endif // _APCB_DF_CXL_CONFIG_H_
