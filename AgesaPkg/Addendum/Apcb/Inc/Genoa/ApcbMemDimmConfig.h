/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_DIMM_CONFIG_H_
#define _APCB_MEM_DIMM_CONFIG_H_
//
// @APCB_START
//

///===============================================================================
/// DDR4 DIMM ID information
typedef struct {
  UINT8  Socket;            ///< Indicates the socket number
  UINT8  Channel;           ///< Indicates the channel number
  UINT8  Dimm;              ///< Indicates the channel number
  BOOLEAN DimmPresentInConfig;  ///< Indicates that the DIMM config is present
  UINT16 PrevPage1SpdChecksumLow;       ///< DIMM checksum for lower 128 bytes
  UINT16 PrevPage1SpdChecksumHigh;      ///< DIMM checksum for Page 1 upper 128 bytes
  UINT16 PrevDimmManId;     ///< DIMM manufacturer ID
  UINT16 PrevDimmModId;     ///< DIMM Module ID
} DIMM_APCB_INFO_CONFIG_ID;

#endif // _APCB_MEM_DIMM_CONFIG_H_


