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
  APCB_GROUP_TOKEN,           // GroupId
  APCB_TYPE_TOKEN_4BYTES,     // TypeId
  sizeof(ApcbTypeHeader),     // SizeOfType, will be fixed up by tool
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




APCB_TOKEN_PAIR_UINT32 TokeList[] = {
// Two macros can be used for token definitions
//  APCB_TOKEN_U32 (APCB_TOKEN_UID_NAME, APCB_TOKEN_UID_NAME_VALUE),
//  APCB_TOKEN_VAL_U32(APCB_TOKEN_UID_NAME),  // Expand to use APCB_TOKEN_UID_NAME_VALUE

  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_CPU_FETCH_FROM_SPI_AP_BASE),                                                //< APs start to fetch code from this address when boot from SPI ROM
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_CCX_MIN_SEV_ASID),                                                          //< override by original CBS token APCB_TOKEN_UID_CBS_CMN_CPU_SEV_ASID_SPACE_LIMIT
                                                                                                                 //< MIN_SEV_ASID
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_PCI_MMIO_SIZE),                                                          //< Size in bytes of space used for PCI MMIO
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_PCI_MMIO_BASE),                                                          //< Lower base address of space used for PCI MMIO
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_PCI_MMIO_HI_BASE),                                                       //< Upper base address of space used for PCI MMIO
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_CAKE_CRC_THRESH_PERF_BOUNDS),                                            //< Percentage of performance to sacrifice for CAKE CRC in 0.00001% units
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_USERTIMINGMODE),                                                            //< UserTimingMode - User Memclock Mode.
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEMCLOCKVALUE),                                                             //< MemClockValue -  Memory Clock Value.
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEMORYBUSFREQUENCYLIMIT),                                                   //< CfgMemoryBusFrequencyLimit -  Memory Bus Frequency Limit.
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_POWERDOWNMODE),                                                             //< CfgPowerDownMode -  Power Down Mode.
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_U32),                                        //< Agressor Static Lane Select Upper 32 bit
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_L32),                                        //< Agressor Static Lane Select Lower 32 bit
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_U32),                                         //< Target Static Lane Select Upper 32 bit
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_L32),                                         //< Target Static Lane Select Lower 32 bit
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_PCIE_RESET_GPIO_PIN_SELECT),                                                //< PCIe reset Gpio pin select
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_FCH_ROM3_BASE_HIGH),                                                        //< ROM3 Base High
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_PSP_MEASURE_CONFIG),                                                        //< PSP Measure Config
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_MEM_SELF_HEAL_BIST_TIMEOUT),                                                //< Self Healing BIST Timeout (ms)
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DXIO_PHY_PARAM_VGA),                                                        //< APCB_TOKEN_UID_DXIO_PHY_PARAM_VGA
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DXIO_PHY_PARAM_POLE),                                                       //< APCB_TOKEN_UID_DXIO_PHY_PARAM_POLE
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DXIO_PHY_PARAM_DC),                                                         //< APCB_TOKEN_UID_DXIO_PHY_PARAM_DC
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DXIO_PHY_PARAM_IQOFC),                                                      //< APCB_TOKEN_UID_DXIO_PHY_PARAM_IQOFC
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_OPN_PLT_COMPAT_FUSING),                                                     //< APCB_TOKEN_UID_OPN_PLT_COMPAT_FUSING
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_PRESET_P11),                                                        //< APCB_TOKEN_UID_DF_XGMI_PRESET_P11
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_PRESET_P12),                                                        //< APCB_TOKEN_UID_DF_XGMI_PRESET_P12
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_PRESET_P13),                                                        //< APCB_TOKEN_UID_DF_XGMI_PRESET_P13
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_PRESET_P14),                                                        //< APCB_TOKEN_UID_DF_XGMI_PRESET_P14
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_PRESET_P15),                                                        //< APCB_TOKEN_UID_DF_XGMI_PRESET_P15
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_DEFAULT),                                               //< APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_DEFAULT
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L0_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L0_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L0_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L0_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L1_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L1_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L1_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L1_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L2_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L2_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L2_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L2_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L3_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L3_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L3_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L3_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L0_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L0_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L0_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L0_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L1_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L1_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L1_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L1_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L2_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L2_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L2_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L2_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L3_P01),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L3_P01
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L3_P23),                                                    //< APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L3_P23
  APCB_TOKEN_VAL_U32 (APCB_TOKEN_UID_XGMI_CHANNEL_TYPE),                                                         //< APCB_TOKEN_UID_XGMI_CHANNEL_TYPE
//  APCB_TOKEN_U32 (0x00000000, 0xFFFFFFFF) // Null token, remove this when there's other token defined
};


APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();



