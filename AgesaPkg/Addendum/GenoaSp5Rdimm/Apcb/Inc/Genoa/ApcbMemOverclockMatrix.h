/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_OVERCLOCK_MATRIX_H_
#define _APCB_MEM_OVERCLOCK_MATRIX_H_
//
// @APCB_START
//


///===============================================================================
typedef struct {
  UINT16 MemoryFreq;   ///< Memory Clock Frequency
  UINT16 FabricFreq;   ///< Infinity Fabric Frequency
  UINT16 VddpVoltage;  ///< VDDP voltage in mV
  UINT16 VddcrSocVid;  ///< VDDCR_SOC Vid
} MEM_OVERCLOCK_MATRIX_ENTRY;


#endif // _APCB_MEM_OVERCLOCK_MATRIX_H_



