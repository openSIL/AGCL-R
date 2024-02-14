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
#ifdef APCB_INTERNAL_BUILD
  #if APCB_INTERNAL_BUILD
    #include <Internal/ApcbV3TokenUidInternal.h>
  #endif
#endif
#include "ApcbAutoGen.h"


APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_TOKEN,
  APCB_TYPE_TOKEN_2BYTES,
  sizeof(ApcbTypeHeader),                       // SizeOfType, will be fixed up by tool
  1,   // APCB_TYPE_INSTANCE_DEBUG              // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_TOKEN,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_ASCENDING,
    APCB_TYPE_ATTR_UNITSIZE_TOKEN_V3,
    APCB_PRIORITY_TYPE_MASK_MEDIUM,
    APCB_TYPE_ATTR_KEYSIZE_TOKEN_V3,
    APCB_TYPE_ATTR_KEYPOS_TOKEN_V3,
    APCB_BOARD_INSTANCE_ALL_KNOWN
  }
};  // SizeOfType will be fixed up by tool


#if !APCB_TOKEN_U16_AUTOGEN_EMPTY

APCB_TOKEN_PAIR_UINT16 TokeList[] = {
// Two macros can be used for token definitions
//  APCB_TOKEN_U16 (APCB_TOKEN_UID_NAME, APCB_TOKEN_UID_NAME_VALUE),
//  APCB_TOKEN_VAL_U16(APCB_TOKEN_UID_NAME),  // Expand to use APCB_TOKEN_UID_NAME_VALUE

  //
  // CBS Token Macros
  //
  APCB_CMN_TOKEN_U16_AUTOGEN
  APCB_DBG_TOKEN_U16_AUTOGEN
};

#endif // !APCB_TOKEN_U32_AUTOGEN_EMPTY


APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();




