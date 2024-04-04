/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * Fabric MMIO initialization library
 *
 * Contains interface to the family specific fabric MMIO map manager library
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGCL-R
 * @e sub-project:  Lib
 * @e \$Revision$   @e \$Date$
 *
 */

#ifndef _FABRIC_RESOURCE_INIT_LIB_H_
#define _FABRIC_RESOURCE_INIT_LIB_H_

#include <Uefi/UefiBaseType.h>
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
EFI_STATUS
FabricResourceInit (
  DFX_RCMGR_INPUT_BLK *DFXRcmgrInputBlock
  );

#pragma pack (pop)
#endif // _FABRIC_RESOURCE_INIT_LIB_H_

