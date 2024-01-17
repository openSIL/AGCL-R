/******************************************************************************
*
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
**/

#include "FchSmmDispatcher.h"
#include "FchSmmSwDispatcher.h"

FCH_SMM_DISPATCHER_TABLE   FchSmmDispatcherTable[] = {
  {
    FCH_SMI_REG88,
    BIT12,
    FchSmmUsbDispatchHandler2
  },
  {
    FCH_SMI_REG84,
    UsbSmi,
    FchSmmUsbDispatchHandler
  },
  {
    FCH_SMI_REG88,
    Slp_Type,
    FchSmmSxDispatchHandler
  },
  {
    FCH_SMI_REG88,
    SmiCmdPort,
    FchSmmSwDispatchHandler
  },
  {
    FCH_SMI_REG84,
    PwrBtn,
    FchSmmPwrBtnDispatchHandler
  },
  {
    FCH_SMI_REG90,
    IoTrapping0 | IoTrapping1 | IoTrapping2 | IoTrapping3 ,
    FchSmmIoTrapDispatchHandler
  },
  {
    FCH_SMI_REG90,
    ShortTimer | LongTimer,
    FchSmmPeriodicalDispatchHandler
  },
  {
    FCH_SMI_REG10,
    Gpe,
    FchSmmGpiDispatchHandler
  },
  {
    FCH_SMI_REG84,
    Smbus0 | BIT13 | BIT14,
    FchSmmMiscDispatchHandler
  },
  {
    FCH_SMI_REG80,
    AllGevents,
    FchSmmMiscDispatchHandler
  },
  {
    FCH_SMI_REG88,
    FchGppSerr0 | FchGppSerr1 | FchGppSerr2 | FchGppSerr3,
    FchSmmMiscDispatchHandler
  },
  {
    FCH_SMI_REG84,
    FchFakeSts0,
    FchSmmMiscDispatchHandler
  },
  {
    FCH_SMI_REG84,
    BIT23,
    FchSmmMiscDispatchHandler
  },
};
UINT8 NumOfDispatcherTableEntry = sizeof (FchSmmDispatcherTable) / sizeof (FCH_SMM_DISPATCHER_TABLE);

SAVE_B2B_IO       B2bIoList[] = {
  {CFG_ADDR_PORT, SMM_IO_UINT32, 0},
  {0x70,  SMM_IO_UINT8, 0},
  {0x72,  SMM_IO_UINT8, 0},
  {FCH_IOMAP_REGC00, SMM_IO_UINT8, 0},
};
UINT8 NumOfB2bIoListEntry = sizeof (B2bIoList) / sizeof (SAVE_B2B_IO);

SAVE_PCI      SavePciList[] = {
  {0, 0, 0, IOHC_NB_SMN_INDEX_0_OFFSET, SMM_IO_UINT32, 0},  // IOHC::NB_SMN_INDEX_0
  {0, 0, 0, IOHC_NB_SMN_INDEX_1_OFFSET, SMM_IO_UINT32, 0},  // IOHC::NB_SMN_INDEX_1
  {0, 0, 0, IOHC_NB_SMN_INDEX_2_OFFSET, SMM_IO_UINT32, 0},  // IOHC::NB_SMN_INDEX_2
  {0, 0, 0, IOHC_NB_SMN_INDEX_3_OFFSET, SMM_IO_UINT32, 0},  // IOHC::NB_SMN_INDEX_3
  {0, 0, 0, IOHC_NB_SMN_INDEX_4_OFFSET, SMM_IO_UINT32, 0},  // IOHC::NB_SMN_INDEX_4
  {0, 0, 0, IOHC_NB_SMN_INDEX_5_OFFSET, SMM_IO_UINT32, 0},  // IOHC::NB_SMN_INDEX_5
};
UINT8 NumOfSavePciListEntry = sizeof (SavePciList) / sizeof (SAVE_PCI);

FCH_USB_SMI_SYSINFO  Fch9004UsbSmiSysInfo = {0};


