/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_ABL_BREAKPOINT_H_
#define _APCB_ABL_BREAKPOINT_H_
//
// @APCB_START
//


 //Note a is from 0 to 31
#define BP_SHIFT(a)   ((UINT64)1 << a)

// Breakpoint Definition
//UMC BPs
#define APCB_BP_UMC_PHASE_1_END                             BP_SHIFT (0)  // End of Phase 1 Initialization  - all addressing/UMC configs done
#define APCB_BP_UMC_START_PMU_ON_IMAGE                      BP_SHIFT (1)  // Start PMU on imagex  - PHY init/SRAM Msg Block done ; just staring 1D training
#define APCB_BP_UMC_MISSION_MODE_CONFIG                     BP_SHIFT (2)  // UMC mision mode configuration
#define APCB_BP_UMC_PMU_FINISHED                            BP_SHIFT (3)  // PMU Finish
#define APCB_BP_UMC_2D_TRAINING_DONE                        BP_SHIFT (4)  // PMU Based Training complete  - 2D Training done
#define APCB_BP_UMC_MEM_PHASE_2_END                         BP_SHIFT (5)  // End of Phase 2 Initialization  - Mission mode timings updated (turn around timings)
#define APCB_BP_UMC_BEFORE_INITIAL_PSTATE                   BP_SHIFT (6)  // Before initial P-state change
#define APCB_BP_UMC_AFTER_INITIAL_PSTATE                    BP_SHIFT (7)  // After initial P-state change
#define APCB_BP_UMC_BEFORE_DRAM_READY                       BP_SHIFT (8)  // Before set UMC DramReady = 1
#define APCB_BP_UMC_BEFORE_INITIAL_IN_PSTATE_FUNCTION       BP_SHIFT (9)  // Before initial P-state change in Pstate function
#define APCB_BP_UMC_AFTER_RECOVERY_MOP_SR_DSTATE1_FUNCTION  BP_SHIFT (15) // After Recover MOP array init but beore Self Refresh DSTATE1 change
#define APCB_BP_UMC_AFTER_RECOVERY_MOP_FUNCTION             BP_SHIFT (16) // After Recovery MOP array function
#define APCB_BP_UMC_DRAM_DETECTION_COMPLETE                 BP_SHIFT (17)    // ABL Memory Detection Completed
#define APCB_BP_UMC_BEFORE_PPT_ENABLE_DISABLE               BP_SHIFT (19) // Before sending the message to enable Periodic retraiing.


//DF BPs
#define APCB_BP_DF_INIT_START                   BP_SHIFT (10)
#define APCB_BP_DF_BEFORE_LINK_TRAINING         BP_SHIFT (11)
#define APCB_BP_DF_LINK_TRAINING_COMPLETE       BP_SHIFT (12)
#define APCB_BP_DF_BEFORE_CREDIT_RELEASE        BP_SHIFT (13)
#define APCB_BP_DF_INIT_COMPLETE                BP_SHIFT (14)

//Other BPS
#define APCB_BP_CUSTOM                          BP_SHIFT (30)
#define APCB_BREAKPOINT_DONE                    BP_SHIFT (31)


//BP related Register definitions
#define UMC_CH_SMN_BASE   0x50000
#define ABL_BP_CONTROL_UMC_CAP          (UMC_CH_SMN_BASE | 0xDF4)      // UMC::CH::UmcCapHi
#define ABL_DBG_CTRL_BKPT_EN             0x0100
#define ABL_DBG_CTRL_CONSOLE_OUT_EN      0x0200
#define ABL_DBG_CTRL_PMU_HDT_CTRL_DIS    0x0400

#define UMC_CTRL_SMN_BASE 0x51000
#define ENV_CONTROL_UMC_SCRATCH_REG_0   (UMC_CTRL_SMN_BASE | 0x050)    // UserDataPattern0
#define ENV_CONTROL_UMC_SCRATCH_REG_1   (UMC_CTRL_SMN_BASE | 0x054)    // UserDataPattern1
#define ENV_CONTROL_UMC_SCRATCH_REG_2   (UMC_CTRL_SMN_BASE | 0x058)    // UserDataPattern2
#define ENV_CONTROL_UMC_SCRATCH_REG_3   (UMC_CTRL_SMN_BASE | 0x05C)    // UserDataPattern3

#define ABL_DBG_SMN_DATA_MBOX_0 ENV_CONTROL_UMC_SCRATCH_REG_2   // Data Mailbox
#define ABL_DBG_SMN_CMD_MBOX_1 ENV_CONTROL_UMC_SCRATCH_REG_3   // Command Mailbox
#define APCB_BREAKPOINT_SMN_OPTIONS ENV_CONTROL_UMC_SCRATCH_REG_0       // Command Options

#define ABL_DBG_CMD_ABL_BP_FOUND         0x5000C001    // Command from ABL to script indicating that BP found
#define ABL_DBG_CMD_ABL_CMD_DONE         0x5000C002    // Command from ABL to script indicating that command processed
#define ABL_DBG_CMD_ABL_BOOT_DONE        0x5000DEAD    // Command from ABL to script indicating that All BPs are done
#define ABL_DBG_CMD_ABL_BP_INIT          0xC001BEE5    // Command from ABL to script indicating init breakpoints
#define ABL_DBG_CMD_SCRIPT_CONTINUE      0xC001C001    // Command from script to ABL indicating continue execution
#define ABL_DBG_CMD_SCRIPT_BP_LIST       0xC001BB11    // Command from script to indicating breakpoints list
#define ABL_DBG_CMD_SCRIPT_GET_PMU_STAGE 0xC001BB12    // Command from script to get training stage of PMU flow
#define ABL_DBG_CMD_SCRIPT_GET_SPD_DATA  0xC001BB13    // Command from script to get SRAM pointer of SPD Data
#define ABL_DBG_CMD_SCRIPT_SET_MEM_FREQ  0xC001BB14    // Command from script to set Memory frequency
#define ABL_DBG_CMD_SCRIPT_SET_BPSTAMP   0xC001BB21    // Command from script to set breakpoint at specific stamp
#define ABL_DBG_CMD_ABL_HDTOUT_INIT  0x99CCEEEE    // Command from ABL to script indicating init ABL HDTOUT
#define ABL_DBG_CMD_ABL_HDTOUT_EXIT  0x99CCD00E    // Command from ABL to script indicating that All HDTOUT print are finished
#define ABL_DBG_CMD_ABL_HDTOUT_PRINT 0x99CC9000    // Command from ABL to script indicating that print ASCII from Script register buffer, last 3 nibble indicated the print size

#define APCB_BREAKPOINT_SMN_DATA_MBOX_0 ENV_CONTROL_UMC_SCRATCH_REG_2   // Data Mailbox
#define APCB_BREAKPOINT_SMN_CMD_MBOX_1 ENV_CONTROL_UMC_SCRATCH_REG_3   // Command Mailbox
#define APCB_BREAKPOINT_CMD_ABL_BP_FOUND  0x5000C001         // Command from ABL indicating that BP found
#define APCB_BREAKPOINT_CMD_ABL_BP_DONE 0x5000DEAD         // Command from ABL indicating that All BPs are done
#define APCB_BREAKPOINT_CMD_CONTINUE   0xC001C001        // Command from script to ABL indicating continue execution
#define APCB_BREAKPOINT_CMD_EXTERNAL_ENABLE  0xC001BEE5  // Command to enable breakpoints
#define APCB_BREAKPOINT_CMD_BP_LIST  0xC001BB11          // Command from script to indicating


#define APCB_IDS_BREAKPOINT(ApcbBreakpointNumber, StdHeader)\
    if (ApcbIdsBreakpoint(ApcbBreakpointNumber, (StdHeader)))

#define CUSTOM_BP APCB_IDS_BREAKPOINT(APCB_BP_CUSTOM, StdHeader)

//
// Pmu Training Stage Definition
//
typedef union {
  struct {
    UINT32 Umc              : 4;    // UMC instance
    UINT32 PmuFirmwareImage : 4;    // Started Pmu Firmware Image
    UINT32 MemPstate        : 4;    // Zero-based MemPstate
    UINT32 Spare            : 19;   // Reserved, Must Be Zero
    UINT32 Valid            : 1;    // Available
  } Bits;
  UINT32 Uint32;
} BPMSG_PMU_TRAN_STAGE;

//
// Set Memory Frequency Message Structure Definition
//
typedef union {
  struct {
    UINT32 MemclkFreq           : 12;
    UINT32 FclkFreqOverride     : 1;
    UINT32 FclkFreq             : 12;
    UINT32 UclkDiv1ModeOverride : 1;
    UINT32 UclkDiv1Mode         : 1;
    UINT32 Spare                : 5;
  } Bits;
  UINT32 Uint32;
} BPMSG_SET_MEM_FREQ;

//
// APCB BreakPoint Definition
//
typedef struct {
  UINT32                 BreakPointsEnabled;        // Indicates if BP are enabled
  UINT32                 BreakPointValue;           // BreakPoint Value
  UINT32                 BreakPointOptions;         // Options
  BPMSG_PMU_TRAN_STAGE   PmuTrainingStage;          // Log training stage
} APCB_BREAKPOINT_CONTROL_STRUCT;

//
// @LPDDR4 BU ONLY
//
#define BP_OPT_WL_SET_B       (1 << 2)  // Write Latency Set A / B
#define BP_OPT_SKIP_RRW       (1 << 3)  // Skip RRW Test
#define BP_OPT_PR_EN          (1 << 4)  // Periodic Retrain Enable
#define BP_OPT_SPEED_LIMIT    (7 << 5)  // Speed Limit Override
#define BP_OPT_CSINTLV_DIS    (1 << 8)  // Chipselect Interleaving
#define BP_OPT_BANKSWAP_DIS   (1 << 9)  // Bank Swap
#define BP_OPT_ADDRHASH_DIS   (1 << 10) // Address hash
#define BP_OPT_CMDSPC_DIS     (1 << 11) // Optimized Command Spacing
#define BP_OPT_DERATED_EN     (1 << 12) // Optimized Command Spacing - Derated
#define BP_OPT_RANK1_DIS      (1 << 13) // Disable Rank 1
#define BP_OPT_RD_DBI_EN      (1 << 14) // Read DBI Enable
#define BP_OPT_WR_DBI_EN      (1 << 15) // Write DBI Enable
#define BP_OPT_MPSTATES_EN    (1 << 16) // Memory PStates Enable

#endif // _APCB_ABL_BREAKPOINT_H_


