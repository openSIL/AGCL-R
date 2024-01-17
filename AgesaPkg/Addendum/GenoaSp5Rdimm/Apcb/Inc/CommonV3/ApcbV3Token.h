/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
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

// #include "ApcbV3TokenUid.h"

/*
typedef struct {
  UINT32                  Token;
  UINT32                  Value;
} APCB_TOKEN_PAIR;
*/

typedef struct {
  UINT32                  Token;
  BOOLEAN              ValueBool;
  UINT8                    Rsvd[3];
} APCB_TOKEN_PAIR_BOOL;

typedef struct {
  UINT32                  Token;
  UINT8                    Value8;
  UINT8                    Rsvd[3];
} APCB_TOKEN_PAIR_UINT8;

typedef struct {
  UINT32                  Token;
  UINT16                  Value16;
  UINT8                    Rsvd[2];
} APCB_TOKEN_PAIR_UINT16;

typedef struct {
  UINT32                  Token;
  UINT32                    Value32;
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


