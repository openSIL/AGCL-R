/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_DATA_GROUP_H_
#define _APCB_DATA_GROUP_H_
//
// @APCB_START
//

//
// Group Id and Type Id for Memory Specific Data
//

#define APCB_GROUP_PSP                                 0x1701
#include "ApcbPspGroup.h"

#define APCB_GROUP_CCX                                 0x1702

#define APCB_GROUP_DF                                  0x1703
#include "ApcbDfGroup.h"

#define APCB_GROUP_MEMORY                              0x1704
#include "ApcbMemGroup.h"

#define APCB_GROUP_GNB                                 0x1705
#include "ApcbGnbGroup.h"

#define APCB_GROUP_FCH                                 0x1706
#include "ApcbFchGroup.h"

#define APCB_GROUP_CBS                                 0x1707

#define APCB_GROUP_OEM                                 0x1708

#define APCB_GROUP_TOKEN                               0x3000
#include "ApcbV3Token.h"

#endif // _APCB_DATA_GROUP_H_


