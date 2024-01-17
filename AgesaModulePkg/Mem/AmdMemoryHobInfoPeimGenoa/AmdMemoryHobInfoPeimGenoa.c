/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */
/**
 * @file
 *
 * AmdMemoryInfoHobPeimGenoa.
 *
 * Contains code that create Memory Hob.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESAt:      AGESA
 * @e sub-project:  UEFI
 * @e \$Revision: 320059 $   @e \$Date: 2015-06-04 00:21:59 -0500 (Thu, 04 Jun 2015) $
 *
 */
/*++
Module Name:

  AmdMemoryInfoHobPeimGenoa.c

Abstract:
--*/

#include <Library/HobLib.h>
#include <Guid/AmdMemoryInfoHobGenoa.h>
#include <Ppi/AmdMemoryInfoHobPpi.h>
#include <Ppi/AmdMemPpiGenoa.h>
#include <Include/xPrfServicesPpi.h>

#include "Filecode.h"
#define FILECODE MEM_AMDMEMORYHOBINFOPEIMRS_AMDMEMORYHOBINFOPEIMRS_FILECODE

extern EFI_GUID gAmdMemoryInitCompletePpiGuid;
extern EFI_GUID gAmdNvdimmInfoHobGuid;
typedef struct _MEMORY_INFO_BLOCK_STRUCT {
  IN BOOLEAN           MemFrequencyValid;   ///< Memory Frequency Valid
  IN UINT32            MemFrequency;        ///< Memory Frequency
  IN BOOLEAN           VddioValid;          ///< This field determines if Vddio is valid
  IN UINT16            Vddio;               ///< Vddio Voltage
  IN BOOLEAN           VddpVddrValid;       ///< This field determines if VddpVddr is valid
  IN UINT8             VddpVddr;            ///< VddpVddr voltage
  IN UINT32            DdrMaxRate;          ///< UMC DdrMaxRateVddpVddr
} MEMORY_INFO_BLOCK_STRUCT;

#ifndef FOURGB
#define FOURGB      0x100000000ull
#endif

#define MAX_NUMBER_OF_EXTENDED_MEMORY_DESCRIPTOR    30
#define MAX_SIZEOF_AMD_MEMORY_INFO_HOB_BUFFER       (sizeof (AMD_MEMORY_INFO_HOB) +  \
          (MAX_NUMBER_OF_EXTENDED_MEMORY_DESCRIPTOR * sizeof (AMD_MEMORY_RANGE_DESCRIPTOR)))


//
// PPI Initialization
//
STATIC AMD_MEMORY_INFO_HOB_PPI mAmdMemoryHobInfoAvailblePpi = {
  AMD_MEMORY_INFO_HOB_PPI_REV_0400
};


STATIC EFI_PEI_PPI_DESCRIPTOR mAmdMemoryHobInfoAvailblePpiList =
{
  (EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
  &gAmdMemoryInfoHobPpiGuid,
  &mAmdMemoryHobInfoAvailblePpi
};

#define ALLOC_PER_SOCKET  BIT0
#define ALLOC_PER_DIE     BIT1
#define ALLOC_PER_CHANNEL BIT2
#define ALLOC_PER_DIMM    BIT3

#define AMD_MEM_CFG_INFO_HOB_OFFSET(Field) OFFSET_OF (AMD_MEM_CFG_INFO_HOB_GENOA, Field)

typedef struct {
   UINT16 Offset;
   UINT8  MultiplySize;
   UINT8  MultiplyFlag;
} MEM_CFG_INFO_HOB_LOOKUP_ENTRY;

CONST MEM_CFG_INFO_HOB_LOOKUP_ENTRY mScalableDataLookupTbl[] = {
  { AMD_MEM_CFG_INFO_HOB_OFFSET (DimmPresentMapOffset)                       , sizeof(UINT32)           , (ALLOC_PER_SOCKET | ALLOC_PER_DIE)                     }, //DimmPresentMap
  { AMD_MEM_CFG_INFO_HOB_OFFSET (ChipselIntlvOffset)                         , sizeof(MEM_CFG_INFO_HOB) , (ALLOC_PER_SOCKET | ALLOC_PER_DIE | ALLOC_PER_CHANNEL) }, //ChipselIntlv
  { AMD_MEM_CFG_INFO_HOB_OFFSET (DramEccOffset)                              , sizeof(MEM_CFG_INFO_HOB) , (ALLOC_PER_SOCKET | ALLOC_PER_DIE)                     }, //DramEcc
  { AMD_MEM_CFG_INFO_HOB_OFFSET (DramParityOffset)                           , sizeof(MEM_CFG_INFO_HOB) , (ALLOC_PER_SOCKET | ALLOC_PER_DIE)                     }, //DramParity
  { AMD_MEM_CFG_INFO_HOB_OFFSET (AutoRefFineGranModeOffset)                  , sizeof(MEM_CFG_INFO_HOB) , (ALLOC_PER_SOCKET | ALLOC_PER_DIE)                     }, //AutoRefFineGranMode
};

/*++
Routine Description:

  This function expands the offset for dynamic data.

Arguments:

  MemCfgInfo - GuidHob pointer

Returns:
  EFI_STATUS - Status code
--*/
STATIC
EFI_STATUS
InternalScalableDataAddrMapping (
  IN OUT AMD_MEM_CFG_INFO_HOB_GENOA  *MemCfgInfo
  )
{
  UINT16  Index;
  UINT16  Offset;
  UINT16  MultipliedResult;
  UINT8   *HobStart;

  HobStart = (UINT8 *)(UINTN) MemCfgInfo;

  Index = 0;
  Offset = sizeof(AMD_MEM_CFG_INFO_HOB_GENOA);
  do {
    *(UINT16 *)(HobStart + mScalableDataLookupTbl[Index].Offset) = Offset;
    MultipliedResult = mScalableDataLookupTbl[Index].MultiplySize;
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_SOCKET) != 0) {
      MultipliedResult *= MemCfgInfo->MaxSocketSupported;
    }
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_DIE) != 0) {
      MultipliedResult *= MemCfgInfo->MaxDiePerSocket;
    }
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_CHANNEL) != 0) {
      MultipliedResult *= MemCfgInfo->MaxChannelPerDie;
    }
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_DIMM) != 0) {
      MultipliedResult *= MemCfgInfo->MaxDimmPerChannel;
    }
    // Size
    Offset += MultipliedResult;
    Index++;
  } while (Index < sizeof (mScalableDataLookupTbl) / sizeof (MEM_CFG_INFO_HOB_LOOKUP_ENTRY));

  return EFI_SUCCESS;
}

EFI_STATUS
BuildHobMemoryConfigInfoData (
  IN AMD_MEMORY_INIT_COMPLETE_PPI   *MemInitCompleteData
 )
{
  EFI_STATUS Status;
  AMD_MEM_CFG_INFO_HOB_GENOA *MemCfgInfo;
  UINTN SizeToAlloc;
  UINT8 NumOfAllocInfoHob;
  UINT32 *DimmPresentMap;
  MEM_CFG_INFO_HOB *ChipselIntlv, *DramEcc, *DramParity, *AutoRefFineGranMode;
  UINT16 Socket, Die, Channel, Index;
  UINTN MultipliedResult;

  //
  // Caculate total size in byte, including Fixed and Dynamic data.
  //
  NumOfAllocInfoHob = sizeof (mScalableDataLookupTbl) / sizeof (mScalableDataLookupTbl[0]);

  Index = 0;
  SizeToAlloc = sizeof(AMD_MEM_CFG_INFO_HOB_GENOA);
  do {
    MultipliedResult = mScalableDataLookupTbl[Index].MultiplySize;
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_SOCKET) != 0) {
      MultipliedResult *= MemInitCompleteData->MaxSocketSupported;
    }
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_DIE) != 0) {
      MultipliedResult *= MemInitCompleteData->MaxDiePerSocket;
    }
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_CHANNEL) != 0) {
      MultipliedResult *= MemInitCompleteData->MaxChannelPerDie;
    }
    if ((mScalableDataLookupTbl[Index].MultiplyFlag & ALLOC_PER_DIMM) != 0) {
      MultipliedResult *= MemInitCompleteData->MaxDimmPerChannel;
    }
    // Size
    SizeToAlloc += MultipliedResult;
    Index++;
  } while (Index < NumOfAllocInfoHob);

  //
  // Fill in HOB data from PPI data structure
  // Note: HOB data structure is packed, DO NOT use CopyMem.
  //
  Status = EFI_NOT_FOUND;
  MemCfgInfo = (AMD_MEM_CFG_INFO_HOB_GENOA *) BuildGuidHob (&gAmdMemCfgInfoHobGuid, SizeToAlloc);
  if (MemCfgInfo != NULL) {
    // Fill in version
    MemCfgInfo->Version = AMD_MEM_CFG_INFO_HOB_VER_0400;

    // Fill in max. number of Socket/Die/Channel/Dimm
    MemCfgInfo->MaxSocketSupported = MemInitCompleteData->MaxSocketSupported;
    MemCfgInfo->MaxDiePerSocket    = MemInitCompleteData->MaxDiePerSocket;
    MemCfgInfo->MaxChannelPerDie   = MemInitCompleteData->MaxChannelPerDie;
    MemCfgInfo->MaxDimmPerChannel  = MemInitCompleteData->MaxDimmPerChannel;

    /// Fixed data
    // MbistTestEnable
    MemCfgInfo->MbistTestEnable.Status.Enabled =  MemInitCompleteData->MbistTestEnable.Status.Enabled;
    MemCfgInfo->MbistTestEnable.StatusCode =  MemInitCompleteData->MbistTestEnable.StatusCode;
    // MbistAggressorEnable
    MemCfgInfo->MbistAggressorEnable.Status.Enabled =  MemInitCompleteData->MbistAggressorEnable.Status.Enabled;
    MemCfgInfo->MbistAggressorEnable.StatusCode =  MemInitCompleteData->MbistAggressorEnable.StatusCode;
    // MbistPerBitSecondaryDieReport
    MemCfgInfo->MbistPerBitSecondaryDieReport.Status.Value =  MemInitCompleteData->MbistPerBitSecondaryDieReport.Status.Value;
    MemCfgInfo->MbistPerBitSecondaryDieReport.StatusCode =  MemInitCompleteData->MbistPerBitSecondaryDieReport.StatusCode;
    // DramTempControlledRefreshEn
    MemCfgInfo->DramTempControlledRefreshEn.Status.Enabled =  MemInitCompleteData->DramTempControlledRefreshEn.Status.Enabled;
    MemCfgInfo->DramTempControlledRefreshEn.StatusCode =  MemInitCompleteData->DramTempControlledRefreshEn.StatusCode;
    // UserTimingMode
    MemCfgInfo->UserTimingMode.Status.Enabled =  MemInitCompleteData->UserTimingMode.Status.Enabled;
    MemCfgInfo->UserTimingMode.StatusCode =  MemInitCompleteData->UserTimingMode.StatusCode;
    // UserTimingValue
    MemCfgInfo->UserTimingValue.Status.Enabled =  MemInitCompleteData->UserTimingValue.Status.Enabled;
    MemCfgInfo->UserTimingValue.StatusCode =  MemInitCompleteData->UserTimingValue.StatusCode;
    // MemBusFreqLimit
    MemCfgInfo->MemBusFreqLimit.Status.Enabled =  MemInitCompleteData->MemBusFreqLimit.Status.Enabled;
    MemCfgInfo->MemBusFreqLimit.StatusCode =  MemInitCompleteData->MemBusFreqLimit.StatusCode;
    // EnablePowerDown
    MemCfgInfo->EnablePowerDown.Status.Enabled =  MemInitCompleteData->EnablePowerDown.Status.Enabled;
    MemCfgInfo->EnablePowerDown.StatusCode =  MemInitCompleteData->EnablePowerDown.StatusCode;
    // DramDoubleRefreshRate
    MemCfgInfo->DramDoubleRefreshRate.Status.Enabled =  MemInitCompleteData->DramDoubleRefreshRate.Status.Enabled;
    MemCfgInfo->DramDoubleRefreshRate.StatusCode =  MemInitCompleteData->DramDoubleRefreshRate.StatusCode;
    // PmuTrainMode
    MemCfgInfo->PmuTrainMode.Status.Value =  MemInitCompleteData->PmuTrainMode.Status.Value;
    MemCfgInfo->PmuTrainMode.StatusCode =  MemInitCompleteData->PmuTrainMode.StatusCode;
    // EccSymbolSize
    MemCfgInfo->EccSymbolSize.Status.Value =  MemInitCompleteData->EccSymbolSize.Status.Value;
    MemCfgInfo->EccSymbolSize.StatusCode =  MemInitCompleteData->EccSymbolSize.StatusCode;
    // UEccRetry
    MemCfgInfo->UEccRetry.Status.Enabled =  MemInitCompleteData->UEccRetry.Status.Enabled;
    MemCfgInfo->UEccRetry.StatusCode =  MemInitCompleteData->UEccRetry.StatusCode;
    // IgnoreSpdChecksum
    MemCfgInfo->IgnoreSpdChecksum.Status.Enabled =  MemInitCompleteData->IgnoreSpdChecksum.Status.Enabled;
    MemCfgInfo->IgnoreSpdChecksum.StatusCode =  MemInitCompleteData->IgnoreSpdChecksum.StatusCode;
    // EnableBankGroupSwapAlt
    MemCfgInfo->EnableBankGroupSwapAlt.Status.Enabled =  MemInitCompleteData->EnableBankGroupSwapAlt.Status.Enabled;
    MemCfgInfo->EnableBankGroupSwapAlt.StatusCode =  MemInitCompleteData->EnableBankGroupSwapAlt.StatusCode;
    // EnableBankGroupSwap
    MemCfgInfo->EnableBankGroupSwap.Status.Enabled =  MemInitCompleteData->EnableBankGroupSwap.Status.Enabled;
    MemCfgInfo->EnableBankGroupSwap.StatusCode =  MemInitCompleteData->EnableBankGroupSwap.StatusCode;
    // DdrRouteBalancedTee
    MemCfgInfo->DdrRouteBalancedTee.Status.Enabled =  MemInitCompleteData->DdrRouteBalancedTee.Status.Enabled;
    MemCfgInfo->DdrRouteBalancedTee.StatusCode =  MemInitCompleteData->DdrRouteBalancedTee.StatusCode;
    // NvdimmPowerSource
    MemCfgInfo->NvdimmPowerSource.Status.Value =  MemInitCompleteData->NvdimmPowerSource.Status.Value;
    MemCfgInfo->NvdimmPowerSource.StatusCode =  MemInitCompleteData->NvdimmPowerSource.StatusCode;
    // OdtsCmdThrotEn
    MemCfgInfo->OdtsCmdThrotEn.Status.Enabled =  MemInitCompleteData->OdtsCmdThrotEn.Status.Enabled;
    MemCfgInfo->OdtsCmdThrotEn.StatusCode =  MemInitCompleteData->OdtsCmdThrotEn.StatusCode;
    // OdtsCmdThrotCyc
    MemCfgInfo->OdtsCmdThrotCyc.Status.Enabled =  MemInitCompleteData->OdtsCmdThrotCyc.Status.Enabled;
    MemCfgInfo->OdtsCmdThrotCyc.StatusCode =  MemInitCompleteData->OdtsCmdThrotCyc.StatusCode;

    ///
    /// Dynamic data
    ///
    Status = InternalScalableDataAddrMapping (MemCfgInfo);
    if (EFI_ERROR (Status)) {
      return Status;
    }

    //
    // Get address
    //
    DimmPresentMap        = (UINT32 *) GET_MEM_CFG_INFO_HOB_ADDR (MemCfgInfo, DimmPresentMapOffset);
    ChipselIntlv          = (MEM_CFG_INFO_HOB *) GET_MEM_CFG_INFO_HOB_ADDR (MemCfgInfo, ChipselIntlvOffset);
    DramEcc               = (MEM_CFG_INFO_HOB *) GET_MEM_CFG_INFO_HOB_ADDR (MemCfgInfo, DramEccOffset);
    DramParity            = (MEM_CFG_INFO_HOB *) GET_MEM_CFG_INFO_HOB_ADDR (MemCfgInfo, DramParityOffset);
    AutoRefFineGranMode   = (MEM_CFG_INFO_HOB *) GET_MEM_CFG_INFO_HOB_ADDR (MemCfgInfo, AutoRefFineGranModeOffset);

    //
    // Fill in data
    //
    for (Socket = 0; Socket < MemInitCompleteData->MaxSocketSupported; Socket++) {

      for (Die = 0; Die < MemInitCompleteData->MaxDiePerSocket; Die++) {
        Index = Socket * MemInitCompleteData->MaxDiePerSocket + Die;
        // DimmPresentMap
        DimmPresentMap[Index] = MemInitCompleteData->DimmPresentMap[Index];
        // DramEcc
        DramEcc[Index].Status.Enabled = MemInitCompleteData->DramEcc[Index].Status.Enabled;
        DramEcc[Index].StatusCode = MemInitCompleteData->DramEcc[Index].StatusCode;
        // DramParity
        DramParity[Index].Status.Enabled = MemInitCompleteData->DramParity[Index].Status.Enabled;
        DramParity[Index].StatusCode = MemInitCompleteData->DramParity[Index].StatusCode;
        // AutoRefFineGranMode
        AutoRefFineGranMode[Index].Status.Value = MemInitCompleteData->AutoRefFineGranMode[Index].Status.Value;
        AutoRefFineGranMode[Index].StatusCode = MemInitCompleteData->AutoRefFineGranMode[Index].StatusCode;

        for (Channel = 0; Channel < MemInitCompleteData->MaxChannelPerDie; Channel++) {
          Index = Socket * MemInitCompleteData->MaxDiePerSocket * MemInitCompleteData->MaxChannelPerDie +
                  Die * MemInitCompleteData->MaxChannelPerDie + Channel;
          // ChipselIntlv
          ChipselIntlv[Index].Status.Enabled = MemInitCompleteData->ChipselIntlv[Index].Status.Enabled;
          ChipselIntlv[Index].StatusCode = MemInitCompleteData->ChipselIntlv[Index].StatusCode;
        }
      }
    }
    Status = EFI_SUCCESS;
  }

  return Status;
}

EFI_STATUS
BuildHobInfo (
  IN CONST  EFI_PEI_SERVICES    **PeiServices,
  IN MEMORY_INFO_BLOCK_STRUCT   *MemInfoBlockPtr
  )
/*++

Routine Description:

  This function build HOB info from post interface parameters

Arguments:

  PeiServices     -     PeiServices
  MemInfoBlockPtr -     MemInfoBlock pointer

Returns:
  EFI_STATUS - Status code
--*/
{
  EFI_STATUS                          Status;
  UINT32                              Index;
  UINT64                              TopOfMemAddress;
  UINT64                              CurrentBase;
  UINT32                              NumOfHoles;
  UINT8                               MemInfoHobBuffer[MAX_SIZEOF_AMD_MEMORY_INFO_HOB_BUFFER];
  AMD_MEMORY_INFO_HOB                 *MemInfoHob;
  AMD_MEMORY_RANGE_DESCRIPTOR         *MemRangeDesc;
  UINTN                               SizeOfMemInfoHob;
  UINT32                              MemRangeIndex;
  AMD_MEMORY_INIT_COMPLETE_PPI        *mMemoryInitCompletePpiPtr;
  MEMORY_HOLE_DESCRIPTOR              *HoleMapPtr;
  AMD_OPENSIL_XPRF_SERVICES_PPI       *mOpenSilXprfServicePpi;

  HoleMapPtr = NULL;
  Status = (*PeiServices)->LocatePpi (PeiServices,
                                      &gAmdMemoryInitCompletePpiGuid,
                                      0,
                                      NULL,
                                      (VOID **)&mMemoryInitCompletePpiPtr);
  if (EFI_SUCCESS != Status) {
    return Status;
  }

  Status = (*PeiServices)->LocatePpi (
                             PeiServices,
                             &gOpenSilxPrfServicePpiGuid,
                             0,
                             NULL,
                             (VOID **)&mOpenSilXprfServicePpi
                             );
  if (EFI_SUCCESS != Status) {
    return Status;
  }
  Status = mOpenSilXprfServicePpi->SilGetSystemMemoryMap(
                                     &NumOfHoles,
                                     &TopOfMemAddress,
                                     (VOID **)&HoleMapPtr
                                     );

  if (EFI_SUCCESS != Status) {
    return Status;
  }
  if (HoleMapPtr == NULL) {
    return EFI_NOT_FOUND;
  }

  MemInfoHob = (AMD_MEMORY_INFO_HOB *) &MemInfoHobBuffer[0];
  MemRangeDesc = &MemInfoHob->Ranges[0];
  MemInfoHob->Version = AMD_MEMORY_INFO_HOB_VERISION;
  MemRangeIndex = 0;
  CurrentBase = 0;
  for (Index = 0; Index < NumOfHoles; Index++) {
    switch (HoleMapPtr->Type) {
    case MMIO:
      MemRangeDesc[MemRangeIndex].Size =  (HoleMapPtr->Base - CurrentBase);
      if ( 0 != MemRangeDesc[MemRangeIndex].Size) {
        MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_AVAILABLE;
        MemRangeDesc[MemRangeIndex].Base = CurrentBase;
        CurrentBase += MemRangeDesc[MemRangeIndex].Size;
        MemRangeIndex += 1;
      }

      MemRangeDesc[MemRangeIndex].Size =  HoleMapPtr->Size;
      ASSERT (0 != MemRangeDesc[MemRangeIndex].Size);
      MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_MMIO;
      MemRangeDesc[MemRangeIndex].Base = HoleMapPtr->Base;
      CurrentBase += HoleMapPtr->Size;
      break;

    case Reserved1TbRemap:
      MemRangeDesc[MemRangeIndex].Size = (HoleMapPtr->Base - CurrentBase);
      if (0 != MemRangeDesc[MemRangeIndex].Size) {
        MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_AVAILABLE;
        MemRangeDesc[MemRangeIndex].Base = CurrentBase;
        CurrentBase += MemRangeDesc[MemRangeIndex].Size;
        MemRangeIndex += 1;
      }

      MemRangeDesc[MemRangeIndex].Size =  HoleMapPtr->Size;
      ASSERT (0 != MemRangeDesc[MemRangeIndex].Size);
      MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_MMIO_RESERVED;
      MemRangeDesc[MemRangeIndex].Base = HoleMapPtr->Base;
      CurrentBase += HoleMapPtr->Size;
      break;

    case UMA:
      MemRangeDesc[MemRangeIndex].Size =  (HoleMapPtr->Base - CurrentBase);
      if (0 != MemRangeDesc[MemRangeIndex].Size) {
        MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_AVAILABLE;
        MemRangeDesc[MemRangeIndex].Base = CurrentBase;
        CurrentBase += MemRangeDesc[MemRangeIndex].Size;
        MemRangeIndex += 1;
      }

      MemRangeDesc[MemRangeIndex].Size =  HoleMapPtr->Size;
      ASSERT (0 != MemRangeDesc[MemRangeIndex].Size);
      MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_UMA;
      MemRangeDesc[MemRangeIndex].Base = HoleMapPtr->Base;
      CurrentBase += HoleMapPtr->Size;
      break;

    default:
      if (PcdGetBool (PcdCfgIommuSupport) && (CurrentBase <= 0xFD00000000) && (HoleMapPtr->Base >= 0x10000000000)) {
        MemRangeDesc[MemRangeIndex].Size = (0xFD00000000 - CurrentBase);
        if ( 0 != MemRangeDesc[MemRangeIndex].Size) {
          MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_AVAILABLE;
          MemRangeDesc[MemRangeIndex].Base = CurrentBase;
          CurrentBase += MemRangeDesc[MemRangeIndex].Size;
          MemRangeIndex += 1;
        }

        MemRangeDesc[MemRangeIndex].Size = (0x10000000000 - CurrentBase);
        if ( 0 != MemRangeDesc[MemRangeIndex].Size) {
          MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_RESERVED;
          MemRangeDesc[MemRangeIndex].Base = CurrentBase;
          CurrentBase += MemRangeDesc[MemRangeIndex].Size;
          MemRangeIndex += 1;
        }
      }

      MemRangeDesc[MemRangeIndex].Size =  (HoleMapPtr->Base - CurrentBase);
      if ( 0 != MemRangeDesc[MemRangeIndex].Size) {
        MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_AVAILABLE;
        MemRangeDesc[MemRangeIndex].Base = CurrentBase;
        CurrentBase += MemRangeDesc[MemRangeIndex].Size;
        MemRangeIndex += 1;
      }

      MemRangeDesc[MemRangeIndex].Size =  HoleMapPtr->Size;
      ASSERT (0 != MemRangeDesc[MemRangeIndex].Size);
      MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_RESERVED;
      MemRangeDesc[MemRangeIndex].Base = HoleMapPtr->Base;
      CurrentBase += HoleMapPtr->Size;
      break;
    }
    MemRangeIndex++;
    HoleMapPtr++;
  }

  if (CurrentBase < TopOfMemAddress) {
    //
    // MemRangeIndex will be incremented in the previous loop hence dont need to increment here
    //
    MemRangeDesc[MemRangeIndex].Attribute = AMD_MEMORY_ATTRIBUTE_AVAILABLE;
    MemRangeDesc[MemRangeIndex].Base = CurrentBase;
    MemRangeDesc[MemRangeIndex].Size =  TopOfMemAddress - CurrentBase;
  } else {
    // Since no additional descriptor required to be updated, decrease the
    // incremented number by 1 to ensure we report correct number of descriptor
    MemRangeIndex--;
  }

  MemInfoHob->NumberOfDescriptor = MemRangeIndex + 1;
  SizeOfMemInfoHob = sizeof (AMD_MEMORY_INFO_HOB) + (MemInfoHob->NumberOfDescriptor - 1) * sizeof (AMD_MEMORY_RANGE_DESCRIPTOR);
  //
  // Update Voltage Information.
  //
  MemInfoHob->AmdMemoryVddioValid = MemInfoBlockPtr->VddioValid;
  MemInfoHob->AmdMemoryVddio = MemInfoBlockPtr->Vddio;
  MemInfoHob->AmdMemoryVddpVddrValid = MemInfoBlockPtr->VddpVddrValid;
  MemInfoHob->AmdMemoryVddpVddr = MemInfoBlockPtr->VddpVddr;
  MemInfoHob->AmdMemoryFrequencyValid = MemInfoBlockPtr->MemFrequencyValid;
  MemInfoHob->AmdMemoryFrequency = MemInfoBlockPtr->MemFrequency;
  MemInfoHob->AmdMemoryDdrMaxRate = MemInfoBlockPtr->DdrMaxRate;

  Status =  EFI_SUCCESS;
  if (BuildGuidDataHob (&gAmdMemoryInfoHobGuid, &MemInfoHobBuffer, SizeOfMemInfoHob) == NULL) {
    Status = EFI_NOT_FOUND;
    return Status;
  }

  ///
  /// Build Memory Config. Info. HOB
  ///
  Status = BuildHobMemoryConfigInfoData (mMemoryInitCompletePpiPtr);

  return Status;
}

EFI_STATUS
GetMemInfoBlockData (
  IN       CONST EFI_PEI_SERVICES         **PeiServices,
  IN OUT         MEMORY_INFO_BLOCK_STRUCT *MemInfoBlockPtr
  )
/*++ -----------------------------------------------------------------------------
  Routine Description:
    This function will get the APOB Data from APOB HOB

  Arguments:
    MemInfoBlockPtr   - Pointer to the AGESA_PSP_OUTPUT_BLOCK_STRUCT

  Returns:
    EFI_STATUS  - Status code
                  EFI_SUCCESS
 */
{
  EFI_STATUS                     Status;
  AMD_MEMORY_INIT_COMPLETE_PPI   *mMemoryInitCompletePpiPtr;

  Status = (*PeiServices)->LocatePpi (PeiServices,
                                      &gAmdMemoryInitCompletePpiGuid,
                                      0,
                                      NULL,
                                      (VOID **)&mMemoryInitCompletePpiPtr);
  if (EFI_SUCCESS != Status) {
    return Status;
  }


  MemInfoBlockPtr->MemFrequencyValid = TRUE;
  MemInfoBlockPtr->MemFrequency = mMemoryInitCompletePpiPtr->AmdMemoryFrequency;

  MemInfoBlockPtr->VddioValid = TRUE;
  MemInfoBlockPtr->Vddio = (UINT16) mMemoryInitCompletePpiPtr->AmdMemoryVddIo;

  MemInfoBlockPtr->VddpVddrValid = mMemoryInitCompletePpiPtr->AmdMemoryVddpVddr.IsValid;
  MemInfoBlockPtr->VddpVddr = mMemoryInitCompletePpiPtr->AmdMemoryVddpVddr.Voltage;
  MemInfoBlockPtr->DdrMaxRate = mMemoryInitCompletePpiPtr->DdrMaxRate;

  return EFI_SUCCESS;
}


EFI_STATUS
EFIAPI
InitializeAmdMemoryInfoHobPeimGenoa (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )
/*++

Routine Description:

  Initialization Entry Point for AmdMemoryHobInfo PEIM

Arguments:
  FileHandle -  FileHandle
  PeiServices - PeiServices

Returns:
  EFI_STATUS  - Status code
                EFI_SUCCESS

--*/
{
  EFI_STATUS                 Status;
  MEMORY_INFO_BLOCK_STRUCT   MemInfoBlock;

  //
  // Get Memory Info Block Data
  //
  Status = GetMemInfoBlockData (PeiServices, &MemInfoBlock);
  if (Status != EFI_SUCCESS) {
    return Status;
  }

  //
  // Build Memory Info Hob
  //
  Status = BuildHobInfo (PeiServices, &MemInfoBlock);

  if (Status == EFI_SUCCESS) {
    Status = (**PeiServices).InstallPpi (PeiServices, &mAmdMemoryHobInfoAvailblePpiList);
  }
  return Status;
}




