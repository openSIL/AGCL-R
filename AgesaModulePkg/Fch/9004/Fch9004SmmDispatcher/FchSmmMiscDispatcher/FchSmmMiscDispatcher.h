/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD FCH SMM Misc Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_SMM_MISC_DISPATCHER_H_
#define _FCH_SMM_MISC_DISPATCHER_H_


#include "FchSmmDispatcher.h"

#include <Protocol/FchSmmMiscDispatch.h>

extern  FCH_SMM_MISC_DISPATCH_PROTOCOL gFchSmmMiscDispatchProtocol;


EFI_STATUS
EFIAPI
FchSmmMiscDispatchHandler (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

///
/// MISC SMI Node
///
typedef struct _FCH_SMM_MISC_NODE {
  EFI_HANDLE                               DispatchHandle;         ///< Dispatch Hangle
  FCH_SMM_MISC_REGISTER_CONTEXT            Context;                ///< Register context
  FCH_SMM_MISC_HANDLER_ENTRY_POINT         CallBackFunction;       ///< SMM handler entry point
  struct _FCH_SMM_MISC_NODE                *FchMiscNodePtr;        ///< pointer to next node
} FCH_SMM_MISC_NODE;

extern  FCH_SMM_MISC_NODE                   *HeadFchSmmMiscNodePtr;
#endif


