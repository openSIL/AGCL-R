/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MM_H_
#define _APCB_MM_H_


//////////////////////////////
//
// Platform Tuning Definitions
//
//////////////////////////////
/// Memory Pstate
typedef enum {
  MEMORY_PSTATE0,   ///< Memory Pstate 0
  MEMORY_PSTATE1,   ///< Memory Pstate 1
  MEMORY_PSTATE2,   ///< Memory Pstate 2
  MEMORY_PSTATE3,   ///< Memory Pstate 3
} MEM_PSTATE;

/// PMU SEQUENCE_CTRL
#define SMB_TESTEnable    (1 << 0)
#define SMB_ShortReset    (1 << 1)
#define SMB_ShortPattern  (1 << 2)
#define SMB_InputVref     (1 << 3)
#define SMB_SkipVrefUpd   (1 << 4)
#define SMB_PER_RANK_TMG    0x01
#define SMB_2T_TMG          0x01
#define SMB_CSMUX_45_ADDR   0x04
#define SMB_CSMUX_67_ADDR   0x08
#define SMB_TMG_MUX_67_ADDR 0x10
#define SMB_DRAM_TYPE_DDR4_UDIMM  0x02
#define SMB_SEQ_DEVINIT     (1 << 0)      // [0] DevInit - Device/phy initialization. Should always be set.
#define SMB_SEQ_WRLVL       (1 << 1)      // [1] WrLvl - Write leveling
#define SMB_SEQ_RXEN        (1 << 2)      // [2] RxEn - Read gate training
#define SMB_SEQ_RDDQS1D     (1 << 3)      // [3] RdDQS1D - 1d read dqs training
#define SMB_SEQ_WRDQ1D      (1 << 4)      // [4] WrDQ1D - 1d write dq training
#define SMB_SEQ_RD2D        (1 << 5)      // [5] rd2D - 2d read dqs training
#define SMB_SEQ_WR2D        (1 << 6)      // [6] wr2D - 2d write dq training
#define SMB_SEQ_LCDLCAL     (1 << 7)      // [7] LcdlCal - LCDL offset calibration training
#define SMB_SEQ_RDDESKEW    (1 << 8)      // [8] RdDeskew - Per lane read dq deskew training
#define SMB_SEQ_MXRDLAT     (1 << 9)      // [9] MxRdLat - Max read latency training
#define SMB_SEQ_DWL         (1 << 10)     // [10] DWL - LDRIMM DRAM Write Leveling
#define SMB_SEQ_MREP        (1 << 11)     // [11] MREP - LRDIMM DRAM Interface MDQ Receive Enable Phase training
#define SMB_SEQ_MRD         (1 << 12)     // [12] MRD - DRAM-to-DB Read Delay training
#define SMB_SEQ_MWD         (1 << 13)     // [13] MWD - DB-to-DRAM Write Delay training
#define SMB_DFE 0x01                      // [0]  1 = Run rx2D with DFE, 0 = Run rx2D with DFE off
#define SMB_FFE 0x01                      // [0]  1 = Run rx2D with FFE, 0 = Run rx2D with FFE off

//
// PLATFORM_TUNING_ENTRY
//
typedef enum _PLATFORM_TUNING_ENTRY {
   PLATFORM_TUNING_ENTRY_START = 0x1000,
   // Enablement
   PLATFORM_TUNING_CHIPSEL_INTLV,
   PLATFORM_TUNING_ECC,
   PLATFORM_TUNING_PARITY,
   PLATFORM_TUNING_MEM_BUS_LIMIT,
   PLATFORM_TUNING_MBIST_ENABLE,
   PLATFORM_TUNING_MBIST_TEST_MODE,
   PLATFORM_TUNING_MBIST_AGGRESSOR_ON,
   PLATFORM_TUNING_MBIST_PER_BIT_SECONDARY_DIE_REPORT,
   PLATFORM_TUNING_POST_PACKAGE_REPAIR_ENABLE,
   PLATFORM_TUNING_POST_PACKAGE_REPAIR_ALL_BANKS,

   // Performace
   PLATFORM_TUNING_BANK_GROUP_SWAP,
   PLATFORM_TUNING_ODTS_CMD_THROTTLE_ENABLE,
   PLATFORM_TUNING_AUTO_REFFINE_GRAN_MODE,
   PLATFORM_TUNING_ADDR_CMD_PARITY_RETRY,
   PLATFORM_TUNING_RCD_PARITY_ENABLE,
   PLATFORM_TUNING_WR_CRC_ENABLE,
   PLATFORM_TUNING_WR_CRC_RETRY,
   PLATFORM_TUNING_ECC_SYMBOL_SIZE,
   PLATFORM_TUNING_DDR4_UECC_RETRY,

   // Power
   PLATFORM_TUNING_ENABLE_POWER_DOWN,
   PLATFORM_TUNING_MEMORY_ALL_CLOCKS_ON,
   PLATFORM_TUNING_POWER_DOWN_MODE,
   PLATFORM_TUNING_TEMPERATURE_CONTROLLED_REFRESH_ENABLE,

   // Platform
   PLATFORM_TUNING_CMD_BUS_TMG,
   PLATFORM_TUNING_DATA_BUS_TMG,

   // Memory Discovery
   PLATFORM_TUNING_SPD_VALUE_OVERRIDE,
   PLATFORM_TUNING_SPD_CRC_IGNORE,

   // UMC Configuration
   PLATFORM_TUNING_GEAR_DOWN_EN,
   PLATFORM_TUNING_CMD_2T_EN,
   PLATFORM_TUNING_WR_PREAMBLE,
   PLATFORM_TUNING_RD_PREAMBLE,
   PLATFORM_TUNING_ODT_PAT_CTRL_CS0,
   PLATFORM_TUNING_ODT_PAT_CTRL_CS1,
   PLATFORM_TUNING_ODT_PAT_CTRL_CS2,
   PLATFORM_TUNING_ODT_PAT_CTRL_CS3,
   PLATFORM_TUNING_TX_EQ_IMPEDANCE_DQ,
   PLATFORM_TUNING_TX_ODT_DRV_STREN,
   PLATFORM_TUNING_TRCDWR,
   PLATFORM_TUNING_TRCDRD,
   PLATFORM_TUNING_TRAS,
   PLATFORM_TUNING_TCL,
   PLATFORM_TUNING_TRP,
   PLATFORM_TUNING_TRTP,
   PLATFORM_TUNING_TRRDDLR,
   PLATFORM_TUNING_TRRDL,
   PLATFORM_TUNING_TRRDS,
   PLATFORM_TUNING_TFAWDLR,
   PLATFORM_TUNING_TFAWSLR,
   PLATFORM_TUNING_TFAW,
   PLATFORM_TUNING_TWTRL,
   PLATFORM_TUNING_TWTRS,
   PLATFORM_TUNING_TCWL,
   PLATFORM_TUNING_TWR,
   PLATFORM_TUNING_TRCPAGE,
   PLATFORM_TUNING_TRFC,
   PLATFORM_TUNING_TRFC2,
   PLATFORM_TUNING_TRFC4,
   PLATFORM_TUNING_TSTAG,
   PLATFORM_TUNING_TSTAGLR,
   PLATFORM_TUNING_TSTAG2LR,
   PLATFORM_TUNING_TSTAG4LR,
   PLATFORM_TUNING_TRDRDBAN,
   PLATFORM_TUNING_TRDRDSCL,
   PLATFORM_TUNING_TRDRDSCDLR,
   PLATFORM_TUNING_TRDRDSC,
   PLATFORM_TUNING_TRDRDSD,
   PLATFORM_TUNING_TRDRDDD,
   PLATFORM_TUNING_TWRWRBAN,
   PLATFORM_TUNING_TWRWRSCL,
   PLATFORM_TUNING_TWRWRSCDLR,
   PLATFORM_TUNING_TWRWRSC,
   PLATFORM_TUNING_TWRWRSD,
   PLATFORM_TUNING_TWRWRDD,
   PLATFORM_TUNING_TWRRDSCDLR,
   PLATFORM_TUNING_TRDWR,
   PLATFORM_TUNING_TWRRD,

   // PHY Configuration
   PLATFORM_TUNING_ADDR_CMD_SETUP,
   PLATFORM_TUNING_CS_ODT_SETUP,
   PLATFORM_TUNING_CKE_SETUP,
   PLATFORM_TUNING_CLK_DRV_STREN,
   PLATFORM_TUNING_ADDR_CMD_DRV_STREN,
   PLATFORM_TUNING_CS_ODT_DRV_STREN,
   PLATFORM_TUNING_CKE_DRV_STREN,
   /// PHY Regs start
   PLATFORM_TUNING_PHY_REG_START,
   PLATFORM_TUNING_RX_ENABLE_DELAY,
   PLATFORM_TUNING_TX_DQ_DELAY,
   PLATFORM_TUNING_RX_PB_DELAY,
   PLATFORM_TUNING_RX_CLK_DELAY,
   PLATFORM_TUNING_VREF_DAC0,
   PLATFORM_TUNING_VREF_DAC1,
   PLATFORM_TUNING_VREF_IN_GLOBAL,
   PLATFORM_TUNING_PHY_REG_END,
   /// PHY Regs end

   // 1D training input
   PLATFORM_TUNING_1D_TRAIN_MR0,
   PLATFORM_TUNING_1D_TRAIN_MR1,
   PLATFORM_TUNING_1D_TRAIN_MR2,
   PLATFORM_TUNING_1D_TRAIN_MR3,
   PLATFORM_TUNING_1D_TRAIN_MR4,
   PLATFORM_TUNING_1D_TRAIN_MR5,
   PLATFORM_TUNING_1D_TRAIN_MR6,
   PLATFORM_TUNING_1D_TRAIN_PHY_VREF,
   PLATFORM_TUNING_1D_TRAIN_SEQUENCE_CTRL,
   PLATFORM_TUNING_1D_TRAIN_DFI_MRL_MARGIN,
   PLATFORM_TUNING_1D_CUSTOM_MSG,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL0,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL1,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL2,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL3,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL4,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL5,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL6,
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL7,
   PLATFORM_TUNING_1D_TRAIN_ALT_WCAS_L,

   // 2D training input
   PLATFORM_TUNING_2D_TRAIN_MR0,
   PLATFORM_TUNING_2D_TRAIN_MR1,
   PLATFORM_TUNING_2D_TRAIN_MR2,
   PLATFORM_TUNING_2D_TRAIN_MR3,
   PLATFORM_TUNING_2D_TRAIN_MR4,
   PLATFORM_TUNING_2D_TRAIN_MR5,
   PLATFORM_TUNING_2D_TRAIN_MR6,
   PLATFORM_TUNING_2D_TRAIN_PHY_VREF,
   PLATFORM_TUNING_2D_TRAIN_SEQUENCE_CTRL,
   PLATFORM_TUNING_2D_TRAIN_DFI_MRL_MARGIN,
   PLATFORM_TUNING_2D_TRAIN_RX2D_TRAIN_OPT,
   PLATFORM_TUNING_2D_TRAIN_TX2D_TRAIN_OPT,
   PLATFORM_TUNING_2D_CUSTOM_MSG,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL0,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL1,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL2,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL3,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL4,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL5,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL6,
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL7,
   PLATFORM_TUNING_2D_TRAIN_ALT_WCAS_L,

   //Validity
   PLATFORM_TUNING_VALIDITY_DRAM_MFG_ID,
   PLATFORM_TUNING_VALIDITY_MODULE_MFG_ID,
   PLATFORM_TUNING_VALIDITY_DRAM_STEPPING,
   PLATFORM_TUNING_VALIDITY_TERMINATOR,

   // END! END! END!
   PLATFORM_TUNING_ENTRY_END,
   PLATFORM_TUNING_TERMINATOR = 0xFEEF
} PLATFORM_TUNING_ENTRY;

typedef UINT8 PTO_ENTRY;

#define OP_MINUS 0x11
#define OP_PLUS 0x22
#define OP_OVERRIDE 0x33


//////////////////////////
//
// USER INTERFACE MACRO(S)
//
//////////////////////////
#define DW_TO_DB(dw) \
 ((UINT8)(((UINT16) (dw)) & 0xFF)), ((UINT8)((((UINT16) (dw)) >> 8) & 0xFF))

#define DD_TO_DB(dd) \
 ((UINT8)(((UINT32) (dd)) & 0xFF)), ((UINT8)((((UINT32) (dd)) >> 8) & 0xFF)), ((UINT8)((((UINT32) (dd)) >> 16) & 0xFF)), ((UINT8)((((UINT32) (dd)) >> 24) & 0xFF))

#define NIBBLE_TO_DB(nibble0, nibble1) \
 ((UINT8)(((UINT8) (nibble0) & 0x0F) | (((UINT8) (nibble1) << 4) & 0xF0)))


#define MAKE_PTO_TERMINATE() DW_TO_DB(PLATFORM_TUNING_TERMINATOR)
//
// Enablement entrys
//
#define MAKE_PTO_CHIPSEL_INTLV_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
  DW_TO_DB(PLATFORM_TUNING_CHIPSEL_INTLV), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Ecc
#define MAKE_PTO_ECC_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_ECC), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Parity
#define MAKE_PTO_PARITY_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_PARITY), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Mem Bus Limit
#define MAKE_PTO_MEM_BUS_LIMIT_ENTRY(SocketBitMap, ChannelBitMap, Speed) \
   DW_TO_DB(PLATFORM_TUNING_MEM_BUS_LIMIT), 7, ANY_SOCKET, ANY_CHANNEL, DW_TO_DB((Speed))
// Mbist Enable
#define MAKE_PTO_MBIST_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Mbist Test Mode
#define MAKE_PTO_MBIST_TEST_MODE_ENTRY(SocketBitMap, ChannelBitMap, Mode) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_TEST_MODE), 6, ANY_SOCKET, ANY_CHANNEL, (Mode)
// Mbist Aggressor On
#define MAKE_PTO_MBIST_AGGRESSOR_ON_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_AGGRESSOR_ON), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Mbist Per Bit Secondary Die Report
#define MAKE_PTO_MBIST_PER_BIT_SECONDARY_DIE_REPORT_ENTRY(SocketBitMap, ChannelBitMap, Value8) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_PER_BIT_SECONDARY_DIE_REPORT), 6, ANY_SOCKET, (ChannelBitMap), (Value8)
// Post Package Repair Enable
#define MAKE_PTO_POST_PACKAGE_REPAIR_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_POST_PACKAGE_REPAIR_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Post Package Repair All Banks
#define MAKE_PTO_POST_PACKAGE_REPAIR_ALL_BANKS_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_POST_PACKAGE_REPAIR_ALL_BANKS), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

//
// Performance entrys
//
// Bank Group Swap
#define MAKE_PTO_BANK_GROUP_SWAP_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_BANK_GROUP_SWAP), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Odts Command Throttle Enable
#define MAKE_PTO_ODTS_CMD_THROTTLE_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_ODTS_CMD_THROTTLE_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Auto Reffine Gran Mode
#define MAKE_PTO_AUTO_REFFINE_GRAN_MODE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_AUTO_REFFINE_GRAN_MODE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)
// Address Command Parity Retry
#define MAKE_PTO_ADDR_CMD_PARITY_RETRY_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_ADDR_CMD_PARITY_RETRY), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Rcd Parity
#define MAKE_PTO_RCD_PARITY_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_RCD_PARITY_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// WrCrc Enable
#define MAKE_PTO_WR_CRC_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_WR_CRC_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// WrCrc Retry
#define MAKE_PTO_WR_CRC_RETRY_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_WR_CRC_RETRY), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)
// Ecc symbol size
#define MAKE_PTO_ECC_SYMBOL_SIZE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_ECC_SYMBOL_SIZE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

//
// Power entrys
//
// Enable power down
#define MAKE_PTO_ENABLE_POWER_DOWN_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_ENABLE_POWER_DOWN), 6, ANY_SOCKET, ANY_CHANNEL, (Value)
// Memory all clocks on
#define MAKE_PTO_ENABLE_TUNING_MEMORY_ALL_CLOCKS_ON_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_MEMORY_ALL_CLOCKS_ON), 6, ANY_SOCKET, ANY_CHANNEL, (Value)
// Power down mode
#define MAKE_PTO_ENABLE_POWER_DOWN_MODE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_POWER_DOWN_MODE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)
// Temperature controlled refresh enable
#define MAKE_PTO_TEMPERATURE_CONTROLLED_REFRESH_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_TEMPERATURE_CONTROLLED_REFRESH_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

//
// Platform entrys
//
// Command Bus Timing
#define MAKE_PTO_CMD_BUS_TMG_ENTRY(SocketBitMap, ChannelBitMap, DimmPerCh, SpeedBitMap, Width, VddIo, Dimm0Rank, Dimm1Rank, SlowMode, AddrCmdCtrl, CkeStrength, CsOdtStrength, AddrCmdStrength, ClkStrength) \
   DW_TO_DB(PLATFORM_TUNING_CMD_BUS_TMG), 22, (SocketBitMap), (ChannelBitMap), (DimmPerCh), DD_TO_DB((SpeedBitMap)), (Width), (VddIo),\
   NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (SlowMode), DD_TO_DB((AddrCmdCtrl)), (CkeStrength), (CsOdtStrength), (AddrCmdStrength), (ClkStrength)
// Data Bus Timing
#define MAKE_PTO_DATA_BUS_TMG_ENTRY(SocketBitMap, ChannelBitMap, DimmPerCh, SpeedBitMap, Width, VddIo, Dimm0Rank, Dimm1Rank, RttNom, RttWr, RttPark, DqDrvStrength, DqsDrvStrength, OdtDrvStrength) \
  DW_TO_DB(PLATFORM_TUNING_DATA_BUS_TMG), 19, (SocketBitMap), (ChannelBitMap), (DimmPerCh), DD_TO_DB((SpeedBitMap)), (Width), (VddIo),\
  NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), RttNom, RttWr, RttPark, DqDrvStrength, DqsDrvStrength, OdtDrvStrength

//
// Memory Discovery entrys
//
// SPD Value Override
#define MAKE_PTO_SPD_VALUE_OVERRIDE_ENTRY(SocketBitMap, ChannelBitMap, Dimm, Offset, Value) \
   DW_TO_DB(PLATFORM_TUNING_SPD_VALUE_OVERRIDE), 8, (SocketBitMap), (ChannelBitMap), (Dimm), (Offset), (Value)
// SPD Crc Ignore
#define MAKE_PTO_SPD_CRC_IGNORE_ENTRY(SocketBitMap, ChannelBitMap, Dimm, Enable) \
   DW_TO_DB(PLATFORM_TUNING_SPD_CRC_IGNORE), 7, ANY_SOCKET, ANY_CHANNEL, ALL_DIMMS, (Enable)

//
// UMC Configuration entrys
//
// Gear Down Enable
#define MAKE_PTO_GEAR_DOWN_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Enable) \
   DW_TO_DB(PLATFORM_TUNING_GEAR_DOWN_EN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Enable)
// Command 2T Enable
#define MAKE_PTO_CMD_2T_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Enable) \
   DW_TO_DB(PLATFORM_TUNING_CMD_2T_EN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Enable)
// Wr preamble
#define MAKE_PTO_WR_PREAMBLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_WR_PREAMBLE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Rd preamble
#define MAKE_PTO_RD_PREAMBLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_RD_PREAMBLE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Odt pattern ctrl cs0
#define MAKE_PTO_ODT_PAT_CTRL_CS0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS0), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))
// Odt pattern ctrl cs1
#define MAKE_PTO_ODT_PAT_CTRL_CS1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS1), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))
// Odt pattern ctrl cs2
#define MAKE_PTO_ODT_PAT_CTRL_CS2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS2), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))
// Odt pattern ctrl cs3
#define MAKE_PTO_ODT_PAT_CTRL_CS3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS3), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))
// Tx eq impedance Dq
#define MAKE_PTO_TX_EQ_IMPEDANCE_DQ_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_TX_EQ_IMPEDANCE_DQ), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), Value
// Tx odt drive strength
#define MAKE_PTO_TX_ODT_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_TX_ODT_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), Value
// Trcdwr
#define MAKE_PTO_TRCDWR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRCDWR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Trcdrd
#define MAKE_PTO_TRCDRD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRCDRD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Tras
#define MAKE_PTO_TRAS_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRAS), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Tcl
#define MAKE_PTO_TCL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TCL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Trp
#define MAKE_PTO_TRP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Trtp
#define MAKE_PTO_TRTP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRTP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrrdDlr
#define MAKE_PTO_TRRDDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRRDDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrrdL
#define MAKE_PTO_TRRDL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRRDL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrrdS
#define MAKE_PTO_TRRDS_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRRDS), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TfawDlr
#define MAKE_PTO_TFAWDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TFAWDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TfawSlr
#define MAKE_PTO_TFAWSLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TFAWSLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Tfaw
#define MAKE_PTO_TFAW_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TFAW), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwtrL
#define MAKE_PTO_TWTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWTRL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwtrS
#define MAKE_PTO_TWTRS_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWTRS), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Tcwl
#define MAKE_PTO_TCWL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TCWL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Twr
#define MAKE_PTO_TWR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Trcpage
#define MAKE_PTO_TRCPAGE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRCPAGE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Trfc
#define MAKE_PTO_TRFC_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16InMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRFC), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16InMemClk))
// Trfc2
#define MAKE_PTO_TRFC2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16InMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRFC2), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16InMemClk))
// Trfc4
#define MAKE_PTO_TRFC4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16InMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRFC4), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16InMemClk))
// Tstag
#define MAKE_PTO_TSTAG_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAG), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TstagLr
#define MAKE_PTO_TSTAGLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAGLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Tstag2Lr
#define MAKE_PTO_TSTAG2LR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAG2LR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Tstag4Lr
#define MAKE_PTO_TSTAG4LR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAG4LR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrdrdBan
#define MAKE_PTO_TRDRDBAN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDBAN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrdrdScL
#define MAKE_PTO_TRDRDSCL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSCL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrdrdScDlr
#define MAKE_PTO_TRDRDSCDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSCDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrdrdSc
#define MAKE_PTO_TRDRDSC_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSC), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrdrdSd
#define MAKE_PTO_TRDRDSD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TrdrdDd
#define MAKE_PTO_TRDRDDD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDDD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrwrBan
#define MAKE_PTO_TWRWRBAN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRBAN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrwrScL
#define MAKE_PTO_TWRWRSCL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSCL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrwrScDlr
#define MAKE_PTO_TWRWRSCDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSCDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrwrSc
#define MAKE_PTO_TWRWRSC_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSC), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrwrSd
#define MAKE_PTO_TWRWRSD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrwrDd
#define MAKE_PTO_TWRWRDD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRDD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// TwrrdScDlr
#define MAKE_PTO_TWRRDSCDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRRDSCDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Trdwr
#define MAKE_PTO_TRDWR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDWR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// Twrrd
#define MAKE_PTO_TWRRD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRRD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), ValueInMemClk
// DDR4 UECC retry
#define MAKE_PTO_DDR4_UECC_RETRY_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_DDR4_UECC_RETRY), 8, ANY_SOCKET, ANY_CHANNEL, 0xFF/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/, (Value)

//
// PHY Configuration entrys
//
// Address Command Setup
#define MAKE_PTO_ADDR_CMD_SETUP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_ADDR_CMD_SETUP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Cs ODT Setup
#define MAKE_PTO_CS_ODT_SETUP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CS_ODT_SETUP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Cke Setup
#define MAKE_PTO_CKE_SETUP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CKE_SETUP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Clk drive strength
#define MAKE_PTO_CLK_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CLK_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Address command drive strength
#define MAKE_PTO_ADDR_CMD_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_ADDR_CMD_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Cs ODT drive strength
#define MAKE_PTO_CS_ODT_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CS_ODT_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Cke drive strength
#define MAKE_PTO_CKE_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CKE_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// Rx enable delay
#define MAKE_PTO_RX_ENABLE_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Nibble, Value16) \
   DW_TO_DB(PLATFORM_TUNING_RX_ENABLE_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), (Nibble), 0xFF/*Dq*/, DW_TO_DB((Value16))
// Tx Dq delay
#define MAKE_PTO_TX_DQ_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_TX_DQ_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))
// Rx PB delay
#define MAKE_PTO_RX_PB_DELAY_ENTRY(SocketBitMap, ChannelBitMap, Operation, Dimm, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_RX_PB_DELAY), 14, (SocketBitMap), (ChannelBitMap), 0/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))
// Rx clk delay
#define MAKE_PTO_RX_CLK_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Nibble, Value16) \
   DW_TO_DB(PLATFORM_TUNING_RX_CLK_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), (Nibble), 0xFF/*Dq*/, DW_TO_DB((Value16))
// Vref DAC0
#define MAKE_PTO_VREF_DAC_0_ENTRY(SocketBitMap, ChannelBitMap, Operation, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_VREF_DAC0), 14, (SocketBitMap), (ChannelBitMap), 0/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), 0xFF/*Dimm*/, (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))
// Vref DAC1
#define MAKE_PTO_VREF_DAC_1_ENTRY(SocketBitMap, ChannelBitMap, Operation, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_VREF_DAC1), 14, (SocketBitMap), (ChannelBitMap), 0/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), 0xFF/*Dimm*/, (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))
// Vref In Global
#define MAKE_PTO_VREF_IN_GLOBAL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Value16) \
   DW_TO_DB(PLATFORM_TUNING_VREF_IN_GLOBAL), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), 0xFF/*Dimm*/, 0xFF/*Byte*/, 0xFF/*Nibble*/, 0xFF/*Dq*/, DW_TO_DB((Value16))

//
// 1D training input entrys
//
// 1D Train MR0
#define MAKE_PTO_1D_TRAIN_MR0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR0), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train MR1
#define MAKE_PTO_1D_TRAIN_MR1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR1), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train MR2
#define MAKE_PTO_1D_TRAIN_MR2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR2), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train MR3
#define MAKE_PTO_1D_TRAIN_MR3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR3), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train MR4
#define MAKE_PTO_1D_TRAIN_MR4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR4), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train MR5
#define MAKE_PTO_1D_TRAIN_MR5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR5), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train MR6
#define MAKE_PTO_1D_TRAIN_MR6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR6), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train Phy Vref
#define MAKE_PTO_1D_TRAIN_PHY_VREF_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_PHY_VREF), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train Sequence Control
#define MAKE_PTO_1D_TRAIN_SEQUENCE_CTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_SEQUENCE_CTRL), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 1D Train DFI MRL Margin
#define MAKE_PTO_1D_TRAIN_DFI_MRL_MARGIN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_DFI_MRL_MARGIN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Custom Message
#define MAKE_PTO_1D_CUSTOM_MSG_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Offset, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_CUSTOM_MSG), 10, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Offset)),\
   (Value)
// 1D Train AcsmOdtCtrl0
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL0), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl1
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL1), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl2
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL2), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl3
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL3), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl4
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL4), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl5
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL5), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl6
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL6), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train AcsmOdtCtrl7
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL7_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL7), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 1D Train ALT_WCAS_L
#define MAKE_PTO_1D_TRAIN_ALT_WCAS_L_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ALT_WCAS_L), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

//
// 2D training input entrys
//
// 2D Train MR0
#define MAKE_PTO_2D_TRAIN_MR0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR0), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train MR1
#define MAKE_PTO_2D_TRAIN_MR1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR1), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train MR2
#define MAKE_PTO_2D_TRAIN_MR2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR2), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train MR3
#define MAKE_PTO_2D_TRAIN_MR3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR3), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train MR4
#define MAKE_PTO_2D_TRAIN_MR4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR4), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train MR5
#define MAKE_PTO_2D_TRAIN_MR5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR5), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train MR6
#define MAKE_PTO_2D_TRAIN_MR6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR6), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train Phy Vref
#define MAKE_PTO_2D_TRAIN_PHY_VREF_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_PHY_VREF), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train Sequence Control
#define MAKE_PTO_2D_TRAIN_SEQUENCE_CTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_SEQUENCE_CTRL), 9,(SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))
// 2D Train DFI MRL Margin
#define MAKE_PTO_2D_TRAIN_DFI_MRL_MARGIN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_DFI_MRL_MARGIN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train RX2D Train Opt
#define MAKE_PTO_2D_TRAIN_RX2D_TRAIN_OPT_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_RX2D_TRAIN_OPT), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train TX2D Train Opt
#define MAKE_PTO_2D_TRAIN_TX2D_TRAIN_OPT_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_TX2D_TRAIN_OPT), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Custom Message
#define MAKE_PTO_2D_CUSTOM_MSG_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Offset, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_CUSTOM_MSG), 10, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Offset)),\
   (Value)
// 2D Train AcsmOdtCtrl0
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL0), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl1
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL1), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl2
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL2), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl3
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL3), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl4
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL4), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl5
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL5), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl6
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL6), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train AcsmOdtCtrl7
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL7_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL7), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)
// 2D Train ALT_WCAS_L
#define MAKE_PTO_2D_TRAIN_ALT_WCAS_L_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ALT_WCAS_L), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

//
// Validity macros
//
// DramManufacturersIDCode
#define MAKE_PTO_VALIDITY_DRAM_MFG_ID_ENTRY(SocketBitMap, ChannelBitMap, DramMfgId) \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_DRAM_MFG_ID), 7, (SocketBitMap), (ChannelBitMap), DW_TO_DB((DramMfgId))
// ModuleManufacturersIDCode
#define MAKE_PTO_VALIDITY_MODULE_MFG_ID_ENTRY(SocketBitMap, ChannelBitMap, ModuleMfgId) \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_MODULE_MFG_ID), 7, (SocketBitMap), (ChannelBitMap), DW_TO_DB((ModuleMfgId))
// DramStepping
#define MAKE_PTO_VALIDITY_DRAM_STEPPING_ENTRY(SocketBitMap, ChannelBitMap, DramStepping) \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_DRAM_STEPPING), 7, (SocketBitMap), (ChannelBitMap), DW_TO_DB((DramStepping))
// Vality Check End
#define MAKE_PTO_VALIDITY_END() \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_TERMINATOR), 3

#endif // _APCB_MM_H_


