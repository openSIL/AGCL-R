/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_DDR_POST_PACKAGE_REPAIR_H_
#define _APCB_MEM_DDR_POST_PACKAGE_REPAIR_H_
//
// @APCB_START
//

///
/// DDR Post Package Repair
///
#define MAX_DPPRCL_ENTRY    64
#define MAX_DPPRCL_SOCKETS  2
#define MAX_DPPRCL_CHANNELS 12
#define MAX_DPPRCL_ENTRIES MAX_DPPRCL_SOCKETS*MAX_DPPRCL_CHANNELS*MAX_DPPRCL_ENTRY    ///< @VALUE:1024

#define DPPR_SOFT_REPAIR 0
#define DPPR_HARD_REPAIR 1
#define DPPR_MBIST_REPAIR 2
#define DPPR_MBIST_RUN 3
#define DPPR_VALID_REPAIR 1
#define DPPR_INVALID_REPAIR 0
#define DPPR_SKIP_REPAIR  1    // if Repair and Valid and Repair skipped, it
                               // may be due to Bank Group Conflict

#define DPPR_DEVICE_X4   4
#define DPPR_DEVICE_X8   8
#define DPPR_DEVICE_X16  16
#define DPPR_DEVICE_ALL  0x1F

#define DPPR_NUM_CACHE_LINES 128
#define DPPR_BUBBLE_COUNT 256

#define DPPR_MAX_X16_DEVICES   72
#define DPPR_MAX_X4_DEVICES   18
#define DPPR_MAX_X8_DEVICES   9

#define DPPR_REPAIR_TARGET_DEVICES 0x1F

#pragma pack(1)
typedef struct _APCB_DPPRCL_REPAIR_ENTRY {
  UINT32 Bank:5;                           ///< [4:0] Bank {BG 4:2,BA 1:0}
  UINT32 RankMultiplier:3;                 ///< [7:5] Rank Multiplier
  UINT32 Device:5;                         ///< [12:8] Device width
                                           ///<        Device = 4, Repair DIMMs with device width x4 only
                                           ///<        Device = 8, Repair DIMMs with device width x8 only
                                           ///<        Device = 16, Repair DIMMs with device width x16 only
                                           ///<        Device = 0x1F - Ignore device width and repair specific devices based on TargetDevice
  UINT32 ChipSelect:2;                     ///< [14:13] ChipSelect
  UINT32 Column:10;                        ///< [24:15] Column Address
  UINT32 RepairType:1;                     ///< [25:25] Hard/soft repair (0=hard, 1=soft)
  UINT32 Valid:1;                          ///< [26:26] Valid entry
  UINT32 TargetDevice:5;                   ///< [31:27] Target Device (only valid if Device = 0x1F)
                                           ///<         x4 (0-17 (with ECC)), x8 (0-8 (with ECC))
  UINT32 Row:18;                           ///< [17:0] Row Address
  UINT32 Socket:3;                         ///< [20:18] Socket
  UINT32 Channel:3;                        ///< [23:21] Channel
  UINT32 Reserverd1:8;                     ///< pad to 32 bit
} APCB_DPPRCL_REPAIR_ENTRY;

typedef union _APCB_DPPRCL_REPAIR_ENTRY_V2 {
  struct {
    UINT32 Bank:5;                    ///< [4:0] Bank {BG 4:2,BA 1:0}
    UINT32 RankMultiplier:3;          ///< [7:5] Rank Multiplier
    UINT32 Device:5;                  ///< [12:8] Device width
                                      ///<        Device = 4, Repair DIMMs with device width x4 only
                                      ///<        Device = 8, Repair DIMMs with device width x8 only
                                      ///<        Device = 16, Repair DIMMs with device width x16 only
                                      ///<        Device = 0x1F - Ignore device width and repair specific devices based on TargetDevice
    UINT32 ChipSelect:2;              ///< [14:13] ChipSelect
    UINT32 Column:11;                 ///< [25:15] Column Address
    UINT32 Valid:1;                   ///< [26:26] Valid entry
    UINT32 TargetDevice:5;            ///< [31:27] Target Device (only valid if Device = 0x1F)
                                      ///<         x4 (0-17 (with ECC)), x8 (0-8 (with ECC))
    UINT32 Row:18;                    ///< [17:0] Row Address
    UINT32 Socket:3;                  ///< [20:18] Socket
    UINT32 Channel:4;                 ///< [24:21] Channel
    UINT32 SubChannel:1;              ///< [25] Sub Channel. 0 - SubChannel A, 1 - Sub Channel B
    UINT32 HardPPRDone:1;             ///< [26] Set Once after ABL performs a successful hard repair.
    UINT32 PPRUndo:1;                 ///< [27] Set to request a PPR undo on DDR5
    UINT32 PPRLock:1;                 ///< [28] Set to request a PPR Lock on DDR5
    UINT32 DeviceTypeToRepair : 3;    ///< [31:29] Device Type to be repaired
                                      ///< 0 = DDR, 1 = HBM, 2 and 3 Reserved for future use
    UINT32 SerialNumber:32;           ///< [31:0] DIMM Serial Number
    UINT32 ErrorCause:3;              ///< [2:0] Cause of the error initiating post package repair
    UINT32 RepairType:2;              ///< [4:3] Repair type (0=sPPR, 1=hPPR, 2=mPPR, 3=MBIST)
    UINT32 Reserved1:27;              ///< [31:5] MBZ
  }ddr;

  struct {
    UINT32 Bank : 4;                  ///< [3:0] Bank {BG 3:2, BA 1:0}
    UINT32 Reserved1 : 2;             ///< [5:4] MBZ
    UINT32 StackId : 2;               ///< [7:6] Stack Id
    UINT32 Column : 5;                ///< [12:8] Column Address
    UINT32 Reserved2 : 3;             ///< [15:13] MBZ
    UINT32 Row : 15;                  ///< [30:16] Row Address
    UINT32 Reserved3 : 1;             ///< [31] MBZ

    UINT32 RepairType : 1;            ///< [0] Repair Type (0 = Hard, 1 = Soft)
    UINT32 Valid : 1;                 ///< [1] Valid PPR entry
    UINT32 Reserved4 : 2;             ///< [3:2] MBZ
    UINT32 Socket : 3;                ///< [6:4] Socket
    UINT32 Reserved5 : 1;             ///< [7] MBZ
    UINT32 MfrId : 4;                 ///< [11:8] Manufacturer Id
    UINT32 Reserved6 : 4;             ///< [15:12] MBZ
    UINT32 Channel : 7;               ///< [22:16] Channel
    UINT32 Reserved7 : 1;             ///< [23] MBZ
    UINT32 SubChannel : 1;            ///< [24] SubChannel (DDR5)
    UINT32 HardPPRDone : 1;           ///< [25] Set once after ABL performs a successful Hard repair
    UINT32 Reserved8 : 3;             ///< [28:26] MBZ
    UINT32 DeviceTypeToRepair : 3;    ///< [31:29] Device Type to be repaired
                                      ///< 0 = DDR, 1 = HBM, 2 and 3 Reserved for future use

    UINT32 SerialNumberLoWord : 32; ///< [31:0] Serial Number LoWord
    UINT32 SerialNumberHiWord : 32; ///< [31:0] Serial Number HiWord
  } hbm;

} APCB_DPPRCL_REPAIR_ENTRY_V2;

/** APCB_DPPRCL_REPAIR_ENTRY
*    @GROUPID: 0x1704
*    @TYPEID: APCB_MEM_TYPE_DDR_POST_PACKAGE_REPAIR (0x5E)
*    APCB_DPPRCL_REPAIR_ENTRY
*/
typedef struct {
  APCB_DPPRCL_REPAIR_ENTRY          ApcbDpprclRepairEntry1st;
  APCB_DPPRCL_REPAIR_ENTRY          ApcbDpprclRepairEntry[];
} APCB_DPPRCL_REPAIR_ENTRY_STRUCTURE;

typedef struct {
  APCB_DPPRCL_REPAIR_ENTRY_V2          ApcbDpprclRepairEntry1st;
  APCB_DPPRCL_REPAIR_ENTRY_V2          ApcbDpprclRepairEntry[];
} APCB_DPPRCL_REPAIR_ENTRY_STRUCTURE_V2;
#pragma pack()

#endif // _APCB_MEM_DDR_POST_PACKAGE_REPAIR_H_


