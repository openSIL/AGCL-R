/*****************************************************************************
*
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
*
*/

#ifndef _APCB_H_
#define _APCB_H_

//
// @APCB_START
//
#define APCB_HEADER_VERSION         0x0300    // APCB Version
#define APCB_HEADER_STRUCT_VERSION  0x0000
#define APCB_HEADER_DATA_VERSION    0x0000
#define ABL_RESERVED                0xFF

#include "ApcbV3Arch.h"
#include "ApcbV3Priority.h"
#include "ApcbDataGroups.h"
#include "ApcbAblBreakpoint.h"

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
/// ABL Serial Baud Rate
typedef enum {
  BAUD_RATE_2400 = 0,     ///< Baud rate 2400
  BAUD_RATE_3600 = 1,     ///< Baud rate 3600
  BAUD_RATE_4800 = 2,     ///< Baud rate 4800
  BAUD_RATE_7200 = 3,     ///< Baud rate 7200
  BAUD_RATE_9600 = 4,     ///< Baud rate 9600
  BAUD_RATE_19200 = 5,    ///< Baud rate 19200
  BAUD_RATE_38400 = 6,    ///< Baud rate 38400
  BAUD_RATE_57600 = 7,    ///< Baud rate 57600
  BAUD_RATE_115200 = 8    ///< Baud rate 115200
} ABL_SERIAL_BAUD_RATE;

/// PMU message control (HdtCtrl)
typedef enum {
  DETAILED_DBG_MSG = 0x05,     ///< Detailded debug message
  COARSE_DBG_MSG = 0x0A,       ///< Coarse debug message
  STAGE_COMPLETION = 0xC8,     ///< Stage completion
  ASSERTION_MESSAGES = 0xC9,   ///< Assertion messages
  FIRMWARE_COMPLETION_MSG_ONLY = 0xFE   ///< Firmware completion message only, 0xFE to instead of 0xFF, because 0xFF is for Auto
} ABL_PMU_MESSAGE_CONTROL;

typedef struct _DIMM_HUB_INFO {
  UINT8  SocketId;            ///< Indicates the socket number
  UINT8  ChannelId;           ///< Indicates the channel number
  UINT8  DimmId;              ///< Indicates the channel number
  UINT8  DimmSmbusAdderess;   ///< SMBus address of this DRAM module
  UINT8  FchI2cI3cCtrlIndex;  ///< FCH I2C / I3C controller route to this DIMM slot
} DIMM_HUB_INFO;

//
// DIMM Configuration Lookup Criteria
//
#define PT_DONT_CARE    0xFF  ///< Do not care
#define NP              1     ///< Not Populated
#define V1_5            1     ///< 1.5 Volts
#define V1_35           2     ///< 1.35 Volts
#define V1_25           4     ///< 1.25 Volts
#define V1_2            1     ///< 1.2 Volts
#define V_TBD1          2     ///< Voltage to be determined 1
#define V_TBD2          4     ///< Voltage to be determined 2
#define V1_1            1     ///< 1.1 Volts
#define V0_6            2     ///< 0.6 Volts
//
// Rank
//
#define DIMM_NP         1     ///< DIMM Not Present
#define DIMM_SR         2     ///< Single Rank DIMM Present
#define DIMM_DR         4     ///< Dual Ranke DIMM Present
#define DIMM_QR         8     ///< Quad Rank DIMM Present
//
// Device Width
//
#define DEVWIDTH_4      0x01
#define DEVWIDTH_8      0x02
//#define DEVWIDTH_16     0x04
//#define DEVWIDTH_32     0x08
#define DEVWIDTH_ALL    0xFF
//
// MPstate
//
#define MP0             0x01
#define MP1             0x02
#define MP2             0x04
#define MP3             0x08
#define MP_ALL          0xFF
/// Timing
///
#define TMG_1N           1     ///< 1N Timing Mode
#define TMG_2N           0     ///< 2N Timing Mode
///
/// Defined values for DDR5 CK_ODT, CS_ODT, and CK_ODT
///
#define D5_ODT_OFF        0     ///< ODT Off
#define D5_ODT_480        1     ///< 480 Ohm
#define D5_ODT_240        2     ///< 240 Ohm
#define D5_ODT_120        3     ///< 120 Ohm
#define D5_ODT_80         4     ///< 80 Ohm
#define D5_ODT_60         5     ///< 60 Ohm
#define D5_ODT_40         7     ///< 40 Ohm
///
/// Defined values for RTT_NOM_WR,RTT_NOM_RD
///
#define D5_RTT_OFF        0     ///< RTT Off
#define D5_RTT_240        1     ///< 240 Ohm
#define D5_RTT_120        2     ///< 120 Ohm
#define D5_RTT_80         3     ///< 80 Ohm
#define D5_RTT_60         4     ///< 60 Ohm
#define D5_RTT_48         5     ///< 48 Ohm
#define D5_RTT_40         6     ///< 40 Ohm
#define D5_RTT_34         7     ///< 34 Ohm
///
/// Generic, un-encoded impedance values for various purposes. They can be
/// translated to the appropriate value for how it is consumed.
///
#define D5_IMP_OFF        0      ///< Impedance Off
#define D5_IMP_480        480    ///< 480 Ohms
#define D5_IMP_240        240    ///< 240 Ohms
#define D5_IMP_160        160    ///< 160 Ohms
#define D5_IMP_120        120    ///< 120 Ohms
#define D5_IMP_96         96     ///< 96 Ohms
#define D5_IMP_80         80     ///< 80 Ohms
#define D5_IMP_68         68     ///< 68 Ohms
#define D5_IMP_60         60     ///< 60 Ohms
#define D5_IMP_53         53     ///< 53 Ohms
#define D5_IMP_48         48     ///< 48 Ohms
#define D5_IMP_43         43     ///< 43 Ohms
#define D5_IMP_40         40     ///< 40 Ohms
#define D5_IMP_36         36     ///< 36 Ohms
#define D5_IMP_34         34     ///< 34 Ohms
#define D5_IMP_32         32     ///< 32 Ohms
#define D5_IMP_30         30     ///< 30 Ohms
#define D5_IMP_28         28     ///< 28 Ohms
#define D5_IMP_26         26     ///< 26 Ohms
#define D5_IMP_25         25     ///< 25 Ohms
///
/// DFE
///
#define DFE_DIS           0      ///< DFE Disabled
#define DFE_EN            1      ///< DFE Enabled

//
// The entry header structure
//
typedef struct _PSCFG_DDR5_BUS_ENTRY_HEADER_S {
  UINT32 Length;          ///< The size of this structure
  UINT32 MemClk;          ///< The target MemClk Frequency
  UINT8  DimmPerCh;       ///< The number of DIMM slot per chanel
  UINT8  Dimm0;           ///< The bitmap of rank type of DIMM0
  UINT8  Dimm1;           ///< The bitmap of rank type of DIMM1
  UINT8  DevWidth;        ///< The bitmap of SDRAM IO width
} PSCFG_DDR5_BUS_ENTRY_HEADER_S;

//
// The entry payload structure
// The entry data is listed at the following.
//
typedef struct _PSCFG_DDR5_BUS_ENTRY_PAYLOAD_S {
  UINT32 Length;          ///< The size of this structure
  UINT32 CaTimingMode;    ///< CaTimingMode
  UINT32 Dimm0_RttNomWr;  ///< RTT_NOM_WR
  UINT32 Dimm0_RttNomRd;  ///< RTT_NOM_RD
  UINT32 Dimm0_RttWr;     ///< RTT_WR
  UINT32 Dimm0_RttPark;   ///< RTT_PARK
  UINT32 Dimm0_DqsRttPark;///< DQS_RTT_PARK
  UINT32 Dimm1_RttNomWr;  ///< RTT_NOM_WR
  UINT32 Dimm1_RttNomRd;  ///< RTT_NOM_RD
  UINT32 Dimm1_RttWr;     ///< RTT_WR
  UINT32 Dimm1_RttPark;   ///< RTT_PARK
  UINT32 Dimm1_DqsRttPark;///< DQS_RTT_PARK
  UINT32 DramDrv;         ///< DRAM_DRV
  UINT32 CkOdtA;          ///< CK_ODT Group A
  UINT32 CsOdtA;          ///< CS_ODT Group A
  UINT32 CaOdtA;          ///< CA_ODT Group A
  UINT32 CkOdtB;          ///< CK_ODT Group B
  UINT32 CsOdtB;          ///< CS_ODT Group B
  UINT32 CaOdtB;          ///< CA_ODT Group B
  UINT32 POdt;            ///< PODT
  UINT32 DqDrv;           ///< DQ Drv
  UINT32 AlertPu;         ///< Alert Pullup
  UINT32 CaDrv;           ///< CA Drv
  UINT32 PhyVref;         ///< PHY Vref
  UINT32 DqVref;          ///< DQ Vref
  UINT32 CaVref;          ///< CA Vref
  UINT32 CsVref;          ///< CS Vref
  UINT32 DCaVref;         ///< DCA Vref
  UINT32 DCsVref;         ///< DCS Vref
  UINT32 RxDfe;           ///< RXDFE
  UINT32 TxDfe;           ///< TXDFE
} PSCFG_DDR5_BUS_ENTRY_PAYLOAD_S;

/// DDR5 Bus configuration entry for DRAMDOWN, SODIMM, or UDIMM
typedef struct _PSCFG_BUS_ENTRY_S {
  PSCFG_DDR5_BUS_ENTRY_HEADER_S   Header;
  PSCFG_DDR5_BUS_ENTRY_PAYLOAD_S  Payload;
} PSCFG_BUS_ENTRY_S;

/*----------------------------------------------------------------------------
 *                           FUNCTIONS PROTOTYPE
 *
 *----------------------------------------------------------------------------
 */

#endif




