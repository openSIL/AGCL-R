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


#include "FchSmmIoTrapDispatcher.h"
#include "Filecode.h"
#define FILECODE UEFI_SMM_FCHSMMDISPATCHER_FCHSMMIOTRAPDISPATCHER_FCHSMMIOTRAPDISPATCHER_FILECODE

EFI_STATUS
EFIAPI
FchSmmIoTrapDispatch2Register (
  IN       CONST FCH_SMM_IO_TRAP_DISPATCH2_PROTOCOL  *This,
  IN       FCH_SMM_IO_TRAP_HANDLER_ENTRY_POINT2      DispatchFunction,
  IN OUT   FCH_SMM_IO_TRAP_REGISTER_CONTEXT          *RegisterContext,
     OUT   EFI_HANDLE                                *DispatchHandle
  );

EFI_STATUS
EFIAPI
FchSmmIoTrapDispatch2UnRegister (
  IN       CONST FCH_SMM_IO_TRAP_DISPATCH2_PROTOCOL *This,
  IN       EFI_HANDLE                               DispatchHandle
  );

FCH_SMM_IO_TRAP_DISPATCH2_PROTOCOL gFchSmmIoTrapDispatch2Protocol = {
  FchSmmIoTrapDispatch2Register,
  FchSmmIoTrapDispatch2UnRegister
};

FCH_IO_TRAP_ENTRY  mFchIoTrapList[] = {
  { BIT20, 0,  0xC0, 0xF0, NULL, {0}, NULL},
  { BIT21, 1,  0xC2, 0xF0, NULL, {0}, NULL},
  { BIT22, 2,  0xC4, 0xF0, NULL, {0}, NULL},
  { BIT23, 3,  0xC8, 0xF0, NULL, {0}, NULL},
};

UINTN mFchIoTrapIndex = 0;

/*----------------------------------------------------------------------------------------*/
/**
 * FCH SMM IO TRAP dispatcher handler
 *
 *
 * @param[in]       SmmImageHandle        Image Handle
 * @param[in, out]   OPTIONAL CommunicationBuffer   Communication Buffer (see PI 1.1 for more details)
 * @param[in, out]   OPTIONAL SourceSize            Buffer size (see PI 1.1 for more details)

 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmIoTrapDispatchHandler (
  IN       EFI_HANDLE   SmmImageHandle,
  IN OUT   VOID         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN        *SourceSize OPTIONAL
  )
{
  EFI_STATUS  Status;
  UINTN       Index;
  UINT32      SmiIoTrapStatusBitmap;
  Status = EFI_UNSUPPORTED;

  SmiIoTrapStatusBitmap = ACPIMMIO32 (ACPI_MMIO_BASE + 0x290);
  SmiIoTrapStatusBitmap &= BIT20 + BIT21 + BIT22 + BIT23;
  if (SmiIoTrapStatusBitmap != 0) {
    for (Index = 0; Index < (sizeof (mFchIoTrapList) / sizeof (FCH_IO_TRAP_ENTRY)); Index++) {
      if ((mFchIoTrapList[Index].StatusMask & SmiIoTrapStatusBitmap) != 0) {
        ACPIMMIO32 (ACPI_MMIO_BASE + 0x290) = mFchIoTrapList[Index].StatusMask;
        if (mFchIoTrapList[Index].DispatchFunction) {
          Status = mFchIoTrapList[Index].DispatchFunction (
                     mFchIoTrapList[Index].DispatchHandle,
                     &mFchIoTrapList[Index].Context,
                     NULL,
                     NULL
                     );
          DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] IoTrap SMM handler dispatched: Address = 0x%04lx, return - %r\n", \
                 mFchIoTrapList[Index].Context.Address, Status));
        }
        break;
      }
    }
  }
  return  Status;
}

/*----------------------------------------------------------------------------------------*/
/**
 * Register IO TRAP child handler
 *
 *
 * @param[in]       This                  Pointer to protocol
 * @param[in]       DispatchFunction      Child dispatcher function
 * @param[in, out]   RegisterContext            Register context (see PI 1.1 for more details)
 * @param[out]      DispatchHandle        Handle (see PI 1.1 for more details)
 *
 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispatcher
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmIoTrapDispatch2Register (
  IN       CONST FCH_SMM_IO_TRAP_DISPATCH2_PROTOCOL  *This,
  IN       FCH_SMM_IO_TRAP_HANDLER_ENTRY_POINT2      DispatchFunction,
  IN OUT   FCH_SMM_IO_TRAP_REGISTER_CONTEXT          *RegisterContext,
     OUT   EFI_HANDLE                                *DispatchHandle
  )
{
  EFI_STATUS  Status;
  UINTN       Index;

  Status = EFI_OUT_OF_RESOURCES;

  ASSERT ((DispatchFunction != NULL) && (DispatchHandle != NULL));

  if (mFchIoTrapIndex == ((sizeof (mFchIoTrapList) / sizeof (FCH_IO_TRAP_ENTRY)))) {
    return EFI_OUT_OF_RESOURCES;
  }
  if (DispatchFunction == NULL || RegisterContext == NULL || DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  for (Index = 0; Index < (sizeof (mFchIoTrapList) / sizeof (FCH_IO_TRAP_ENTRY)); Index++) {
    if ((mFchIoTrapList[Index].DispatchFunction == NULL) && (Index == mFchIoTrapIndex))  {
      CopyMem (
        &mFchIoTrapList[Index].Context,
        RegisterContext,
        sizeof (FCH_SMM_IO_TRAP_REGISTER_CONTEXT)
        );
      mFchIoTrapList[Index].DispatchFunction = DispatchFunction;
      *DispatchHandle = &mFchIoTrapList[Index];
      mFchIoTrapIndex ++;
      //Clear Status
      ACPIMMIO32 (ACPI_MMIO_BASE + 0x290) = mFchIoTrapList[Index].StatusMask;
      //Set base address
      ACPIMMIO16 (ACPI_MMIO_BASE + 0xEC0 + Index * 2) = RegisterContext->Address;
      //Set Read Write Attribute
      ACPIMMIO32 (ACPI_MMIO_BASE + 0xECC ) &= ~ (1 << Index );
      if (RegisterContext->Type == WriteTrap) {
        ACPIMMIO32 (ACPI_MMIO_BASE + 0xECC ) |= (1 << Index );
      }
      // Enable SMI
      ACPIMMIO32 (ACPI_MMIO_BASE + 0x2C4) |= 1 << ((Index * 2) + 8);

      DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Registering IoTrap SMM handler: Address = 0x%04lx, Type = 0x%x\n", \
             RegisterContext->Address, RegisterContext->Type));
      Status = EFI_SUCCESS;
      break;
    }
  }
  return  Status;
}


/*----------------------------------------------------------------------------------------*/
/**
 * Unregister IO TRAP child handler
 *
 *
 * @param[in]       This                  Pointer to protocol
 * @param[in]       DispatchHandle
 *
 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmIoTrapDispatch2UnRegister (
  IN       CONST FCH_SMM_IO_TRAP_DISPATCH2_PROTOCOL *This,
  IN       EFI_HANDLE                               DispatchHandle
  )
{
  EFI_STATUS  Status;
  UINTN       Index;
  Status = EFI_NOT_FOUND;
  for (Index = 0; Index < (sizeof (mFchIoTrapList) / sizeof (FCH_IO_TRAP_ENTRY)); Index++) {
    if ( &mFchIoTrapList[Index] == DispatchHandle) {
      mFchIoTrapList[Index].DispatchFunction = NULL;
      //Clear Status ACTION. Is it safe? wll EOS be taken care?
      ACPIMMIO32 (ACPI_MMIO_BASE + 0x290) = mFchIoTrapList[Index].StatusMask;
      // Disable SMI
      ACPIMMIO32 (ACPI_MMIO_BASE + 0x2C4) &= (~(3 << ((Index * 2) + 8)));
      Status = EFI_SUCCESS;
    }
  }
  return  Status;
}


EFI_STATUS
EFIAPI
EfiSmmIoTrapDispatch2Register (
  IN       CONST EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL *This,
  IN       EFI_SMM_HANDLER_ENTRY_POINT2             DispatchFunction,
  IN OUT   EFI_SMM_IO_TRAP_REGISTER_CONTEXT         *RegisterContext,
     OUT   EFI_HANDLE                               *DispatchHandle
  )
{
  FCH_SMM_IO_TRAP_REGISTER_CONTEXT  FchRegisterContext;

  FchRegisterContext.Address = RegisterContext->Address;
  FchRegisterContext.Length  = RegisterContext->Length;
  FchRegisterContext.Type    = RegisterContext->Type;
  return FchSmmIoTrapDispatch2Register (
           &gFchSmmIoTrapDispatch2Protocol,
           (FCH_SMM_IO_TRAP_HANDLER_ENTRY_POINT2)DispatchFunction,
           &FchRegisterContext,
           DispatchHandle
           );
}

EFI_STATUS
EFIAPI
EfiSmmIoTrapDispatch2UnRegister (
  IN       CONST EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL *This,
  IN       EFI_HANDLE                               DispatchHandle
  )
{
  return FchSmmIoTrapDispatch2UnRegister (
           &gFchSmmIoTrapDispatch2Protocol,
           DispatchHandle
           );
}

EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL gEfiSmmIoTrapDispatch2Protocol = {
  EfiSmmIoTrapDispatch2Register,
  EfiSmmIoTrapDispatch2UnRegister
};



