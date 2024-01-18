/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APOB_H_
#define _APOB_H_

#include "APOBCMN.h"
#include "EnvironmentFlags.h"

/*----------------------------------------------------------------------------
 *   Mixed (DEFINITIONS AND MACROS / TYPEDEFS, STRUCTURES, ENUMS)
 *
 *----------------------------------------------------------------------------
 */

/*-----------------------------------------------------------------------------
 *                         DEFINITIONS AND MACROS
 *
 *-----------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------
 *                         TYPEDEFS, STRUCTURES, ENUMS
 *
 *----------------------------------------------------------------------------
 */
/**
 * @brief APOB Typedefs, Structures, and Enums
 *
 */

#define APOB_VERSION          0x0018      ///< AP0B Version
#define APOB_HEADER_OFFSET    0           ///< APOB Header Offset

#define ABL_APOB_MAX_SOCKETS_SUPPORTED   2   ///< Max number of sockets in system
#define ABL_APOB_MAX_DIES_PER_SOCKET     1   ///< Max dies per socket
#define ABL_APOB_MAX_CHANNELS_PER_SOCKET 12  ///< Max Channels per sockets
#define ABL_APOB_MAX_CHANNELS_PER_DIE    12  ///< Max channels per die
#define ABL_APOB_MAX_DIMMS_PER_CHANNEL   1   ///< Max dimms per die
#define ABL_APOB_MAX_CS_PER_CHANNEL      4   ///< Max CS per channel
#define MAX_PMU_SMB_SIZE  0x400              ///< Max PMU SMB size

#define MAX_APOB_ERROR_ENTRIES  64  ///< Max APOB Error Entries
#define MAX_DDR_PHY_ENTRY_SIZE  4   ///< Max DDR Phy Entry Size

/**
 * @brief Agesa APOB Defintions
 *
 */
#define ABL_APOB_HEADER_SIZE sizeof (APOB_HEADER)                       ///< APOB Header size in bytes
#define ABL_S3_RESTORE_DATA_HEADER_SIZE  sizeof (APOB_TYPE_HEADER)      ///< APOB Type Header size in bytes for S3 Restore
#define ABL_S3_RESTORE_DATA_REPLAY_BUFFER_SIZE  sizeof (REPLAY_BUFFER)  ///< Replay Buffer size in bytes for S3 Restore
#define ABL_S3_RESTORE_DATA_SIZE ABL_S3_RESTORE_DATA_HEADER_SIZE + ABL_S3_RESTORE_DATA_REPLAY_BUFFER_SIZE          ///< Total data size in bytes for S3 Restore
#define ABL_S3_PHY_RESTORE_DATA_SIZE (ABL_S3_RESTORE_DATA_HEADER_SIZE + ABL_S3_RESTORE_DATA_REPLAY_BUFFER_SIZE)*5  ///< Total data size in bytes for S3 Phy Restore
#define ABL_MEM_GEN_ERROR_SIZE sizeof (APOB_MEM_GENERAL_ERRORS_TYPE_STRUCT)                           ///< Size of APOB_MEM_GENERAL_ERRORS_TYPE_STRUCT in bytes
#define ABL_MEM_SOC_INIT_CONFIG_SIZE sizeof (APOB_MEM_SOC_INIT_CONFIG_STRUCT)                         ///< Size of APOB_MEM_SOC_INIT_CONFIG_STRUCT in bytes
#define ABL_MEM_RMP_INFO_SIZE  sizeof (APOB_MEM_RMP_INFO_STRUCT)                                      ///< Size of APOB_MEM_RMP_INFO_STRUCT in bytes
#define ABL_MEM_GEN_CONFIG_SIZE sizeof (APOB_MEM_GENERAL_CONFIGURATION_INFO_TYPE_STRUCT)              ///< Size of APOB_MEM_GENERAL_CONFIGURATION_INFO_TYPE_STRUCT in bytes
#define ABL_MEM_SYS_CONFIG_SIZE sizeof (APOB_MEM_SYSTEM_CONFIGURATION_INFO_TYPE_STRUCT)               ///< Size of APOB_MEM_SYSTEM_CONFIGURATION_INFO_TYPE_STRUCT in bytes
#define ABL_GEN_INFO_SIZE sizeof (APOB_D5_GEN_INFO_TYPE_STRUCT)                                       ///< Size of APOB_D5_GEN_INFO_TYPE_STRUCT in bytes
#define ABL_MEM_PMU_SMB_SIZE sizeof (APOB_PMU_SMB_TYPE_STRUCT)                                        ///< Size of APOB_PMU_SMB_TYPE_STRUCT in bytes
#define ABL_MEM_MBIST_RESULT_SIZE sizeof (APOB_MBIST_STATUS_TYPE_STRUCT)                              ///< Size of APOB_MBIST_STATUS_TYPE_STRUCT in bytes
#define ABL_SYS_MAP_SIZE APOB_SYS_MAP_STRUCT_SIZE + sizeof (APOB_TYPE_HEADER)                         ///< Size in bytes of the System Map struct and APOB Type Header
#define ABL_SYS_NPS_INFO_SIZE sizeof (APOB_SYSTEM_NPS_INFO_TYPE_STRUCT)                               ///< Size of APOB_SYSTEM_NPS_INFO_TYPE_STRUCT in bytes
#define ABL_SYS_SLINK_INFO_SIZE sizeof (APOB_SYSTEM_SLINK_INFO_TYPE_STRUCT)                           ///< size of APOB_SYSTEM_SLINK_INFO_TYPE_STRUCT in bytes
#define ABL_DF_DXIO_PHY_FW_OVERRIDE_TABLE_SIZE sizeof (APOB_DF_DXIO_PHY_FW_OVERRIDE_TABLE_STRUCT)     ///< Size of APOB_DF_DXIO_PHY_FW_OVERRIDE_TABLE_STRUCT in bytes
#define ABL_CCX_LOGICAL_TO_PHYSICAL_MAP_SIZE (sizeof (APOB_CCX_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT))  ///Size of APOB_CCX_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT in bytes
#define ABL_CCD_LOGICAL_TO_PHYSICAL_MAP_SIZE (sizeof (APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT))  ///< Size of APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT in bytes
#define ABL_EVENT_LOG_SIZE  (sizeof (EVENT_LOG_STRUCT))                                               ///< Size of EVENT_LOG_STRUCT in bytes
#define ABL_DIMM_SMBUS_INFO_SIZE  (sizeof (APOB_MEM_DIMM_SMBUS_INFO_TYPE_STRUCT))                     ///< Size of APOB_MEM_DIMM_SMBUS_INFO_TYPE_STRUCT in bytes
/**
 * @brief Max number of DIMMs based on the max number of sockets, dies per socket, channels per die, and DIMMs per channel
 *
 */
#define ABL_MAX_DIMMS (ABL_APOB_MAX_SOCKETS_SUPPORTED * ABL_APOB_MAX_DIES_PER_SOCKET * ABL_APOB_MAX_CHANNELS_PER_DIE * ABL_APOB_MAX_DIMMS_PER_CHANNEL)
/**
 * @brief SMBIOS Memory info size based on Mem DMI Header size and max number of DIMMs multiplied by the sizes of the Mem DMI physical and logical DIMM structs
 *
 */
#define ABL_MEM_SMBIOS_INFO_SIZE  (sizeof (APOB_MEM_DMI_HEADER) + ABL_MAX_DIMMS * (sizeof (APOB_MEM_DMI_PHYSICAL_DIMM) + sizeof (APOB_MEM_DMI_LOGICAL_DIMM)))
#define ABL_MEM_NVDIMM_INFO_SIZE (sizeof (APOB_MEM_NVDIMM_INFO_STRUCT))     ///< Size of APOB_MEM_NVDIMM_INFO_STRUCT in bytes
#define ABL_APOB_APCB_BOOT_INFO_SIZE (sizeof (APOB_APCB_BOOT_INFO_STRUCT))  ///< Size of APOB_APCB_BOOT_INFO_STRUCT in bytes
/**
 * @brief The master APOB size based on the APOB header and all APOB structs
 *
 */
#define MAX_MASTER_APOB_SIZE  ABL_APOB_HEADER_SIZE + \
                                ABL_MEM_GEN_ERROR_SIZE + \
                                ABL_MEM_GEN_CONFIG_SIZE + \
                                ABL_MEM_SYS_CONFIG_SIZE + \
                                ABL_GEN_INFO_SIZE + \
                                ABL_S3_RESTORE_DATA_SIZE + \
                                ABL_MEM_PMU_SMB_SIZE + \
                                ABL_CCX_LOGICAL_TO_PHYSICAL_MAP_SIZE + \
                                ABL_EVENT_LOG_SIZE + \
                                ABL_MEM_SMBIOS_INFO_SIZE + \
                                ABL_S3_PHY_RESTORE_DATA_SIZE + \
                                ABL_MEM_NVDIMM_INFO_SIZE + \
                                ABL_MEM_RMP_INFO_SIZE
#define MAX_SECONDARY_APOB_SIZE (MAX_MASTER_APOB_SIZE - ABL_APOB_HEADER_SIZE)   ///< The secondary APOB size based on the all APOB structs (not including the APOB header)
/**
 * @brief Maximum APOB size based off one master and the max number of secondaries using the max number of sockets and dies per socket
 *
 */
#define MAX_APOB_SIZE MAX_MASTER_APOB_SIZE + MAX_SECONDARY_APOB_SIZE*ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET
#define COMMON_INFO_ARRAY_OFFSET  ABL_APOB_HEADER_SIZE + ABL_SYS_MAP_SIZE   ///< APOB Header size and System Map size

/**
 * @brief APOB Group Definitons
 *
 */
#define APOB_MEM      1  ///< APOB Group ID for Memory
#define APOB_DF       2  ///< APOB Group ID for DF
#define APOB_CCX      3  ///< APOB Group ID for CCX
#define APOB_GNB      4  ///< APOB Group ID for GNB
#define APOB_FCH      5  ///< APOB Group ID for FCH
#define APOB_PSP      6  ///< APOB Group ID for PSP
#define APOB_GEN      7  ///< APOB Group ID for General Info
#define APOB_SMBIOS   8  ///< APOB Group ID for SMBIOS
#define APOB_FABRIC   9  ///< APOB Group ID for Fabric/System Memory Map

/**
 * @brief APOB Type Definitions
 *
 */
#define APOB_MEM_GENERAL_ERRORS_TYPE   1              ///< Memory General Erros APOB Data Type
#define APOB_MEM_GENERAL_CONFIGURATION_INFO_TYPE   2  ///< Memory General Config Info APOB Data Type
#define APOB_GEN_CONFIGURATION_INFO_TYPE   3          ///< General Config Info APOB Data Type
#define APOB_GEN_S3_REPLAY_BUFFER_INFO_TYPE   4       ///< S3 Replay Buffer Info APOB Data Type
#define APOB_MEM_PMU_SMB_TYPE   5                     ///< PMU SMB APOB Data Type
#define APOB_GEN_EVENT_LOG_TYPE   6                   ///< Event Log APOB Data Type
#define APOB_MEM_DIMM_SMBUS_INFO_TYPE   7             ///< DIMM SMBUS Info APOB Data Type
#define APOB_MEM_SMBIOS_TYPE  8                       ///< SMBIOS Info APOB Data Type
#define APOB_SYS_MAP_INFO_TYPE   9                    ///< System Map Info APOB Data Type
#define APOB_MEM_NVDIMM_INFO_TYPE   15                ///< NVDIMM address range and size Info APOB Data Type
#define APOB_APCB_BOOT_INFO_TYPE    16                ///< APCB Boot Info APOB Data Type
#define APOB_MEM_DIMM_SPD_DATA_TYPE     17            ///< DIMM SPD data APOB Data Type
#define APOB_MEM_MBIST_RESULT_INFO_TYPE 18            ///< MBIST Results Info APOB Data Type
#define APOB_SYS_NPS_INFO_TYPE   19                   ///< System NPS Info APOB Data Type
#define APOB_SYS_SLINK_INFO_TYPE   20                 ///< System Slink Info APOB Data Type
#define APOB_DF_DXIO_PHY_FW_OVERRIDE_INFO_TYPE 21     ///< DF DXIO Phy FW Override Table Info APOB Data Type

#define APOB_MEM_S3_DDR_PHY_REPLAY_PHASE0_BUFFER_INFO_TYPE   30  ///< DDR Phy Settings APOB Data Type
#define APOB_MEM_S3_DDR_PHY_REPLAY_MAX_ENTRIES               10  ///< Max number of entries for DDR Phy Settings

/**
 * @brief
 *
 */
#define APOB_CCX_LOGICAL_TO_PHYSICAL_MAP_TYPE  1  ///< CCX Logical to Physical Map APOB Data Type
#define APOB_CCX_EDC_THROTTLE_THRESH_TYPE      2  ///< CCX EDC Throttle Threshold APOB Data Type
#define APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE  3  ///< CCD Logical to Physical Map APOB Data Type


#define APOB_SYS_MAP_STRUCT_SIZE sizeof (SYSTEM_MEMORY_MAP) + (17 * sizeof (MEMORY_HOLE_DESCRIPTOR))  ///< System Memory Map struct size in bytes including max number of Memory Hole structs

/**
 * @brief AMD APOB_HEADER Header
 * @details Contains offsets for accessing the different APOB data types
 *
 */
typedef struct {
  UINT32   Signature;                      ///< APOB signature
  UINT32   Version;                        ///< Version
  UINT32   Size;                           ///< APOB Size
  UINT32   OffsetOfFirstEntry;             ///< APOB Header Size
  UINT32   SysMapOffset;                   ///< System Map Info [Master Only]
  UINT32   MemSmbiosOffset;                ///< Memory SMBIOS Buffer Type Offset [Master Only]
  UINT32   NvdimmInfoOffset;               ///< NVDIMM Info
  UINT32   ApobApcbBootInfoOffset;         ///< APOB Boot Info to report RecoveryFlag and ActiveInstance
  UINT32   SysNpsOffset;                   ///< System NPS Info [Master Only]
  UINT32   SysSLinkOffset;                 ///< System SLink Info [Master Only]
  UINT32   DfDxioPhyFwOverrideInfoOffset;  ///< DF DXIO Phy FW Override Info [Master Only]
  UINT32   Reserved[1];  ///< Reserved for alignment purposes
  UINT32   MemConfigOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];   ///< Memory Configuration Buffer Type Offset
  UINT32   MemErrorOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];    ///< Memory Error Buffer Type Offset
  UINT32   GenConfigOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];   ///< General Configuration Buffer Type Offset
  UINT32   ReplayBuffOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];  ///< Replay Buffer Offset
  UINT32   MemPmuSmbOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];   ///< Memroy PMU SMB Offset
  UINT32   CcxLogToPhysMapOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];         ///< CCX Map Offset
  UINT32   CcxEdcThrottleThreshOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];    ///< CCX EDC Threshold Offset
  UINT32   CcdLogToPhysMapOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];         ///< CCD Map Offset
  UINT32   EventLogOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];    ///< Event log Offset
  UINT32   MemSpdDataOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];  ///< Memory SPD data Buffer Type Offset
  UINT32   DdrPhyReplayBuffPhaseOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET][APOB_MEM_S3_DDR_PHY_REPLAY_MAX_ENTRIES];  ///< DDR Phy Replay Buffer Offset
  UINT32   ApobMbistTestResultsOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];    ///< MBIST Test Results
  UINT32   MemPmuTrainingFailureOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];   ///< Memory PMU training failure info
  UINT32   MemSocInitConfigOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET];    ///< Memory SOC Init Config Buffer Type Offset
  UINT32   MopArrayReplayBuffChannelOffset[ABL_APOB_MAX_SOCKETS_SUPPORTED*ABL_APOB_MAX_DIES_PER_SOCKET][APOB_MEM_S3_MOP_ARRAY_REPLAY_MAX_ENTRIES]; ///< DDR MOP Array Replay Buffer Type Offset
  APOB_HMAC ApobHeaderHmac;                    ///< Hmac location for type
} APOB_HEADER;

/**
 * @brief AMD APOB_TYPE ENTRY
 *
 */
typedef struct {
  APOB_TYPE_HEADER typeHeader;  ///< APOB Type header
  UINT32  *Source;              ///< Entry Source
  UINT32  Destination;          ///< Entry Destination
} APOB_TYPE_ENTRY;

/**
 * @brief AMD APOB_MEM_GENERAL_ERRORS Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;  ///< APOB Type Header
  BOOLEAN GsbMTRRshort;              ///< Ran out of MTRRs while mapping memory
  BOOLEAN GsbAllECCDimms;            ///< All banks of all Nodes are ECC capable
  BOOLEAN GsbDramECCDis;             ///< Dram ECC requested but not enabled.
  BOOLEAN GsbSoftHole;               ///< A Node Base gap was created
  BOOLEAN GsbHWHole;                 ///< A HW dram remap was created
  BOOLEAN GsbNodeIntlv;              ///< Node Memory interleaving was enabled
  BOOLEAN GsbSpIntRemapHole;         ///< Special condition for Node Interleave and HW remapping
  BOOLEAN GsbEnDIMMSpareNW;          ///< Indicates that DIMM Spare can be used without a warm reset
} APOB_MEM_GENERAL_ERRORS_TYPE_STRUCT;

/**
 * @brief AMD APOB_MBIST_MARGIN structure
 *
 */
typedef struct _APOB_MBIST_MARGIN {
  UINT8  PositiveEdge;  ///< Positive edge margin
  UINT8  NegativeEdge;  ///< Negative edge margin
} APOB_MBIST_MARGIN;

/**
 * @brief AMD APOB_MBIST_DATA_EYE_MARGIN
 *
 */
typedef struct _APOB_MBIST_DATA_EYE_MARGIN {
  APOB_MBIST_MARGIN  ReadDqDelay;    ///< Smallest Positive and Negative Read Dq Delay margin
  APOB_MBIST_MARGIN  ReadVref;       ///< Smallest Positive and Negative Read Vref delay
  APOB_MBIST_MARGIN  WriteDqDelay;   ///< Smallest Positive and Negative Write Dq Delay margin
  APOB_MBIST_MARGIN  WriteVref;      ///< Smallest Positive and Negative Write Vref delay
} APOB_MBIST_DATA_EYE_MARGIN;

/**
 * @brief AMD APOB_MBIST_DATA_EYE_RECORD
 *
 */
typedef struct _APOB_MBIST_DATA_EYE_RECORD {
  BOOLEAN                      DataEyeValid;   ///< Indicates if data eye is valid
  APOB_MBIST_DATA_EYE_MARGIN   DataEyeRecord;  ///< Structure containing data eye margin data
} APOB_MBIST_DATA_EYE_RECORD;

#define APOB_MBIST_SUBTESTS 5  ///< Number of MBIST Subtests

/**
 * @brief AMD MBIST STATUS STRUCTURE Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                                                    ///< APOB Type Header
  UINT8           ResultValid [APOB_MBIST_SUBTESTS][ABL_APOB_MAX_CHANNELS_PER_DIE];    ///< ErrorStatus valid per Chip Select
                                                                                       ///<    For Each Bit, 0...3
                                                                                       ///<      0 = Chip select was not tested
                                                                                       ///<      1 = Chip select was tested
                                                                                       ///<    Bits 7:4 Reserved
  UINT8             ErrorStatus [APOB_MBIST_SUBTESTS][ABL_APOB_MAX_CHANNELS_PER_DIE];  ///< Error Status per Chip Select
                                                                                       ///<    For Each Bit, 0...3
                                                                                       ///<      0 = Chip select Passed
                                                                                       ///<      1 = Chip Select Failed
                                                                                       ///<    Bits 7:4 Reserved
  APOB_MBIST_DATA_EYE_RECORD  ApobDataEyeRecord[ABL_APOB_MAX_CHANNELS_PER_DIE][ABL_APOB_MAX_CS_PER_CHANNEL];  ///< Data eye information per chipselect
} APOB_MBIST_STATUS_TYPE_STRUCT;

/// AMD APOB_GEN_CONFIGURATION_INFO Header
/**
 * @brief DDR Post Package Repair
 *
 */
#define APOB_STATUS_REPAIR_FAIL 0                      ///< Post Package Repair failed
#define APOB_STATUS_REPAIR_PASS 1                      ///< Post Package Repair was successful

#define APOB_STATUS_REPAIR_RANK_MISS_MATCH_ERROR 2     ///< Post Package Repair Error, Rank is valid, but did not match an installed rank
#define APOB_STATUS_REPAIR_RANK_INVALID_ERROR 4        ///< Post Package Repair Error, Rank is not valid
#define APOB_STATUS_REPAIR_BANK_INVALID_ERROR  8       ///< Post Package Repair Error, Bank is not valid
#define APOB_STATUS_REPAIR_SOCKET_INVALID_ERROR   0x10  ///< Post Package Repair Error, Socket is not valid
#define APOB_STATUS_REPAIR_CHANNEL_INVALID_ERROR  0x20  ///< Post Package Repair Error, Channel is not valid
#define APOB_STATUS_REPAIR_DEVICE_INVALID_ERROR   0x40  ///< Post Package Repair Error, Device is not valid
#define APOB_STATUS_REPAIR_DEVICE_MISSMATCH_ERROR 0x80  ///< Post Package Repair Error, Device missmatch

#define APOB_DPPR_VALID_REPAIR 1                        ///< DDR Post Package Repair Valid repair
#define APOB_DPPR_INVALID_REPAIR 0                      ///< DDR Post Package Repair Invalid repair

#define APOB_DPPR_SOFT_REPAIR 0                         ///< DDR Post Package Repair Soft repair
#define APOB_DPPR_HARD_REPAIR 1                         ///< DDR Post Package Repair Hard repair
#define APOB_DPPR_PMU_BIST_SOFT_REPAIR 2                ///< DDR Post Package Repair PMU BIST Soft repair
#define APOB_DPPR_PMU_BIST_HARD_REPAIR 3                ///< DDR Post Package Repair PMU BIST Hard repair

#define APOB_DPPR_RESULTS_VALID 1                       ///< DDR Post Package Repair Results valid
#define APOB_DPPR_RESULTS_INVALID 0                     ///< DDR Post Package Repair Results invalid

#define APOB_MAX_DPPRCL_ENTRY 64                        ///< Max post package repair list entires
#define APOB_MAX_DPPRCL_SOCKETS 1                       ///< Max post package repair list sockets
#define APOB_MAX_DPPRCL_CHANNELS 1                      ///< Max post package repair list channels

#define APOB_MAX_DPPRCL_ENTRIES APOB_MAX_DPPRCL_SOCKETS*APOB_MAX_DPPRCL_CHANNELS  ///< Max post package repair list entries based on max sockets and channels

/**
 * @brief The following defintion represent cause of error which initiated
 * Post Package Repair.
 */
typedef enum {
  PPR_ECC = 1,
  PPR_CECC_STORM,
  PPR_UECC_DEFER,
  PPR_UECC_CONSUME,
  PPR_UECC_STORM,
} ERROR_CAUSE_FOR_POST_PACKAGE_REPAIR;

/**
 * @brief The following defintion indicates whether Post Package Repair is for
 * DDR or HBM device
 */
typedef enum {
  DeviceTypeRepairedDdr = 0,
  DeviceTypeRepairedHbm,
  DeviceTypeRepairedReserved1,
  DeviceTypeRepairedReserved2,
} DEVICE_TYPE_RAPAIRED;

/**
 * @brief Post Package Repair List Entry struct
 *
 */
typedef union DPPRCL_REPAIR_REPORT_ENTRY_V2 {
  struct {
    UINT32 Valid: 1 ;                     ///< [0:0] Valid entry
    UINT32 Status: 8 ;                    ///< [8:1] Status
    UINT32 RepairType: 3 ;                ///< [11:9] Repair Type 0 - Soft PPR, 1 - Hard PPR,
                                          ///< 2 - PMU BIST Soft PPR, 3 - PMU BIST Hard PPR
    UINT32 ErrorCause: 3 ;                ///< [14:12] Cause of error which initiated this repair
    UINT32 DeviceTypeRepaired : 2;        ///< [16:15] Device Type which was repaird. 0  - DDR, 1 - HBM, 2 and 3 reserved
                                          ///< for future
    UINT32 DeviceWidth: 5 ;               ///< [21:17] Device WIdth
    UINT32 TargetDevice: 5 ;              ///< [26:22] Target Device
    UINT32 BankAddress: 5 ;               ///< [31:27] Bank Address

    UINT32 Socket: 3 ;                    ///< [2:0] Socket Number
    UINT32 Channel: 4 ;                   ///< [6:3] DDR Channel
    UINT32 SubChannel: 1 ;                ///< [7:7] Sub Channel 0 - Subchannel A, 1 - Subchannel B
    UINT32 ChipSelect: 2 ;                ///< [9:8] ChipSelect 0 -3
    UINT32 RankMultiplier: 3 ;            ///< [12:10] Rank Multiplier
    UINT32 RowAddress: 18 ;               ///< [30:13] RowAddress
    UINT32 Reserved_1: 1 ;                ///< [31:31] Reserved
} ddr;
  struct {
    UINT32 Valid: 1 ;                     ///< [0:0] Valid entry
    UINT32 Status: 8 ;                    ///< [8:1] Status
    UINT32 RepairType: 3 ;                ///< [11:9] Repair Type 0 - Soft PPR, 1 - Hard PPR,
                                          ///< 2 - PMU BIST Soft PPR, 3 - PMU BIST Hard PPR
    UINT32 ErrorCause: 3 ;                ///< [14:12] Cause of error which initiated this repair
    UINT32 DeviceTypeRepaired : 2;        ///< [16:15] Device Type which was repaird. 0  - DDR, 1 - HBM, 2 and 3 reserved
                                          ///< for future
    UINT32 Socket : 3;                    ///< [19:17] Socket
    UINT32 Channel : 4;                   ///< [23:20] Channel
    UINT32 SubChannel : 1;                ///< [24:24] SubChannel (DDR5)
    UINT32 MfrId : 4;                     ///< [2:25] Manufacturer Id
    UINT32 Reserved_0 : 3;                ///< [31:29] MBZ

    UINT32 BankAddress: 5 ;               ///< [4:0] Bank Address
    UINT32 Column : 5;                    ///< [9:5] Column Address
    UINT32 Row : 15;                      ///< [24:10] Row Address
    UINT32 Reserved_1:7;                  ///< [31:25] Reserved for hbm PPR repair update
  } hbm;
} DPPRCL_REPAIR_REPORT_ENTRY_V2;

/**
 * @brief Post Package Repair List
 * @details Contains all Post Package Repair List Entries
 *
 */
typedef struct _APOB_DPPRCL_STRUCT_V2{
  DPPRCL_REPAIR_REPORT_ENTRY_V2 DppRclReportEntry[APOB_MAX_DPPRCL_ENTRY];
} APOB_DPPRCL_STRUCT_V2;

/**
 * @brief DDR Post Package Repair Struct
 *
 */
typedef struct _APOB_DPPR_STRUCT_V2 {
  BOOLEAN  PprResultsValid;          /// Indicates that the PPR results are valid
  UINT8    Reserved;
  UINT16   Reserved1;
  APOB_DPPRCL_STRUCT_V2 Channel[APOB_MAX_DPPRCL_ENTRIES];
} APOB_DPPR_STRUCT_V2;

/**
 * @brief Interleaving settings
 *
 */
typedef union {
  /**
   * @brief Bitfields of Interleaving Settings
   *
   */
  struct {
    UINT32 ChannelIntlv:8;  ///< Bit map for channel interleave setting
    UINT32 DieIntlv:2;      ///< Bit map for die interleave setting
    UINT32 SocketIntlv:1;   ///< Socket interleave setting
    UINT32 :21;             ///< Reserved
  } Field;
  UINT32  Value;  ///< Interleaving Settings as 32 bit value
} INTLV_SETTING;

/**
 * @brief APOB Memory Config Info
 *
 */
typedef struct _APOB_MEM_CFG_INFO {
  /**
   * @brief Union for status enabled flag or configured status value
   *
   */
  union {
    BOOLEAN Enabled;      ///< Status.Enabled - TRUE: Enabled.
    UINT16 Value;         ///< Status.Value - Configured value.
  } Status;
  UINT16 StatusCode;      ///< Status Code.
} APOB_MEM_CFG_INFO;

/**
 * @brief DDR5 Bus Config Info
 *
 */
typedef struct {
  BOOLEAN  DimmPresent;     ///< DIMM Present flag
  UINT8  CaTimingMode;      ///< CaTimingMode
  UINT8  Dimm0_RttNomWr;    ///< DIMM 0, RTT_NOM_WR
  UINT8  Dimm0_RttNomRd;    ///< DIMM 0, RTT_NOM_RD
  UINT8  Dimm0_RttWr;       ///< DIMM 0, RTT_WR
  UINT8  Dimm0_RttPark;     ///< DIMM 0, RTT_PARK
  UINT8  Dimm0_DqsRttPark;  ///< DIMM 0, RTT_DQS_RTT_PARK
  UINT8  Dimm1_RttNomWr;    ///< DIMM 0, RTT_NOM_WR
  UINT8  Dimm1_RttNomRd;    ///< DIMM 0, RTT_NOM_RD
  UINT8  Dimm1_RttWr;       ///< DIMM 0, RTT_WR
  UINT8  Dimm1_RttPark;     ///< DIMM 0, RTT_PARK
  UINT8  Dimm1_DqsRttPark;  ///< DIMM 0, RTT_DQS_RTT_PARK
  UINT8  DramDrv;           ///< DRAM_DRV
  UINT8  CkOdtA;            ///< GroupA, CK_ODT
  UINT8  CsOdtA;            ///< GroupA, CS_ODT
  UINT8  CaOdtA;            ///< GroupA, CA_ODT
  UINT8  CkOdtB;            ///< GroupB, CK_ODT
  UINT8  CsOdtB;            ///< GroupB, CS_ODT
  UINT8  CaOdtB;            ///< GroupB, CA_ODT
  UINT8  Proc_Odt;          ///< CPU, PODT
  UINT8  Proc_DqDrv;        ///< CPU, DQ_Drv
  UINT8  Proc_AlertPu;      ///< CPU, Alert Pullup
  UINT8  Proc_CaDrv;        ///< CPU, CA_Drv
  UINT8  PhyVref;           ///< PHY Vref
  UINT8  DqVref;            ///< DQ Vref
  UINT8  CaVref;            ///< CA Vref
  UINT8  CsVref;            ///< CS Vref
  UINT8  RxDfe;             ///< Rx DFE
  UINT8  TxDfe;             ///< Tx DFE
} APOB_MEM_D5_BUS_CFG_INFO;

/**
 * @brief APOB Memory General Config Info Struct
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                        ///< APOB Type Header
  UINT32 BootMediaTypeInfo;                                ///< BootMediaTypeInfo
  UINT16 MemClkFreq;                                       ///< Data from MemClkFreq: 667/800/933/1067/1200/1333/1467/1600 Mhz
  UINT16 DdrMaxRate;                                       ///< UMC DdrMaxRate
  BOOLEAN EccEnable [ABL_APOB_MAX_CHANNELS_PER_DIE];       ///< ECC enabled or Disabled per channel. ie. Channel 0 or Channel 1
  BOOLEAN NvDimmInstalled[ABL_APOB_MAX_CHANNELS_PER_DIE];  ///< NVDIMM presence per channel. ie. Channel 0 or Channel 1
  BOOLEAN ChannelIntlvEn;                                  ///< DIMM channel interleave status
  UINT8  Reserved1[7];  ///< Reserved
  APOB_DPPR_STRUCT_V2 DdrPostPackageRepair;          ///< DDR Post package repaair
  OUT
  INTLV_SETTING InterLeaveCurrentMode;            ///< Current interleave mode
  OUT
  INTLV_SETTING InterLeaveCapability;             ///< Capability of interleave
  OUT
  UINT32 InterLeaveSize;                          ///< Interleaving size
  UINT32 DimmSize[ABL_APOB_MAX_CHANNELS_PER_DIE][ABL_APOB_MAX_DIMMS_PER_CHANNEL];  ///< 2d array of DIMM sizes per channel per die
  APOB_MEM_CFG_INFO ChipselIntlv[ABL_APOB_MAX_CHANNELS_PER_DIE];                   /// Chipselect interleaving per channel
  APOB_MEM_CFG_INFO DramEcc;                      ///< DRAM ECC Configuration
  APOB_MEM_CFG_INFO DramParity;                   ///< DRAM Parity Configuration
  APOB_MEM_CFG_INFO AutoRefFineGranMode;          ///< AutoRefresh Fine Granularity Mode Configuration
  APOB_MEM_CFG_INFO MbistTestEnable;              ///< MBIST Test Enable Configuration
  APOB_MEM_CFG_INFO MbistAggressorEnable;         ////< MBIST Aggressor Enable Configuration
  APOB_MEM_CFG_INFO MbistPerBitSecondaryDieReport;///< MBIST Per Bit Secondary Die Report Configuration
  APOB_MEM_CFG_INFO DramTempControlledRefreshEn;  ///< DRAM Temperature Controlled Refresh Configuration
  APOB_MEM_CFG_INFO UserTimingMode;               ///< User Timing Mode Configuration
  APOB_MEM_CFG_INFO UserTimingValue;              ///< User Timing Value Configuration
  APOB_MEM_CFG_INFO MemBusFreqLimit;              ///< Memory Bus Frequency Limit Configuration
  APOB_MEM_CFG_INFO EnablePowerDown;              ///< Enable Power Down Configuration
  APOB_MEM_CFG_INFO DramDoubleRefreshRate;        ///< DRAM Double Refresh Rate Configuration
  APOB_MEM_CFG_INFO PmuTrainMode;                 ///< PMU Training Mode Configuration
  APOB_MEM_CFG_INFO EccSymbolSize;                ///< ECC Symbol Size Configuration
  APOB_MEM_CFG_INFO UEccRetry;                    ///< Uncorrectable ECC Retry Configuration
  APOB_MEM_CFG_INFO IgnoreSpdChecksum;            ///< Ignore SPD Checksum Configuration
  APOB_MEM_CFG_INFO EnableBankGroupSwapAlt;       ///< Bank Group Swap Alt Control Configuration
  APOB_MEM_CFG_INFO EnableBankGroupSwap;          ///< Bank Group Swap Control Configuration
  APOB_MEM_CFG_INFO DdrRouteBalancedTee;          ///< Motherboard DDR Routing Configuration
  APOB_MEM_CFG_INFO NvdimmPowerSource;            ///< NVDIMM Power Source Configuration 1: device, 2: host
  APOB_MEM_CFG_INFO OdtsCmdThrotEn;               ///< ODTS Command Throttle Configuration
  APOB_MEM_CFG_INFO OdtsCmdThrotCyc;              ///< ODTS Command Throttle Cycle Configuration
} APOB_MEM_GENERAL_CONFIGURATION_INFO_TYPE_STRUCT;

/**
 * @brief APOB Memory System Config Info
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;  ///< APOB Type Header
  APOB_MEM_D5_BUS_CFG_INFO ChannelBusCfgInfo[ABL_APOB_MAX_CHANNELS_PER_DIE];  ///< Channel Bus Config Info per Channel
} APOB_MEM_SYSTEM_CONFIGURATION_INFO_TYPE_STRUCT;

/**
 * @brief Memory Termination Data
 *
 */
typedef struct _AMD_MEMORY_TERMINATION_DATA_PPI {
  APOB_MEM_D5_BUS_CFG_INFO  DimmTermination[ABL_APOB_MAX_SOCKETS_SUPPORTED][ABL_APOB_MAX_CHANNELS_PER_SOCKET];  ///< DIMM Termination Info per channel per socket
} AMD_MEMORY_TERMINATION_DATA_PPI;

/**
 * @brief AMD APOB_GEN_INFO_PARAMETER_INFO_STRUCT
 * @details This structure passes parameter information from ABL cold to ABL Warm/Resume
 *
 */
typedef struct {
  UINT32  ApobUniqueApcbInstance;  ///< UniuweApcbInstance to ensure
                                   ///< compatibitly for giveen flshed BIOS lifecycle
  BOOLEAN ApobAblRestoreControl;   ///< This field indicates if ABL should perform a restore
  UINT8 SubProgram;                ///< Subprogram in PSP dir
  UINT16 BoardMask;                ///< Board Mask
  UINT32 Reserved1;                ///< Reserved for alignment
} APOB_GEN_INFO_PARAMETER_INFO_STRUCT;

/**
 * @brief AMD APOB_GEN_INFO_ERROR_INFO_STRUCT
 * @details This structure passes Error information from ABL cold to ABL Warm/Resume
 *
 */
typedef struct {
  BOOLEAN ApobErrorReportPortReportingEnable;  ///< Indicates if ABL will report errors via a port
                                               ///< TRUE - Error logging will be reported via a port
                                               ///< FALSE - Error logging will not be reported via a port
  IN
  BOOLEAN  ApobErrorReportUsingHandshakeEnable;  ///< This flag indicates if the ABL will use an handshake for the Error Log
                                                 ///< TRUE - Error log reported using a handshake with the "ErrorLogOutputPort" and "ErrorLogInputPort"
                                                 ///< FALSE - Error log reported using "ErrorLogOutputPort" only with each DWORD in log delayed by
                                                 ///<         ErrorLogOutputDwordDelay
  OUT
  UINT16 Reserved1;  ///< Reserved for alignment
  IN
  UINT32  ApobErrorReportInputPort;              ///< Input Port to receive ABL Error information
                                                 ///< (only valid if ReportErrorLogUsingHandshakeEnable = TRUE)
  IN
  UINT32  ApobErrorReportOutputDwordDelay;       ///< Number of "10ns" to wait before sending the next Log Dword informaiton via "ErrorLogOutputPort"
                                                 ///< (only valid if ReportErrorLogUsingHandshakeEnable = FALSE)
  IN
  UINT32  ApobErrorReportOutputPort;             ///< Output Port for ABL Error information
  IN
  BOOLEAN ApobErrorReportStopOnFirstFatalErrorEnable;  ///< Indicates that ABL will stop on the first fatal error
                                                       ///< TRUE - Stop and report the first FATAL error
                                                       ///< FALSE - Report all errors
  OUT
  UINT8 Reserved2;   ///< Reserved for alignment
  OUT
  UINT16 Reserved3;  ///< Reserved for alignment
  IN
  UINT32  ApobErrorReportInputPortSize;         ///< Indicates the size of the input and outut port
                                                ///< 1 - 8 bit port
                                                ///< 2 - 16 bit port
                                                ///< 4 - 32 bit port
  IN
  UINT32  ApobErrorReportOutputPortSize;        ///< Indicates the size of the input and outut port
                                                 ///< 1 - 8 bit port
                                                ///< 2 - 16 bit port
                                                ///< 4 - 32 bit port
  IN
  UINT32  ApobErrorReportInputPortType;         ///< Indicates the type of Input Port or location of the port
                                                ///< 0 - PCIE HT0
                                                ///< 2 - PCIE HT1
                                                ///< 5 - PCIE MMIO
                                                ///< 6 - FCH_HT_IO (Default)
                                                ///< 7 - FCH_MMIO
  IN
  UINT32  ApobErrorReportOutputPortType;        ///< Indicates the type of Output Port or location of the port
                                                ///< 0 - PCIE HT0
                                                ///< 2 - PCIE HT1
                                                ///< 5 - PCIE MMIO
                                                ///< 6 - FCH_HT_IO (Default)
                                                ///< 7 - FCH_MMIO
  IN
  BOOLEAN  ApobErrorReportClearAcknowledgement;   ///< Indicates if the ABL will clear acknolgements during protocol
                                                  ///< TRUE - Clear acknowledgemetns
                                                  ///< FALSE - Do not clear acknologements
  IN
  BOOLEAN ApobErrorLogHeartBeatEnable;             ///< Indicates if ABL will provide periodic status to a port as a heart beat
                                                   ///< TRUE - Heartbeat Error log will be reported via a port
                                                   ///< FALSE - Heartbeat Error log will not be reported via a port
                                                   ///<
                                                   ///< Notes:
                                                   ///<   1) This feature is only valid if ErrorLogPortReportingEnable
                                                   ///<   2) This is can be mono-directional or bi-directional based on "ErrorLogReportUsingHandshakeEnable"
                                                   ///<        "ErrorLogReportUsingHandshakeEnable" = TRUE - bi-directional
                                                   ///<        "ErrorLogReportUsingHandshakeEnable" = FALSE - mono-directional
                                                   ///<   3) Requires the following to be defined:
                                                   ///<    - "ErrorLogReportInputPortType", "ErrorLogInputPort, "ErrorLogReportInputPortSize"
                                                   ///<    - "ErrorLogReportInputPortType", "ErrorLogInputPort, "ErrorLogReportInputPortSize"
} APOB_GEN_INFO_ERROR_INFO_STRUCT;

/**
 * @brief Memory DMI Type 17 - for memory use
 *
 */
typedef struct {
  OUT UINT8                     Socket:2;               ///< Socket ID
  OUT UINT8                     Channel:4;              ///< Channel ID
  OUT UINT8                     Dimm:1;                 ///< DIMM ID
  OUT UINT8                     DimmPresent:1;          ///< Dimm Present
  OUT UINT8                     SpdAddr;                ///< SPD Address
  OUT UINT16                    Handle;                 ///< The temporary handle, or instance number, associated with the structure
  OUT UINT16                    ConfigSpeed;            ///< Configured memory clock speed
  OUT UINT16                    ConfigVoltage;          ///< Configured voltage for this device, in millivolt
} APOB_MEM_DMI_PHYSICAL_DIMM;

/**
 * @brief Memory DMI Type 20 - for memory use
 *
 */
typedef struct {
  OUT UINT8                     Socket:2;               ///< Socket ID
  OUT UINT8                     Channel:4;              ///< Channel ID
  OUT UINT8                     Dimm:1;                 ///< DIMM ID
  OUT UINT8                     DimmPresent:1;          ///< Dimm Present
  OUT UINT8                     Interleaved:1;          ///< Interleaving enabled
  OUT UINT8                     Reserved:7;             ///< Reserved
  OUT UINT16                    MemoryDeviceHandle;     ///< The handle, or instance number, associated with
                                                        ///< the Memory Device structure to which this address
                                                        ///< range is mapped.
  OUT UINT32                    StartingAddr;           ///< The physical address, in kilobytes, of a range
                                                        ///< of memory mapped to the referenced Memory Device.
  OUT UINT32                    EndingAddr;             ///< The handle, or instance number, associated with
                                                        ///< the Memory Device structure to which this address
                                                        ///< range is mapped.
  /**
   * @brief Ext Starting Address
   * @details Union for 64 bit address or struct of upper and lower 32 bits
   *
   */
  union {
    OUT UINT64                  ExtStartingAddr;        ///< The physical address, in bytes, of a range of
                                                        ///< memory mapped to the referenced Memory Device.
    /**
     * @brief Struct for the address upper and lower 32 bits
     *
     */
    struct {
      OUT UINT32                ExtStartingAddrLow;   ///< Lower 32 bits of the address
      OUT UINT32                ExtStartingAddrHigh;  ///< Upper 32 bits of the address
    } ExtStartingAddrForPsp;
  } UnifiedExtStartingAddr;

  /**
   * @brief Ext Ending Address
   * @details Union for 64 bit address or struct of upper and lower 32 bits
   *
   */
  union {
    OUT UINT64                  ExtEndingAddr;          ///< The physical ending address, in bytes, of the last of
                                                        ///< a range of addresses mapped to the referenced Memory Device.
    /**
     * @brief Struct for the address upper and lower 32 bits
     *
     */
    struct {
      OUT UINT32                ExtEndingAddrLow;   ///< Lower 32 bits of the address
      OUT UINT32                ExtEndingAddrHigh;  ///< Upper 32 bits of the address
    } ExtEndingAddrForPsp;
  } UnifiedExtEndingAddr;
} APOB_MEM_DMI_LOGICAL_DIMM;

/**
 * @brief APOB Memory DMI entry header
 *
 */
typedef struct {
  APOB_TYPE_HEADER ApobTypeHeader;                     ///< APOB Type header
  UINT8            MemoryType:7;                       ///< Memory Type
  UINT8            EccCapable:1;                       ///< ECC Capable
  UINT8            MaxPhysicalDimms;                   ///< Maximum physical DIMMs
  UINT8            MaxLogicalDimms;                    ///< Maximum logical DIMMs
  UINT8            Reserved;                           ///< Reserved
} APOB_MEM_DMI_HEADER;

/**
 * @brief APOB Memory DMI entry
 *
 */
typedef union {
  /**
   * @brief DMI Entry fields
   *
   */
  struct {
    APOB_MEM_DMI_HEADER Header;                           ///< APOB Type header
    APOB_MEM_DMI_PHYSICAL_DIMM  PhysDimm[1];              ///< Memory Type
    APOB_MEM_DMI_LOGICAL_DIMM   LogDimm[1];               ///< Memory Type
  } Fields;
  UINT8             WorstCase[ABL_MEM_SMBIOS_INFO_SIZE];  ///< Worst case DMI Entry size
} APOB_MEM_DMI_INFO_STRUCT;


#define MAX_APOB_MEM_NB_BLOCK_SIZE 1528       ///< Memory NB Block Buffer Size
#define MAX_APOB_MEM_DCT_BLOCK_SIZE  976      ///< Memory DCT Block Buffer Size
#define MAX_APOB_MEM_TIMINGS_BLOCK_SIZE 360   ///< Memory Timings Block Buffer Size
#define MAX_APOB_MEM_CHANNEL_BLOCK_SIZE  450  ///< Memory Channel Block Buffer Size
#define MAX_APOB_MEM_DIE_BLOCK_SIZE 108       ///< Memory Die Block Buffer Size
#define MAX_APOB_MEM_MEM_INIT_DATA_BLOCK_SIZE 0x6000  ///< Memory Init Data Block Buffer Size
#define MAX_APOB_MEM_PARAMETER_DATA_BLOCK_SIZE 0x200  ///< Memory Parameter Block Buffer Size

/**
 * @brief AMD APOB_GEN_CONFIGURATION_INFO Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                   ///< APOB Type Header
  OUT
  UINT32 Bootmode;                                    ///< Bootmode detected by ABL.
  OUT
  BOOLEAN EmulationEnv;                               ///< Emulation Environment detected by ABL.
  OUT
  BOOLEAN SimulationEnv;                              ///< Simulation Environment detected by ABL.
  OUT
  UINT16 Reserved;                                    ///< Reserved for alignment
  IN
  APOB_GEN_INFO_ERROR_INFO_STRUCT ApobErrorInfo;      ///< APOB error information
  APOB_GEN_INFO_PARAMETER_INFO_STRUCT ApobParamInfo;  ///< APOB parameter information
  EVENT_LOG_STRUCT   ApobEventLog;                    ///< APOB event log
  UINT8 MemNbBlock[MAX_APOB_MEM_NB_BLOCK_SIZE];       ///> Memory NB block buffer
  UINT8 MemDctBlock[ABL_APOB_MAX_CHANNELS_PER_DIE][MAX_APOB_MEM_DCT_BLOCK_SIZE];  ///> Memory DCT block buffer
  UINT8 MemDieBlock[MAX_APOB_MEM_DIE_BLOCK_SIZE];     ///> Memory Die block buffer
} APOB_GEN_INFO_TYPE_STRUCT;

/**
 * @brief AMD APOB_D5_GEN_INFO_TYPE_STRUCT Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                   ///< APOB Type Header
  OUT
  UINT32 Bootmode;                                    ///< Bootmode detected by ABL.
  OUT
  BOOLEAN EmulationEnv;                               ///< Emulation Environment detected by ABL.
  OUT
  BOOLEAN SimulationEnv;                              ///< Simulation Environment detected by ABL.
  OUT
  UINT16 Reserved;                                    ///< Reserved for alignment
  IN
  APOB_GEN_INFO_ERROR_INFO_STRUCT ApobErrorInfo;      ///< APOB error information
  APOB_GEN_INFO_PARAMETER_INFO_STRUCT ApobParamInfo;  ///< APOB parameter information
  EVENT_LOG_STRUCT   ApobEventLog;                    ///< APOB event log
  UINT8 MemInitDataBlock[MAX_APOB_MEM_MEM_INIT_DATA_BLOCK_SIZE];    ///> MemInitData block buffer
  UINT8 MemParameterBlock[MAX_APOB_MEM_PARAMETER_DATA_BLOCK_SIZE];  ///> MemParameter block buffer
} APOB_D5_GEN_INFO_TYPE_STRUCT;

/**
 * @brief APOB_MEM_SOC_INIT_CONFIG_STRUCT Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;         ///< APOB Type Header
  BOOLEAN           IsMemOverclock;         ///< IsMemOverclock
  BOOLEAN           MemPeriodicRetrainEn;   ///< PPT Enable
  UINT8             MemoryType;             ///< Memory Type
  BOOLEAN           PhyPllBypassEn;         ///< PhyPllBypassEn
  BOOLEAN           PhyPllRelockEn;         ///< PhyPllRelockEn
  BOOLEAN           MemPStateEn;            ///< MemPStateEn
  BOOLEAN           SpecificDimmInSocket;   ///< Specific vendor's DimmInSocket
  UINT32            DdrMaxRate;             ///< DdrMaxRate
  UINT32            DdrMaxRateEnf;          ///< DdrMaxRateEnf
} APOB_MEM_SOC_INIT_CONFIG_STRUCT;

/**
 * @brief AMD APOB_PMU_SMB_STRUCT Header
 *
 */
typedef struct {
  IN
  UINT8 ApobPmuSmb[MAX_PMU_SMB_SIZE];  ///< APOB PMU SMB
} APOB_PMU_SMB_STRUCT;

/**
 * @brief AMD APOB_PMU_SMB_TYPE_STRUCT Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;    ///< APOB Type Header
  IN
  APOB_PMU_SMB_STRUCT ApobPmuSmb;      ///< APOB PMU SMB
} APOB_PMU_SMB_TYPE_STRUCT;

#define CCX_MAX_SOCKETS            ABL_APOB_MAX_SOCKETS_SUPPORTED  ///< Max number of supported sockets
#define CCX_MAX_DIES_PER_SOCKET    1   ///< Max dies per sockets
#define CCX_MAX_COMPLEXES_PER_DIE  2   ///< Max complexes per die
#define CCX_MAX_CORES_PER_COMPLEX  8   ///< Max cores per complex
#define CCX_MAX_THREADS_PER_CORE   2   ///< Max threads per core
#define CCX_NOT_PRESENT (0xFF)         ///< Not present

/**
 * @brief AMD LOGICAL_CORE_INFO
 *
 */
typedef struct {
  UINT8    PhysCoreNumber;                             ///< Physical Core Number
  BOOLEAN  IsThreadEnabled[CCX_MAX_THREADS_PER_CORE];  ///< Thread enabled flag per thread
} LOGICAL_CORE_INFO;

/**
 * @brief AMD LOGICAL_COMPLEX_INFO
 *
 */
typedef struct {
  UINT8              PhysComplexNumber;                    ///< Physical Complex Number
  LOGICAL_CORE_INFO  CoreInfo[CCX_MAX_CORES_PER_COMPLEX];  ///< Core info per core
} LOGICAL_COMPLEX_INFO;

/**
 * @brief AMD APOB_CCX_LOGICAL_TO_PHYSICAL_MAP_TYPE Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER      ApobTypeHeader;                         ///< APOB Type Header
  LOGICAL_COMPLEX_INFO  ComplexMap[CCX_MAX_COMPLEXES_PER_DIE];  ///< Complex info per complex
} APOB_CCX_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT;

// Program dependent
#define CCD_MAX_COMPLEXES_PER_CCD  2   ///< Max complexes per CCD
// Program dependent
#define CCD_MAX_CCDS_PER_DIE       12  ///< Max CCDs per Die

/**
 * @brief AMD LOGICAL_CCD_INFO
 *
 */
typedef struct {
  UINT8                 PhysCcdNumber;                          ///< Physical CCD Number
  LOGICAL_COMPLEX_INFO  ComplexMap[CCD_MAX_COMPLEXES_PER_CCD];  ///< Complex Info per CCD
} LOGICAL_CCD_INFO;

/**
 * @brief AMD APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                ///< APOB Type Header
  LOGICAL_CCD_INFO  CcdMap[CCD_MAX_CCDS_PER_DIE];  ///< CCD Maps
} APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT;

/**
 * @brief AMD SYSTEM_MEMORY_MAP Header
 *
 */
typedef enum {
  UMA,                        ///< UC DRAM cycles.  I do not think this is needed in SoC15 since HBM is not part of the system map
  MMIO,                       ///< Cycles are sent out to IO.  Only expect the 1 below 4GB
  PrivilegedDRAM,             ///< Read-only 0xFFs.  No special cache considerations are needed.  Map out of E820
  Reserved1TbRemap,           ///< Read-only 0xFFs.  This region is set to WB DRAM and cannot be used as MMIO.  Map out of E820
  ReservedSLink,              ///< SLink connected memory is not available until later in POST
  ReservedSLinkAlignment,     ///< Read-only 0xFFs.  This region is set to WB DRAM and cannot be used as MMIO.  Map out of E820
  ReservedDrtm,               ///< DRAM reserved for PSP use.  Access is determined by the PSP.
  ReservedCvip,               ///< DRAM reserved for CVIP use.
  ReservedSmuFeatures,        ///< DRAM reserved for SMU features
  ReservedMpioC20,            ///< DRAM reserved for C20 PHY
  ReservedNbif,               ///< DRAM reserved for NBIF
  ReservedCxl,                ///< CXL connected memory is not available until later in POST
  ReservedCxlAlignment,       ///< Read-only 0xFFs.  This region is set to WB DRAM and cannot be used as MMIO.  Map out of E820
  ReservedCpuTmr,             ///< DRAM reserved for CPU TMR
  ReservedRasEinj,            ///< DRAM reserved for RAS EINJ
  ReservedBelow4GB,           ///< DRAM reserved for Below 4GB.
  MaxMemoryHoleTypes,         ///< Not a valid type.  Used for validating the others.
} MEMORY_HOLE_TYPES;

/**
 * @brief AMD MEMORY_HOLE_DESCRIPTOR struct
 *
 */
typedef struct {
  UINT64             Base;    ///< Full 64 bit base address of the hole
  UINT64             Size;    ///< Size in bytes of the hole
  MEMORY_HOLE_TYPES  Type;    ///< Hole type
} MEMORY_HOLE_DESCRIPTOR;

/**
 * @brief AMD SYSTEM_MEMORY_MAP struct
 *
 */
typedef struct {
  UINT64                  TopOfSystemMemory;  ///< Final DRAM byte address in the system + 1
  UINT32                  NumberOfHoles;      ///< SoC15 systems will always have at least one
  MEMORY_HOLE_DESCRIPTOR  HoleInfo[1];        ///< Open ended array of descriptors
} SYSTEM_MEMORY_MAP;

/**
 * @brief AMD APOB_SYSTEM_MEMORY_MAP_TYPE_STRUCT Header
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                ///< APOB Type Header
  OUT
  SYSTEM_MEMORY_MAP   ApobSystemMap;               ///< APOB event log
  MEMORY_HOLE_DESCRIPTOR  AdditionalHoleInfo[17];  ///< Descriptors for memory holes in the memory map
} APOB_SYSTEM_MEMORY_MAP_TYPE_STRUCT;

/**
 * @brief AMD APOB_SYSTEM_NPS_INFO_TYPE_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER     ApobTypeHeader;      ///< APOB Type Header
  UINT8                RequestedNps;        ///< Requested NPS
  UINT8                ActualNps;           ///< Actual NPS
  UINT8                MinAllowableNps;     ///< Min allowable NPS
  UINT8                MaxAllowableNps;     ///< Max allowable NPS
} APOB_SYSTEM_NPS_INFO_TYPE_STRUCT;

/**
 * @brief DF CXL Region Init Status
 *
 */
typedef enum {
  CXL_ADDR_SUCCESS = 0,            ///< The requested CXL mapping was successfully created
  CXL_ADDR_OUT_OF_MAPS = 1,        ///< This region was not routed due to a shortage of DRAM map registers
  CXL_ADDR_INVALID_SOCKET = 2,     ///< The APCB passed in a 3rd and/or 4th region descriptor attached to the same socket
  CXL_ADDR_INVALID_NBIO_MAP = 3,   ///< The APCB passed in 2 even or 2 odd numbered NBIOs for the same socket, whether it is in the same descriptor or 2 different descriptors.
  CXL_ADDR_INVALID_ALIGNMENT = 4,  ///< The requested alignment was not achievable.
  CXL_ADDR_INVALID_SIZE = 5,       ///< The requested region was too large for the current configuration.
} DF_CXL_REGION_INIT_STATUS;

/**
 * @brief AMD CXL_ADDR_MAP_INFO struct
 *
 */
typedef struct {
  UINT64    Base;            ///< Base address of assigned region or 0xFFFFFFFF_FFFFFFFF if a problem occurred or if the input Size was zero.
  UINT64    Size;            ///<  Raw size routed in DF (zero if a problem occurred)
  UINT32    Status;          ///< see DF_SLINK_REGION_INIT_STATUS
  UINT8     Socket;          ///< Zero means socket 0, One means socket 1
  UINT8     PhysNbioMap;     ///< Bit n set means NBIO n on the given socket should be included in this region
  UINT8     Alignment;       ///< Bit position to align to (e.g. 32 will result in the region being 4GB aligned)
  UINT8     IntlvSize;       ///< Resulting region interleave size.  See DF_MEM_INTLV_SIZE_VALIDVAL.
  UINT8     SubIntlvMap[4];  ///< sub-link interleave bitfield
  UINT8     SubIntlvSize;    ///< sub-link interleave size
  UINT8     Type;            ///< 0 - Volatile; 1 - Persistent
} CXL_ADDR_MAP_INFO;

/**
 * @brief AMD APOB_SYSTEM_CXL_INFO_TYPE_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER     ApobTypeHeader;      ///< APOB Type Header
  CXL_ADDR_MAP_INFO    CxlInfo[8];          ///< CXL address map information
} APOB_SYSTEM_CXL_INFO_TYPE_STRUCT;

// DF DXIO
// Max size should be 150 bytes, but allocate more just in case
#define MAX_DF_DXIO_PHY_FW_OVERRIDE_TABLE_SIZE 0x100  ///< Max DF DXIO Phy Fw Override Table Size

/**
 * @brief AMD APOB_DF_DXIO_PHY_FW_OVERRIDE_TABLE_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER     ApobTypeHeader;                                              ///< APOB Type Header
  UINT32               OverrideTableSize;                                           ///< Size in bytes of override table
  UINT8                OverrideTableData[MAX_DF_DXIO_PHY_FW_OVERRIDE_TABLE_SIZE];   ///< Override table buffer
} APOB_DF_DXIO_PHY_FW_OVERRIDE_TABLE_STRUCT;


/// S3 Support

#define MAX_GEN_REPLAY_BUFFER_ENTRIES 0x770ul  ///< Max general S3 replay buffer entires
#define MAX_PHY_REPLAY_BUFFER_ENTRIES 0x500ul  ///< Max S3 phy replay buffer entires
#define MAX_MOP_ARRAY_REPLAY_BUFFER_ENTRIES 0x210ul	///Max S3 MOP Array replay buffer entires

/**
 * @brief Entry for the S3 replay buffer (direct register access).
 *
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Address;    ///< Register address
  _4BYTE_ALIGN UINT32 Value;      ///< Register value
} GEN_REPLAY_BUFFER_ENTRY;

/**
 * @brief Entry for the S3 replay buffer (indirect register access).
 *
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Index;      ///< Register index
  _4BYTE_ALIGN UINT32 Data;       ///< Register data
} GEN_INDEX_DATA_REPLAY_BUFFER_ENTRY;

/**
 * @brief Entry for the S3 DDR Phy Buffer
 *
 */
typedef struct {
  _2BYTE_ALIGN UINT16 Value[4];  ///< PHY register value
} DDR_PHY_BUFFER_ENTRY;

/**
 * @brief Entry for the S3 MOP array Buffer
 *
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Value[2]; ///< PHY register value
} MOP_ARRAY_BUFFER_ENTRY;

/**
 * @brief Replay buffer union for the different buffer entry types
 *
 */
typedef union {
  GEN_REPLAY_BUFFER_ENTRY               GenReplayEntry;             ///< Gen replay entry
  GEN_INDEX_DATA_REPLAY_BUFFER_ENTRY    GenIndexDataReplayEntry;    ///< Gen index data replay entry
  DDR_PHY_BUFFER_ENTRY                  DdrPhyReplayEntry;          ///< DdrPhy replay entry
  MOP_ARRAY_BUFFER_ENTRY                MopArrayReplayEntry;        ///< Mop Array replay entry
} REPLAY_BUFFER_ENTRY;

/**
 * @brief Entry for the S3 DDR Phy Buffer
 *
 */
typedef struct {
  BOOLEAN LogEn;           ///< Enables or disables logging for DDR Phy Entries
  UINT8 Reserved0;         ///< Reserved
  UINT16 Reserved1;        ///< Reserved
  UINT32 CurrPhyEntryNum;  ///< Current Phy entry number
  UINT32 CurrEntryNum;     ///< Current Entry Number
  UINT32 StartEntryNum;    ///< Start Entry
  UINT32 StopFlag;         ///< Stop Flag
  BOOLEAN ChannelEnable[ABL_APOB_MAX_CHANNELS_PER_DIE];      ///< Channels enabled
  UINT16 Reserved2;        ///< Reserved
  REPLAY_BUFFER_ENTRY Entry[MAX_PHY_REPLAY_BUFFER_ENTRIES];  ///< DDR Phy Buffer
} PHY_REPLAY_BUFFER;

/**
 * @brief Replay buffer
 *
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Version;   ///< Version of header
  UINT32 StopValue;              ///< Stop Value
  PHY_REPLAY_BUFFER ReplayBuff;  ///< General Replay Buffer
} REPLAY_BUFFER_PHY;

/**
 * @brief APOB Phy Replay Buffer Type
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;    ///< APOB Type Header
  REPLAY_BUFFER_PHY  PhyReplayData;    ///< Replay buffer
} APOB_REPLAY_BUFFER_PHY_TYPE_STRUCT;

/**
 * @brief General replay for the S3 DDR Phy Buffer
 *
 */
typedef struct {
  BOOLEAN DirectLogEn;     ///< Enables or dislables direct register access logging to replay buffer
  BOOLEAN IndirectLogEn;   ///< Enables or dislables indirect register access logging to replay buffer
  UINT16 Reserved1;        ///< Reserved
  UINT32 CurrPhyEntryNum;  ///< Current Phy entry number
  UINT32 CurrEntryNum;     ///< Current Entry Number
  UINT32 StartEntryNum;    ///< Start Entry
  UINT32 StopFlag;         ///< Stop Flag
  BOOLEAN ChannelEnable[ABL_APOB_MAX_CHANNELS_PER_DIE];      ///< Channels enabled
  UINT16 Reserved2;        ///< Reserved
  REPLAY_BUFFER_ENTRY Entry[MAX_GEN_REPLAY_BUFFER_ENTRIES];  ///< Replay Buffer
} GEN_REPLAY_BUFFER;

/* Device related definitions */

/**
 * @brief Replay buffer
 *
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Version;   ///< Version of header
  UINT32 StopValue;              ///< Stop Value
  GEN_REPLAY_BUFFER ReplayBuff;  ///< General Replay Buffer
} REPLAY_BUFFER;

/**
 * @brief APOB General Replay Buffer Type
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;    ///< APOB Type Header
  REPLAY_BUFFER   ReplayData;          ///< Replay buffer
} APOB_REPLAY_BUFFER_TYPE_STRUCT;

/**
 * @brief Entry for the S3 Mop Array Buffer
 *
 */
typedef struct {
  BOOLEAN LogEn;                                                  ///< Enables or disables logging for DDR Phy Entries
  UINT8 Reserved0;                                                ///< Reserved
  UINT16 Reserved1;                                               ///< Reserved
  UINT32 CurrPhyEntryNum;                                         ///< Current Phy entry number
  UINT32 CurrEntryNum;                                            ///< Current Entry Number
  UINT32 StartEntryNum;                                           ///< Start Entry
  UINT32 StopFlag;                                                ///< Stop Flag
  BOOLEAN ChannelEnable[ABL_APOB_MAX_CHANNELS_PER_DIE];           ///< Channels enabled
  UINT16 Reserved2;                                               ///< Reserved
  REPLAY_BUFFER_ENTRY Entry[MAX_MOP_ARRAY_REPLAY_BUFFER_ENTRIES]; ///< Mop Array Buffer
} MOP_ARRAY_REPLAY_BUFFER;

/**
 * @brief Replay buffer
 *
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Version;        ///< Version of header
  UINT32 StopValue;                   ///< Stop Value
  MOP_ARRAY_REPLAY_BUFFER ReplayBuff; ///< General Replay Buffer
} REPLAY_BUFFER_MOP_ARRAY;

/**
 * @brief APOB Mop array Replay Buffer Type
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;            ///< APOB Type Header
  REPLAY_BUFFER_MOP_ARRAY  MopArrayReplayData; ///< Replay buffer
} APOB_REPLAY_BUFFER_MOP_ARRAY_TYPE_STRUCT;

//-----------------------------------------------------------------------------
/**
 * @brief AMD APOB_MEM_DIMM_SPD_DATA_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;  ///< APOB Type Header
  UINT8 MaxDimmsPerChannel;          ///< Max DIMMs per channel
  UINT8 MaxChannelsPerSocket;        ///< Max channels per socket
  APOB_SPD_STRUCT   DimmSmbusInfo[ABL_APOB_MAX_CHANNELS_PER_DIE * ABL_APOB_MAX_DIMMS_PER_CHANNEL];  ///< DIMM SMBUS Info for max number of DIMMS per die
} APOB_MEM_DIMM_SPD_DATA_STRUCT;

/**
 * @brief AMD APOB_MEM_DIMM_D5_SPD_DATA_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;  ///< APOB Type Header
  UINT8 MaxDimmsPerChannel;          ///< Max DIMMs per channel
  UINT8 MaxChannelsPerSocket;        ///< Max channels per socket
  APOB_D5_SPD_STRUCT   DimmSmbusInfo[ABL_APOB_MAX_CHANNELS_PER_DIE * ABL_APOB_MAX_DIMMS_PER_CHANNEL];  ///< DIMM SMBUS Info for max number of DIMMS per die
} APOB_MEM_DIMM_D5_SPD_DATA_STRUCT;

/**
 * @brief AMD APOB_MEM_DIMM_SPD_DATA_UNION_STRUCT
 *
 */
typedef union {
  APOB_MEM_DIMM_SPD_DATA_STRUCT     ApobMemDimmD4SpdData;
  APOB_MEM_DIMM_D5_SPD_DATA_STRUCT  ApobMemDimmD5SpdData;
} APOB_MEM_DIMM_SPD_DATA_UNION_STRUCT;
/**
 * @brief Definition for APOB EDC throttle thresholds
 *
 */
typedef struct {
  APOB_TYPE_HEADER        ApobTypeHeader;                        ///< APOB Type Header
  UINT32                  NumberOfValidThresholds;               ///< Number of valid EDC throttle thresholds
  EDC_THROTTLE_THRESHOLD  Thresholds[MAX_NUMBER_OF_THROTTLERS];  ///< Array of thresholds
} APOB_EDC_THROTTLE_THRESHOLD_INFO_STRUCT;

/**
 * @brief Memory PMU revision structure
 *
 */
typedef struct {
  UINT16 RdimmPmuRev;
  UINT16 LRdimmPmuRev;
} MEM_PMU_REVISION;

/**
 * @brief Structure for memory events from event log
 *
 */
typedef struct {
  UINT32    EventInfo;        ///< Uniquely identifies the event
  UINT32    DataA;            ///< Data A Error Information
  UINT32    DataB;            ///< Data B Error Information
} MEM_EVENT_LOG;

/**
 * @brief DRAM Type Enum
 *
 */
typedef enum {
  DramType_RDIMM = 0,  ///< RDIMM
  DramType_LRDIMM,     ///< LRMDIMM
} DRAM_TYPE;

/**
 * @brief AMD PMU_TRAINING_FAILURE_INFO_ENTRY
 *
 */
typedef struct {
  UINT32  SocketId:1;          ///< 1 bit socket ID
  UINT32  UmcId:4;             ///< 4 bit UMC ID
  UINT32  Train1d2d:1;         ///< 1 bit train 1D or 2D type
  UINT32  Train1dAttempt:3;    ///< 3 bit train 1D attempts
  UINT32  DramType:1;          ///< 1 bit DRAM type
  UINT32  Reserved:6;          ///< 6 bit Reserved
  UINT32  stageCompletion:16;  ///< 16 bit stage completion
  UINT32  ErrorCode;           ///< Error Code
  UINT32  Data[4];             ///< Arguments
} PMU_TRAINING_FAILURE_INFO_ENTRY;

/**
 * @brief AMD PMU_TRAINING_FAILURE_INFO_STRUCT
 *
 */
// Up to 8 channels per socket, maximum five 1D training failure per channel, up to 40 entries
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;                     ///< APOB Type Header
  UINT32 nextEmptyEntry;                                ///< Next empty failure entry
  PMU_TRAINING_FAILURE_INFO_ENTRY  FailureEntry[40];    ///< Array of failure entries
} PMU_TRAINING_FAILURE_INFO_STRUCT;

/**
 * @brief AMD APOB_COMMON_DIE_DATA
 *
 */
typedef struct {
  APOB_MEM_GENERAL_CONFIGURATION_INFO_TYPE_STRUCT  MemGeneralCfg;             ///< APOB Mem General Config Info
  APOB_MEM_SYSTEM_CONFIGURATION_INFO_TYPE_STRUCT   MemSystemCfg;              ///< APOB Mem System Configuration Info
  APOB_MEM_GENERAL_ERRORS_TYPE_STRUCT              MemGeneralErrors;          ///< APOB Mem General Errors
  APOB_D5_GEN_INFO_TYPE_STRUCT                     GeneralInfo;               ///< APOB General Info
  APOB_MEM_SOC_INIT_CONFIG_STRUCT                  MemSocInitConfig;          ///< APOB Mem Soc Init Config
  APOB_MEM_RMP_INFO_STRUCT                         MemRmpInfo;                ///< APOB Mem Rmp Info
  APOB_REPLAY_BUFFER_TYPE_STRUCT                   S3ReplayData;              ///< APOB S3 Replay Buffer
  APOB_PMU_SMB_TYPE_STRUCT                         PmuSmb;                    ///< APOB PMU SMB
  APOB_MBIST_STATUS_TYPE_STRUCT                    MbistTestResults;          ///< APOB MBIST Test Results
  APOB_CCX_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT     CcxMap;                    ///< APOB CCX Map
  APOB_EDC_THROTTLE_THRESHOLD_INFO_STRUCT          CcxEdcThrottleThreshInfo;  ///< APOB CCX EDC Throttle Threshold Info
  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT     CcdMap;                    ///< APOB CCD Logical to Physical Map
  EVENT_LOG_STRUCT                                 EventLog;                  ///< Event log
  APOB_MEM_DIMM_SPD_DATA_UNION_STRUCT              SpdData;                   ///< APOB Memory DIMM SPD data
  PMU_TRAINING_FAILURE_INFO_STRUCT                 PmuTrainingFailure;        ///< PMU Training Failure Info
  APOB_REPLAY_BUFFER_MOP_ARRAY_TYPE_STRUCT         S3ReplayMopArrayData[APOB_MEM_S3_MOP_ARRAY_REPLAY_MAX_ENTRIES];  ///< APOB S3 MPOP Array Replay Buffer
  APOB_REPLAY_BUFFER_PHY_TYPE_STRUCT               S3ReplayPhyData[APOB_MEM_S3_DDR_PHY_REPLAY_MAX_ENTRIES];  ///< APOB S3 PHY Replay Buffer
} APOB_COMMON_DIE_DATA;

/**
 * @brief AMD APOB_MEM_NVDIMM_INFO_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;  ///< APOB Type Header
  UINT32    NvdimmInfo[ABL_APOB_MAX_SOCKETS_SUPPORTED * ABL_APOB_MAX_CHANNELS_PER_SOCKET * ABL_APOB_MAX_DIMMS_PER_CHANNEL][2];  ///< NVDIMM Info
  BOOLEAN   NvdimmPresentInSystem;   ///< NVDIMM Present Flag
  UINT8     Reserved[7];             ///< Reserved
} APOB_MEM_NVDIMM_INFO_STRUCT;

/**
 * @brief Defintion for APOB Boot Info to pass RecoveryFlag and ApcbInstance
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;      ///< APOB Type Header
  UINT32    ApcbActiveInstance;          ///< APCB Active Insatnce of the boot
  DIMM_APOB_OPT_ID CurrentBootDimmIdInfo[ABL_APOB_MAX_SOCKETS_SUPPORTED][ABL_APOB_MAX_CHANNELS_PER_SOCKET][ABL_APOB_MAX_DIMMS_PER_CHANNEL];  ///< Current boot DIMM info
  BOOLEAN DimmConfigurationUpdated;      //< FALSE - DIMM Configuration not updated,
                                         //< TRUE - DIMM Configuration updated
  UINT8     ApcbRecoveryFlag;            ///< APCB Recovery Flag
  UINT8     ActionOnBistFailure;         ///< Action On BIST failure
  UINT8     Reserved [1];                ///< Reserved for alignment
  UINT32    LastPmuTrainTime;            ///< Last time memory get trained
  UINT32    LastPartSerialNum0;          ///< Last part serial number 0
  UINT32    LastPartSerialNum1;          ///< Last part serial number 1
  UINT32    Reserved1;
} APOB_APCB_BOOT_INFO_STRUCT;

/**
 * @brief AMD APOB_ENV_FLAGS_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER           ApobTypeHeader;  ///< APOB Type Header
  ENV_FLAGS_STRUCT           Flags;           ///< Environment Flags
} APOB_ENV_FLAGS_STRUCT;

/**
 * @brief AMD APOB_GLOBAL_DATA struct
 *
 */
typedef struct {
  APOB_ENV_FLAGS_STRUCT                     EnvFlags;                 ///< Environment flags
  APOB_AGESA_CONFIG_DB_STRUCT               ConfigData;               ///< AGESA Config Data
  APOB_SYSTEM_MEMORY_MAP_TYPE_STRUCT        SystemMemoryMap;          ///< System Memory Map
  APOB_MEM_DMI_INFO_STRUCT                  SystemDmiInfo;            ///< Memory DMI Info
  APOB_MEM_NVDIMM_INFO_STRUCT               NvdimmInfo;               ///< NVDIMM Info
  APOB_APCB_BOOT_INFO_STRUCT                ApobApcbBootInfo;         ///< APCB Boot Info
  APOB_SYSTEM_CXL_INFO_TYPE_STRUCT          SystemCxlInfo;            ///< System CXL Info
  APOB_DF_DXIO_PHY_FW_OVERRIDE_TABLE_STRUCT DfDxioPhyFwOverrideInfo;  ///< DF DXIO PHY FW Override Table
  APOB_SYSTEM_NPS_INFO_TYPE_STRUCT          SystemNpsInfo;            ///< System NPS Info
} APOB_GLOBAL_DATA;

/**
 * @brief AMD APOB_DATA struct
 *
 */
typedef struct {
  APOB_HEADER                 Header;      ///< APOB Header
  APOB_GLOBAL_DATA            GlobalData;  ///< APOB Global Data
  APOB_COMMON_DIE_DATA        CommonDieData[ABL_APOB_MAX_SOCKETS_SUPPORTED];  ///< Common die data for all sockets
  } APOB_DATA;

//-----------------------------------------------------------------------------
/**
 * @brief SPD Data for each DIMM.
 *
 */
typedef struct _APOB_DIMM_INFO_SMBUS {
  UINT8  MemoryLayoutType;    ///< Memory Layout Type, if 0 = SpdLayout  1= Onboard Layout
  UINT8  DimmSlotPresent;     ///< Indicates that the DIMM is present and Data is valid
  UINT8  SocketId;            ///< Indicates the socket number
  UINT8  ChannelId;           ///< Indicates the channel number
  UINT8  DimmId;              ///< Indicates the channel number
  UINT8  DimmSmbusAdderess;   ///< SMBus address of the DRAM
  UINT8  I2CMuxAddress;       ///< I2C Mux Address
  UINT8  MuxChannel;          ///< I2C Mux Channel assocaited iwth this SPD
} APOB_DIMM_INFO_SMBUS;
/// APOB_MEM_DIMM_SMBUS_INFO_TYPE

/**
 * @brief AMD APOB_MEM_DIMM_SMBUS_INFO_TYPE_STRUCT
 *
 */
typedef struct {
  APOB_TYPE_HEADER  ApobTypeHeader;  ///< APOB Type Header
  UINT32            totalEntry;  ///< Total entries
  APOB_DIMM_INFO_SMBUS   DimmSmbusInfo[ABL_APOB_MAX_SOCKETS_SUPPORTED *
                                       ABL_APOB_MAX_CHANNELS_PER_SOCKET *
                                       ABL_APOB_MAX_DIMMS_PER_CHANNEL];  ///<DIMM SMBUS Info for all DIMMs per channel per socket per die
} APOB_MEM_DIMM_SMBUS_INFO_TYPE_STRUCT;

#endif  /* _APOB_H_ */

