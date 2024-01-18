/******************************************************************************
*
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
**/

#define FILECODE UEFI_SMM_FCHSMMDIAGDISPATCHER_FCHSMMDIAGDISPATCHER_FILECODE

#include <Protocol/SmmBase2.h>
#include <Protocol/SmmConfiguration.h>
#include <Protocol/SmmCpuIo2.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/FchSmmLib.h>
#include <Protocol/SmmCpu.h>
#include "FchPlatform.h"
#include "FchBiosRamUsage.h"
#include <Library/SmmMemLib.h>

#define DIAG_ENABLE                 0x1
#define DIAG_DISABLE                0x2

extern EFI_GUID gFchSmmDiagDispatchProtocolGuid;

BOOLEAN DiagEnable;

typedef struct {
  EFI_GUID  *Guid;
  VOID      *Interface;
} FCH_PROTOCOL_LIST;

FCH_PROTOCOL_LIST FchProtocolDiagList[] = {
                    {&gFchSmmDiagDispatchProtocolGuid, NULL}
                    };

EFI_STATUS
EFIAPI
FchSmmDiagDispatchHandler (
  IN       EFI_HANDLE                   SmmImageHandle,
  IN       CONST VOID                   *SmmEntryContext,
  IN OUT   VOID                         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN                        *SourceSize OPTIONAL
  );

VOID
FchSmmDiagIoRead (
  IN       EFI_SMM_CPU_IO2_PROTOCOL    *SmmIo,
  IN       EFI_SMM_IO_WIDTH            AccessWidth,
  IN       UINT16                      Address,
     OUT   VOID                        *Value
  );
VOID
FchSmmDiagIoWrite (
  IN       EFI_SMM_CPU_IO2_PROTOCOL    *SmmIo,
  IN       EFI_SMM_IO_WIDTH            AccessWidth,
  IN       UINT64                      Address,
  IN       VOID                        *Value
  );
/*----------------------------------------------------------------------------------------*/
/**
 * Entry point of the AMD FCH SMM dispatcher driver
 * Example of dispatcher driver that handled IO TRAP requests only
 *
 * @param[in]     ImageHandle    Pointer to the firmware file system header
 * @param[in]     SystemTable    Pointer to System table
 *
 * @retval        EFI_SUCCESS    Module initialized successfully
 * @retval        EFI_ERROR      Initialization failed (see error for more details)
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmDiagDispatcherEntry (
  IN       EFI_HANDLE         ImageHandle,
  IN       EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS                    Status;
  EFI_HANDLE                    DispatchHandle;
  EFI_HANDLE                    FchSmmDiagDispatcherHandle;
  UINTN                         i;

  if (PcdGetBool (PcdFchSmiDiagEnable) == FALSE){
    return EFI_UNSUPPORTED;
  }

  Status = gSmst->SmiHandlerRegister (
                    FchSmmDiagDispatchHandler,
                    NULL,
                    &DispatchHandle
                    );

  if (EFI_ERROR (Status)) {
    return Status;
  }

  for (i = 0 ; i < sizeof (FchProtocolDiagList) / sizeof (FCH_PROTOCOL_LIST); i++ ) {
    FchSmmDiagDispatcherHandle =  NULL;
    Status = gSmst->SmmInstallProtocolInterface (
               &FchSmmDiagDispatcherHandle,
               FchProtocolDiagList[i].Guid,
               EFI_NATIVE_INTERFACE,
               FchProtocolDiagList[i].Interface);
    if (EFI_ERROR (Status)) {
      return Status;
    }
  }

  return Status;
}

VOID
FchSmmDiagIoRead (
  IN       EFI_SMM_CPU_IO2_PROTOCOL    *SmmIo,
  IN       EFI_SMM_IO_WIDTH            AccessWidth,
  IN       UINT16                      Address,
     OUT   VOID                        *Value
  )
{
  SmmIo->Io.Read (
                   SmmIo,
                   AccessWidth,
                   Address,
                   1,
                   Value
                   );
}
VOID
FchSmmDiagIoWrite (
  IN       EFI_SMM_CPU_IO2_PROTOCOL    *SmmIo,
  IN       EFI_SMM_IO_WIDTH            AccessWidth,
  IN       UINT64                      Address,
  IN       VOID                        *Value
  )
{
  SmmIo->Io.Write (
              SmmIo,
              AccessWidth,
              Address,
              1,
              Value
              );
}

/*----------------------------------------------------------------------------------------*/
/**
 * FCH SMM dispatcher handler
 *
 *
 * @param[in]        SmmImageHandle                 Image Handle
 * @param[in]        SmmEntryContext                (see PI 1.2 for more details)
 * @param[in, out]   OPTIONAL CommunicationBuffer   Communication Buffer (see PI 1.1 for more details)
 * @param[in, out]   OPTIONAL SourceSize            Buffer size (see PI 1.1 for more details)

 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmDiagDispatchHandler (
  IN       EFI_HANDLE                   SmmImageHandle,
  IN       CONST VOID                   *SmmEntryContext,
  IN OUT   VOID                         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN                        *SourceSize OPTIONAL
  )
{
  EFI_STATUS   Status;
  UINT16       SwSmiCmdAddress; // acpismicmd is 16bit register
  UINT8        SwSmiValue;
  UINT8        Index;

  if ( CommunicationBuffer != NULL
    && SourceSize != NULL
    && !SmmIsBufferOutsideSmmValid ((UINTN)CommunicationBuffer, (UINT64)(*SourceSize)) )
  {
    DEBUG ((EFI_D_ERROR, "[%a]SMM communication data buffer in SMRAM or overflow!\n", __FUNCTION__));
    return (EFI_INVALID_PARAMETER);
  }

  LibFchSmmPmioRead16V2 (&gSmst->SmmIo, FCH_PMIOA_REG6A, &SwSmiCmdAddress);
  FchSmmDiagIoWrite (&gSmst->SmmIo, SMM_IO_UINT16, 0x80, &SwSmiCmdAddress);
  FchSmmDiagIoRead (&gSmst->SmmIo, SMM_IO_UINT8, SwSmiCmdAddress, &SwSmiValue);
  if (SwSmiValue == DIAG_ENABLE) {
    DiagEnable = TRUE;
    LibFchSmmPmioRead8V2 (&gSmst->SmmIo, FCH_PMIOA_REG04, &SwSmiCmdAddress);
    SwSmiCmdAddress |= BIT0;
    LibFchSmmPmioWrite8V2 (&gSmst->SmmIo, FCH_PMIOA_REG04, &SwSmiCmdAddress);

    FchSmmDiagIoWrite (&gSmst->SmmIo, SMM_IO_UINT16, 0x80, &DiagEnable);
  } else if (SwSmiValue == DIAG_DISABLE) {
    DiagEnable = FALSE;
    FchSmmDiagIoWrite (&gSmst->SmmIo, SMM_IO_UINT16, 0x80, &DiagEnable);
  }

  if (DiagEnable == TRUE) {
    for ( Index = 0; Index < 20; Index++ ) {
      ACPIMMIO8 (BIOS_RAM_MMIO_BASE + BIOS_RAM_REG20 + Index) = ACPIMMIO8 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG80 + Index);
    }
    ACPIMMIO8 (BIOS_RAM_MMIO_BASE + BIOS_RAM_REG40) = SwSmiValue;

    for ( Index = 0; Index < 20; Index++ ) {
      ACPIMMIO8 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG80 + Index) |= 0;
    }
  }
  Status = EFI_SUCCESS;
  return  Status;
}







