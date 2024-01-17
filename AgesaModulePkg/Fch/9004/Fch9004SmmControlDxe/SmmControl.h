/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * FCH DXE Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:  AGCL-R
 * @e sub-project   SMM Control DXE Driver
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#ifndef _AMD_SMM_CONTROL_H_
#define _AMD_SMM_CONTROL_H_

#define FCH_8259_CONTROL_REG_MASTER 0x20
#define FCH_8259_MASK_REG_MASTER    0x21

#include <Uefi.h>
#include <Library/HobLib.h>
#include <Library/DebugLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/IoLib.h>

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeLib.h>
#include <Guid/EventGroup.h>

// Consumed Protocols
#include <Protocol/PciRootBridgeIo.h>

// Produced Protocols
#include <Protocol/SmmControl2.h>

//
// Module specific definitions
//

#endif // _AMD_SMM_CONTROL_H_


