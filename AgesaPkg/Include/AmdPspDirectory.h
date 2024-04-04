/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/**
 * @file  AmdPspDirectory.h
 *
 * @brief Structure definition for PSP directory
 *
 */

#ifndef _AMD_PSP_DIR_H_
#define _AMD_PSP_DIR_H_

#pragma pack (push, 1)
#define PSP_DIRECTORY_HEADER_SIGNATURE  0x50535024ul   ///< $PSP
#define PSP_LV2_DIRECTORY_HEADER_SIGNATURE 0x324C5024ul   ///< $PL2
#define TOTAL_ENTRIES_MAX 512
#define ENTRY_SIZE_MAX  0x1000000   ///< 16M Bytes

#define FIRMWARE_TABLE_SIGNATURE  0x55AA55AAul
#define IMAGE_SLOT_PRIORITY_UNBOOTABLE    0
#define MAX_IMAGE_SLOT_COUNT 32

///
/// Define structure for 32 bits Additional Info field of PSP Directory Header
///
typedef struct {
  UINT32 MaxSize:10;            ///< Directory Size in 4K bytes
  UINT32 SpiBlockSize:4;        ///< Modifiable Entry alignment
  UINT32 BaseAddress:15;        ///< [26:12] of Directory Image Base Address
  UINT32 AddressMode:2;         ///< Directory Address Mode (0, 1, 2, or 3)
  UINT32 Reserved:1;            ///< Reserved
} PSP_DIRECTORY_HEADER_ADDITIONAL_INFO_FIELD;

///
/// Define union type for 32 bits Additional Info field
///
typedef union {
  PSP_DIRECTORY_HEADER_ADDITIONAL_INFO_FIELD Field;  // Definition of each field
  UINT32                                     Value;  // Group it as 32bits Int
} PSP_DIRECTORY_HEADER_ADDITIONAL_INFO;

///
/// Define structure for PSP directory
///
typedef struct {
  UINT32  Cookie;                                        ///< "$PSP"
  UINT32  Checksum;                                      ///< 32 bit CRC of header items below and the entire table
  UINT32  TotalEntries;                                  ///< Number of PSP Entries
  PSP_DIRECTORY_HEADER_ADDITIONAL_INFO  AdditionalInfo;  ///< Additional Info
} PSP_DIRECTORY_HEADER;

///
/// Define structure for 32 bits Entry type field
///
typedef struct {
  UINT32 Type:8;             ///< Type of PSP Directory entry
  UINT32 SubProgram:8;       ///< Specify the SubProgram
  UINT32 RomId:2;            ///< Specify the ROM ID
  UINT32 Writable:1;         ///< 1: Region writable, 0: Region read only
  UINT32 Instance:4;         ///< Instance
  UINT32 Reserved:9;         ///< Reserved
} PSP_DIRECTORY_ENTRY_TYPE_FIELD;

///
/// Define structure for 32 bits Firmware Id field
///
typedef struct {
  UINT32 FwId:16;             ///< Type of PSP Directory entry
  UINT32 Reserved:16;         ///< Reserved
} PSP_DIRECTORY_FW_ID_FIELD;
///
/// Define union type for 32 bits Entry type field
///
typedef union {
  PSP_DIRECTORY_FW_ID_FIELD      FwIdField; // Definition of each field for Fw Id defined in _PSP_DIRECTORY_FW_ID
  PSP_DIRECTORY_ENTRY_TYPE_FIELD Field; // Definition of each field for Entry Type defined in _PSP_DIRECTORY_ENTRY_TYPE
  UINT32                         Value; // Group it as 32bits Int
} PSP_DIRECTORY_ENTRY_TYPE;

/**
 * @enum define various enum type for PSP entry type
 */
typedef enum _PSP_DIRECTORY_ENTRY_TYPE {
  AMD_PUBLIC_KEY                  = 0x00,           ///< ID: 0x00, PSP entry pointer to AMD public key
  PSP_FW_BOOT_LOADER              = 0x01,           ///< ID: 0x01, PSP entry points to PSP boot loader in SPI space
  PSP_FW_TRUSTED_OS               = 0x02,           ///< ID: 0x02, PSP entry points to PSP Firmware region in SPI space
  PSP_FW_RECOVERY_BOOT_LOADER     = 0x03,           ///< ID: 0x03, PSP entry point to PSP recovery region.
  PSP_NV_DATA                     = 0x04,           ///< ID: 0x04, PSP entry points to fTPM data region in SPI space
  BIOS_PUBLIC_KEY_V1              = 0x05,           ///< ID: 0x05, PSP entry points to BIOS public key stored in SPI space
  BIOS_RTM_FIRMWARE_V1            = 0x06,           ///< ID: 0x06, PSP entry points to BIOS RTM code (PEI volume) in SPI space
  BIOS_RTM_SIGNATURE_V1           = 0x07,           ///< ID: 0x07, PSP entry points to signed BIOS RTM hash stored  in SPI space
  SMU_OFFCHIP_FW                  = 0x08,           ///< ID: 0x08, PSP entry points to SMU image
  AMD_SEC_DBG_PUBLIC_KEY          = 0x09,           ///< ID: 0x09, PSP entry pointer to Secure Unlock Public key
  OEM_PSP_FW_PUBLIC_KEY           = 0x0A,           ///< ID: 0x0A, PSP entry pointer to an optional public part of the OEM PSP Firmware Signing Key Token
  AMD_SOFT_FUSE_CHAIN_01          = 0x0B,           ///< ID: 0x0B, PSP entry pointer to 64bit PSP Soft Fuse Chain
  PSP_BOOT_TIME_TRUSTLETS         = 0x0C,           ///< ID: 0x0C, PSP entry points to boot-loaded trustlet binaries
  PSP_BOOT_TIME_TRUSTLETS_KEY     = 0x0D,           ///< ID: 0x0D, PSP entry points to key of the boot-loaded trustlet binaries
  PSP_AGESA_RESUME_FW             = 0x10,           ///< ID: 0x10, PSP Entry points to PSP Agesa-Resume-Firmware
  SMU_OFF_CHIP_FW_2               = 0x12,           ///< ID: 0x12, PSP entry points to secondary SMU image
  PSP_EARLY_UNLOCK_DEBUG_IMAGE    = 0x13,           ///< ID: 0x13, PSP entry points to PSP early secure unlock debug image
  PSP_S3_NV_DATA                  = 0x1A,           ///< ID: 0x1A, PSP entry pointer to S3 Data Blob
  HW_IP_CONFIG_FILE               = 0x20,           ///< ID: 0x20, PSP entry points to HW IP configuration file
  WRAPPED_IKEK                    = 0x21,           ///< ID: 0x21, PSP entry points to Wrapped iKEK
  PSP_TOKEN_UNLOCK_DATA           = 0x22,           ///< ID: 0x22, PSP entry points to PSP token unlock data
  PSP_DIAG_BOOT_LOADER            = 0x23,           ///< ID: 0x23, PSP entry points to PSP Diag BL on non-secure part via fuse
  SECURE_GASKET_BINARY            = 0x24,           ///< ID: 0x24, PSP entry points to security gasket binary
  KVM_ENGINE_BINARY               = 0x29,           ///< ID: 0x29, PSP entry points to PSP KVM Engine binary
  TEE_WONE_NVRAM                  = 0x2C,           ///< ID: 0x2C, PSP entry points to TEE_WONE_NVRAM binary
  EXTERNAL_PREMIUM_CHIPSET_MP1_FW = 0x2F,           ///< ID: 0x2F, PSP entry points to External Premium Chipset MP0 FW image
  AGESA_BOOT_LOADER_0             = 0x30,           ///< ID: 0x30, PSP entry points to PSP AGESA Binary 0
  AGESA_BOOT_LOADER_1             = 0x31,           ///< ID: 0x31, PSP entry points to PSP AGESA Binary 1
  AGESA_BOOT_LOADER_2             = 0x32,           ///< ID: 0x32, PSP entry points to PSP AGESA Binary 2
  AGESA_BOOT_LOADER_3             = 0x33,           ///< ID: 0x33, PSP entry points to PSP AGESA Binary 3
  AGESA_BOOT_LOADER_4             = 0x34,           ///< ID: 0x34, PSP entry points to PSP AGESA Binary 4
  AGESA_BOOT_LOADER_5             = 0x35,           ///< ID: 0x35, PSP entry points to PSP AGESA Binary 5
  AGESA_BOOT_LOADER_6             = 0x36,           ///< ID: 0x36, PSP entry points to PSP AGESA Binary 6
  AGESA_BOOT_LOADER_7             = 0x37,           ///< ID: 0x37, PSP entry points to PSP AGESA Binary 7
  PSP_VM_GUARD_DATA               = 0x38,           ///< ID: 0x38, PSP entry points to VM Guard data
  PSP_SEV                         = 0x39,           ///< ID: 0x39, PSP entry points to SEV binary
  PSP_DIR_LV2                     = 0x40,           ///< ID: 0x40, PSP entry points to Level 2 PSP DIR
  PSP_PHY                         = 0x42,           ///< ID: 0x42, PSP entry points to PHY binary
  EXTERNAL_PREMIUM_CHIPSET_PSP_BL = 0x46,           ///< ID: 0x46, PSP entry points to External Premium Chipset PSP Boot Loader
  PSP_REGION_A_DIR                = 0x48,           ///< ID: 0x48, PSP entry points to PSP DIR in Region A
  BIOS_REGION_DIR                 = 0x49,           ///< ID: 0x49, PSP entry points to BIOS DIR in Region A or B
  PSP_REGION_B_DIR                = 0x4A,           ///< ID: 0x4A, PSP entry points to PSP DIR in Region B
  PSP_NVRAM                       = 0x54,           ///< ID: 0x54, PSP entry points to PSP NVRAM for RPMC
  MSMU_BINARY_0                   = 0x5A,           ///< ID: 0x5A, PSP entry points to MSMU
  PSP_MPIO                        = 0x5D,           ///< ID: 0x5D, PSP entry points to MPIO Offchip Firmware
  AMD_SCS_BINARY                  = 0x5F,           ///< ID: 0x5F, Software Configuration Settings Data Block
  AMD_SFFS_BINARY                 = 0x63,           ///< ID: 0x63, Secure Coprocessor Enforced System Firmware
                                                    //Provides an authenticated mechanism to enable and customize system level firmware/software features.

  PSP_RIB                         = 0x76,           ///< ID: 0x76, PSP entry points to RIB FW
  PSP_BOOT_OEM_TRUSTLET           = 0x80,           ///< ID: 0x80, PSP entry points to boot-loaded OEM trustlet binary
  PSP_BOOT_OEM_TRUSTLET_KEY       = 0x81,           ///< ID: 0x81, PSP entry points to key of the boot-loaded OEM trustlet binary
  MPM_FW_1                        = 0x85,           ///< ID: 0x85, AMF Firmware part 1: Lx core can start execution only from SRAM,
                                                    ///< also part 1 FW will be used to initialize MPM TLB's so that DRAM can be mapped to Lx
  MPM_FW_2                        = 0x86,           ///< ID: 0x86, AMF Firmware part 2: Bulk of MPM functionality will be implemented in this part
  MPM_PERSISTENT_STORAGE          = 0x87,           ///< ID: 0x87, Persistent storage exclusively for AIM-T needs
  MPM_WLAN_FW                     = 0x88,           ///< ID: 0x88, WLAN firmware copied to MPM memory by MFD and then MPM will send this to WLAN
  PSP_MMPDMA                      = 0x8C,           ///< ID: 0x8C, PSP entry points to TigerFish MMPDMA FW.
  PSP_GMI                         = 0x91,           ///< ID: 0x91, PSP entry points to MPDMA Page Migration FW
  PSP_PM                          = 0x92,           ///< ID: 0x92, PSP entry points to GMI FW
  PMF_BINARY                      = 0x99,           ///< ID: 0x99, Binary that contains PMF policy

} PSP_DIRECTORY_ENTRY_TYPE_ID;

/**
 * @enum define various enum type for PSP Firmware ID
 */
typedef enum _PSP_DIRECTORY_FW_ID {
  AMD_PUBLIC_KEY_FW_ID                = 0x0139,           ///< FW ID pointer to AMD public key
  PSP_FW_BOOT_LOADER_FW_ID            = 0x0001,           ///< FW ID points to PSP boot loader in SPI space
  PSP_FW_TRUSTED_OS_FW_ID             = 0x0009,           ///< FW ID points to PSP Firmware region in SPI space
  AMD_SEC_DBG_PUBLIC_KEY_FW_ID        = 0x0132,           ///< FW ID pointer to Secure Unlock Public key
  PSP_EARLY_UNLOCK_DEBUG_IMAGE_FW_ID  = 0x000B,           ///< FW ID points to PSP early secure unlock debug image
  HW_IP_CONFIG_FILE_FW_ID             = 0x1007,           ///< FW ID points to HW IP configuration file
  WRAPPED_IKEK_FW_ID                  = 0x013B,           ///< FW ID points to Wrapped iKEK
  SECURE_GASKET_BINARY_FW_ID          = 0x004B,           ///< FW ID points to security gasket binary
  PSP_TRUSTED_OS_SYS_DRV_FW_ID        = 0x000A,           ///< FW ID points to AMD TEE3.0 Trusted OS System Driver
  MP5_CCD_FW_ID                       = 0x104C,           ///< FW ID points to MP5 CCD Drv
  AGESA_BOOT_LOADER_0_FW_ID           = 0x000F,           ///< FW ID points to PSP AGESA Binary 0
  BIOS_REGION_DIR_FW_ID               = 0x014F,           ///< FW IDpoints to BIOS DIR in Region A or B
  PSP_PHY_FW_ID                       = 0x101A,           ///< FW ID points to PHY binary
  DRTM_TRUSTED_APP_FW_ID              = 0x0052,           ///< FW ID points to DRTM Trusted Application
  PSP_REGION_A_FW_ID                  = 0x013C,           ///< FW ID points to PSP Region A
  PSP_REGION_B_FW_ID                  = 0x013D,           ///< FW ID points to PSP Region B
  PSP_BL_KEY_DB_DATA_FW_ID            = 0x004E,           ///< FW ID points to PSP BL Key DB Data
  PSP_KEY_DB_FW_ID                    = 0x004F,           ///< FW ID points to PSP Key DB
  ANTI_ROLLBACK_FW_ID                 = 0x0056,           ///< FW ID points to Anti-Rollback Drv
  MPIO_DRV_FW_ID                      = 0x101B,           ///< FW ID points to MPIO Offchip Firmware
  BOOT_AUDIT_MODULE_FW_ID             = 0x005E,           ///< FW ID points to Boot Audit Module
  PSP_STG_2_BL_FW_ID                  = 0x0002,           ///< FW ID points to PSP Stage 2 Bootloader
  DR_RIB_FW_ID                        = 0x0131,           ///< FW ID points to DF Rib
  SPI_DEVICE_TABLE_FW_ID              = 0x0133,           ///< FW ID points to SPI Service Table
  MCA_BANK_INFO_TABLE_FW_ID           = 0x0134,           ///< FW ID points to MCA Bank Info Table
  DGPU_VBIOS_IMAGE_FW_ID              = 0x0137,           ///< FW ID points to dGPU VBIOS Image
  DGPU_VBIOS_IMAGE_SIG_FW_ID          = 0x0141,           ///< FW ID points to dGPU VBIOS Image Signature
  MEM_CONFIG_TABLE_FW_ID              = 0x0147,           ///< FW ID points to Memory Configuration Table
  MEM_INIT_UNIVERSAL_MOD_FW_ID        = 0x0148,           ///< FW ID points to Memory Initialization Universal Module
  TEE_SOC_DRV_FW_ID                   = 0x014A,           ///< FW ID points to TEE Soc driver (DrvSoc)
  TEE_SOC_DBG_DRV_FW_ID               = 0x014B,           ///< FW ID points to TEE Soc DBG driver (DrvDbg)
  TEE_INTERFACE_DRV_FW_ID             = 0x014C,           ///< FW ID points to TEE Interface driver (DrvIntf)
  UMC_FW_FW_ID                        = 0x1009,           ///< FW ID points to UMC Firmware
  XCD_MP5_FW_ID                       = 0x1051,           ///< FW ID points to XCD MP5
  INVALID_FW_ID                       = 0xFFFF,           ///< Invalide Firmware ID
} PSP_DIRECTORY_FW_ID;

///
/// Structure for PSP Entry
///
typedef struct {
  PSP_DIRECTORY_ENTRY_TYPE    Type;       ///< Type of PSP entry; 32 bit long
  UINT32                      Size;       ///< Size of PSP Entry in bytes
  UINT64                      Location;   ///< Location of PSP Entry (byte offset from start of SPI-ROM,
                                          ///  The bits[62:63] of Location are used as Entry Address Mode)
} PSP_DIRECTORY_ENTRY;

///
/// Structure for PSP directory
///
typedef struct {
  PSP_DIRECTORY_HEADER  Header;           ///< PSP directory header
  PSP_DIRECTORY_ENTRY   PspEntry[1];      ///< Array of PSP entries each pointing to a binary in SPI flash
                                          ///< The actual size of this array comes from the
                                          ///< header (PSP_DIRECTORY.Header.TotalEntries)
} PSP_DIRECTORY;

///
/// Define the structure OEM signature table
///
typedef struct _FIRMWARE_ENTRY_TABLEV2 {
  UINT32  Signature;          ///< 0x00 Signature should be 0x55AA55AAul
  UINT32  ImcRomBase;         ///< 0x04 Base Address for Imc Firmware
  UINT32  GecRomBase;         ///< 0x08 Base Address for Gmc Firmware
  UINT32  XHCRomBase;         ///< 0x0C Base Address for XHCI Firmware
  UINT32  LegacyPspDirBase;   ///< 0x10 Base Address of PSP directory for legacy program (ML, BP, CZ, BR, ST)
  UINT32  PspDirBase;         ///< 0x14 Base Address for PSP directory
  UINT32  ZpBiosDirBase;      ///< 0x18 Base Address for ZP BIOS directory
  UINT32  RvBiosDirBase;      ///< 0x1C Base Address for RV BIOS directory
  UINT32  SspBiosDirBase;     ///< 0x20 Base Address for RV BIOS directory
  UINT32  Config;             ///< 0x24 reserved for EFS configuration
  UINT32  NewBiosDirBase;     ///< 0x28 Generic Base address for all program start from RN
  UINT32  PspDirBackupBase;   ///< 0x2C Backup PSP directory address for all programs starting from RMB
  UINT32  PTFW;               ///< 0x30 Point to promontory firmware
  UINT32  LPPTFW;             ///< 0x34 Point to LP promontory firmware
  UINT32  PT19FW;             ///< 0x38 Point to promontory19 firmware
} FIRMWARE_ENTRY_TABLEV2;


/// Unified Boot BIOS Directory structure
enum _BIOS_DIRECTORY_ENTRY_TYPE {
  BIOS_PUBLIC_KEY               = 0x05,       ///< PSP entry points to BIOS public key stored in SPI space
  BIOS_RTM_SIGNATURE            = 0x07,       ///< PSP entry points to signed BIOS RTM hash stored  in SPI space
  MAN_OS                        = 0x5C,       ///< PSP entry points to manageability OS binary
  MAN_IP_LIB                    = 0x5D,       ///< PSP entry points to manageability proprietary IP library
  MAN_CONFIG                    = 0x5E,       ///< PSP entry points to manageability configuration inforamtion
  BIOS_APCB_INFO                = 0x60,       ///< Agesa PSP Customization Block (APCB)
  BIOS_APOB_INFO                = 0x61,       ///< Agesa PSP Output Block (APOB) target location
  BIOS_FIRMWARE                 = 0x62,       ///< BIOS Firmware volumes
  APOB_NV_COPY                  = 0x63,       ///< APOB data copy on non-volatile storage which will used by ABL during S3 resume
  PMU_INSTRUCTION               = 0x64,       ///< Location field pointing to the instruction portion of PMU firmware
  PMU_DATA                      = 0x65,       ///< Location field pointing to the data portion of PMU firmware
  UCODE_PATCH                   = 0x66,       ///< Microcode patch
  CORE_MCEDATA                  = 0x67,       ///< Core MCE data
  BIOS_APCB_INFO_BACKUP         = 0x68,       ///< Backup Agesa PSP Customization Block (APCB)
  BIOS_DIR_LV2                  = 0x70,       ///< BIOS entry points to Level 2 BIOS DIR
  DISCRETE_USB4_FIRMWARE        = 0x71,       ///< Discrete USB4 Firmware volumes
};

/// Type attribute for BIOS Directory entry
typedef struct {
  UINT32 Type : 8 ;          ///< [0:7], Type of BIOS entry
  UINT32 S3Reload :1;        ///< [8], Flag to identify the entry need to reload during S3 exit
  UINT32 Reserved1 :7;       ///< [9:15], Reserved
  UINT32 BiosResetImage: 1;  ///< [16], Set for SEC or EL3 fw, which will be authenticate by PSP FW known as HVB
  UINT32 Copy: 1;            ///< [17], Copy: 1- copy BIOS image image from source to destination 0- Set region attribute based on <ReadOnly, Source, size> attributes
  UINT32 ReadOnly : 1;       ///< [18], 1: Set region to read-only (applicable for ARM- TA1/TA2) 0: Set region to read/write
  UINT32 Compressed : 1;     ///< [19], 1: Compresed
  UINT32 Instance : 4;       ///< [20:23], Specify the Instance of an entry
  UINT32 SubProgram : 3;     ///< [24:26], Specify the SubProgram
  UINT32 RomId:2;            ///< [27:28], Specify the RomId
  UINT32 Writable : 1;       ///< [29], 1: Region writable, 0: Region read only
  UINT32 Reserved : 2;       ///< [30:31], Reserve for future use
} TYPE_ATTRIB;


/// Structure for PSP Entry
typedef struct {
  TYPE_ATTRIB                 TypeAttrib;       ///< Type of PSP entry; 32 bit long
  UINT32                      Size;             ///< Size of PSP Entry in bytes
  UINT64                      Location;         ///< Location of PSP Entry (byte offset from start of SPI-ROM)
  UINT64                      Destination;      ///< Destination of PSP Entry copy to
} BIOS_DIRECTORY_ENTRY;

#define BIOS_DIRECTORY_HEADER_SIGNATURE 0x44484224ul       ///< $BHD BIOS Directory Signature
#define BIOS_LV2_DIRECTORY_HEADER_SIGNATURE 0x324C4224ul   ///< $BL2 BIOS Directory Lv2 Signature
/// Structure for BIOS directory
typedef struct {
  PSP_DIRECTORY_HEADER  Header;           ///< PSP directory header
  BIOS_DIRECTORY_ENTRY  BiosEntry[1];     ///< Array of PSP entries each pointing to a binary in SPI flash
                                          ///< The actual size of this array comes from the
                                          ///< header (PSP_DIRECTORY.Header.TotalEntries)
} BIOS_DIRECTORY;

/// Structure for PSP Combo directory
#define PSP_COMBO_DIRECTORY_COOKIE  0x50535032ul  ///< 2PSP PSP Combo Directory Signature
#define BIOS_COMBO_DIRECTORY_COOKIE 0x44484232ul  ///< "BHD2" BIOS Combo Directory Signature

typedef struct {
  UINT32  Cookie;         ///< "2PSP" or "2BHD"
  UINT32  Checksum;       ///< 32 bit CRC of header items below and the entire table
  UINT32  TotalEntries;   ///< Number of PSP Entries
  UINT32  LookUpMode;     ///< 0 - Dynamic look up through all entries, 1 - PSP/chip ID match.
  UINT8   Reserved[16];   ///< Reserved
} COMBO_DIRECTORY_HEADER;

/// Structure for PSP Combo directory entry
typedef struct {
  UINT32 IdSelect;        ///< 0 - Compare PSP ID, 1 - Compare chip family ID
  UINT32 Id;              ///< 32-bit Chip/PSP ID
  UINT64 DirTableAddr;    ///< Point to PSP directory table (level 2)
} COMBO_DIRECTORY_ENTRY;

typedef struct {
  COMBO_DIRECTORY_HEADER  Header;       ///< PSP Combo directory header
  COMBO_DIRECTORY_ENTRY ComboEntry[1];  ///<  Array of PSP combo entries each pointing to level 2 PSP Direcotry header
} COMBO_DIRECTORY;

/// Structure for image slot entry, only used in family VN & MR
///  It also used as structure to store ISH generic information accross programs
typedef struct {
  UINT32 Priority;              ///< This field indicates whether the image is preferred for boot selection
                                ///< For A/B scheme, partition A and B's ISH will both have a non 0 priority, with A's always higher than B's. This priority is never changed after factory flash.
  UINT32 UpdateRetries;         ///< This field represents the number of boot attempts that are allowed on a newly updated partition before a partition is considered unbootable
                                ///< For A/B recovery scheme, this field is hardcoded as 1, specifying that no boot retrial shall be attempted
  UINT32 GlitchRetries;         ///< Glitch retry counter,This field represents the number of boot attempts that are allowed on a working partition before an image is considered "unbootable"
                                ///< For A/B recovery scheme, this counter is set 0, not allowing any retrials
  UINT32 ImageSlotAddr;         ///< The associated partition location in flash offset, where the PSP L2 directory of the partition is in flash.
} IMAGE_SLOT_HEADER;

///Structure for image slot entry, start use from RMB
///Major changes:
/// 1. Add CRC checksum
/// 2. Add PSPID to support combo, w/o combo directory
/// 3. Increased max entry number, 8 -> 32 (support up to 16 SOCs)
/// 4. Increased L1 as well as pointer in EFS (support multiple SOC image flash programming)
typedef struct {
  UINT32    CheckSum;       ///< [0x0000] Newly added on Rembrandt. 32 bit CRC value of items below this field in the ISH.
                            ///< Fletcher's checksum algorithm is used for CRC calculation.
  UINT32    Priority;       ///< [0x0004] This field indicates whether the image is preferred for boot selection
                            ///< In the A/B scheme, the A partition will have a hardcoded priority of 0xFFFF_FFFF,
                            ///< while B partition will have a hardcoded priority of 0.
  UINT32    UpdateRetries;  ///< [0x0008] This field represents the number of boot attempts that are allowed on a newly updated partition before a partition is considered unbootable
                            ///< For A/B recovery scheme, this field is hardcoded as 1, specifying that no boot retrial shall be attempted
  UINT8     GlitchRetries;  ///< [0x000C] Glitch retry counter,This field represents the number of boot attempts that are allowed on a working partition before an image is considered "unbootable"
                            ///< For A/B recovery scheme, this counter is set 0, not allowing any retrials
  UINT8     Reserved[3];    ///< [0x000D]
  UINT32    ImageSlotAddr;  ///< [0x0010] The Slot BIOS Image location, point to the PSP L2 directory of the partition (using SPI ROM Offset).
  UINT32    PspId;          ///< [0x0014] PSP ID of the SoC this image slot is for.
  UINT32    SlotMaxSize;    ///< [0x0018] Maximum image size allowed to program into the slot this ISH points to.
  UINT32    Reserved_1;     ///< [0x001C]
} IMAGE_SLOT_HEADER_V2;     ///< [0x0020]

typedef struct {
  UINT32            SlotCount;                                  ///< the slot count in the system
  UINT8             BootableSlotCount;                          ///< the bootable slot count in the system
  UINT8             BootableSlotArray[MAX_IMAGE_SLOT_COUNT];    ///< bootable slot index array
  UINT8             UnbootableSlotCount;                        ///< the unbootable slot count in the system
  UINT8             UnbootableSlotArray[MAX_IMAGE_SLOT_COUNT];  ///< unbootable slot index array
  UINT8             SlotAIndex;                                 ///< index of slot with highest priority
  IMAGE_SLOT_HEADER SlotAHeader;                                ///< slot header with highest priority
  UINT8             SlotBIndex;                                 ///< index of slot with second highest priority
  IMAGE_SLOT_HEADER SlotBHeader;                                ///< slot header with second highest priority
} IMAGE_SLOT_INFO;

#pragma pack (pop)
#endif //_AMD_PSP_DIR_H_

