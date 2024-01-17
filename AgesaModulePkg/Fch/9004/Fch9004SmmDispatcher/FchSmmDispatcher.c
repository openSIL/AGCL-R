/******************************************************************************
*
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
**/

#include "FchSmmDispatcher.h"
#define FILECODE UEFI_SMM_FCHSMMDISPATCHER_FCHSMMDISPATCHER_FILECODE

#include "FchSmmSwDispatcher.h"

extern FCH_SMM_DISPATCHER_TABLE FchSmmDispatcherTable[];
extern UINT8 NumOfDispatcherTableEntry;
extern SAVE_B2B_IO B2bIoList[];
extern UINT8 NumOfB2bIoListEntry;
extern SAVE_PCI SavePciList[];
extern UINT8 NumOfSavePciListEntry;
extern FCH_USB_SMI_SYSINFO  Fch9004UsbSmiSysInfo;

UINT8  mEspiSmiOutB = 0;

FCH_SMM_SW_NODE              *HeadFchSmmSwNodePtr;
FCH_SMM_COMMUNICATION_BUFFER *CommunicationBufferPtr;

extern
UINT8
FchSmmGetSocket1Bus (
  VOID
  );


typedef struct {
  EFI_GUID  *Guid;
  VOID      *Interface;
} FCH_PROTOCOL_LIST;

FCH_PROTOCOL_LIST FchProtocolList[] = {
                    {&gFchSmmSwDispatch2ProtocolGuid,            &gFchSmmSwDispatch2Protocol},
                    {&gEfiSmmSwDispatch2ProtocolGuid,            &gEfiSmmSwDispatch2Protocol},
                    {&gFchSmmSxDispatch2ProtocolGuid,            &gFchSmmSxDispatch2Protocol},
                    {&gEfiSmmSxDispatch2ProtocolGuid,            &gEfiSmmSxDispatch2Protocol},
                    {&gFchSmmPwrBtnDispatch2ProtocolGuid,        &gFchSmmPwrBtnDispatch2Protocol},
                    {&gEfiSmmPowerButtonDispatch2ProtocolGuid,   &gEfiSmmPwrBtnDispatch2Protocol},
                    {&gFchSmmPeriodicalDispatch2ProtocolGuid,    &gFchSmmPeriodicalDispatch2Protocol},
                    {&gEfiSmmPeriodicTimerDispatch2ProtocolGuid, &gEfiSmmPeriodicalDispatch2Protocol},
                    {&gFchSmmUsbDispatch2ProtocolGuid,           &gFchSmmUsbDispatch2Protocol},
                    {&gEfiSmmUsbDispatch2ProtocolGuid,           &gEfiSmmUsbDispatch2Protocol},
                    {&gFchSmmGpiDispatch2ProtocolGuid,           &gFchSmmGpiDispatch2Protocol},
                    {&gEfiSmmGpiDispatch2ProtocolGuid,           &gEfiSmmGpiDispatch2Protocol},
                    {&gFchSmmIoTrapDispatch2ProtocolGuid,        &gFchSmmIoTrapDispatch2Protocol},
                    {&gEfiSmmIoTrapDispatch2ProtocolGuid,        &gEfiSmmIoTrapDispatch2Protocol},
                    {&gFchSmmMiscDispatchProtocolGuid,           &gFchSmmMiscDispatchProtocol},
                    };

FCH_PROTOCOL_LIST FchProtocolListRas[] = {
                    {&gFchSmmApuRasDispatchProtocolGuid,         &gFchSmmApuRasDispatchProtocol},
                    };

EFI_STATUS
EFIAPI
FchSmmDispatchHandler (
  IN       EFI_HANDLE                   SmmImageHandle,
  IN       CONST VOID                   *SmmEntryContext,
  IN OUT   VOID                         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN                        *SourceSize OPTIONAL
  );

VOID
FchSmmInitUsbSmiSysInfo (
  VOID
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
FchSmmDispatcherEntry (
  IN       EFI_HANDLE         ImageHandle,
  IN       EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS                    Status;
  EFI_HANDLE                    DispatchHandle;
  EFI_HANDLE                    FchSmmDispatcherHandle;
  UINTN                         i;

  AGESA_TESTPOINT (TpFchSmmDispatcherEntry, NULL);

  // Init Golbal data
  mEspiSmiOutB = PcdGet8 (PcdEspiSmiOutBVwEnable);

  Status = gSmst->SmmLocateProtocol (
                    &gEfiSmmCpuProtocolGuid,
                    NULL,
                    (VOID **)&mSmmCpuProtocol
                    );
  ASSERT_EFI_ERROR (Status);

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_SW_NODE),
                    (VOID **)&HeadFchSmmSwNodePtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmSwNodePtr, sizeof (FCH_SMM_SW_NODE));

  Status = gSmst->SmmAllocatePool (
                          EfiRuntimeServicesData,
                          sizeof (FCH_SMM_SX_NODE),
                          (VOID **)&HeadFchSmmSxNodePtr
                          );

  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmSxNodePtr, sizeof (FCH_SMM_SX_NODE));

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_PWRBTN_NODE),
                    (VOID **)&HeadFchSmmPwrBtnNodePtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmPwrBtnNodePtr, sizeof (FCH_SMM_PWRBTN_NODE));

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_PERIODICAL_NODE),
                    (VOID **)&HeadFchSmmPeriodicalNodePtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmPeriodicalNodePtr, sizeof (FCH_SMM_PERIODICAL_NODE));

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_GPI_NODE),
                    (VOID **)&HeadFchSmmGpiNodePtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmGpiNodePtr, sizeof (FCH_SMM_GPI_NODE));
  HeadFchSmmGpiNodePtr->Context.GpiNum = 0xffff;

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_USB_NODE),
                    (VOID **)&HeadFchSmmUsbNodePtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmUsbNodePtr, sizeof (FCH_SMM_USB_NODE));
  HeadFchSmmUsbNodePtr->Context.Order = 0xFF;

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_MISC_NODE),
                    (VOID **)&HeadFchSmmMiscNodePtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (HeadFchSmmMiscNodePtr, sizeof (FCH_SMM_MISC_NODE));

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_SW_CONTEXT),
                    (VOID **)&EfiSmmSwContext
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }
  ZeroMem (EfiSmmSwContext, sizeof (FCH_SMM_SW_CONTEXT));

  Status = gSmst->SmmAllocatePool (
                    EfiRuntimeServicesData,
                    sizeof (FCH_SMM_COMMUNICATION_BUFFER),
                    (VOID **)&CommunicationBufferPtr
                    );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  for (i = 0 ; i < sizeof (FchProtocolList) / sizeof (FCH_PROTOCOL_LIST); i++ ) {
    FchSmmDispatcherHandle =  NULL;
    Status = gSmst->SmmInstallProtocolInterface (
               &FchSmmDispatcherHandle,
               FchProtocolList[i].Guid,
               EFI_NATIVE_INTERFACE,
               FchProtocolList[i].Interface);
    if (EFI_ERROR (Status)) {
      return Status;
    }
  }

    ZeroMem (HeadFchSmmApuRasNodePtr, sizeof (FCH_SMM_APURAS_NODE));

    FchSmmDispatcherHandle =  NULL;
    Status = gSmst->SmmInstallProtocolInterface (
               &FchSmmDispatcherHandle,
               FchProtocolListRas[0].Guid,
               EFI_NATIVE_INTERFACE,
               FchProtocolListRas[0].Interface);
    if (EFI_ERROR (Status)) {
      return Status;
    }

    // Find handler for APU Hw Assertion bit
    for (i = 0; i < NumOfDispatcherTableEntry; i++ ) {
      if ((FchSmmDispatcherTable[i].StatusReg == FCH_SMI_REG84) && (FchSmmDispatcherTable[i].SmiStatusBit == ApuRasSmi)) {
        FchSmmDispatcherTable[i].SmiDispatcher = FchSmmApuRasDispatchHandler;
      }
    }
  }

  Status = gSmst->SmiHandlerRegister (
                    FchSmmDispatchHandler,
                    NULL,
                    &DispatchHandle
                    );

  if (EFI_ERROR (Status)) {
    return Status;
  }

  {
    UINT32  SmmDispatcherData32;
    UINT32  SmmDispatcherIndex;

  //
  // Clear all handled SMI status bit
  //
    for (SmmDispatcherIndex = 0; SmmDispatcherIndex < NumOfDispatcherTableEntry; SmmDispatcherIndex++ ) {
      SmmDispatcherData32 = ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FchSmmDispatcherTable[SmmDispatcherIndex].StatusReg);
      SmmDispatcherData32 &= FchSmmDispatcherTable[SmmDispatcherIndex].SmiStatusBit;
      ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FchSmmDispatcherTable[SmmDispatcherIndex].StatusReg) = SmmDispatcherData32;
    }
  //
  // Clear SmiEnB and Set EOS
  //
    SmmDispatcherData32 = ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG98);
    SmmDispatcherData32 &= ~(BIT31);
    SmmDispatcherData32 |= BIT28;
    ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG98) = SmmDispatcherData32;
  }

  FchSmmInitUsbSmiSysInfo ();

  AGESA_TESTPOINT (TpFchSmmDispatcherExit, NULL);
  return Status;
}

VOID
SaveB2BRegisters (
  VOID
  )
{
  EFI_SMM_CPU_IO2_PROTOCOL   *SmmCpuIo;
  UINT8                      i;
  UINT32                     PciAddress;

  SmmCpuIo = &gSmst->SmmIo;

  for (i = 0; i < NumOfB2bIoListEntry; i++) {
    SmmCpuIo->Io.Read (SmmCpuIo, B2bIoList[i].ioWidth, B2bIoList[i].ioPort, 1, &B2bIoList[i].ioValue);
  }
  for (i = 0; i < NumOfSavePciListEntry; i++) {
    PciAddress = 0x80000000;
    PciAddress |= ((SavePciList[i].Bus << 16) | (SavePciList[i].Dev << 11) | (SavePciList[i].Func << 8) | (SavePciList[i].Offset));
    SmmCpuIo->Io.Write (SmmCpuIo, SMM_IO_UINT32, CFG_ADDR_PORT, 1, &PciAddress);
    SmmCpuIo->Io.Read (SmmCpuIo, SavePciList[i].DataWidth, CFG_DATA_PORT, 1, &SavePciList[i].DataValue);
  }
}

VOID
RestoreB2BRegisters ( VOID )
{
  EFI_SMM_CPU_IO2_PROTOCOL   *SmmCpuIo;
  UINT8                      i;
  UINT32                     PciAddress;

  SmmCpuIo = &gSmst->SmmIo;

  for (i = 0; i < NumOfSavePciListEntry; i++) {
    PciAddress = 0x80000000;
    PciAddress |= ((SavePciList[i].Bus << 16) | (SavePciList[i].Dev << 11) | (SavePciList[i].Func << 8) | (SavePciList[i].Offset));
    SmmCpuIo->Io.Write (SmmCpuIo, SMM_IO_UINT32, CFG_ADDR_PORT, 1, &PciAddress);
    SmmCpuIo->Io.Write (SmmCpuIo, SavePciList[i].DataWidth, CFG_DATA_PORT, 1, &SavePciList[i].DataValue);
  }
  for (i = 0; i < NumOfB2bIoListEntry; i++) {
    SmmCpuIo->Io.Write (SmmCpuIo, B2bIoList[i].ioWidth, B2bIoList[i].ioPort, 1, &B2bIoList[i].ioValue);
  }
}

VOID
SendEspiSmiOutB_Assert ( VOID )
{
  if (mEspiSmiOutB & BIT0) {
    // eSPI0
    FchEspiSendSmiOutbVW (FCH_ESPI0_BASE_ADDRESS, 0x20);
    DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Sent SMIOUT Assertion VW on eSPI0!\n"));
  }

  if (mEspiSmiOutB & BIT1) {
    // eSPI1
    FchEspiSendSmiOutbVW (FCH_ESPI1_BASE_ADDRESS, 0x20);
    DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Sent SMIOUT Assertion VW on eSPI1!\n"));
  }
}

VOID
SendEspiSmiOutB_DeAssert ( VOID )
{
  if (mEspiSmiOutB & BIT0) {
    // eSPI0
    FchEspiSendSmiOutbVW (FCH_ESPI0_BASE_ADDRESS, 0x22);
    DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Sent SMIOUT De-Assertion VW on eSPI0!\n"));
  }

  if (mEspiSmiOutB & BIT1) {
    // eSPI1
    FchEspiSendSmiOutbVW (FCH_ESPI1_BASE_ADDRESS, 0x22);
    DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Sent SMIOUT De-Assertion VW on eSPI1!\n"));
  }
}

/*----------------------------------------------------------------------------------------*/
/**
 * FCH SMM dispatcher handler
 *
 *
 * @param[in]       SmmImageHandle        Image Handle
 * @param[in]       SmmEntryContext         (see PI 1.2 for more details)
 * @param[in, out]   OPTIONAL CommunicationBuffer   Communication Buffer (see PI 1.1 for more details)
 * @param[in, out]   OPTIONAL SourceSize            Buffer size (see PI 1.1 for more details)

 * @retval          EFI_SUCCESS           SMI handled by dispatcher
 * @retval          EFI_UNSUPPORTED       SMI not supported by dispcther
 */
/*----------------------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
FchSmmDispatchHandler (
  IN       EFI_HANDLE                   SmmImageHandle,
  IN       CONST VOID                   *SmmEntryContext,
  IN OUT   VOID                         *CommunicationBuffer OPTIONAL,
  IN OUT   UINTN                        *SourceSize OPTIONAL
  )
{
  UINT8        SmmDispatcherIndex;
  UINT32       SmiStatusData;
//  UINT32       SmiReg88StatusData;
  //UINT32       UsbSmiEnableRegister;
  //UINT32       UsbSmiEnableStatus;
  UINT32       EosStatus;
  EFI_STATUS   Status;

  if ( CommunicationBuffer != NULL
    && SourceSize != NULL
    && !SmmIsBufferOutsideSmmValid ((UINTN)CommunicationBuffer, (UINT64)(*SourceSize)) )
  {
    DEBUG ((EFI_D_ERROR, "[%a]SMM communication data buffer in SMRAM or overflow!\n", __FUNCTION__));
    return (EFI_INVALID_PARAMETER);
  }

  Status = EFI_WARN_INTERRUPT_SOURCE_PENDING; //Updated to be compliant with UDK2010.SR1.UP1
  SaveB2BRegisters ();
  SendEspiSmiOutB_Assert ();
  do {
    for (SmmDispatcherIndex = 0; SmmDispatcherIndex < NumOfDispatcherTableEntry; SmmDispatcherIndex++ ) {
      SmiStatusData = ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FchSmmDispatcherTable[SmmDispatcherIndex].StatusReg);
      if (( SmiStatusData &= FchSmmDispatcherTable[SmmDispatcherIndex].SmiStatusBit) != 0) {
        CommunicationBufferPtr->SmiStatusReg = FchSmmDispatcherTable[SmmDispatcherIndex].StatusReg;
        CommunicationBufferPtr->SmiStatusBit = SmiStatusData;
        CommunicationBuffer = (VOID *) CommunicationBufferPtr;
        Status = FchSmmDispatcherTable[SmmDispatcherIndex].SmiDispatcher (SmmImageHandle, CommunicationBuffer, SourceSize);
        if (Status != EFI_SUCCESS) {
          Status = EFI_WARN_INTERRUPT_SOURCE_PENDING;
        }
        SmmDispatcherIndex = 0;
      }
    }
    ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG98) |= Eos;
    EosStatus = ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG98) & Eos;
  //} while ((EosStatus != Eos) || (ACPIMMIO32 (ACPI_MMIO_BASE + SMI_BASE + FCH_SMI_REG84) & UsbSmi));
  } while ((EosStatus != Eos));
  SendEspiSmiOutB_DeAssert ();
  RestoreB2BRegisters ();
  return  Status;
}

//temp fix..
CONST VOID* IdsDebugPrint[] =
{
  NULL
};

VOID
FchSmmInitUsbSmiSysInfo (
  VOID
  )
{
  if (PcdGetBool (PcdXhci0Enable)) {
    //XHCI0 on NBIO3
    Fch9004UsbSmiSysInfo.Socket0NbioSmiEn |= BIT3;
  }
  if (PcdGetBool (PcdXhci1Enable)) {
    //XHCI1 on NBIO2
    Fch9004UsbSmiSysInfo.Socket0NbioSmiEn |= BIT2;
  }
  if (PcdGetBool (PcdXhci2Enable)) {
    //XHCI2 on Socket1 NBIO3
    Fch9004UsbSmiSysInfo.Socket1En = TRUE;
    Fch9004UsbSmiSysInfo.Socket1NbioSmiEn |= BIT3;
  }
  if (PcdGetBool (PcdXhci3Enable)) {
    //XHCI3 on Socket1 NBIO2
    Fch9004UsbSmiSysInfo.Socket1En = TRUE;
    Fch9004UsbSmiSysInfo.Socket1NbioSmiEn |= BIT2;
  }
  if (Fch9004UsbSmiSysInfo.Socket1En) {
    Fch9004UsbSmiSysInfo.Socket1Bus = (UINT8) FchSmmGetSocket1Bus ();
    DEBUG ((DEBUG_INFO, "[%a] Get 2nd Socket Bus Number = 0x%x\n", __FUNCTION__, Fch9004UsbSmiSysInfo.Socket1Bus));
  }
  DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Update USB SMI SysInfo: Socket0NbioSmiEn = 0x%x\n", \
         Fch9004UsbSmiSysInfo.Socket0NbioSmiEn));
  DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Update USB SMI SysInfo: Socket1NbioSmiEn = 0x%x\n", \
         Fch9004UsbSmiSysInfo.Socket1NbioSmiEn));
  DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Update USB SMI SysInfo: Socket1En = 0x%x\n", \
         Fch9004UsbSmiSysInfo.Socket1En));
  DEBUG ((DEBUG_INFO, "[FchSmmDispatcher] Update USB SMI SysInfo: Socket1Bus = 0x%x\n", \
         Fch9004UsbSmiSysInfo.Socket1Bus));
}

