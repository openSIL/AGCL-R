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
  APCB_TYPE_TOKEN_1BYTE,      // TypeId
  sizeof(ApcbTypeHeader),        // SizeOfType, will be fixed up by tool
  0,                             // InstanceId
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


APCB_TOKEN_PAIR_UINT8 TokeList[] = {
// Two macros can be used for token definitions
//  APCB_TOKEN_U8 (APCB_TOKEN_UID_NAME, APCB_TOKEN_UID_NAME_VALUE),
//  APCB_TOKEN_VAL_U8(APCB_TOKEN_UID_NAME), // Expand to use APCB_TOKEN_UID_NAME_VALUE

APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_PSP_ENABLE_DEBUG_MODE),                         //< ENABLE_DEBUG_MODE
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_GMI_ENCRYPT),                                //< GMI encryption
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_XGMI_ENCRYPT),                               //< xGMI encryption
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_SAVE_RESTORE_MEM_ENCRYPT),                   //< Save/Restore memory encryption
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_PROBE_FILTER),                               //< SPF
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_BOTTOMIO),                                   //< Bottom IO
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_MEM_INTERLEAVING),                           //< Channel, Die, Socket interleaving control
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_CXL_MEM_INTERLEAVING),                       //< CXL interleaving control
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_CXL_SUBLINK_INTERLEAVING),                   //< CXL sublink interleaving control
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF3_XGMI2_LINK_CFG),                            //< Specify the number of xGMI links connected to the other socket
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_DRAM_NPS),                                   //< Nodes per socket
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_INVERT_DRAM_MAP),                            //< Low addresses go to lowest numbered memory channels or highest numbered memory channels
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_2LINK_MAX_XGMI_SPEED),                       //< 2-Link max xGMI speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_4LINK_MAX_XGMI_SPEED),                       //< 4-Link max xGMI speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_3LINK_MAX_XGMI_SPEED),                       //< 3-Link max xGMI speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_REMAP_AT_1TB),                               //< Attempt to remap the memory just below the 1TB boundary
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_PMUTRAINMODE),                                  //< PmuTrainMode - PMU Training Mode
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DIMMSENSORRESOLUTION),                          //< DIMM temperature sensor register index BSU16 (8), Temperature resolution register
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_AUTOREFFINEGRANMODE),                           //< UMC::CH::SpazCtrl_AutoRefFineGranMode
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_EN_DDR),                              //< MBIST Test Enable/Disable
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_TESTMODE_DDR),                        //< MBIST SubTest Type
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_AGGRESSORS_DDR),                      //< Aggressor Enable/Disable
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_HALT_ON_ERROR),                       //< Halt on Error in case MBIST Test failed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_CPU_VREF_RANGE),                            //< CPU Vref margins in percent (%)
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_DRAM_VREF_RANGE),                           //< DRAM Vref margins in percent (%)
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_DATA_POISON),                               //< Data Poison enabling 1: Enabled, 0: Disabled
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_DATA_SCRAMBLE),                             //< Data Scramble enabling 1: Enabled, 0: Disabled
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_PS_ERROR_HANDLING),                         //< Platform specific error handling
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_PER_BIT_SECONDARY_DIE_REPORT_DDR),    //< MBIST per bit secondary die report
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_AGGRESSORS_CHNL_DDR),                 //< Enable Read Aggressor Channels
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_PATTERN_LENGTH_DDR),                  //< Read Pattern Length
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_PATTERN_SELECT_DDR),                  //< Read Pattern Select
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_ECC),            //< Aggressor ECC Lanes Mask
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_VAL),                //< Aggressor DQ Lanes value, set as 0 or 1
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_ECC),             //< Target ECC Lanes Mask
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_VAL),                 //< Target DQ Lanes value set as 0 or 1
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_TYPE),                       //< Read Data Type
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_WORST_CASE_GRAN),                     //< Read Data Eye worst case margins, per cs or per nibble
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP),          //< Read Data Eye Voltage Step i.e. 1,2 and 4
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_TIMING_STEP),           //< Read Data Eye Timing Step  i.e. 1, 2 and 4
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP),         //< Write Data Eye Voltage Step i.e. 1,2 and 4
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP),          //< Write Data Eye Timing Step i.e. 1,2 and 4
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_EXECUTION_REPEAT_COUNT),     //< Data Eye Execution Repeat Count.
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_HEALING_BIST_ENABLE_BITMASK_DDR),           //< DDR Healing BIST Test Selection
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_HEALING_BIST_REPAIR_TYPE_DDR),              //< DDR Healing BIST Post Package Repair Type Selection
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_HEALING_BIST_MAX_BANK_FAILS_DDR),           //< DDR Healing BIST Max fails per bank
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_SOCKET_NUMBER),                             //< BMC SOcket Number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_START_LANE),                                //< BMC Start Lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_END_LANE),                                  //< BMC End Lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_DEVICE),                                    //< BMC Device Number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_FUNCTION),                                  //< BMC Function Number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_LINK_SPEED),                                //< BMC Link Speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_GEN2_TX_DEEMPHASIS),                        //< BMC De-Emphasis
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_START_LANE),                   //< Early training - Second PCIe link start lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_END_LANE),                     //< Early training - Second PCIe link end lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_SPEED),                        //< Early training - Second PCIe link speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_MAX_PAYLOAD),                  //< Early training - Second PCIe link max payload
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_DEVICE),                       //< Early training - Second PCIe link device number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_FUNCTION),                     //< Early training - Second PCIe link function number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_SECOND_PCIE_LINK_PORT_PRESENT),                 //< Early training - Second PCIe link port present value - set to 0 train in PEI
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_THIRD_PCIE_LINK_START_LANE),                    //< Early training - Third PCIe link start lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_THIRD_PCIE_LINK_END_LANE),                      //< Early training - Third PCIe link end lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_THIRD_PCIE_LINK_SPEED),                         //< Early training - Third PCIe link speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_THIRD_PCIE_LINK_DEVICE),                        //< Early training - Third PCIe link device number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_THIRD_PCIE_LINK_FUNCTION),                      //< Early training - Third PCIe link function number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_THIRD_PCIE_LINK_PORT_PRESENT),                  //< Early training - Third PCIe link port present value - set to 0 train in PEI
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FOURTH_PCIE_LINK_START_LANE),                   //< Early training - Fourth PCIe link start lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FOURTH_PCIE_LINK_END_LANE),                     //< Early training - Fourth PCIe link end lane
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FOURTH_PCIE_LINK_SPEED),                        //< Early training - Fourth PCIe link speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FOURTH_PCIE_LINK_DEVICE),                       //< Early training - Fourth PCIe link device number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FOURTH_PCIE_LINK_FUNCTION),                     //< Early training - Fourth PCIe link function number
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FOURTH_PCIE_LINK_PORT_PRESENT),                 //< Early training - Fourth PCIe link port present value - set to 0 train in PEI
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_CONSOLE_OUT_ENABLE),                        //< ABL log enabling on a given UART port
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT),                   //< UART Port Used for ABL log
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_CONSOLE_OUT_SUPER_IO_TYPE),                 //< SuperIO UART type if UART Port is SuperIO
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_CONSOLE_OUT_BASIC_ENABLE),                  //< ABL Console Out Basic Enabling
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_PCIE_RESET_PIN_SELECT),                         //< PCIE Reset Pin Select
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_ABL_SERIAL_BAUD_RATE),                          //< ABL Serial Baud Rate
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_SMBUS_SPEED),                               //< FCH Smbus speed
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_TRAINING_HDTCTRL),                          //< Memory training MsgBlock->HdtCtrl
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_PSTATE_MODE_SELECT),                         //< DF PState mode select
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_ACTION_ON_BIST_FAILURE),                        //< Action on BIST failure
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BMC_RCB_WRONG_ATTR_DIS),                        //< BMC RCB Wrong Attr Disable
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_SUBURGREFLOWERBOUND),                       //< UMC::CH::SpazCtrl [10:8] SubUrgRefLowerBound
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_URGREFLIMIT),                               //< UMC::CH::SpazCtrl [6:4] UrgRefLimit
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DRAMDOUBLEREFRESHRATE),                         //< DramDoubleRefreshRate - PMU Training Mode
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_SELF_REFRESH_EXIT_STAGGERING),              //< Tcksrx += (Trfc/n * (UMC_Number % 4))), n = 0, 3 or 4
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_WORKLOAD_PROFILE),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_CONFIG_XGMI_CRC_SCALE),                         //< DF XGMI CRB Scale
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_CONFIG_XGMI_CRC_THRESHOLD),                     //< DF XGMI CRB Threshold
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_RESERVED_DRAM_MODULE_DRTM),                     //< DRESERVED_DRAM_MODULE_DRTM
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_BOOT_TIME_POST_PACKAGE_REPAIR_ENABLE),          //< Enable/Disable Boot Time Post Package Repair
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_APML_SBTSI_SECONDARY_MODE),                     //< APML SBTSI SECONDARY MODE, 0 - i3c; 1 - i2c
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_IC_SDA_HOLD_OVERRIDE),                      //< Enable the override of I2C controller IC_SDA_TX_HOLD or IC_SDA_RX_HOLD
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_IC_SDA_RX_HOLD),                            //< I2C IC_SDA_RX_HOLD time
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2C_I3C_SMBUS_0),                               //< Select FCH I2C/I3C/Smbus controller 0 working mode
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2C_I3C_SMBUS_1),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2C_I3C_SMBUS_2),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2C_I3C_SMBUS_3),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2C_I3C_SMBUS_4),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2C_I3C_SMBUS_5),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2CI3C_CONTROLLER0),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2CI3C_CONTROLLER1),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2CI3C_CONTROLLER2),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2CI3C_CONTROLLER3),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2CI3C_CONTROLLER4),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_I2CI3C_CONTROLLER5),
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_I3C_SDA_HOLD_SWITCH_DLY_TIMING),            //< I3C APCB_TOKEN_UID_FCH_I3C_SDA_HOLD_SWITCH_DLY_TIMING
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_XGMI_PRESET_CONTROL),                        //< APCB_TOKEN_UID_DF_XGMI_PRESET_CONTROL
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_XGMI_AC_DC_COUPLED_LINK),                       //< APCB_TOKEN_UID_XGMI_AC_DC_COUPLED_LINK
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_SYS_STORAGE_AT_TOP_OF_MEM),                  //< Controls location of private memory regions
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_POPULATION_MSG_CTRL),                       //< ABL Memory Population message Control
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_I3C_TRANSFER_SPEED),
#ifdef SERIAL_PORT_ESPI_CONTROLLER_VALUE
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_ESPI_CONTROLLER),   //< UART Port espi base and 2E/2F, 4E/4F Used for ABL log
#endif
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_IO),                //< Select Legacy Uart (SIO or eSPI) IO base
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_NBIO_SATA_MODE),                                //< Select the operational mode for the SATA controller
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_ODTSEN),                                        //< UMC::CH::ThrottleCtrl [27] OdtsEn
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_ODTSCMDTHROTEN),                                //< UMC::CH::ThrottleCtrl[OdtsCmdThrotEn]
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_ECSFEATURE_DDR),                            //< ECSFEATURE_DDR
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_DATA_POISONING_DDR),                        //< DATA_POISONING_DDR
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_SPD_VERIFY_CRC),                            //< DIMM SPD CRC verify
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_CCD_BW_THROTTLE_LV),                         //< Controls CCD Bandwidth Balance Throttle Level
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_APIC_MODE),                                     //< Specify APIC mode (see gEfiAmdAgesaModulePkgTokenSpaceGuid.PcdAmdApicMode)
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_MEM_DISPLAY_PMU_TRAINING_RESULT),               //< Dilslay or hide PMU training results to console
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_DF_PF_ORGANIZATION),                            //< APCB_TOKEN_UID_DF_PF_ORGANIZATION
APCB_TOKEN_VAL_U8 (APCB_TOKEN_UID_PROG_SDXI_CLASS_CODE),                          //< Program SDXI Class Code
};


APCB_TYPE_DATA_END_SIGNATURE();
APCB_DUMMY_MAIN_FUNC();

