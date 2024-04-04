/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD SMI Dispatcher Driver Example
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#pragma once

#include <PiSmm.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/IoLib.h>
#include <SilCommon.h>
#include <FchCore/FchHwAcpi/FchHwAcpiReg.h>
#include <Library/IoLib.h>
#include <Library/SmmMemLib.h>
#include <FchSmmSwDispatcher.h>

#define FCH_SMI_REG80            0x80         // SmiStatus0
#define FCH_SMI_REG84            0x84         // SmiStatus1
#define FCH_SMI_REG88            0x88         // SmiStatus2
#define FCH_SMI_REG8C            0x8C         // SmiStatus3
#define FCH_SMI_REG90            0x90         // SmiStatus4
#define FCH_SMI_REG94            0x94         // SmiPointer
#define FCH_SMI_REG96            0x96         // SmiTimer
#define FCH_SMI_REG98            0x98         // SmiTrig
#define FCH_SMI_REG9C            0x9C         // SmiTrig

#define SmiCmdPort  BIT11

#define FCH_SMI_CMD_PORT          BIT_32(11)
#define FCH_END_OF_SMI            BIT_32(28)

#define FCH_SMI_STATUS2           0x88
#define FCH_SMI_TRIGGER           0x98

#define ACPIMMIO32(x) (*(volatile UINT32*)(UINTN)(x))
#define ACPIMMIO16(x) (*(volatile UINT16*)(UINTN)(x))
#define ACPIMMIO8(x)  (*(volatile UINT8*)(UINTN)(x))

typedef struct {
  EFI_GUID              *Guid;
  VOID                  *Interface;
} SMM_PROTOCOL_LIST;

typedef EFI_STATUS (EFIAPI *AMD_SM_SMM_CHILD_DISPATCHER_HANDLER) (
  IN      EFI_HANDLE     SmmImageHandle,
  IN OUT  VOID           *CommunicationBuffer OPTIONAL,
  IN OUT  UINTN          *SourceSize OPTIONAL
  );

///
/// AMD FCH SMM Dispatcher Structure
///
typedef struct {
  UINT32                                SmiStatusReg;   ///< Status Register
  UINT32                                SmiStatusBit;   ///< Status Bit
} FCH_SMM_COMMUNICATION_BUFFER;

