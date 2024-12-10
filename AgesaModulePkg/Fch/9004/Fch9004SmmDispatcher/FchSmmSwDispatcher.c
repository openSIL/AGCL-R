/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD Child SMI Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 311751 $   @e \$Date: 2015-01-26 13:34:23 -0800 (Mon, 26 Jan 2015) $
 *
 */

#include "FchSmmSwDispatcher.h"

extern UINT16 mSwSmiCmdAddress;

FCH_SMM_SW_NODE              *HeadFchSmmSwNodePtr;

EFI_STATUS
EFIAPI
FchSmmSwDispatch2Register (
  IN       CONST FCH_SMM_SW_DISPATCH2_PROTOCOL  *This,
  IN       FCH_SMM_SW_HANDLER_ENTRY_POINT2      DispatchFunction,
  IN       CONST FCH_SMM_SW_REGISTER_CONTEXT    *RegisterContext,
     OUT   EFI_HANDLE                           *DispatchHandle
  );

EFI_STATUS
EFIAPI
FchSmmSwDispatch2UnRegister (
  IN       CONST FCH_SMM_SW_DISPATCH2_PROTOCOL  *This,
  IN       EFI_HANDLE                           DispatchHandle
  );

FCH_SMM_SW_DISPATCH2_PROTOCOL gFchSmmSwDispatch2Protocol = {
  FchSmmSwDispatch2Register,
  FchSmmSwDispatch2UnRegister,
  (UINTN) MAX_SW_SMI_VALUE
};

BOOLEAN
STATIC
IsSwSmiValueUsed (
  IN UINTN Value
  );

/*----------------------------------------------------------------------------------------*/
/**
 * FCH SMM SW dispatcher handler
 *
 *
 * @param[in]       SmmImageHandle        Image Handle
 * @param[in, out]   OPTIONAL CommunicationBuffer   Communication Buffer (see PI 1.2 for more details)
 * @param[in, out]   OPTIONAL SourceSize            Buffer size (see PI 1.2 for more details)

 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmSwDispatchHandler (
  IN       EFI_HANDLE   SmmImageHandle,
  IN OUT   VOID         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN        *SourceSize OPTIONAL
  )
{
  EFI_STATUS                  Status;
  FCH_SMM_SW_NODE             *CurrentFchSmmSwNodePtr;
  UINT16                      SwSmiValue;
  UINT16                      SwSmiCmdAddress;  // acpismicmd is 16bit register
  UINT16                      SwSmiDispatched;
  UINTN                       SizeOfFchSmmSwContext;
  UINTN                       i;
  EFI_SMM_SAVE_STATE_IO_INFO  IoInfo;

  Status = EFI_NOT_FOUND;
  SwSmiDispatched = 0;

  SwSmiCmdAddress = MmioRead16 (ACPI_MMIO_BASE + PMIO_BASE + FCH_PMIOA_REG6A);
  SwSmiValue      = IoRead16 (SwSmiCmdAddress);

  ASSERT (mSmmCpuProtocol != NULL);
  i = gSmst->NumberOfCpus;
  do {
    EfiSmmSwContext->SwSmiCpuIndex = i - 1;
    Status = mSmmCpuProtocol->ReadSaveState (
                                mSmmCpuProtocol,
                                sizeof (EFI_SMM_SAVE_STATE_IO_INFO),
                                EFI_SMM_SAVE_STATE_REGISTER_IO,
                                EfiSmmSwContext->SwSmiCpuIndex,
                                &IoInfo
                                );
    if ((Status == EFI_SUCCESS) && (IoInfo.IoPort == SwSmiCmdAddress) && ((UINT8) IoInfo.IoData == (UINT8) SwSmiValue)) {
      break;
    }
  } while (--i);
  EfiSmmSwContext->CommandPort = (UINT8) SwSmiValue;
  EfiSmmSwContext->DataPort = (UINT8) (SwSmiValue >> 8);

  if (HeadFchSmmSwNodePtr->FchSwNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
  } else {
    CurrentFchSmmSwNodePtr = HeadFchSmmSwNodePtr;
    while (CurrentFchSmmSwNodePtr->FchSwNodePtr!= NULL) {
      if ((UINT8) CurrentFchSmmSwNodePtr->Context.AmdSwValue == (UINT8) SwSmiValue) {
        if (CurrentFchSmmSwNodePtr->CallBack2Function != NULL) {
          SizeOfFchSmmSwContext = (UINTN) sizeof (FCH_SMM_SW_CONTEXT);
          Status = CurrentFchSmmSwNodePtr->CallBack2Function (
                                          CurrentFchSmmSwNodePtr->DispatchHandle,
                                          &CurrentFchSmmSwNodePtr->Context,
                                          EfiSmmSwContext,
                                          &SizeOfFchSmmSwContext
                                          );
          DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] SW SMM handler dispatched: SwValue = 0x%x, Order = 0x%x, return - %r\n", \
                 CurrentFchSmmSwNodePtr->Context.AmdSwValue, CurrentFchSmmSwNodePtr->Context.Order, Status));
        }

        SwSmiDispatched++;
      }
      CurrentFchSmmSwNodePtr = CurrentFchSmmSwNodePtr->FchSwNodePtr;
    }
    if (SwSmiDispatched <= 0) {
      Status = EFI_NOT_FOUND;
    } else {
      ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG88) = SmiCmdPort;
      Status = EFI_SUCCESS;
    }
  }
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG88) = SmiCmdPort;
  return  Status;
}

/*----------------------------------------------------------------------------------------*/
/**
 * Register SW child handler
 *
 *
 * @param[in]       This                  Pointer to protocol
 * @param[in]       DispatchFunction      Callback Function
 * @param[in, out]  RegisterContext       Register contecxt (see PI 1.1 for more details)
 * @param[out]      DispatchHandle        Handle (see PI 1.1 for more details)
 *
 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmSwDispatch2Register (
  IN       CONST FCH_SMM_SW_DISPATCH2_PROTOCOL *This,
  IN       FCH_SMM_SW_HANDLER_ENTRY_POINT2     DispatchFunction,
  IN       CONST FCH_SMM_SW_REGISTER_CONTEXT   *RegisterContext,
     OUT   EFI_HANDLE                          *DispatchHandle
  )
{
  EFI_STATUS      Status;
  FCH_SMM_SW_NODE *NewFchSmmSwNodePtr;
  FCH_SMM_SW_NODE *CurrentFchSmmSwNodePtr;
  FCH_SMM_SW_NODE *PreviousFchSmmSwNodePtr;

  Status = EFI_OUT_OF_RESOURCES;

  if (DispatchFunction == NULL || RegisterContext == NULL || DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REGB0) |= BIT22;
  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_SW_NODE),
                    (VOID **)&NewFchSmmSwNodePtr
                    );
  ASSERT_EFI_ERROR (Status);

  NewFchSmmSwNodePtr->CallBack2Function = DispatchFunction;
  NewFchSmmSwNodePtr->Context = *RegisterContext;
  *DispatchHandle = &NewFchSmmSwNodePtr->DispatchHandle;
  NewFchSmmSwNodePtr->DispatchHandle = *DispatchHandle;

  DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Registering SW SMM handler: SwValue = 0x%x, Order = 0x%x\n", RegisterContext->AmdSwValue, RegisterContext->Order));
  if (HeadFchSmmSwNodePtr->FchSwNodePtr == NULL) {
    NewFchSmmSwNodePtr->FchSwNodePtr = HeadFchSmmSwNodePtr;
    HeadFchSmmSwNodePtr = NewFchSmmSwNodePtr;
  } else {
    PreviousFchSmmSwNodePtr = HeadFchSmmSwNodePtr;
    CurrentFchSmmSwNodePtr = HeadFchSmmSwNodePtr;
    while (CurrentFchSmmSwNodePtr->FchSwNodePtr != NULL) {
      if (NewFchSmmSwNodePtr->Context.Order <= CurrentFchSmmSwNodePtr->Context.Order &&
          CurrentFchSmmSwNodePtr->Context.AmdSwValue == NewFchSmmSwNodePtr->Context.AmdSwValue) {

        if (PreviousFchSmmSwNodePtr == CurrentFchSmmSwNodePtr) {
          NewFchSmmSwNodePtr->FchSwNodePtr = HeadFchSmmSwNodePtr;
          HeadFchSmmSwNodePtr = NewFchSmmSwNodePtr;
          Status = EFI_SUCCESS;
          return Status;
        }
        NewFchSmmSwNodePtr->FchSwNodePtr = PreviousFchSmmSwNodePtr->FchSwNodePtr;
        PreviousFchSmmSwNodePtr->FchSwNodePtr = NewFchSmmSwNodePtr;

        Status = EFI_SUCCESS;
        return  Status;
      }
      PreviousFchSmmSwNodePtr = CurrentFchSmmSwNodePtr;
      CurrentFchSmmSwNodePtr = CurrentFchSmmSwNodePtr->FchSwNodePtr;
    }
    PreviousFchSmmSwNodePtr->FchSwNodePtr = NewFchSmmSwNodePtr;
    NewFchSmmSwNodePtr->FchSwNodePtr = CurrentFchSmmSwNodePtr;
  }
  Status = EFI_SUCCESS;
  return  Status;
}


/*----------------------------------------------------------------------------------------*/
/**
 * Unregister SW child handler
 *
 *
 * @param[in]       This                  Pointer to protocol
 * @param[in]       DispatchHandle        Dispatch Handle
 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmSwDispatch2UnRegister (
  IN       CONST FCH_SMM_SW_DISPATCH2_PROTOCOL *This,
  IN       EFI_HANDLE                          DispatchHandle
  )
{
  EFI_STATUS      Status;
  FCH_SMM_SW_NODE *CurrentFchSmmSwNodePtr;
  FCH_SMM_SW_NODE *PreviousFchSmmSwNodePtr;

  if (DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  if (HeadFchSmmSwNodePtr->FchSwNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
    return  Status;
  } else {
    PreviousFchSmmSwNodePtr = HeadFchSmmSwNodePtr;
    CurrentFchSmmSwNodePtr = HeadFchSmmSwNodePtr;
    if (CurrentFchSmmSwNodePtr->DispatchHandle == DispatchHandle) {
      HeadFchSmmSwNodePtr = CurrentFchSmmSwNodePtr->FchSwNodePtr;
    } else {
      while (CurrentFchSmmSwNodePtr->DispatchHandle != DispatchHandle) {
        PreviousFchSmmSwNodePtr = CurrentFchSmmSwNodePtr;
        CurrentFchSmmSwNodePtr = CurrentFchSmmSwNodePtr->FchSwNodePtr;
        if (CurrentFchSmmSwNodePtr->DispatchHandle == NULL) {
          Status = EFI_NOT_FOUND;
          return  Status;
        }
      }
      PreviousFchSmmSwNodePtr->FchSwNodePtr = CurrentFchSmmSwNodePtr->FchSwNodePtr;
    }

    Status = gSmst->SmmFreePool (
                      CurrentFchSmmSwNodePtr
                      );
    ASSERT_EFI_ERROR (Status);
  }
  Status = EFI_SUCCESS;
  return  Status;
}

BOOLEAN
STATIC
IsSwSmiValueUsed (
  IN UINTN Value
  )
{
  BOOLEAN           Result;
  FCH_SMM_SW_NODE   *CurrentFchSmmSwNodePtr;

  Result = FALSE;
  CurrentFchSmmSwNodePtr = HeadFchSmmSwNodePtr;
  while ((CurrentFchSmmSwNodePtr->FchSwNodePtr != NULL) && !Result) {
    Result = (CurrentFchSmmSwNodePtr->Context.AmdSwValue == Value);
    CurrentFchSmmSwNodePtr = CurrentFchSmmSwNodePtr->FchSwNodePtr;
  }
  return Result;
}

EFI_STATUS
EFIAPI
EfiSmmSwDispatch2Register (
  IN       CONST EFI_SMM_SW_DISPATCH2_PROTOCOL   *This,
  IN       EFI_SMM_HANDLER_ENTRY_POINT2          DispatchFunction,
  IN OUT   EFI_SMM_SW_REGISTER_CONTEXT           *RegisterContext,
     OUT   EFI_HANDLE                            *DispatchHandle
  )
{
  FCH_SMM_SW_REGISTER_CONTEXT    FchRegisterContext;
  UINTN                          Index;

  FchRegisterContext.Order = 0x80;               // SMM_DEFAULT_ORDER
  if (RegisterContext->SwSmiInputValue == (UINTN) -1) {
    for (Index = 1u; Index < MAX_SW_SMI_VALUE; Index++) {
      if (!IsSwSmiValueUsed (Index)) {
        FchRegisterContext.AmdSwValue = Index;
        RegisterContext->SwSmiInputValue = Index;
        break;
      }
    }
    if (Index == MAX_SW_SMI_VALUE) {
      return EFI_OUT_OF_RESOURCES;
    }
  } else {
    FchRegisterContext.AmdSwValue = RegisterContext->SwSmiInputValue;
  }
  return FchSmmSwDispatch2Register (
           &gFchSmmSwDispatch2Protocol,
           (FCH_SMM_SW_HANDLER_ENTRY_POINT2)DispatchFunction,
           &FchRegisterContext,
           DispatchHandle
           );
}


EFI_STATUS
EFIAPI
EfiSmmSwDispatch2UnRegister (
  IN       CONST EFI_SMM_SW_DISPATCH2_PROTOCOL *This,
  IN       EFI_HANDLE                          DispatchHandle
  )
{
  return FchSmmSwDispatch2UnRegister (
           &gFchSmmSwDispatch2Protocol,
           DispatchHandle
           );
}

EFI_SMM_SW_DISPATCH2_PROTOCOL gEfiSmmSwDispatch2Protocol = {
  EfiSmmSwDispatch2Register,
  EfiSmmSwDispatch2UnRegister,
  (UINTN) MAX_SW_SMI_VALUE
};



