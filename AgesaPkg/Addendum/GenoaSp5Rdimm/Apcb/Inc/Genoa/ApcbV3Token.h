/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */
/**
 * ApcbV3Token.h
 *
 * APCB V3 Token definitions
 *
 */

#ifndef _APCB_V3_TOKEN_H_
#define _APCB_V3_TOKEN_H_
//
// @APCB_START
//

#define APCB_TYPE_TOKEN_BOOLEAN   0x0000
#define APCB_TYPE_TOKEN_1BYTE     0x0001
#define APCB_TYPE_TOKEN_2BYTES    0x0002
#define APCB_TYPE_TOKEN_4BYTES    0x0004

#include "ApcbV3TokenUid.h"

/*
typedef struct {
  UINT32                  Token;
  UINT32                  Value;
} APCB_TOKEN_PAIR;
*/

/**
 * @brief APCB Token Pair for a Boolean option
 */
typedef struct {
  UINT32  Token;      ///< Token UID
  BOOLEAN ValueBool;  ///< Boolean token value
  UINT8   Rsvd[3];    ///< Reserved
} APCB_TOKEN_PAIR_BOOL;

/**
 * @brief APCB Token Pair for a 1Byte/UINT8 option
 */
typedef struct {
  UINT32  Token;    ///< Token UID
  UINT8   Value8;   ///< 1Byte token value
  UINT8   Rsvd[3];  ///< Reserved
} APCB_TOKEN_PAIR_UINT8;

/**
 * @brief APCB Token Pair for a 2Byte/UINT16 option
 */
typedef struct {
  UINT32  Token;    ///< Token UID
  UINT16  Value16;  ///< 2Byte token value
  UINT8   Rsvd[2];  ///< Reserved
} APCB_TOKEN_PAIR_UINT16;

/**
 * @brief APCB Token Pair for a 4Byte/UINT32 option
 */
typedef struct {
  UINT32 Token;   ///< Token UID
  UINT32 Value32; ///< 4Byte token value
} APCB_TOKEN_PAIR_UINT32;

#define APCB_TOKEN_BOOL(UID, BoolVal)      {UID, BoolVal, {0,0,0}}
#define APCB_TOKEN_U8(UID, Uint8Val)       {UID, Uint8Val, {0, 0,0}}
#define APCB_TOKEN_U16(UID, Uint16Val)     {UID, Uint16Val, {0,0}}
#define APCB_TOKEN_U32(UID, Uint32Val)     {UID, Uint32Val}

#define APCB_TOKEN_VAL_BOOL(TokenName)  APCB_TOKEN_BOOL(TokenName, TokenName##_VALUE)
#define APCB_TOKEN_VAL_U8(TokenName)    APCB_TOKEN_U8(TokenName, TokenName##_VALUE)
#define APCB_TOKEN_VAL_U16(TokenName)   APCB_TOKEN_U16(TokenName, TokenName##_VALUE)
#define APCB_TOKEN_VAL_U32(TokenName)   APCB_TOKEN_U32(TokenName, TokenName##_VALUE)

#endif // _APCB_V3_TOKEN_H_
