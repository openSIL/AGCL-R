/*****************************************************************************
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * Environment Flags definition
 *
 * Contains additional declarations need to use Memory and CPU Advanced interface, such as
 * would be required by the basic interface implementations.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:  AGCL-R
 * @e sub-project:  Include
 * @e \$Revision: 260234 $   @e \$Date: 2014-03-13 09:47:02 -0600 (Wed, 13 Mar 2013) $
 */


#ifndef _ENVIRONMENT_FLAGS_H_
#define _ENVIRONMENT_FLAGS_H_

/* Emulation/Simulation Environment Control Scratch Register */
#define MP0_C2PMSG_97_ADDR                 0x3010A84ul
#define MP0_C2PMSG_98_ADDR                 0x3010A88ul
#define MP0_C2PMSG_99_ADDR                 0x3010A8Cul

#define PRESIL_CTRL0_REG   MP0_C2PMSG_97_ADDR            // C2PMSG_97
#define PRESIL_CTRL1_REG   MP0_C2PMSG_98_ADDR            // C2PMSG_98

//
// C2PMSG_97  (SMN address 0x3810A84)
//
typedef union {
  struct {
    UINT32 Environment:4;                  ///< Environment: 0 - HW, 1 - SoC emulation, 2 - Cobra, 3 - GIO, 4 - GC Lite.  Replaces UserDataPattern0 force
    UINT32 CoreClNum:3;                    ///< Core CL selector: Varies from release to release.  Replaces DF scratch 30[23:0] force
    UINT32 DisablePmuDevinitUseSwmra:1;    ///< Disable DEVINIT and use SWMRA instead. Replaces UmcCfgEco[19] force
    UINT32 OsBackdoorLoad:1;               ///< OS backdoor load to DRAM.  New feature bit.
    UINT32 SkipAllUSBControllerAccess:1;   ///< When set FW will skip all USB Control init communication from the FW
    UINT32 SkipAllUSBPhyAccess:1;          ///< When set FW will skip all USB phy communication from the FW
    UINT32 SkipDxioInitializaion:1;        ///<When set FW will skip DXIO Initialization from the FW>
    UINT32 ForceMpmMeventPath:1;           ///< Set to 1 to force MPM M-event path (X86 not released)
    UINT32 :18;                            ///< Reserved
  } Field;
  UINT32  Value;
} PRESIL_CTRL0;

#define PRESIL_CTRL_ENV_HW            0
#define PRESIL_CTRL_ENV_SOC_EMULATION 1
#define PRESIL_CTRL_ENV_COBRA         2
#define PRESIL_CTRL_ENV_GIO           3
#define PRESIL_CTRL_ENV_GC_LITE       4

//
// C2PMSG_98  (SMN address 0x3810A88)
//
typedef union {
  struct {
    UINT32 DisableMemtest:1;               ///< Disable the memory test.  Replaces UmcCfgEco[16] force.  DEPRECATING: Will move to APCB
    UINT32 DisableMemclear:1;              ///< Disable the memory clear.  Replaces DF scratch 30[31] force.  DEPRECATING: Already in APCB
    UINT32 DisableMemSetReg:1;             ///< Controls logging of UMC/PMU register writes.  Replaces UmcCfgEco[17] force.  DEPRECATING: Will create a filter in APCB
    UINT32 DisableMemtestVerbose:1;        ///< Controls logging of memtest.  Replaces UmcCfgEco[17] force.  DEPRECATING: Will create a filter in APCB
    UINT32 DisableExtSpd:1;                ///< Disable SPD read attempts across SMBus.  Replaces UmcCfgEco[20] force.  DEPRECATING: Will move to APCB
    UINT32 DisableRrwMemtest:1;            ///< Disable reliable read-write memtest.  Replaces UmcCfgEco[21] force.  DEPRECATING: Will move to APCB
    UINT32 DisableSettingUnusedChannel:1;  ///< Disable accesses to mem channels other than 0.  Replaces UmcCfgEco[22] force.  DEPRECATING: Will consume harvest fuses
    UINT32 DisableDxioPhyFwLoad:1;         ///< Disable MP0 DXIO phy firmware loading process.  Replaces DF scratch 30[31] force.  DEPRECATING: Will try to move to APCB
    UINT32 DisableMemToUseDvSettings:1;    ///< Design verification settings.  Replaces UmcCfgEco[23] force.  DEPRECATING: Will be a build time switch
    UINT32 EnableAblVerboseMessaging:1;    ///< verbose message control; 0- no override (controlled by build config), 1- enable>
    UINT32 DisableSerialOut:1;             ///< serial out control; 0- no override (controlled by build config), 1- disable>
    UINT32 EnableIoRedirect:1;             ///< Port 80 control. Replaces C2PMSG_82[31] force; 0- no override (controlled by build config), 1- enable>
    UINT32 FASTSIM_GIO:1;                  ///< FASTSIM_GIO
    UINT32 FASTSIM_DXIO:1;                 ///< FASTSIM_DXIO
    UINT32 FASTSIM_DFLT_TBL:1;             ///< FASTSIM_DFLT_TBL
    UINT32 FASTSIM_SMU_MSGS:1;             ///< FASTSIM_SMU_MSGS
    UINT32 FASTSIM_PWR_MSGS:1;             ///< FASTSIM_PWR_MSGS
    UINT32 FASTSIM_PEI_LOG:1;              ///< FASTSIM_PEI_LOG
    UINT32 FASTSIM_DXE_LOG:1;              ///< FASTSIM_DXE_LOG
    UINT32 UseUmcHardcode:1;               ///< Use Hardcoded UMC Settings
    UINT32 UseDdrPhyHardcode:1;            ///< Use Hardcoded DDR PHY Settings
    UINT32 EmulatorType:2;                 ///< Emulator Type. 00 - Palladium. 01 - Veloce.
    UINT32 UseDfHardcode:1;                ///< Use Hardcoded DV DF settings
    UINT32 DisableMp1DxioPhyFwLoad:1;      ///< Disable phy FW loading for MP1
    UINT32 EnableCharPrintSocket1:1;       ///< Enable Socket 1 CharPrint to C2P_MSG_99
    UINT32 :6;                             ///< Reserved
  } Field;
  UINT32  Value;
} PRESIL_CTRL1;

typedef struct {
  PRESIL_CTRL0               PreSilCtrl0;
  PRESIL_CTRL1               PreSilCtrl1;
} ENV_FLAGS_STRUCT;

typedef struct _PRESIL_CTRL_FLAG_CHECK {
  UINT32  EnvValue;
  UINT32  ExpectedValue;
} PRESIL_CTRL_FLAG_CHECK;

#endif // _ENVIRONMENT_FLAGS_H_

