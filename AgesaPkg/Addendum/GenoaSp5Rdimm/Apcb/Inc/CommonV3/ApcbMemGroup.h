/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_GROUP_H_
#define _APCB_MEM_GROUP_H_
//
// @APCB_START
//

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

/// Dram technology type
typedef enum {
  SODIMM_PACKAGE,        ///< SODIMM package
  UDIMM_PACKAGE,         ///< UDIMM Package
  RDIMM_PACKAGE,         ///< RDIMM Package
  DRAMDOWN_PACKAGE,      ///< DRAM Down Package
  UNSUPPORTED_PACKAGE,   ///< Unsupported package
} DRAM_PACKAGE_TYPE;

/// I2C_MUX_INFO for SPD
typedef struct _SPD_MUX_INFO {
  UINT8  SpdMuxPresent;       ///< Spd I2C MUX present or not, TRUE - Present, FALSE - Not Present
  UINT8  MuxSmbusAddress;     ///< I2C Mux Address
  UINT8  MuxChannel;          ///< I2C Mux Channel assocaited iwth this SPD
  UINT8  Reserved;            ///< Reserved
} SPD_MUX_INFO;


#define APCB_MEM_TYPE_SPD_INFO                      0x0030
#include "ApcbMemSpdInfo.h"                     // (0x30) APCB_MEM_TYPE_SPD_INFO

#define APCB_MEM_TYPE_DDR_POST_PACKAGE_REPAIR       0x005E
#include "ApcbMemDdrPostPackageRepair.h"        // (0x5E) APCB_MEM_TYPE_DDR_POST_PACKAGE_REPAIR

#endif // _APCB_MEM_GROUP_H_


