/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD FCH SMM Power Button Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_SMM_PWRBTN_DISPATCHER2_H_
#define _FCH_SMM_PWRBTN_DISPATCHER2_H_


#include "FchSmmDispatcher.h"

#include <Protocol/SmmPowerButtonDispatch2.h>
#include <Protocol/FchSmmPwrBtnDispatch2.h>

extern  FCH_SMM_PWRBTN_DISPATCH2_PROTOCOL gFchSmmPwrBtnDispatch2Protocol;
extern  EFI_SMM_POWER_BUTTON_DISPATCH2_PROTOCOL gEfiSmmPwrBtnDispatch2Protocol;


EFI_STATUS
EFIAPI
FchSmmPwrBtnDispatchHandler (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

///
/// Power Button SMI Node
///
typedef struct _FCH_SMM_PWRBTN_NODE {
  EFI_HANDLE                              DispatchHandle;         ///< Dispatch Hangle
  FCH_SMM_PWRBTN_REGISTER_CONTEXT         Context;                ///< Register context
  FCH_SMM_PWRBTN_HANDLER_ENTRY_POINT2     CallBack2Function;      ///< SMM handler2 entry point
  struct _FCH_SMM_PWRBTN_NODE             *FchPwrBtnNodePtr;      ///< pointer to next node
} FCH_SMM_PWRBTN_NODE;

extern  FCH_SMM_PWRBTN_NODE                *HeadFchSmmPwrBtnNodePtr;
#endif


