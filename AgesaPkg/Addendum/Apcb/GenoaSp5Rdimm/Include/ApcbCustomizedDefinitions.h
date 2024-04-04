/*****************************************************************************
*
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
**/
/**
 *
 * @file ApcbCustomizedDefinitions.h
 *
 * @brief Platform configuration parameter declaration in AGESA PSP Customization Block.
 * @details Customer controllable platform configuration parameter declaration in AGESA PSP Customization Block.
 *
 **/
//
// OEM CUSTOMIZABLE DEFINITIONS. Any changes must be done here...
//

#ifndef _APCB_CUSTOMIZED_DEFINITIONS_H_
#define _APCB_CUSTOMIZED_DEFINITIONS_H_

// =================================================================================================
// APCB Token Value Customization
// =================================================================================================

//Alias: BLDCFG_TIMING_MODE_SELECT
#define APCB_TOKEN_UID_USERTIMINGMODE_VALUE                                    TIMING_MODE_AUTO

//Alias: BLDCFG_MEMORY_CLOCK_SELECT
#define APCB_TOKEN_UID_MEMCLOCKVALUE_VALUE                                     DDR2400_FREQUENCY

//Alias: BLDCFG_MEMORY_ENABLE_CHIPSELECT_INTERLEAVING
#define APCB_TOKEN_UID_ENABLECHIPSELECTINTLV_VALUE                             FALSE

//Alias: BLDCFG_ENABLE_ECC_FEATURE
#define APCB_TOKEN_UID_ENABLEECCFEATURE_VALUE                                  FALSE

//Alias: BLDCFG_MEMORY_POWER_DOWN
#define APCB_TOKEN_UID_ENABLEPOWERDOWN_VALUE                                   FALSE

//Alias: BLDCFG_PARITY_CONTROL
#define APCB_TOKEN_UID_ENABLEPARITY_VALUE                                      TRUE

//Alias: BLDCFG_BANK_SWIZZLE
#define APCB_TOKEN_UID_ENABLEBANKSWIZZLE_VALUE                                 FALSE

//Alias: BLDCFG_MEMORY_RESTORE_CONTROL
#define APCB_TOKEN_UID_MEMRESTORECTL_VALUE                                     FALSE

//Alias: BLDCFG_PMU_TRAINING_MODE
#define APCB_TOKEN_UID_PMUTRAINMODE_VALUE                                      PMU_TRAIN_1D_2D

#define APCB_TOKEN_UID_DISPLAY_PMU_TRAIN_RESULTS_VALUE                         FALSE

//Alias: BLDCFG_ECC_SYMBOL_SIZE
#define APCB_TOKEN_UID_ECCSYMBOLSIZE_VALUE                                     SYMBOL_SIZE_X16

//Alias: BLDCFG_MEMORY_ALL_CLOCKS_ON
#define APCB_TOKEN_UID_MEMORYALLCLOCKSON_VALUE                                 TRUE

//Alias: BLDCFG_POWER_DOWN_MODE
#define APCB_TOKEN_UID_POWERDOWNMODE_VALUE                                     POWER_DOWN_BY_CHANNEL

//Alias: BLDCFG_IGNORE_SPD_CHECKSUM
#define APCB_TOKEN_UID_IGNORESPDCHECKSUM_VALUE                                 TRUE

//Alias: BLDCFG_BANK_SWAP_GROUP_ENABLE
#define APCB_TOKEN_UID_ENABLEBANKGROUPSWAP_VALUE                               TRUE

//Alias: BLDCFG_ODT_CMD_THROT_ENABLE
#define APCB_TOKEN_UID_ODTSCMDTHROTEN_VALUE                                    TRUE

//Alias: BLDCFG_SW_CMD_THROT_ENABLE
#define APCB_TOKEN_UID_SWCMDTHROTEN_VALUE                                      0

//Alias: BLDCFG_ODTSEN_VALUE
#define APCB_TOKEN_UID_ODTSEN_VALUE                                            TRUE

//Alias: BLDCFG_ODT_CMD_THROT_CYCLE
#define APCB_TOKEN_UID_ODTSCMDTHROTCYC_VALUE                                   0x1ff

//Alias: BLDCFG_SW_CMD_THROT_CYCLE
#define APCB_TOKEN_UID_SWCMDTHROTCYC_VALUE                                     0

//Alias: BLDCFG_DIMM_SENSOR_CONFIGURATION
#define APCB_TOKEN_UID_DIMMSENSORCONF_VALUE                                    0x408

//Alias: BLDCFG_DIMM_SENSOR_UPPER
#define APCB_TOKEN_UID_DIMMSENSORUPPER_VALUE                                   80

//Alias: BLDCFG_3DS_DIMM_SENSOR_UPPER
#define APCB_TOKEN_UID_3DSDIMMSENSORUPPER_VALUE                                66

//Alias: BLDCFG_DIMM_SENSOR_LOWER
#define APCB_TOKEN_UID_DIMMSENSORLOWER_VALUE                                   10

//Alias: BLDCFG_DIMM_SENSOR_CRITICAL
#define APCB_TOKEN_UID_DIMMSENSORCRITICAL_VALUE                                95

//Alias: BLDCFG_3DS_DIMM_SENSOR_CRITICAL
#define APCB_TOKEN_UID_3DSDIMMSENSORCRITICAL_VALUE                            80

//Alias: BLDCFG_DIMM_SENSOR_RESOLUTION
#define APCB_TOKEN_UID_DIMMSENSORRESOLUTION_VALUE                              1

//Alias: BLDCFG_AUTO_REF_FINE_GRAN_MODE
#define APCB_TOKEN_UID_AUTOREFFINEGRANMODE_VALUE                               0

//Alias: BLDCFG_ENABLE_MEMPSTATE
#define APCB_TOKEN_UID_ENABLEMEMPSTATE_VALUE                                   FALSE

//Alias: BLDCFG_ENABLE_DDRROUTEBALANCEDTEE
#define APCB_TOKEN_UID_DDRROUTEBALANCEDTEE_VALUE                               FALSE

//Alias: BLDCFG_MEM_DATA_POISON
#define APCB_TOKEN_UID_MEM_DATA_POISON_VALUE                                   TRUE

//Alias: BLDCFG_MEM_DATA_SCRAMBLE
#define APCB_TOKEN_UID_MEM_DATA_SCRAMBLE_VALUE                                 TRUE

//
// MBIST Items
// MBIST SubTestType: 0-BInterface Mode, 1 - Data Eye
//


//Alias: BLDCFG_MEM_MBIST_HALT_ON_ERROR
#define APCB_TOKEN_UID_MEM_MBIST_HALT_ON_ERROR_VALUE                           TRUE

//Alias: BLDCFG_MEM_MBIST_CPU_VREF_RANGE
#define APCB_TOKEN_UID_MEM_CPU_VREF_RANGE_VALUE                                0

//Alias: BLDCFG_MEM_MBIST_DRAM_VREF_RANGE
#define APCB_TOKEN_UID_MEM_DRAM_VREF_RANGE_VALUE                               0

//Alias: BLDCFG_MEM_MBIST_AGGR_STATIC_LANE_CTRL
#define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_CTRL_VALUE                   0

//Alias: BLDCFG_MEM_MBIST_AGGR_STATIC_LANE_SEL_U32
#define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_U32_VALUE                0  // 32 bit DQ Lane mask Uppoer 32

//Alias: BLDCFG_MEM_MBIST_AGGR_STATIC_LANE_SEL_L32
#define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_L32_VALUE                0  // 32 bit DQ Lane mask Lower 32

//Alias: BLDCFG_MEM_MBIST_AGGR_STATIC_LANE_SEL_ECC
#define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_ECC_VALUE                0  // 8 bit ECC Lane mask

//Alias: BLDCFG_MEM_MBIST_AGGR_STATIC_LANE_VAL
#define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_VAL_VALUE                    0  // Pattern 0 or 1

//Alias: BLDCFG_MEM_MBIST_TGT_STATIC_LANE_CTRL
#define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_CTRL_VALUE                    0

//Alias: BLDCFG_MEM_MBIST_TGT_STATIC_LANE_SEL_U32
#define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_U32_VALUE                 0  // 32 bit DQ Lane mask Upper 32

//Alias: BLDCFG_MEM_MBIST_TGT_STATIC_LANE_SEL_L32
#define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_L32_VALUE                 0  // 32 bit DQ Lane mask Lower 32

//Alias: BLDCFG_MEM_MBIST_TGT_STATIC_LANE_SEL_ECC
#define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_ECC_VALUE                 0  // Target ECC Lane Mask - 8 bit

//Alias: BLDCFG_MEM_MBIST_TGT_STATIC_LANE_VAL
#define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_VAL_VALUE                     0  // Pattern 0 or 1

//Alias: BLDCFG_MEM_MBIST_DATA_EYE_TYPE
#define APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_TYPE_VALUE                           1  //  Data Eye type
                                                                                  // 0 - 1D Voltage Sweep
                                                                                  // 1 - 1D Timing Sweep
                                                                                  // 2 - 2D Full Data Eye
                                                                                  // 3 - Worst Case Margin Only

//Alias: BLDCFG_MEM_MBIST_WORST_CASE_GRAN
#define APCB_TOKEN_UID_MEM_MBIST_WORST_CASE_GRAN_VALUE                         0  // Worst Case Granularity.
                                                                                  // 0 - Per Chipselect
                                                                                  // 1 - Per Nibble

//Alias: BLDCFG_MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP
#define APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP_VALUE              1  // Voltage Step, Options 1, 2 and 4

//Alias: BLDCFG_MEM_MBIST_READ_DATA_EYE_TIMING_STEP
#define APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_TIMING_STEP_VALUE               1  // Timing Step, Options 1, 2 and 4

//Alias: BLDCFG_MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP
#define APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP_VALUE             1  // Voltage Step, Options 1, 2 and 4

//Alias: BLDCFG_MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP
#define APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP_VALUE              1  // Timing Step, Options 1, 2 and 4

//Alias: BLDCFG_MEM_MBIST_DATA_EYE_EXECUTION_REPEAT_COUNT_VALUE       1
#define APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_EXECUTION_REPEAT_COUNT_VALUE         1

//Alias: BLDCFG_BOOT_TIME_POST_PACKAGE_REPAIR_ENABLE
#define APCB_TOKEN_UID_BOOT_TIME_POST_PACKAGE_REPAIR_ENABLE_VALUE              FALSE  //< Enable/Disable Boot Time Post Package Repair

//Alias: BLDCFG_MEM_TSME_ENABLE
#define APCB_TOKEN_UID_MEM_TSME_ENABLE_DDR_VALUE                               FALSE

//Alias: BLDCFG_SME_MK_ENABLE
#define APCB_TOKEN_UID_SME_MK_ENABLE_VALUE                                     FALSE

#define APCB_TOKEN_UID_MEM_OVERCLOCK_FAIL_CNT_VALUE                            0

//
// CCX specific settings
//
//Alias: BLDCFG_CCX_MIN_SEV_ASID
#define APCB_TOKEN_UID_CCX_MIN_SEV_ASID_VALUE                                  1

//Alias: BLDCFG_CPU_FETCH_FROM_SPI_AP_BASE
#define APCB_TOKEN_UID_CPU_FETCH_FROM_SPI_AP_BASE_VALUE                        0xFFF00000
//
// PSP Debug Mode settings
//
//Alias: BLDCFG_PSP_ENABLE_DEBUG_MODE
#define APCB_TOKEN_UID_PSP_ENABLE_DEBUG_MODE_VALUE                             0

//Alias: BLDCFG_PSP_SYSHUB_WDT_INTERVAL
#define APCB_TOKEN_UID_PSP_SYSHUB_WDT_INTERVAL_VALUE                           2600

//Alias: BLDCFG_PSP_PSB_AUTO_FUSE
#define APCB_TOKEN_UID_PSP_PSB_AUTO_FUSE_VALUE                                 TRUE

//Alias: BLDCFG_PSP_SEV_DISABLE
#define APCB_TOKEN_UID_PSP_SEV_DISABLE_VALUE                                   FALSE

#define APCB_TOKEN_UID_APIC_MODE_VALUE                                         APIC_MODE_AUTO

#define APCB_TOKEN_UID_IOMMU_VALUE                                             TRUE

//
// DF specific settings
//
//Alias: BLDCFG_DF_GMI_ENCRYPT
#define APCB_TOKEN_UID_DF_GMI_ENCRYPT_VALUE                                    ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF_XGMI_ENCRYPT
#define APCB_TOKEN_UID_DF_XGMI_ENCRYPT_VALUE                                   ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF_SAVE_RESTORE_MEM_ENCRYPT
#define APCB_TOKEN_UID_DF_SAVE_RESTORE_MEM_ENCRYPT_VALUE                       ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF_SYS_STORAGE_AT_TOM
#define APCB_TOKEN_UID_DF_SYS_STORAGE_AT_TOP_OF_MEM_VALUE                      DF_SYS_STORAGE_AT_TOP_OF_MEM_AUTO

//Alias: BLDCFG_DF_PROBE_FILTER_ENABLE
#define APCB_TOKEN_UID_DF_PROBE_FILTER_VALUE                                   ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF_BOTTOM_IO
#define BLDCFG_DF_BOTTOM_IO                                                    0xB0
#define APCB_TOKEN_UID_DF_BOTTOMIO_VALUE                                       0xB0

//Alias: BLDCFG_DF_MEM_INTERLEAVING
#define APCB_TOKEN_UID_DF_MEM_INTERLEAVING_VALUE                               DF_MEM_INTLV_AUTO

//Alias: BLDCFG_DF_DRAM_INTLV_SIZE
#define APCB_TOKEN_UID_DF_MEM_INTERLEAVING_SIZE_VALUE                          DF_MEM_INTLV_SIZE_AUTO

#ifndef APCB_TOKEN_UID_DF_CXL_MEM_INTERLEAVING_VALUE
  #define APCB_TOKEN_UID_DF_CXL_MEM_INTERLEAVING_VALUE                         BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL_AUTO
#endif
#ifndef APCB_TOKEN_UID_DF_CXL_SUBLINK_INTERLEAVING_VALUE
  #define APCB_TOKEN_UID_DF_CXL_SUBLINK_INTERLEAVING_VALUE                     BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL_AUTO
#endif

//Alias: BLDCFG_DF_CHAN_INTLV_HASH_EN
#define APCB_TOKEN_UID_DF_CHAN_INTLV_HASH_VALUE                                ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF_PCI_MMIO_SIZE
#ifndef APCB_TOKEN_UID_DF_PCI_MMIO_SIZE_VALUE
#define APCB_TOKEN_UID_DF_PCI_MMIO_SIZE_VALUE                                  0x10000000
#endif

// Must match platform PCI Express Base Address setting. (e.g. PcdPciExpressBaseAddress)
#ifndef APCB_TOKEN_UID_DF_PCI_MMIO_BASE_VALUE
#define APCB_TOKEN_UID_DF_PCI_MMIO_BASE_VALUE                                  0xE0000000
#endif
#ifndef APCB_TOKEN_UID_DF_PCI_MMIO_HI_BASE_VALUE
#define APCB_TOKEN_UID_DF_PCI_MMIO_HI_BASE_VALUE                               0x0
#endif

//Alias: BLDCFG_DF_CAKE_CRC_THRESH_PERF_BOUNDS
#define APCB_TOKEN_UID_DF_CAKE_CRC_THRESH_PERF_BOUNDS_VALUE                    100  // 0.001%

//Alias: BLDCFG_DF_MEM_CLEAR
#define APCB_TOKEN_UID_DF_MEM_CLEAR_VALUE                                      ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF3_XGMI2_LINK_CFG
#define APCB_TOKEN_UID_DF3_XGMI2_LINK_CFG_VALUE                                DF_XGMI_LINK_CFG_AUTO

//Alias: BLDCFG_DF_DRAM_NPS
#define APCB_TOKEN_UID_DF_DRAM_NPS_VALUE                                       DF_DRAM_NPS_AUTO

//Alias: BLDCFG_DF_INVERT_DRAM_MAP
#define APCB_TOKEN_UID_DF_INVERT_DRAM_MAP_VALUE                                ENABLE_DISABLE_AUTO_OPTION_AUTO

//Alias: BLDCFG_DF_4LINK_MAX_XGMI_SPEED
#define APCB_TOKEN_UID_DF_4LINK_MAX_XGMI_SPEED_VALUE                           DF_XGMI_LINK_SPEED_AUTO

//Alias: BLDCFG_DF_3LINK_MAX_XGMI_SPEED
#define APCB_TOKEN_UID_DF_3LINK_MAX_XGMI_SPEED_VALUE                           DF_XGMI_LINK_SPEED_AUTO

#define APCB_TOKEN_UID_DF_2LINK_MAX_XGMI_SPEED_VALUE                           DF_XGMI_LINK_SPEED_AUTO

//Alias: BLDCFG_DF_REMAP_AT_1TB
#define APCB_TOKEN_UID_DF_REMAP_AT_1TB_VALUE                                   DF_REMAP_AT_1TB_AUTO

// Select xGMI TXEQ Mode
#define APCB_TOKEN_UID_DF_XGMI_TXEQ_MODE_VALUE                                 DF_XGMI_TXEQ_MODE_AUTO

// Select CCD Bandwidth throttle level
#define APCB_TOKEN_UID_DF_CCD_BW_THROTTLE_LV_VALUE                             DF_CCD_BW_THROTTLE_LV_AUTO

// Select Probe Filter Organization
#define APCB_TOKEN_UID_DF_PF_ORGANIZATION_VALUE                                DF_PF_ORGANIZATION_DEDICATED

//
// GNB Specific Configurations
//
#ifndef BLDCFG_EARLY_PCIE_TRAINING
#define BLDCFG_EARLY_PCIE_TRAINING      TRUE
#endif

#define APCB_TOKEN_UID_PCIE_RESET_GPIO_PIN_SELECT_VALUE                        0xFFFFFFFF

/**
 * @details Select APML SB-TSI to 0(I3C mode) or 1(I2C mode).
 * In I3C mode, the secondary controller can support both I3C and I2C(Adaptive mode).
 */
//Alias: BLDCFG_APML_SBTSI_SECONDARY_MODE
#define APCB_TOKEN_UID_APML_SBTSI_SECONDARY_MODE_VALUE                              0

#if BLDCFG_EARLY_PCIE_TRAINING == TRUE
  //Alias: BLDCFG_BMC_SOCKET_INFO
  #define APCB_TOKEN_UID_BMC_SOCKET_NUMBER_VALUE                                0x00
  #ifndef APCB_TOKEN_UID_BMC_START_LANE_VALUE
    //Alias: BLDCFG_BMC_START_LANE
    #define APCB_TOKEN_UID_BMC_START_LANE_VALUE                                 134
  #endif
  #ifndef APCB_TOKEN_UID_BMC_END_LANE_VALUE
    //Alias: BLDCFG_BMC_END_LANE
    #define APCB_TOKEN_UID_BMC_END_LANE_VALUE                                   134
  #endif
  #ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_START_LANE_VALUE
    #define APCB_TOKEN_UID_SECOND_PCIE_LINK_START_LANE_VALUE                    135
  #endif
  #ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_END_LANE_VALUE
    #define APCB_TOKEN_UID_SECOND_PCIE_LINK_END_LANE_VALUE                      135
  #endif
#else
  //Alias: BLDCFG_BMC_SOCKET_INFO
  #define APCB_TOKEN_UID_BMC_SOCKET_NUMBER_VALUE                                0x0F

  //Alias: BLDCFG_BMC_START_LANE
  #define APCB_TOKEN_UID_BMC_START_LANE_VALUE                                   0xFF

  //Alias: BLDCFG_BMC_END_LANE
  #define APCB_TOKEN_UID_BMC_END_LANE_VALUE                                     0xFF

  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_START_LANE_VALUE                      0xFF

  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_END_LANE_VALUE                        0xFF
#endif


#ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_DEVICE_VALUE
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_DEVICE_VALUE                          5
#endif

#ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_FUNCTION_VALUE
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_FUNCTION_VALUE                        3
#endif

#ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_PORT_PRESENT_VALUE
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_PORT_PRESENT_VALUE                    0
#endif

#ifndef APCB_TOKEN_UID_THIRD_PCIE_LINK_START_LANE_VALUE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_START_LANE_VALUE                       0xFF
#endif

#ifndef APCB_TOKEN_UID_THIRD_PCIE_LINK_END_LANE_VALUE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_END_LANE_VALUE                         0xFF
#endif

#ifndef APCB_TOKEN_UID_THIRD_PCIE_LINK_SPEED_VALUE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_SPEED_VALUE                            3
#endif

#ifndef APCB_TOKEN_UID_THIRD_PCIE_LINK_DEVICE_VALUE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_DEVICE_VALUE                           5
#endif

#ifndef APCB_TOKEN_UID_THIRD_PCIE_LINK_FUNCTION_VALUE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_FUNCTION_VALUE                         1
#endif

#ifndef APCB_TOKEN_UID_THIRD_PCIE_LINK_PORT_PRESENT_VALUE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_PORT_PRESENT_VALUE                     0
#endif

#ifndef APCB_TOKEN_UID_FOURTH_PCIE_LINK_START_LANE_VALUE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_START_LANE_VALUE                      0xFF
#endif

#ifndef APCB_TOKEN_UID_FOURTH_PCIE_LINK_END_LANE_VALUE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_END_LANE_VALUE                        0xFF
#endif

#ifndef APCB_TOKEN_UID_FOURTH_PCIE_LINK_SPEED_VALUE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_SPEED_VALUE                           3
#endif

#ifndef APCB_TOKEN_UID_FOURTH_PCIE_LINK_DEVICE_VALUE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_DEVICE_VALUE                          5
#endif

#ifndef APCB_TOKEN_UID_FOURTH_PCIE_LINK_FUNCTION_VALUE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_FUNCTION_VALUE                        4
#endif

#ifndef APCB_TOKEN_UID_FOURTH_PCIE_LINK_PORT_PRESENT_VALUE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_PORT_PRESENT_VALUE                    0
#endif

//Alias: BLDCFG_BMC_BMC_DEVICE
#define APCB_TOKEN_UID_BMC_DEVICE_VALUE                                        5

//Alias: BLDCFG_BMC_FUNCTION
#define APCB_TOKEN_UID_BMC_FUNCTION_VALUE                                      2

// Select BMC Link speed 1-Gen1, 2-Gen2
#ifndef APCB_TOKEN_UID_BMC_LINK_SPEED_VALUE
  #define APCB_TOKEN_UID_BMC_LINK_SPEED_VALUE                                  3
#endif

// Select Second Pcie Link speed 1-Gen1, 2-Gen2
#ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_SPEED_VALUE
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_SPEED_VALUE                          3
#endif

// Select second PCIe Link Maximum Payload Size
#ifndef APCB_TOKEN_UID_SECOND_PCIE_LINK_MAX_PAYLOAD_VALUE
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_MAX_PAYLOAD_VALUE                    0xFF
#endif

/// Select RCB checks incorrect attributes 0-Enable, 1-Disable, 0xFF-Auto
#ifndef APCB_TOKEN_UID_BMC_RCB_WRONG_ATTR_DIS_VALUE
  #define APCB_TOKEN_UID_BMC_RCB_WRONG_ATTR_DIS_VALUE                          0xFF
#endif

// Select BMC Gen2 Tx DeEmphasis
  //0x0 - Use de-emphasis from CSR
  //0x1 - Use de-emphasis requested by upstream component
  //0x2 - Use -6.0 dB
  //0x3 - Use -3.5 dB
  //0xFF - Skip Override Tx DeEmphasis Setting
#ifndef APCB_TOKEN_UID_BMC_GEN2_TX_DEEMPHASIS_VALUE
  #define APCB_TOKEN_UID_BMC_GEN2_TX_DEEMPHASIS_VALUE                          0xFF
#endif

// Early init BMC before DRAM
#ifndef APCB_TOKEN_UID_BMC_INIT_BEFORE_DRAM_VALUE
  #define APCB_TOKEN_UID_BMC_INIT_BEFORE_DRAM_VALUE                            FALSE
#endif

#ifndef APCB_TOKEN_UID_ENABLE_VGA_PROGRAM_VALUE
  #define APCB_TOKEN_UID_ENABLE_VGA_PROGRAM_VALUE                              TRUE
#endif

// Select Enable second PCIe link
#ifndef APCB_TOKEN_UID_CONFIGURE_SECOND_PCIE_LINK_VALUE
  #define APCB_TOKEN_UID_CONFIGURE_SECOND_PCIE_LINK_VALUE                      FALSE
#endif

// Select Enable BMC Legacy VGA IO Port
#ifndef APCB_TOKEN_UID_BMC_LEGACY_IO_ENABLE_VALUE
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_ENABLE_VALUE                            FALSE
#endif

// BMC Legacy VGA IO Port Number
#ifndef APCB_TOKEN_UID_BMC_LEGACY_IO_PORT_VALUE
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_PORT_VALUE                              0
#endif

// BMC Legacy VGA IO Port Range
#ifndef APCB_TOKEN_UID_BMC_LEGACY_IO_PORT_SIZE_VALUE
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_PORT_SIZE_VALUE                         0
#endif

// Replace Re-locatable I/O Space BAR address by Legacy VGA IO Port
#ifndef APCB_TOKEN_UID_BMC_LEGACY_IO_BAR_REPLACE_VALUE
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_BAR_REPLACE_VALUE                       0
#endif

// Enables control of PCIe reset as GPIO26
// If PCIe reset (GPIO26) is used for PCIe slot reset, this should be set to TRUE
//Alias: BLDCFG_PCIE_RESET_CONTROL
#define APCB_TOKEN_UID_PCIE_RESET_CONTROL_VALUE                                TRUE

// Pcie reset pin select 0:disable 1:GPIO26 2:GPIO266 3:GPIO267 4:GPIO27
#ifndef APCB_TOKEN_UID_PCIE_RESET_PIN_SELECT_VALUE
//Alias: BLDCFG_PCIE_RESET_PIN_SELECT
  #define APCB_TOKEN_UID_PCIE_RESET_PIN_SELECT_VALUE                             2
#endif

// Group D platform selection
#ifndef APCB_TOKEN_UID_GROUP_D_PLATFORM_VALUE
  #define APCB_TOKEN_UID_GROUP_D_PLATFORM_VALUE                                TRUE
#endif

#ifndef APCB_TOKEN_UID_CCX_PPIN_OPT_IN_VALUE
  #define APCB_TOKEN_UID_CCX_PPIN_OPT_IN_VALUE                                 FALSE
#endif

/**
 * @brief UART Enable Disable through SOC UART/ eSPI-SUPER IO for ABL log
 * 0 - Disable ConsoleOut Function for ABL, 1 - Enable ConsoleOut Function for ABL,  2 - AUTO Keep defualt behavior
 */
//Alias: BLDCFG_FCH_CONSOLE_OUT_ENABLE
#ifndef APCB_TOKEN_UID_FCH_CONSOLE_OUT_ENABLE_VALUE
#define APCB_TOKEN_UID_FCH_CONSOLE_OUT_ENABLE_VALUE                            0
#endif

/**
 * @brief ABL Serial Console Out Port Info
 * 0:LPC/eSPI Super IO, 1:SOC UART0, 2:SOC UART1
 */
//Alias: BLDCFG_FCH_CONSOLE_OUT_SERIAL_PORT
#ifndef APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE                     1
#endif


#ifndef APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_IO_VALUE
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_IO_VALUE                     0
#endif


//BIT0:  Select which eSPI controller has epsi uart for ABL console out  0: eSPI controller 0  1: eSPI controller 1
//BIT3   Disable or enable 2E/2F IO on the selected eSPI controller      0: 2E/2F Enabled      1: 2E/2F Disabled.
//BIT4   Disable or enable 4E/4F IO on the selected eSPI controller      0: 4E/4F Enabled      1: 4E/4F Disabled.
#ifdef SERIAL_PORT_ESPI_CONTROLLER_VALUE
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_ESPI_CONTROLLER_VALUE        SERIAL_PORT_ESPI_CONTROLLER_VALUE
#endif

/**
 * @brief The following field is applicable only if APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_VALUE
 * is set to 0 for eSPI SuperIO.
 * 1 - Aspeed, 2 - Pilot4
 */
#ifndef APCB_TOKEN_UID_FCH_CONSOLE_OUT_SUPER_IO_TYPE_VALUE
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SUPER_IO_TYPE_VALUE                   FCH_CONSOLE_OUT_SUPER_IO_TYPE_DEFAULT
#endif

/**
 * @brief ABL Serial Console Out Port Info
 * 0:LPC Super IO 1:UART0 2:UART1
 */
//Alias: BLDCFG_FCH_CONSOLE_OUT_BASIC_ENABLE
#ifndef APCB_TOKEN_UID_FCH_CONSOLE_OUT_BASIC_ENABLE_VALUE
#define APCB_TOKEN_UID_FCH_CONSOLE_OUT_BASIC_ENABLE_VALUE                      0
#endif

//Alias: BLDCFG_MEM_POPULATION_MSG_CTRL
#ifndef APCB_TOKEN_UID_MEM_POPULATION_MSG_CTRL_VALUE
  #define APCB_TOKEN_UID_MEM_POPULATION_MSG_CTRL_VALUE                         0
#endif

/**
 * @brief This token represents bit 63:32 of BAR_64MB_ROM3_High.
 * If set to 0, this will pick up the reset default into this register.
 */
//Alias: APCB_TOKEN_UID_FCH_ROM3_BASE_HIGH
#define APCB_TOKEN_UID_FCH_ROM3_BASE_HIGH_VALUE                                0

#ifndef APCB_TOKEN_UID_DXIO_VGA_API_ENABLE_VALUE
  #define APCB_TOKEN_UID_DXIO_VGA_API_ENABLE_VALUE                              FALSE      //default
#endif

#ifndef APCB_TOKEN_UID_DXIO_PHY_PARAM_VGA_VALUE
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_VGA_VALUE                               0xFFFFFFFF  //defalut, indicating SKIP adjustment
#endif

#ifndef APCB_TOKEN_UID_DXIO_PHY_PARAM_POLE_VALUE
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_POLE_VALUE                              0xFFFFFFFF //defalut, indicating SKIP adjustment
#endif

#ifndef APCB_TOKEN_UID_DXIO_PHY_PARAM_DC_VALUE
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_DC_VALUE                                0xFFFFFFFF //defalut, indicating SKIP adjustment
#endif

#ifndef APCB_TOKEN_UID_DXIO_PHY_PARAM_IQOFC_VALUE
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_IQOFC_VALUE                             0x7FFFFFFF //defalut, indicating SKIP adjustment
#endif

// Select Addition Feature Config
#ifndef APCB_TOKEN_UID_GNB_ADDI_FEAT_CFG_VALUE
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_CFG_VALUE                                TRUE
#endif

// Select Addition Feature Config DSM
#ifndef APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM_VALUE
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM_VALUE                                FALSE
#endif

// Select Addition Feature Config DSM Detector
#ifndef APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM_DETECTOR_VALUE
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM_DETECTOR_VALUE                       FALSE
#endif

// Select Addition Feature Config L3 Perf Bias
#ifndef APCB_TOKEN_UID_GNB_ADDI_FEAT_L3_PERF_BIAS_VALUE
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_L3_PERF_BIAS_VALUE                       TRUE
#endif

// Program SDXI Class Code
#ifndef APCB_TOKEN_UID_PROG_SDXI_CLASS_CODE_VALUE
  #define APCB_TOKEN_UID_PROG_SDXI_CLASS_CODE_VALUE                             0x0
#endif

// =================================================================================================
// APCB Type Data Structure Member Customization
// =================================================================================================

//
// MEM Platform Specific Overrides
//
#ifndef NUMBER_OF_CHANNEL_PER_SOCKET
  #define NUMBER_OF_CHANNEL_PER_SOCKET  12
#endif

#ifndef NUMBER_OF_DIMMS_PER_CHANNEL
  #define NUMBER_OF_DIMMS_PER_CHANNEL   1
#endif

/**
 * @details Declare how many memory channel at specific CPU
 * socket.
 */
#define BLDCFG_NUM_CHNL_SUPPORTED     NUMBER_OF_CHANNELS_SUPPORTED(ANY_SOCKET, NUMBER_OF_CHANNEL_PER_SOCKET),                     // NumberChannelsSupported

/**
 * @details Declare how many memory DIMM slot at specific CPU
 * socket and channel on the board. Can define multiple
 * instances with different name while the DIMM/channel is not a
 * constant on the board design.
 */
#define BLDCFG_NUM_DIMMS_SUPPORTED    NUMBER_OF_DIMMS_SUPPORTED(ANY_SOCKET, ANY_CHANNEL, NUMBER_OF_DIMMS_PER_CHANNEL),            // NumberDimmSupported

/**
 * @details Declare how many memory DIMM slot at specific CPU socket
 * and channel on the default Genoa board with twelve memory channels.
 * Can define multiple instances with different name while the DIMM/channel
 * is not constant on the board design.
 */
#define BLDCFG_NUM_DIMMS_SUPPORTED_12_CHANNEL    NUMBER_OF_DIMMS_SUPPORTED_12_CHANNEL(ANY_SOCKET, ANY_CHANNEL, \
                                                   (CHANNEL_I + CHANNEL_J + CHANNEL_K + CHANNEL_L), NUMBER_OF_DIMMS_PER_CHANNEL),            // NumberDimmSupported

#define BLDCFG_NUM_DIMMS_SUPPORTED_12_CHANNEL_SP6 NUMBER_OF_DIMMS_SUPPORTED_12_CHANNEL(ANY_SOCKET, (CHANNEL_A + CHANNEL_B + CHANNEL_D), \
                                                   (CHANNEL_E + CHANNEL_F + CHANNEL_H), NUMBER_OF_DIMMS_PER_CHANNEL),
#endif   //ifndef  _APCB_CUSTOMIZED_DEFINITIONS_H_


