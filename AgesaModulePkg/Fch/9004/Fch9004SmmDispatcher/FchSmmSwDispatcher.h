/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD SW SMM Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_SMM_SW_DISPATCHER_H_
#define _FCH_SMM_SW_DISPATCHER_H_

#include "FchSmmDispatcher.h"
#include <PiSmm.h>
#include <Protocol/SmmSwDispatch2.h>
#include "Protocol/FchSmmSwDispatch2.h"
#include <Protocol/SmmCpu.h>

extern  FCH_SMM_SW_DISPATCH2_PROTOCOL gFchSmmSwDispatch2Protocol;
extern  EFI_SMM_SW_DISPATCH2_PROTOCOL gEfiSmmSwDispatch2Protocol;

EFI_STATUS
EFIAPI
FchSmmSwDispatchHandler (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

///
/// Soft SMI Node
///
typedef struct _FCH_SMM_SW_NODE {
  EFI_HANDLE                         DispatchHandle;         ///< Dispatch Hangle
  FCH_SMM_SW_REGISTER_CONTEXT        Context;                ///< Register context
  FCH_SMM_SW_HANDLER_ENTRY_POINT2    CallBack2Function;      ///< SMM handler entry point 2
  struct _FCH_SMM_SW_NODE            *FchSwNodePtr;          ///< pointer to next node
} FCH_SMM_SW_NODE;

#define MAX_SW_SMI_VALUE              0xFF
extern  FCH_SMM_SW_NODE               *HeadFchSmmSwNodePtr;
extern  FCH_SMM_SW_CONTEXT            *EfiSmmSwContext;
extern  EFI_SMM_CPU_PROTOCOL          *mSmmCpuProtocol;
#endif
