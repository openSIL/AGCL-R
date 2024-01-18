/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD Hudson-2 SMI Dispatcher Driver Example
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _FCH_SMM_IO_TRAP_DISPATCHER_H_
#define _FCH_SMM_IO_TRAP_DISPATCHER_H_

#include "FchSmmDispatcher.h"

#include <Protocol/SmmIoTrapDispatch2.h>
#include <Protocol/FchSmmIoTrapDispatch2.h>

extern  FCH_SMM_IO_TRAP_DISPATCH2_PROTOCOL gFchSmmIoTrapDispatch2Protocol;
extern  EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL gEfiSmmIoTrapDispatch2Protocol;

EFI_STATUS
EFIAPI
FchSmmIoTrapDispatchHandler (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

/// South Bridge I/O trap entry structure
typedef struct {
  UINT32                                StatusMask;             ///< Status mask
  UINT8                                 EnableBitOffset;        ///< Enable bit
  UINT8                                 BaseAddressRegister;    ///< Base address register
  UINT8                                 RwAddressRegister;      ///< Read/Write register
  EFI_HANDLE                            DispatchHandle;         ///< Dispatch Hangle
  FCH_SMM_IO_TRAP_REGISTER_CONTEXT      Context;                ///< Register context
  FCH_SMM_IO_TRAP_HANDLER_ENTRY_POINT2  DispatchFunction;       ///< SMM handler entry point
} FCH_IO_TRAP_ENTRY;


#endif


