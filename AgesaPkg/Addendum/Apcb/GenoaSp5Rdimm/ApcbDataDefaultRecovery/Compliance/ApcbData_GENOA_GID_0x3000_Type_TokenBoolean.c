/*****************************************************************************
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/

/* $NoKeywords:$ */
/**
 * @file
 *
 * @e \$Revision:$   @e \$Date:$
 */


#include <MyPorting.h>
#include <MiscMemDefines.h>
#include <APCB.h>
#include "ApcbCustomizedDefinitions.h"
#include "ApcbCustomizedBoardDefinitions.h"
#include <ApcbDefaults.h>
#include <ApcbV3TokenUid.h>


APCB_TYPE_DATA_START_SIGNATURE();
APCB_V3_TYPE_HEADER       ApcbTypeHeader = {
  APCB_GROUP_TOKEN,
  APCB_TYPE_TOKEN_BOOLEAN,
  sizeof(ApcbTypeHeader),                       // SizeOfType, will be fixed up by tool
  0,                          // InstanceId
  {
    APCB_TYPE_ATTR_CONTEXT_TYPE_TOKEN,
    APCB_TYPE_ATTR_CONTEXT_FORMAT_ASCENDING,
    APCB_TYPE_ATTR_UNITSIZE_TOKEN_V3,
    APCB_PRIORITY_TYPE_MASK_DEFAULT,
    APCB_TYPE_ATTR_KEYSIZE_TOKEN_V3,
    APCB_TYPE_ATTR_KEYPOS_TOKEN_V3,
    BLDCFG_APCB_DATA_BOARD_MASK
  }
};  // SizeOfType will be fixed up by tool




APCB_TOKEN_PAIR_BOOL TokeList[] = {
// Two macros can be used for token definitions
//  APCB_TOKEN_BOOL (APCB_TOKEN_UID_NAME, APCB_TOKEN_UID_NAME_VALUE),
//  APCB_TOKEN_VAL_BOOL(APCB_TOKEN_UID_NAME), // Expand to use APCB_TOKEN_UID_NAME_VALUE

APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PSP_TP_PORT),
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PSP_ERROR_DISPLAY),
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PSP_EVENT_LOG_DISPLAY),
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PSP_STOP_ON_ERROR),
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PSP_PSB_AUTO_FUSE),
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMHOLEREMAPPING),                                           //< MemHoleRemapping - Memory Hole Remapping (1-bit).
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_LIMITMEMORYTOBELOW1TB),                                      //< Limit memory address space to below 1 TB
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLECHIPSELECTINTLV),                                      //< EnableChipSelectIntlv - Dram chip select Interleaving (1-bit).
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLECHANNELINTLV),                                         //< EnableChannelIntlv - Channel Interleaving (1-bit).
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEECCFEATURE),                                           //< EnableEccFeature - enable ECC error to go into MCE.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEPOWERDOWN),                                            //< EnablePowerDown - CKE based power down mode (1-bit).
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEPARITY),                                               //< EnableParity - Parity control.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEBANKSWIZZLE),                                          //< EnableBankSwizzle - BankSwizzle control.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEMEMCLR),                                               //< EnableMemClr - Memory Clear functionality control.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMRESTORECTL),                                              //< MemRestoreCtl - Memory context restore control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ISCAPSULEMODE),                                              //< IsCapsuleMode - Capsule reboot control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_AMPENABLE),                                                  //< AmpEnable - Specify the average time between refresh requests to all DRAM devices.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ECCREDIRECTION),                                             //< CfgEccRedirection; ///< ECC Redirection.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ECCSYNCFLOOD),                                               //< CfgEccSyncFlood -  ECC Sync Flood.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DQSTRAININGCONTROL),                                         //< CfgDqsTrainingControl -  Dqs Training Control.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_UMAABOVE4G),                                                 //< CfgUmaAbove4G -  Uma Above 4G Support
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYALLCLOCKSON),                                          //< CfgMemoryAllClocksOn -  Memory All Clocks On.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_IGNORESPDCHECKSUM),                                          //< CfgIgnoreSpdChecksum -  Ignore Spd Checksum.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYMODEUNGANGED),                                         //< CfgMemoryModeUnganged -  Memory Mode Unganged.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYQUADRANKCAPABLE),                                      //< CfgMemoryQuadRankCapable -  Memory Quad Rank Capable.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYRDIMMCAPABLE),                                         //< CfgMemoryRDimmCapable -  Memory RDIMM Capable.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYLRDIMMCAPABLE),                                        //< CfgMemoryLRDimmCapable -  Memory LRDIMM Capable.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYUDIMMCAPABLE),                                         //< CfgMemoryUDimmCapable -  Memory UDIMM Capable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEMORYSODIMMCAPABLE),                                        //< CfgMemorySODimmCapable - Memory SODimm Capable.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DRAMDOUBLEREFRESHRATEEN),                                    //< CfgDramDoubleRefreshRateEn - Double DRAM refresh rate
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DIMMTYPEDDDR3CAPABLE),                                       //< DimmTypeDddr3Capable -  Indicates that the system is DDR3 Capable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DIMMTYPELPDDDR3CAPABLE),                                     //< DimmTypeLpDddr3Capable -  Indicates that the system is LPDDR3 Capable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEBANKGROUPSWAP),                                        //< EnableBankGroupSwap - Indicates that Bank Group Swap is enabled
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_SWCMDTHROTEN),                                               //< UMC::CH::ThrottleCtrl[SwCmdThrotEn]
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEMEMPSTATE),                                            //< Memory Pstate Enable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DDRROUTEBALANCEDTEE),                                        //< CfgDdrRouteBalancedTee - Motherboard DDR Routing control.
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_TEMP_CONTROLLED_REFRESH_EN),                             //< Dram Temperature Controlled Refresh Rate Enable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLEBANKGROUPSWAPALT),                                     //< Bank Group Swap Alt control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_TEMP_CONTROLLED_EXTENDED_REFRESH_EN),                    //< MR4[2] Temperature Controlled Refresh Range
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_CTRL),                            //< Aggressor Static Lane Select Control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_CTRL),                             //< Target Static Lane Select Control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PCIE_RESET_CONTROL),                                         //< PCIe Reset Control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DISPLAY_PMU_TRAIN_RESULTS),                                  //< Display PMU training results
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_GROUP_D_PLATFORM),                                           //< Group D platform selection
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DISREFCMDTHROTCNT),                                          //< UMC::CH::ThrottleCtrl [30] DisRefCmdThrotCnt
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_FORCE_DATA_MASK_DISABLE_DDR4),                           //< Force Data Mask Disable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_OC_VDDIO_CONTROL),                                       //< MEM VDDIO control
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_SPD_READ_OPTIMIZATION_DDR4),                             //< SPD read optimization enablement
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_MEM_TSME_ENABLE_DDR),                                        //< TSME enable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DISABLE_NVDIMM_N_FEATURE),                                   //< Disable NVDIMM-N feature for memory margin tool
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_CCX_PPIN_OPT_IN),                                            //< Enable / Disable PPIN feature
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_CONFIGURE_SECOND_PCIE_LINK),                                 //< Enable second PCIe link
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_BMC_INIT_BEFORE_DRAM),                                       //< BMC init entrypoint selection
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ENABLE_VGA_PROGRAM),                                         //< Display Splash Screen
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_DXIO_VGA_API_ENABLE),                                        //< Enable/Disable DXIO API
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PERFORMANCE_TRACING),                                        //< Performance Tracing
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_GNB_ADDI_FEAT_CFG),                                          //< Addition Feature Config
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM),                                          //< Addition Feature Config DSM
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM_DETECTOR),                                 //< Addition Feature Config DSM Detector
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_GNB_ADDI_FEAT_L3_PERF_BIAS),                                 //< Addition Feature Config L3 Perf Bias
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ESPI_ABL_INIT_ENABLE),                                       //< Enable eSPI ABL init
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_SME_MK_ENABLE),                                              //< Enable SME-MK
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_CPU_WDT_EN),                                                 //< CPU WDT Enable
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_PSP_SEV_DISABLE),                                            //< Enable/Disable SEV, 0: Enabled, 1: Disabled
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_FCH_SPD_CONTROL_OWNERSHIP),                                  //< FCH SPD Host Control Ownership
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_ESPI_ABL_INIT_ENABLE),                                       //< ESPI_ABL_INIT_ENABLE
APCB_TOKEN_VAL_BOOL (APCB_TOKEN_UID_IOMMU),                                                      //< IOMMU enablement
//  APCB_TOKEN_BOOL (0x00000000, FALSE) // Null token, remove this when there's other token defined
};


APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();




