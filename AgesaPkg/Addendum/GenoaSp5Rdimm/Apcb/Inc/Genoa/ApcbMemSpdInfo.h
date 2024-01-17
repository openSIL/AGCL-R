/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define SPD Info Data
 */
#ifndef _APCB_MEM_SPD_INFO_H_
#define _APCB_MEM_SPD_INFO_H_

/**
 * @brief Maximum number of Sockets Supported
 */
#define APCB_MAX_SOCKETS_SUPPORTED  1
/**
 * @brief Maximum number of Channels Supported per Socket
 */
#define APCB_MAX_CHANNEL_PER_SOCKET 12
/**
 * @brief Maximum number of Dimms per Channel
 */
#define APCB_MAX_DIMMS_PER_CHANNEL  1
/**
 * @brief Total Number of Dimms in the System
 */
#define APCB_TOTAL_SYSTEM_DIMMS  (APCB_MAX_SOCKETS_SUPPORTED * APCB_MAX_CHANNEL_PER_SOCKET * APCB_MAX_DIMMS_PER_CHANNEL)

#if ABL_BUILD
/**
 * @brief Dram technology type
 */
typedef enum {
  DDR2_TECHNOLOGY,        ///< DDR2 technology
  DDR3_TECHNOLOGY,        ///< DDR3 technology
  GDDR5_TECHNOLOGY,       ///< GDDR5 technology
  DDR4_TECHNOLOGY,        ///< DDR4 technology
  LPDDR3_TECHNOLOGY,      ///< LPDDR3 technology
  LPDDR4_TECHNOLOGY,      ///< LPDDR4 technology
  HBM_TECHNOLOGY,         ///< HBM technology
  GDDR6_TECHNOLOGY,       ///< GDDR6 technology
  DDR5_TECHNOLOGY,        ///< DDR5 technology
  LPDDR5_TECHNOLOGY,      ///< LPDDR5 technology
  UNSUPPORTED_TECHNOLOGY, ///< Unsupported technology
} TECHNOLOGY_TYPE;
#endif

/**
 * @brief Data Structure to pass SPD Mux Info
 */
typedef struct _SPD_MUX_INFO {
  UINT8  SpdMuxPresent;      ///< SpdMux Present or not. if 1, then yes otherwise no
  UINT8  MuxI2CAddress;      ///< MuxI2cAddress
  UINT8  MuxChannel;         ///< MuxChannel no.
  UINT8  Reserved;           ///< Reserved
} SPD_MUX_INFO;

/**
 * @brief Dram Paclage type
 */
typedef enum {
  SODIMM_PACKAGE,        ///< SODIMM package
  UDIMM_PACKAGE,         ///< UDIMM Package
  RDIMM_PACKAGE,         ///< RDIMM Package
  DRAMDOWN_PACKAGE,      ///< DRAM Down Package
  UNSUPPORTED_PACKAGE,   ///< Unsupported package
} DRAM_PACKAGE_TYPE;

/**
 * @brief ECC Symbol Size type
 */
/// ECC Symbol Size
typedef enum {
   SYMBOL_SIZE_X4,           ///< Symbol size x4
   SYMBOL_SIZE_X8,           ///< Symbol size x8
   SYMBOL_SIZE_X16,          ///< Symbol size x16
   SYMBOL_SIZE_UNSUPPORTED   ///< Boundary check
} ECC_SYMBOL_SIZE;

/**
 * @brief SPD Data for each DIMM.
 */
typedef struct _SPD_DEF_STRUCT {
  BOOLEAN                 DramDownSpdValid;                     ///< Indicates that the DramDown SPD is valid
  BOOLEAN                 DimmPresent;                          ///< Indicates that the DIMM is present and Data is valid
  UINT8                   PageAddress;                          /**< Indicates the 256 Byte EE Page the data belongs to
                                                                 *      0 = Lower Page
                                                                 *      1 = Upper Page
                                                                 */
  BOOLEAN                 NvDimmPresent;                        ///< Indicates this DIMM is NVDIMM
  UINT16                  DramManufacturersIDCode;              /// DRAM Manufacture ID
  UINT16                  ModuleManufacturersIDCode;            /// Module Manufacture ID
  UINT32                  Address;                              ///< SMBus address of the DRAM
  SPD_MUX_INFO            SpdMuxInfo;                           ///< Mux and Channel Number associated with this DIMM
  TECHNOLOGY_TYPE         Technology;                           /**< Indicates the type of Technology used in SPD
                                                                 *   DDR3_TECHNOLOGY = Use DDR3 DIMMs
                                                                 *   DDR4_TECHNOLOGY = Use DDR4 DIMMs
                                                                 *   LPDDR3_TECHNOLOGY = Use LPDDR3
                                                                 */
  DRAM_PACKAGE_TYPE       Package;                              /**< Indicates the package type
                                                                 * SODIMM_PACKAGE = SODIMM package
                                                                 * UDIMM_PACKAGE = UDIMM Package
                                                                 * RDIMM_PACKAGE = RDIMM Package
                                                                 * DRAMDOWN_PACKAGE = DRAM Down Package
                                                                 */
  UINT8                   SocketNumber;                         ///< Indicates the socket number
  UINT8                   ChannelNumber;                        ///< Indicates the channel number
  UINT8                   DimmNumber;                           ///< Indicates the channel number
  BOOLEAN                 ShadowSpdValid;                       ///< Indicates whether the DIMM is present in the last boot
  UINT8                   Data[512];                            ///< Buffer for 512 Bytes of SPD data from DIMM
} SPD_DEF_STRUCT;

/**
 * @brief This data structure is used to pass wrapper parameters to the memory configuration code
 * @details  GROUPID: APCB_GROUP_MEMORY TYPEID: APCB_MEM_TYPE_SPD_INFO
 */
typedef struct _PSP_SPD_STRUCT {
  UINT32 TotalDimms;                                ///< Total Number of Dimms
  SPD_DEF_STRUCT  SpdData[APCB_TOTAL_SYSTEM_DIMMS]; ///< List containing SPD Data info for Each Dimm
} PSP_SPD_STRUCT;


#endif // _APCB_MEM_SPD_INFO_H_

