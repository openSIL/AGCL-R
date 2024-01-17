/*****************************************************************************
 *
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 **/

/**
 * @file
 *
 * AMD MEM PPI prototype definition
 *
 */

#ifndef _AMD_MEM_PPI_GENOA_H_
#define _AMD_MEM_PPI_GENOA_H_

#include <Base.h>
#include "AGESA.h"
#include "PlatformMemoryConfiguration.h"
#include "Library/AmdCalloutLib.h"

//----------------------------------------------------
//
//  Amd Memory Service Functions
//
//-------------------------------------------------------

/**
  Reads Service for the Memory Above 4GB

  Parameters:
  PeiServices
    A pointer to the PEI services
  AmountOfMemory
    Return data pointer for the amount of memory

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_MEMORY_ABOVE_4GB_INTERFACE  ) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            *AmountOfMemory
  );
/**
  Read Service for the Memory Below 4GB

  Parameters:
  PeiServices
    A pointer to the PEI services
  AmountOfMemory
    Return data pointer for the amount of memory

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_MEMORY_BELOW_4GB_INTERFACE  ) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            *AmountOfMemory
  );
/**
  Read Service for the memory Below 1TB

  Parameters:
  PeiServices
    A pointer to the PEI services
  AmountOfMemory
    Return data pointer for the amount of memory

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_MEMORY_BELOW_1TB_INTERFACE  ) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            *AmountOfMemory
  );
/**
  Read Service for the total amount of memory in the system

  Parameters:
  PeiServices
    A pointer to the PEI services
  AmountOfMemory
    Return data pointer for the amount of memory

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_TOTAL_MEMORY_SIZE_INTERFACE) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            *AmountOfMemory
  );
/**
  Read Service for the Bottom of MMIO

  Parameters:
  PeiServices
    A pointer to the PEI services
  AmountOfMemory
    Return data pointer for the amount of memory

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_MEMORY_BOTTOM_IO_INTERFACE) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            *AmountOfMemory
  );
/**
  Read Service for the Memory Frequency of a channel

  Parameters:
  PeiServices
    A pointer to the PEI services
  Channel
    A pointer to the channel to read
  Frequency
    Return data pointer for a channel frequency

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_MEMORY_FREQUENCY_INTERFACE) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            Channel,
     OUT  UINT32            *Frequency
  );
/**
  Read Service for the Memory Frequency of a channel

  Parameters:
  PeiServices
    A pointer to the PEI services
  UmaInfo
    Return data pointer for the UmaInfo

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_SOC_GET_UMA_INFO_INTERFACE) (
  IN      EFI_PEI_SERVICES  **PeiServices,
     OUT  UINT32            *UmaInfo
  );



/**
 * @brief Get the Memory Map Interface
 * @param[in] PeiServices - A pointer to the PEI services
 * @param[in] NumberOfHoles - The number of holes in the system memory map
 * @param[in] TopOfSystemMemory - Top of system memory
 * @param[in] MemHoleDescPtr - Pointer to an open ended array of MEMORY_HOLE_DESCRIPTORs.
 * @return EFI_SUCCESS           - Return value is valid
 * @return EFI_UNSUPPORTED       - This function is not supported by this version of the driver
 */
typedef EFI_STATUS (EFIAPI * PEI_GET_SYSTEM_MEMORY_MAP) (
  IN CONST EFI_PEI_SERVICES     **PeiServices,
  IN UINT32                     *NumberOfHoles,
  IN UINT64                     *TopOfSystemMemory,
  IN VOID                       **MemHoleDescPtr
 );



//----------------------------------------------------
//
//  Amd Memory Init Complete Ppi
//
//-------------------------------------------------------
extern EFI_GUID gAmdMemoryInitCompletePpiGuid;
extern EFI_GUID gAmdMemTerminationDataPpiGuid;

/**
 * @brief Amd Memory UMA Info
 */
typedef struct _AMD_MEMORY_UMA_INFO {
  UMA_MODE UmaMode; ///<  Uma Mode
                       ///<  0 = None
                       ///<  1 = Specified
                       ///<  2 = Auto
  UINT32 UmaSize; ///<  The size of shared graphics dram (16-bits)
                     ///<  NV_UMA_Size[31:0]=Addr[47:16]
                     ///<
  UINT32 UmaBase;
} AMD_MEMORY_UMA_INFO;

//-----------------------------------------------------------------------------

#ifndef _MEM_STATUS_CODE_GENERAL_INFO_
#define _MEM_STATUS_CODE_GENERAL_INFO_

//
// Macro to get DIMM presence
//
#define GET_DIMM_PRESENCE_OF(This, DimmPresentMap, Socket, Die, Channel, Dimm) \
       (UINT8) ((DimmPresentMap[Socket * ((AMD_MEMORY_INIT_COMPLETE_PPI  *)This)->MaxDiePerSocket +\
                      Die] >> (Channel *  ((AMD_MEMORY_INIT_COMPLETE_PPI  *)This)->MaxDimmPerChannel + Dimm)) & 1)
#endif

/**
 * @brief Status union for boolean or value status
 */
typedef union {
  BOOLEAN Enabled;    ///< Status.Enabled - TRUE: Enabled.
  UINT16 Value;       ///< Status.Value - Configured value.
} STATUS;

/**
 * @brief Memory Config Info
 */
typedef struct _MEM_CFG_INFO {
   STATUS Status;        ///< Status: Enable/disable or configured status value
   UINT16 StatusCode;    ///< Status Code: MEM_STATUS_CODE_GENERAL_INFO
} MEM_CFG_INFO;

/**
 * @brief Amd Memory Init Complete Ppi
 */
typedef struct _AMD_MEMORY_INIT_COMPLETE_PPI {
  UINT32                 Revision;                                              ///< revision
  UINT16                 AmdBottomIo;                                           ///< Bottom IO
  UINT32                 AmdMemoryBelow4gb;                                     ///< Memory below 4G
  UINT32                 AmdMemoryAbove4gb;                                     ///< Memory above 4G
  UINT32                 AmdMemoryBelow1Tb;                                     ///< Memory below 1T
  UINT32                 AmdTotalMemorySize;                                    ///< Total Memory Size
  UINT32                 AmdMemoryFrequency;                                    ///< Memory Frequency
  DIMM_VOLTAGE           AmdMemoryVddIo;                                        ///< Memory Vddio
  VDDP_VDDR_VOLTAGE      AmdMemoryVddpVddr;                                     ///< Memory Vddp Vddr
  AMD_MEMORY_UMA_INFO    AmdGetUmaInfo;                                         ///< AMD UMA Info
  UINT32                 DdrMaxRate;                                            ///< DdrMaxRate
  PEI_GET_SYSTEM_MEMORY_MAP        GetSystemMemoryMap;                          ///< System Memory Map @see PEI_GET_SYSTEM_MEMORY_MAP

  LIST_ENTRY SpdDataListHead;

  ///
  /// Use below info. to be aware of max. number of Socket/Die/Channel/Dimm supported.
  /// Those are filled in by specific memory PEIMs.
  ///
  UINT8  MaxSocketSupported;          ///< Indicates max. socket supported
  UINT8  MaxDiePerSocket;             ///< Indicates max. die per socket
  UINT8  MaxChannelPerDie;            ///< Indicates max. channel per die
  UINT8  MaxDimmPerChannel;           ///< Indicates max. dimm per channel

  /// Dynamic data
  // Status reporting stuff
  UINT32 *DimmPresentMap;             ///< DimmPresentMap[MaxSocketSupported * MaxDiePerSocket]
                                      ///< Bit[1:0] - Dimm[1:0] of Channel0, .. , Bit[15:14] - Dimm[1:0] of Channel7
  MEM_CFG_INFO *ChipselIntlv;         ///< ChipselIntlv[MaxSocketSupported * MaxDiePerSocket * MaxChannelPerDie]
  MEM_CFG_INFO *DramEcc;              ///< DramEcc[MaxSocketSupported * MaxDiePerSocket]
  MEM_CFG_INFO *DramParity;           ///< DramParity[MaxSocketSupported * MaxDiePerSocket]
  MEM_CFG_INFO *AutoRefFineGranMode;  ///< AutoRefFineGranMode[MaxSocketSupported * MaxDiePerSocket]
  // Platform Tuning stuff

  /// Fixed data
  // Status reporting stuff
  MEM_CFG_INFO MbistTestEnable;       ///< MbistTestEnable
  MEM_CFG_INFO MbistAggressorEnable;  ///< MbistAggressorEnable
  MEM_CFG_INFO MbistPerBitSecondaryDieReport;  ///< MbistPerBitSecondaryDieReport
  MEM_CFG_INFO DramTempControlledRefreshEn;    ///< DramTempControlledRefreshEn
  MEM_CFG_INFO UserTimingMode;        ///< UserTimingMode
  MEM_CFG_INFO UserTimingValue;       ///< UserTimingValue
  MEM_CFG_INFO MemBusFreqLimit;       ///< MemBusFreqLimit
  MEM_CFG_INFO EnablePowerDown;       ///< EnablePowerDown
  MEM_CFG_INFO DramDoubleRefreshRate; ///< DramDoubleRefreshRate
  MEM_CFG_INFO PmuTrainMode;          ///< PmuTrainMode
  MEM_CFG_INFO EccSymbolSize;         ///< EccSymbolSize
  MEM_CFG_INFO UEccRetry;             ///< UEccRetry
  MEM_CFG_INFO IgnoreSpdChecksum;     ///< IgnoreSpdChecksum
  MEM_CFG_INFO EnableBankGroupSwapAlt;///< EnableBankGroupSwapAlt
  MEM_CFG_INFO EnableBankGroupSwap;   ///< EnableBankGroupSwap
  MEM_CFG_INFO DdrRouteBalancedTee;   ///< DdrRouteBalancedTee
  MEM_CFG_INFO NvdimmPowerSource;     ///< NvdimmPowerSource
  MEM_CFG_INFO OdtsCmdThrotEn;        ///< OdtsCmdThrotEn
  MEM_CFG_INFO OdtsCmdThrotCyc;       ///< OdtsCmdThrotCyc
} AMD_MEMORY_INIT_COMPLETE_PPI;

#define AMD_MEMORY_INIT_COMPLETE_REVISION   0x0001
#define AMD_MEMORY_INIT_COMPLETE_REV_0002   0x0002
#define AMD_MEMORY_INIT_COMPLETE_REV_0003   0x0003
#define AMD_MEMORY_INIT_COMPLETE_REV_0400   0x0400

//nhu typedef struct _AMD_MEMORY_TERMINATION_DATA_PPI {
//nhu   APOB_MEM_D5_BUS_CFG_INFO  DimmTermination[ABL_APOB_MAX_SOCKETS_SUPPORTED][ABL_APOB_MAX_CHANNELS_PER_SOCKET];
//nhu } AMD_MEMORY_TERMINATION_DATA_PPI;

/**
 * @brief Amd Memory Channel Translation Table Ppi
 */
typedef struct _AMD_MEMORY_CHANNEL_XLAT_PPI {
  UINT32                          Revision;                                              ///< revision
  VOID                            *XLatTab;                                              ///< Translation Table
} AMD_MEMORY_CHANNEL_XLAT_PPI;

#define AMD_MEMORY_CHANNEL_XLAT_REVISION   0x01

//----------------------------------------------------
//
//  Amd Memory Platform Configuration Ppi
//
//-------------------------------------------------------
typedef struct _AMD_AGESA_MEM_PLATFORM_CONFIGURATION_PPI {
  UINT32                          Revision;                                              ///< revision
  PSO_ENTRY                       *PlatformMemoryConfiguration;                          ///< Platform Memory Configurattion
} AMD_AGESA_MEM_PLATFORM_CONFIGURATION_PPI;

//----------------------------------------------------
//
// PEI_AMD_PLATFORM_DIMM_SPD_PPI data structure definition.
//
//-------------------------------------------------------
typedef struct _PEI_AMD_PLATFORM_DIMM_SPD_PPI PEI_AMD_PLATFORM_DIMM_SPD_PPI;

//----------------------------------------------------
//
// Defines function prototype for PlatformDimmSpdRead
//
//-------------------------------------------------------
typedef
EFI_STATUS
(EFIAPI *PEI_AMD_DIMM_SPD_READ) (
  IN      EFI_PEI_SERVICES                    **PeiServices,  ///< Pointer to PeiServices
  IN struct _PEI_AMD_PLATFORM_DIMM_SPD_PPI    *This,          ///< Pointer to the PPI structure
  IN OUT  AGESA_READ_SPD_PARAMS               *SpdData        ///< SPD Data Buffer
  );

//----------------------------------------------------
//
// PEI_AMD_PLATFORM_DIMM_SPD_PPI data structure definition.
//
//-------------------------------------------------------
struct _PEI_AMD_PLATFORM_DIMM_SPD_PPI {          // See the Forward Declaration above
  UINT8                                       TotalNumberOfSocket;    ///< Total Number of Physical Socket.
  UINT8                                       TotalNumberOfDimms;     ///< Total Number of DIMMS
  PEI_AMD_DIMM_SPD_READ                       PlatformDimmSpdRead;    ///< Function to be called
};

extern EFI_GUID gAmdMemoryBeforeDramInitPpiGuid;

/**
  Memory Before DRAM Init Interface

  Parameters:
  PeiServices

  Status Codes Returned:
  EFI_SUCCESS           - Return value is valid
  EFI_UNSUPPORTED       - This function is not supported by this version of the driver
**/
typedef EFI_STATUS (EFIAPI * PEI_AMD_MEMORY_BEFORE_DRAM_INIT_INTERFACE  ) (
  IN      EFI_PEI_SERVICES  **PeiServices
  );

//----------------------------------------------------
//
//  Amd Memory Before Dram Init Ppi
//
//-------------------------------------------------------
typedef struct _PEI_AMD_MEMORY_BEFORE_DRAM_INIT_PPI {
  UINT32                          Revision;                                              ///< revision
} PEI_BEFORE_DRAM_INIT_COMPLETE_PPI;

#define AMD_MEMORY_BEFORE_DRAM_INIT_REVISION   0x00

extern EFI_GUID gAmdMemoryAfterDramInitPpiGuid;

//----------------------------------------------------
//
//  Amd Memory After Dram Init Ppi
//
//-------------------------------------------------------
typedef struct _PEI_AMD_MEMORY_AFTER_DRAM_INIT_PPI {
  UINT32                          Revision;                                              ///< revision
} PEI_AFTER_DRAM_INIT_COMPLETE_PPI;

#define AMD_MEMORY_AFTER_DRAM_INIT_REVISION   0x00

extern EFI_GUID gAmdMemoryInitializeAgesaMemoryPpiGuid;

//----------------------------------------------------
//
//  Amd Memory Init Ppi
//
//-------------------------------------------------------
typedef struct _PEI_INITIALIZE_AGESA_MEMORY_PPI {
  UINT32                          Revision;                                              ///< revision
} PEI_INITIALIZE_AGESA_MEMORY_PPI;

#define AMD_MEMORY_INITIALIZE_AGESA_MEMORY_REVISION   0x00

extern EFI_GUID gAmdMemoryFamilyServicesPpiGuid;

//----------------------------------------------------
//
//  Amd Memory Family Services PPI
//
//-------------------------------------------------------
typedef struct _PEI_MEMORY_FAMILY_SERVICE_PPI {
  UINT32                          Revision;                                              ///< revision
  PEI_AMD_SOC_GET_MEMORY_ABOVE_4GB_INTERFACE   AmdGetMemoryAbove4gbFamilyService;        ///< Service to get memory above 4G
  PEI_AMD_SOC_GET_MEMORY_BELOW_4GB_INTERFACE   AmdGetMemoryBelow4gbFamilyService;        ///< Service to get memory below 4G
  PEI_AMD_SOC_GET_MEMORY_BELOW_1TB_INTERFACE    AmdGetMemoryBelow1TbFamilyService;       ///< Service to get memory below 1T
  PEI_AMD_SOC_GET_MEMORY_BOTTOM_IO_INTERFACE    AmdGetBottomIo1TbFamilyService;          ///< Service to get BottomIo
  PEI_AMD_SOC_GET_TOTAL_MEMORY_SIZE_INTERFACE   AmdGetTotalMemorySize4gbFamilyService;   ///< Service to get total memory
} PEI_MEMORY_FAMILY_SERVICE_PPI;

#define AMD_MEMORY_FAMILY_SERVICE_REVISION   0x00

//
// GUID definition
//

extern EFI_GUID gAmdMemoryPoolPointerTablePpiGuid;

//----------------------------------------------------
//
//  AMD memory tech Services PPI
//
//-------------------------------------------------------
typedef EFI_STATUS (EFIAPI * PEI_AMD_MEM_TECH_SERVICES_INTERFACE  ) (
  );
typedef struct _AMD_MEM_TECH_SERVICES_PPI {
  UINTN               Revision;                                   ///< Revision Number
  PEI_AMD_MEM_TECH_SERVICES_INTERFACE   AmdDimmPresenceService;   ///< Service to detect DIMM presence
} AMD_MEM_TECH_SERVICES_PPI;

// Current PPI revision
#define AMD_MEM_TECH_SERVICES_REVISION   0x00

extern EFI_GUID gAmdMemoryTecnologyPpiGuid;

//----------------------------------------------------
//
//  AMD memory tech PPI
//
//-------------------------------------------------------
typedef struct _PEI_MEMORY_TECHNOLOGY_PPI {
  UINTN               Revision;               ///< Revision Number
} PEI_MEMORY_TECHNOLOGY_PPI;

// Current PPI revision
#define AMD_MEMORY_TECHNOLOGY_REVISION   0x00

extern EFI_GUID gAmdMemoryAgesaReadSpdPpiGuid;

typedef EFI_STATUS (EFIAPI * PEI_AMD_MEMORY_AGESA_READ_SPD_INTERFACE  ) (
  );
//----------------------------------------------------
//
//  AMD memory Read SPD PPI
//
//-------------------------------------------------------
typedef struct _PEI_MEMORY_AGESA_READ_SPD_PPI {
  UINTN               Revision;                             ///< Revision Number
  PEI_AMD_MEMORY_AGESA_READ_SPD_INTERFACE   AgesaReadSpd;   ///< Service to read SPD
} PEI_MEMORY_AGESA_READ_SPD_PPI;

// Current PPI revision
#define AMD_MEMORY_AGESA_READ_SPD_REVISION   0x00

//----------------------------------------------------
//
// Defines function prototype to install Memory feature block
//
//-------------------------------------------------------
typedef
EFI_STATUS (*AMD_MEM_FEAT_ISNTALL_INTERFACE) (
  IN OUT     VOID*      MemFeatBlock                      ///< Memory feature block
  );
//----------------------------------------------------
//
//  AMD memory Install Feature PPI
//
//-------------------------------------------------------
typedef struct _AMD_AGESA_MEM_FEAT_INSTALL_PPI {
  UINT32                                Revision;                   ///< revision
  AMD_MEM_FEAT_ISNTALL_INTERFACE        Install;                    ///< Service to install memory feature block
} AMD_AGESA_MEM_FEAT_INSTALL_PPI;

// Current PPI revision
#define AMD_MEMORY_FEAT_INSTALL_REVISION   0x00

#endif


