/*******************************************************************************
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define Platform Tuning Data Structures
 */
#ifndef _APCB_MEM_PLATFORM_TUNING_H_
#define _APCB_MEM_PLATFORM_TUNING_H_

/**
 * @brief Memory Pstate Types
 */
typedef enum {
  MEMORY_PSTATE0,   ///< Memory Pstate 0
  MEMORY_PSTATE1,   ///< Memory Pstate 1
  MEMORY_PSTATE2,   ///< Memory Pstate 2
  MEMORY_PSTATE3,   ///< Memory Pstate 3
} MEM_PSTATE;

/**
 * @brief  SMB Test Enable Encoding
 */
#define SMB_TESTEnable    (1 << 0)
/**
 * @brief  SMB Short Reset Encoding
 */
#define SMB_ShortReset    (1 << 1)
/**
 * @brief  SMB Short Pattern Encoding
 */
#define SMB_ShortPattern  (1 << 2)
/**
 * @brief  SMB Input Vref Encoding
 */
#define SMB_InputVref     (1 << 3)
/**
 * @brief  SMB Skip Vref UPD Encoding
 */
#define SMB_SkipVrefUpd   (1 << 4)
/**
 * @brief  SMB Per Rank Timing Encoding
 */
#define SMB_PER_RANK_TMG    0x01
/**
 * @brief  SMB 2T Timing Encoding
 */
#define SMB_2T_TMG          0x01
/**
 * @brief  SMB CS MUX 45 Encoding
 */
#define SMB_CSMUX_45_ADDR   0x04
/**
 * @brief  SMB CS MUX 67 Encoding
 */
#define SMB_CSMUX_67_ADDR   0x08
/**
 * @brief  SMB TIMING MUX 67 Encoding
 */
#define SMB_TMG_MUX_67_ADDR 0x10
/**
 * @brief  Ddr4 UDIMM Dram Type Encoding
 */
#define SMB_DRAM_TYPE_DDR4_UDIMM  0x02
/**
 * @brief  SMB Sequence control Encoding: [0] DevInit - Device/phy initialization. Should always be set.
 */
#define SMB_SEQ_DEVINIT     (1 << 0)
/**
 * @brief SMB Sequence control Encoding : [1] WrLvl - Write leveling
 */
#define SMB_SEQ_WRLVL       (1 << 1)
/**
 * @brief SMB Sequence control Encoding : [2] RxEn - Read gate training
 */
#define SMB_SEQ_RXEN        (1 << 2)
/**
 * @brief SMB Sequence control Encoding : [3] RdDQS1D - 1d read dqs training
 */
#define SMB_SEQ_RDDQS1D     (1 << 3)
/**
 * @brief SMB Sequence control Encoding : [4] WrDQ1D - 1d write dq training
 */
#define SMB_SEQ_WRDQ1D      (1 << 4)
/**
 * @brief SMB Sequence control Encoding : [5] rd2D - 2d read dqs training
 */
#define SMB_SEQ_RD2D        (1 << 5)
/**
 * @brief SMB Sequence control Encoding : [6] wr2D - 2d write dq training
 */
#define SMB_SEQ_WR2D        (1 << 6)
/**
 * @brief SMB Sequence control Encoding : [7] LcdlCal - LCDL offset calibration training
 */
#define SMB_SEQ_LCDLCAL     (1 << 7)
/**
 * @brief SMB Sequence control Encoding : [8] RdDeskew - Per lane read dq deskew training
 */
#define SMB_SEQ_RDDESKEW    (1 << 8)
/**
 * @brief SMB Sequence control Encoding : [9] MxRdLat - Max read latency training
 */
#define SMB_SEQ_MXRDLAT     (1 << 9)
/**
 * @brief SMB Sequence control Encoding : [10] DWL - LDRIMM DRAM Write Leveling
 */
#define SMB_SEQ_DWL         (1 << 10)
/**
 * @brief SMB Sequence control Encoding : [11] MREP - LRDIMM DRAM Interface MDQ Receive Enable Phase training
 */
#define SMB_SEQ_MREP        (1 << 11)
/**
 * @brief SMB Sequence control Encoding : [12] MRD - DRAM-to-DB Read Delay training
 */
#define SMB_SEQ_MRD         (1 << 12)
/**
 * @brief SMB Sequence control Encoding : [13] MWD - DB-to-DRAM Write Delay training
 */
#define SMB_SEQ_MWD         (1 << 13)
/**
 * @brief SMB Sequence control Encoding : [0]  1 = Run rx2D with DFE, 0 = Run rx2D with DFE off
 */
#define SMB_DFE 0x01
/**
 * @brief SMB Sequence control Encoding : [0]  1 = Run rx2D with FFE, 0 = Run rx2D with FFE off
 */
#define SMB_FFE 0x01

/**
 * @brief Platform Tuning
 */
typedef enum _PLATFORM_TUNING_ENTRY {
   PLATFORM_TUNING_ENTRY_START = 0x1000,                  ///< PLATFORM_TUNING_ENTRY_START State = 0x1000
   // Enablement
   PLATFORM_TUNING_CHIPSEL_INTLV,                         ///< PLATFORM_TUNING_CHIPSEL_INTLV State = 0x1001
   PLATFORM_TUNING_ECC,                                   ///< PLATFORM_TUNING_ECC = 0x1002
   PLATFORM_TUNING_PARITY,                                ///< PLATFORM_TUNING_PARITY = 0x1003
   PLATFORM_TUNING_MEM_BUS_LIMIT,                         ///< PLATFORM_TUNING_MEM_BUS_LIMIT = 0x1004
   PLATFORM_TUNING_MBIST_ENABLE,                          ///< PLATFORM_TUNING_MBIST_ENABLE = 0x1005
   PLATFORM_TUNING_MBIST_TEST_MODE,                       ///< PLATFORM_TUNING_MBIST_TEST_MODE = 0x1006
   PLATFORM_TUNING_MBIST_AGGRESSOR_ON,                    ///< PLATFORM_TUNING_MBIST_AGGRESSOR_ON = 0x1007
   PLATFORM_TUNING_MBIST_PER_BIT_SECONDARY_DIE_REPORT,    ///< PLATFORM_TUNING_MBIST_PER_BIT_SECONDARY_DIE_REPORT = 0x1008
   PLATFORM_TUNING_POST_PACKAGE_REPAIR_ENABLE,            ///< PLATFORM_TUNING_POST_PACKAGE_REPAIR_ENABLE = 0x1009
   PLATFORM_TUNING_POST_PACKAGE_REPAIR_ALL_BANKS,         ///< PLATFORM_TUNING_POST_PACKAGE_REPAIR_ALL_BANKS = 0x100A
   // Performace
   PLATFORM_TUNING_BANK_GROUP_SWAP,                       ///< PLATFORM_TUNING_BANK_GROUP_SWAP = 0x100B
   PLATFORM_TUNING_ODTS_CMD_THROTTLE_ENABLE,              ///< PLATFORM_TUNING_ODTS_CMD_THROTTLE_ENABLE = 0x100C
   PLATFORM_TUNING_AUTO_REFFINE_GRAN_MODE,                ///< PLATFORM_TUNING_AUTO_REFFINE_GRAN_MODE = 0x100D
   PLATFORM_TUNING_ADDR_CMD_PARITY_RETRY,                 ///< PLATFORM_TUNING_ADDR_CMD_PARITY_RETRY = 0x100E
   PLATFORM_TUNING_RCD_PARITY_ENABLE,                     ///< PLATFORM_TUNING_RCD_PARITY_ENABLE = 0x100F
   PLATFORM_TUNING_WR_CRC_ENABLE,                         ///< PLATFORM_TUNING_WR_CRC_ENABLE = 0x1010
   PLATFORM_TUNING_WR_CRC_RETRY,                          ///< PLATFORM_TUNING_WR_CRC_RETRY = 0x1011
   PLATFORM_TUNING_ECC_SYMBOL_SIZE,                       ///< PLATFORM_TUNING_ECC_SYMBOL_SIZE = 0x1012
   PLATFORM_TUNING_DDR4_UECC_RETRY,                       ///< PLATFORM_TUNING_DDR4_UECC_RETRY = 0x1013
   // Power
   PLATFORM_TUNING_ENABLE_POWER_DOWN,                     ///< PLATFORM_TUNING_ENABLE_POWER_DOWN = 0x1014
   PLATFORM_TUNING_MEMORY_ALL_CLOCKS_ON,                  ///< PLATFORM_TUNING_MEMORY_ALL_CLOCKS_ON = 0x1015
   PLATFORM_TUNING_POWER_DOWN_MODE,                       ///< PLATFORM_TUNING_POWER_DOWN_MODE = 0x1016
   PLATFORM_TUNING_TEMPERATURE_CONTROLLED_REFRESH_ENABLE, ///< PLATFORM_TUNING_TEMPERATURE_CONTROLLED_REFRESH_ENABLE = 0x1017
   // Platform
   PLATFORM_TUNING_CMD_BUS_TMG,                           ///< PLATFORM_TUNING_CMD_BUS_TMG = 0x1018
   PLATFORM_TUNING_DATA_BUS_TMG,                          ///< PLATFORM_TUNING_DATA_BUS_TMG = 0x1019
   // Memory Discovery
   PLATFORM_TUNING_SPD_VALUE_OVERRIDE,                    ///< PLATFORM_TUNING_SPD_VALUE_OVERRIDE - 0x101A
   PLATFORM_TUNING_SPD_CRC_IGNORE,                        ///< PLATFORM_TUNING_SPD_CRC_IGNORE = 0x101B
   // UMC Configuration
   PLATFORM_TUNING_GEAR_DOWN_EN,                          ///< PLATFORM_TUNING_GEAR_DOWN_EN = 0x101C
   PLATFORM_TUNING_CMD_2T_EN,                             ///< PLATFORM_TUNING_CMD_2T_EN = 0x101D
   PLATFORM_TUNING_WR_PREAMBLE,                           ///< PLATFORM_TUNING_WR_PREAMBLE = 0x101E
   PLATFORM_TUNING_RD_PREAMBLE,                           ///< PLATFORM_TUNING_RD_PREAMBLE = 0x101F
   PLATFORM_TUNING_ODT_PAT_CTRL_CS0,                      ///< PLATFORM_TUNING_ODT_PAT_CTRL_CS0 = 0x1020
   PLATFORM_TUNING_ODT_PAT_CTRL_CS1,                      ///< PLATFORM_TUNING_ODT_PAT_CTRL_CS1 = 0x1021
   PLATFORM_TUNING_ODT_PAT_CTRL_CS2,                      ///< PLATFORM_TUNING_ODT_PAT_CTRL_CS2 = 0x1022
   PLATFORM_TUNING_ODT_PAT_CTRL_CS3,                      ///< PLATFORM_TUNING_ODT_PAT_CTRL_CS3 = 0x1023
   PLATFORM_TUNING_TX_EQ_IMPEDANCE_DQ,                    ///< PLATFORM_TUNING_TX_EQ_IMPEDANCE_DQ = 0x1024
   PLATFORM_TUNING_TX_IMPEDANCE_DQ,                       ///< PLATFORM_TUNING_TX_IMPEDANCE_DQ = 0x1025
   PLATFORM_TUNING_TX_EQ_HI_IMPEDANCE_DQ,                 ///< PLATFORM_TUNING_TX_EQ_HI_IMPEDANCE_DQ = 0x1026
   PLATFORM_TUNING_TX_ODT_DRV_STREN,                      ///< PLATFORM_TUNING_TX_ODT_DRV_STREN = 0x1027
   PLATFORM_TUNING_TRCDWR,                                ///< PLATFORM_TUNING_TRCDWR = 0x1028
   PLATFORM_TUNING_TRCDRD,                                ///< PLATFORM_TUNING_TRCDRD = 0x1029
   PLATFORM_TUNING_TRAS,                                  ///< PLATFORM_TUNING_TRAS = 0x102A
   PLATFORM_TUNING_TCL,                                   ///< PLATFORM_TUNING_TCL  = 0x102B
   PLATFORM_TUNING_TRP,                                   ///< PLATFORM_TUNING_TRP = 0x102C
   PLATFORM_TUNING_TRTP,                                  ///< PLATFORM_TUNING_TRTP = 0x102D
   PLATFORM_TUNING_TRRDDLR,                               ///< PLATFORM_TUNING_TRRDDLR = 0x102E
   PLATFORM_TUNING_TRRDL,                                 ///< PLATFORM_TUNING_TRRDL = 0x102F
   PLATFORM_TUNING_TRRDS,                                 ///< PLATFORM_TUNING_TRRDS = 0x1030
   PLATFORM_TUNING_TFAWDLR,                               ///< PLATFORM_TUNING_TFAWDLR = 0x1031
   PLATFORM_TUNING_TFAWSLR,                               ///< PLATFORM_TUNING_TFAWSLR = 0x1032
   PLATFORM_TUNING_TFAW,                                  ///< PLATFORM_TUNING_TFAW = 0x1033
   PLATFORM_TUNING_TWTRL,                                 ///< PLATFORM_TUNING_TWTRL = 0x1034
   PLATFORM_TUNING_TWTRS,                                 ///< PLATFORM_TUNING_TWTRS = 0x1035
   PLATFORM_TUNING_TCWL,                                  ///< PLATFORM_TUNING_TCWL = 0x1036
   PLATFORM_TUNING_TWR,                                   ///< PLATFORM_TUNING_TWR = 0x1037
   PLATFORM_TUNING_TRCPAGE,                               ///< PLATFORM_TUNING_TRCPAGE = 0x1038
   PLATFORM_TUNING_TRFC,                                  ///< PLATFORM_TUNING_TRFC = 0x1039
   PLATFORM_TUNING_TRFC2,                                 ///< PLATFORM_TUNING_TRFC2 = 0x103A
   PLATFORM_TUNING_TRFC4,                                 ///< PLATFORM_TUNING_TRFC4 = 0x103B
   PLATFORM_TUNING_TSTAG,                                 ///< PLATFORM_TUNING_TSTAG = 0x103C
   PLATFORM_TUNING_TSTAGLR,                               ///< PLATFORM_TUNING_TSTAGLR = 0x103D
   PLATFORM_TUNING_TSTAG2LR,                              ///< PLATFORM_TUNING_TSTAG2LR = 0x103E
   PLATFORM_TUNING_TSTAG4LR,                              ///< PLATFORM_TUNING_TSTAG4LR = 0x103F
   PLATFORM_TUNING_TRDRDBAN,                              ///< PLATFORM_TUNING_TRDRDBAN = 0x1040
   PLATFORM_TUNING_TRDRDSCL,                              ///< PLATFORM_TUNING_TRDRDSCL = 0x1041
   PLATFORM_TUNING_TRDRDSCDLR,                            ///< PLATFORM_TUNING_TRDRDSCDLR = 0x1042
   PLATFORM_TUNING_TRDRDSC,                               ///< PLATFORM_TUNING_TRDRDSC = 0x1043
   PLATFORM_TUNING_TRDRDSD,                               ///< PLATFORM_TUNING_TRDRDSD = 0x1044
   PLATFORM_TUNING_TRDRDDD,                               ///< PLATFORM_TUNING_TRDRDDD = 0x1045
   PLATFORM_TUNING_TWRWRBAN,                              ///< PLATFORM_TUNING_TWRWRBAN = 0x1046
   PLATFORM_TUNING_TWRWRSCL,                              ///< PLATFORM_TUNING_TWRWRSCL = 0x1047
   PLATFORM_TUNING_TWRWRSCDLR,                            ///< PLATFORM_TUNING_TWRWRSCDLR = 0x1048
   PLATFORM_TUNING_TWRWRSC,                               ///< PLATFORM_TUNING_TWRWRSC = 0x1049
   PLATFORM_TUNING_TWRWRSD,                               ///< PLATFORM_TUNING_TWRWRSD = 0x104A
   PLATFORM_TUNING_TWRWRDD,                               ///< PLATFORM_TUNING_TWRWRDD = 0x104B
   PLATFORM_TUNING_TWRRDSCDLR,                            ///< PLATFORM_TUNING_TWRRDSCDLR = 0x104C
   PLATFORM_TUNING_TRDWR,                                 ///< PLATFORM_TUNING_TRDWR = 0x104D
   PLATFORM_TUNING_TWRRD,                                 ///< PLATFORM_TUNING_TWRRD = 0x104E
   // PHY Configuration
   PLATFORM_TUNING_ADDR_CMD_SETUP,                        ///< PLATFORM_TUNING_ADDR_CMD_SETUP = 0x104F
   PLATFORM_TUNING_CS_ODT_SETUP,                          ///< PLATFORM_TUNING_CS_ODT_SETUP = 0x1050
   PLATFORM_TUNING_CKE_SETUP,                             ///< PLATFORM_TUNING_CKE_SETUP = 0x1051
   PLATFORM_TUNING_CLK_DRV_STREN,                         ///< PLATFORM_TUNING_CLK_DRV_STREN = 0x1052
   PLATFORM_TUNING_ADDR_CMD_DRV_STREN,                    ///< PLATFORM_TUNING_ADDR_CMD_DRV_STREN = 0x1053
   PLATFORM_TUNING_CS_ODT_DRV_STREN,                      ///< PLATFORM_TUNING_CS_ODT_DRV_STREN = 0x1054
   PLATFORM_TUNING_CKE_DRV_STREN,                         ///< PLATFORM_TUNING_CKE_DRV_STREN = 0x1055
   /// PHY Regs start
   PLATFORM_TUNING_PHY_REG_START,                         ///< PLATFORM_TUNING_PHY_REG_START = 0x1056
   PLATFORM_TUNING_RX_ENABLE_DELAY,                       ///< PLATFORM_TUNING_RX_ENABLE_DELAY = 0x1057
   PLATFORM_TUNING_TX_DQ_DELAY,                           ///< PLATFORM_TUNING_TX_DQ_DELAY = 0x1058
   PLATFORM_TUNING_TX_DQS_DELAY,                          ///< PLATFORM_TUNING_TX_DQS_DELAY = 0x1059
   PLATFORM_TUNING_RX_PB_DELAY,                           ///< PLATFORM_TUNING_RX_PB_DELAY = 0x105A
   PLATFORM_TUNING_RX_CLK_DELAY,                          ///< PLATFORM_TUNING_RX_CLK_DELAY = 0x105B
   PLATFORM_TUNING_VREF_DAC0,                             ///< PLATFORM_TUNING_VREF_DAC0 = 0x105C
   PLATFORM_TUNING_VREF_DAC1,                             ///< PLATFORM_TUNING_VREF_DAC1 = 0x105D
   PLATFORM_TUNING_VREF_IN_GLOBAL,                        ///< PLATFORM_TUNING_VREF_IN_GLOBAL = 0x105E
   PLATFORM_TUNING_DQ_DQS_RCV_CTRL,                       ///< PLATFORM_TUNING_DQ_DQS_RCV_CTRL = 0x105F
   PLATFORM_TUNING_PHY_REG_END,                           ///< PLATFORM_TUNING_PHY_REG_END = 0x1060
   /// PHY Regs end
   // 1D training input
   PLATFORM_TUNING_1D_TRAIN_MR0,                          ///< PLATFORM_TUNING_1D_TRAIN_MR0 = 0x1061
   PLATFORM_TUNING_1D_TRAIN_MR1,                          ///< PLATFORM_TUNING_1D_TRAIN_MR1 = 0x1062
   PLATFORM_TUNING_1D_TRAIN_MR2,                          ///< PLATFORM_TUNING_1D_TRAIN_MR2 = 0x1063
   PLATFORM_TUNING_1D_TRAIN_MR3,                          ///< PLATFORM_TUNING_1D_TRAIN_MR3 = 0x1064
   PLATFORM_TUNING_1D_TRAIN_MR4,                          ///< PLATFORM_TUNING_1D_TRAIN_MR4 = 0x1065
   PLATFORM_TUNING_1D_TRAIN_MR5,                          ///< PLATFORM_TUNING_1D_TRAIN_MR5 = 0x1066
   PLATFORM_TUNING_1D_TRAIN_MR6,                          ///< PLATFORM_TUNING_1D_TRAIN_MR6 = 0x1067
   PLATFORM_TUNING_1D_TRAIN_PHY_VREF,                     ///< PLATFORM_TUNING_1D_TRAIN_PHY_VREF = 0x1067
   PLATFORM_TUNING_1D_TRAIN_SEQUENCE_CTRL,                ///< PLATFORM_TUNING_1D_TRAIN_SEQUENCE_CTRL = 0x1068
   PLATFORM_TUNING_1D_TRAIN_DFI_MRL_MARGIN,               ///< PLATFORM_TUNING_1D_TRAIN_DFI_MRL_MARGIN = 0x1069
   PLATFORM_TUNING_1D_CUSTOM_MSG,                         ///< PLATFORM_TUNING_1D_CUSTOM_MSG = 0x106A
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL0,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL0 = 0x106B
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL1,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL1 = 0x106C
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL2,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL2 = 0x106D
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL3,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL3 = 0x106E
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL4,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL4 = 0x106F
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL5,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL5 = 0x1070
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL6,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL6 = 0x1071
   PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL7,               ///< PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL7 = 0x1072
   PLATFORM_TUNING_1D_TRAIN_ALT_WCAS_L,                   ///< PLATFORM_TUNING_1D_TRAIN_ALT_WCAS_L = 0x1073
   // 2D training input
   PLATFORM_TUNING_2D_TRAIN_MR0,                          ///< PLATFORM_TUNING_2D_TRAIN_MR0 = 0x1074
   PLATFORM_TUNING_2D_TRAIN_MR1,                          ///< PLATFORM_TUNING_2D_TRAIN_MR1 = 0x1075
   PLATFORM_TUNING_2D_TRAIN_MR2,                          ///< PLATFORM_TUNING_2D_TRAIN_MR2 = 0x1076
   PLATFORM_TUNING_2D_TRAIN_MR3,                          ///< PLATFORM_TUNING_2D_TRAIN_MR3 = 0x1077
   PLATFORM_TUNING_2D_TRAIN_MR4,                          ///< PLATFORM_TUNING_2D_TRAIN_MR4 = 0x1078
   PLATFORM_TUNING_2D_TRAIN_MR5,                          ///< PLATFORM_TUNING_2D_TRAIN_MR5 = 0x1079
   PLATFORM_TUNING_2D_TRAIN_MR6,                          ///< PLATFORM_TUNING_2D_TRAIN_MR6 = 0x107A
   PLATFORM_TUNING_2D_TRAIN_PHY_VREF,                     ///< PLATFORM_TUNING_2D_TRAIN_PHY_VREF = 0x107B
   PLATFORM_TUNING_2D_TRAIN_SEQUENCE_CTRL,                ///< PLATFORM_TUNING_2D_TRAIN_SEQUENCE_CTRL = 0x107C
   PLATFORM_TUNING_2D_TRAIN_DFI_MRL_MARGIN,               ///< PLATFORM_TUNING_2D_TRAIN_DFI_MRL_MARGIN = 0x107D
   PLATFORM_TUNING_2D_TRAIN_RX2D_TRAIN_OPT,               ///< PLATFORM_TUNING_2D_TRAIN_RX2D_TRAIN_OPT = 0x107E
   PLATFORM_TUNING_2D_TRAIN_TX2D_TRAIN_OPT,               ///< PLATFORM_TUNING_2D_TRAIN_TX2D_TRAIN_OPT = 0x107F
   PLATFORM_TUNING_2D_CUSTOM_MSG,                         ///< PLATFORM_TUNING_2D_CUSTOM_MSG = 0x1080
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL0,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL0 = 0x1081
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL1,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL1 = 0x1082
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL2,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL2 = 0x1083
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL3,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL3 = 0x1084
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL4,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL4 = 0x1085
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL5,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL5 = 0x1086
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL6,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL6 = 0x1087
   PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL7,               ///< PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL7 = 0x1088
   PLATFORM_TUNING_2D_TRAIN_ALT_WCAS_L,                   ///< PLATFORM_TUNING_2D_TRAIN_ALT_WCAS_L = 0x1089
   //Validity
   PLATFORM_TUNING_VALIDITY_DRAM_MFG_ID,                  ///< PLATFORM_TUNING_VALIDITY_DRAM_MFG_ID = 0x108A
   PLATFORM_TUNING_VALIDITY_MODULE_MFG_ID,                ///< PLATFORM_TUNING_VALIDITY_MODULE_MFG_I = 0x108B
   PLATFORM_TUNING_VALIDITY_DRAM_STEPPING,                ///< PLATFORM_TUNING_VALIDITY_DRAM_STEPPING = 0x108C
   PLATFORM_TUNING_VALIDITY_TERMINATOR,                   ///< PLATFORM_TUNING_VALIDITY_TERMINATOR = 0x108D
   // END! END! END!
   PLATFORM_TUNING_ENTRY_END,                             ///< PLATFORM_TUNING_ENTRY_END  = 0x108E
   PLATFORM_TUNING_TERMINATOR = 0xFEEF                    ///< PLATFORM_TUNING_TERMINATOR = 0xFEEF
} PLATFORM_TUNING_ENTRY;

/**
 * @brief PTO_ENTRY Type Definition
 */
typedef UINT8 PTO_ENTRY;

/**
 * @brief OP_MINUS Definition
 */
#define OP_MINUS 0x11
/**
 * @brief OP_PLUS Definition
 */
#define OP_PLUS 0x22
/**
 * @brief OP_OVERRIDE Definition
 */
#define OP_OVERRIDE 0x33

/**
 * @brief DWord_TO_DByte conversion
 * @param[in] Dword UINT16 16-bit Data Value
 */
#define DW_TO_DB(dw) \
 ((UINT8)(((UINT16) (dw)) & 0xFF)), ((UINT8)((((UINT16) (dw)) >> 8) & 0xFF))

/**
 * @brief DD to Dbyte conversion
 * @param[in] DD UINT32 32-bit Data Value
 */
#define DD_TO_DB(dd) \
 ((UINT8)(((UINT32) (dd)) & 0xFF)), ((UINT8)((((UINT32) (dd)) >> 8) & 0xFF)), ((UINT8)((((UINT32) (dd)) >> 16) & 0xFF)), ((UINT8)((((UINT32) (dd)) >> 24) & 0xFF))

/**
 * @brief Nibble to Dbyte conversion
 * @param[in] Nibble0 UINT8 Nibble Value
 * @param[in] Nibble1 UINT8 Nibble Value
 */
#define NIBBLE_TO_DB(nibble0, nibble1) \
 ((UINT8)(((UINT8) (nibble0) & 0x0F) | (((UINT8) (nibble1) << 4) & 0xF0)))

/**
 * @brief Platform Tuning Terminate Dword to Dbyte Conversion
 * @param[in] PLATFORM_TUNING_TERMINATOR UINT16 Enumerated constant = 0xFEEF
 */
#define MAKE_PTO_TERMINATE() DW_TO_DB(PLATFORM_TUNING_TERMINATOR)

/**
 * @brief Generate PTO_ChipSel_INTLV_Entry
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_CHIPSEL_INTLV_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
  DW_TO_DB(PLATFORM_TUNING_CHIPSEL_INTLV), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_ECC_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ECC_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_ECC), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_PARITY_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_PARITY_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_PARITY), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_MEM_BUS_LIMIT_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_MEM_BUS_LIMIT_ENTRY(SocketBitMap, ChannelBitMap, Speed) \
   DW_TO_DB(PLATFORM_TUNING_MEM_BUS_LIMIT), 7, ANY_SOCKET, ANY_CHANNEL, DW_TO_DB((Speed))

/**
 * @brief Generate PTO_MBIST_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_MBIST_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_MBIST_TEST_MODE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_MBIST_TEST_MODE_ENTRY(SocketBitMap, ChannelBitMap, Mode) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_TEST_MODE), 6, ANY_SOCKET, ANY_CHANNEL, (Mode)

/**
 * @brief Generate PTO_MBIST_AGGRESSOR_ON_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_MBIST_AGGRESSOR_ON_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_AGGRESSOR_ON), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_MBIST_PER_BIT_SECONDARY_DIE_REPORT_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_MBIST_PER_BIT_SECONDARY_DIE_REPORT_ENTRY(SocketBitMap, ChannelBitMap, Value8) \
   DW_TO_DB(PLATFORM_TUNING_MBIST_PER_BIT_SECONDARY_DIE_REPORT), 6, ANY_SOCKET, (ChannelBitMap), (Value8)

/**
 * @brief Generate PTO_POST_PACKAGE_REPAIR_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_POST_PACKAGE_REPAIR_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_POST_PACKAGE_REPAIR_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_POST_PACKAGE_REPAIR_ALL_BANKS_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_POST_PACKAGE_REPAIR_ALL_BANKS_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_POST_PACKAGE_REPAIR_ALL_BANKS), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_BANK_GROUP_SWAP_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_BANK_GROUP_SWAP_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_BANK_GROUP_SWAP), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_ODTS_CMD_THROTTLE_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ODTS_CMD_THROTTLE_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_ODTS_CMD_THROTTLE_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_AUTO_REFFINE_GRAN_MODE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_AUTO_REFFINE_GRAN_MODE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_AUTO_REFFINE_GRAN_MODE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

/**
 * @brief Generate PTO_ADDR_CMD_PARITY_RETRY_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ADDR_CMD_PARITY_RETRY_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_ADDR_CMD_PARITY_RETRY), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_RCD_PARITY_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_RCD_PARITY_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_RCD_PARITY_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_WR_CRC_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_WR_CRC_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_WR_CRC_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_WR_CRC_RETRY_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_WR_CRC_RETRY_ENTRY(SocketBitMap, ChannelBitMap, Enable) \
   DW_TO_DB(PLATFORM_TUNING_WR_CRC_RETRY), 6, ANY_SOCKET, ANY_CHANNEL, (Enable)

/**
 * @brief Generate PTO_ECC_SYMBOL_SIZE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ECC_SYMBOL_SIZE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_ECC_SYMBOL_SIZE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

/**
 * @brief Generate PTO_ENABLE_POWER_DOWN_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ENABLE_POWER_DOWN_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_ENABLE_POWER_DOWN), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

/**
 * @brief Generate PTO_ENABLE_TUNING_MEMORY_ALL_CLOCKS_ON_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ENABLE_TUNING_MEMORY_ALL_CLOCKS_ON_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_MEMORY_ALL_CLOCKS_ON), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

/**
 * @brief Generate PTO_ENABLE_POWER_DOWN_MODE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_ENABLE_POWER_DOWN_MODE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_POWER_DOWN_MODE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

/**
 * @brief Generate PTO_TEMPERATURE_CONTROLLED_REFRESH_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_TEMPERATURE_CONTROLLED_REFRESH_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_TEMPERATURE_CONTROLLED_REFRESH_ENABLE), 6, ANY_SOCKET, ANY_CHANNEL, (Value)

/**
 * @brief Generate PTO_CMD_BUS_TMG_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] DimmPerCh UINT8 Number of Dimms per Channel
 * @param[in] SpeedBitMap UINT32 Speed Bit Mapping
 * @param[in] Width UINT8 Width
 * @param[in] VddIo UINT8 VddIo
 * @param[in] Dimm0Rank UINT8 Dimm0 Rank
 * @param[in] Dimm1Rank UINT8 Dimm1 Rank
 * @param[in] SlowMode  UINT8 SlowMode
 * @param[in] AddrCmdCtrl UINT32 Address Cmd Ctrl
 * @param[in] CkeStrength UINT8 CkeStrength
 * @param[in] CsOdtStrength UINT8 CsOdtStrength
 * @param[in] AddrCmdStrength UINT8 AddrCmdStrength
 * @param[in] ClkStrength UINT8 ClkStrength
 */
#define MAKE_PTO_CMD_BUS_TMG_ENTRY(SocketBitMap, ChannelBitMap, DimmPerCh, SpeedBitMap, Width, VddIo, Dimm0Rank, Dimm1Rank, SlowMode, AddrCmdCtrl, CkeStrength, CsOdtStrength, AddrCmdStrength, ClkStrength) \
   DW_TO_DB(PLATFORM_TUNING_CMD_BUS_TMG), 22, (SocketBitMap), (ChannelBitMap), (DimmPerCh), DD_TO_DB((SpeedBitMap)), (Width), (VddIo),\
   NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (SlowMode), DD_TO_DB((AddrCmdCtrl)), (CkeStrength), (CsOdtStrength), (AddrCmdStrength), (ClkStrength)

/**
 * @brief Generate PTO_DATA_BUS_TMG_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] DimmPerCh UINT8 Number of Dimms per Channel
 * @param[in] SpeedBitMap UINT32 Speed Bit Mapping
 * @param[in] Width UINT8 Width
 * @param[in] VddIo UINT8 VddIo
 * @param[in] Dimm0Rank UINT8 Dimm0 Rank
 * @param[in] Dimm1Rank UINT8 Dimm1 Rank
 * @param[in] RttNom UINT8 RttNom
 * @param[in] RttWr UINT8 RttWr
 * @param[in] RttPark UINT8 RttPark
 * @param[in] DqDrvStrength UINT8 DqDrvStrength
 * @param[in] DqsDrvStrength UINT8 DqsDrvStrength
 * @param[in] OdtDrvStrength UINT8 OdtDrvStrength
 */
#define MAKE_PTO_DATA_BUS_TMG_ENTRY(SocketBitMap, ChannelBitMap, DimmPerCh, SpeedBitMap, Width, VddIo, Dimm0Rank, Dimm1Rank, RttNom, RttWr, RttPark, DqDrvStrength, DqsDrvStrength, OdtDrvStrength) \
  DW_TO_DB(PLATFORM_TUNING_DATA_BUS_TMG), 19, (SocketBitMap), (ChannelBitMap), (DimmPerCh), DD_TO_DB((SpeedBitMap)), (Width), (VddIo),\
  NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (RttNom), (RttWr), (RttPark), (DqDrvStrength), (DqsDrvStrength), (OdtDrvStrength)

/**
 * @brief Generate PTO_SPD_VALUE_OVERRIDE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] DimmBitMap UINT8 DimmBitMap
 * @param[in] Offset UINT8 Offset
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_SPD_VALUE_OVERRIDE_ENTRY(SocketBitMap, ChannelBitMap, DimmBitMap, Offset, Value) \
   DW_TO_DB(PLATFORM_TUNING_SPD_VALUE_OVERRIDE), 9, (SocketBitMap), (ChannelBitMap), (DimmBitMap), DW_TO_DB(Offset), (Value)

/**
 * @brief Generate PTO_SPD_CRC_IGNORE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Dimm UINT8 Dimm#
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_SPD_CRC_IGNORE_ENTRY(SocketBitMap, ChannelBitMap, Dimm, Enable) \
   DW_TO_DB(PLATFORM_TUNING_SPD_CRC_IGNORE), 7, ANY_SOCKET, ANY_CHANNEL, ALL_DIMMS, (Enable)

/**
 * @brief Generate PTO_GEAR_DOWN_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_GEAR_DOWN_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Enable) \
   DW_TO_DB(PLATFORM_TUNING_GEAR_DOWN_EN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Enable)

/**
 * @brief Generate PTO_CMD_2T_ENABLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Enable UINT8 Enable bit
 */
#define MAKE_PTO_CMD_2T_ENABLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Enable) \
   DW_TO_DB(PLATFORM_TUNING_CMD_2T_EN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Enable)

/**
 * @brief Generate PTO_WR_PREAMBLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_WR_PREAMBLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_WR_PREAMBLE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate PTO_RD_PREAMBLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_RD_PREAMBLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_RD_PREAMBLE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate PTO_ODT_PAT_CTRL_CS0_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value32 UINT32 32-bit Value
 */
#define MAKE_PTO_ODT_PAT_CTRL_CS0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS0), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))

/**
 * @brief Generate PTO_ODT_PAT_CTRL_CS1_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value32 UINT32 32-bit Value
 */
#define MAKE_PTO_ODT_PAT_CTRL_CS1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS1), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))

/**
 * @brief Generate PTO_ODT_PAT_CTRL_CS2_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT32 32-bit Value
 */
#define MAKE_PTO_ODT_PAT_CTRL_CS2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS2), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))

/**
 * @brief Generate PTO_ODT_PAT_CTRL_CS3_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT32 32-bit Value
 */
#define MAKE_PTO_ODT_PAT_CTRL_CS3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value32) \
   DW_TO_DB(PLATFORM_TUNING_ODT_PAT_CTRL_CS3), 11, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DD_TO_DB((Value32))

/**
 * @brief Generate PTO_TX_EQ_IMPEDANCE_DQ_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_TX_EQ_IMPEDANCE_DQ_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_TX_EQ_IMPEDANCE_DQ), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate PTO_TX_IMPEDANCE_DQ_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_TX_IMPEDANCE_DQ_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_TX_IMPEDANCE_DQ), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate PTO_TX_EQ_HI_IMPEDANCE_DQ_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_TX_EQ_HI_IMPEDANCE_DQ_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_TX_EQ_HI_IMPEDANCE_DQ), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate PTO_TX_ODT_DRV_STREN_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_TX_ODT_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_TX_ODT_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate PTO_TRCDWR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRCDWR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRCDWR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRCDRD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRCDRD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRCDRD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRAS_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRAS_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRAS), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TCL_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TCL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TCL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRP_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRTP_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRTP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRTP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRRDDLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRRDDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRRDDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRRDL_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRRDL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRRDL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRRDS_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRRDS_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRRDS), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TFAWDLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TFAWDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TFAWDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TFAWSLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TFAWSLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TFAWSLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_ODT_PAT_CTRL_CS0_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TFAW_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TFAW), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWTRL_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWTRL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWTRS_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWTRS_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWTRS), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TCWL_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TCWL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TCWL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TCRPAGE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRCPAGE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRCPAGE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRFC_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16InMemClk UINT16 Value16InMemClk
 */
#define MAKE_PTO_TRFC_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16InMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRFC), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16InMemClk))

/**
 * @brief Generate PTO_TRFC2_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16InMemClk UINT16 Value16InMemClk
 */
#define MAKE_PTO_TRFC2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16InMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRFC2), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16InMemClk))

/**
 * @brief Generate PTO_TRFC4_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16InMemClk UINT16 Value16InMemClk
 */
#define MAKE_PTO_TRFC4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16InMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRFC4), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16InMemClk))

/**
 * @brief Generate PTO_TSTAG_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TSTAG_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAG), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TSTAGLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TSTAGLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAGLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TSTAG2LR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TSTAG2LR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAG2LR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TSTAG4LR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TSTAG4LR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TSTAG4LR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDRDBAN_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDRDBAN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDBAN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDRDSCL_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDRDSCL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSCL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDRDSCDLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDRDSCDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSCDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDRDSC_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDRDSC_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSC), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDRDSD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDRDSD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDSD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDRDDD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDRDDD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDRDDD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRWRBAN_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRWRBAN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRBAN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRWRSCL_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRWRSCL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSCL), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRWRSCDLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRWRSCDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSCDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRWRSC_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRWRSC_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSC), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRWRSD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRWRSD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRSD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRWRDD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRWRDD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRWRDD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRRDSCDLR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRRDSCDLR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRRDSCDLR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TRDWR_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TRDWR_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TRDWR), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_TWRRD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRRD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRRD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Generate PTO_DDR4_UECC_RETRY_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_DDR4_UECC_RETRY_ENTRY(SocketBitMap, ChannelBitMap, Value) \
   DW_TO_DB(PLATFORM_TUNING_DDR4_UECC_RETRY), 8, ANY_SOCKET, ANY_CHANNEL, 0xFF/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/, (Value)

/**
 * @brief Generate Address Command Setup
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */

#define MAKE_PTO_ADDR_CMD_SETUP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_ADDR_CMD_SETUP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate CS Odt Setup
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_CS_ODT_SETUP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CS_ODT_SETUP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate Cke Setup
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_CKE_SETUP_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CKE_SETUP), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate Clk drive strength
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_CLK_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CLK_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate Address command drive strength
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_ADDR_CMD_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_ADDR_CMD_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate Cs ODT drive strength
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_CS_ODT_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CS_ODT_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate  Cke drive strength
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_CKE_DRV_STREN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_CKE_DRV_STREN), 8, (SocketBitMap), (ChannelBitMap), 0xFF, NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate Rx enable delay
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Operation UINT8 Operation
 * @param[in] Dimm UINT8 Dimm
 * @param[in] Byte UINT8 Byte
 * @param[in] Nibble UINT8 Nibble
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_RX_ENABLE_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Nibble, Value16) \
   DW_TO_DB(PLATFORM_TUNING_RX_ENABLE_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), (Nibble), 0xFF/*Dq*/, DW_TO_DB((Value16))

/**
 * @brief Generate Tx Dq delay
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Operation UINT8 Operation
 * @param[in] Dimm UINT8 Dimm
 * @param[in] Byte UINT8 Byte
 * @param[in] Dq UINT8 Dq
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_TX_DQ_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_TX_DQ_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))

/**
 * @brief Generate  Tx Dqs delay
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Operation UINT8 Operation
 * @param[in] Dimm UINT8 Dimm
 * @param[in] Byte UINT8 Byte
 * @param[in] Nibble UINT8 Nibble
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_TX_DQS_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Nibble, Value16) \
   DW_TO_DB(PLATFORM_TUNING_TX_DQS_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), (Nibble), 0xFF/*Dq*/, DW_TO_DB((Value16))

/**
 * @brief Generate Rx PB delay
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Operation UINT8 Operation
 * @param[in] Dimm UINT8 Dimm
 * @param[in] Byte UINT8 Byte
 * @param[in] Dq UINT8 Dq
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_RX_PB_DELAY_ENTRY(SocketBitMap, ChannelBitMap, Operation, Dimm, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_RX_PB_DELAY), 14, (SocketBitMap), (ChannelBitMap), 0/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))

/**
 * @brief Generate Rx clk delay
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Operation UINT8 Operation
 * @param[in] Dimm UINT8 Dimm
 * @param[in] Byte UINT8 Byte
 * @param[in] Nibble UINT8 Nibble
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_RX_CLK_DELAY_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Dimm, Byte, Nibble, Value16) \
   DW_TO_DB(PLATFORM_TUNING_RX_CLK_DELAY), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), (Dimm), (Byte), (Nibble), 0xFF/*Dq*/, DW_TO_DB((Value16))

/**
 * @brief Generate Vref DAC0
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Operation UINT8 Operation
 * @param[in] Byte UINT8 Byte
 * @param[in] Dq UINT8 Dq
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_VREF_DAC_0_ENTRY(SocketBitMap, ChannelBitMap, Operation, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_VREF_DAC0), 14, (SocketBitMap), (ChannelBitMap), 0/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), 0xFF/*Dimm*/, (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))

/**
 * @brief Generate Vref DAC1
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] Operation UINT8 Operation
 * @param[in] Byte UINT8 Byte
 * @param[in] Dq UINT8 Dq
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_VREF_DAC_1_ENTRY(SocketBitMap, ChannelBitMap, Operation, Byte, Dq, Value16) \
   DW_TO_DB(PLATFORM_TUNING_VREF_DAC1), 14, (SocketBitMap), (ChannelBitMap), 0/*MemPstate*/, 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), 0xFF/*Dimm*/, (Byte), 0xFF/*Nibble*/, (Dq), DW_TO_DB((Value16))

/**
 * @brief Generate Vref in Global
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Operation UINT8 Operation type
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_VREF_IN_GLOBAL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Operation, Value16) \
   DW_TO_DB(PLATFORM_TUNING_VREF_IN_GLOBAL), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   (Operation), 0xFF/*Dimm*/, 0xFF/*Byte*/, 0xFF/*Nibble*/, 0xFF/*Dq*/, DW_TO_DB((Value16))

/**
 * @brief Generate DqDqsRcvCtrl
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Byte UINT8 Byte
 * @param[in] Nibble UINT8 Nibble
 * @param[in] Value16 UINT16 Value16
 */
#define MAKE_PTO_DQ_DQS_RCV_CTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Byte, Nibble, Value16) \
   DW_TO_DB(PLATFORM_TUNING_DQ_DQS_RCV_CTRL), 14, (SocketBitMap), (ChannelBitMap), (MemPstate), 0xFF/*NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)*/,\
   OP_OVERRIDE, 0xFF/*Dimm*/, (Byte), (Nibble), 0xFF/*Dq*/, DW_TO_DB((Value16))


/**
 * @brief Generate   1D Train MR0
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR0), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate   1D Train MR1
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR1), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate   1D Train MR2
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR2), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate   1D Train MR3
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR3), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate   1D Train MR4
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR4), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate   1D Train MR5
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR5), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate   1D Train MR6
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_MR6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_MR6), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate 1D Train Phy Vref
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_PHY_VREF_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_PHY_VREF), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train Sequence Control
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_1D_TRAIN_SEQUENCE_CTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_SEQUENCE_CTRL), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate 1D Train DFI MRL Margin
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_DFI_MRL_MARGIN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_DFI_MRL_MARGIN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Custom Message
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Offset UINT8 Offset
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_CUSTOM_MSG_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Offset, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_CUSTOM_MSG), 10, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Offset)),\
   (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl0
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL0), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl1
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL1), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl2
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL2), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl3
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL3), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl4
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL4), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl5
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL5), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl6
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL6), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train AcsmOdtCtrl7
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ACSM_ODT_CTRL7_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL7), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 1D Train ALT_WCAS_L
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_1D_TRAIN_ALT_WCAS_L_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_1D_TRAIN_ALT_WCAS_L), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)


/**
 * @brief Generate  2D Train MR0
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR0), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate  2D Train MR1
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR1), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate  2D Train MR2
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR2), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate  2D Train MR3
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR3), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate  2D Train MR4
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR4), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate  2D Train MR5
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR5), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate  2D Train MR6
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_MR6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_MR6), 9, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate 2D Train Phy Vref
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_PHY_VREF_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_PHY_VREF), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate  2D Train Sequence Control
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value16 UINT16 16-bit Value
 */
#define MAKE_PTO_2D_TRAIN_SEQUENCE_CTRL_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value16) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_SEQUENCE_CTRL), 9,(SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Value16))

/**
 * @brief Generate 2D Train DFI MRL Margin
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_DFI_MRL_MARGIN_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_DFI_MRL_MARGIN), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train RX2D Train Opt
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_RX2D_TRAIN_OPT_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_RX2D_TRAIN_OPT), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train TX2D Train Opt
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_TX2D_TRAIN_OPT_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_TX2D_TRAIN_OPT), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Custom Message
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Offset UINT8 Offset
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_CUSTOM_MSG_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Offset, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_CUSTOM_MSG), 10, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), DW_TO_DB((Offset)),\
   (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl0
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL0_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL0), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl1
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL1_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL1), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl2
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL2_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL2), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl3
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL3_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL3), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl4
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL4_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL4), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl5
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL5_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL5), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl6
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL6_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL6), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train AcsmOdtCtrl7
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ACSM_ODT_CTRL7_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL7), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Generate 2D Train ALT_WCAS_L
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_2D_TRAIN_ALT_WCAS_L_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_2D_TRAIN_ALT_WCAS_L), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief  Generate DramManufacturersIDCode
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] DramMfgId UINT8 DramMfgId
 */
#define MAKE_PTO_VALIDITY_DRAM_MFG_ID_ENTRY(SocketBitMap, ChannelBitMap, DramMfgId) \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_DRAM_MFG_ID), 7, (SocketBitMap), (ChannelBitMap), DW_TO_DB((DramMfgId))

/**
 * @brief  Generate ModuleManufacturersIDCode
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] DramMfgId UINT8 ModuleMfgId
 */
#define MAKE_PTO_VALIDITY_MODULE_MFG_ID_ENTRY(SocketBitMap, ChannelBitMap, ModuleMfgId) \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_MODULE_MFG_ID), 7, (SocketBitMap), (ChannelBitMap), DW_TO_DB((ModuleMfgId))

/**
 * @brief  Generate DramStepping
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] DramMfgId UINT8 DramStepping
 */
#define MAKE_PTO_VALIDITY_DRAM_STEPPING_ENTRY(SocketBitMap, ChannelBitMap, DramStepping) \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_DRAM_STEPPING), 7, (SocketBitMap), (ChannelBitMap), DW_TO_DB((DramStepping))

/**
 * @brief  Generate Vality Check End
 */
#define MAKE_PTO_VALIDITY_END() \
   DW_TO_DB(PLATFORM_TUNING_VALIDITY_TERMINATOR), 3


/**
 * @brief  Chipsel Interleave Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_CHIPSEL_INTLV_ENTRY;

/**
 * @brief Ecc Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_ECC_ENTRY;

/**
 * @brief Parity Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_PARITY_ENTRY;

/**
 * @brief  Mem Bus Limit Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT16   Speed;      ///< Speed
} PTO_MEM_BUS_LIMIT_ENTRY;

/**
 * @brief  Mbist Enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_MBIST_ENABLE_ENTRY;

/**
 * @brief   Mbist Test Mode Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Mode;      ///< Mode
} PTO_MBIST_TEST_MODE_ENTRY;

/**
 * @brief  Mbist Aggressor On Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_MBIST_AGGRESSOR_ON_ENTRY;

/**
 * @brief  Mbist Per Bit Secondary Die Report Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value8;      ///< Value8
} PTO_MBIST_PER_BIT_SECONDARY_DIE_REPORT_ENTRY;

/**
 * @brief  Post Package Repair Enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_POST_PACKAGE_REPAIR_ENABLE_ENTRY;

/**
 * @brief  Post Package Repair All Banks Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_POST_PACKAGE_REPAIR_ALL_BANKS_ENTRY;

/**
 * @brief  Bank Group Swap Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_BANK_GROUP_SWAP_ENTRY;

/**
 * @brief  Odts Command Throttle Enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_ODTS_CMD_THROTTLE_ENABLE_ENTRY;

/**
 * @brief  Auto Reffine Gran Mode Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value;      ///< Value
} PTO_AUTO_REFFINE_GRAN_MODE_ENTRY;

/**
 * @brief  Address Command Parity Retry Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_ADDR_CMD_PARITY_RETRY_ENTRY;

/**
 * @brief   Rcd Parity Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_RCD_PARITY_ENABLE_ENTRY;

/**
 * @brief  WrCrc Enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_WR_CRC_ENABLE_ENTRY;

/**
 * @brief  WrCrc Retry Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Enable;      ///< Enable
} PTO_WR_CRC_RETRY_ENTRY;

/**
 * @brief  Ecc symbol size Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value;      ///< Value
} PTO_ECC_SYMBOL_SIZE_ENTRY;


/**
 * @brief  Enable power down Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value;      ///< Value
} PTO_ENABLE_POWER_DOWN_ENTRY;

/**
 * @brief  Memory all clocks on Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value;      ///< Value
} PTO_ENABLE_TUNING_MEMORY_ALL_CLOCKS_ON_ENTRY;

/**
 * @brief   Power down mode Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value;      ///< Value
} PTO_ENABLE_POWER_DOWN_MODE_ENTRY;

/**
 * @brief  Temperature controlled refresh enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Value;      ///< Value
} PTO_TEMPERATURE_CONTROLLED_REFRESH_ENABLE_ENTRY;

/**
 * @brief  Command Bus Timing Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   DimmPerCh;     ///< DimmPerCh
  UINT32 SpeedBitMap;    ///< SpeedBitMap
  UINT8   Width;              ///< Width
  UINT8   VddIo;              ///< VddIo
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   SlowMode;       ///< SlowMode
  UINT32 AddrCmdCtrl;   ///< AddrCmdCtrl
  UINT8   CkeStrength;   ///< CkeStrength
  UINT8   CsOdtStrength;   ///< CsOdtStrength
  UINT8   AddrCmdStrength;   ///< AddrCmdStrength
  UINT8   ClkStrength;   ///< ClkStrength
} PTO_CMD_BUS_TMG_ENTRY;

/**
 * @brief   Data Bus Timing Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   DimmPerCh;     ///< DimmPerCh
  UINT32 SpeedBitMap;    ///< SpeedBitMap
  UINT8   Width;              ///< Width
  UINT8   VddIo;              ///< VddIo
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   RttNom;       ///< RttNom
  UINT8   RttWr;         ///< RttWr
  UINT8   RttPark;      ///< RttPark
  UINT8   DqDrvStrength;   ///< DqDrvStrength
  UINT8   DqsDrvStrength;   ///< DqsDrvStrength
  UINT8   OdtDrvStrength;   ///< OdtDrvStrength
} PTO_DATA_BUS_TMG_ENTRY;


/**
 * @brief  SPD Value Override Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Dimm;              ///< Dimm
  UINT16 Offset;              ///< Offset
  UINT8   Value;              ///< Value
} PTO_SPD_VALUE_OVERRIDE_ENTRY;

/**
 * @brief  SPD Crc Ignore Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   Dimm;              ///< Dimm
  UINT8   Enable;              ///< Enable
} PTO_SPD_CRC_IGNORE_ENTRY;


/**
 * @brief  Gear Down Enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Enable;              ///< Enable
} PTO_GEAR_DOWN_ENABLE_ENTRY;

/**
 * @brief  Command 2T Enable Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Enable;              ///< Enable
} PTO_CMD_2T_ENABLE_ENTRY;

/**
 * @brief  Wr preamble Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;              ///< Value
} PTO_WR_PREAMBLE_ENTRY;

/**
 * @brief Generate PTO_RD_PREAMBLE_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] Value UINT8 Value
 */
#define MAKE_PTO_RD_PREAMBLE_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, Value) \
   DW_TO_DB(PLATFORM_TUNING_RD_PREAMBLE), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (Value)

/**
 * @brief Rd preamble Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;              ///< Value
} PTO_RD_PREAMBLE_ENTRY;

/**
 * @brief  Odt pattern ctrl cs0 Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT32   Value32;              ///< Value32
} PTO_ODT_PAT_CTRL_CS0_ENTRY;

/**
 * @brief   Odt pattern ctrl cs1 Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT32   Value32;              ///< Value32
} PTO_ODT_PAT_CTRL_CS1_ENTRY;

/**
 * @brief  Odt pattern ctrl cs2 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT32   Value32;              ///< Value32
} PTO_ODT_PAT_CTRL_CS2_ENTRY;

/**
 * @brief  Odt pattern ctrl cs3 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT32   Value32;         ///< Value32
} PTO_ODT_PAT_CTRL_CS3_ENTRY;

/**
 * @brief  Tx eq impedance Dq Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;         ///< Value
} PTO_TX_EQ_IMPEDANCE_DQ_ENTRY;

/**
 * @brief   Tx odt drive strength Type
 *
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;         ///< Value
} PTO_TX_ODT_DRV_STREN_ENTRY;

/**
 * @brief  Trcdwr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRCDWR_ENTRY;

/**
 * @brief  Trcdrd Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRCDRD_ENTRY;

/**
 * @brief Tras Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRAS_ENTRY;

/**
 * @brief Tcl Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TCL_ENTRY;

/**
 * @brief Trp Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRP_ENTRY;

/**
 * @brief Trtp Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRTP_ENTRY;

/**
 * @brief TrrdDlr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRRDDLR_ENTRY;

/**
 * @brief  TrrdL Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRRDL_ENTRY;

/**
 * @brief  TrrdS Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRRDS_ENTRY;

/**
 * @brief  TfawDlr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TFAWDLR_ENTRY;

/**
 * @brief  TfawSlr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TFAWSLR_ENTRY;

/**
 * @brief  Tfaw Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TFAW_ENTRY;

/**
 * @brief  TwtrL Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWTRL_ENTRY;

/**
 * @brief  TwtrS Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWTRS_ENTRY;

/**
 * @brief Tcwl Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TCWL_ENTRY;

/**
 * @brief Twr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWR_ENTRY;

/**
 * @brief  Trcpage type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRCPAGE_ENTRY;

/**
 * @brief Trfc Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT16   Value16InMemClk;  ///< Value16InMemClk
} PTO_TRFC_ENTRY;

/**
 * @brief  Trfc2 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT16   Value16InMemClk;  ///< Value16InMemClk
} PTO_TRFC2_ENTRY;

/**
 * @brief  Trfc4 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT16   Value16InMemClk;  ///< Value16InMemClk
} PTO_TRFC4_ENTRY;

/**
 * @brief  Tstag Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TSTAG_ENTRY;

/**
 * @brief TstagLr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TSTAGLR_ENTRY;

/**
 * @brief  Tstag2Lr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TSTAG2LR_ENTRY;

/**
 * @brief  Tstag4Lr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TSTAG4LR_ENTRY;

/**
 * @brief  TrdrdBan Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDRDBAN_ENTRY;

/**
 * @brief  TrdrdScL Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDRDSCL_ENTRY;

/**
 * @brief  TrdrdScDlr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDRDSCDLR_ENTRY;

/**
 * @brief  TrdrdSc Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDRDSC_ENTRY;

/**
 * @brief  TrdrdSd Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDRDSD_ENTRY;

/**
 * @brief  TrdrdDd Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDRDDD_ENTRY;

/**
 * @brief  TwrwrBan Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRWRBAN_ENTRY;

/**
 * @brief TwrwrScL Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRWRSCL_ENTRY;

/**
 * @brief  TwrwrScDlr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRWRSCDLR_ENTRY;

/**
 * @brief  TwrwrSc Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRWRSC_ENTRY;

/**
 * @brief  TwrwrSd Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRWRSD_ENTRY;

/**
 * @brief  TwrwrDd Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRWRDD_ENTRY;

/**
 * @brief  TwrrdScDlr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRRDSCDLR_ENTRY;

/**
 * @brief Trdwr Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TRDWR_ENTRY;

/**
 * @brief Generate PTO_TWRRD_ENTRY
 * @param[in] SocketBitMap UINT8 Socket Mapping
 * @param[in] ChannelBitMap UINT8 Channel Mapping
 * @param[in] MemPstate UINT8 Pstate#
 * @param[in] Dimm0Rank UINT8 Dimm0Rank
 * @param[in] Dimm1Rank UINT8 Dimm1Rank
 * @param[in] ValueInMemClk UINT8 ValueInMemClk
 */
#define MAKE_PTO_TWRRD_ENTRY(SocketBitMap, ChannelBitMap, MemPstate, Dimm0Rank, Dimm1Rank, ValueInMemClk) \
   DW_TO_DB(PLATFORM_TUNING_TWRRD), 8, (SocketBitMap), (ChannelBitMap), (MemPstate), NIBBLE_TO_DB((Dimm0Rank), (Dimm1Rank)), (ValueInMemClk)

/**
 * @brief Twrrd Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   ValueInMemClk;  ///< ValueInMemClk
} PTO_TWRRD_ENTRY;

/**
 * @brief DDR4 UECC retry Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;  ///< Value
} PTO_DDR4_UECC_RETRY_ENTRY;

/**
 * @brief Address Command Setup Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;  ///< Value
} PTO_ADDR_CMD_SETUP_ENTRY;

/**
 * @brief Cs ODT Setup Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;  ///< Value
} PTO_CS_ODT_SETUP_ENTRY;

/**
 * @brief Cke Setup Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4; ///< Dimm0Rank
  UINT8   Dimm1Rank:4; ///< Dimm1Rank
  UINT8   Value;  ///< Value
} PTO_CKE_SETUP_ENTRY;

/**
 * @brief Clk drive strength Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_CLK_DRV_STREN_ENTRY;

/**
 * @brief Address command drive strength Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_ADDR_CMD_DRV_STREN_ENTRY;

/**
 * @brief Cs ODT drive strength Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_CS_ODT_DRV_STREN_ENTRY;

/**
 * @brief Cke drive strength Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_CKE_DRV_STREN_ENTRY;

/**
 * @brief Rx enable delay Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Operation;      ///< Operation
  UINT8   Dimm;           ///< Dimm
  UINT8   Byte;           ///< Byte
  UINT8   Nibble;         ///< Nibble
  UINT8   Dq;             ///< Dq
  UINT16   Value16;       ///< Value16
} PTO_RX_ENABLE_DELAY_ENTRY;

/**
 * @brief Tx Dq delay Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Operation;      ///< Operation
  UINT8   Dimm;           ///< Dimm
  UINT8   Byte;           ///< Byte
  UINT8   Nibble;         ///< Nibble
  UINT8   Dq;             ///< Dq
  UINT16   Value16;       ///< Value16
} PTO_TX_DQ_DELAY_ENTRY;

/**
 * @brief Rx PB delay Type
 */
typedef struct {
  UINT16  PTEType;         ///< Platform Tuning Entry Type
                           ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;       ///< Number of bytes used for this macro
  UINT8   SocketBitMap;    ///< SocketBitMap
  UINT8   ChannelBitMap;   ///< ChannelBitMap
  UINT8   MemPstate;       ///< MemPstate
  UINT8   Dimm0Rank:4;     ///< Dimm0Rank
  UINT8   Dimm1Rank:4;     ///< Dimm1Rank
  UINT8   Operation;       ///< Operation
  UINT8   Dimm;            ///< Dimm
  UINT8   Byte;            ///< Byte
  UINT8   Nibble;          ///< Nibble
  UINT8   Dq;              ///< Dq
  UINT16   Value16;        ///< Value16
} PTO_RX_PB_DELAY_ENTRY;

/**
 * @brief Rc clk delay Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Operation;      ///< Operation
  UINT8   Dimm;           ///< Dimm
  UINT8   Byte;           ///< Byte
  UINT8   Nibble;         ///< Nibble
  UINT8   Dq;             ///< Dq
  UINT16   Value16;       ///< Value16
} PTO_RX_CLK_DELAY_ENTRY;

/**
 * @brief Vref DAC0 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Operation;      ///< Operation
  UINT8   Dimm;           ///< Dimm
  UINT8   Byte;           ///< Byte
  UINT8   Nibble;         ///< Nibble
  UINT8   Dq;             ///< Dq
  UINT16   Value16;       ///< Value16
} PTO_VREF_DAC_0_ENTRY;

/**
 * @brief Vref DAC1 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Operation;      ///< Operation
  UINT8   Dimm;           ///< Dimm
  UINT8   Byte;           ///< Byte
  UINT8   Nibble;         ///< Nibble
  UINT8   Dq;             ///< Dq
  UINT16   Value16;       ///< Value16
} PTO_VREF_DAC_1_ENTRY;

/**
 * @brief Vref In Global Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Operation;      ///< Operation
  UINT8   Dimm;           ///< Dimm
  UINT8   Byte;           ///< Byte
  UINT8   Nibble;         ///< Nibble
  UINT8   Dq;             ///< Dq
  UINT16   Value16;       ///< Value16
} PTO_VREF_IN_GLOBAL_ENTRY;

/**
 * @brief 1D Train MR0 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR0_ENTRY;

/**
 * @brief  1D Train MR1 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR1_ENTRY;

/**
 * @brief  1D Train MR2 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR2_ENTRY;

// 1D Train MR3
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR3_ENTRY;

/**
 * @brief 1D Train MR4 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR4_ENTRY;

/**
 * @brief 1D Train MR5 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR5_ENTRY;

/**
 * @brief  1D Train MR6 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_MR6_ENTRY;

/**
 * @brief  1D Train Phy Vref Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_PHY_VREF_ENTRY;

/**
 * @brief  1D Train Sequence Control Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_1D_TRAIN_SEQUENCE_CTRL_ENTRY;


/**
 * @brief  1D Train DFI MRL Margin Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank: 4;    ///< Dimm0Rank
  UINT8   Dimm1Rank: 4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_DFI_MRL_MARGIN_ENTRY;

/**
 * @brief 1D Custom Message Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank: 4;    ///< Dimm0Rank
  UINT8   Dimm1Rank: 4;    ///< Dimm1Rank
  UINT16 Offset;          ///< Offset
  UINT8   Value;          ///< Value
} PTO_1D_CUSTOM_MSG_ENTRY;

/**
 * @brief  1D Train AcsmOdtCtrl0 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL0_ENTRY;

/**
 * @brief 1D Train AcsmOdtCtrl1 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL1_ENTRY;

/**
 * @brief  // 1D Train AcsmOdtCtrl2 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL2_ENTRY;

/**
 * @brief 1D Train AcsmOdtCtrl3 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL3_ENTRY;

/**
 * @brief 1D Train AcsmOdtCtrl4 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL4_ENTRY;

/**
 * @brief 1D Train AcsmOdtCtrl5 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL5_ENTRY;

/**
 * @brief 1D Train AcsmOdtCtrl6 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL6_ENTRY;

/**
 * @brief 1D Train AcsmOdtCtrl7 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ACSM_ODT_CTRL7_ENTRY;

/**
 * @brief 1D Train ALT_WCAS_L Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_1D_TRAIN_ALT_WCAS_L_ENTRY;

/**
 * @brief 2D Train MR0 Type
 */ 
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR0_ENTRY;

/**
 * @brief 2D Train MR1 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR1_ENTRY;

/**
 * @brief 2D Train MR2 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR2_ENTRY;

/**
 * @brief 2D Train MR3 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR3_ENTRY;

/**
 * @brief 2D Train MR4 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR4_ENTRY;

/**
 * @brief 2D Train MR5 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR5_ENTRY;

/**
 * @brief 2D Train MR6 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_MR6_ENTRY;

/**
 * @brief 2D Train Phy Vref
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_PHY_VREF_ENTRY;

/**
 * @brief 2D Train Sequence Control
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16  Value16;        ///< Value16
} PTO_2D_TRAIN_SEQUENCE_CTRL_ENTRY;

/**
 * @brief 2D Train DFI MRL Margin Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_DFI_MRL_MARGIN_ENTRY;

/**
 * @brief 2D Train RX2D Train Opt Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_RX2D_TRAIN_OPT_ENTRY;

/**
 * @brief 2D Train TX2D Train Opt Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_TX2D_TRAIN_OPT_ENTRY;

/**
 * @brief 2D Custom Message Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT16 Offset;          ///< Offset
  UINT8   Value;          ///< Value
} PTO_2D_CUSTOM_MSG_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl0 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL0_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl1 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL1_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl2 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL2_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl3 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL3_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl4 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL4_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl5 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL5_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl6 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL6_ENTRY;

/**
 * @brief 2D Train AcsmOdtCtrl7 Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ACSM_ODT_CTRL7_ENTRY;

/**
 * @brief 2D Train ALT_WCAS_L Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT8   MemPstate;      ///< MemPstate
  UINT8   Dimm0Rank:4;    ///< Dimm0Rank
  UINT8   Dimm1Rank:4;    ///< Dimm1Rank
  UINT8   Value;          ///< Value
} PTO_2D_TRAIN_ALT_WCAS_L_ENTRY;

/**
 * @brief Validuty Check End Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
} PTO_VALIDITY_END;

/**
 * @brief Dram Manufacturer ID Entry Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT16  DramMfgId;      ///< DramMfgId
} PTO_VALIDITY_DRAM_MFG_ID_ENTRY;

/**
 * @brief DramStepping Entry Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type
                          ///< @RANGE: PLATFORM_TUNING_ENTRY
  UINT8   NumOfByte;      ///< Number of bytes used for this macro
  UINT8   SocketBitMap;   ///< SocketBitMap
  UINT8   ChannelBitMap;  ///< ChannelBitMap
  UINT16  DramStepping;   ///< DramStepping
} PTO_VALIDITY_DRAM_STEPPING_ENTRY;

/**
 * @brief Termination Entry Type
 */
typedef struct {
  UINT16  PTEType;        ///< Platform Tuning Entry Type. RANGE: PLATFORM_TUNING_ENTRY
} PTO_TERMINATE_ENTRY;

/**
 * @brief Memory Platform Tuning data Structure
 */
typedef union {
  PTO_CHIPSEL_INTLV_ENTRY PtoChipselIntlv; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CHIPSEL_INTLV
  PTO_ECC_ENTRY PtoEcc; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ECC
  PTO_MEM_BUS_LIMIT_ENTRY PtoMemBusLimit; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_MEM_BUS_LIMIT
  PTO_MBIST_ENABLE_ENTRY PtoMbistEnable; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_MBIST_ENABLE
  PTO_MBIST_TEST_MODE_ENTRY PtoMbistTestMode; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_MBIST_TEST_MODE
  PTO_MBIST_AGGRESSOR_ON_ENTRY PtoMbistAggressorOn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_MBIST_AGGRESSOR_ON
  PTO_MBIST_PER_BIT_SECONDARY_DIE_REPORT_ENTRY PtoMbistPerBitSecondaryDieReport; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_MBIST_PER_BIT_SECONDARY_DIE_REPORT
  PTO_POST_PACKAGE_REPAIR_ENABLE_ENTRY PtoPostPackageRepairEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_POST_PACKAGE_REPAIR_ENABLE
  PTO_POST_PACKAGE_REPAIR_ALL_BANKS_ENTRY PtoPostPackageRepairAllBanks; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_POST_PACKAGE_REPAIR_ALL_BANKS
  PTO_BANK_GROUP_SWAP_ENTRY PtoBankGroupSwap; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_BANK_GROUP_SWAP
  PTO_ODTS_CMD_THROTTLE_ENABLE_ENTRY PtoOdtsCmdThrottleEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ODTS_CMD_THROTTLE_ENABLE
  PTO_AUTO_REFFINE_GRAN_MODE_ENTRY PtoAutoReffineGranMode; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_AUTO_REFFINE_GRAN_MODE
  PTO_ADDR_CMD_PARITY_RETRY_ENTRY PtoAddrCmdParityRetry; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ADDR_CMD_PARITY_RETRY
  PTO_RCD_PARITY_ENABLE_ENTRY PtoRcdParityEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_RCD_PARITY_ENABLE
  PTO_WR_CRC_ENABLE_ENTRY PtoWrCrcEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_WR_CRC_ENABLE
  PTO_WR_CRC_RETRY_ENTRY PtoWrCrcRetry; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_WR_CRC_RETRY
  PTO_ECC_SYMBOL_SIZE_ENTRY PtoEccSymbolSize; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ECC_SYMBOL_SIZE
  PTO_ENABLE_POWER_DOWN_ENTRY PtoEnPowerDown; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ENABLE_POWER_DOWN
  PTO_ENABLE_TUNING_MEMORY_ALL_CLOCKS_ON_ENTRY PtoEnMemAllClocks; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_MEMORY_ALL_CLOCKS_ON
  PTO_ENABLE_POWER_DOWN_MODE_ENTRY PtoEnPowerDownMode; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_POWER_DOWN_MODE
  PTO_TEMPERATURE_CONTROLLED_REFRESH_ENABLE_ENTRY PtoTempCntrlRefreshEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TEMPERATURE_CONTROLLED_REFRESH_ENABLE
  PTO_CMD_BUS_TMG_ENTRY PtoCmdBusTmg; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CMD_BUS_TMG
  PTO_DATA_BUS_TMG_ENTRY PtoDataBusTmg; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_DATA_BUS_TMG
  PTO_SPD_VALUE_OVERRIDE_ENTRY PtoSpdValOverride; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_SPD_VALUE_OVERRIDE
  PTO_SPD_CRC_IGNORE_ENTRY PtoSpdCrcIgnore; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_SPD_CRC_IGNORE
  PTO_GEAR_DOWN_ENABLE_ENTRY PtoGearDownEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_GEAR_DOWN_EN
  PTO_CMD_2T_ENABLE_ENTRY PtoCmd2tEn; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CMD_2T_EN
  PTO_WR_PREAMBLE_ENTRY PtoWrPreamble; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_WR_PREAMBLE
  PTO_RD_PREAMBLE_ENTRY PtoRdPreamble; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_RD_PREAMBLE
  PTO_ODT_PAT_CTRL_CS0_ENTRY PtoOdtPatCtrlCs0; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ODT_PAT_CTRL_CS0
  PTO_ODT_PAT_CTRL_CS1_ENTRY PtoOdtPatCtrlCs1; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ODT_PAT_CTRL_CS1
  PTO_ODT_PAT_CTRL_CS2_ENTRY PtoOdtPatCtrlCs2; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ODT_PAT_CTRL_CS2
  PTO_ODT_PAT_CTRL_CS3_ENTRY PtoOdtPatCtrlCs3; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ODT_PAT_CTRL_CS3
  PTO_TX_EQ_IMPEDANCE_DQ_ENTRY PtoTxEqImpedDq; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TX_EQ_IMPEDANCE_DQ
  PTO_TX_ODT_DRV_STREN_ENTRY PtoTxOdtDrvStren; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TX_ODT_DRV_STREN
  PTO_TRCDWR_ENTRY PtoTrcdwr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRCDWR
  PTO_TRCDRD_ENTRY PtoTrcdrd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRCDRD
  PTO_TRAS_ENTRY PtoTras; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRAS
  PTO_TCL_ENTRY PtoTcl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TCL
  PTO_TRP_ENTRY PtoTrp; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRP
  PTO_TRTP_ENTRY PtoTrtp; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRTP
  PTO_TRRDDLR_ENTRY PtoTrrddlr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRRDDLR
  PTO_TRRDL_ENTRY PtoTrrdl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRRDL
  PTO_TRRDS_ENTRY PtoTrrds; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRRDS
  PTO_TFAWDLR_ENTRY PtoTfawdlr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TFAWDLR
  PTO_TFAWSLR_ENTRY PtoTfawslr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TFAWSLR
  PTO_TFAW_ENTRY PtoTfaw; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TFAW
  PTO_TWTRL_ENTRY PtoTwtrl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWTRL
  PTO_TWTRS_ENTRY PtoTwtrs; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWTRS
  PTO_TCWL_ENTRY PtoTcwl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TCWL
  PTO_TWR_ENTRY PtoTwr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWR
  PTO_TRCPAGE_ENTRY PtoTrcpage; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRCPAGE
  PTO_TRFC_ENTRY PtoTrfc; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRFC
  PTO_TRFC2_ENTRY PtoTrfc2; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRFC2
  PTO_TRFC4_ENTRY PtoTrfc4; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRFC4
  PTO_TSTAG_ENTRY PtoTstag; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TSTAG
  PTO_TSTAGLR_ENTRY Ptostaglr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TSTAGLR
  PTO_TSTAG2LR_ENTRY Ptostag2lr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TSTAG2LR
  PTO_TSTAG4LR_ENTRY Ptostag4lr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TSTAG4LR
  PTO_TRDRDBAN_ENTRY PtoTrdrdban; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDRDBAN
  PTO_TRDRDSCL_ENTRY PtoTrdrdscl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDRDSCL
  PTO_TRDRDSCDLR_ENTRY PtoTrdrdscdlr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDRDSCDLR
  PTO_TRDRDSC_ENTRY PtoTrdrdsc; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDRDSC
  PTO_TRDRDSD_ENTRY PtoTrdrdsd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDRDSD
  PTO_TRDRDDD_ENTRY PtoTrdrddd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDRDDD
  PTO_TWRWRBAN_ENTRY PtoTwrwrban; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRWRBAN
  PTO_TWRWRSCL_ENTRY PtoTwrwrscl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRWRSCL
  PTO_TWRWRSCDLR_ENTRY PtoTwrwrscdlr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRWRSCDLR
  PTO_TWRWRSC_ENTRY PtoTwrwrsc; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRWRSC
  PTO_TWRWRSD_ENTRY PtoTwrwrsd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRWRSD
  PTO_TWRWRDD_ENTRY PtoTwrwrdd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRWRDD
  PTO_TWRRDSCDLR_ENTRY PtoTwrrdscdlr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRRDSCDLR
  PTO_TRDWR_ENTRY PtoTrdwr; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TRDWR
  PTO_TWRRD_ENTRY PtoTwrrd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TWRRD
  PTO_DDR4_UECC_RETRY_ENTRY PtoDdr4UeccRetry; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_DDR4_UECC_RETRY
  PTO_ADDR_CMD_SETUP_ENTRY PtoAddrCmdSetup; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ADDR_CMD_SETUP
  PTO_CS_ODT_SETUP_ENTRY PtoCsOdtSetup; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CS_ODT_SETUP
  PTO_CKE_SETUP_ENTRY PtoCkeSetup; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CKE_SETUP
  PTO_CLK_DRV_STREN_ENTRY PtoClkDrvStren; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CLK_DRV_STREN
  PTO_ADDR_CMD_DRV_STREN_ENTRY PtoAddCmdDrvStren; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_ADDR_CMD_DRV_STREN
  PTO_CS_ODT_DRV_STREN_ENTRY PtoCsOdtDrvStren; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CS_ODT_DRV_STREN
  PTO_CKE_DRV_STREN_ENTRY PtoCkeDrvStren; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_CKE_DRV_STREN
  PTO_RX_ENABLE_DELAY_ENTRY PtoRxEnable; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_RX_ENABLE_DELAY
  PTO_TX_DQ_DELAY_ENTRY PtoTxDqDly; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TX_DQ_DELAY
  PTO_RX_PB_DELAY_ENTRY PtoRxPbDly; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_RX_PB_DELAY
  PTO_RX_CLK_DELAY_ENTRY PtoRxClkDly; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_RX_CLK_DELAY
  PTO_VREF_DAC_0_ENTRY PtoVrefDAC0; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_VREF_DAC0
  PTO_VREF_DAC_1_ENTRY PtoVrefDAC1; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_VREF_DAC1
  PTO_VREF_IN_GLOBAL_ENTRY PtoVrefInGlobal; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_VREF_IN_GLOBAL
  PTO_1D_TRAIN_MR0_ENTRY Pto1dTrainMr0; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR0
  PTO_1D_TRAIN_MR1_ENTRY Pto1dTrainMr1; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR1
  PTO_1D_TRAIN_MR2_ENTRY Pto1dTrainMr2; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR2
  PTO_1D_TRAIN_MR3_ENTRY Pto1dTrainMr3; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR3
  PTO_1D_TRAIN_MR4_ENTRY Pto1dTrainMr4; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR4
  PTO_1D_TRAIN_MR5_ENTRY Pto1dTrainMr5; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR5
  PTO_1D_TRAIN_MR6_ENTRY Pto1dTrainMr6; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_MR6
  PTO_1D_TRAIN_PHY_VREF_ENTRY Pto1dTrainPhyVref; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_PHY_VREF
  PTO_1D_TRAIN_SEQUENCE_CTRL_ENTRY Pto1dTrainSeqCtrl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_SEQUENCE_CTRL
  PTO_1D_TRAIN_DFI_MRL_MARGIN_ENTRY Pto1dTrainDfiMrlMargin; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_DFI_MRL_MARGIN
  PTO_1D_CUSTOM_MSG_ENTRY Pto1dCustomMsg; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_CUSTOM_MSG
  PTO_1D_TRAIN_ACSM_ODT_CTRL0_ENTRY Pto1dTrainAcsmOdtCtrl0; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL0
  PTO_1D_TRAIN_ACSM_ODT_CTRL1_ENTRY Pto1dTrainAcsmOdtCtrl1; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL1
  PTO_1D_TRAIN_ACSM_ODT_CTRL2_ENTRY Pto1dTrainAcsmOdtCtrl2; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL2
  PTO_1D_TRAIN_ACSM_ODT_CTRL3_ENTRY Pto1dTrainAcsmOdtCtrl3; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL3
  PTO_1D_TRAIN_ACSM_ODT_CTRL4_ENTRY Pto1dTrainAcsmOdtCtrl4; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL4
  PTO_1D_TRAIN_ACSM_ODT_CTRL5_ENTRY Pto1dTrainAcsmOdtCtrl5; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL5
  PTO_1D_TRAIN_ACSM_ODT_CTRL6_ENTRY Pto1dTrainAcsmOdtCtrl6; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL6
  PTO_1D_TRAIN_ACSM_ODT_CTRL7_ENTRY Pto1dTrainAcsmOdtCtrl7; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ACSM_ODT_CTRL7
  PTO_1D_TRAIN_ALT_WCAS_L_ENTRY Pto1dTrainAltWcsL; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_1D_TRAIN_ALT_WCAS_L
  PTO_2D_TRAIN_MR0_ENTRY Pto2dTrainMr0; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR0
  PTO_2D_TRAIN_MR1_ENTRY Pto2dTrainMr1; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR1
  PTO_2D_TRAIN_MR2_ENTRY Pto2dTrainMr2; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR2
  PTO_2D_TRAIN_MR3_ENTRY Pto2dTrainMr3; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR3
  PTO_2D_TRAIN_MR4_ENTRY Pto2dTrainMr4; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR4
  PTO_2D_TRAIN_MR5_ENTRY Pto2dTrainMr5; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR5
  PTO_2D_TRAIN_MR6_ENTRY Pto2dTrainMr6; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_MR6
  PTO_2D_TRAIN_PHY_VREF_ENTRY Pto2dTrainPhyVref; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_PHY_VREF
  PTO_2D_TRAIN_SEQUENCE_CTRL_ENTRY Pto2dTrainSeqCtrl; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_SEQUENCE_CTRL
  PTO_2D_TRAIN_DFI_MRL_MARGIN_ENTRY Pto2dTrainDfiMrlMargin; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_DFI_MRL_MARGIN
  PTO_2D_TRAIN_RX2D_TRAIN_OPT_ENTRY Pto2dTrainRx2dOpt; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_RX2D_TRAIN_OPT
  PTO_2D_TRAIN_TX2D_TRAIN_OPT_ENTRY Pto2dTrainTx2dOpt; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_TX2D_TRAIN_OPT
  PTO_2D_CUSTOM_MSG_ENTRY Pto2dCustomMsg; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_CUSTOM_MSG
  PTO_2D_TRAIN_ACSM_ODT_CTRL0_ENTRY Pto2dTrainAcsmOdtCtrl0; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL0
  PTO_2D_TRAIN_ACSM_ODT_CTRL1_ENTRY Pto2dTrainAcsmOdtCtrl1; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL1
  PTO_2D_TRAIN_ACSM_ODT_CTRL2_ENTRY Pto2dTrainAcsmOdtCtrl2; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL2
  PTO_2D_TRAIN_ACSM_ODT_CTRL3_ENTRY Pto2dTrainAcsmOdtCtrl3; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL3
  PTO_2D_TRAIN_ACSM_ODT_CTRL4_ENTRY Pto2dTrainAcsmOdtCtrl4; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL4
  PTO_2D_TRAIN_ACSM_ODT_CTRL5_ENTRY Pto2dTrainAcsmOdtCtrl5; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL5
  PTO_2D_TRAIN_ACSM_ODT_CTRL6_ENTRY Pto2dTrainAcsmOdtCtrl6; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL6
  PTO_2D_TRAIN_ACSM_ODT_CTRL7_ENTRY Pto2dTrainAcsmOdtCtrl7; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ACSM_ODT_CTRL7
  PTO_2D_TRAIN_ALT_WCAS_L_ENTRY Pto2dTrainAltWcsL; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_2D_TRAIN_ALT_WCAS_L
  PTO_VALIDITY_END PtoValidtyEnd; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_VALIDITY_TERMINATOR
  PTO_VALIDITY_DRAM_MFG_ID_ENTRY      PtoValDramMfgId; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_VALIDITY_DRAM_MFG_ID
  PTO_VALIDITY_DRAM_STEPPING_ENTRY  PtoValDramStepping; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_VALIDITY_DRAM_STEPPING
  PTO_TERMINATE_ENTRY  PtoTerminate; ///< @SELECTION: PTEType = PLATFORM_TUNING_ENTRY::PLATFORM_TUNING_TERMINATOR
} MEM_PLATFORM_TUNING;

/**
 * @brief This data structure is used to pass memory MEM_PLATFORM_TUNING data
 * @details GROUPID: APCB_GROUP_MEMORY TYPEID: APCB_MEM_TYPE_PLATFORM_TUNING
 */
typedef struct {
  MEM_PLATFORM_TUNING       MemPTE1st; ///< Platform Tuning First Value
  MEM_PLATFORM_TUNING       MemPTE[];  ///< Platform Tuning List of Values
} PLATFORM_TUNING_ENTRY_ARRAY;

#endif // _APCB_MEM_PLATFORM_TUNING_H_



