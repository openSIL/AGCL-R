/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/*****************************************************************************
 *
 * Warning: BoardIdGettingMethod applies to multiple APCB only, please remove it
 * from ApcbCreate.bat if only 1 APCB instance is needed
 *
 *****************************************************************************
 */

#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>

APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_CONFIG,                                // GroupId
  APCB_CONFIG_TYPE_PRIORITY_CUSTOMIZATION,          // TypeId
  sizeof(ApcbTypeHeader),       // SizeOfType, will be fixed up by tool
  0,                            // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_STRUCT,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_NATIVE_RAW,
    0,
    APCB_PRIORITY_TYPE_MASK_DEFAULT | APCB_PRIORITY_TYPE_MASK_HARD_FORCE, // Priority mask
    0,
    0,
    BLDCFG_APCB_DATA_BOARD_MASK                 // Board specific APCB instance mask
  }
};  // SizeOfType will be fixed up by tool

APCB_PRIORITY_CUSTOMIZE_MAP  ApcbPriorityMap[] = {
#if 1 // CRB
    {APCB_PRIORTY_ORDER_HIGH, APCB_PRIORITY_TYPE_MASK_ADMIN},
    {APCB_PRIORTY_ORDER_MEDIUM, APCB_PRIORITY_TYPE_MASK_EVENT_LOGGING},
    {APCB_PRIORTY_ORDER_LOW, APCB_PRIORITY_TYPE_MASK_DEBUG},
    {APCB_PRIORTY_ORDER_LOWEST, APCB_PRIORITY_TYPE_MASK_NORMAL}
#else // Customer board
    {APCB_PRIORTY_ORDER_HIGH, APCB_PRIORITY_TYPE_MASK_ADMIN},
    {APCB_PRIORTY_ORDER_MEDIUM, APCB_PRIORITY_TYPE_MASK_EVENT_LOGGING},
//  {APCB_PRIORTY_ORDER_LOW, APCB_PRIORITY_TYPE_MASK_DEBUG},
    {APCB_PRIORTY_ORDER_LOWEST, APCB_PRIORITY_TYPE_MASK_NORMAL | APCB_PRIORITY_TYPE_MASK_DEBUG}
#endif
};

APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();





