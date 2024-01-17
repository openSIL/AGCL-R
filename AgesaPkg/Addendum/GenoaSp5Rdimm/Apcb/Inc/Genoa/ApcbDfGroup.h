/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_DF_GROUP_H_
#define _APCB_DF_GROUP_H_


#define  DF_DRAM_NPS0         0
#define  DF_DRAM_NPS1         1
#define  DF_DRAM_NPS2         2
#define  DF_DRAM_NPS4         3


//
// DF Type ID
//
#define APCB_DF_TYPE_XGMI_TX_EQ                     0x00D0
#define   APCB_DF_TYPE_XGMI_INSTANCE_SPEED_COMBINED   0   // Instance ID 0
#define   APCB_DF_TYPE_XGMI_INSTANCE_SPEED_COMBINED_1 1   // Instance ID 1
#include "ApcbDfXgmiTxEq.h"

#define APCB_DF_TYPE_CXL_CONFIG                     0x00CC
#include "ApcbDfCxlConfig.h"

#define APCB_DF_TYPE_XGMI_PHY_OVERRIDE              0x00DD
#include "ApcbDfXgmiPhyOverride.h"

#endif // _APCB_DF_GROUP_H_

