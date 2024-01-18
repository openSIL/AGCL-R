/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD FCH Periodical Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_SMM_PERIODICAL_DISPATCHER_H_
#define _FCH_SMM_PERIODICAL_DISPATCHER_H_


#include "FchSmmDispatcher.h"

#include <Protocol/SmmPeriodicTimerDispatch2.h>
#include <Protocol/FchSmmPeriodicalDispatch2.h>

#define  ELAPSED_TIME_UNKNOWN    0

extern  FCH_SMM_PERIODICAL_DISPATCH2_PROTOCOL gFchSmmPeriodicalDispatch2Protocol;
extern  EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL gEfiSmmPeriodicalDispatch2Protocol;

EFI_STATUS
EFIAPI
FchSmmPeriodicalDispatchHandler (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

///
/// Periodic SMI Node
///
typedef struct _FCH_SMM_PERIODICAL_NODE {
  EFI_HANDLE                                  DispatchHandle;             ///< Dispatch Hangle
  FCH_SMM_PERIODICAL_REGISTER_CONTEXT         Context;                    ///< Register context
  FCH_SMM_PERIODICAL_HANDLER_ENTRY_POINT2     CallBack2Function;          ///< SMM handler entry point 2
  struct _FCH_SMM_PERIODICAL_NODE             *FchPeriodicalNodePtr;      ///< pointer to next node
} FCH_SMM_PERIODICAL_NODE;

extern  FCH_SMM_PERIODICAL_NODE                *HeadFchSmmPeriodicalNodePtr;
extern  EFI_SMM_PERIODIC_TIMER_CONTEXT         EfiSmmPeriodicTimerContext;

#endif


