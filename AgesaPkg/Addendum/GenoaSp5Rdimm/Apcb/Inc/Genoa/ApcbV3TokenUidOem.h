/********************************************************************************
 * Copyright (C) 2021-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *****************************************************************************
*/
#ifndef _APCB_V3_TOKEN_UID_OEM_H_
#define _APCB_V3_TOKEN_UID_OEM_H_
//
// @APCB_START
//


// =================================================================================================
//
// @APCB_TOKEN
//
// -------------------------------------------------------------------------------------------------
// @GROUPID: APCB_GROUP_TOKEN
// @TYPEID: APCB_TYPE_TOKEN_BOOLEAN
// @SIZE: 1
  #define APCB_TOKEN_UID_SAMPLE_BOOLEAN_CTRL  0xFFFF6893  // bool
/// @DESC: PSP TP Port control
/// @RANGE: BOOLEAN_TRUE_FALSE_VAL

// -------------------------------------------------------------------------------------------------
// @GROUPID: APCB_GROUP_TOKEN
// @TYPEID: APCB_TYPE_TOKEN_1BYTE
// @SIZE: 1
//
  #define APCB_TOKEN_UID_SAMPLE_UINT8_CTRL    0xFFFF0369  // uint8
  #define APCB_TOKEN_UID_SAMPLE_UINT8_CTRL1   0xFFFF3E64  // uint8
  #define APCB_TOKEN_UID_SAMPLE_UINT8_CTRL2   0xFFFFEE23  // uint8
  #define APCB_TOKEN_UID_SAMPLE_UINT8_CTRL3   0xFFFFB9B1  // uint8

/// @DESC: PSP_ENABLE_DEBUG_MODE
/// @RANGE:


// -------------------------------------------------------------------------------------------------
// @GROUPID: APCB_GROUP_TOKEN
// @TYPEID: APCB_TYPE_TOKEN_2BYTES
// @SIZE: 2
//
  #define APCB_TOKEN_UID_SAMPEL_UINT16_CTRL   0xFFFFDAC6  // uint16
/// @DESC: BOTTOMIO
/// @RANGE:


// -------------------------------------------------------------------------------------------------
// @GROUPID: APCB_GROUP_TOKEN
// @TYPEID: APCB_TYPE_TOKEN_2BYTES
// @SIZE: 4
//
  #define APCB_TOKEN_UID_SAMPLE_UINT32_CTRL   0xFFFF60E3  // uint32
/// @DESC: CCX_MIN_SEV_ASID
/// @RANGE:


#endif // _APCB_V3_TOKEN_UID_OEM_H_

