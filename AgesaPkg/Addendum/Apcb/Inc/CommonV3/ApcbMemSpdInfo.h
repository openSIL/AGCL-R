/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_SPD_INFO_H_
#define _APCB_MEM_SPD_INFO_H_

//
// @CONSTANT
//
#define APCB_MAX_SOCKETS_SUPPORTED  1  ///< Max Sockets supproted by APCB
#define APCB_MAX_CHANNEL_PER_SOCKET 12
#define APCB_MAX_DIMMS_PER_CHANNEL  1
#define APCB_TOTAL_SYSTEM_DIMMS  (APCB_MAX_SOCKETS_SUPPORTED * APCB_MAX_CHANNEL_PER_SOCKET * APCB_MAX_DIMMS_PER_CHANNEL) ///< @VALUE:4

//
// @APCB_START
//

/// SPD_MUX_INFO
typedef struct _SPD_MUX_INFO {
  UINT8  SpdMuxPresent;      ///< SpdMux Present or not. if 1, then yes otherwise no
  UINT8  MuxI2CAddress;      ///< MuxI2cAddress
  UINT8  MuxChannel;         ///< MuxChannel no.
  UINT8  Reserved;           ///< Reserved
} SPD_MUX_INFO;

/// Dram technology type
typedef enum {
  SODIMM_PACKAGE,        ///< SODIMM package
  UDIMM_PACKAGE,         ///< UDIMM Package
  RDIMM_PACKAGE,         ///< RDIMM Package
  DRAMDOWN_PACKAGE,      ///< DRAM Down Package
  UNSUPPORTED_PACKAGE,   ///< Unsupported package
} DRAM_PACKAGE_TYPE;

/// ECC Symbol Size
typedef enum {
   SYMBOL_SIZE_X4,           ///< Symbol size x4
   SYMBOL_SIZE_X8,           ///< Symbol size x8
   SYMBOL_SIZE_X16,          ///< Symbol size x16

   SYMBOL_SIZE_UNSUPPORTED   ///< Boundary check
} ECC_SYMBOL_SIZE;

//-----------------------------------------------------------------------------
///
/// SPD Data for each DIMM.
///
typedef struct _SPD_DEF_STRUCT {
  BOOLEAN                 DramDownSpdValid;                     ///< Indicates that the DramDown SPD is valid
  BOOLEAN                 DimmPresent;                          ///< Indicates that the DIMM is present and Data is valid
  UINT8                   PageAddress;                          ///< Indicates the 256 Byte EE Page the data belongs to
                                                                //      0 = Lower Page
                                                                //      1 = Upper Page
  BOOLEAN                 NvDimmPresent;                        ///< Indicates this DIMM is NVDIMM
  UINT16                  DramManufacturersIDCode;              /// DRAM Manufacture ID
  UINT16                  ModuleManufacturersIDCode;            /// Module Manufacture ID
  UINT32                  Address;                              ///< SMBus address of the DRAM
  SPD_MUX_INFO            SpdMuxInfo;                           ///< Mux and Channel Number associated with this DIMM
  TECHNOLOGY_TYPE         Technology;                           ///< Indicates the type of Technology used in SPD
                                                                ///<   DDR3_TECHNOLOGY = Use DDR3 DIMMs
                                                                ///<   DDR4_TECHNOLOGY = Use DDR4 DIMMs
                                                                ///<   LPDDR3_TECHNOLOGY = Use LPDDR3
  DRAM_PACKAGE_TYPE       Package;                              ///< Indicates the package type
                                                                // SODIMM_PACKAGE = SODIMM package
                                                                // UDIMM_PACKAGE = UDIMM Package
                                                                // RDIMM_PACKAGE = RDIMM Package
                                                                // DRAMDOWN_PACKAGE = DRAM Down Package
  UINT8                   SocketNumber;                         ///< Indicates the socket number
  UINT8                   ChannelNumber;                        ///< Indicates the channel number
  UINT8                   DimmNumber;                           ///< Indicates the channel number
  BOOLEAN                 ShadowSpdValid;                       ///< Indicates whether the DIMM is present in the last boot
  UINT8                   Data[512];                            ///< Buffer for 512 Bytes of SPD data from DIMM
} SPD_DEF_STRUCT;

///===============================================================================
/// _PSP_SPD_LPDDR3_STRUCT
/// This data structure is used to pass wrapper parameters to the memory configuration code
///

/** PSP_SPD_STRUCT
*    @GROUPID: APCB_GROUP_MEMORY
*    @TYPEID: APCB_MEM_TYPE_SPD_INFO
*    This data structure is used to pass wrapper parameters to the memory configuration code
*/
typedef struct _PSP_SPD_STRUCT {
  UINT32 TotalDimms;
  SPD_DEF_STRUCT  SpdData[APCB_TOTAL_SYSTEM_DIMMS];
} PSP_SPD_STRUCT;


#endif // _APCB_MEM_SPD_INFO_H_

