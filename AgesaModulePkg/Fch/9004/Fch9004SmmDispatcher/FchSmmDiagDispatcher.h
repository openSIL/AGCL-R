/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD FCH AOAC SMM Dispatcher Driver Example
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_AOAC_SMM_DISPATCHER_H_
#define _FCH_AOAC_SMM_DISPATCHER_H_

#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>

#include <Protocol/SmmCpu.h>
#include <Protocol/FchAoacSmmSwDispatch.h>


#include "FchPlatform.h"
#pragma pack (8)


#define SmiCmdPortStatus  BIT11

///
/// Soft SMI Node
///
typedef struct _FCH_AOAC_SMM_SW_NODE {
  EFI_HANDLE                              DispatchHandle;                 ///< Dispatch Hangle
  UINT16                                  Order;                          ///< Register context
  UINT8                                   Rule;                           ///< Register rule
  FCH_AOAC_SMM_SW_HANDLER_ENTRY_POINT     AoacCallBackFunction;           ///< SMM handler entry point 2
  struct _FCH_AOAC_SMM_SW_NODE            *AoacFchSwNextNodePtr;          ///< pointer to next node
} FCH_AOAC_SMM_SW_NODE;

///
/// AMD FCH SMM Dispatcher Structure
///

typedef struct {
  UINT8                                  LinkListId;                      /// Link List ID
  FCH_AOAC_SMM_SW_NODE                   *LinkListPtr;                    /// Link List Pointer
} FCH_AOAC_SMM_LINK_LIST_TABLE;

#endif


