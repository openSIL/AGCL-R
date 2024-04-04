/*****************************************************************************
 *
 * Copyright (C) 2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#include <PiPei.h>
#include <Library/BaseMemoryLib.h>
#include <Sil-api.h>
#include <Mpio/MpioClass-api.h>
#include <Mpio/Common/MpioStructs.h>

MPIO_PORT_DESCRIPTOR MpioPortDescriptorOnyx[] = {
    { // P4 - x1 NIC
      0,
      MPIO_ENGINE_DATA_INITIALIZER (MpioPcieEngine, 135, 135, PcieHotplugBasic, 0),
      MPIO_PORT_DATA_INITIALIZER_PCIE (
        MpioPortEnabled,                      // Port Present
        0,                                    // Requested Device
        0,                                    // Requested Function
        PcieHotplugDisabled,                  // Hotplug
        PcieGenMaxSupported,                  // Max Link Speed
        PcieGenMaxSupported,                  // Max Link Capability
        AspmL1,                               // ASPM
        AspmDisabled,                         // ASPM L1.1 disabled
        AspmDisabled,                         // ASPM L1.2 disabled
        MpioClkPmSupportDisabled              // Clock PM
      )
    },
    { // P4 - x1 M.2
      0,
      MPIO_ENGINE_DATA_INITIALIZER (MpioPcieEngine, 128, 131, PcieHotplugBasic, 0),
      MPIO_PORT_DATA_INITIALIZER_PCIE (
        MpioPortEnabled,                      // Port Present
        0,                                    // Requested Device
        0,                                    // Requested Function
        PcieHotplugDisabled,                  // Hotplug
        PcieGenMaxSupported,                  // Max Link Speed
        PcieGenMaxSupported,                  // Max Link Capability
        AspmL1,                               // ASPM
        AspmDisabled,                         // ASPM L1.1 disabled
        AspmDisabled,                         // ASPM L1.2 disabled
        MpioClkPmSupportDisabled              // Clock PM
      )
    },
    { // P5 - x2 WAFL
      DESCRIPTOR_TERMINATE_LIST,
      MPIO_ENGINE_DATA_INITIALIZER (MpioPcieEngine, 132, 133, PcieHotplugBasic, 0),
      MPIO_PORT_DATA_INITIALIZER_PCIE (
        MpioPortEnabled,                      // Port Present
        0,                                    // Requested Device
        0,                                    // Requested Function
        PcieHotplugDisabled,                  // Hotplug
        PcieGenMaxSupported,                  // Max Link Speed
        PcieGenMaxSupported,                  // Max Link Capability
        AspmL1,                               // ASPM
        AspmDisabled,                         // ASPM L1.1 disabled
        AspmDisabled,                         // ASPM L1.2 disabled
        MpioClkPmSupportDisabled              // Clock PM
      )
    },
};

MPIO_COMPLEX_DESCRIPTOR MpioComplexDescriptorOnyx = {
  DESCRIPTOR_TERMINATE_LIST,
  0,
  MpioPortDescriptorOnyx,
  NULL,
  0,
  0,
  {0,0}
};

EFI_STATUS
SetMpioConfig (
  MPIOCLASS_INPUT_BLK           *MpioData
  )
{
  CopyMem (&MpioData->PcieTopologyData.PlatformData, &MpioComplexDescriptorOnyx, sizeof (MPIO_COMPLEX_DESCRIPTOR));
  MpioData->PcieTopologyData.PlatformData[0].PciePortList = MpioData->PcieTopologyData.PortList;
  CopyMem (&MpioData->PcieTopologyData.PortList, &MpioPortDescriptorOnyx, sizeof (MpioPortDescriptorOnyx));

  return EFI_SUCCESS;
}