/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD FCH SMM Sleep Type Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_SMM_SX_DISPATCHER_H_
#define _FCH_SMM_SX_DISPATCHER_H_


#include "FchSmmDispatcher.h"

#include <Protocol/SmmSxDispatch2.h>
#include <Protocol/FchSmmSxDispatch2.h>

extern  FCH_SMM_SX_DISPATCH2_PROTOCOL gFchSmmSxDispatch2Protocol;
extern  EFI_SMM_SX_DISPATCH2_PROTOCOL gEfiSmmSxDispatch2Protocol;

#define SLEEP_TYPE_S0 0
#define SLEEP_TYPE_S1 1
#define SLEEP_TYPE_S2 2
#define SLEEP_TYPE_S3 3
#define SLEEP_TYPE_S4 4
#define SLEEP_TYPE_S5 5

EFI_STATUS
EFIAPI
FchSmmSxDispatchHandler (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

///
/// Sleep Type Node
///
typedef struct _FCH_SMM_SX_NODE {
  EFI_HANDLE                         DispatchHandle;         ///< Dispatch Hangle
  FCH_SMM_SX_REGISTER_CONTEXT        Context;                ///< Register context
  FCH_SMM_SX_HANDLER_ENTRY_POINT2    CallBack2Function;      ///< SMM handler2 entry point
  struct _FCH_SMM_SX_NODE            *FchSxNodePtr;          ///< pointer to next node
} FCH_SMM_SX_NODE;


extern  FCH_SMM_SX_NODE               *HeadFchSmmSxNodePtr;
#endif


