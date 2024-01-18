/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD Hudson-2 Misc Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#include "FchSmmMiscDispatcher.h"
#include "Filecode.h"
#define FILECODE UEFI_SMM_FCHSMMDISPATCHER_FCHSMMMISCDISPATCHER_FCHSMMMISCDISPATCHER_FILECODE

EFI_STATUS
EFIAPI
FchSmmMiscDispatchRegister (
  IN       CONST FCH_SMM_MISC_DISPATCH_PROTOCOL   *This,
  IN       FCH_SMM_MISC_HANDLER_ENTRY_POINT       CallBackFunction,
  IN OUT   FCH_SMM_MISC_REGISTER_CONTEXT          *MiscRegisterContext,
     OUT   EFI_HANDLE                             *DispatchHandle
  );

EFI_STATUS
EFIAPI
FchSmmMiscDispatchUnRegister (
  IN       CONST FCH_SMM_MISC_DISPATCH_PROTOCOL   *This,
  IN       EFI_HANDLE                             DispatchHandle
  );

EFI_STATUS
EFIAPI
FchSmmMiscSmiEnable (
  IN OUT   FCH_SMM_MISC_REGISTER_CONTEXT          *MiscRegisterContext
  );

FCH_SMM_MISC_DISPATCH_PROTOCOL gFchSmmMiscDispatchProtocol = {
  FchSmmMiscDispatchRegister,
  FchSmmMiscDispatchUnRegister
};

/*----------------------------------------------------------------------------------------*/
/**
 * FCH SMM Misc dispatcher handler
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
FchSmmMiscDispatchHandler (
  IN       EFI_HANDLE   SmmImageHandle,
  IN OUT   VOID         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN        *SourceSize OPTIONAL
  )
{
  EFI_STATUS  Status;
  FCH_SMM_MISC_NODE                   *CurrentFchSmmMiscNodePtr;
  FCH_SMM_COMMUNICATION_BUFFER        *CommunicationBufferPtr;
  UINT16 MiscSmiDispatched;
  MiscSmiDispatched = 0;
  Status = EFI_NOT_FOUND;
  CommunicationBufferPtr = (FCH_SMM_COMMUNICATION_BUFFER *)CommunicationBuffer;

  if (HeadFchSmmMiscNodePtr->FchMiscNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
    ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + CommunicationBufferPtr->SmiStatusReg) = CommunicationBufferPtr->SmiStatusBit;
  } else {
    CurrentFchSmmMiscNodePtr = HeadFchSmmMiscNodePtr;
    ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + CommunicationBufferPtr->SmiStatusReg) = CommunicationBufferPtr->SmiStatusBit;
    while (CurrentFchSmmMiscNodePtr->FchMiscNodePtr!= NULL) {
      if (CurrentFchSmmMiscNodePtr->Context.SmiStatusReg == CommunicationBufferPtr->SmiStatusReg &&
          CurrentFchSmmMiscNodePtr->Context.SmiStatusBit == CommunicationBufferPtr->SmiStatusBit) {
        Status = CurrentFchSmmMiscNodePtr->CallBackFunction (
                                            CurrentFchSmmMiscNodePtr->DispatchHandle,
                                            &CurrentFchSmmMiscNodePtr->Context
                                            );
        MiscSmiDispatched++;
      }
      CurrentFchSmmMiscNodePtr = CurrentFchSmmMiscNodePtr->FchMiscNodePtr;
    }
    if (MiscSmiDispatched <= 0) {
      Status = EFI_NOT_FOUND;
    } else {
      Status = EFI_SUCCESS;
    }
  }
  return  Status;
}

/*----------------------------------------------------------------------------------------*/
/**
 * Register MISC child handler
 *
 *
 * @param[in]       This                  Pointer to protocol
 * @param[in]       CallBackFunction
 * @param[in, out]   MiscRegisterContext
 * @param[out]      DispatchHandle        Handle (see PI 1.1 for more details)
 *
 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmMiscDispatchRegister (
  IN       CONST FCH_SMM_MISC_DISPATCH_PROTOCOL   *This,
  IN       FCH_SMM_MISC_HANDLER_ENTRY_POINT       CallBackFunction,
  IN OUT   FCH_SMM_MISC_REGISTER_CONTEXT          *MiscRegisterContext,
     OUT   EFI_HANDLE                             *DispatchHandle
  )
{
  EFI_STATUS            Status;
  FCH_SMM_MISC_NODE     *NewFchSmmMiscNodePtr;
  FCH_SMM_MISC_NODE     *CurrentFchSmmMiscNodePtr;
  FCH_SMM_MISC_NODE     *PreviousFchSmmMiscNodePtr;

  Status = EFI_OUT_OF_RESOURCES;
  if (CallBackFunction == NULL || MiscRegisterContext == NULL || DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  Status = gSmst->SmmAllocatePool (
                       EfiRuntimeServicesData,
                       sizeof (FCH_SMM_MISC_NODE),
                       (VOID **)&NewFchSmmMiscNodePtr
                       );
  ASSERT_EFI_ERROR (Status);

  NewFchSmmMiscNodePtr->CallBackFunction = CallBackFunction;
  *DispatchHandle = &NewFchSmmMiscNodePtr->DispatchHandle;
  NewFchSmmMiscNodePtr->DispatchHandle   = *DispatchHandle;
  NewFchSmmMiscNodePtr->Context          = *MiscRegisterContext;
  NewFchSmmMiscNodePtr->FchMiscNodePtr = HeadFchSmmMiscNodePtr;

  Status = FchSmmMiscSmiEnable (MiscRegisterContext);

  if (HeadFchSmmMiscNodePtr->FchMiscNodePtr == NULL) {
    NewFchSmmMiscNodePtr->FchMiscNodePtr = HeadFchSmmMiscNodePtr;
    HeadFchSmmMiscNodePtr = NewFchSmmMiscNodePtr;
  } else {
    PreviousFchSmmMiscNodePtr = HeadFchSmmMiscNodePtr;
    CurrentFchSmmMiscNodePtr = HeadFchSmmMiscNodePtr;
    while (CurrentFchSmmMiscNodePtr->FchMiscNodePtr != NULL) {
      if (NewFchSmmMiscNodePtr->Context.Order <= CurrentFchSmmMiscNodePtr->Context.Order &&
          CurrentFchSmmMiscNodePtr->Context.SmiStatusReg == NewFchSmmMiscNodePtr->Context.SmiStatusReg &&
          CurrentFchSmmMiscNodePtr->Context.SmiStatusBit == NewFchSmmMiscNodePtr->Context.SmiStatusBit) {
        if (PreviousFchSmmMiscNodePtr == CurrentFchSmmMiscNodePtr) {
          NewFchSmmMiscNodePtr->FchMiscNodePtr = HeadFchSmmMiscNodePtr;
          HeadFchSmmMiscNodePtr = NewFchSmmMiscNodePtr;
          Status = EFI_SUCCESS;
          return  Status;
        }
        NewFchSmmMiscNodePtr->FchMiscNodePtr = PreviousFchSmmMiscNodePtr->FchMiscNodePtr;
        PreviousFchSmmMiscNodePtr->FchMiscNodePtr = NewFchSmmMiscNodePtr;

        Status = EFI_SUCCESS;
        return  Status;
      }
      PreviousFchSmmMiscNodePtr = CurrentFchSmmMiscNodePtr;
      CurrentFchSmmMiscNodePtr = CurrentFchSmmMiscNodePtr->FchMiscNodePtr;
    }
    PreviousFchSmmMiscNodePtr->FchMiscNodePtr = NewFchSmmMiscNodePtr;
    NewFchSmmMiscNodePtr->FchMiscNodePtr = CurrentFchSmmMiscNodePtr;
  }
  Status = EFI_SUCCESS;
  return  Status;
}


/*----------------------------------------------------------------------------------------*/
/**
 * Unregister MISC child handler
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
FchSmmMiscDispatchUnRegister (
  IN       CONST FCH_SMM_MISC_DISPATCH_PROTOCOL   *This,
  IN       EFI_HANDLE                             DispatchHandle
  )
{
  EFI_STATUS        Status;
  FCH_SMM_MISC_NODE *CurrentFchSmmMiscNodePtr;
  FCH_SMM_MISC_NODE *PreviousFchSmmMiscNodePtr;

  if (DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  if (HeadFchSmmMiscNodePtr->FchMiscNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
    return  Status;
  } else {
    PreviousFchSmmMiscNodePtr = HeadFchSmmMiscNodePtr;
    CurrentFchSmmMiscNodePtr = HeadFchSmmMiscNodePtr;
    if (CurrentFchSmmMiscNodePtr->DispatchHandle == DispatchHandle) {
      HeadFchSmmMiscNodePtr = CurrentFchSmmMiscNodePtr->FchMiscNodePtr;
    } else {
      while (CurrentFchSmmMiscNodePtr->DispatchHandle != DispatchHandle) {
        PreviousFchSmmMiscNodePtr = CurrentFchSmmMiscNodePtr;
        CurrentFchSmmMiscNodePtr = CurrentFchSmmMiscNodePtr->FchMiscNodePtr;
        if (CurrentFchSmmMiscNodePtr->DispatchHandle == NULL) {
          Status = EFI_NOT_FOUND;
          return  Status;
        }
      }
      PreviousFchSmmMiscNodePtr->FchMiscNodePtr = CurrentFchSmmMiscNodePtr->FchMiscNodePtr;
    }
    Status = gSmst->SmmFreePool (
                       CurrentFchSmmMiscNodePtr
                       );
    ASSERT_EFI_ERROR (Status);
  }
  Status = EFI_SUCCESS;
  return  Status;
}


EFI_STATUS
EFIAPI
FchSmmMiscSmiEnable (
  IN OUT   FCH_SMM_MISC_REGISTER_CONTEXT          *MiscRegisterContext
  )
{
  UINT32    SmiEvent;
  UINT32    SmiStatusBit;
  UINT32    SmiControlReg;
  UINT32    SmiControlBit;

  SmiEvent = 0;
  SmiStatusBit = MiscRegisterContext->SmiStatusBit;
  while ((SmiStatusBit & BIT0) == 0) {
    SmiEvent++;
    SmiStatusBit = SmiStatusBit >> 1;
  }
  SmiEvent += (MiscRegisterContext->SmiStatusReg - FCH_SMI_REG80) * 8;

  SmiControlReg = FCH_SMI_REGA0 + (SmiEvent * 2 / 32) * 4;
  SmiControlBit = 1 << ((SmiEvent *2 ) % 32);

  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + MiscRegisterContext->SmiStatusReg) =  MiscRegisterContext->SmiStatusBit;

  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + SmiControlReg) &= ~(UINT32) (SmiControlBit + SmiControlBit * 2);
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + SmiControlReg) |= SmiControlBit;
  return EFI_SUCCESS;
}


