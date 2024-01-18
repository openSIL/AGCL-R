/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD Hudson-2 USB Dispatcher Driver
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  UEFI
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */

#include "FchSmmUsbDispatcher.h"
#include "Filecode.h"
#include <Library/DevicePathLib.h>
#include <Library/BaseMemoryLib.h>
#include "GnbDxio.h"
#define FILECODE UEFI_SMM_FCHSMMDISPATCHER_FCHSMMUSBDISPATCHER_FCHSMMUSBDISPATCHER_FILECODE

extern FCH_USB_SMI_SYSINFO  Fch9004UsbSmiSysInfo;

EFI_STATUS
EFIAPI
FchSmmUsbDispatch2Register (
  IN       CONST FCH_SMM_USB_DISPATCH2_PROTOCOL  *This,
  IN       FCH_SMM_USB_HANDLER_ENTRY_POINT2      CallBackFunction,
  IN       CONST FCH_SMM_USB_REGISTER_CONTEXT    *RegisterContext,
     OUT   EFI_HANDLE                            *DispatchHandle
  );

EFI_STATUS
EFIAPI
FchSmmUsbDispatch2UnRegister (
  IN       CONST FCH_SMM_USB_DISPATCH2_PROTOCOL  *This,
  IN       EFI_HANDLE                            DispatchHandle
  );

VOID
Fch9004SmmUsbSmiEnable (
  VOID
  );

VOID
Fch9004SmmUsbClearSmiSts (
  VOID
  );

BOOLEAN
FchSmmUsbSmuUsbConfigUpdate (
  IN  UINT32    DieBusNum,
  IN  UINT32    smn_register,
  IN  UINT32    smn_mask,
  IN  UINT32    smn_data,
  IN  UINT32    smn_group
  );

FCH_SMM_USB_DISPATCH2_PROTOCOL gFchSmmUsbDispatch2Protocol = {
  FchSmmUsbDispatch2Register,
  FchSmmUsbDispatch2UnRegister
};

/*----------------------------------------------------------------------------------------*/
/**
 * FCH SMM USB dispatcher handler
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
FchSmmUsbDispatchHandler (
  IN       EFI_HANDLE   SmmImageHandle,
  IN OUT   VOID         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN        *SourceSize OPTIONAL
  )
{
  EFI_STATUS       Status;
  FCH_SMM_USB_NODE *CurrentFchSmmUsbNodePtr;

  Status = EFI_NOT_FOUND;

  if (HeadFchSmmUsbNodePtr->FchUsbNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
  } else {
    CurrentFchSmmUsbNodePtr = HeadFchSmmUsbNodePtr;
    while (CurrentFchSmmUsbNodePtr->FchUsbNodePtr!= NULL) {
      if (CurrentFchSmmUsbNodePtr->CallBack2Function != NULL) {
        Status = CurrentFchSmmUsbNodePtr->CallBack2Function (
                                            CurrentFchSmmUsbNodePtr->DispatchHandle,
                                            &CurrentFchSmmUsbNodePtr->Context,
                                            NULL,
                                            NULL
                                            );
        DEBUG ((DEBUG_VERBOSE, "[FchSmmDispatcher] USB SMM handler dispatched: Order = 0x%x, \
               return - %r\n", CurrentFchSmmUsbNodePtr->Context.Order, Status));
      }
      CurrentFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr->FchUsbNodePtr;
    }
  }
  Fch9004SmmUsbClearSmiSts ();
  return  Status;
}

/*----------------------------------------------------------------------------------------*/
/**
 * Register USB child handler
 *
 *
 * @param[in]       This                  Pointer to protocol
 * @param[in]       CallBackFunction
 * @param[in, out]   RegisterContext            Register contecxt (see PI 1.1 for more details)
 * @param[out]      DispatchHandle        Handle (see PI 1.1 for more details)
 *
 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmUsbDispatchHandler2 (
  IN       EFI_HANDLE   SmmImageHandle,
  IN OUT   VOID         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN        *SourceSize OPTIONAL
  )
{
  EFI_STATUS       Status;
  FCH_SMM_USB_NODE *CurrentFchSmmUsbNodePtr;
  Status = EFI_NOT_FOUND;
  if (HeadFchSmmUsbNodePtr->FchUsbNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
  } else {
    CurrentFchSmmUsbNodePtr = HeadFchSmmUsbNodePtr;
    while (CurrentFchSmmUsbNodePtr->FchUsbNodePtr!= NULL) {
      if (CurrentFchSmmUsbNodePtr->CallBack2Function != NULL) {
        Status = CurrentFchSmmUsbNodePtr->CallBack2Function (
                                            CurrentFchSmmUsbNodePtr->DispatchHandle,
                                            &CurrentFchSmmUsbNodePtr->Context,
                                            NULL,
                                            NULL
                                            );
        DEBUG ((DEBUG_VERBOSE, "[FchSmmDispatcher] USB SMM handler dispatched: Order = 0x%x, \
               return - %r\n", CurrentFchSmmUsbNodePtr->Context.Order, Status));
      }
      CurrentFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr->FchUsbNodePtr;
    }
  }
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG88) = BIT12;
  return  Status;
}
EFI_STATUS
EFIAPI
FchSmmUsbDispatch2Register (
  IN       CONST FCH_SMM_USB_DISPATCH2_PROTOCOL  *This,
  IN       FCH_SMM_USB_HANDLER_ENTRY_POINT2      CallBackFunction,
  IN       CONST FCH_SMM_USB_REGISTER_CONTEXT    *RegisterContext,
     OUT   EFI_HANDLE                            *DispatchHandle
  )
{
  EFI_STATUS       Status;
  FCH_SMM_USB_NODE *NewFchSmmUsbNodePtr;
  FCH_SMM_USB_NODE *CurrentFchSmmUsbNodePtr;
  FCH_SMM_USB_NODE *PreviousFchSmmUsbNodePtr;
  Status = EFI_OUT_OF_RESOURCES;

  if (CallBackFunction == NULL || RegisterContext == NULL || DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_USB_NODE),
                    (VOID **)&NewFchSmmUsbNodePtr
                    );
  ASSERT_EFI_ERROR (Status);

  NewFchSmmUsbNodePtr->CallBack2Function = CallBackFunction;
  NewFchSmmUsbNodePtr->Context = *RegisterContext;
  *DispatchHandle = &NewFchSmmUsbNodePtr->DispatchHandle;
  NewFchSmmUsbNodePtr->DispatchHandle = *DispatchHandle;

  DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Registering USB SMM handler: Type = 0x%x, Order = 0x%x\n", \
         RegisterContext->Type, RegisterContext->Order));
  if (HeadFchSmmUsbNodePtr->FchUsbNodePtr == NULL) {
    NewFchSmmUsbNodePtr->FchUsbNodePtr = HeadFchSmmUsbNodePtr;
    HeadFchSmmUsbNodePtr = NewFchSmmUsbNodePtr;
  } else {
    PreviousFchSmmUsbNodePtr = HeadFchSmmUsbNodePtr;
    CurrentFchSmmUsbNodePtr = HeadFchSmmUsbNodePtr;
    while (CurrentFchSmmUsbNodePtr->FchUsbNodePtr != NULL) {
      if (NewFchSmmUsbNodePtr->Context.Order <= CurrentFchSmmUsbNodePtr->Context.Order &&
          CurrentFchSmmUsbNodePtr->Context.Type == NewFchSmmUsbNodePtr->Context.Type &&
          (CurrentFchSmmUsbNodePtr->Context.Device != NULL && NewFchSmmUsbNodePtr->Context.Device != NULL &&
          CompareMem (CurrentFchSmmUsbNodePtr->Context.Device, NewFchSmmUsbNodePtr->Context.Device, GetDevicePathSize (NewFchSmmUsbNodePtr->Context.Device)) == 0)) {

        if (PreviousFchSmmUsbNodePtr == CurrentFchSmmUsbNodePtr) {
          NewFchSmmUsbNodePtr->FchUsbNodePtr = HeadFchSmmUsbNodePtr;
          HeadFchSmmUsbNodePtr = NewFchSmmUsbNodePtr;
          Status = EFI_SUCCESS;
          return Status;
        }
        NewFchSmmUsbNodePtr->FchUsbNodePtr = PreviousFchSmmUsbNodePtr->FchUsbNodePtr;
        PreviousFchSmmUsbNodePtr->FchUsbNodePtr = NewFchSmmUsbNodePtr;

        Status = EFI_SUCCESS;
        return  Status;
      }
      PreviousFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr;
      CurrentFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr->FchUsbNodePtr;
    }
    PreviousFchSmmUsbNodePtr->FchUsbNodePtr = NewFchSmmUsbNodePtr;
    NewFchSmmUsbNodePtr->FchUsbNodePtr = CurrentFchSmmUsbNodePtr;
  }

  Fch9004SmmUsbSmiEnable ();

  Status = EFI_SUCCESS;
  return  Status;
}


/*----------------------------------------------------------------------------------------*/
/**
 * Unregister USB child handler
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
FchSmmUsbDispatch2UnRegister (
  IN       CONST FCH_SMM_USB_DISPATCH2_PROTOCOL  *This,
  IN       EFI_HANDLE                            DispatchHandle
  )
{
  EFI_STATUS       Status;
  FCH_SMM_USB_NODE *CurrentFchSmmUsbNodePtr;
  FCH_SMM_USB_NODE *PreviousFchSmmUsbNodePtr;

  if (DispatchHandle == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  if (HeadFchSmmUsbNodePtr->FchUsbNodePtr == NULL) {
    Status = EFI_NOT_FOUND;
    return  Status;
  } else {
    PreviousFchSmmUsbNodePtr = HeadFchSmmUsbNodePtr;
    CurrentFchSmmUsbNodePtr = HeadFchSmmUsbNodePtr;
    if (CurrentFchSmmUsbNodePtr->DispatchHandle == DispatchHandle) {
      HeadFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr->FchUsbNodePtr;
    } else {
      while (CurrentFchSmmUsbNodePtr->DispatchHandle != DispatchHandle) {
        PreviousFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr;
        CurrentFchSmmUsbNodePtr = CurrentFchSmmUsbNodePtr->FchUsbNodePtr;
        if (CurrentFchSmmUsbNodePtr->DispatchHandle == NULL) {
          Status = EFI_NOT_FOUND;
          return  Status;
        }
      }
      PreviousFchSmmUsbNodePtr->FchUsbNodePtr = CurrentFchSmmUsbNodePtr->FchUsbNodePtr;
    }

    Status = gSmst->SmmFreePool (
                      CurrentFchSmmUsbNodePtr
                      );
    ASSERT_EFI_ERROR (Status);
  }
  Status = EFI_SUCCESS;
  return  Status;
}

VOID
Fch9004SmmUsbClearSmiSts (
  VOID
  )
{
  UINT32              Bus;
  UINT8               Nbio;

  Bus  = 0;
  Nbio = 0;
  //
  // 1, Clear SMI event status bit in FCH
  //
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG84) = UsbSmi;

  //
  // 2, Clear NBIO/IOHC status
  //
  if (Fch9004UsbSmiSysInfo.Socket0NbioSmiEn != 0) {                   //Socket0
    Bus = 0;
    for (Nbio = 0; Nbio < 4; Nbio++) {
      if (Fch9004UsbSmiSysInfo.Socket0NbioSmiEn & (1 << Nbio)) {
        FchSmnRW ((UINT32)Bus, 0x13B10120 + Nbio * 0x100000, 0xfffffffe, BIT0, NULL);
        FchSmnRW ((UINT32)Bus, 0x13B20020 + Nbio * 0x100000, 0xfffffeff, BIT8, NULL);
      }
    }
  }

  if (Fch9004UsbSmiSysInfo.Socket1NbioSmiEn != 0) {                   //Socket1
    Bus = Fch9004UsbSmiSysInfo.Socket1Bus;
    for (Nbio = 0; Nbio < 4; Nbio++) {
      if (Fch9004UsbSmiSysInfo.Socket1NbioSmiEn & (1 << Nbio)) {
        FchSmnRW ((UINT32)Bus, 0x13B10120 + Nbio * 0x100000, 0xfffffffe, BIT0, NULL);
        FchSmnRW ((UINT32)Bus, 0x13B20020 + Nbio * 0x100000, 0xfffffeff, BIT8, NULL);
      }
    }
  }

  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG84) = UsbSmi; //PLAT-11747
}

VOID
Fch9004SmmUsbSmiEnable (
  VOID
  )
{
  UINT32  Bus;

  Bus = 0;

  //
  // Only need to do once if USB SMI has not been enabled.
  //
  if ((ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REGAC) & (BIT10 + BIT11)) == BIT10) {
    return;
  }

  //
  // Enable SMI on NBIO/IOHC side
  //
  if (Fch9004UsbSmiSysInfo.Socket0NbioSmiEn != 0) {                   //Socket0
    Bus = 0;
    //XHCI0
    if (Fch9004UsbSmiSysInfo.Socket0NbioSmiEn & BIT3) {
      FchSmnRW ((UINT32)Bus, 0x13B20020 + 3 * 0x100000, 0xfffffeff, BIT8, NULL);   //HWSMI_STS
      FchSmnRW ((UINT32)Bus, 0x13B201D0 + 3 * 0x100000, 0xffffbfff, BIT14, NULL);  //PCIE_SMI_EN
      FchSmnRW ((UINT32)Bus, 0x13B10120 + 3 * 0x100000, 0xfffffffe, BIT0, NULL);   //SMI_EOI
      FchSmmUsbSmuUsbConfigUpdate (0, FCH_SN_USB_INTERRUPT_CONTROL, 0xfffff000, 0x100, 0x01000001);
    }
    //XHCI1
    if (Fch9004UsbSmiSysInfo.Socket0NbioSmiEn & BIT2) {
      FchSmnRW ((UINT32)Bus, 0x13B20020 + 2 * 0x100000, 0xfffffeff, BIT8, NULL);   //HWSMI_STS
      FchSmnRW ((UINT32)Bus, 0x13B201D0 + 2 * 0x100000, 0xffffbfff, BIT14, NULL);  //PCIE_SMI_EN
      FchSmnRW ((UINT32)Bus, 0x13B10120 + 2 * 0x100000, 0xfffffffe, BIT0, NULL);   //SMI_EOI
      FchSmmUsbSmuUsbConfigUpdate (0, FCH_SN_USB_INTERRUPT_CONTROL, 0xfffff000, 0x100, 0x01100001);
    }
  }

  if (Fch9004UsbSmiSysInfo.Socket1NbioSmiEn != 0) {                   //Socket1
    Bus = Fch9004UsbSmiSysInfo.Socket1Bus;
    //XHCI2
    if (Fch9004UsbSmiSysInfo.Socket1NbioSmiEn & BIT3) {
      FchSmnRW ((UINT32)Bus, 0x13B20020 + 3 * 0x100000, 0xfffffeff, BIT8, NULL);   //HWSMI_STS
      FchSmnRW ((UINT32)Bus, 0x13B201D0 + 3 * 0x100000, 0xffffbfff, BIT14, NULL);  //PCIE_SMI_EN
      FchSmnRW ((UINT32)Bus, 0x13B10120 + 3 * 0x100000, 0xfffffffe, BIT0, NULL);   //SMI_EOI
      FchSmmUsbSmuUsbConfigUpdate (1, FCH_SN_USB_INTERRUPT_CONTROL, 0xfffff000, 0x100, 0x01000001);
    }
    //XHCI3
    if (Fch9004UsbSmiSysInfo.Socket1NbioSmiEn & BIT2) {
      FchSmnRW ((UINT32)Bus, 0x13B20020 + 2 * 0x100000, 0xfffffeff, BIT8, NULL);   //HWSMI_STS
      FchSmnRW ((UINT32)Bus, 0x13B201D0 + 2 * 0x100000, 0xffffbfff, BIT14, NULL);  //PCIE_SMI_EN
      FchSmnRW ((UINT32)Bus, 0x13B10120 + 2 * 0x100000, 0xfffffffe, BIT0, NULL);   //SMI_EOI
      FchSmmUsbSmuUsbConfigUpdate (1, FCH_SN_USB_INTERRUPT_CONTROL, 0xfffff000, 0x100, 0x01100001);
    }
  }

  //
  // Enable APU HW SMI control in FCH
  //
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG84) = UsbSmi;
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REGAC) |= BIT10;
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG84) = UsbSmi;

  // USB Legacy KBC Emulation
  ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REGB0) |= BIT24;
  ACPIMMIO32 (ACPI_MMIO_BASE + PMIO_BASE + FCH_PMIOA_REGED) |= (BIT4);
}

EFI_STATUS
EFIAPI
EfiSmmUsbDispatch2Register (
  IN       CONST EFI_SMM_USB_DISPATCH2_PROTOCOL *This,
  IN       EFI_SMM_HANDLER_ENTRY_POINT2         DispatchFunction,
  IN       CONST EFI_SMM_USB_REGISTER_CONTEXT   *RegisterContext,
     OUT   EFI_HANDLE                           *DispatchHandle
  )
{
  FCH_SMM_USB_REGISTER_CONTEXT     FchRegisterContext;

  FchRegisterContext.Type   = RegisterContext->Type;
  FchRegisterContext.Device = RegisterContext->Device;
  FchRegisterContext.Order  = 0x80;      // SMM_DEFAULT_ORDER
  return FchSmmUsbDispatch2Register (
           &gFchSmmUsbDispatch2Protocol,
           (FCH_SMM_USB_HANDLER_ENTRY_POINT2)DispatchFunction,
           &FchRegisterContext,
           DispatchHandle
           );
}

EFI_STATUS
EFIAPI
EfiSmmUsbDispatch2UnRegister (
  IN       CONST EFI_SMM_USB_DISPATCH2_PROTOCOL *This,
  IN       EFI_HANDLE                           DispatchHandle
  )
{
  return FchSmmUsbDispatch2UnRegister (
           &gFchSmmUsbDispatch2Protocol,
           DispatchHandle
           );
}

EFI_SMM_USB_DISPATCH2_PROTOCOL gEfiSmmUsbDispatch2Protocol = {
  EfiSmmUsbDispatch2Register,
  EfiSmmUsbDispatch2UnRegister
};


/**
 * FchSmmUsbSmuUsbConfigUpdate  -  Xhci Smu Usb Config Update
 *
 *
 *
 */
BOOLEAN
FchSmmUsbSmuUsbConfigUpdate (
  IN  UINT32    DieBusNum,
  IN  UINT32    smn_register,
  IN  UINT32    smn_mask,
  IN  UINT32    smn_data,
  IN  UINT32    smn_group
  )
{
  BOOLEAN status;
  PCI_ADDR        NbioPciAddress;
  UINT32          SmuArg[6];
  status = FALSE;
  NbioSmuServiceCommonInitArguments (SmuArg);
  SmuArg[0] = smn_register;
  SmuArg[1] = smn_mask;
  SmuArg[2] = smn_data;
  SmuArg[3] = smn_group;
  NbioPciAddress.AddressValue = MAKE_SBDFO (DF_GET_SEGMENT(DieBusNum), DF_GET_BUS(DieBusNum), 0, 0, 0);
  if (NbioSmuServiceRequest (NbioPciAddress, BIOSSMC_MSG_UsbConfigUpdate, SmuArg,0)) {
    status = TRUE;
  }

  return status;
}

