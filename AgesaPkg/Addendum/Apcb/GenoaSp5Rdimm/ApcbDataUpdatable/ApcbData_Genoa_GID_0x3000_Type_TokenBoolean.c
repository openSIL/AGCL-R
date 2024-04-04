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
#include <ApcbV3TokenUid.h>

#define APCB_TYPE_DATA_HEADER_ONLY  1

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_TOKEN,
  APCB_TYPE_TOKEN_BOOLEAN,
  sizeof(ApcbTypeHeader),                       // SizeOfType, will be fixed up by tool
  0,                          // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_TOKEN,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_ASCENDING,
    APCB_TYPE_ATTR_UNITSIZE_TOKEN_V3,
    APCB_PRIORITY_TYPE_MASK_LOW,
    APCB_TYPE_ATTR_KEYSIZE_TOKEN_V3,
    APCB_TYPE_ATTR_KEYPOS_TOKEN_V3,
    APCB_BOARD_INSTANCE_ALL_KNOWN
  }
};  // SizeOfType will be fixed up by tool


#if !APCB_TYPE_DATA_HEADER_ONLY
APCB_TOKEN_PAIR_BOOL TokeList[] = {
// Two macros can be used for token definitions
//  APCB_TOKEN_BOOL (APCB_TOKEN_UID_NAME, APCB_TOKEN_UID_NAME_VALUE),
//  APCB_TOKEN_VAL_BOOL(APCB_TOKEN_UID_NAME), // Expand to use APCB_TOKEN_UID_NAME_VALUE

//  APCB_TOKEN_BOOL (0x00000000, FALSE) // Null token, remove this when there's other token defined
};
#endif

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();




