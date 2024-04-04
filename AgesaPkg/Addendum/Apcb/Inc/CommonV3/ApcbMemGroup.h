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

#define APCB_MEM_TYPE_SPD_INFO                      0x0030
#include "ApcbMemSpdInfo.h"                     // (0x30) APCB_MEM_TYPE_SPD_INFO

#define APCB_MEM_TYPE_DDR_POST_PACKAGE_REPAIR       0x005E
#include "ApcbMemDdrPostPackageRepair.h"        // (0x5E) APCB_MEM_TYPE_DDR_POST_PACKAGE_REPAIR

#endif // _APCB_MEM_GROUP_H_


