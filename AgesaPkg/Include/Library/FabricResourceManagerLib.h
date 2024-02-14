/*****************************************************************************
 * Copyright (C) 2008-2022 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * Low-level Fabric MMIO map manager Services library
 *
 * Contains interface to the family specific fabric MMIO and IO map manager library
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  Lib
 * @e \$Revision$   @e \$Date$
 *
 */

#ifndef _FABRIC_RESOURCE_MANAGER_LIB_H_
#define _FABRIC_RESOURCE_MANAGER_LIB_H_

#include <PiDxe.h>
#include <SilCommon.h>
#include <RcMgr/DfX/RcManager4-api.h>
#include <Apob.h>
#include <DF/DfIp2Ip.h>
#include <DF/Common/BaseFabricTopologyCmn.h>
#include <DF/DfX/DfXBaseFabricTopology.h>

#pragma pack (push, 1)

/*---------------------------------------------------------------------------------------
 *                 D E F I N I T I O N S     A N D     M A C R O S
 *---------------------------------------------------------------------------------------
 */

/*---------------------------------------------------------------------------------------
 *               T Y P E D E F S,   S T R U C T U R E S,    E N U M S
 *---------------------------------------------------------------------------------------
 */

/*---------------------------------------------------------------------------------------
 *                        F U N C T I O N    P R O T O T Y P E
 *---------------------------------------------------------------------------------------
 */

/**
  *  @brief Returns a list of currently available resources
  *  @details This function will read a current list of available resources. These value can be used for informative
  *     purposes or to prepare a call to the re-allocate function
  *  @param[in] ResourceForEachRb (DFX_FABRIC_RESOURCE_FOR_EACH_RB *) Pointer to a buffer where the function will place a matrix
  *     of information about the available resources. The buffer must be large enough to hold the matrix for the system.
  *
  *  @returns EFI_STATUS
  *  @retval EFI_SUCCESS           Available resources successfully obtained
  *  @retval EFI_ABORTED           Unable to obtain resource information
  */
EFI_STATUS
FabricGetAvailableResource (
  IN DFX_FABRIC_RESOURCE_FOR_EACH_RB *ResourceSizeForEachRb
  );

/**
 * This service retrieves information about the overall system with respect to data fabric.
 *
 * @param[out] NumberOfInstalledProcessors    Pointer to the total number of populated
 *                                            processor sockets in the system.
 * @param[out] TotalNumberOfDie               Pointer to the total number of die in the system.
 * @param[out] TotalNumberOfRootBridges       Pointer to the total number of root PCI bridges in
 *                                            the system.
 * @param[out] SystemFchRootBridgeLocation    System primary FCH location.
 * @param[out] SystemSmuRootBridgeLocation    System primary SMU location.
 *
 * @retval EFI_SUCCESS                        The system topology information was successfully retrieved.
 * @retval EFI_INVALID_PARAMETER              All output parameter pointers are NULL.
 *
 **/
EFI_STATUS
EFIAPI
FabricGetSystemInfo (
  OUT   UINT32                                 *NumberOfInstalledProcessors,
  OUT   UINT32                                 *TotalNumberOfDie,
  OUT   UINT32                                 *TotalNumberOfRootBridges,
  OUT   ROOT_BRIDGE_LOCATION                   *SystemFchRootBridgeLocation,
  OUT   ROOT_BRIDGE_LOCATION                   *SystemSmuRootBridgeLocation
  );

#pragma pack (pop)
#endif // _FABRIC_RESOURCE_MANAGER_LIB_H_
