/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_FCH_ESPI_INIT_H_
#define _APCB_FCH_ESPI_INIT_H_

//
// @APCB_START
//

//
// @CONSTANT
//

/// FCH eSPI initialization configuration structure
/** APCB_FCH_ESPI_INIT_STRUCT
 * @brief FCH eSPI initialization configuration structure
 * @GROUPID: APCB_GROUP_FCH
 * @TYPEID: APCB_FCH_TYPE_ESPI_INIT
 * @param EspiEnable Enable eSPI controller
 * @param DataBusSelect eSPI data bus selection
 * @param ClockPinSelect eSPI CS Pin selection
 * @param CsPinSelect eSPI CS Pin selection
 * @param ClockFreq eSPI operating clock frequency
 * @param IoMode eSPI IO mode
 * @param AlertMode eSPI alert mode
 * @param PltRstDeasrt eSPI PLTRST# de-assert
 * @param Io80Enable eSPI IO80 port decoding
 * @param Io6064Enable eSPI KBC port IO60/64 decoding
 * @param IoRangeSize[16] eSPI IO range size
 * @param IoRangeBase[16] eSPI IO range base
 * @param MmioRangeSize[5] eSPI MMIO range size
 * @param MmioRangeBase[5] eSPI MMIO range base
 * @param IrqMask Bits[23:0]eSPI IRQ mask bitmap for IRQ23~0   1 - masked off the interrupt   0 - no mask
 * @param IrqPolarity Bits[23:0] eSPI IRQ polarity bitmap for IRQ23~0  1 - High    0 - low
 * @param TempRtcVwEn CPUTEMP_RTCTIME_VW_EN
 * @param RtctimeVwIndexSel CPUTEMP_RTCTIME_VW_EN
 * @param MmioCpuTemp MMIO base for Cpu temp
 * @param MmioRtcTime MMIO base for RTC Time
 * @param BusMasterEn eSPI Bus Master
 *   This data structure is used to pass parameters to the eSPI configuration code
 */
typedef struct _APCB_FCH_ESPI_INIT_STRUCT {
  BOOLEAN      EspiEnable;                ///< Enable eSPI controller
  UINT8        DataBusSelect;             ///< eSPI data bus selection
  UINT8        ClockPinSelect;            ///< eSPI Clock Pin selection
  UINT8        CsPinSelect;               ///< eSPI CS Pin selection
  UINT8        ClockFreq;                 ///< eSPI operating clock frequency
  UINT8        IoMode;                    ///< eSPI IO mode
  UINT8        AlertMode;                 ///< eSPI alert mode
  BOOLEAN      PltRstDeasrt;              ///< eSPI PLTRST# de-assert
  BOOLEAN      Io80Enable;                ///< eSPI IO80 port decoding
  BOOLEAN      Io6064Enable;              ///< eSPI KBC port IO60/64 decoding
  UINT8        IoRangeSize[16];           ///< eSPI IO range size
  UINT16       IoRangeBase[16];           ///< eSPI IO range base
  UINT16       MmioRangeSize[5];          ///< eSPI MMIO range size
  UINT32       MmioRangeBase[5];          ///< eSPI MMIO range base
  UINT32       IrqMask;                   ///< eSPI IRQ mask bitmap
  UINT32       IrqPolarity;               ///< eSPI IRQ polarity bitmap
  BOOLEAN      TempRtcVwEn;               ///< CPUTEMP_RTCTIME_VW_EN
  UINT8        RtctimeVwIndexSel;         ///< CPUTEMP_RTCTIME_VW_INDEX_SEL
  UINT32       MmioCpuTemp;               ///< MMIO base for Cpu temp
  UINT32       MmioRtcTime;               ///< MMIO base for RTC Time
  BOOLEAN      BusMasterEn;               ///< eSPI Bus Master
} APCB_FCH_ESPI_INIT_STRUCT;

#endif // _APCB_FCH_ESPI_INIT_H_
