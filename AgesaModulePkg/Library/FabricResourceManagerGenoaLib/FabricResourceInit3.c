/*
 ******************************************************************************
 *
 * Copyright (C) 2020-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */
/* $NoKeywords:$ */
/**
 * @file
 *
 * Base Fabric MMIO map manager Lib implementation for Genoa
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  Library
 * @e \$Revision$   @e \$Date$
 *
 */


/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */

#include <Uefi/UefiBaseType.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseFabricTopologyLib.h>
#include <RcMgr/FabricResourceManager.h>
#include <Sil-api.h>
#include <RcMgr/DfX/RcManager4-api.h>

#define FILECODE LIBRARY_FABRICRESOURCEMANAGERDF3LIB_FABRICRESOURCEINIT3_FILECODE

/*----------------------------------------------------------------------------------------
 *                   D E F I N I T I O N S    A N D    M A C R O S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *           P R O T O T Y P E S     O F     L O C A L     F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */

VOID
FabricCheckResourceValid (
  IN       DFX_FABRIC_RESOURCE_FOR_EACH_RB  *ResourceSizeForEachRb
  );

/*----------------------------------------------------------------------------------------
 *                          E X P O R T E D    F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */

/*---------------------------------------------------------------------------------------*/
/**
 * FabricResourceInit
 *
 * Initialize DF resource registers for each RootBridge.
 *
 */
EFI_STATUS
FabricResourceInit (
  IN OUT    DFX_RCMGR_INPUT_BLK  *DFXRcmgrInputBlock
  )
{
  //
  // Provide RcMgrData defaults
  //
  DFXRcmgrInputBlock->SetRcBasedOnNv = FALSE;
  DFXRcmgrInputBlock->SocketNumber = 1;
  DFXRcmgrInputBlock->RbsPerSocket = 4;
  DFXRcmgrInputBlock->McptEnable = TRUE;
  DFXRcmgrInputBlock->PciExpressBaseAddress = PcdGet64 (PcdPciExpressBaseAddress);
  DFXRcmgrInputBlock->BottomMmioReservedForPrimaryRb = PcdGet32 (PcdAmdBottomMmioReservedForPrimaryRb);
  DFXRcmgrInputBlock->MmioSizePerRbForNonPciDevice = PcdGet32 (PcdAmdMmioSizePerRbForNonPciDevice);
  DFXRcmgrInputBlock->MmioAbove4GLimit = PcdGet64 (PcdAmdMmioAbove4GLimit);
  DFXRcmgrInputBlock->Above4GMmioSizePerRbForNonPciDevice = PcdGet32 (PcdAmdAbove4GMmioSizePerRbForNonPciDevice);

  // Output RcMgrData default values
  DEBUG ((DEBUG_INFO, "FabricResourceInit() RcMgrData default values:"));
  DEBUG ((DEBUG_INFO, "  DFRcmgrInputBlock->PciExpressBaseAddress               = %lx\n", PcdGet64 (PcdPciExpressBaseAddress)));
  DEBUG ((DEBUG_INFO, "  DFRcmgrInputBlock->BottomMmioReservedForPrimaryRb      = %x\n", PcdGet32 (PcdAmdBottomMmioReservedForPrimaryRb)));
  DEBUG ((DEBUG_INFO, "  DFRcmgrInputBlock->MmioSizePerRbForNonPciDevice        = %x\n", PcdGet32 (PcdAmdMmioSizePerRbForNonPciDevice)));
  DEBUG ((DEBUG_INFO, "  DFRcmgrInputBlock->MmioAbove4GLimit                    = %lx\n", PcdGet64 (PcdAmdMmioAbove4GLimit)));
  DEBUG ((DEBUG_INFO, "  DFRcmgrInputBlock->Above4GMmioSizePerRbForNonPciDevice = %x\n", PcdGet32 (PcdAmdAbove4GMmioSizePerRbForNonPciDevice)));

  return EFI_SUCCESS;
}
