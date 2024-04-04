/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/


#ifndef _AMD_PCI_RESOURCES_PROTOCOL_H
#define _AMD_PCI_RESOURCES_PROTOCOL_H

/// Forward declaration for the AMD_PCI_RESOURCES_PROTOCOL.
typedef struct _AMD_PCI_RESOURCES_PROTOCOL AMD_PCI_RESOURCES_PROTOCOL;

/**
 * @brief System information through EFI call
 * @details
 */
typedef
EFI_STATUS
(EFIAPI *AMD_PCI_RESOURCES_GET_NUMBER_OF_ROOTBRIDGES) (
  IN       AMD_PCI_RESOURCES_PROTOCOL            *This,
  OUT      UINTN                                 *NumberOfRootBridges
  );

typedef
EFI_STATUS
(EFIAPI *AMD_PCI_RESOURCES_GET_ROOT_BRIDGE_INFO) (
  IN       AMD_PCI_RESOURCES_PROTOCOL            *This,
  IN       UINTN                                 RootBridgeIndex,
  OUT      PCI_ROOT_BRIDGE_OBJECT                **RootBridgeInfo
  );

typedef
EFI_STATUS
(EFIAPI *AMD_PCI_RESOURCES_GET_NUMBER_OF_ROOTPORTS) (
  IN       AMD_PCI_RESOURCES_PROTOCOL            *This,
  IN       UINTN                                 RootBridgeIndex,
  OUT      UINTN                                 *NumberOfRootPorts
  );

typedef
EFI_STATUS
(EFIAPI *AMD_PCI_RESOURCES_GET_ROOT_PORT_INFO) (
  IN       AMD_PCI_RESOURCES_PROTOCOL            *This,
  IN       UINTN                                 RootBridgeIndex,
  IN       UINTN                                 RootPortIndex,
  OUT      PCI_ROOT_PORT_OBJECT                  **RootPortInfo
  );

typedef
EFI_STATUS
(EFIAPI *AMD_PCI_RESOURCES_GET_NUMBER_OF_FIXEDRESOURCES) (
  IN       AMD_PCI_RESOURCES_PROTOCOL            *This,
  IN       UINTN                                 RootBridgeIndex,
  OUT      UINTN                                 *NumberOfFixedResources
  );

typedef
EFI_STATUS
(EFIAPI *AMD_PCI_RESOURCES_GET_FIXED_RESOURCE_INFO) (
  IN       AMD_PCI_RESOURCES_PROTOCOL            *This,
  IN       UINTN                                 RootBridgeIndex,
  IN       UINTN                                 FixedResourceIndex,
  OUT      FIXED_RESOURCES_OBJECT                **FixedResourceInfo
  );

struct _AMD_PCI_RESOURCES_PROTOCOL {
    AMD_PCI_RESOURCES_GET_NUMBER_OF_ROOTBRIDGES        AmdPciResourcesGetNumberOfRootBridges;
    AMD_PCI_RESOURCES_GET_ROOT_BRIDGE_INFO             AmdPciResourcesGetRootBridgeInfo;
    AMD_PCI_RESOURCES_GET_NUMBER_OF_ROOTPORTS          AmdPciResourcesGetNumberOfRootPorts;
    AMD_PCI_RESOURCES_GET_ROOT_PORT_INFO               AmdPciResourcesGetRootPortInfo;
    AMD_PCI_RESOURCES_GET_NUMBER_OF_FIXEDRESOURCES     AmdPciResourcesGetNumberOfFixedResources;
    AMD_PCI_RESOURCES_GET_FIXED_RESOURCE_INFO          AmdPciResourcesGetFixedResourceInfo;
};

extern EFI_GUID gAmdPciResourceProtocolGuid;         ///< Guid for calling

#endif


