/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_V3_TOKEN_UID_H_
#define _APCB_V3_TOKEN_UID_H_
//
// @APCB_START
//

//
// @APCB_TOKEN
//

/**
 *  @defgroup NBIO
 *  NBIO APCB Tokens
*/

/**
 *  @defgroup CCX
 *  CCX APCB Tokens
*/

/**
 *  @defgroup FCH
 *  FCH APCB Tokens
*/

/**
 *  @defgroup PSP
 *  PSP APCB Tokens
*/

/**
 *  @defgroup DF
 *  DF APCB Tokens
*/

/**
 *  @defgroup Memory
 *  Memory APCB Tokens
*/

/**
 *  @defgroup Miscellaneous
 *  Miscellaneous APCB Tokens
*/

// =================================================================================================
// CBS CMN APCB Tokens (BOOLEAN)
// -------------------------------------------------------------------------------------------------
/** BOOLEAN_TRUE_FALSE_VALIDVAL
*   Value range for boolean type with True and False usage
*/
typedef enum {
  _FALSE = 0,      ///< False
  _TRUE = 1,       ///< True
} BOOLEAN_TRUE_FALSE_VALIDVAL;

/** BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
*   Value range for boolean type with Enable and Disable usage
*/
typedef enum {
  BOOLEAN_ENABLE_1_DISABLE_0_DISABLE = 0,      ///< Disable
  BOOLEAN_ENABLE_1_DISABLE_0_ENABLE = 1,       ///< Enable
} BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL;

/** BOOLEAN_ENABLE_0_DISABLE_1_VALIDVAL
*   Value range for boolean type with Enable and Disable usage
*/
typedef enum {
  BOOLEAN_ENABLE_0_DISABLE_1_DISABLE = 1,      ///< Disable
  BOOLEAN_ENABLE_0_DISABLE_1_ENABLE = 0,       ///< Enable
} BOOLEAN_ENABLE_0_DISABLE_1_VALIDVAL;

/** BOOLEAN_DISABLE_0_AUTO_VALIDVAL
*   Value range for boolean type with Disable and Auto usage
*/
typedef enum {
  BOOLEAN_DISABLE_0_AUTO_VALIDVAL_DISABLED = 0,///<Disabled
  BOOLEAN_DISABLE_0_AUTO_VALIDVAL_AUTO = 0xFF, ///<Auto
} BOOLEAN_DISABLE_0_AUTO_VALIDVAL;

/** BOOLEAN_ENABLE_1_AUTO_VALIDVAL
*   Value range for boolean type with Enable and Auto usage
*/
typedef enum {
  BOOLEAN_ENABLE_1_AUTO_VALIDVAL_DISABLED = 0,///<Enabled
  BOOLEAN_ENABLE_1_AUTO_VALIDVAL_AUTO = 0xFF, ///<Auto
} BOOLEAN_ENABLE_1_AUTO_VALIDVAL;

/// @brief Value range for boolean type with Enable and Disable usage
/// @details Type:BOOLEAN
typedef enum {
  BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL_DISABLE = 0,      ///< Disabled
  BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL_ENABLE = 1,       ///< Enabled
  BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL_AUTO = 0xFF,      ///< Auto
} BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL;


// -------------------------------------------------------------------------------------------------
/// @GROUPID: APCB_GROUP_TOKEN
/// @TYPEID: APCB_TYPE_TOKEN_BOOLEAN
/// @DATATYPE: BOOLEAN
/// @SIZE: 1

/// @ingroup PSP
/// @brief PSP TP Port control
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_PSP_TP_PORT                                        0x0460ABE8  // bool

/// @ingroup PSP
/// @brief PSP_ERROR_DISPLAY
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_PSP_ERROR_DISPLAY                                  0xDC33FF21  // bool

/// @ingroup PSP
/// @brief PSP_EVENT_LOG_DISPLAY
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_PSP_EVENT_LOG_DISPLAY                              0x0C473E1C  // bool

/// @ingroup PSP
/// @brief PSP_STOP_ON_ERROR
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_PSP_STOP_ON_ERROR                                  0xE7024A21  // bool

/// @ingroup PSP
/// @brief This is an APCB Token that controls the action of the PSP when it detects a processor having the 'Neutral CPU' state.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li FALSE - "deferred PSB fusing" - Regardless of the BIOS PSB status, the PSP will leave the processor in the 'Neutral CPU' state.
/// @li TRUE - "PSB Auto fusing" - The PSP will check the PSB status of the BIOS and when...
/// @li BIOS is enabled for PSB, the PSP will move the processor to the 'PSB_Enabled' state.
/// @li BIOS is not instrumented for PSB, the processor will be left in 'Neutral CPU' state.
  #define APCB_TOKEN_UID_PSP_PSB_AUTO_FUSE                                  0x2FCD70C9  // bool

/// @ingroup Memory
/// @brief This options enables or disables the Memory Hole Remapping feature. DRAM memory is contiguous from 0 through 4GB or more; however, for PCI compatibili
/// ty, a 'hole' is created just under the 4GB address mark to allow 32-bit address devices to locate their MMIO region for register access. The actual DR
/// AM memory 'under' this hole will be lost. The remapping feature recovers this memory by making it accessible at high addresses beyond the end of physi
/// cal memory. This feature is most valuable to system with smaller amounts of DRAM. See also the Bottom IO setting.
/// @brief Permitted Choices: (Type: List)(Default: Enable)
/// @li Enable - Memory under the PCI MMIO 'hole' is Remapped to high addresses.
/// @li Disable - Memory under the PCI MMIO 'hole' is lost.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_MEMHOLEREMAPPING                                   0x6A133AC5  // bool

/// @ingroup Memory
/// @brief LIMITMEMORYTOBELOW1TB
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_LIMITMEMORYTOBELOW1TB                              0x5E71E6D8  // bool

/// @ingroup Memory
/// @brief Specifies if the system should use Chip Select. This feature will spread memory accesses across the ranks of memory within a channel.
/// @brief Permitted Choices: (Type: List)(Default: Enabled)
/// @li Enabled - This option is active
/// @li Disabled - This option is turned off
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_ENABLECHIPSELECTINTLV                              0x6F81A115  // bool

/// @ingroup Memory
/// @brief ENABLECHANNELINTLV
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ENABLECHANNELINTLV                                 0x48254F73  // bool

/// @brief This turns on the correction action and enables the ability of the MCA subsystem to report errors. It does not activate the MCA error report interrupt
/// s.
/// @brief Permitted Choices: (Type: Boolean)(Default: Enabled)
/// @li Enabled - This option is active
/// @li Disabled - This option is turned off
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_ENABLEECCFEATURE                                   0xFA35F040  // bool

/// @ingroup Memory
/// @brief ENABLEPOWERDOWN
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ENABLEPOWERDOWN                                    0xBBB185A2  // bool

/// @brief ENABLEPARITY
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ENABLEPARITY                                       0x3CB8CBD2  // bool

/// @ingroup Memory
/// @brief ENABLEBANKSWIZZLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ENABLEBANKSWIZZLE                                  0x6414D160  // bool

/// @ingroup Memory
/// @brief ENABLEMEMCLR
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ENABLEMEMCLR                                       0xC6ACDB37  // bool

/// @ingroup Memory
/// @brief This APCB token enables the Memory Context Restoration feature.
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li TRUE - Memory context restore is enabled. PMU training is bypassed during warm boot whenever possible.
/// @li FALSE - Memory context restore is turned off. PMU training is performed each time the system boots.
  #define APCB_TOKEN_UID_MEMRESTORECTL                                      0xFEDB01F8  // bool

/// @brief ISCAPSULEMODE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ISCAPSULEMODE                                      0x96176308  // bool

/// @brief AMPENABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_AMPENABLE                                          0x592CB3CA  // bool

/// @brief ECCREDIRECTION
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ECCREDIRECTION                                     0xDEDE0E09  // bool

/// @brief ECCSYNCFLOOD
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ECCSYNCFLOOD                                       0x88BD40C2  // bool

/// @brief DQSTRAININGCONTROL
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_DQSTRAININGCONTROL                                 0x3CAAA3FA  // bool

/// @brief UMAABOVE4G
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_UMAABOVE4G                                         0x77E41D2A  // bool

/// @brief MEMORYALLCLOCKSON
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYALLCLOCKSON                                  0xB95E0555  // bool

/// @brief When the checksum of the SPD record fails, the typical action is to drop the DIMM and not attempt to configure it into the system. The software indica
/// tes via return code that this condition has occurred. Under certain conditions, the platform can decide to accept the associated risk and choose to ig
/// nore the SPD checksum.
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li TRUE - Ignore faulty SPD checksum and continue DIMM initialization
/// @li FALSE - If the checksum of an SPD is found to be invalid, then the memory initialization process is terminated for that DIMM
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_IGNORESPDCHECKSUM                                  0x7D369DBC  // bool

/// @brief MEMORYMODEUNGANGED
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYMODEUNGANGED                                 0x03CE1180  // bool

/// @brief MEMORYQUADRANKCAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYQUADRANKCAPABLE                              0xE6DFD3DC  // bool

/// @brief MEMORYRDIMMCAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYRDIMMCAPABLE                                 0x81726666  // bool

/// @brief MEMORYLRDIMMCAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYLRDIMMCAPABLE                                0x014FBF20  // bool

/// @brief MEMORYUDIMMCAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYUDIMMCAPABLE                                 0x3CF8A8EC  // bool

/// @brief MEMORYSODIMMCAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEMORYSODIMMCAPABLE                                0x7C61C187  // bool

/// @brief DIMMTYPEDDDR3CAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_DIMMTYPEDDDR3CAPABLE                               0x0789210C  // bool

/// @brief DIMMTYPELPDDDR3CAPABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_DIMMTYPELPDDDR3CAPABLE                             0xAD96AA30  // bool

/// @ingroup Memory
/// @brief Bank Swap control
/// @details Permitted Choices (Type: List) (Default: 0x1 Enabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
  #define APCB_TOKEN_UID_ENABLEBANKGROUPSWAP                                0x46920968  // bool

/// @ingroup Memory
/// @brief Enable OdtsCmdThrot based throttling
/// @details See PPR UMC::ThrottleCtrl[25] OdtsCmdThrotEn
/// @details Permitted Choices (Type: List) (Default: 0x1 Enabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
  #define APCB_TOKEN_UID_ODTSCMDTHROTEN                                     0xC0736395  // uint8

/// @brief This option enables the memory channel SW CMD Throttle feature (see PPR: SWCmdThrotEn). APCB V2 platforms use token APCB_TOKEN_CONFIG_SWCMDTHROTEN whi
/// ch is set by modifying the value of BLDCFG_SW_CMD_THROT_EN. APCB V3 platforms use APCB_TOKEN_UID_SWCMDTHROTEN which is set by midifying the value of A
/// PCB_TOKEN_UID_SWCMDTHROTEN.
/// @brief Permitted Choices: (Type: Boolean)(Default: False)
/// @li TRUE - Enabled.
/// @li FALSE - Disabled.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_SWCMDTHROTEN                                       0xA29C1CF9  // bool

/// @ingroup Memory
/// @brief This options enables Force Power Down Throttle Enable.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE -  feature is enabled.
/// @li FALSE -  feature is turned off.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_FORCEPWRDOWNTHROTEN                                0x10849D6C  // bool

/// @ingroup Memory
/// @brief This value indicates whether to enable memory P-States.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE - Enable memory P-States.
/// @li FALSE - Disable memory P-States.
  #define APCB_TOKEN_UID_ENABLEMEMPSTATE                                    0x56B93947  // bool

/// @ingroup Memory
/// @brief Desired type of DDR routing.
/// @brief Permitted Choices: (Type: BOOLEAN)(Default: FALSE):
/// @li TRUE : Enable routing for a 'balanced Tee' sytle.
/// @li FALSE : Disabled
  #define APCB_TOKEN_UID_DDRROUTEBALANCEDTEE                                0xE68C363D  // bool

/// @ingroup Memory
/// @brief This option selects the temperature controlled Refresh Mode.
/// @brief Permitted Choices: (Type: BOOLEAN) (Default: Disabled)
/// @li Enabled - This feature is enabled and operational.
/// @li Disabled
  #define APCB_TOKEN_UID_MEM_TEMP_CONTROLLED_REFRESH_EN                     0xF051E1C4  // bool

/// @ingroup Memory
/// @brief This is an advanced performance setting. It specifies if the system should use DRAM Bank Group Swap mode. The AMD recommended setting is indicated by
/// the default setting. Changes to this setting must be based on individual platform testing.
/// @brief Permitted Choices: (Type: List)(Default: Enabled)
/// @li Disabled
/// @li Enabled
/// @li Auto  -  ABL decides the best setting.
  #define APCB_TOKEN_UID_ENABLEBANKGROUPSWAPALT                             0xA89D1BE8  // bool

/// @ingroup Memory
/// @brief UECC_RETRY_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_UECC_RETRY_DDR4                                    0xBFF00125  // bool

/// @ingroup Memory
/// @brief This token control for using aggressor static lanes include ECC lanes.
/// @li Disable  -  Aggressor Static Lane configuration is disabled (Default)
/// @li Enabled - Aggressor Static Lane configuration is enabled
  #define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_CTRL                    0x77E6F2C9  // bool

/// @brief DRAMDOUBLEREFRESHRATEEN
/// @details Type:BOOLEAN
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_DRAMDOUBLEREFRESHRATEEN                            0x974E8E7C  // unused

/// @brief CBS_CMN_MEM_CTRLLER_DRAM_ECC_EN_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_DRAM_ECC_EN_DDR4               0x9C6D6993  // bool

/// @brief This item configures the feature of DRAM Post Package Repair.
/// @brief Permitted Choices: (Type: Boolean) (Default: FALSE)
/// @li FALSE - Post Package Repair is disabled.
/// @li TRUE - Post Package Repair is enabled.
  #define APCB_TOKEN_UID_POST_PACKAGE_REPAIR_ENABLE                         0xCDC03E4E  // bool

/// @ingroup Memory
/// @brief This token, if enable will enable the entries for target static lanes including ECC lanes.
/// @details Permitted Choices: (Type: Boolean) (Default: FALSE)
/// @li FALSE - Aggressor Static Lane configuration is disabled
/// @li TRUE - Aggressor Static Lane configuration is enabled
  #define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_CTRL                     0xE1CC135E  // bool

/// @brief CBS_CMN_MEM_MAPPING_BANK_INTERLEAVE_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_DISABLE_0_AUTO_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_MAPPING_BANK_INTERLEAVE_DDR4           0x77A2B63A  // bool in code, uint8 in x86 data //bool

/// @brief CBS_CMN_MEM_CTRLLER_BANK_GROUP_SWAP_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_BANK_GROUP_SWAP_DDR4           0x229EDFE4  // bool in code, uint8 in x86 data //bool

/// @brief CBS_CMN_MEM_ADDRESS_HASH_BANK_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_ADDRESS_HASH_BANK_DDR4                 0x0EF08D04  // bool in code, uint8 in x86 data //bool

/// @brief CBS_CMN_MEM_ADDRESS_HASH_CS_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_ADDRESS_HASH_CS_DDR4                   0xA01AB8A0  // bool in code, uint8 in x86 data //bool

/// @ingroup Memory
/// @brief CBS_CMN_MEM_SPD_READ_OPTIMIZATION_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_SPD_READ_OPTIMIZATION_DDR4             0x8D3AB10E  // bool in code, uint8 in x86 data //bool

/// @brief CBS_CMN_MEM_MBIST_EN
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_MBIST_EN                               0x0D0AE86F  // uint8 //bool

/// @ingroup Memory
/// @brief CBS_CMN_MEM_UECC_RETRY_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_UECC_RETRY_DDR4                        0x42216E4B  // Duplicate with APCB_TOKEN_UID_UECC_RETRY_DDR4 //bool

/// @brief CBS_CMN_MEM_DATA_POISONING_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_DATA_POISONING_DDR4                    0x598E8661  // uint8 in x86 data, not used in code //bool

/// @brief CBS_CMN_MEM_OVERCLOCK_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_AUTO_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_OVERCLOCK_DDR4                         0x593292BE  // uint8 in x86 data, parent control in code //bool

/// @brief CBS_CMN_MEM_ADDRESS_HASH_RM_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_AUTO_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_ADDRESS_HASH_RM_DDR4                   0x50A6D6CA  // bool

/// @brief CBS_CMN_MEM_CTRLLER_DATA_SCRAMBLE_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_DATA_SCRAMBLE_DDR4             0x6301BD18  // bool

/// @brief CBS_CMN_MEM_GEAR_DOWN_MODE_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_GEAR_DOWN_MODE_DDR4                    0x68444D72  // bool

/// @brief CBS_CMN_MEM_MBIST_AGGRESSORS
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_MBIST_AGGRESSORS                       0xD98B8639  // bool

/// @brief CBS_CMN_MEM_MBIST_PER_BIT_SECONDARY_DIE_REPORT
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_MBIST_PER_BIT_SECONDARY_DIE_REPORT         0xF4943BAD  // bool

/// @brief For those who include the CBS feature, this item is the CBS control for enabling the memory Power Down. When this item is set to 'Auto', the resulting
/// value is taken from the APCB_TOKEN_UID_ENABLEPOWERDOWN control.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE -  Power Down is forced to be active.
/// @li FALSE - Power Down is forced to be turned off.
/// @li Auto - value is taken from APCB token APCB_TOKEN_UID_ENABLEPOWERDOWN.
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_PWR_DN_EN_DDR4                 0x2D3BB9D8  // bool

/// @brief CBS_CMN_MEM_CTRLLER_BANK_GROUP_SWAP_ALT_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_BANK_GROUP_SWAP_ALT_DDR4       0xAE6507DA  // bool

/// @ingroup DF
/// @brief DF_PROBE_FILTER_ENABLE
/// @details Type:BOOLEAN
/// @see ENABLE_DISABLE_AUTO_OPTION
  #define APCB_TOKEN_UID_DF_PROBE_FILTER                                    0x6597C573  // uint8

/// @ingroup PSP
/// @brief This token enables debug mode in PSP and SMU FW, allowing the system to hang when there's an error instead of a reset.
/// @brief Permitted Choices: (Type: Value) (Default: TRUE - Production Mode)
/// @li FALSE = Production Mode. System will reset on fatal error.
/// @li TRUE = Debug Mode. System will hang allowing time for a debug user to view the issue.
  #define APCB_TOKEN_UID_PSP_ENABLE_DEBUG_MODE                              0xD1091CD0  // uint8

/// @brief Specifies if Write CRC feature is to be enabled in the memory controller and should be attempted. CRC errors could cause fatal system error or be retr
/// ied. The processor implements a cyclic redundancy check (CRC) on write data packets, as per the JEDEC DDR4 standard. If a CRC error occurs, the comman
/// d is replayed. This feature provides detection and recovery for transient errors on the bus. Enablement of this feature is optional, since enabling ha
/// s a performance impact, and the number of replay attempts is configurable.
/// @brief Permitted Choices: (Type: List)(Default: Disabled)
/// @li Enabled - ABL automatically enables address/command parity replay also.
/// @li Disabled
/// @li Auto - ABL will decide the best setting.
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_WR_CRC_EN_DDR4                 0x94451A4B  // bool

/// @brief MEM_DIS_MEM_ERR_INJ
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_DIS_MEM_ERR_INJ                        0xFF756025  // bool

/// @brief MEM_RCD_PARITY_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_RCD_PARITY_DDR4                        0x7E23FE78  // bool

/// @brief MEM_WRITE_CRC_RETRY_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_WRITE_CRC_RETRY_DDR4                   0x25FB6EA6  // bool

/// @brief MEM_EARLY_PAGE_ACTIVATE_DDR4
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_CBS_DBG_MEM_EARLY_PAGE_ACTIVATE_DDR4               0x3D1FB3FF  // bool, debug items

/// @ingroup CCX
/// @brief This control is used to Enable / Disable the Protected Processor Inventory Number (PPIN) feature. Please see the PPR description for and CPUID_Fn80000
/// 008_EBX [23:PPIN].
  #define APCB_TOKEN_UID_CCX_PPIN_OPT_IN                                    0x6A6700FD  // bool

/// @brief APCB request to provide for Group D platform selection. This control tells the SMU to make the appropriate IRM adjustments for a 'Group D' platform. F
/// 17M30 platforms are group D platforms (TRUE); whereas, F17M00 platforms are not (FALSE). See the IRM for further details.
/// @brief Permitted Choices: (Type: Boolean) (Default: FALSE)
  #define APCB_TOKEN_UID_GROUP_D_PLATFORM                                   0x68318493  // bool

/// @ingroup Memory
/// @brief Force Data Mask Disable
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEM_FORCE_DATA_MASK_DISABLE_DDR4                   0xD68482B3  //bool

/// @brief DisRefCmdThrotCnt
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_DISREFCMDTHROTCNT                                  0x8F84DCB4

/// @ingroup Memory
/// @brief OdtsEn
/// @details Enable thermal refresh rate polling MR4 for DDR5 thermal status. If this bit is not set, refresh rate will not be changed based on thermal status.
/// When set, and when thermal status reaches the thermal threshold, refresh rate will be increased.
/// See PPR UMC::ThrottleCtrl[27] OdtsEn
/// @details Permitted Choices (Type: List) (Default: 0x0 Disabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
  #define APCB_TOKEN_UID_ODTSEN                                             0xAEB3F914

/// @brief This item configures the SPD Read Optimization. Because SPD reads via SMBUS is a very slow interface, this option allows the user to skip some unneces
/// sary SPD reads to reduce the memory detection time.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE - SPD reads are skipped for reserved fields and most of upper 256 Bytes.
/// @li FALSE - Read all 512 SPD Bytes.
  #define APCB_TOKEN_UID_MEM_SPD_READ_OPTIMIZATION_DDR4                     0x6816F949

/// @ingroup NBIO
/// @brief Display Splash Screen
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ENABLE_VGA_PROGRAM                                 0x6570EACE

/// @ingroup NBIO
/// @brief Forces to enable OC mode which will disable FCLK DPM and Memory Pstates
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_GNB_FCLK_OC_FLAG                                   0x8A109D3F

/// @brief Enables GPU Translation Cache
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_GPU_TRANSLATION_CACHE                              0xEEED60BA  //bool

/// @ingroup Memory
/// @brief MEM VDDIO control
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEM_OC_VDDIO_CONTROL                               0x6CD36DBE

/// @ingroup Memory
/// @brief Discard OC condition and enforce to enable MEM VDDIO adjustment
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_MEM_OC_VDDIO_CONTROL_ENFORCE_ON                    0x72958E2C

/// @ingroup Memory
/// @brief DFE is a Phy Hardware feature for the receive Data DQ to improve read margin. Customers may want to disable DFE on certain DIMMs that have lots of mar
/// gin to reduce power consumption.
/// @brief Permitted Choices: (Type: List)(Default: AUTO)
/// @li Auto - the powerup default is used (enabled).
/// @li Enable - the DFE service is active.
/// @li Disable - the DFE service is stopped.
  #define APCB_TOKEN_UID_MEM_CTRLLER_PMU_TRAIN_DFE_DDR4                     0x36A4BB5B  //bool

/// @ingroup Memory
/// @brief FFE is a Transmit Data equalization in the PHY that applies a modified drive level to the DQ Lanes to improve the signal at the Dram. Customers may wa
/// nt to disable FFE on certain DIMMs that have lots of margin to reduce power consumption.
/// @brief Permitted Choices: (Type: List)(Default: AUTO)
/// @li Auto - the power up default is used (enabled).
/// @li Enable - the FFE service is active.
/// @li Disable - the FFE service is stopped.
  #define APCB_TOKEN_UID_MEM_CTRLLER_PMU_TRAIN_FFE_DDR4                     0x0D46186D  //bool

/// @brief Enable LN2 mode
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_GNB_SMU_LN2_MODE                                   0x359597F5

/// @ingroup FCH
/// @brief eSPI ABL init
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ESPI_ABL_INIT_ENABLE                               0x87958B5A  // uint8

/// @ingroup FCH
/// @brief eSPI Port 80H decoding Enable
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ESPI_IO80_ENABLE                                   0x99ACD54C  // uint8

/// @ingroup FCH
/// @brief eSPI KBC Port 60h/64h decoding Enable
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_ESPI_KBC6064_ENABLE                                0xFFF62D7C  // uint8

/// @brief Disable NVDIMM-N feature
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_DISABLE_NVDIMM_N_FEATURE                           0x941A92D4

/// @brief Disable NVDIMM-N feature
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_DISABLE_NVDIMM_N_FEATURE               0xB424AFF0

/// @brief Trimming the p-state level to make P0=P1
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_SMU_DPM_LEVEL_TRIMMING                             0xCCFBCC5D

/// @brief Degrade MP3 frequency to 333/333/667
/// @details Type:BOOLEAN
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_SMU_DPM_MP3_DEGRADE                                0xFCF03E05

/// @brief This is the main switch that enables the Pole, VGA, DC, & IQOFC phy over-ride pararmeters.
/// @brief Permitted choices: (Type: Boolean)(Default: FALSE)
/// @li FALSE - The feature is disabled.
/// @li TRUE - The below overrides are active.
  #define APCB_TOKEN_UID_DXIO_VGA_API_ENABLE                                0xBD5AA3C6

/// @brief Enable to program the settings that are required for performance tracing in ABL. This token should only be enabled in non-mission mode (development/de
/// bug) situations.
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
  #define APCB_TOKEN_UID_PERFORMANCE_TRACING                                0xF27A10F0  // bool

/// @brief Addition Feature Config Support
/// @details Type:BOOLEAN
/// @li 0 = Disable
/// @li 1 = Enable
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_CFG                                  0x0F4C7789  // bool

/// @brief Addition Feature config DSM
/// @details Type:BOOLEAN
/// @li 0 = Disable
/// @li 1 = Enable
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM                                  0x31A6AFAD  // bool

/// @brief Addition Feature config DSM Detector
/// @details Type:BOOLEAN
/// @li 0 = Disable
/// @li 1 = Enable
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_DSM_DETECTOR                         0xF5768CEE  // bool

/// @brief Addition Feature config L3 Perf Bias
/// @details Type:BOOLEAN
/// @li 0 = Disable
/// @li 1 = Enable
  #define APCB_TOKEN_UID_GNB_ADDI_FEAT_L3_PERF_BIAS                         0xA003B37A  // bool

/// @ingroup Memory
/// @brief Interleave memory blocks across the DRAM chip selects for node 0.
/// @details The "Disabled" setting will prevent bank interleaving from being established. The "Auto" setting will allow ABL to determine if the DIMMs are
/// capable of supporting the feature and then make the proper settings. If the DIMMs present in the system are not conducive to bank interleaving operation,
/// then ABL will not use interleave settings.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li Auto = ABL to determine if the DIMMs are capable of supporting the feature and then make the proper settings
  #define APCB_TOKEN_UID_MEM_CS_INTERLEAVE_DDR                              0xA196A838  // bool

/// @ingroup Memory
/// @brief Enable or disable bank address hashing
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_ADDRESS_HASH_BANK_DDR                          0x27CC2068  // bool

/// @ingroup Memory
/// @brief Enable or disable chip select address hashing
/// @details Chip select interleaving with 2-way or 4-way interleaving across DIMMs with matched ranks is a prerequisite to enable address hashing for chip select.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_ADDRESS_HASH_CS_DDR                            0x91D21E3F  // bool

/// @ingroup Memory
/// @brief Enable or disable rank multiply address hashing
/// @details Rank multiply addressing is a prerequisite to enable address hashing for the rank multiply bit.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_ADDRESS_HASH_RM_DDR                            0xC325AA87  // bool

/// @ingroup Memory
/// @brief Enable or disable sub-channel address hashing
/// @details The CH bit selection with UMC::BeqCtrl0[VcmEn]==1 is a prerequisite to enable address hashing on the channel bit.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_ADDRESS_HASH_SUBCHANNEL_DDR                    0x3664DBA5

/// @ingroup Memory
/// @brief Enable or disable data scrambling
/// @details The data scramble feature reduces the likelihood of pathological bad signal integrity problems on the DDR interface. The data is scrambled prior
/// to being written to DRAM. The data is unscrambled when the data is returned on a DRAM read access.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_DATA_CTRL_DATA_SCRAMBLE_EN_DDR                 0x8D67F9E4

/// @ingroup Memory
/// @brief CXL_ENCRYPTION_ENABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_AUTO_VALIDVAL
  #define APCB_TOKEN_UID_CXL_ENCRYPTION_ENABLE                              0xE6E3505D  // bool

/// @ingroup Memory
/// @brief SME_MK_ENABLE
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_SME_MK_ENABLE                                      0x07A5DB75  // bool

/// @ingroup CCX
/// @brief CPU Watchdog Enable
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_CPU_WDT_EN                                         0x74362038  // bool

/// @ingroup PSP
/// @brief This is the main switch that disable SEV. To re-enable SEV, a POWER CYCLE is needed after selecting the "Enable" option.
/// @brief Permitted choices: (Type: Boolean)(Default: FALSE)
/// @li FALSE - The PSP SEV is enabled.
/// @li TRUE - The PSP SEV is disabled.
  #define APCB_TOKEN_UID_PSP_SEV_DISABLE                                    0xADC833E4  // bool

/// @ingroup DF
/// @brief DF CDMA
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL
  #define APCB_TOKEN_UID_DF_CDMA                                            0xD7D76F0C  // bool

/// @ingroup DF
/// @brief DF_CDMA_CS_CFGA4_B7
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL
  #define APCB_TOKEN_UID_DF_CDMA_CS_CFGA4_B7                                0x900B0A9F  // bool

/// @ingroup CCX
/// @brief Passes APIC mode to ABL.
/// @details This should always be the same as gEfiAmdAgesaModulePkgTokenSpaceGuid.PcdAmdApicMode.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
//  @see APIC_MODE_VALIDVAL
  #define APCB_TOKEN_UID_APIC_MODE                                          0xF284AD3F
/** APIC_MODE_VALIDVAL
*  Value range for APCB_TOKEN_UID_APIC_MODE
*/
typedef enum {
  APIC_MODE_COMPATIBILITY  = 0,      ///< Compatibility
  APIC_MODE_XAPIC          = 1,      ///< xAPIC
  APIC_MODE_X2APIC         = 2,      ///< x2APIC
  APIC_MODE_AUTO           = 0xFF,   ///< Auto
} APIC_MODE_VALIDVAL;

/// @ingroup NBIO
/// @brief Passes IOMMU enablement to ABL.
/// @details This should always be the same as gEfiAmdAgesaPkgTokenSpaceGuid.PcdCfgIommuSupport.
/// @details Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE - This option is active.
/// @li FALSE - This option is turned off.
  #define APCB_TOKEN_UID_IOMMU                                              0x1CCC9834


// =================================================================================================
// CBS CMN APCB Tokens (1BYTE)
// -------------------------------------------------------------------------------------------------
/** ENABLE_DISABLE_AUTO_OPTION
*   Value range for UINT8 type with Enable, Disable and Auto usage
*/
typedef enum {
  ENABLE_DISABLE_AUTO_OPTION_DISABLED = 0,///<Disabled
  ENABLE_DISABLE_AUTO_OPTION_ENABLED = 1,///<Enabled
  ENABLE_DISABLE_AUTO_OPTION_AUTO = 3,///<Auto
} ENABLE_DISABLE_AUTO_OPTION;

/** MANUAL_AUTO_0X00_VALIDVAL
*   Value range for UINT8 type with AUTO: 0x00 and ENABLE: 0x01 usage
*/
typedef enum {
  MANUAL_AUTO_0X00_VALIDVAL_AUTO = 0x00,      ///< AUTO
  MANUAL_AUTO_0X00_VALIDVAL_MANUAL = 1,       ///< MANUAL
} MANUAL_AUTO_0X00_VALIDVAL;

/** MANUAL_AUTO_0XFF_VALIDVAL
*   Value range for UINT8 type with AUTO: 0xFF and ENABLE: 0x01 usage
*/
typedef enum {
  MANUAL_AUTO_0XFF_VALIDVAL_AUTO = 0xFF,      ///< AUTO
  MANUAL_AUTO_0XFF_VALIDVAL_MANUAL = 1,       ///< MANUAL
} MANUAL_AUTO_0XFF_VALIDVAL;

typedef enum {
  WORKLOAD_PROFILE_DISABLED = 0,
  WORKLOAD_PROFILE_CPU_INTENSIVE = 1,
  WORKLOAD_PROFILE_JAVA_THROUGHPUT = 2,
  WORKLOAD_PROFILE_JAVA_LATENCY = 3,
  WORKLOAD_PROFILE_POWER_EFFICIENCY = 4,
  WORKLOAD_PROFILE_MEMORY_THROUGHPUT_INTENSIVE = 5,
  WORKLOAD_PROFILE_STORAGE_IO_INTENSIVE = 6,
  WORKLOAD_PROFILE_NIC_THROUGHPUT_INTENSIVE = 7,
  WORKLOAD_PROFILE_NIC_LATENCY_SENSITIVE = 8,
  WORKLOAD_PROFILE_ACCELERATOR_THROUGHPUT = 9,
  WORKLOAD_PROFILE_VMWARE_VSPHERE_OPTIMIZED = 10,
  WORKLOAD_PROFILE_LINUX_KVM_OPTIMIZED = 11,
  WORKLOAD_PROFILE_CONTAINER_OPTIMIZED = 12,
  WORKLOAD_PROFILE_RDBMS_OPTIMIZED = 13,
  WORKLOAD_PROFILE_BIG_DATA_ANALYTICS_OPTIMIZED = 14,
  WORKLOAD_PROFILE_IOT_GATEWAY = 15,
  WORKLOAD_PROFILE_HPC_OPTIMIZED = 16,
  WORKLOAD_PROFILE_OPENSTACK_NFV = 17,
  WORKLOAD_PROFILE_OPENSTACK_FOR_REALTIME_KERNEL = 18
} WORKLOAD_PROFILE_VALIDVAL;

// -------------------------------------------------------------------------------------------------
/// @GROUPID: APCB_GROUP_TOKEN
/// @TYPEID: APCB_TYPE_TOKEN_1BYTE
/// @DATATYPE: UINT8
/// @SIZE: 1

/// @ingroup CCX
/// @brief CCX_CPB
/// @details Type:UINT8
/// @li 0x00~0xFF = UINT8 Valid Value
  #define APCB_TOKEN_UID_CCX_CPB                                            0x9DA294C2

/// @ingroup CCX
/// @brief Secure Encrypted Virtualization (SEV) uses Address Identifiers (ASIDs) to label the various Virtual Machines (VMs) running in the system. The VMs may
/// be using different features. This token specifies the maximum valid ASID, which affects the maximum system physical address space. 16TB of physical ad
/// dress space is available for systems that support 253 ASIDs, while 8TB is available for systems that support 509 ASIDs.
/// @brief Permitted Choices: (Type: List) (Default: 0x01 - 509 ASIDs)
/// @li 0x00 - Use 253 ASIDs (16TB physical address space).
/// @li 0x01 - Use 509 ASIDs (8TB physical address space).
/// @li 0x03 - Auto mode - will prefer 509 ASIDs.
  #define APCB_TOKEN_UID_CCX_SEV_ASID_COUNT                                 0x55876720  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable DRAM ECC.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - ECC Disabled
/// @li 1 - ECC Enabled
/// @li Auto - ABL decides the setting
  #define APCB_TOKEN_UID_MEM_ECC_EN_DDR                                     0x5F1DE498

/// @ingroup Memory
/// @brief This option controls whether or not system DRAM contents will be initialized to zero.
/// @details The clear operation will vary in time duration proportionate to the size of DRAM memory. Avoiding the clear, could reduce overall boot time.
/// Note that if DRAM ECC is enabled, this token has no effect as the memory clear process is required.
/// Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Enabled - DRAM memory will be cleared to zeroes.
/// @li Disabled - DRAM will not be cleared.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_MEM_MEMORY_CLEAR_DDR                               0xC90B1AEC  //uint8

/// @ingroup CCX
/** CPU_SEV_ASID_COUNT_VALIDVAL
*   Value range for APCB_TOKEN_UID_CCX_SEV_ASID_COUNT
*/
typedef enum {
  CPU_SEV_ASID_COUNT_253ASIDS = 0,///<253 ASIDs
  CPU_SEV_ASID_COUNT_509ASIDS = 1,///<509 ASIDs
  CPU_SEV_ASID_COUNT_AUTO = 3,///<Auto
} CPU_SEV_ASID_COUNT_VALIDVAL;

/// @ingroup CCX
/// @brief XTRIG7_WORKAROUND
/// @details Type:UINT8
/// @see CPU_XTRIG7_WORKAROUND_VALIDVAL
  #define APCB_TOKEN_UID_XTRIG7_WORKAROUND                                  0x2762E77B  //uint8
/// @ingroup CCX
/** CPU_XTRIG7_WORKAROUND_VALIDVAL
*   Value range for APCB_TOKEN_UID_XTRIG7_WORKAROUND
*/
typedef enum {
  CPU_XTRIG7_WORKAROUND_AUTO = 0xFF,///<Auto
  CPU_XTRIG7_WORKAROUND_NOWORKAROUND = 0,///<No Workaround
  CPU_XTRIG7_WORKAROUND_BRONZEWORKAROUND = 1,///<Bronze Workaround
} CPU_XTRIG7_WORKAROUND_VALIDVAL;

/// @ingroup Memory
/// @brief MBIST Aggressor Static Lane Select ECC
/// @details This token set the DQ lanes mask for ECC byte for Aggressor Lanes. This is 1 byte and each bit represents 1 DQ lane of ECC.
/// @details Permitted Choices (Type: Numerical) (Default: 0x0)
/// @li 0 ~ 0xa
  #define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_ECC                 0x57122E99  //uint8

/// @ingroup Memory
/// @brief MBIST Aggressor Static Lane Value
/// @details This token determines the value which need to be set for Aggressor Static Lanes. The possible values are either 0 or 1.
/// @details Permitted Choices (Type: Numerical) (Default: 0x0)
/// @li 0 ~ 0xa
  #define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_VAL                     0x4474D416  //uint8

/// @ingroup Memory
/// @brief MBIST Target Static Lane Select ECC
/// @details This token set the DQ lanes mask for ECC byte for Target Lanes. This is 1 byte and each bit represents 1 DQ lane of ECC.
/// @details Permitted Choices (Type: Numerical) (Default: 0x0)
/// @li 0 ~ 0xa
  #define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_ECC                  0xA6E92CEE  //uint8

/// @ingroup Memory
/// @brief MBIST Target Static Lane Value
/// @details Target Static Lane Control must be enabled as a prerequisite. Specifies the override data value used for creating traffic on the data bus.
/// The possible values are either 0 or 1.
/// @details Permitted Choices (Type: Numerical) (Default: 0x0)
/// @li 0 ~ 0xa
  #define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_VAL                      0x4D7E0206  //uint8

/// @ingroup Memory
/// @brief Mbist Data Eye Type
/// @details This options determines which results are expected to be captured for Data Eye. (Default: Worst Case Margin Only)
/// @see MEM_MBIST_DATA_EYE_TYPE_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_TYPE                            0x4E2EDC1B  //uint8

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_TYPE
*/
typedef enum {
  MEM_MBIST_DATA_EYE_TYPE_1DVOLTAGESWEEP = 0,       ///< 1D Voltage Sweep
  MEM_MBIST_DATA_EYE_TYPE_1DTIMINGSWEEP = 1,        ///< 1D Timing Sweep
  MEM_MBIST_DATA_EYE_TYPE_2DFULLDATAEYE = 2,        ///< 2D Full Data Eye
  MEM_MBIST_DATA_EYE_TYPE_WORSTCASEMARGINONLY = 3,  ///< Worst Case Margin Only
} MEM_MBIST_DATA_EYE_TYPE_VALIDVAL;

/// @ingroup Memory
/// @brief MBIST Worst Case Granularity
/// @details This token determines the granularity of the data capture for worst case margins. (Default: Per Nibble)
/// @see MEM_MBIST_WORST_CASE_GRAN_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_WORST_CASE_GRAN                          0x23B0B6A1  //uint8

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_WORST_CASE_GRAN
*/
typedef enum {
  MEM_MBIST_WORST_CASE_GRAN_PERCHIPSELECT = 0,  ///< Per Chip Select
  MEM_MBIST_WORST_CASE_GRAN_PERNIBBLE = 1,      ///< Per Nibble
} MEM_MBIST_WORST_CASE_GRAN_VALIDVAL;

/// @ingroup Memory
/// @brief MBIST Read Data Eye Voltage Step
/// @details This field is used in sweeping the voltage Vref for DDR5. This token determines the step size for the read data eye voltage parameter.
/// For further detail, see the PPR description for UMC::Phy::VrefDac1. (Default: 1)
/// @see MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP               0x35D6A4F8  //uint8

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP
*/
typedef enum {
  MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP_1 = 1, ///< Increment by one 'step unit' (as defined by the PPR) on each pass.
  MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP_2 = 2, ///< Increment by 2 step units.
  MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP_4 = 4, ///< Increment by 4 step units.
} MEM_MBIST_READ_DATA_EYE_VOLTAGE_STEP_VALIDVAL;

/// @ingroup Memory
/// @brief MBIST Read Data Eye Timing Step
/// @details This field is used in sweeping the RxClk Delay. This token determines the step size for the read data eye timing parameter. (Default: 1)
/// @see MEM_MBIST_READ_DATA_EYE_TIMING_STEP_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_TIMING_STEP                0x58CCD28A  //uint8

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_READ_DATA_EYE_TIMING_STEP
*/
typedef enum {
  MEM_MBIST_READ_DATA_EYE_TIMING_STEP_1 = 1, ///< Increment by one 'step unit' (as defined by the PPR) on each pass.
  MEM_MBIST_READ_DATA_EYE_TIMING_STEP_2 = 2, ///< Increment by 2 step units.
  MEM_MBIST_READ_DATA_EYE_TIMING_STEP_4 = 4, ///< Increment by 4 step units.
} MEM_MBIST_READ_DATA_EYE_TIMING_STEP_VALIDVAL;

/// @ingroup Memory
/// @brief MBIST Write Data Eye Voltage Step
/// @details This field is used in sweeping the voltage Vref for DDR5. This token determines the step size for the write data eye voltage parameter.
/// For further detail, see the PPR description for UMC::Phy::VrefDac0. (Default: 1)
/// @see MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP              0xCDA61022  //uint8

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP
*/
typedef enum {
  MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP_1 = 1, ///< Increment by one 'step unit' (as defined by the PPR) on each pass.
  MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP_2 = 2, ///< Increment by 2 step units.
  MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP_4 = 4, ///< Increment by 4 step units.
} MEM_MBIST_WRITE_DATA_EYE_VOLTAGE_STEP_VALIDVAL;

/// @ingroup Memory
/// @brief MBIST Write Data Eye Timing Step
/// @details This field is used in sweeping the Tx DQ Delay. This token determines the step size for the write data eye timing parameter. (Default: 1)
/// @see MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP               0xD9025142  //uint8

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP
*/
typedef enum {
  MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP_1 = 1, ///< Increment by one 'step unit' (as defined by the PPR) on each pass.
  MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP_2 = 2, ///< Increment by 2 step units.
  MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP_4 = 4, ///< Increment by 4 step units.
} MEM_MBIST_WRITE_DATA_EYE_TIMING_STEP_VALIDVAL;

/// @brief MEM_MBIST_DATA_EYE_EXECUTION_REPEAT_COUNT
/// @details Type:UINT8
/// @li 0~10 = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_MBIST_DATA_EYE_EXECUTION_REPEAT_COUNT          0x8E4BDAD7  //uint8

/// @ingroup DF
/// @brief Disable DF sync flood propagation.
/// @brief Permitted Choices (Type: Value) (Default: 0)
/// @li 0 - Allow SyncFlood propagation.
/// @li 1 - Disable SyncFlood propagation.
/// @li 0xFF - Auto
  #define APCB_TOKEN_UID_DF_SYNC_FLOOD_PROP                                 0x49639134  //uint8

/// @ingroup DF
/// @brief Disable SyncFlood propagation to UMC and downstream secondarys .
/// @brief Permitted Choices (Type: Value) (Default: 0)
/// @li 0 - Allow SyncFlood propagation.
/// @li 1 - Disable SyncFlood propagation.
/// @li 0xFF - Auto
  #define APCB_TOKEN_UID_DF_EXT_IP_SYNC_FLOOD_PROP                          0xFFFE0B07  //uint8

/// @ingroup DF
/** DF_SYNC_FLOOD_PROP_VALIDVAL
*   Value range for APCB_TOKEN_UID_DF_SYNC_FLOOD_PROP
*/
typedef enum {
  DF_SYNC_FLOOD_PROP_SYNCFLOODDISABLED = 1,///<Sync flood disabled
  DF_SYNC_FLOOD_PROP_SYNCFLOODENABLED = 0,///<Sync flood enabled
  DF_SYNC_FLOOD_PROP_AUTO = 0xFF,///<Auto
} DF_SYNC_FLOOD_PROP_VALIDVAL;

/// @ingroup DF
/// @brief  Specifies whether DF_FREEZE_MODULE_ON_ERROR is Enabled or Disabled
/// @details Type:UINT8
/// @see ENABLE_DISABLE_AUTO_OPTION
  #define APCB_TOKEN_UID_DF_FREEZE_MODULE_ON_ERROR                          0x686B845E  //uint8

/// @ingroup DF
/// @brief This options enables GMI encryption.
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li TRUE - Enabled.
/// @li FALSE - Disabled.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_DF_GMI_ENCRYPT                                     0x08A45920  // uint8 //uint8

/// @ingroup DF
/// @brief This options enables XGMI encryption.
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li TRUE - Enabled.
/// @li FALSE - Disabled.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_DF_XGMI_ENCRYPT                                    0x6BD32F1C  // uint8 //uint8

/// @ingroup DF
/// @brief Choice to activate the C6 / DF save / restore regions.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE - Enabled.
/// @li FALSE - Disabled.
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_DF_SAVE_RESTORE_MEM_ENCRYPT                        0x7B3D1F75  // uint8 //uint8

/// @ingroup Memory
/// @brief AUTOREFMODE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_AUTOREFMODE                                        0x5B10198C  // uint8

typedef enum {
  APCB_REF_MODE_AUTO = 0,
  APCB_REF_MODE_ALLBANK,
  APCB_REF_MODE_PERBANK,
  APCB_REF_MODE_MIXED,
} APCB_REF_MODE;

/// @ingroup Memory
/// @brief Advanced Encryption Standard Mode
/// @details The UMC data encryption feature is used as part of overall SOC solutions for main memory encryption. The data is encrypted in the UMC prior
/// to being written to DRAM. The data is decrypted in the UMC when the data is returned on a DRAM read access. (Default: AES-256)
/// @see MEM_AES_VALIDVAL
  #define APCB_TOKEN_UID_MEM_AES                                            0x14756DDD  // uint8

/**
*   @ingroup Memory
*   @brief Values for APCB_TOKEN_UID_MEM_AES
*/
typedef enum {
  MEM_AES_128 = 0, ///< AES-128
  MEM_AES_256 = 1, ///< AES-256
} MEM_AES_VALIDVAL;

/// @ingroup Memory
/// @brief Bank Swap Mode
/// @details This feature determines DRAM address mapping strategy
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL decides the best setting
/// @li 0 = Disabled
/// @li 1 = Swap CPU
  #define APCB_TOKEN_UID_MEM_BANK_SWAP_MODE_DDR                             0x7EF11128  //uint8

/// @ingroup Memory
/// @brief Token to choose ECS mode between Auto and Manual ECS.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - ECS Auto Mode
/// @li 1 - ECS Manual Mode
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_ECSFEATURE_DDR                                 0xB3846DDF  //uint8

/// @ingroup Memory
/// @brief Token to choose ECS count mode between CodeWord and RowCount Modes.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - Row Count Mode
/// @li 1 - Code Word Count Mode
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_ECS_COUNT_MODE_DDR                             0x236EFFF3  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable AutoEcs during Self refresh when in Manual ECS mode.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - Auto ECS Disabled
/// @li 1 - Auto ECS Enabled
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_AUTOECS_IN_SELF_REFRESH_DDR                    0x905039D0  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable ECS Writeback Suppression.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - ECS Writeback Suppression Disabled
/// @li 1 - ECS Writeback Suppression Enabled
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_ECS_WRITEBACK_SUPPRESSION_DDR                  0xC033C515  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable X4 Writeback Suppression.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - X4 Writeback Suppression Disabled
/// @li 1 - X4 Writeback Suppression Enabled
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_X4_WRITEBACK_SUPPRESSION_DDR                   0x7368D8E1  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable Dram Redirect Scrubber.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - Redirect Scrub Disabled
/// @li 1 - Redirect Scrub Enabled
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_REDIRECT_SCRUB_DDR                             0x5E0BAD65  //uint8

/// @ingroup Memory
/// @brief Token to select Dram ECC Scrub Redirection Limit.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - 8 scrubs
/// @li 1 - 4 scrubs
/// @li 2 - 2 scrubs
/// @li 3 - 1 scrub
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_REDIRECT_SCRUB_LIMIT_DDR                       0xB2AF7696  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable Dram Patrol Scrubber
/// @brief DRAM Scrub Time
/// @details Specifies the number of hours to scrub memory.
/// @details Permitted Choices (Type: List) (Default: 24)
/// @li 0 = Disabled
/// @li 1 = 1 hour
/// @li 4 = 4 hours
/// @li 6 = 6 hours
/// @li 8 = 8 hours
/// @li 12 = 12 hours
/// @li 16 = 16 hours
/// @li 24 = 24 hours
/// @li 48 = 48 hours
  #define APCB_TOKEN_UID_MEM_PATROL_SCRUB_DDR                               0x4EA08B9D  //uint8

/// @ingroup Memory
/// @brief Token to select Dram Error Threshold Count Value.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - ETC_4
/// @li 1 - ETC_16
/// @li 2 - ETC_64
/// @li 3 - ETC_256
/// @li 4 - ETC_1024
/// @li 5 - ETC_4096
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_ETC_DDR                                        0xE1F73EAD  //uint8

/// @ingroup Memory
/// @brief Token to Enable/Disable poison data creation on uncorrectable DRAM ECC errors and poison propagation to CPU cores and caches.
/// @details Requires ECC memory. When FALSE, a fatal error event will occur on DDR ECC errors. sets UMC_CH::EccCtrl[UcFatalEn] when MC_CH::EccCtrl[WrEccEn] is set.
/// Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - Poisoning Disabled
/// @li 1 - Poisoning Enabled
/// @li Auto - ABL decides the best setting
  #define APCB_TOKEN_UID_MEM_DATA_POISONING_DDR                             0x86140D77  //uint8

/// @brief BMC_INIT_BEFORE_DRAM
/// @details Type:UINT8
/// @see BOOLEAN_TRUE_FALSE_VALIDVAL
  #define APCB_TOKEN_UID_BMC_INIT_BEFORE_DRAM                               0xFA94EE37  // bool

///@ingroup NBIO
/// @brief If the second WAFL link is enabled as an x1 PCIE link (APCB_TOKEN_UID_CONFIGURE_SECOND_PCIE_LINK = TRUE); this APCB token will be used to set the Gen
/// speed of the second x1 PCIE link at early ABL phase.
/// @brief Permitted Choices: (Type: List)(Default: 0)
/// @li 0x0 = Keep HW default.
/// @li 0x1 = Gen1 speed.
/// @li 0x2 = Gen2 speed.
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_SPEED                             0x8723750F

/// @ingroup NBIO
/// @brief SECOND_PCIE_LINK_START_LANE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_START_LANE                        0xB1648033  // uint8

/// @ingroup NBIO
/// @brief SECOND_PCIE_LINK_END_LANE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_END_LANE                          0x3BF323FD  // uint8

/// @ingroup NBIO
/// @brief SECOND_PCIE_LINK_DEVICE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_DEVICE                            0x05D08D49  // uin8

/// @ingroup NBIO
/// @brief SECOND_PCIE_LINK_FUNCTION
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_FUNCTION                          0x1097E009  // uin8

/// @ingroup NBIO
/// @brief SECOND_PCIE_LINK_PORT_PRESENT
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_PORT_PRESENT                      0x973CEADD  // uin8

/// @ingroup NBIO
/// @brief THIRD_PCIE_LINK_START_LANE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_START_LANE                         0x8EA3BD2A  // uin8

/// @ingroup NBIO
/// @brief THIRD_PCIE_LINK_END_LANE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_END_LANE                           0x8EC61B06  // uin8

/// @ingroup NBIO
/// @brief THIRD_PCIE_LINK_SPEED
/// @details Type:UINT
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_SPEED                              0x79633632  // uin8

/// @ingroup NBIO
/// @brief THIRD_PCIE_LINK_DEVICE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_DEVICE                             0xD92271F3  // uin8

/// @ingroup NBIO
/// @brief THIRD_PCIE_LINK_FUNCTION
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_FUNCTION                           0x20035400  // uin8

/// @ingroup NBIO
/// @brief THIRD_PCIE_LINK_PORT_PRESENT
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_THIRD_PCIE_LINK_PORT_PRESENT                       0xEBDCF0F1  // uin8

/// @ingroup NBIO
/// @brief FOURTH_PCIE_LINK_START_LANE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_START_LANE                        0x0870533F  // uin8

/// @ingroup NBIO
/// @brief FOURTH_PCIE_LINK_END_LANE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_END_LANE                          0xA87654BF  // uin8

/// @ingroup NBIO
/// @brief FOURTH_PCIE_LINK_SPEED
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_SPEED                             0x06396763  // uin8

/// @ingroup NBIO
/// @brief FOURTH_PCIE_LINK_DEVICE
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_DEVICE                            0x391E6398  // uin8

/// @ingroup NBIO
/// @brief FOURTH_PCIE_LINK_FUNCTION
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_FUNCTION                          0x09B00CD0  // uin8

/// @ingroup NBIO
/// @brief FOURTH_PCIE_LINK_PORT_PRESENT
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 VALID RANGE
  #define APCB_TOKEN_UID_FOURTH_PCIE_LINK_PORT_PRESENT                      0x4736DAF9  // uin8

/// @ingroup NBIO
/// @brief If the second WAFL link is enabled as an x1 PCIE link (APCB_TOKEN_UID_CONFIGURE_SECOND_PCIE_LINK = TRUE); this APCB token is used to set the second x1
/// PCIE link maximum payload size at early ABL phase.
/// @brief Permitted Choices: (Type: List)(Default: 0xFF)
/// @li 0 - 128Bytes.
/// @li 1 - 256Bytes.
/// @li 2 - 512Byte.
/// @li 3 - 1024Bytes.
/// @li 4 - 2048Bytes
/// @li 5 - 4096Bytes
/// @li 0xFF - Use Hardware default.
  #define APCB_TOKEN_UID_SECOND_PCIE_LINK_MAX_PAYLOAD                       0xE02DF04B  // uint8

/// @ingroup NBIO
/// @brief This Token is being used on the platform to select the Link speed for the BMC link. This will be used during the early initialization for the BMC link
/// .
/// @brief Permitted Choices: (Type: List)(Default: Gen1)
/// @li 1 - Gen1 speed will be used.
/// @li 2 - Gen2 speed will be used.
  #define APCB_TOKEN_UID_BMC_LINK_SPEED                                     0x9C790F4B  // uint8
/** BMC_LINK_SPEED
*   Value range for APCB_TOKEN_UID_BMC_LINK_SPEED
*/
typedef enum {
  PCIE_GEN1_SPEED = 1,    ///< PCIE Gen1 Speed
  PCIE_GEN2_SPEED = 2,    ///< PCIE Gen2 Speed
} BMC_LINK_SPEED;

/// @ingroup NBIO
/// @brief Select RCB checks received completions for incorrect attributes
/// @details Type:UINT8
/// @see BMC_RCB_WRONG_ATTR_DIS
  #define APCB_TOKEN_UID_BMC_RCB_WRONG_ATTR_DIS                             0xAE7F0DF4  // uint8

/// @ingroup NBIO
/** BMC_RCB_WRONG_ATTR_DIS
*   Value range for APCB_TOKEN_UID_BMC_RCB_WRONG_ATTR_DIS
*/
typedef enum {
  WRONG_ATTR_EN = 0,           ///< Enable RCB checks incorrect attributes
  WRONG_ATTR_DIS = 1,          ///< Disable RCB checks incorrect attributes
  WRONG_ATTR_SKIP = 0xFF,      ///< Skip override setting
} BMC_RCB_WRONG_ATTR_DIS;

/// @ingroup NBIO
/// @brief This token is being used to control PCIe GEN2 De-emphasis in ABL for Early training for BMC link.
/// @brief Permitted Choices: (Type: List)(Default: 0xFF)
/// @li 0 - Use de-emphasis from CSR.
/// @li 1 - Use de-emphasis requested by upstream component.
/// @li 2 - Use -6.0 dB
/// @li 3 - Use -3.5 dB
/// @li 0xFF - Skip override setting.
  #define APCB_TOKEN_UID_BMC_GEN2_TX_DEEMPHASIS                             0xF30D142D  // uint8

/// @ingroup NBIO
/// @brief Select Enable BMC Legacy VGA IO Port
/// @details Type:UINT8
/// @li True = Enable, False = Disable
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_ENABLE                               0x468D2CFA  // bool

/// @ingroup NBIO
/// @brief BMC Legacy VGA IO Port Number
/// @details Type:UINT8
/// @li 0~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_PORT                                 0x06E06198  // uint16

/// @ingroup NBIO
/// @brief BMC Legacy VGA IO Port Range
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_PORT_SIZE                            0xFC3F2520  // uint8

/// @ingroup NBIO
/// @brief Replace Re-locatable I/O Space BAR address by Legacy VGA IO Port
/// @details Type:UINT8
/// @li 0~0x6 = Select BAR0 ~ BAR6
  #define APCB_TOKEN_UID_BMC_LEGACY_IO_BAR_REPLACE                          0x2C81A37F  // uint8

/// @brief This control selects whether to configure the second WAFL link as a x1 PCIE link at early ABL phase.
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li True - Enabled the 2nd WAFL link for early training.
/// @li False - Turned off.
  #define APCB_TOKEN_UID_CONFIGURE_SECOND_PCIE_LINK                         0x71428092  // bool

/// @ingroup FCH
/// @brief This option enables the ABL Console Output for debug. Data is sent to a specific port as defined by APCB_TOKEN_CONFIG_FCH_CONSOLE_OUT_SERIAL_PORT. Ena
/// bling console output will increase the boot times.
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE)
/// @li TRUE - Enables the ABL Console Out messages.
/// @li FALSE - This option is turned off and no output is generated.
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_ENABLE                             0xDDB759DA  // uint8
  /// @ingroup FCH
  /// @brief CONSOLE_OUT_BOOT_MODE
  /// @li 0~0xFF = UINT8 Valid Range
  /// BIT[0]  - Normal boot
  /// BIT[1]  - S3/S0i3
  #define APCB_TOKEN_UID_CONSOLE_OUT_BOOT_MODE                              0x4B993A83  // uint8

/// @ingroup FCH
/// @brief Select Legacy Uart (SIO or eSPI) IO base
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_IO                     0x95DC6839  // uint8
/// @ingroup FCH
/** FCH_CONSOLE_OUT_SERIAL_PORT_IO
*   Value range for APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_IO
*/
typedef enum {
  FCH_CONSOLE_OUT_SERIAL_PORT_IO_3F8 = 0,///<0x3F8
  FCH_CONSOLE_OUT_SERIAL_PORT_IO_2F8 = 1,///<0x2F8
  FCH_CONSOLE_OUT_SERIAL_PORT_IO_3E8 = 2,///<0x3E8
  FCH_CONSOLE_OUT_SERIAL_PORT_IO_2E8 = 3,///<0x2E8
} FCH_CONSOLE_OUT_SERIAL_PORT_IO;

/// @ingroup FCH
/// @brief Select which eSPI controller has Uart for ABL consol out with 2E/4E IO enabled or disabled.
/// @details Type:UINT8
/// @li BIT0 - Select which eSPI controller has epsi uart for ABL console out. 0: eSPI controller 0  1: eSPI controller 1
/// @li BIT3 - Disable or enable 2E/2F IO on the selected eSPI controller.     0: 2E/2F Enabled      1: 2E/2F Disabled
/// @li BIT4 - Disable or enable 4E/4F IO on the selected eSPI controller.     0: 4E/4F Enabled      1: 4E/4F Disabled
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SERIAL_PORT_ESPI_CONTROLLER        0xD9D297A6  // uint8

   #define  ESPI_CONTROLLER1_BIT     (1 << 0)
   #define  IO_2E_2F_DIS_BIT         (1 << 3)
   #define  IO_4E_4F_DIS_BIT         (1 << 4)

/// @ingroup FCH
/// @brief When the console is set to use a SuperIO COM port, this option specifies the type of SIO init sequence to be used. An SIO devices typically needs to e
/// nter and exit a configuration mode for setting its devices' parameters. This sequence varies by device.
/// @brief Permitted Choices: (Type: List)(Default: FCH_CONSOLE_OUT_SUPER_IO_TYPE_DEFAULT)
/// @li FCH_CONSOLE_OUT_SUPER_IO_TYPE_DEFAULT - No action. The SIO config is set by customer specific programming.
/// @li FCH_CONSOLE_OUT_SUPER_IO_TYPE_CUSTOM_1 - SIO Type 1 - requires 0xA5 to be sent to the config port (0x2E) twice for unlock; followed by the UART config
/// ; then a final 0xAA sent to the config port to exit config mode.
/// @li FCH_CONSOLE_OUT_SUPER_IO_TYPE_CUSTOM_2 - SIO type 2 - requires 0x5A to be sent to the config port (0x2E) for unlock; followed by the UART config; then
/// a final 0xA5 sent to the config port to exit config mode.
  #define APCB_TOKEN_UID_FCH_CONSOLE_OUT_SUPER_IO_TYPE                      0x5C8D6E82  // uint8
/** FCH_CONSOLE_OUT_SUPER_IO_TYPE
*   Value range for APCB_TOKEN_UID_FCH_CONSOLE_OUT_SUPER_IO_TYPE
*/
typedef enum {
  FCH_CONSOLE_OUT_SUPER_IO_TYPE_DEFAULT = 0,///<Use default type to support multiple super IO
  FCH_CONSOLE_OUT_SUPER_IO_TYPE_CUSTOM_1 = 1,///<Cusotm 1 - Aspeed
  FCH_CONSOLE_OUT_SUPER_IO_TYPE_CUSTOM_2 = 2,///<Cusotm 2 - Pilot 4
} FCH_CONSOLE_OUT_SUPER_IO_TYPE;

/// @ingroup FCH
/// @brief This control sets the baud rate of the selected serial port used for the console.
/// @brief Permitted Choices: (Type: List)(Default: BAUD_RATE_115200)
/// @li BAUD_RATE_2400
/// @li BAUD_RATE_3600
/// @li BAUD_RATE_4800
/// @li BAUD_RATE_7200
/// @li BAUD_RATE_9600
/// @li BAUD_RATE_19200
/// @li BAUD_RATE_38400
/// @li BAUD_RATE_57600
/// @li BAUD_RATE_115200
  #define APCB_TOKEN_UID_ABL_SERIAL_BAUD_RATE                               0xAE46CEA4  // uint8

/// @ingroup DF
/// @brief Selects the type of interleaving desired for the system. Memory interleaving is the process of spreading accesses across various memory components in
/// the system. Interleaving tends to improve overall throughput by running operations in parallel to the different memory controllers. Interleaving is on
/// ly available on systems with more than one memory controller with populated memory devices.
/// @brief Permitted Choices: (Type: List)(Default: Auto)
/// @li DF_MEM_INTLV_SOCKET - [F17M00][F17M10][F17M20] spread accesses across all populated memory devices on all sockets in the system.
/// @li DF_MEM_INTLV_DIE - [F17M00][F17M10][F17M20] spread accesses across all populated memory devices within a socket.
/// @li DF_MEM_INTLV_CHANNEL - [F17M00][F17M10][F17M20] spread accesses across all populated memory devices by channels.
/// @li DF_MEM_INTLV_NONE - Large scale interleaving is not used. However, bank interleaving within a DIMM may still be active. See APCB_TOKEN_CONFIG_CONFIG_E
/// NABLEBANKINTLV.
/// @li Auto - [F17M30] Interleaving is based upon the NUMA topology per NUMA Node Per Socket (NPSx). See reference
/// @li Auto  -  [F17M00][F17M10][F17M20] ABL decides the best setting according to this chart:
/// <table>
/// <caption>Memory Interleaving</caption>
/// <tr><th>Package<th>Channel Interleave<th>Die Interleave<th>Socket Interleave<th>Address Hashing<th>Interleave Bit
/// <tr><td>AM4<td>1<td>n/a<td>n/a<td>1<td>8
/// <tr><td>SP3<td>1<td>0<td>0<td>1<td>8
/// <tr><td>SP3r2-clients<td>1<td>1<td>n/a<td>0<td>8
/// <tr><td>SP3r2-server<td>1<td>0<td>0<td>1<td>8
/// <tr><td>APU w/iGPU<td>1<td>n/a<td>n/a<td>0<td>8
/// <tr><td>APU w/o iGPU<td>1<td>n/a<td>n/a<td>1<td>8
/// </table>
  #define APCB_TOKEN_UID_DF_MEM_INTERLEAVING                                0xCE0176EF  // uint8 //uint8
/// @ingroup DF
/** DF_MEM_INTERLEAVING_VALIDVAL
*  Value range for APCB_TOKEN_UID_DF_MEM_INTERLEAVING
*/
typedef enum {
  DF_MEM_INTLV_NONE     = 0,      ///< No interleave
  DF_MEM_INTLV_CHANNEL  = 1,      ///< Channel interleave
  DF_MEM_INTLV_DIE      = 2,      ///< Die interleave
  DF_MEM_INTLV_SOCKET   = 3,      ///< Socket interleave
  DF_MEM_INTLV_AUTO     = 7,      ///< Auto interleave
} DF_MEM_INTERLEAVING_VALIDVAL;
//#define macro(
//#define conts (A * B *C) ///< @VALUE:3

/// @ingroup DF
/// @brief DF CXL memory interleaving Enable
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL
  #define APCB_TOKEN_UID_DF_CXL_MEM_INTERLEAVING                            0x638709E6  // bool

/// @ingroup DF
/// @brief DF CXL sublink interleaving Enable
/// @details Type:BOOLEAN
/// @see BOOLEAN_ENABLE_1_DISABLE_0_AUTO_FF_VALIDVAL
  #define APCB_TOKEN_UID_DF_CXL_SUBLINK_INTERLEAVING                        0x66F1625A  // bool

/// @ingroup Memory
/// @brief Enable or Disable DRAM Boot Time Post Package Repair
/// @details Permitted Choices: (Type: List) (Default: Disable)
/// @li 0 = Disable
/// @li 1 = Enable
  #define APCB_TOKEN_UID_BOOT_TIME_POST_PACKAGE_REPAIR_ENABLE               0xE2291E4A

/// @ingroup DF
/// @brief [F17M30][F19M00] Specifies the starting address bit used for interleaving.
/// @brief Permitted Choices: (Type: List)(Default: DF_MEM_INTLV_SIZE_256BYTES)
/// @li DF_MEM_INTLV_SIZE_256BYTES
/// @li DF_MEM_INTLV_SIZE_512BYTES
/// @li DF_MEM_INTLV_SIZE_1KB. see note 2.
/// @li DF_MEM_INTLV_SIZE_2KB. see note 2.
/// @li DF_MEM_INTLV_SIZE_4KB. see notes 1 & 2. ([F19M00] only).
/// @li DF_MEM_INTLV_SIZE_AUTO - ABL uses = DF_MEM_INTLV_SIZE_256BYTES.
/// @li [F19M00]When 6-channel interleaving is in use, only DF_MEM_INTLV_SIZE_2KB and DF_MEM_INTLV_SIZE_4KB are supported, any other interleave size selectio
/// n will be forced to DF_MEM_INTLV_SIZE_2KB.
/// @li [F17M30][F19M00] If DF_MEM_INTLV_SIZE_1KB or DF_MEM_INTLV_SIZE_2KB or DF_MEM_INTLV_SIZE_4KB is selected, channel interleaving hash will be disabled.
  #define APCB_TOKEN_UID_DF_MEM_INTERLEAVING_SIZE                           0x2606C42E  //uint8
/// @ingroup DF
/** DF_MEM_INTLV_SIZE_VALIDVAL
*  Value range for APCB_TOKEN_UID_DF_MEM_INTERLEAVING_SIZE
*/
typedef enum {
  DF_MEM_INTLV_SIZE_256BYTES = 0,  ///< Interleave size 256 bytes
  DF_MEM_INTLV_SIZE_512BYTES = 1,  ///< Interleave size 512 bytes
  DF_MEM_INTLV_SIZE_1KB = 2,       ///< Interleave size 1024 bytes
  DF_MEM_INTLV_SIZE_2KB = 3,       ///< Interleave size 2048 bytes
  DF_MEM_INTLV_SIZE_4KB = 4,       ///< Interleave size 4096 bytes
  DF_MEM_INTLV_SIZE_AUTO = 7,      ///< Auto
} DF_MEM_INTLV_SIZE_VALIDVAL;

/// @ingroup DF
/** DF_DRAM_INTLV_SIZE_VAL
*  Value range for APCB_TOKEN_UID_DF_MEM_INTERLEAVING_SIZE
*/
typedef enum {
  DF_DRAM_INTLV_SIZE_256 = 0,     ///< Interleave size 256 bytes
  DF_DRAM_INTLV_SIZE_512 = 1,     ///< Interleave size 512 bytes
  DF_DRAM_INTLV_SIZE_1024 = 2,    ///< Interleave size 1024 bytes
  DF_DRAM_INTLV_SIZE_2048 = 3,    ///< Interleave size 2048 bytes
  DF_DRAM_INTLV_SIZE_4096 = 4,    ///< Interleave size 4096 bytes
} DF_DRAM_INTLV_SIZE_VAL;

/// @brief UMAMODE
/// @details Type:UINT8
/// @see UMAMODE_VAL
  #define APCB_TOKEN_UID_UMAMODE                                            0x1FB35295
/** UMAMODE_VAL
*  Value range for APCB_TOKEN_UID_UMAMODE
*/
typedef enum {
  UMAMODE_NONE = 0,        ///< UMA disabled
  UMAMODE_SPECIFIED = 1,   ///< UMA configuration will be pulled from other options
  UMAMODE_AUTO = 2,        ///< Auto
} UMAMODE_VAL;

/// @brief UMAVERSION
/// @details Type:UINT8
/// @see UMAVERSION_VAL
  #define APCB_TOKEN_UID_UMAVERSION                                         0xA00D4B57
/** UMAVERSION_VAL
*  Value range for APCB_TOKEN_UID_UMAVERSION
*/
typedef enum {
  UMAVERSION_LEGACY = 0,         ///< Legacy
  UMAVERSION_NON_LEGACY = 1,     ///< Non-legacy
  UMAVERSION_HYBRID_SECURE = 2,  ///< Hybrid secure
} UMAVERSION_VAL;

/// @brief UMADISPLAYRESOLUTION
/// @details Type:UINT8
/// @see UMADISPLAYRESOLUTION_VAL
  #define APCB_TOKEN_UID_UMADISPLAYRESOLUTION                               0x04CBD6B1
/** UMADISPLAYRESOLUTION_VAL
*  Value range for APCB_TOKEN_UID_UMADISPLAYRESOLUTION
*/
typedef enum {
  UMADISPLAYRESOLUTION_1920x1080_AND_BELOW = 0,  ///< 1920x1080 and below
  UMADISPLAYRESOLUTION_2560x1600 = 1,            ///< 2560x1600
  UMADISPLAYRESOLUTION_3840x2160 = 2,            ///< 3840x2160
} UMADISPLAYRESOLUTION_VAL;

/// @brief Control to enable/disable PMU training results display, currently, it supports to display the following PMU training results:
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li Receive Enable Delay
/// @li Read DQS to RxClk Delay
/// @li Write DQS Delay
/// @li Read DQ per-bit BDL delay
/// @li VrefDAC0 control for DQ Receiver
/// @li VrefDAC1 control for DQ Receiver (when DFE is enabled in DDR4)
/// @li TRUE - PMU training results output is enabled.
/// @li FALSE - No debug output is generated.
  #define APCB_TOKEN_UID_DISPLAY_PMU_TRAIN_RESULTS                          0x9E36A9D4  // boolean

/// @ingroup DF
/// @brief Under certain conditions, problems have been found using IOMMU when system DRAM is present just below the 1TB address boundary. The solution to date h
/// as been to make an IOMMU hole by marking multiple GB of DRAM as reserved. This variable controls whether or not the ABL tries to remap memory just bel
/// ow the 1TB boundary to be above the boundary. This solution allows the full contigent of DRAM to be available. It is worth noting that remapping is no
/// t possible in certain memory configurations. If the region that crosses the problematic boundary is based at system address 0x0000, remapping is not p
/// ossible. As an example, if DRAM interleaving is set to 'Die' and each socket has 1TB of DRAM, remapping is not possible.
/// @brief Permitted Choices: (Type: Boolean)(Default: False)
/// @li True - Memory under the 1TB IOMMU 'hole' is Remapped to high addresses above the 1TB boundary.
/// @li False - Memory under the 1TB IOMMU 'hole' is lost.
  #define APCB_TOKEN_UID_DF_REMAP_AT_1TB                                    0x35EE96F3  // uint8
/// @ingroup DF
/* DF_REMAP_AT_1TB_VALIDVAL
 *  Value range for APCB_TOKEN_UID_DF_REMAP_AT_1TB_VALUE
 */
typedef enum {
  DF_REMAP_AT_1TB_FALSE = 0,    ///< Memory under the 1TB IOMMU 'hole' is lost
  DF_REMAP_AT_1TB_TRUE,         ///< Memory under the 1TB IOMMU 'hole' is remapped to above 1TB boundary
  DF_REMAP_AT_1TB_AUTO = 0xFF   ///< Auto
} DF_REMAP_AT_1TB_VALIDVAL;

/// @ingroup FCH
/// @brief FCH_SMBUS_SPEED
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_FCH_SMBUS_SPEED                                    0x24473329

/// @ingroup Memory
/// @brief ABL PMU message Control
/// @details Control the total number of PMU debug messages.
/// @details Permitted Choices: (Type: List) (Default: 0xFF Auto)
/// @li 0x04 = Detailed debug messages (e.g. Eye delays)
/// @li 0x0A = Coarse debug messages (e.g. rank information)
/// @li 0xC8 = Stage completion
/// @li 0xC9 = Assertion messages
/// @li 0xFE = Firmware completion messages only
/// @li Auto = ABL decides the setting
  #define APCB_TOKEN_UID_MEM_TRAINING_HDTCTRL                               0xAF6D3A6F

/// @ingroup Memory
/// @brief This PCD token sets the maximum interval the system is allowed run without a memory training pass.
/// @brief Permitted Choices: (Type: Value)(Default: 30)
  #define APCB_TOKEN_UID_MEM_RESTORE_VALID_DAYS                             0x6BD70482

/// @ingroup Memory
/// @brief This token allows the memory clock to be further reduced from the platform maximum set by APCB_TOKEN_CONFIG_MEMORYBUSFREQUENCYLIMIT. This control will
/// be ignored if it tries to set a speed greater than the platform limit. This could be used as a temporary reduction for testing with new devices.
/// @brief Permitted Choices: (Type: List)(Default: Auto) Please consult the PPR specification for the product in use for supported frequencies.
/// @li Auto - use the limit set by APCB_TOKEN_CONFIG_MEMORYBUSFREQUENCYLIMIT.
/// @li 400MHz - DDR800_FREQUENCY
/// @li 667MHz - DDR1333_FREQUENCY
/// @li 800MHz - DDR1600_FREQUENCY
/// @li 933MHz - DDR1866_FREQUENCY
/// @li 1067MHz - DDR2133_FREQUENCY
/// @li 1200MHz - DDR2400_FREQUENCY
/// @li 1333MHz - DDR2667_FREQUENCY
/// @li 1467MHz - DDR2933_FREQUENCY
/// @li 1600MHz - DDR3200_FREQUENCY
/// @li 1633MHz - DDR3266_FREQUENCY
/// @li 1667MHz - DDR3333_FREQUENCY
/// @li 1700MHz - DDR3400_FREQUENCY
/// @li 1733MHz - DDR3466_FREQUENCY
/// @li 1767MHz - DDR3533_FREQUENCY
/// @li 1800MHz - DDR3600_FREQUENCY
  #define APCB_TOKEN_UID_CBS_CMN_MEM_SPEED_DDR4                             0xE0604CE9  // uint8 //uint8
/** MEM_SPEED_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_SPEED_DDR4
*/
typedef enum {
  MEM_SPEED_DDR4_AUTO = 0xFF,///<Auto
  MEM_SPEED_DDR4_667MHZ = 0x14,///<667MHz
  MEM_SPEED_DDR4_800MHZ = 0x18,///<800MHz
  MEM_SPEED_DDR4_933MHZ = 0x1C,///<933MHz
  MEM_SPEED_DDR4_1067MHZ = 0x20,///<1067MHz
  MEM_SPEED_DDR4_1200MHZ = 0x24,///<1200MHz
  MEM_SPEED_DDR4_1333MHZ = 0x28,///<1333MHz
  MEM_SPEED_DDR4_1400MHZ = 0x2A,///<1400MHz
  MEM_SPEED_DDR4_1467MHZ = 0x2C,///<1467MHz
  MEM_SPEED_DDR4_1533MHZ = 0x2E,///<1533MHz
  MEM_SPEED_DDR4_1600MHZ = 0x30,///<1600MHz
  MEM_SPEED_DDR4_1667MHZ = 0x32,///<1667MHz
  MEM_SPEED_DDR4_1733MHZ = 0x34,///<1733MHz
  MEM_SPEED_DDR4_1800MHZ = 0x36,///<1800MHz
  MEM_SPEED_DDR4_1867MHZ = 0x38,///<1867MHz
  MEM_SPEED_DDR4_1933MHZ = 0x3A,///<1933MHz
  MEM_SPEED_DDR4_2000MHZ = 0x3C,///<2000MHz
  MEM_SPEED_DDR4_333MHZ = 4,///<333MHz
  MEM_SPEED_DDR4_400MHZ = 6,///<400MHz
  MEM_SPEED_DDR4_533MHZ = 0xA,///<533MHz
  MEM_SPEED_DDR4_1050MHZ = 0x19,///<1050MHz
  MEM_SPEED_DDR4_1066MHZ = 0x1A,///<1066MHz
} MEM_SPEED_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TCL_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TCL_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TCL_DDR4                        0xB2D12C4E  // uint8 //uint8
/** MEM_TIMING_TCL_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TCL_DDR4
*/
typedef enum {
  MEM_TIMING_TCL_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TCL_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TCL_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TCL_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TCL_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TCL_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TCL_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TCL_DDR4_0FHCLK = 0xF,///<0Fh Clk
  MEM_TIMING_TCL_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TCL_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TCL_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TCL_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TCL_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TCL_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TCL_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TCL_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TCL_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TCL_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TCL_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TCL_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TCL_DDR4_1BHCLK = 0x1B,///<1Bh Clk
  MEM_TIMING_TCL_DDR4_1CHCLK = 0x1C,///<1Ch Clk
  MEM_TIMING_TCL_DDR4_1DHCLK = 0x1D,///<1Dh Clk
  MEM_TIMING_TCL_DDR4_1EHCLK = 0x1E,///<1Eh Clk
  MEM_TIMING_TCL_DDR4_1FHCLK = 0x1F,///<1Fh Clk
  MEM_TIMING_TCL_DDR4_20HCLK = 0x20,///<20h Clk
  MEM_TIMING_TCL_DDR4_21HCLK = 0x21,///<21h Clk
} MEM_TIMING_TCL_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRCDRD_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRCDRD_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRCDRD_DDR4                     0xB22E12F7  // uint8 //uint8
/** MEM_TIMING_TRCDRD_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRCDRD_DDR4
*/
typedef enum {
  MEM_TIMING_TRCDRD_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRCDRD_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRCDRD_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRCDRD_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRCDRD_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TRCDRD_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TRCDRD_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TRCDRD_DDR4_0FHCLK = 0xF,///<0Fh Clk
  MEM_TIMING_TRCDRD_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TRCDRD_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TRCDRD_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TRCDRD_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TRCDRD_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TRCDRD_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TRCDRD_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TRCDRD_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TRCDRD_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TRCDRD_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TRCDRD_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TRCDRD_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRCDRD_DDR4_1BHCLK = 0x1B,///<1Bh Clk
} MEM_TIMING_TRCDRD_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRCDWR_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRCDWR_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRCDWR_DDR4                     0xB3840F07  // uint8 //uint8
/** MEM_TIMING_TRCDWR_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRCDWR_DDR4
*/
typedef enum {
  MEM_TIMING_TRCDWR_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRCDWR_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRCDWR_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRCDWR_DDR4_0XACLK = 0xA,///<0xA Clk
  MEM_TIMING_TRCDWR_DDR4_0XBCLK = 0xB,///<0xB Clk
  MEM_TIMING_TRCDWR_DDR4_0XCCLK = 0xC,///<0xC Clk
  MEM_TIMING_TRCDWR_DDR4_0XDCLK = 0xD,///<0xD Clk
  MEM_TIMING_TRCDWR_DDR4_0XECLK = 0xE,///<0xE Clk
  MEM_TIMING_TRCDWR_DDR4_0XFCLK = 0xF,///<0xF Clk
  MEM_TIMING_TRCDWR_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TRCDWR_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TRCDWR_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TRCDWR_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TRCDWR_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TRCDWR_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TRCDWR_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TRCDWR_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TRCDWR_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TRCDWR_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TRCDWR_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TRCDWR_DDR4_1BHCLK = 0x1B,///<1Bh Clk
} MEM_TIMING_TRCDWR_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRP_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRP_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRP_DDR4                        0xA2D655C8  // uint8 //uint8
/** MEM_TIMING_TRP_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRP_DDR4
*/
typedef enum {
  MEM_TIMING_TRP_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRP_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRP_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRP_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRP_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TRP_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TRP_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TRP_DDR4_0FHCLK = 0xF,///<0Fh Clk
  MEM_TIMING_TRP_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TRP_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TRP_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TRP_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TRP_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRP_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TRP_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TRP_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TRP_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TRP_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TRP_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TRP_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TRP_DDR4_1BHCLK = 0x1B,///<1Bh Clk
} MEM_TIMING_TRP_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRAS_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRAS_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRAS_DDR4                       0x03E98A84  // uint8 //uint8
/** MEM_TIMING_TRAS_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRAS_DDR4
*/
typedef enum {
  MEM_TIMING_TRAS_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TRAS_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TRAS_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TRAS_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TRAS_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TRAS_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TRAS_DDR4_1BHCLK = 0x1B,///<1Bh Clk
  MEM_TIMING_TRAS_DDR4_1CHCLK = 0x1C,///<1Ch Clk
  MEM_TIMING_TRAS_DDR4_1DHCLK = 0x1D,///<1Dh Clk
  MEM_TIMING_TRAS_DDR4_1EHCLK = 0x1E,///<1Eh Clk
  MEM_TIMING_TRAS_DDR4_1FHCLK = 0x1F,///<1Fh Clk
  MEM_TIMING_TRAS_DDR4_20HCLK = 0x20,///<20h Clk
  MEM_TIMING_TRAS_DDR4_21HCLK = 0x21,///<21h Clk
  MEM_TIMING_TRAS_DDR4_22HCLK = 0x22,///<22h Clk
  MEM_TIMING_TRAS_DDR4_23HCLK = 0x23,///<23h Clk
  MEM_TIMING_TRAS_DDR4_24HCLK = 0x24,///<24h Clk
  MEM_TIMING_TRAS_DDR4_25HCLK = 0x25,///<25h Clk
  MEM_TIMING_TRAS_DDR4_26HCLK = 0x26,///<26h Clk
  MEM_TIMING_TRAS_DDR4_27HCLK = 0x27,///<27h Clk
  MEM_TIMING_TRAS_DDR4_28HCLK = 0x28,///<28h Clk
  MEM_TIMING_TRAS_DDR4_29HCLK = 0x29,///<29h Clk
  MEM_TIMING_TRAS_DDR4_2AHCLK = 0x2A,///<2Ah Clk
  MEM_TIMING_TRAS_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRAS_DDR4_2BHCLK = 0x2B,///<2Bh Clk
  MEM_TIMING_TRAS_DDR4_2CHCLK = 0x2C,///<2Ch Clk
  MEM_TIMING_TRAS_DDR4_2DHCLK = 0x2D,///<2Dh Clk
  MEM_TIMING_TRAS_DDR4_2EHCLK = 0x2E,///<2Eh Clk
  MEM_TIMING_TRAS_DDR4_2FHCLK = 0x2F,///<2Fh Clk
  MEM_TIMING_TRAS_DDR4_30HCLK = 0x30,///<30h Clk
  MEM_TIMING_TRAS_DDR4_31HCLK = 0x31,///<31h Clk
  MEM_TIMING_TRAS_DDR4_32HCLK = 0x32,///<32h Clk
  MEM_TIMING_TRAS_DDR4_33HCLK = 0x33,///<33h Clk
  MEM_TIMING_TRAS_DDR4_34HCLK = 0x34,///<34h Clk
  MEM_TIMING_TRAS_DDR4_35HCLK = 0x35,///<35h Clk
  MEM_TIMING_TRAS_DDR4_36HCLK = 0x36,///<36h Clk
  MEM_TIMING_TRAS_DDR4_37HCLK = 0x37,///<37h Clk
  MEM_TIMING_TRAS_DDR4_38HCLK = 0x38,///<38h Clk
  MEM_TIMING_TRAS_DDR4_39HCLK = 0x39,///<39h Clk
  MEM_TIMING_TRAS_DDR4_3AHCLK = 0x3A,///<3Ah Clk
} MEM_TIMING_TRAS_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRC_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRC_CTRL_DDR4                   0xBBC7849A  // uint8 in x86 data, not used in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TRC_DDR4
/// @details Type:UINT8
/// @li 0x1D~0x87 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRC_DDR4                        0x5B082A2B  // uint8 in data //uint8

/// @brief CBS_CMN_MEM_TIMING_TRRD_S_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRRD_S_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRRD_S_DDR4                     0x50B2D463  // uint8 //uint8
/** MEM_TIMING_TRRD_S_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRRD_S_DDR4
*/
typedef enum {
  MEM_TIMING_TRRD_S_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRRD_S_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TRRD_S_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TRRD_S_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TRRD_S_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TRRD_S_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRRD_S_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRRD_S_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRRD_S_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRRD_S_DDR4_0CHCLK = 0xC,///<0Ch Clk
} MEM_TIMING_TRRD_S_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRRD_L_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRRD_L_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRRD_L_DDR4                     0xFC23535E  // uint8 //uint8
/** MEM_TIMING_TRRD_L_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRRD_L_DDR4
*/
typedef enum {
  MEM_TIMING_TRRD_L_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRRD_L_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TRRD_L_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TRRD_L_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TRRD_L_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TRRD_L_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRRD_L_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRRD_L_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRRD_L_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRRD_L_DDR4_0CHCLK = 0xC,///<0Ch Clk
} MEM_TIMING_TRRD_L_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TFAW_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TFAW_CTRL_DDR4                  0xB36B7473  // uint8 in x86 data, used as 2nd level parent control in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TFAW_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TFAW_DDR4                       0xDE1D6178  // uint8 //uint8

/// @brief CBS_CMN_MEM_TIMING_TWTR_S_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TWTR_S_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWTR_S_DDR4                     0xEB6A9FE9  // uint8 //uint8
/** MEM_TIMING_TWTR_S_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWTR_S_DDR4
*/
typedef enum {
  MEM_TIMING_TWTR_S_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TWTR_S_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TWTR_S_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TWTR_S_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TWTR_S_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TWTR_S_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TWTR_S_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TWTR_S_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TWTR_S_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TWTR_S_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TWTR_S_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TWTR_S_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TWTR_S_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TWTR_S_DDR4_0EHCLK = 0xE,///<0Eh Clk
} MEM_TIMING_TWTR_S_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TWTR_L_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TWTR_L_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWTR_L_DDR4                     0x5782D479  // uint8 //uint8
/** MEM_TIMING_TWTR_L_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWTR_L_DDR4
*/
typedef enum {
  MEM_TIMING_TWTR_L_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TWTR_L_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TWTR_L_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TWTR_L_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TWTR_L_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TWTR_L_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TWTR_L_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TWTR_L_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TWTR_L_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TWTR_L_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TWTR_L_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TWTR_L_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TWTR_L_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TWTR_L_DDR4_0EHCLK = 0xE,///<0Eh Clk
} MEM_TIMING_TWTR_L_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TWR_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWR_CTRL_DDR4                   0x5C26F15B  // uint8 //uint8

/// @brief CBS_CMN_MEM_TIMING_TWR_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWR_DDR4                        0x4FC9F17E  // uint8 //uint8

/// @brief CBS_CMN_MEM_TIMING_TRCPAGE_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRCPAGE_CTRL_DDR4               0x2BC2CA69  // uint8 //uint8

/// @brief CBS_CMN_MEM_TIMING_TRCPAGE_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRCPAGE_DDR4                    0x1A82F1F6  // uint8 (new data), uint16 (old data in x86), uint8 in code. //uint8

/// @brief CBS_CMN_MEM_TIMING_TRDRD_SC_L_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_SC_L_CTRL_DDR4            0xC71A49AA  // uint8 in x86 data, 2nd level parent control in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TRDRD_SC_L_DDR4
/// @details Type:UINT8
/// @li 0x01~0x0F = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_SC_L_DDR4                 0x6A594A63  // uint8 //uint8

/// @brief CBS_CMN_MEM_TIMING_TWRWR_SC_L_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_SC_L_CTRL_DDR4            0x91371469  // uint8 , 2nd level parent control in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TWRWR_SC_L_DDR4
/// @details Type:UINT8
/// @li 0x01~0x3F = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_SC_L_DDR4                 0xA148AB5F  // uint8 in x86 data, uint32 varible in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TRFC_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRFC_CTRL_DDR4                  0x86ED48B5  // uint8 , 2nd level parent control in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TRFC2_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRFC2_CTRL_DDR4                 0x6D8E4884  // uint8 , 2nd level parent control in code //uint8

/// @brief CBS_CMN_MEM_TIMING_TRFC4_CTRL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRFC4_CTRL_DDR4                 0xFBB240FD  // uint8 , 2nd level parent control in code //uint8

/// @brief CBS_CMN_MEM_CTRLLER_PROC_ODT_DDR4
/// @details Type:UINT8
/// @see MEM_CTRLLER_PROC_ODT_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_PROC_ODT_DDR4                  0xE74CFD9B  // uint8 //uint8
/** MEM_CTRLLER_PROC_ODT_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_PROC_ODT_DDR4
*/
typedef enum {
  MEM_CTRLLER_PROC_ODT_DDR4_AUTO = 0xFF,///<Auto
  MEM_CTRLLER_PROC_ODT_DDR4_HIGHIMPEDANCE = 0,///<High Impedance
  MEM_CTRLLER_PROC_ODT_DDR4_480OHM = 1,///<480 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_240OHM = 2,///<240 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_160OHM = 3,///<160 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_120OHM = 8,///<120 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_96OHM = 9,///<96 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_80OHM = 10,///<80 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_686OHM = 11,///<68.6 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_60OHM = 0x18,///<60 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_533OHM = 0x19,///<53.3 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_48OHM = 0x1A,///<48 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_436OHM = 0x1B,///<43.6 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_40OHM = 0x38,///<40 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_369OHM = 0x39,///<36.9 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_343OHM = 0x3A,///<34.3 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_32OHM = 0x3B,///<32 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_30OHM = 0x3E,///<30 ohm
  MEM_CTRLLER_PROC_ODT_DDR4_282OHM = 0x3F,///<28.2 ohm
} MEM_CTRLLER_PROC_ODT_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_MBIST_TESTMODE
/// @details Type:UINT8
/// @see MEM_MBIST_TESTMODE_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_MBIST_TESTMODE                         0x4D0C053F  //uint8
/** MEM_MBIST_TESTMODE_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_MBIST_TESTMODE
*/
typedef enum {
  MEM_MBIST_TESTMODE_INTERFACEMODE = 0,///<Interface Mode
  MEM_MBIST_TESTMODE_DATAEYEMODE = 1,///<Data Eye Mode
} MEM_MBIST_TESTMODE_VALIDVAL;

/// @ingroup CCX
/// @brief CCX_P0_SETTING
/// @details Type:UINT8
/// @see CPU_PST_CUSTOM_P0_VALIDVAL
  #define APCB_TOKEN_UID_CCX_P0_SETTING                                     0x83CF6A10  //uint8
/// @ingroup CCX
/** CPU_PST_CUSTOM_P0_VALIDVAL
*   Value range for APCB_TOKEN_UID_CCX_P0_SETTING
*/
typedef enum {
  CPU_PST_CUSTOM_P0_CUSTOM = 1,///<Custom
  CPU_PST_CUSTOM_P0_AUTO = 2,///<Auto
} CPU_PST_CUSTOM_P0_VALIDVAL;

/// @ingroup CCX
/// @brief CCX_P0_FID
/// @details Type:UINT8
/// @li 0x10~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CCX_P0_FID                                         0x6B492DDA  //uint8

/// @ingroup CCX
/// @brief CCX_P0_DID
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CCX_P0_DID                                         0x09C5BCCC  //uint8

/// @ingroup CCX
/// @brief CCX_P0_VID
/// @details Type:UINT8
/// @li 0x00~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CCX_P0_VID                                         0x65370189  //uint8


/// @brief CBS_CMN_MEM_TIMING_TRDRD_SC_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRDRD_SC_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_SC_DDR4                   0x2E199CAA  //uint8
/** MEM_TIMING_TRDRD_SC_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_SC_DDR4
*/
typedef enum {
  MEM_TIMING_TRDRD_SC_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TRDRD_SC_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TRDRD_SC_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TRDRD_SC_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TRDRD_SC_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TRDRD_SC_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TRDRD_SC_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TRDRD_SC_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRDRD_SC_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRDRD_SC_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRDRD_SC_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRDRD_SC_DDR4_AUTO = 0xFF,///<Auto
} MEM_TIMING_TRDRD_SC_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRDRD_SD_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRDRD_SD_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_SD_DDR4                   0x6AD7647F  //uint8
/** MEM_TIMING_TRDRD_SD_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_SD_DDR4
*/
typedef enum {
  MEM_TIMING_TRDRD_SD_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TRDRD_SD_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TRDRD_SD_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TRDRD_SD_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TRDRD_SD_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TRDRD_SD_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TRDRD_SD_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRDRD_SD_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRDRD_SD_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRDRD_SD_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRDRD_SD_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRDRD_SD_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TRDRD_SD_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TRDRD_SD_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TRDRD_SD_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TRDRD_SD_DDR4_0FHCLK = 0xF,///<0Fh Clk
} MEM_TIMING_TRDRD_SD_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRDRD_DD_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRDRD_DD_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_DD_DDR4                   0xA1E46AFC  //uint8
/** MEM_TIMING_TRDRD_DD_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDRD_DD_DDR4
*/
typedef enum {
  MEM_TIMING_TRDRD_DD_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TRDRD_DD_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TRDRD_DD_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TRDRD_DD_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TRDRD_DD_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TRDRD_DD_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TRDRD_DD_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRDRD_DD_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRDRD_DD_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRDRD_DD_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRDRD_DD_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRDRD_DD_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TRDRD_DD_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TRDRD_DD_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TRDRD_DD_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TRDRD_DD_DDR4_0FHCLK = 0xF,///<0Fh Clk
} MEM_TIMING_TRDRD_DD_DDR4;

/// @brief CBS_CMN_MEM_TIMING_TWRWR_SC_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TWRWR_SC_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_SC_DDR4                   0x4DE9DD1F  //uint8
/** MEM_TIMING_TWRWR_SC_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_SC_DDR4
*/
typedef enum {
  MEM_TIMING_TWRWR_SC_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TWRWR_SC_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TWRWR_SC_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TWRWR_SC_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TWRWR_SC_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TWRWR_SC_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TWRWR_SC_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TWRWR_SC_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TWRWR_SC_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TWRWR_SC_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TWRWR_SC_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TWRWR_SC_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TWRWR_SC_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TWRWR_SC_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TWRWR_SC_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TWRWR_SC_DDR4_0FHCLK = 0xF,///<0Fh Clk
} MEM_TIMING_TWRWR_SC_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TWRWR_SD_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TWRWR_SD_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_SD_DDR4                   0xA95E4B3B  //uint8
/** MEM_TIMING_TWRWR_SD_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_SD_DDR4
*/
typedef enum {
  MEM_TIMING_TWRWR_SD_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TWRWR_SD_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TWRWR_SD_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TWRWR_SD_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TWRWR_SD_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TWRWR_SD_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TWRWR_SD_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TWRWR_SD_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TWRWR_SD_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TWRWR_SD_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TWRWR_SD_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TWRWR_SD_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TWRWR_SD_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TWRWR_SD_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TWRWR_SD_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TWRWR_SD_DDR4_0FHCLK = 0xF,///<0Fh Clk
} MEM_TIMING_TWRWR_SD_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TWRWR_DD_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TWRWR_DD_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_DD_DDR4                   0x9E720EC8  //uint8
/** MEM_TIMING_TWRWR_DD_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRWR_DD_DDR4
*/
typedef enum {
  MEM_TIMING_TWRWR_DD_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TWRWR_DD_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TWRWR_DD_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TWRWR_DD_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TWRWR_DD_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TWRWR_DD_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TWRWR_DD_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TWRWR_DD_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TWRWR_DD_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TWRWR_DD_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TWRWR_DD_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TWRWR_DD_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TWRWR_DD_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TWRWR_DD_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TWRWR_DD_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TWRWR_DD_DDR4_0FHCLK = 0xF,///<0Fh Clk
} MEM_TIMING_TWRWR_DD_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRDWR_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRDWR_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDWR_DDR4                      0x7636900E  //uint8
/** MEM_TIMING_TRDWR_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRDWR_DDR4
*/
typedef enum {
  MEM_TIMING_TRDWR_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TRDWR_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TRDWR_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TRDWR_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TRDWR_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TRDWR_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TRDWR_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRDWR_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRDWR_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRDWR_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRDWR_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TRDWR_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TRDWR_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TRDWR_DDR4_0FHCLK = 0xF,///<0Fh Clk
  MEM_TIMING_TRDWR_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TRDWR_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TRDWR_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TRDWR_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TRDWR_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TRDWR_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TRDWR_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TRDWR_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TRDWR_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TRDWR_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TRDWR_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TRDWR_DDR4_1BHCLK = 0x1B,///<1Bh Clk
  MEM_TIMING_TRDWR_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRDWR_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TRDWR_DDR4_1CHCLK = 0x1C,///<1Ch Clk
  MEM_TIMING_TRDWR_DDR4_1DHCLK = 0x1D,///<1Dh Clk
  MEM_TIMING_TRDWR_DDR4_1EHCLK = 0x1E,///<1Eh Clk
  MEM_TIMING_TRDWR_DDR4_1FHCLK = 0x1F,///<1Fh Clk
} MEM_TIMING_TRDWR_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TWRRD_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TWRRD_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRRD_DDR4                      0x8FD5A3D2  //uint8
/** MEM_TIMING_TWRRD_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TWRRD_DDR4
*/
typedef enum {
  MEM_TIMING_TWRRD_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TWRRD_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TWRRD_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TWRRD_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TWRRD_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TWRRD_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TWRRD_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TWRRD_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TWRRD_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TWRRD_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TWRRD_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TWRRD_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TWRRD_DDR4_0CH = 0xC,///<0Ch
  MEM_TIMING_TWRRD_DDR4_0DH = 0xD,///<0Dh
  MEM_TIMING_TWRRD_DDR4_0EH = 0xE,///<0Eh
  MEM_TIMING_TWRRD_DDR4_0FH = 0xF,///<0Fh
} MEM_TIMING_TWRRD_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TRTP_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TRTP_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRTP_DDR4                       0x88B9F33B  //uint8
/** MEM_TIMING_TRTP_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRTP_DDR4
*/
typedef enum {
  MEM_TIMING_TRTP_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TRTP_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TRTP_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TRTP_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TRTP_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TRTP_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TRTP_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TRTP_DDR4_5CLK = 0x5,///<5 Clk
  MEM_TIMING_TRTP_DDR4_6CLK = 0x6,///<6 Clk
  MEM_TIMING_TRTP_DDR4_7CLK = 0x7,///<7 Clk
  MEM_TIMING_TRTP_DDR4_0EHCLK = 0xE,///<0Eh Clk
} MEM_TIMING_TRTP_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TCWL_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TCWL_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TCWL_DDR4                       0xBDBA463D  //uint8
/** MEM_TIMING_TCWL_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TCWL_DDR4
*/
typedef enum {
  MEM_TIMING_TCWL_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TCWL_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TCWL_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TCWL_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TCWL_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TCWL_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TCWL_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TCWL_DDR4_0FHCLK = 0xF,///<0Fh Clk
  MEM_TIMING_TCWL_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TCWL_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TCWL_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TCWL_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TCWL_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TCWL_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TCWL_DDR4_16HCLK = 0x16,///<16h Clk
} MEM_TIMING_TCWL_DDR4_VALIDVAL;

/// @ingroup Memory
/// @brief CBS_CMN_MEM_DATA_BUS_CONFIG_CTL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0XFF_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_DATA_BUS_CONFIG_CTL_DDR4               0x9CC11046  //uint8

/// @brief CBS_CMN_MEM_CTRLLER_RTT_NOM_DDR4
/// @details Type:UINT8
/// @see MEM_CTRLLER_RTT_NOM_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_RTT_NOM_DDR4                   0xBFFF404B  //uint8
/** MEM_CTRLLER_RTT_NOM_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_RTT_NOM_DDR4
*/
typedef enum {
  MEM_CTRLLER_RTT_NOM_DDR4_RTT_NOMDISABLE = 0,///<Rtt_Nom Disable
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ4 = 1,///<RZQ/4
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ2 = 2,///<RZQ/2
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ6 = 3,///<RZQ/6
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ1 = 4,///<RZQ/1
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ5 = 5,///<RZQ/5
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ3 = 6,///<RZQ/3
  MEM_CTRLLER_RTT_NOM_DDR4_RZQ7 = 7,///<RZQ/7
  MEM_CTRLLER_RTT_NOM_DDR4_AUTO = 0xFF,///<Auto
} MEM_CTRLLER_RTT_NOM_DDR4_VALIDVAL;

/// @ingroup Memory
/// @brief CBS_CMN_MEM_CTRLLER_RTT_WR_DDR4
/// @details Type:UINT8
/// @see MEM_CTRLLER_RTT_WR_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_RTT_WR_DDR4                    0xA80353D7  //uint8
/** MEM_CTRLLER_RTT_WR_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_RTT_WR_DDR4
*/
typedef enum {
  MEM_CTRLLER_RTT_WR_DDR4_DYNAMICODTOFF = 0,///<Dynamic ODT Off
  MEM_CTRLLER_RTT_WR_DDR4_RZQ2 = 1,///<RZQ/2
  MEM_CTRLLER_RTT_WR_DDR4_RZQ1 = 2,///<RZQ/1
  MEM_CTRLLER_RTT_WR_DDR4_HIZ = 3,///<Hi-Z
  MEM_CTRLLER_RTT_WR_DDR4_RZQ3 = 4,///<RZQ/3
  MEM_CTRLLER_RTT_WR_DDR4_AUTO = 0xFF,///<Auto
} MEM_CTRLLER_RTT_WR_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_CTRLLER_RTT_PARK_DDR4
/// @details Type:UINT8
/// @see MEM_CTRLLER_RTT_PARK_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_RTT_PARK_DDR4                  0x58BF5D3E  //uint8
/** MEM_CTRLLER_RTT_PARK_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER_RTT_PARK_DDR4
*/
typedef enum {
  MEM_CTRLLER_RTT_PARK_DDR4_RTT_PARKDISABLE = 0,///<Rtt_PARK Disable
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ4 = 1,///<RZQ/4
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ2 = 2,///<RZQ/2
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ6 = 3,///<RZQ/6
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ1 = 4,///<RZQ/1
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ5 = 5,///<RZQ/5
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ3 = 6,///<RZQ/3
  MEM_CTRLLER_RTT_PARK_DDR4_RZQ7 = 7,///<RZQ/7
  MEM_CTRLLER_RTT_PARK_DDR4_AUTO = 0xFF,///<Auto
} MEM_CTRLLER_RTT_PARK_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_TIMING_TCKE_DDR4
/// @details Type:UINT8
/// @see MEM_TIMING_TCKE_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TCKE_DDR4                       0x5EF92FB0  //uint8
/** MEM_TIMING_TCKE_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TCKE_DDR4
*/
typedef enum {
  MEM_TIMING_TCKE_DDR4_AUTO = 0xFF,///<Auto
  MEM_TIMING_TCKE_DDR4_1CLK = 1,///<1 Clk
  MEM_TIMING_TCKE_DDR4_2CLK = 2,///<2 Clk
  MEM_TIMING_TCKE_DDR4_3CLK = 3,///<3 Clk
  MEM_TIMING_TCKE_DDR4_4CLK = 4,///<4 Clk
  MEM_TIMING_TCKE_DDR4_5CLK = 5,///<5 Clk
  MEM_TIMING_TCKE_DDR4_6CLK = 6,///<6 Clk
  MEM_TIMING_TCKE_DDR4_7CLK = 7,///<7 Clk
  MEM_TIMING_TCKE_DDR4_8CLK = 8,///<8 Clk
  MEM_TIMING_TCKE_DDR4_9CLK = 9,///<9 Clk
  MEM_TIMING_TCKE_DDR4_0AHCLK = 0xA,///<0Ah Clk
  MEM_TIMING_TCKE_DDR4_0BHCLK = 0xB,///<0Bh Clk
  MEM_TIMING_TCKE_DDR4_0CHCLK = 0xC,///<0Ch Clk
  MEM_TIMING_TCKE_DDR4_0DHCLK = 0xD,///<0Dh Clk
  MEM_TIMING_TCKE_DDR4_0EHCLK = 0xE,///<0Eh Clk
  MEM_TIMING_TCKE_DDR4_0FHCLK = 0xF,///<0Fh Clk
  MEM_TIMING_TCKE_DDR4_10HCLK = 0x10,///<10h Clk
  MEM_TIMING_TCKE_DDR4_11HCLK = 0x11,///<11h Clk
  MEM_TIMING_TCKE_DDR4_12HCLK = 0x12,///<12h Clk
  MEM_TIMING_TCKE_DDR4_13HCLK = 0x13,///<13h Clk
  MEM_TIMING_TCKE_DDR4_14HCLK = 0x14,///<14h Clk
  MEM_TIMING_TCKE_DDR4_15HCLK = 0x15,///<15h Clk
  MEM_TIMING_TCKE_DDR4_16HCLK = 0x16,///<16h Clk
  MEM_TIMING_TCKE_DDR4_17HCLK = 0x17,///<17h Clk
  MEM_TIMING_TCKE_DDR4_18HCLK = 0x18,///<18h Clk
  MEM_TIMING_TCKE_DDR4_19HCLK = 0x19,///<19h Clk
  MEM_TIMING_TCKE_DDR4_1AHCLK = 0x1A,///<1Ah Clk
  MEM_TIMING_TCKE_DDR4_1BHCLK = 0x1B,///<1Bh Clk
  MEM_TIMING_TCKE_DDR4_1CHCLK = 0x1C,///<1Ch Clk
  MEM_TIMING_TCKE_DDR4_1DHCLK = 0x1D,///<1Dh Clk
  MEM_TIMING_TCKE_DDR4_1EHCLK = 0x1E,///<1Eh Clk
  MEM_TIMING_TCKE_DDR4_1FHCLK = 0x1F,///<1Fh Clk
} MEM_TIMING_TCKE_DDR4_VALIDVAL;

/// @brief CBS_CMN_CLDO_VDDP_CTL
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_CLDO_VDDP_CTL                              0xE033C709  //uint8

/// @brief CBS_CMN_MEM_CTRLLER2_T_MODE_DDR4
/// @details Type:UINT8
/// @see MEM_CTRLLER2_T_MODE_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER2_T_MODE_DDR4                   0x0677966C  //uint8
/** MEM_CTRLLER2_T_MODE_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CTRLLER2_T_MODE_DDR4
*/
typedef enum {
  MEM_CTRLLER2_T_MODE_DDR4_1T = 0,///<1T
  MEM_CTRLLER2_T_MODE_DDR4_2T = 1,///<2T
  MEM_CTRLLER2_T_MODE_DDR4_AUTO = 0xFF,///<Auto
} MEM_CTRLLER2_T_MODE_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_CAD_BUS_TIMING_CTL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0XFF_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_TIMING_CTL_DDR4                0x264B7625  //uint8

/// @brief CBS_CMN_MEM_ADDR_CMD_SETUP_DDR4
/// @details Type:UINT8
/// @li 0x00~0x3F = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_ADDR_CMD_SETUP_DDR4                    0x1E974F51  //uint8

/// @brief CBS_CMN_MEM_CS_ODT_SETUP_DDR4
/// @details Type:UINT8
/// @li 0x00~0x3F = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CS_ODT_SETUP_DDR4                      0x3B1B99E9  //uint8

/// @brief CBS_CMN_MEM_CKE_SETUP_DDR4
/// @details Type:UINT8
/// @li 0x00~0x3F = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CKE_SETUP_DDR4                         0x37D13B99  //uint8

/// @brief CBS_CMN_MEM_CAD_BUS_DRV_STREN_CTL_DDR4
/// @details Type:UINT8
/// @see MANUAL_AUTO_0XFF_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_DRV_STREN_CTL_DDR4             0xDB047BEB  //uint8

/// @brief CBS_CMN_MEM_CAD_BUS_CLK_DRV_STREN_DDR4
/// @details Type:UINT8
/// @see MEM_CAD_BUS_CLK_DRV_STREN_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_CLK_DRV_STREN_DDR4             0xD8ADC426  //uint8
/** MEM_CAD_BUS_CLK_DRV_STREN_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_CLK_DRV_STREN_DDR4
*/
typedef enum {
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_AUTO = 0xFF,///<Auto
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_1200OHM = 0,///<120.0 Ohm
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_600OHM = 1,///<60.0 Ohm
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_400OHM = 3,///<40.0 Ohm
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_300OHM = 7,///<30.0 Ohm
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_240OHM = 15,///<24.0 Ohm
  MEM_CAD_BUS_CLK_DRV_STREN_DDR4_200OHM = 31,///<20.0 Ohm
} MEM_CAD_BUS_CLK_DRV_STREN_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4
/// @details Type:UINT8
/// @see MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4        0xF91E8072  //uint8
/** MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4
*/
typedef enum {
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_AUTO = 0xFF,///<Auto
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_1200OHM = 0,///<120.0 Ohm
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_600OHM = 1,///<60.0 Ohm
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_400OHM = 3,///<40.0 Ohm
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_300OHM = 7,///<30.0 Ohm
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_240OHM = 15,///<24.0 Ohm
  MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_200OHM = 31,///<20.0 Ohm
} MEM_CAD_BUS_ADDR_CMD_DRV_STREN_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4
/// @details Type:UINT8
/// @see MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4          0x7BBE9AF1  //uint8
/** MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4
*/
typedef enum {
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_AUTO = 0xFF,///<Auto
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_1200OHM = 0,///<120.0 Ohm
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_600OHM = 1,///<60.0 Ohm
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_400OHM = 3,///<40.0 Ohm
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_300OHM = 7,///<30.0 Ohm
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_240OHM = 15,///<24.0 Ohm
  MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_200OHM = 31,///<20.0 Ohm
} MEM_CAD_BUS_CS_ODT_DRV_STREN_DDR4_VALIDVAL;

/// @brief CBS_CMN_MEM_CAD_BUS_CKE_DRV_STREN_DDR4
/// @details Type:UINT8
/// @see MEM_CAD_BUS_CKE_DRV_STREN_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_CKE_DRV_STREN_DDR4             0x1014364F  //uint8
/** MEM_CAD_BUS_CKE_DRV_STREN_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_CAD_BUS_CKE_DRV_STREN_DDR4
*/
typedef enum {
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_AUTO = 0xFF,///<Auto
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_1200OHM = 0,///<120.0 Ohm
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_600OHM = 1,///<60.0 Ohm
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_400OHM = 3,///<40.0 Ohm
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_300OHM = 7,///<30.0 Ohm
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_240OHM = 15,///<24.0 Ohm
  MEM_CAD_BUS_CKE_DRV_STREN_DDR4_200OHM = 31,///<20.0 Ohm
} MEM_CAD_BUS_CKE_DRV_STREN_DDR4_VALIDVAL;
typedef enum {
  MEM_CTRLLER_DRAM_ECC_SYMBOL_SIZE_DDR4_X4 = 0,///<x4
  MEM_CTRLLER_DRAM_ECC_SYMBOL_SIZE_DDR4_X8 = 1,///<x8
  MEM_CTRLLER_DRAM_ECC_SYMBOL_SIZE_DDR4_X16 = 2,///<x16
  MEM_CTRLLER_DRAM_ECC_SYMBOL_SIZE_DDR4_AUTO = 0xFF,///<Auto
} MEM_CTRLLER_DRAM_ECC_SYMBOL_SIZE_DDR4_VALIDVAL;

/// @ingroup Memory
/// @brief This item Selects the operational mode for TSME (Transparent Secure Memory Encryption).
/// @brief Permitted Choices: (Type: Boolean)(Default: TRUE; [F19M00]:FALSE)
/// @li TRUE - ForeceEnc and AddrTweakEn will be set (see volume 4 of the PPR)
/// @li FALSE - This option is turned off.
  #define APCB_TOKEN_UID_MEM_TSME_ENABLE                                    0xD1FA6660  // bool

/// @brief MEM_ADDR_CMD_PARITY_ERROR_MAX_REPLAY_D
/// @details Type:UINT8
/// @li 0x00~0x3F = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_ADDR_CMD_PARITY_ERROR_MAX_REPLAY_DDR4  0x04E6A482

/// @brief MEM_ADDR_CMD_PARITY_RETRY_DDR4
/// @details Type:UINT8
/// @see MEM_ADDR_CMD_PARITY_RETRY_DDR4_VALIDVAL
  #define APCB_TOKEN_UID_CBS_CMN_MEM_ADDR_CMD_PARITY_RETRY_DDR4             0xBE8BEBCE
/** MEM_ADDR_CMD_PARITY_RETRY_DDR4_VALIDVAL
*   Value range for APCB_TOKEN_UID_CBS_CMN_MEM_ADDR_CMD_PARITY_RETRY_DDR4
*/
typedef enum {
  MEM_ADDR_CMD_PARITY_RETRY_DDR4_AUTO = 0xFF,///<Auto
  MEM_ADDR_CMD_PARITY_RETRY_DDR4_DISABLED = 0,///<Disabled
  MEM_ADDR_CMD_PARITY_RETRY_DDR4_ENABLED = 1,///<Enabled
} MEM_ADDR_CMD_PARITY_RETRY_DDR4_VALIDVAL;

/// @brief Specifies the Write CRC error maximum number of replays (retries). This option is only valid if the retry feature is enabled. Once the retries are exh
/// austed, a system fatal error will be logged in the MCA.
/// @brief Permitted Choices: (Type: value)(Default: 0x08)
/// @li 0x04..0x08 - number of retries to attempt.
/// @li Auto - ABL will decide the best setting.
  #define APCB_TOKEN_UID_CBS_CMN_MEM_WRITE_CRC_ERROR_MAX_REPLAY_DDR4        0x74A08BEC  //uint8

/// @ingroup CCX
/// @brief CPU_SYNC_FLOOD_ON_MCA
/// @details Type:UINT8
/// @li 0x00~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CPU_SYNC_FLOOD_ON_MCA                              0x96664127

/// @ingroup DF
/// @brief xGMI Link Configuration
/// @details Type:UINT8
/// @see DF_XGMI_LINK_CFG_VALIDVAL
  #define APCB_TOKEN_UID_DF3_XGMI2_LINK_CFG                                 0xB0B6AD3E  // uint8
  #define   DF3_XGMI2_LINK_CFG_2LINK  0
  #define   DF3_XGMI2_LINK_CFG_3LINK  1
  #define   DF3_XGMI2_LINK_CFG_4LINK  2
/// @ingroup DF
/** DF_XGMI_LINK_CFG_VALIDVAL
*   Value range for APCB_TOKEN_UID_DF3_XGMI2_LINK_CFG
*/
typedef enum {
  DF_XGMI_LINK_CFG_AUTO = 3,///<Auto
  DF_XGMI_LINK_CFG_2XGMILINKS = 0,///<2 xGMI Links
  DF_XGMI_LINK_CFG_3XGMILINKS = 1,///<3 xGMI Links
  DF_XGMI_LINK_CFG_4XGMILINKS = 2,///<4 xGMI Links
  DF_XGMI_LINK_CFG_4XGMILINKS_2P2G = 4, ///<4 xGMI Links (2G+2P)
} DF_XGMI_LINK_CFG_VALIDVAL;

/// @ingroup DF
/// @brief DF_2LINK_MAX_XGMI_SPEED
/// @details Type:UINT8
/// @see DF_XGMI_LINK_SPEED
  #define APCB_TOKEN_UID_DF_2LINK_MAX_XGMI_SPEED                            0xD19C6E80  // uint8

/// @ingroup DF
/// @brief The maximum xGMI2 speed for a 3-link system is determined by this token, in addition to hardware limitation.
/// @brief Permitted Choices: (Type: List)(Default: 13 Gbps)
/// @li 6.4 Gbps
/// @li 7.467 Gbps
/// @li 8.533 Gbps
/// @li 9.6 Gbps
/// @li 10.667 Gbps
/// @li 11 Gbps
/// @li 12 Gbps
/// @li 13 Gbps
/// @li 14 Gbps
/// @li 15 Gbps
/// @li 16 Gbps
/// @li 17 Gbps
/// @li 18 Gbps
/// @li 19 Gbps
/// @li 20 Gbps
/// @li 21 Gbps
/// @li 22 Gbps
/// @li 23 Gbps
/// @li 24 Gbps
/// @li 25 Gbps
  #define APCB_TOKEN_UID_DF_3LINK_MAX_XGMI_SPEED                            0x53BA449B  // uint8

/// @ingroup DF
/// @brief The maximum xGMI2 speed for a 4-link system is determined by this token, in addition to any hardware limitation.
/// @brief Permitted Choices: (Type: List)(Default: 13 Gbps)
/// @li 6.4 Gbps
/// @li 7.467 Gbps
/// @li 8.533 Gbps
/// @li 9.6 Gbps
/// @li 10.667 Gbps
/// @li 11 Gbps
/// @li 12 Gbps
/// @li 13 Gbps
/// @li 14 Gbps
/// @li 15 Gbps
/// @li 16 Gbps
/// @li 17 Gbps
/// @li 18 Gbps
/// @li 19 Gbps
/// @li 20 Gbps
/// @li 21 Gbps
/// @li 22 Gbps
/// @li 23 Gbps
/// @li 24 Gbps
/// @li 25 Gbps
  #define APCB_TOKEN_UID_DF_4LINK_MAX_XGMI_SPEED                            0x3F307CB3  // uint8
/// @ingroup DF
/* DF_XGMI_LINK_SPEED
 *  Value range for APCB_TOKEN_UID_DF_3LINK_MAX_XGMI_SPEED_VALUE
 *  Value range for APCB_TOKEN_UID_DF_4LINK_MAX_XGMI_SPEED_VALUE
 */
typedef enum {
  DF_XGMI_LINK_SPEED_640 = 0,       ///< 6.4 Gbps
  DF_XGMI_LINK_SPEED_746,           ///< 7.467 Gbps
  DF_XGMI_LINK_SPEED_853,           ///< 8.533 Gbps
  DF_XGMI_LINK_SPEED_960,           ///< 9.6 Gbps
  DF_XGMI_LINK_SPEED_1066,          ///< 10.667 Gbps
  DF_XGMI_LINK_SPEED_1100,          ///< 11 Gbps
  DF_XGMI_LINK_SPEED_1200,          ///< 12 Gbps
  DF_XGMI_LINK_SPEED_1300,          ///< 13 Gbps
  DF_XGMI_LINK_SPEED_1400,          ///< 14 Gbps
  DF_XGMI_LINK_SPEED_1500,          ///< 15 Gbps
  DF_XGMI_LINK_SPEED_1600,          ///< 16 Gbps
  DF_XGMI_LINK_SPEED_1700,          ///< 17 Gbps
  DF_XGMI_LINK_SPEED_1800,          ///< 18 Gbps
  DF_XGMI_LINK_SPEED_1900,          ///< 19 Gbps
  DF_XGMI_LINK_SPEED_2000,          ///< 20 Gbps
  DF_XGMI_LINK_SPEED_2100,          ///< 21 Gbps
  DF_XGMI_LINK_SPEED_2200,          ///< 22 Gbps
  DF_XGMI_LINK_SPEED_2300,          ///< 23 Gbps
  DF_XGMI_LINK_SPEED_2400,          ///< 24 Gbps
  DF_XGMI_LINK_SPEED_2500,          ///< 25 Gbps
  DF_XGMI_LINK_SPEED_2600,          ///< 26 Gbps
  DF_XGMI_LINK_SPEED_2700,          ///< 27 Gbps
  DF_XGMI_LINK_SPEED_2800,          ///< 28 Gbps
  DF_XGMI_LINK_SPEED_2900,          ///< 29 Gbps
  DF_XGMI_LINK_SPEED_3000,          ///< 30 Gbps
  DF_XGMI_LINK_SPEED_3100,          ///< 31 Gbps
  DF_XGMI_LINK_SPEED_3200,          ///< 32 Gbps
  DF_XGMI_LINK_SPEED_AUTO = 0xFF    ///< Auto
} DF_XGMI_LINK_SPEED;

/// @ingroup DF
/// @brief For the above Memory Interleaving option, this token specifies the number of NUMA nodes per socket.
/// @brief Permitted Choices (Type: List) (Default: NPS1)
/// @li NPS0
/// @li NPS1 - 1 NUMA node per socket.
/// @li NPS2 - use 2 NUMA nodes per socket.
/// @li NPS4 - use 4 NUMA nodes per socket.
  #define APCB_TOKEN_UID_DF_DRAM_NPS                                        0x2CF3DAC9  // uint8
/// @ingroup DF
/* DF_DRAM_NPS_VALIDVAL
 *  Value range for APCB_TOKEN_UID_DF_DRAM_NPS_VALUE
 */
typedef enum {
  DF_DRAM_NPS_0 = 0,      ///< No NUMA nodes
  DF_DRAM_NPS_1,          ///< 1 NUMA node per socket
  DF_DRAM_NPS_2,          ///< 2 NUMA node per socket
  DF_DRAM_NPS_4,          ///< 4 NUMA node per socket
  DF_DRAM_NPS_AUTO = 7    ///< Auto
} DF_DRAM_NPS_VALIDVAL;

/// @ingroup DF
/// @brief Enabling this token causes the highest memory channels to get assigned the lowest addresses in the system.
/// @brief Permitted Choices (Type: Boolean) (Default: FALSE)
/// @li FALSE - Disable memory map inversion.
/// @li TRUE - Use high channels for low address memory.
  #define APCB_TOKEN_UID_DF_INVERT_DRAM_MAP                                 0x6574B2C0  // uint8

/// @ingroup DF
/// @brief DF_SPF_WAY_CTRL
/// @details Type:UINT8
/// @li 0x00~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_DF_SPF_WAY_CTRL                                    0x71094904  // uint8

/// @ingroup DF
/// @brief DF_VC8_TRACING_TOK_ALLOC
/// @details Type:UINT8
/// @see DF_VC8_TRACING_TOK_ALLOC_VALIDVAL
  #define APCB_TOKEN_UID_DF_VC8_TRACING_TOK_ALLOC                                0xF9C587ED  // uint8
/// @ingroup DF
/** DF_VC8_TRACING_TOK_ALLOC_VALIDVAL
*  Value range for APCB_TOKEN_UID_DF_VC8_TRACING_TOK_ALLOC
*/
typedef enum {
  DF_VC8_TRACING_TOK_ALLOC_ALLOCATE = 0,///<Allocate
  DF_VC8_TRACING_TOK_ALLOC_AUTO = 1,///<Auto
} DF_VC8_TRACING_TOK_ALLOC_VALIDVAL;

/// @ingroup DF
/// @brief DF_DBGU_DRAM_TRACE
/// @details Type:UINT8
/// @li 0~3 = UINT8 Valid Range
  #define APCB_TOKEN_UID_DF_DBGU_DRAM_TRACE                                      0x1D0A4CB8  // uint8

/// @ingroup DF
/// @brief DF_IOM_TCB_DRAM_TRACE
/// @details Type:UINT8
/// @li 0~3 = UINT8 Valid Range
  #define APCB_TOKEN_UID_DF_IOM_TCB_DRAM_TRACE                                   0xA6C03643  // uint8

/// @ingroup DF
/// @brief DF_CS_TCB_DRAM_TRACE
/// @details Type:UINT8
/// @li 0~3 = UINT8 Valid Range
  #define APCB_TOKEN_UID_DF_CS_TCB_DRAM_TRACE                                    0x7D6B8E95  // uint8

/// @ingroup NBIO
/// @brief This control specifies which system GPIO is being used on the platform for reset of the BMC link. This will be used during the early initialization fo
/// r the BMC link.
/// @brief Permitted Choices: (Type: List)(Default: GPIO266)
/// @li Disable - ABL will not attempt to control early BMC link reset
/// @li GPIO26
/// @li GPIO266
/// @li GPIO267
/// @li GPIO27
  #define APCB_TOKEN_UID_PCIE_RESET_PIN_SELECT                              0x8C0B2DE9  // uint8

/// @ingroup NBIO
/// @brief UCLK DIV1 MODE
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_UCLK_DIV1_MODE                     0xF0947E37  // uint8

/// @ingroup NBIO
/// @brief VDDCR_SOC_VID
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_VDDCR_SOC_VID                      0x4CAD640C  // uint8

/// @ingroup NBIO
/// @brief FCLK FREQUENCY
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_FCLK_FREQUENCY                     0xF1823F38  // uint8

/// @ingroup NBIO
/// @brief FCLK FREQUENCY VALUE
/// @details Type:UINT8
/// @li 400~4000 = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_FCLK_FREQUENCY_VALUE               0x448E8DF2  // uint16

/// @brief UCLK FREQUENCY
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_UCLK_FREQUENCY                     0x75C8500B  // uint8

/// @ingroup NBIO
/// @brief MEMCLK FREQUENCY
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_MEMCLK_FREQUENCY                   0xA31DB44A  // uint8

/// @ingroup NBIO
/// @brief MEMCLK FREQUENCY VALUE
/// @details Type:UINT8
/// @li 400~4000 = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_MEMCLK_FREQUENCY_VALUE             0x4B7FA6A4  // uint16

/// @brief RCD F0RC0F nLadd (APCB override)
/// @details Type:UINT8
/// @li 0~4
/// @li 0xFF = Auto
  #define APCB_TOKEN_UID_MEM_TIMING_RCD_F0RC0F_NLADD_OVERRIDE               0xD155798A  // uint8

/// @brief Specifies whether or not the memory controller should activate parity checking on RDIMMs. The feature is invoked only if the RDIMMs present are all ca
/// pable of supporting the parity detection.
/// @brief Permitted Choices: (Type: List)(Default: Enabled)
/// @li Enabled
/// @li Disabled
/// @li Auto - ABL will decide the best setting.
  #define APCB_TOKEN_UID_RCD_PARITY                                         0x647D7662

/// @ingroup Memory
/// @brief RCD Command Address bus parity check
/// @details Permitted Choices (Type: List) (Default: 0x0 Disabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_RCD_PARITY                                     0xC4F7C913

/// @ingroup Memory
/// @brief Max allowed recursive replay attempts on RCD parity failure
/// @details Permitted Choices (Type: Numerical) (Default: 0x8)
/// @li 1 ~ 0x3f
  #define APCB_TOKEN_UID_MEM_MAX_RCD_PARITY_ERROR_REPLAY                    0x970204A2

/// @brief DRAM Address Command Parity Retry
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_DRAM_ADDRESS_COMMAND_PARITY_RETRY                  0x3E7C51F8

/// @brief Max Parity Error Replay
/// @details Type:UINT8
/// @li 0~0x3f = UINT8 Valid Range
  #define APCB_TOKEN_UID_MAX_PARITY_ERROR_REPLAY                            0xC9E9A1C9

/// @brief Write CRC enable
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_CTRLLER_WR_CRC                                 0x7D1C6E46

/// @brief DRAM Write CRC Enable and Retry Limit
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_DRAM_WRITE_CRC_ENABLE_AND_RETRY_LIMIT              0xC73A7692

/// @ingroup Memory
/// @brief Generates the CRC checksum on DRAM write
/// @details Permitted Choices (Type: List) (Default: 0x0 Disabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_WR_CRC_EN_DDR                                  0x750987BC

/// @ingroup Memory
/// @brief Max allowed recursive replay attempts on write CRC checksum failure
/// @details Permitted Choices (Type: Numerical) (Default: 0x8)
/// @li 1 ~ 0x3f
  #define APCB_TOKEN_UID_MEM_MAX_WRITE_CRC_ERROR_REPLAY                     0x7342FC94

/// @brief Max Write CRC Error Replay
/// @details Type:UINT8
/// @li 1~0x3f = UINT8 Valid Range
  #define APCB_TOKEN_UID_MAX_WRITE_CRC_ERROR_REPLAY                         0x6BB1ACF9

/// @ingroup Memory
/// @brief Generates the CRC checksum on DRAM read
/// @details Permitted Choices (Type: List) (Default: 0x0 Disabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_RD_CRC_EN_DDR                                  0x836033C6

/// @ingroup Memory
/// @brief Max allowed recursive replay attempts on read CRC checksum failure
/// @details Permitted Choices (Type: Numerical) (Default: 0x8)
/// @li 1 ~ 0x3f
  #define APCB_TOKEN_UID_MEM_MAX_READ_CRC_ERROR_REPLAY                      0x29ADC904

/// @ingroup Memory
/// @brief Allow recursive replay attempts on DRAM uncorrectable ECC failure
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_UECC_RETRY_EN_DDR                              0x4907B13A

/// @brief DRAM UECC Retry
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_UECC_RETRY                                         0x4AF3DE3C

/// @ingroup Memory
/// @brief Max allowed recursive replay attempts on DRAM UECC failure
/// @details Permitted Choices (Type: Numerical) (Default: 0x8)
/// @li 1 ~ 0x3f
  #define APCB_TOKEN_UID_MEM_MAX_UECC_ERROR_REPLAY                          0x3096B9A5

/// @brief PMU Pattern Bits Control
/// @details Type:UINT8
/// @see MANUAL_AUTO_0X00_VALIDVAL
  #define APCB_TOKEN_UID_MEM_CTRLLER_PMU_PATTERN_BITS_CTRL_DDR4             0x46D97109  // uint8

/// @brief PMU Pattern Bits
/// @details Type:UINT8
/// @li 0~0xA = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_CTRLLER_PMU_PATTERN_BITS_DDR4                  0xC2FBEAFF  // uint8

/// @ingroup DF
/// @brief DF_PSTATE_MODE_SELECT
/// @details Type:UINT8
/// @li 0x00~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_DF_PSTATE_MODE_SELECT                              0xAEB84B12  // uint8
/// @ingroup DF
/** APCB_TOKEN_UID_DF_PSTATE_MODE_SELECT_VALIDVAL
*   Value range for APCB_TOKEN_UID_DF_PSTATE_MODE_SELECT
*/
typedef enum {
  GNB_SMU_DF_PSTATE_MODE_SELECT_NORMAL = 0,///<Normal
  GNB_SMU_DF_PSTATE_MODE_SELECT_LIMIT_HIGHEST = 1,///<Limit Highest
  GNB_SMU_DF_PSTATE_MODE_SELECT_LIMITALL = 2,///<Limit All
  GNB_SMU_DF_PSTATE_MODE_SELECT_AUTO = 0xFF,///<Auto
} GNB_SMU_DF_PSTATE_MODE_SELECT_VALIDVAL;

/// @ingroup DF
/// @brief This item selects the XGMI TXEQ/RX vetting Mode.
/// @brief Permitted Choices: (Type: List)(Default: 0xFF)
/// @li 0xFF - (auto) -
/// @li 0 - TXEQ_Disabled.
/// @li 1 - TXEQ_Enabled_By_Lane.
/// @li 2 - TXEQ_Enabled_By_Link.
/// @li 3 - TXEQ_Enabled_By_Link_Plus_RX_Vetting.
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_MODE                                  0xADE79549  // uint8
/// @ingroup DF
/* DF_XGMI_TXEQ_MODE_VALIDVAL
 *  Value range for APCB_TOKEN_UID_DF_XGMI_TXEQ_MODE
 */
typedef enum {
  DF_XGMI_TXEQ_MODE_DISABLED = 0,
  DF_XGMI_TXEQ_MODE_ENABLED_BY_LANE,
  DF_XGMI_TXEQ_MODE_ENABLED_BY_LINK,
  DF_XGMI_TXEQ_MODE_ENABLED_BY_LINK_PLUS_RX_VETTING,
  DF_XGMI_TXEQ_MODE_AUTO = 0xFF
} DF_XGMI_TXEQ_MODE_VALIDVAL;

/// @ingroup FCH
/// @brief eSPI Operating Clock
/// @details Type:UINT8
/// @li 0~0x2 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_CLOCK                                         0x58077CCD  // uint8
/// @ingroup FCH
/** ESPI_CLOCKVAL
*   Value range for APCB_TOKEN_UID_ESPI_CLOCK
*/
typedef enum {
  ESPI_CLOCKVAL_16MHZ,            ///< 16.6MHz
  ESPI_CLOCKVAL_33MHZ,            ///< 33MHz
  ESPI_CLOCKVAL_66MHZ,            ///< 66MHz
} ESPI_CLOCKVAL;

/// @ingroup FCH
/// @brief eSPI IO mode
/// @details Type:UINT8
/// @li 0~0x2 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_IOMODE                                        0xF78C9C14  // uint8
/** ESPI_IOMODEVAL
*   Value range for APCB_TOKEN_UID_ESPI_IOMODE
*/
typedef enum {
  ESPI_IOMODEVAL_SINGLE,            ///< Single I/O
  ESPI_IOMODEVAL_DUAL,              ///< Dual I/O
  ESPI_IOMODEVAL_QUAD,              ///< Quad I/O
} ESPI_IOMODEVAL;

/// @brief eSPI Alert mode
/// @details Type:UINT8
/// @li 0~0x1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_ALERT_MODE                                    0xFED2F627  // uint8
/** ESPI_ALERT_MODE_VAL
*   Value range for APCB_TOKEN_UID_ESPI_ALERT_MODE
*/
typedef enum {
  ESPI_ALERT_MODE_VAL_NO_ALERT_PIN,            ///< I/O[1] pin is used to signal the Alert event
  ESPI_ALERT_MODE_VAL_ALERT_PIN,               ///< A dedicated Alert# pin is used to signal the Alert event
} ESPI_ALERT_MODE_VAL;

/// @brief eSPI IO Range0 Size
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE0_SIZE                                 0x506C4570  // uint8

/// @brief eSPI IO Range1 Size
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE1_SIZE                                 0x3308F8E4  // uint8

/// @brief eSPI IO Range2 Size
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE2_SIZE                                 0x8B45D00A  // uint8

/// @brief eSPI IO Range3 Size
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE3_SIZE                                 0xACAA0899  // uint8

/// @ingroup FCH
/// @brief eSPI Clock pin selection
/// @details Type:UINT8
/// @li 0~0x1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_CLOCK_PIN_SELECTION                           0x7762A4EF  // uint8
/** ESPI_CLOCK_PIN_SELECTION_VAL
*   Value range for APCB_TOKEN_UID_ESPI_CS_SELECTION
*/
typedef enum {
  ESPI_CLOCK_PIN_SELECTION_VAL_SPI_CLOCK,                ///< Use SPI clock
  ESPI_CLOCK_PIN_SELECTION_VAL_GPIO86,                  ///< Use GPIO86
} ESPI_CLOCK_PIN_SELECTION_VAL;

/// @ingroup FCH
/// @brief eSPI Data Pin set
/// @details Type:UINT8
/// @li 0~0x1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_DATA_SELECTION                                0x59994737  // uint8
/** ESPI_DATA_SELECTION_VAL
*   Value range for APCB_TOKEN_UID_ESPI_DATA_SELECTION
*/
typedef enum {
  ESPI_DATA_SELECTION_VAL_SPI_DATA1,               ///< Use SPI_DATA1
  ESPI_DATA_SELECTION_VAL_SPI_DATA2,               ///< Use SPI_DATA2
} ESPI_DATA_SELECTION_VAL;

/// @brief GPIO pin for eSPI Data Pin selection
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_DATA_SEL_GPIO                                 0x1773FBE3  // uint8

/// @brief GPIO pin for eSPI Data Pin Value
/// @details Type:UINT8
/// @li 0~0x1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_DATA_SEL_GPIO_OUTPUT                          0x69EC8C7E  // uint8
/** ESPI_DATA_SEL_GPIO_OUTPUT_VAL
*   Value range for APCB_TOKEN_UID_ESPI_DATA_SEL_GPIO_OUTPUT
*/
typedef enum {
  ESPI_DATA_SEL_GPIO_OUTPUT_VAL_LOW,               ///< Output Low
  ESPI_DATA_SEL_GPIO_OUTPUT_VAL_HIGH,              ///< Output High
} ESPI_DATA_SEL_GPIO_OUTPUT_VAL;

/// @brief eSPI CS pin selection
/// @details Type:UINT8
/// @li 0~0x1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_ESPI_CS_SELECTION                                  0x84EF2C57  // uint8
/** ESPI_CS_SELECTION_VAL
*   Value range for APCB_TOKEN_UID_ESPI_CS_SELECTION
*/
typedef enum {
  ESPI_CS_SELECTION_VAL_GPIO30,                ///< Use GPIO30 as eSPI_CS
  ESPI_CS_SELECTION_VAL_GPIO31,                ///< Use GPIO31 as eSPI_CS
} ESPI_CS_SELECTION_VAL;

/// @ingroup DF
/// @brief [F17M00][F17M10][F17M20]Controls whether or not the private memory regions (PSP, SMU and CC6) are at the top of last DRAM pair, the top of first DRAM
/// pair or distributed. Priviledged memory space will be reserved by UEFI BIOS to prohibit OS from using it, if customers wants to consolidate all reserv
/// ed memory to a single piece, they can choose to use CONSOLIDATED options.
/// @brief Permitted Choices: (Type: List)(Default: DF_SYS_STORAGE_AT_TOP_OF_MEM_DISTRIBUTED)
/// @li DF_SYS_STORAGE_AT_TOP_OF_MEM_DISTRIBUTED - For a system with 8-CCDs and 8 memory channels with full memory populated (no NVDIMM)
/// @li The privileged memory space of CCD0 and CCD1 will be consolided and located at top of specific memory region - region 0.
/// @li The privileged memory space of CCD2 and CCD3 will be consolided and located at top of specific memory region - region 1.
/// @li and so on through CCD6 and CCD7.
/// @li DF_SYS_STORAGE_AT_TOP_OF_MEM_CONSOLIDATED - For the 8-CCDs/8 memory channels with full memory populated (no NVDIMM) case:
/// @li All CCDs' privileged memory region on each socket will be consolidated and located at top of last dram region.
/// @li DF_SYS_STORAGE_AT_TOP_OF_1ST_MEM_CONSOLIDATED - consolidate all reserved/privileged memory in first dram pair.
/// @li DF_SYS_STORAGE_AT_TOP_OF_MEM_AUTO.
  #define APCB_TOKEN_UID_DF_SYS_STORAGE_AT_TOP_OF_MEM                       0x249E08D5  // uint8
/// @ingroup DF
/* DF_SYS_STORAGE_AT_TOP_OF_MEM_VALIDVAL
 *  Value range for APCB_TOKEN_UID_DF_SYS_STORAGE_AT_TOP_OF_MEM
 */
typedef enum {
  DF_SYS_STORAGE_AT_TOP_OF_MEM_DISTRIBUTED = 0,
  DF_SYS_STORAGE_AT_TOP_OF_MEM_CONSOLIDATED = 1,
  DF_SYS_STORAGE_AT_TOP_OF_1ST_MEM_CONSOLIDATED = 2,
  DF_SYS_STORAGE_AT_TOP_OF_MEM_AUTO = 0xFF
} DF_SYS_STORAGE_AT_TOP_OF_MEM_VALIDVAL;

/// @ingroup Memory
/// @brief The number of training failure/retries required before boot from recovery mode
/// @details Type:UINT8
/// @li 0~10 = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_OVERCLOCK_FAIL_CNT                             0xE5325C7B  //uint8

/// @brief MEM_CTRLLER_MR6_VREF_DQ_DDR4
/// @details Type:UINT8
/// @li 0x00~0x7F = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_CTRLLER_MR6_VREF_DQ_DDR4                       0x6649F4D1  // uint8

/// @brief MEM_CTRLLER_CPU_VREF_TRAINING_SEED_DDR
/// @details Type:UINT8
/// @li 0x00~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_CTRLLER_CPU_VREF_TRAINING_SEED_DDR4            0xC7389840  // uint8

/// @ingroup PSP
/// @brief SYSTEM_TPM_CONFIG
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_PSP_SYSTEM_TPM_CONFIG                              0x016DA8CA
/**
 *  @ingroup PSP
 *  SYSTEM_TPM_CONFIG_VAL
 *  Value range for APCB_TOKEN_UID_PSP_SYSTEM_TPM_CONFIG
 */
typedef enum {
  SYSTEM_TPM_CONFIG_DTPM     = 0x00, ///< dTPM
  SYSTEM_TPM_CONFIG_PSP_FTPM = 0x01, ///< PSP FTPM
  SYSTEM_TPM_CONFIG_HSP_FTPM = 0x02, ///< HSP FTPM
  SYSTEM_TPM_CONFIG_NONE     = 0xFF, ///< None of TPM
} SYSTEM_TPM_CONFIG_VAL;

/// @ingroup PSP
/// @brief SYSTEM_TPM_ALG_SMX
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_PSP_SYSTEM_TPM_ALG_SMX                             0x87EE0442
/**
 *  @ingroup PSP
 *  SYSTEM_TPM_ALG_VAL
 *  Value range for APCB_TOKEN_UID_PSP_SYSTEM_TPM_ALG_SMX
 */
typedef enum {
  SYSTEM_TPM_ALG_SMX_UNSUPPORTED = 0x00, ///< Does not support SM2, SM3 and SM4 crypto algorithms
  SYSTEM_TPM_ALG_SMX_SUPPORTED   = 0x01, ///< Fully support SM2, SM3 and SM4 crypto algorithms
} SYSTEM_TPM_ALG_VAL;

/// @ingroup CCX
/// @brief This token defines the action to be taken when there is a BIST failure.
/// @brief Permitted Choices: (Type: Value) (Default: 0)
/// @li 0: Do nothing
/// @li 1: Use Down-CCD feature to disable CCDs and attempt to boot with a minimum configuration.
  #define APCB_TOKEN_UID_ACTION_ON_BIST_FAILURE                             0xCBC2C0DD  // uint8

/// @brief RX_DAT_CHN_DLY
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_DBG_MEM_RX_DAT_CHN_DLY_DDR4                    0x1AB002CD  // uint8

/// @brief RX_DAT_CHN_DLY_CMN
/// @details Type:UINT8
/// @li 0~1 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_RX_DAT_CHN_DLY_DDR4                    0x9D35337D  // uint8

/// @brief MEM_DFI_MRL_MARGIN_DDR4
/// @details Type:UINT8
/// @li 0~31 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_DFI_MRL_MARGIN_DDR4                    0x5687D670  // uint8

/// @brief MEM_TIMING_A_RD_PTR_MP0_DDR4
/// @details Type:UINT8
/// @li 0~15 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_A_RD_PTR_MP0_DDR4               0x44D5B1BE  // uint8

/// @brief MEM_TIMING_A_RD_PTR_MP1_DDR4
/// @details Type:UINT8
/// @RANGE: 0~127 = UINT8 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_A_RD_PTR_MP1_DDR4               0xF7CA85CC  // uint8

/// @brief This item allows the user to limit the DDR4 DIMM activity. Normally this would be set by the DIMM SPD byte 7 [3:0] Maximum Activity Count (MAC) field.
/// @brief Permitted Choices: (Type: List)(Default: 0xff)
/// @li 0 = Untested MAC
/// @li 1 = 700 K
/// @li 2 = 600 K
/// @li 3 = 500 K
/// @li 4 = 400 K
/// @li 5 = 300 K
/// @li 6 = 200 K
/// @li 8 = Unlimited MAC
/// @li 0xff = Auto (use DIMM SPD Byte 7 bit [3:0])
  #define APCB_TOKEN_UID_MEM_MAXACTIVATECOUNT                               0x0853CDAA  // uint8

/// @ingroup Memory
/// @brief This item enables LRDIMM Refresh Staggering by adding a value to SrsmTiming0.TckSrx to delay Self-Refresh Exit by .33 * Trfc or 0.25 Trfc * UMC Insta
/// nce number modulo 4. The purpose is to prevent all of the DIMMs exiting self refresh at the same time, which may cause power surge or voltage droop.
/// @brief Permitted Choices: (Type: List)(Default: Disabled)
/// @li Disabled  -  This option is turned off.
/// @li Trfc/3 - one third of the Trfc time.
/// @li Trfc/4 - one fourth of the Trfc time.
  #define APCB_TOKEN_UID_MEM_SELF_REFRESH_EXIT_STAGGERING                   0xBC52E5F7  // uint8

/// @ingroup Miscellaneous
/// @brief This token sets the work load profile to be used. Please see the reference WorkLoads for more information. The reference document will detail the exac
/// t profiles and their related settings. Remember, using this profile will override any manual settings previously selected for the profile controls.
/// @brief Permitted Choices: (Type: List)(Default: Disabled)
  #define APCB_TOKEN_UID_WORKLOAD_PROFILE                                   0x22F4299F

/// @ingroup Memory
/// @brief Transparent Secure Memory Encryption
/// @details The UMC data encryption feature is used as part of overall SOC solutions for main memory encryption. The data is encrypted in the UMC prior to being
/// written to DRAM. The data is decrypted in the UMC when the data is returned on a DRAM read access.
/// @details Permitted Choices: (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 1 = Enabled
/// @li 0 = Disabled
  #define APCB_TOKEN_UID_MEM_TSME_ENABLE_DDR                                0xF0869ECA

/// @ingroup DF
/// @brief XGMI_CRC_SCALE
/// @details Type:UINT8
/// @li 0~21
  #define APCB_TOKEN_UID_CONFIG_XGMI_CRC_SCALE                              0x5174F4A0  // uint8

/// @ingroup DF
/// @brief XGMI_CRC_THRESHOLD
/// @details Type:UINT8
/// @li 0~0xFF
  #define APCB_TOKEN_UID_CONFIG_XGMI_CRC_THRESHOLD                          0xC3754DA2  // uint8

/// @ingroup Memory
/// @brief Token to choose ECC Symbol Size x4/x16
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 - x4
/// @li 2 - x16
/// @li Auto - ABL decides the setting
  #define APCB_TOKEN_UID_MEM_DRAM_ECC_SYMBOL_SIZE_DDR                       0xDB3E011A  //uint8

/// @ingroup Memory
/// @brief Power Down Enable
/// @details Enable or disable DDR power down mode
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li Auto = ABL will decide the best setting.
  #define APCB_TOKEN_UID_MEM_CTRLLER_POWER_DOWN_EN_DDR                      0x6E6B60F7  //uint8

/// @ingroup Memory
/// @brief This setting indicates whether or not to refresh the memories at twice the rate calculated or as indicated in the SPD information.
/// This faster frequency refresh is likely to be employed in cases where extended temperature support is desired or smaller geometry DRAM
/// technologies are utilized, improving reliability at higher temperatures at the cost of performance.
/// @brief Permitted Choices: (Type: List)(Default: 0)
/// @li 0  - Use the standard refresh rate. {Example: 7.8us}
/// @li 1  - Double the refresh rate (cut period in half). {Example: 3.9us}
  #define APCB_TOKEN_UID_DRAMDOUBLEREFRESHRATE                              0x44D40026  // uint8

/** MEM_DRAM_REFRESH_RATE_VALIDVAL
*   @ingroup Memory
*   Values for APCB_TOKEN_UID_DRAMDOUBLEREFRESHRATE
*/
typedef enum {
  MEM_DRAM_REFRESH_RATE_0 = 0, ///<7.8 usec
  MEM_DRAM_REFRESH_RATE_1 = 1, ///<3.9 usec
} MEM_DRAM_REFRESH_RATE_VALIDVAL;

/// @ingroup Memory
/// @brief Dram ODT impedance RTT_NOM_WR
/// @details Select the DRAMs On-die Termination impedance for RTT_NOM_WR
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 0 = RTT_OFF
/// @li 1 = RZQ (240)
/// @li 2 = RZQ/2 (120)
/// @li 3 = RZQ/3 (80)
/// @li 4 = RZQ/4 (60)
/// @li 5 = RZQ/5 (48)
/// @li 6 = RZQ/6 (40)
/// @li 7 = RZQ/7 (34)
  #define APCB_TOKEN_UID_MEM_RTT_NOM_WR_DDR                                 0xA085FAD9  //uint8

/// @ingroup Memory
/// @brief Dram ODT impedance RTT_NOM_RD
/// @details Select the DRAMs On-die Termination impedance for RTT_NOM_RD
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 0 = RTT_OFF
/// @li 1 = RZQ (240)
/// @li 2 = RZQ/2 (120)
/// @li 3 = RZQ/3 (80)
/// @li 4 = RZQ/4 (60)
/// @li 5 = RZQ/5 (48)
/// @li 6 = RZQ/6 (40)
/// @li 7 = RZQ/7 (34)
  #define APCB_TOKEN_UID_MEM_RTT_NOM_RD_DDR                                 0x668AC7E7  //uint8

/// @ingroup Memory
/// @brief Dram ODT impedance RTT_WR
/// @details Select the DRAMs On-die Termination impedance for RTT_WR
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 0 = RTT_OFF
/// @li 1 = RZQ (240)
/// @li 2 = RZQ/2 (120)
/// @li 3 = RZQ/3 (80)
/// @li 4 = RZQ/4 (60)
/// @li 5 = RZQ/5 (48)
/// @li 6 = RZQ/6 (40)
/// @li 7 = RZQ/7 (34)
  #define APCB_TOKEN_UID_MEM_RTT_WR_DDR                                     0x29AD741F  //uint8

/// @ingroup Memory
/// @brief Dram ODT impedance RTT_PARK
/// @details Select the DRAMs On-die Termination impedance for RTT_PARK
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 0 = RTT_OFF
/// @li 1 = RZQ (240)
/// @li 2 = RZQ/2 (120)
/// @li 3 = RZQ/3 (80)
/// @li 4 = RZQ/4 (60)
/// @li 5 = RZQ/5 (48)
/// @li 6 = RZQ/6 (40)
/// @li 7 = RZQ/7 (34)
  #define APCB_TOKEN_UID_MEM_RTT_PARK_DDR                                   0xDF253FE7  //uint8

/// @ingroup Memory
/// @brief Dram ODT impedance DQS_RTT_PARK
/// @details Select the DRAMs On-die Termination impedance for DQS_RTT_PARK
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 0 = RTT_OFF
/// @li 1 = RZQ (240)
/// @li 2 = RZQ/2 (120)
/// @li 3 = RZQ/3 (80)
/// @li 4 = RZQ/4 (60)
/// @li 5 = RZQ/5 (48)
/// @li 6 = RZQ/6 (40)
/// @li 7 = RZQ/7 (34)
  #define APCB_TOKEN_UID_MEM_RTT_PARK_DQS_DDR                               0xFFEDC3F7  //uint8

/// @ingroup Memory
/// @brief Processor ODT impedance
/// @details Select the ODT impedance for all DBYTE IOs
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 0x00 = High Impedance
/// @li 0x01 = 480 ohm
/// @li 0x02 = 240 ohm
/// @li 0x03 = 160 ohm
/// @li 0x08 = 120 ohm
/// @li 0x09 = 96 ohm
/// @li 0x0A = 80 ohm
/// @li 0x0B = 68.6 ohm
/// @li 0x18 = 60 ohm
/// @li 0x19 = 53.3 ohm
/// @li 0x1A = 48 ohm
/// @li 0x1B = 43.6 ohm
/// @li 0x38 = 40 ohm
/// @li 0x39 = 36.9 ohm
/// @li 0x3A = 34.3 ohm
/// @li 0x3B = 32 ohm
/// @li 0x3E = 30 ohm
/// @li 0x3F = 28.2 ohm
  #define APCB_TOKEN_UID_MEM_PROC_ODT_DDR                                   0xB88F40C8  //uint8

/// @ingroup Memory
/// @brief This item allow the user to customize refresh controls. Please see the PPR, ref: UMC::CH::SpazCtrl::SubUrgRefLowerBound. Note: SubUrgRefLowerBound MUS
/// T be less than or equal to UrgRefLimit per PPR documentation.
/// @brief Permitted Choices: (Type: value)(Default: 4)
/// @li 1..6 - see PPR for details.
  #define APCB_TOKEN_UID_MEM_SUBURGREFLOWERBOUND                            0xE7562AB6

/// @ingroup Memory
/// @brief This item allow the user to customize refresh controls. Please see the PPR, ref: UMC::CH::SpazCtrl::UrgRefLimit. Some customers may choose to use thes
/// e new options as override to {1,1} or {1,2} to reduce the likelihood of TRRespass type exploits.
/// @brief Permitted Choices: (Type: value)(Default: 6)
/// @li 1..6 - see PPR for details.
  #define APCB_TOKEN_UID_MEM_URGREFLIMIT                                    0x133332DF

/// @ingroup Memory
/// @brief Dram DQ drive strengths
/// @details Selects the Dram Pull-up and Pull-Down Output Driver Impedance for all DQ and DMI IOs
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li Auto = ABL will decide the best setting.
/// @li 2 = 48 ohm
/// @li 1 = 40 ohm
/// @li 0 = 34 ohm
  #define APCB_TOKEN_UID_MEM_DRV_IMP_DDR                                    0xC4765F1F

/// @ingroup Memory
/// @brief Disable Memory Error Injection
/// @details Specifies if UMC error injection configuration writes are disabled.
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = False
/// @li 1 = True
/// @li Auto = ABL will decide the best setting.
  #define APCB_TOKEN_UID_MEM_ECC_DIS_ERR_INJECTION_DDR                      0xF77A05F1

/// @ingroup Memory
/// @brief: Maximum number of DIMMs that can power on at the same time.
/// @brief: Permitted Choices: (Type: Numerical)
/// @li 1~24
  #define APCB_TOKEN_UID_MEM_MAX_DIMM_STAGGER_DDR                           0x8EB007CF

/// @ingroup Memory
/// @brief: Amount of time to wait between powering on DIMMs in milliseconds.
/// @brief: Permitted Choices: (Type: Numerical)
/// @li 0~0xFF
  #define APCB_TOKEN_UID_MEM_PMIC_STAGGER_DDR                               0xF1E345D7

/// @ingroup Memory
/// @brief PMIC Fault Recovery
/// @details Permitted Choices (Type: List) (Default: Always)
/// @li 0 = Always, PMIC will ignore previous boot errors. No channel disabled
/// @li 1 = Never, PMIC disables the channel with errors from previous boot
/// @li 2 = Once, PMIC will ignore the previous boot errors once. More than once channel will be disabled
  #define APCB_TOKEN_UID_MEM_PMIC_PERSISTENT_ERROR_DDR                      0x014DF1CE

/// @ingroup Memory
/// @brief PMIC Operation Mode
/// @details Programmable mode allows certain PMIC registers to be programmed after VR enable else they will be in secure mode
/// @li 0 = Secure Mode
/// @li 1 = Programmable Mode
  #define APCB_TOKEN_UID_MEM_PMIC_OPERATION_MODE_DDR                        0x1A56CBF4

/// @brief RESERVED_DRAM_MODULE_DRTM
/// @details Type:UINT8
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_RESERVED_DRAM_MODULE_DRTM                          0xB051E421

/// @ingroup Memory
/// @brief DRAM Survives Warm Reset
/// @details If enabled, on a warm reset the DRAM content is preserved. Training values are saved & retrieved.
/// @details Permitted Choices (Type: List) (Default: Disabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
  #define APCB_TOKEN_UID_MEM_DRAM_SURVIVES_WARM_RESET_DDR                   0x7B17577C

/// @ingroup Memory
/// @brief DRAM PDA Enumerate ID Programming Mode
/// @details Type:UINT8
/// @see MEM_DRAM_PDA_ENUM_ID_PROG_MODE_VALIDVAL
  #define APCB_TOKEN_UID_MEM_DRAM_PDA_ENUM_ID_PROG_MODE_DDR                 0x2BF8781F

/**
*   @ingroup Memory
*   Values for APCB_TOKEN_UID_MEM_DRAM_PDA_ENUM_ID_PROG_MODE_DDR
*/
typedef enum {
  MEM_DRAM_PDA_ENUM_ID_PROG_MODE_DDR_AUTO     = 0xFF, ///<Auto
  MEM_DRAM_PDA_ENUM_ID_PROG_MODE_DDR_TOGGLING = 0,    ///<Continuous DQS toggling PDA enumeration mode
  MEM_DRAM_PDA_ENUM_ID_PROG_MODE_DDR_LEGACY   = 1,    ///<Legacy PDA enumeration mode
} MEM_DRAM_PDA_ENUM_ID_PROG_MODE_VALIDVAL;

/// @brief APML_SBTSI_SECONDARY_MODE
/// @details Type:UINT8
/// @see 0 - i3c; 1 = i2c
  #define APCB_TOKEN_UID_APML_SBTSI_SECONDARY_MODE                              0xB6661742

/// @ingroup Memory
/// @brief Address XOR after ECC
/// @details In order to provide data integrity when data is returned from the wrong address, UMC will hash the data after ECC with the normalized address.
/// @details Permitted Choices (Type: List)
/// @li 1 = Enabled
/// @li 0 = Disabled
/// @li Auto = ABL will decide the best setting.
  #define APCB_TOKEN_UID_MEM_ADDR_XOR_AFTER_ECC_DDR                         0xAD4841A2

/// @ingroup DF
/// @brief XGMI Preset Control
/// @details Type:UINT8
/// @see BOOLEAN_ENABLE_1_DISABLE_0_VALIDVAL
  #define APCB_TOKEN_UID_DF_XGMI_PRESET_CONTROL                             0x21AA0C13

/// @ingroup DF
/// @brief XGMI AC/DC Coupled Link Control
/// @details Type:UINT8
/// @li 0~0xFF = UINT8 Valid Range
/// @li Bit0 for socket 0 link 0
/// @li Bit1 for socket 0 link 1
/// @li Bit2 for socket 0 link 2
/// @li Bit3 for socket 0 link 3
/// @li Bit4 for socket 1 link 0
/// @li Bit5 for socket 1 link 1
/// @li Bit6 for socket 1 link 2
/// @li Bit7 for socket 1 link 3
/// @li Valid value: 0: AC coupled 1: DC coupled
  #define APCB_TOKEN_UID_XGMI_AC_DC_COUPLED_LINK                            0xA7AE5713

/// @ingroup Memory
/// @brief DRAM Refresh Management (RFM)
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = Disabled
/// @li 1 = Enabled
/// @li 2 = Force Enabled, enabled regardless of support
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_REFRESH_MANAGEMENT_DDR                         0x4136CE56

/// @ingroup Memory
/// @brief RAA Initial Management Threshold (RAAIMT)
/// @details Specifies the Rolling Accumulated ACT accumulated activate initial management threshold
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 32 = threshold value
/// @li 40 = threshold value
/// @li 48 = threshold value
/// @li 56 = threshold value
/// @li 64 = threshold value
/// @li 72 = threshold value
/// @li 80 = threshold value
/// @li Auto = ABL choose the lowest supported value from DIMM SPD
  #define APCB_TOKEN_UID_MEM_RAAIMT_DDR                                     0x139193BC

/// @ingroup Memory
/// @brief RAA Maximum Management Threshold (RAAMMT)
/// @details Specifies the RAAIMT multiplier for the maximum management threshold
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 2 = 3x
/// @li 3 = 4x
/// @li 4 = 5x
/// @li 5 = 6x
/// @li Auto = ABL choose the lowest supported value from DIMM SPD
  #define APCB_TOKEN_UID_MEM_RAAMMT_DDR                                     0xC6CEDA5B

/// @ingroup Memory
/// @brief RAA Refresh Decrement Multiplier
/// @details Specifies the RAAIMT multiplier for the REF decrement
/// @details Permitted Choices (Type: List) (Default: 0xFF Auto)
/// @li 0 = 0.5x
/// @li 1 = 1x
/// @li Auto = ABL to determine the best setting
  #define APCB_TOKEN_UID_MEM_RAA_DEC_REF_MULT_DDR                           0xEDBE9A03

/// @cond INT
#define MEM_HEALING_BIST_ENABLE_PMU_MEM_BIST              BIT0
#define MEM_HEALING_BIST_ENABLE_SELF_HEALING_BIST         BIT1
/// @endcond

/// @ingroup Memory
/// @brief DDR Healing BIST Enable BitMask
/// @brief New DDR5 DIMMs have the ability to 'Self Heal'. JEDEC has defined a standard (Committee: JC42.3B) where the DIMM performs a MBIST self test then performs
/// a hard repair for areas found to be problematic. The BIOS can also perform a similar test targeting repairs with the Post Package Repair (PPR) process.
/// This item enables a full memory test. Please note that this is a memory content test and is separate and distinct from the MBIST test of Interface
/// and Data Eye.
/// @brief Caution: This testing will increase the boot time.
/// @brief Permitted Choices: (Type: List)(Default: 0)
/// @li 0 - Disabled
/// @li 1 - PMU Mem BIST, this uses PMU firmware to test memory on all channels simultaneously. Failing memory will be repaired using soft or hard PPR depending
/// on the PPR configuration. The test will take ~6 seconds to ~47 seconds per memory rank per pattern.(depending on the algorithms it uses, see PMU Mem
/// BIST Algorithm Bitmask)
/// @li 2 - Self-Healing Mem BIST, this runs the JEDEC DRAM self healing, if the device and DIMM support the feature. The DRAM will do a hard repair for faili
/// ng memory. The test will take ~10 seconds per memory rank per channel.
/// @li 3 - PMU and Self-Healing Mem BIST, this option runs the PMU Mem BIST then the Self-Healing Mem BIST tests sequentially.
  #define APCB_TOKEN_UID_MEM_HEALING_BIST_ENABLE_BITMASK_DDR                0x552205A3

/// @cond INT
#define MEM_HEALING_BIST_REPAIR_TYPE_SOFT_REPAIR                 0
#define MEM_HEALING_BIST_REPAIR_TYPE_HARD_REPAIR                 1
#define MEM_HEALING_BIST_REPAIR_TYPE_NO_REPAIR                   2
/// @endcond

/// @ingroup Memory
/// @brief DDR Healing BIST Repair Type
/// @brief When PMU Mem BIST is enabled, this control sets the type of Post Package Repair to be invoked.
/// @brief Permitted Choices: (Type: List)(Default: 0)
/// @li 0 - Soft Repair
/// @li 1 - Hard Repair
/// @li 2 - No Repair
  #define APCB_TOKEN_UID_MEM_HEALING_BIST_REPAIR_TYPE_DDR                   0x9BF85C70

/// @ingroup Memory
/// @brief DDR Healing BIST Max Bank Fails
/// @details When PMU Mem BIST is enabled, this control sets the maximum number of fails detected by the memory healing BIST in a single bank. If this threshold is
/// exceeded in a single bank, the DIMM will fail the test and be removed from the memory map.
/// @details Permitted Choices: (Type: value) (Default: 3)
/// @li 0~0xFF = UINT8 Valid Range
  #define APCB_TOKEN_UID_MEM_HEALING_BIST_MAX_BANK_FAILS_DDR                0xA94A3A01

/// @ingroup Memory
/// @brief ABL Memory Population Message Control
/// @details This feature controls the behavior for memory configurations that do not follow SP5 Memory Population Guidelines.
/// @details Permitted Choices (Type: List) (Default: Warning message)
/// @li 0 = Warning Message, shows warning messages if Memory channel configuration does NOT follow SP5 Memory Population Guidelines
/// @li 1 = Fatal error, show the messages and halt the system.
  #define APCB_TOKEN_UID_MEM_POPULATION_MSG_CTRL                            0x2CE124DC

/// @ingroup Memory
/// @brief MBIST Data Eye Silent Execution
/// @details Execute MBIST Data Eye silently without ABL log output
/// @details Permitted Choices (Type: List) (Default: Disabled)
/// @li 0 = Disabled
/// @li 1 = Enabled
  #define APCB_TOKEN_UID_MEM_MBIST_DATAEYE_SILENT_EXECUTION_DDR             0x8EE6E78F

/// @ingroup Memory
/// @brief ABL DDR DIMM SPD CRC verify
/// @details This feature controls the DDR DIMM SPD CRC verify or not
/// @details Permitted Choices (Type: List) (Default: 0 Disabled)
/// @li 0 = Skip verifing DDR DIMM SPD CRC
/// @li 1 = ABL verify DDR DIMM SPD CRC
  #define APCB_TOKEN_UID_MEM_SPD_VERIFY_CRC                                 0x87B6D2D4

/// @ingroup DF
/// @brief CCD Bandwidth Balance Throttle Level
/// @details Type:UINT8
/// @details Defines the percentage of "CCM RSPQ Buffer Count" to be allowed for each of Sdp0 and Sdp1 port of CCD.
/// Allowed Values: Level 0 = 100%, Level 1 = 90%, Level 2 = 75%, Level 3 = 67%, Level4 = 50%
/// The bandwidth percentage of RSPQ Buffer Count specified by this level is applied to DF::CCMRspQBufCnt[Sdp0RspQBufCnt]
/// and DF::CCMRspQBufCnt[Sdp1RspQBufCnt], in order to calculate and set DF::CCMRspQBufCnt[RspQMaxCnt].
/// @see DF_CCD_BW_THROTTLE_LV_VALIDVAL
  #define APCB_TOKEN_UID_DF_CCD_BW_THROTTLE_LV                              0xD2886DC9

/** DF_CCD_BW_THROTTLE_LV_VALIDVAL
*   Value range for APCB_TOKEN_UID_DF_CCD_BW_THROTTLE_LV
*/
typedef enum {
  DF_CCD_BW_THROTTLE_LV0,              ///<Level 0
  DF_CCD_BW_THROTTLE_LV1,              ///<Level 1
  DF_CCD_BW_THROTTLE_LV2,              ///<Level 2
  DF_CCD_BW_THROTTLE_LV3,              ///<Level 3
  DF_CCD_BW_THROTTLE_LV4,              ///<Level 4
  DF_CCD_BW_THROTTLE_LV_AUTO  = 0xFF,  ///<Auto
} DF_CCD_BW_THROTTLE_LV_VALIDVAL;

/// @ingroup Memory
/// @brief ABL dilslay PMU training results to console
/// @details This feature controls ABL display PMU training results to console or not
/// @details Permitted Choices (Type: List)
/// @li 0 = Do not dilslay PMU training results to console, either pass or fail
/// @li 1 = Dilslay PMU training results to console
  #define APCB_TOKEN_UID_MEM_DISPLAY_PMU_TRAINING_RESULT                    0xB8A63EBA

/// @brief: DF_PF_ORGANIZATION
/// @details Type:UINT8
/// @see DF_PF_ORGANIZATION_VALIDVAL
  #define APCB_TOKEN_UID_DF_PF_ORGANIZATION                                 0x868E73F0  // unit8

/**
*   Value range for APCB_TOKEN_UID_DF_PF_ORGANIZATION
*/
typedef enum {
  DF_PF_ORGANIZATION_AUTO        = 0xFF,  ///< Auto
  DF_PF_ORGANIZATION_DEDICATED   = 0,     ///< Dedicated
  DF_PF_ORGANIZATION_SHARED      = 2,     ///< Shared
} DF_PF_ORGANIZATION_VALIDVAL;

/// @brief: DDR, PMIC, override register 0x1A
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_1A                                    0x00FF717D

/// @brief: DDR, PMIC, override register 0x1B
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_1B                                    0xFB1397F4

/// @brief: DDR, PMIC, override register 0x21
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_21                                    0x04F20275

/// @brief: DDR, PMIC, override register 0x23
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_23                                    0x72BAA0F6

/// @brief: DDR, PMIC, override register 0x25
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_25                                    0x318FF740

/// @brief: DDR, PMIC, override register 0x27
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_27                                    0x428E69D3

/// @brief: DDR, PMIC, override register 0x2B
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_2B                                    0x911F6B4F

/// @brief: DDR, PMIC, override register 0x2C
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_2C                                    0x10030EF7

/// @brief: DDR, PMIC, override register 0x2D
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_2D                                    0x6BB62844

/// @brief: DDR, PMIC, override register 0x32
/// @details Type:UINT8
  #define APCB_TOKEN_UID_MEM_PMIC_REG_32                                    0x05EAC330

/// @brief: Only display POST CODE to ABL console log
/// @details Type:UINT8
/// @li 0 = Feature disabled
/// @li 1 = Feature enabled
  #define APCB_TOKEN_UID_POST_CODE_ONLY_ABL_LOG                             0xAD13F65E


/// @brief: Specifies Periodic Training config
/// @details Type:UINT8
/// @li 0 = Feature disabled
/// @li 1 = Feature enabled
  #define APCB_TOKEN_UID_MEM_PR_TRAIN_EN_DDR                                 0x87E5BF5E

// =================================================================================================
// CBS CMN APCB Tokens (2BYTE)
// -------------------------------------------------------------------------------------------------
/// @GROUPID: APCB_GROUP_TOKEN
/// @TYPEID: APCB_TYPE_TOKEN_2BYTES
/// @DATATYPE: UINT16
/// @SIZE: 2

/// @brief CBS_CMN_MEM_TIMING_TRFC2_DDR4
/// @details Type:UINT16
/// @li 0x003C~0x03DE = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRFC2_DDR4                      0xEF6CF7B3  // uint16 //uint16

/// @brief CBS_CMN_MEM_TIMING_TRFC4_DDR4
/// @details Type:UINT16
/// @li 0x003C~0x03DE = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_MEM_TIMING_TRFC4_DDR4                      0x4A05C5E2  // uint16 //uint16

/// @ingroup PSP
/// @brief This token the timer interval of the PSP SYSHUB Watchdogtimer. Value is in milliseconds and must be within the range: 1-65535.
/// @brief Permitted Choices: (Type: Value)(Default: 2600)
  #define APCB_TOKEN_UID_PSP_SYSHUB_WDT_INTERVAL                            0xEDB5E4C9  // uint16

/// @ingroup NBIO
/// @brief OVERCLOCK_VDDP_VOLTAGE
/// @details Type:UINT16
/// @li 0x0000~0x07FF = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_VDDP_VOLTAGE                       0xAB4BABF4  // uint16

/// @brief OVERCLOCK_VDDG_VOLTAGE
/// @details Type:UINT16
/// @li 0x0000~0x07FF = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_VDDG_VOLTAGE                       0xEE9F031C  // uint16

/// @brief OVERCLOCK_IOD_VDDG_VOLTAGE
/// @details Type:UINT16
/// @li 0x0000~0x07FF = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_IOD_VDDG_VOLTAGE                   0x93CA7EA3  // uint16

/// @brief OVERCLOCK_CCD_VDDG_VOLTAGE
/// @details Type:UINT16
/// @li 0x0000~0x07FF = UINT16 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_GNB_SMU_CCD_VDDG_VOLTAGE                   0xC286E57A  // uint16

/// @brief eSPI IO Range0 Base
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE0_BASE                                 0xA1B71439  // uint16

/// @brief eSPI IO Range1 Base
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE1_BASE                                 0x10397E9A  // uint16

/// @brief eSPI IO Range2 Base
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE2_BASE                                 0x632A9B05  // uint16

/// @brief eSPI IO Range3 Base
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_IORANGE3_BASE                                 0x9DC3A759  // uint16

/// @brief eSPI MMIO Range0 Size
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE0_SIZE                               0x28B271A1  // uint16

/// @brief eSPI MMIO Range1 Size
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE1_SIZE                               0x2712CD64  // uint16

/// @brief eSPI MMIO Range2 Size
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE2_SIZE                               0x0DC96471  // uint16

/// @brief eSPI MMIO Range3 Size
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE3_SIZE                               0x9EB1D9FC  // uint16

/// @ingroup FCH
/// @brief This control allows the user to disable the GPP clocks at a very early ABL boot stage. Multiple clocks can be specified.
/// @brief Permitted Choices: (Type: list) (Default: GPP_ALL_CLK_AUTO)
/// @brief Examples:
/// @li GPP_ALL_CLK_ON - used for the condition where some of the CPU GPP CLK has been fused (set to default as OFF) for the specific OPN; but, the customer w
/// ants ALL GPP CLK(s) to be ON.
/// @li GPP_ALL_CLK_AUTO - Keep the power-on reset value.
/// @li S0_GPP0_CLK_OFF
/// @li S0_GPP1_CLK_OFF
/// @li S0_GPP2_CLK_OFF
/// @li S0_GPP3_CLK_OFF
/// @li S0_GPP4_CLK_OFF
/// @li S1_GPP0_CLK_OFF
/// @li S1_GPP1_CLK_OFF
/// @li S1_GPP2_CLK_OFF
/// @li S1_GPP3_CLK_OFF
/// @li S1_GPP4_CLK_OFF
/// @code
///            Example 1. Socket 0 GPP1 clock and Socket 0 GPP2 clock OFF
///            APCB_TOKEN_UID_FCH_GPP_CLK_MAP    (S0_GPP1_CLK_OFF | S0_GPP2_CLK_OFF)
///
///            Example 2. Socket 0 GPP0 clock and Socket 1 GPP2 clock OFF
///            APCB_TOKEN_UID_FCH_GPP_CLK_MAP    (S0_GPP0_CLK_OFF | S1_GPP2_CLK_OFF)
/// @endcode
  #define APCB_TOKEN_UID_FCH_GPP_CLK_MAP                                    0xCD7E6983  // uint16
/// @ingroup FCH
/* FCH_GPP_CLK_MAP
 *  Value range for APCB_TOKEN_UID_FCH_GPP_CLK_MAP
 */
typedef enum {
  GPP_ALL_CLK_ON = 0x0000,
  GPP_ALL_CLK_AUTO = 0xFFFF,
  // S0
  S0_GPP0_CLK_OFF = 1,
  S0_GPP1_CLK_OFF = (1 << 1),
  S0_GPP2_CLK_OFF = (1 << 3),
  S0_GPP3_CLK_OFF = (1 << 4),
  S0_GPP4_CLK_OFF = (1 << 2),
  // S1
  S1_GPP0_CLK_OFF = 1 << 8,
  S1_GPP1_CLK_OFF = (1 << (1 + 8)),
  S1_GPP2_CLK_OFF = (1 << (3 + 8)),
  S1_GPP3_CLK_OFF = (1 << (4 + 8)),
  S1_GPP4_CLK_OFF = (1 << (2 + 8))
} FCH_GPP_CLK_MAP;

/// @brief For those who include the CBS feature, this item is the CBS control set a delay for entry into DDR power down mode by specified a number of DRAM clock
/// s to wait. Usage: Setting it to higher values will delay the entry into DRAM power-down mode. In lower DRAM bandwidth workloads, higher values may red
/// uce average latency to DRAM at the cost of reduced DRAM power-down residency (less power saved).
/// @brief Permitted Choices: (Type: Value)(Default: 0xFF - Auto)
/// @li 1..N - The number of clocks to wait before entering Power Down Mode.
/// @li 0xFF, Auto  -  Do not delay entry. Save as much power as possible.
  #define APCB_TOKEN_UID_CBS_CMN_MEM_PWRDOWNDLY                             0x1EBE755A

/// @ingroup Memory
/// @brief Memory Target Speed
/// @details Specifies the memory target speed in MT/s.
/// @details The valid input is 3200, 3600, 4000, 4400, 4800, 5200, 5600.
/// @details Permitted Choices (Type: Numerical) (Default: 4800)
/// @li 1000~6000
  #define APCB_TOKEN_UID_MEM_TARGET_SPEED_DDR                               0xD06DBAFB

/// @ingroup Memory
/// @brief Specifies the time in memory clock cycles from the CAS assertion
/// for a read cycle until data return
/// @brief Permitted Choices: (Type: Numerical)
/// @li 22 ~ 64 (Stepping of 2)
  #define APCB_TOKEN_UID_MEM_TIMING_TCL_DDR                                 0xFC195E5C

/// @ingroup Memory
/// @brief Specifies the RAS active to CAS read delay time
/// @brief Permitted Choices: (Type: Numerical)
/// @li 8 ~ 62 (Stepping of 2)
  #define APCB_TOKEN_UID_MEM_TIMING_TRCD_DDR                                0xE31F1FCE

/// @ingroup Memory
/// @brief Specifies row precharge delay time
/// @brief Permitted Choices: (Type: Numerical)
/// @li 8 ~ 62 (Stepping of 2)
  #define APCB_TOKEN_UID_MEM_TIMING_TRP_DDR                                 0x0DB8CB47

/// @ingroup Memory
/// @brief Specifies the minimum time in memory clock cycles from an activate
/// command to a precharge command, both to the same bank
/// @brief Permitted Choices: (Type: Numerical)
/// @li 30 ~ 126 (Stepping of 2)
  #define APCB_TOKEN_UID_MEM_TIMING_TRAS_DDR                                0x5E367ACA

/// @ingroup Memory
/// @brief Specifies Active to Active/Refresh Delay Time
/// @brief Permitted Choices: (Type: Numerical)
/// @li 29 ~ 135
  #define APCB_TOKEN_UID_MEM_TIMING_TRC_DDR                                 0x7F877269

/// @ingroup Memory
/// @brief Specifies the minimum time in memory clock cycles from the last data
/// write until the chipselect bank precharge
/// @brief Permitted Choices: (Type: Numerical)
/// @li 10 ~ 100
  #define APCB_TOKEN_UID_MEM_TIMING_TWR_DDR                                 0x082D6E55

/// @ingroup Memory
/// @brief Specifies the REF command
/// @brief Permitted Choices: (Type: Numerical)
/// @li 60 ~ 990
  #define APCB_TOKEN_UID_MEM_TIMING_TRFC1_DDR                               0xBBEED68E

/// @ingroup Memory
/// @brief Specifies the Fine Granularity Refresh mode REF command period
/// @brief Permitted Choices: (Type: Numerical)
/// @li 60 ~ 990
  #define APCB_TOKEN_UID_MEM_TIMING_TRFC2_DDR                               0x2C5A76B2

/// @ingroup Memory
/// @brief Specifies the Refresh Recovery Delay Time
/// @brief Permitted Choices: (Type: Numerical)
/// @li 50 ~ 2047
  #define APCB_TOKEN_UID_MEM_TIMING_TRFCSB_DDR                              0x32EB3B5B

/// @ingroup Memory
/// @brief Specifies the minimum time in memory clock cycles a page can be
/// closed after having been read
/// @brief Permitted Choices: (Type: Numerical)
/// @li 5 ~ 14
  #define APCB_TOKEN_UID_MEM_TIMING_TRTP_DDR                                0xE5AEA7D3

/// @ingroup Memory
/// @brief Specifies the minimum time in memory clock cycles between
/// activate commands to different chipselect banks in the same bank group
/// @brief Permitted Choices: (Type: Numerical)
/// @li 4 ~ 12
  #define APCB_TOKEN_UID_MEM_TIMING_TRRDL_DDR                               0xA715EE94

/// @ingroup Memory
/// @brief Specifies the minimum time in memory clock cycles between
/// activate commands to different chipselect banks
/// @brief Permitted Choices: (Type: Numerical)
/// @li 4 ~ 12
  #define APCB_TOKEN_UID_MEM_TIMING_TRRDS_DDR                               0x89251A4E

/// @ingroup Memory
/// @brief Specifies the rolling window in memory clock cycles during
/// which no more than 4 banks may be activated
/// @brief Permitted Choices: (Type: Numerical)
/// @li 6 ~ 54
  #define APCB_TOKEN_UID_MEM_TIMING_TFAW_DDR                                0xD8690C08

/// @ingroup Memory
/// @brief Specifies the minimum number of memory clock cycles from a write
/// operation to a read operation, both to the same chipselect in the same
/// bank group. This is measured from the rising clock edge following last
/// non-masked data strobe of the write to the rising clock edge of the next
/// read command
/// @brief Permitted Choices: (Type: Numerical)
/// @li 2 ~ 14
  #define APCB_TOKEN_UID_MEM_TIMING_TWTRL_DDR                               0xABA4CB4A

/// @ingroup Memory
/// @brief Specifies the minimum number of memory clock cycles from a write
/// operation to a read operation, both to the same chipselect. This is
/// measured from the rising clock edge following last non-masked data
/// strobe of the write to the rising clock edge of the next read command
/// @brief Permitted Choices: (Type: Numerical)
/// @li 2 ~ 14
  #define APCB_TOKEN_UID_MEM_TIMING_TWTRS_DDR                               0xF65089FD

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of the first read-burst operation to the clock in which
/// CAS is asserted for a following read-burst operation in the same
/// chipselect in the same bank group
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TRDRDSCL_DDR                            0x796F2C65

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of the first readburst operation to the clock in which CAS
/// is asserted for a following read-burst operation in the same chipselect
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TRDRDSC_DDR                             0x91364DC6

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of the first readburst operation to the clock in which CAS
/// is asserted for a following read-burst operation in the same DIMM
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TRDRDSD_DDR                             0x627427BD

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of the first readburst operation to the clock in which CAS
/// is asserted for a following read-burst operation in a different DIMM
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TRDRDDD_DDR                             0x08E99B01

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of a first write-burst operation to the clock in which CAS
/// is asserted for a following write-burst operation in the same bank group
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 63
  #define APCB_TOKEN_UID_MEM_TIMING_TWRWRSCL_DDR                            0x86E6A99A

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of a first write-burst operation to the clock in which CAS
/// is asserted for a following write-burst operation in the same chipselect
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TWRWRSC_DDR                             0x275A3185

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of the first write-burst operation to the clock in which CAS
/// is asserted for a following write-burst operation in the same DIMM
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TWRWRSD_DDR                             0x99B04933

/// @ingroup Memory
/// @brief Specifies the minimum number of cycles from the last clock of
/// virtual CAS of the first write-burst operation to the clock in which CAS
/// is asserted for a following write-burst operation in a different DIMM
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TWRWRDD_DDR                             0x10B50ABC

/// @ingroup Memory
/// @brief Specifies the minimum number of clock cycles from the last clock
/// of virtual CAS of a first write-burst operation to the clock in which CAS
/// is asserted for a following read-burst operation
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TWRRD_DDR                               0x77AF3F93

/// @ingroup Memory
/// @brief Specifies the minimum number of clock cycles from the last clock
/// of virtual CAS of a first read-burst operation to the clock in which CAS
/// is asserted for a following write-burst operation
/// @brief Permitted Choices: (Type: Numerical)
/// @li 1 ~ 15
  #define APCB_TOKEN_UID_MEM_TIMING_TRDWR_DDR                               0x1382572D

/// @brief Power Down Entry Delay
/// @details Type:UINT16
/// @li 0~0xFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_MEM_POWER_DOWN_ENTRY_DLY                           0x2784C3AB  // uint16

/// @ingroup Memory
/// @brief PMIC SWA/SWB VDD Core
/// @details Range is from 1000mV to 1200mV.
/// @details Permitted Choices (Type: Numerical) (Default: 1100)
/// @li 1000~1200
  #define APCB_TOKEN_UID_MEM_PMIC_SWA_SWB_VDDCORE_DDR                       0x78ECAB2F

/// @ingroup Memory
/// @brief PMIC SWC VDDIO
/// @details Range is from 1000mV to 1200mV
/// @details Permitted Choices (Type: Numerical) (Default: 1100)
/// @li 1000~1200
  #define APCB_TOKEN_UID_MEM_PMIC_SWC_VDDIO_DDR                             0xB241BE44

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 0 Link 0 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L0                          0xF57749D9

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 0 Link 1 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L1                          0x6D17233F

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 0 Link 2 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L2                          0x2C733C17

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 0 Link 3 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S0_L3                          0xC49E23E3

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 1 Link 0 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L0                          0xDB75063F

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 1 Link 1 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L1                          0x98BA12F7

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 1 Link 2 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L2                          0x01A916BC

/// @ingroup DF
/// @brief XGMI Initial Preset Socket 1 Link 3 Pstate0/1/2/3
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_S1_L3                          0x416FF232

/// @ingroup CCX
/// @brief CPU Watchdog Timeout
/// @details Type:UINT16
/// @li 0x0000~0xFFFF = UINT16 Valid Range
  #define APCB_TOKEN_UID_CPU_WDT_TIMEOUT                                    0xCFCAE1BD

/// @cond INT
#define MEM_PMU_BIST_ALGORITHM_1                              BIT0
#define MEM_PMU_BIST_ALGORITHM_2                              BIT1
#define MEM_PMU_BIST_ALGORITHM_3                              BIT2
#define MEM_PMU_BIST_ALGORITHM_4                              BIT3
#define MEM_PMU_BIST_ALGORITHM_5                              BIT4
#define MEM_PMU_BIST_ALGORITHM_6                              BIT5
#define MEM_PMU_BIST_ALGORITHM_7                              BIT6
#define MEM_PMU_BIST_ALGORITHM_8                              BIT7
#define MEM_PMU_BIST_ALGORITHM_9                              BIT8
/// @endcond

/// @ingroup Memory
/// @brief PMU Mem BIST Algorithm Bitmask
/// @brief PMU Mem BIST supports nine algorithms. This option allows user to choose the algorithm(s)
/// that will be performed.
/// @brief Algorithm #1: Write-Pause-Read (This test will take ~11 seconds per memory rank per pattern).
/// @brief Algorithm #2: Write-Pause-Read, short tWR (This test will take ~26 seconds per memory rank per pattern).
/// @brief Algorithm #3: Row Victim Aggressor (This test will take ~22 seconds per memory rank per pattern).
/// @brief Algorithm #4: Write-Pause-Read, Closed Page (This test will take ~19 seconds per memory rank per pattern).
/// @brief Algorithm #5: Closed Page Stress Test (This test will take ~29 seconds per memory rank per pattern).
/// @brief Algorithm #6: Double Row Victim Aggressor (This test will take ~18 seconds per memory rank per pattern).
/// @brief Algorithm #7: Open page Checkerboard RMW (This test will take ~47 seconds per memory rank per pattern).
/// @brief Algorithm #8: Closed page tWR Stress (This test will take ~28 seconds per memory rank per pattern).
/// @brief Algorithm #9: Open Page Static Refresh Test (This test will take ~6 seconds per memory rank per pattern).
/// @brief Permitted Choices: (Type: value)(Default: 0x1FF)
/// @li BIT0 - 0:Disable algorithm #1. 1:Enable algorithm #1
/// @li BIT1 - 0:Disable algorithm #2. 1:Enable algorithm #2
/// @li BIT2 - 0:Disable algorithm #3. 1:Enable algorithm #3
/// @li BIT3 - 0:Disable algorithm #4. 1:Enable algorithm #4
/// @li BIT4 - 0:Disable algorithm #5. 1:Enable algorithm #5
/// @li BIT5 - 0:Disable algorithm #6. 1:Enable algorithm #6
/// @li BIT6 - 0:Disable algorithm #7. 1:Enable algorithm #7
/// @li BIT7 - 0:Disable algorithm #8. 1:Enable algorithm #8
/// @li BIT8 - 0:Disable algorithm #9. 1:Enable algorithm #9
  #define APCB_TOKEN_UID_MEM_PMU_BIST_ALGORITHM_BITMASK_DDR                 0xEB1B26D3

/// @ingroup Memory
/// @brief OdtsCmdThrotCyc
/// @details Specifies the weighted allowed cycles per rolling window depth.
/// @details See PPR UMC::ThrottleCtrl[19:10] OdtsCmdThrotCyc
/// @details Permitted Choices: (Type: Numerical) (Default: 0x1FF)
/// @li 0x1~0x3FF
  #define APCB_TOKEN_UID_ODTSCMDTHROTCYC                                    0x69318E90

/// @ingroup Memory
/// @brief Specifies the throttling rolling window depth
/// @brief See PPR UMC::ThrottleCtrl[9:0] RollWindowDepth
/// @brief Permitted Choices: (Type: Numerical) (Default: 0x1FF)
/// @li 0x1~0x3FF Memclks
  #define APCB_TOKEN_UID_ROLLWINDOWDEPTH                                    0x5985083A

/// @brief MEM_PR_INTERVAL_OVERRIDE
/// @details Type:UINT16
/// @li 0~0xFFFF = UINT16 Valid Range
#define APCB_TOKEN_UID_MEM_PR_INTERVAL_DDR                                  0x9147E823

// =================================================================================================
// CBS CMN APCB Tokens (4BYTE)
// -------------------------------------------------------------------------------------------------
/// @GROUPID: APCB_GROUP_TOKEN
/// @TYPEID: APCB_TYPE_TOKEN_4BYTES
/// @DATATYPE: UINT32
/// @SIZE: 4

/// @ingroup CCX
/// @brief This control specifies, per the PPR, the minimum ASID value that must be used for a guest that has SEV enabled, but SEV-ES disabled. SEV VMs using AS
/// IDs below this value must enable the SEV-ES feature. ASIDs from APCB_TOKEN_UID_CCX_MIN_SEV_ASID to (APCB_TOKEN_UID_CCX_SEV_ASID_COUNT + 1) can only be
/// used with SEV only VMs. If this token is set to (APCB_TOKEN_UID_CCX_SEV_ASID_COUNT + 1), all ASIDs are forced to be SEV-ES ASIDs.
/// @brief Permitted Choices: (Type: Value)(Default: 0x0001)
  #define APCB_TOKEN_UID_CCX_MIN_SEV_ASID                                   0xA7C33753  // uint32

/// @ingroup DF
/// @brief Raw size in bytes of the space used for PCI cfg MMIO. Lower 4 nibbles must be 0.
/// @brief Permitted Choices: (Type: Value)(Default: 0x10000000)
/// @brief Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_DF_PCI_MMIO_SIZE                                   0x3D9B7D7B  // uint32

/// @ingroup DF
/// @brief DF PCI Express Base Address. 1MB aligne required. Should match platform PcdPciExpressBaseAddress
/// @details Type:UINT32
/// @li 0x80000000~0xF8000000 = PCI express base address valid range. 1MB aligne required.
  #define APCB_TOKEN_UID_DF_PCI_MMIO_BASE                                   0x7A4FA9ED

/// @ingroup DF
/// @brief DF PCI Express Upper Base Address.
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_PCI_MMIO_HI_BASE                                0xF6B915BF

/// @ingroup DF
/// @brief This options specifies the performance penalty the customer is willing to accept in order to enable inter-die link CRC detection / protection in 0.000
/// 01% units. The parameter is 32-bits in length with an allowable range of 0 - 1,000,000 (decimal) which corresponds to [disabled - 10%]. A value of zer
/// o disables the feature. If there are no GMI or xGMI links in the system (single die system), the value is ignored.
/// @brief Permitted Choices: (Type: Value)(Default: 100 (0.001%))
  #define APCB_TOKEN_UID_DF_CAKE_CRC_THRESH_PERF_BOUNDS                     0x9258CF45  // uint32

/// @ingroup Memory
/// @brief Allows the platform to select how the determination is made for the memory clock that is to be used in the system. (See also APCB_TOKEN_UID_MEMCLOCKVA
/// LUE.)
/// @brief Permitted Choices: (Type: List)(Default: TIMING_MODE_AUTO)
/// @li 0 = TIMING_MODE_AUTO - The AGESA software calculates the best memory clock rate.
/// @li 1 = TIMING_MODE_LIMITED - The AGESA software calculates the best memory clock, restricted by a maximum user limit provided in APCB_TOKEN_UID_MEMCLOCKVALUE.
/// @li 2 = TIMING_MODE_SPECIFIC - The platform specifies the clock rate, which is provided in APCB_TOKEN_UID_MEMCLOCKVALUE.
  #define APCB_TOKEN_UID_USERTIMINGMODE                                     0xFC560D7D  // uint32

/// @ingroup Memory
/// @brief This is the specified memory clock to be used in the system as determined by the selected mode. (See also APCB_TOKEN_UID_USERTIMINGMODE.)
/// @brief Permitted Choices: (Type: List)(Default: Auto)
/// @li DDR400_FREQUENCY
/// @li DDR533_FREQUENCY
/// @li DDR667_FREQUENCY
/// @li DDR800_FREQUENCY
/// @li DDR1066_FREQUENCY
/// @li DDR1333_FREQUENCY
/// @li DDR1600_FREQUENCY
/// @li DDR1866_FREQUENCY
/// @li DDR2100_FREQUENCY
/// @li DDR2133_FREQUENCY
/// @li DDR2400_FREQUENCY
/// @li DDR2667_FREQUENCY
/// @li DDR2933_FREQUENCY
/// @li DDR3200_FREQUENCY
/// @li Auto - ABL decides the best setting.
  #define APCB_TOKEN_UID_MEMCLOCKVALUE                                      0xCC83F65F  // uint32

/// @brief UMASIZE
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_UMASIZE                                            0x37B1F8CF  // uint32

/// @brief UMAALIGNMENT
/// @details Type:UINT32
/// @see UMAALIGNMENT_VAL
  #define APCB_TOKEN_UID_UMAALIGNMENT                                       0x57DDF512  // uint32
/** UMAALIGNMENT_VAL
*  Value range for APCB_TOKEN_UID_UMAALIGNMENT
*/
typedef enum {
  UMAALIGNMENT_NONE = 0x00FFFFFF,      ///< NO UMA aligned
  UMAALIGNMENT_128MB = 0x00FFF800,     ///< UMA 128MB aligned
  UMAALIGNMENT_256MB = 0x00FFF000,     ///< UMA 256MB aligned
  UMAALIGNMENT_512MB = 0x00FFE000,     ///< UMA 512MB aligned
} UMAALIGNMENT_VAL;

/// @ingroup Memory
/// @brief MEMORYBUSFREQUENCYLIMIT
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_MEMORYBUSFREQUENCYLIMIT                            0x34970A3C  // uint32

/// @brief POWERDOWNMODE
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_POWERDOWNMODE                                      0x23DD2705  // uint32

/// @brief CBS_CMN_CLDOVDD_PVOLTAGE
/// @details Type:UINT32
/// @li 0x000002BC~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_CBS_CMN_CLDOVDD_PVOLTAGE                           0x7915D708  //uint32

/// @ingroup Memory
/// @brief MBIST Aggressor Static Lane Select Lower 32
/// @details This pair of tokens set the DQ lanes mask for Aggressor Lanes. This is a 64-bit value split to be two 32-bit values (L32-lower bits, U32-upper bits) w
/// here each bit represents 1 DQ lane. Lanes represented with a 1, will be used as aggressors during the MBIST test.
/// @details Permitted Choices: (Type: Numerical) (Default: 0)
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_L32                 0x745218AD  //uint32

/// @ingroup Memory
/// @brief MBIST Aggressor Static Lane Select Upper 32
/// @details This pair of tokens set the DQ lanes mask for Aggressor Lanes. This is a 64-bit value split to be two 32-bit values (L32-lower bits, U32-upper bits) w
/// here each bit represents 1 DQ lane. Lanes represented with a 1, will be used as aggressors during the MBIST test.
/// @details Permitted Choices: (Type: Numerical) (Default: 0)
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_MEM_MBIST_AGGR_STATIC_LANE_SEL_U32                 0xFAC9F48F  //uint32

/// @ingroup Memory
/// @brief Mbist Target Static Lane Select Lower 32
/// @details Static Lane Select for Lower 32 bits. The bit mask represents the bits to be read.
/// @details Permitted Choices: (Type: Numerical) (Default: 0)
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_L32                  0x81880D15  //uint32

/// @ingroup Memory
/// @brief Mbist Target Static Lane Select Upper 32
/// @details Static Lane Select for Upper 32 bit. The bit mask represents the bits to be read.
/// @details Permitted Choices: (Type: Numerical) (Default: 0)
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_MEM_MBIST_TGT_STATIC_LANE_SEL_U32                  0xAF669F33  //uint32

/// @brief PCIE_RESET_GPIO_PIN_SELECT
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_PCIE_RESET_GPIO_PIN_SELECT                         0x596663AC  //uint32

/// @ingroup CCX
/// @brief AP base address when fetch from SPI ROM
/// @details Type:UINT32
/// @li Lowest Available Memory~Top Of Memory = UINT32 Valid Range, must be 0x10000 aligned
  #define APCB_TOKEN_UID_CPU_FETCH_FROM_SPI_AP_BASE                         0xD403EA0E  // uint32

/// @brief eSPI MMIO Range0 Base
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE0_BASE                               0x29F49AF8  // uint32

/// @brief eSPI MMIO Range1 Base
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE1_BASE                               0xD1DE10BD  // uint32

/// @brief eSPI MMIO Range2 Base
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE2_BASE                               0x5831DE1A  // uint32

/// @brief eSPI MMIO Range3 Base
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_ESPI_MMIORANGE3_BASE                               0x419A9D4F  // uint32

/// @ingroup FCH
/// @brief This token sets the base address for the ROM3 region. See the PPPR for "BAR_64MB_ROM3_High" at FCH::ITF::SPI. This control is used by systems enabling
/// the ROM Armor feature .
/// @brief Permitted Choices: (Type: Value Int32)(Default: 0x0000_0000)
/// @li 0x0000 - This will result in no change of the BAR register from the power-on default value of 0x0000_00FD. (ROM3 region will be 0x00FD_0000_0000 to 0x
/// 00FD_03FF_FFFF).
/// @li 0x0??? - This value will specifically update the BAR register. e.g. if this token value is set to 0x07FC, the register will read as 0x7FC and the ROM3
/// region will be 0x07FC_0000_0000 to 0x07FC_03FF_FFFF.
  #define APCB_TOKEN_UID_FCH_ROM3_BASE_HIGH                                 0x3E7D5274  //uint32

/// @brief Signature for CBS to keep the hash value
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_CBS_SYNC_SIGNATURE                                 0xB331378E  // uint32

/// @ingroup PSP
/// @brief Reserved feature. Must be =0.
/// @brief Permitted Choices: (Type: Value)(Default: 0)
  #define APCB_TOKEN_UID_PSP_MEASURE_CONFIG                                 0xDD3AD029  //uint32

/// @brief MEM_SELF_HEAL_BIST_TIMEOUT
/// @details Type:UINT32
/// @li 0x00000000~0x0000FFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_MEM_SELF_HEAL_BIST_TIMEOUT                         0xBE7597D4  //uint32

/// @brief Controls the CTLE gain.
/// @brief Permitted choices: (Type: Value)(Default: 0xFFFFFFF (skip))
/// @li 0x00000000~0xFFFFFFFF = (UINT32) Valid Range.
/// @li 0xFFFFFFFF = skip.
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_VGA                                 0xDE09C43B

/// @brief This controls the capacitive degeneration.
/// @brief Permitted choices: (Type: Value)(Default: 0xFFFFFFFF (skip))
/// @li 0x00000000~0xFFFFFFFF = (UINT32) Valid Range.
/// @li 0xFFFFFFFF = skip.
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_POLE                                0xB189447E

/// @brief Controls register degeneration.
/// @brief Permitted choices: (Type: Value)(Default: 0xFFFFFFF (skip))
/// @li 0x00000000~0xFFFFFFFF = (UINT32) Valid Range.
/// @li 0xFFFFFFFF = skip.
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_DC                                  0x20667C30

/// @brief Shift the phase on x-axis.
/// @brief Permitted choices: (Type: Value)(Default: 0xFFFFFFF (skip))
/// @li -4 ~ 4 = (INT32) Valid Range.
/// @li 0x7FFFFFFF = skip.
  #define APCB_TOKEN_UID_DXIO_PHY_PARAM_IQOFC                               0x7E6069C5

/// @ingroup Memory
/// @brief Enable or disable Memory MBIST
/// @brief Permitted Choices: (Type: List)
/// @li 0 - Disable MBIST
/// @li 1 - Enable MBIST
/// @li 0xFF - Auto
  #define APCB_TOKEN_UID_MEM_MBIST_EN_DDR                                   0x7DCB2DA5

/// @ingroup Memory
/// @brief Enable or disable MBIST Aggressor test
/// @brief Permitted Choices: (Type: List)
/// @li 0 - Interface Mode
/// @li 1 - Data Eye Mode
/// @li 2 - Both (Enables Interface Mode and Data Eye Mode)
/// @li 0xFF - Auto
  #define APCB_TOKEN_UID_MEM_MBIST_AGGRESSORS_DDR                           0xB46EF9AB

/// @ingroup Memory
/// @brief Select MBIST Test Mode -Interface Mode (Tests Single and Multiple CS transactions
/// and Basic Connectivity) or Data Eye Mode (Measures Voltage vs. Timing)
/// @brief Permitted Choices: (Type: List)
/// @li 0 - Disable MBIST
/// @li 1 - Enable MBIST
/// @li 0xFF - Auto
  #define APCB_TOKEN_UID_MEM_MBIST_TESTMODE_DDR                             0x96DF25CA

/// @ingroup Memory
/// @brief Reports 2D Data Eye Results in ABL Log for each DQ, Chipselect, and Channel
/// @brief Permitted Choices: (Type: List)
/// @li 0 - Disable MBIST
/// @li 1 - Enable MBIST
/// @li 0xFF - Auto
  #define APCB_TOKEN_UID_MEM_MBIST_PER_BIT_SECONDARY_DIE_REPORT_DDR             0x3B782D55

/// @ingroup Memory
/// @brief Channels to use as aggressors
/// @brief Permitted Choices: (Type: List)
/// @li 0 - Subchannel for the current target is an aggressor
/// @li 1 - Half Subchannel - Subchannels on the same side as the current target subchannel are aggressors
/// @li 2 - All Subchannel - All Subchannels are aggressors
/// @li 0xFF - Auto
/// @see MEM_MBIST_AGGRESSORS_CHNL_VALIDVAL
  #define APCB_TOKEN_UID_MEM_MBIST_AGGRESSORS_CHNL_DDR                      0x02FC8CA9

/**
*   @ingroup Memory
*   @brief Value range for APCB_TOKEN_UID_MEM_MBIST_AGGRESSORS_CHNL_DDR
*/
typedef enum {
  MEM_MBIST_AGGRESSORS_CHNL_SUBCHANNEL  = 0,  ///<SubChannel only
  MEM_MBIST_AGGRESSORS_CHNL_HALF        = 1,  ///<Half of all channels
  MEM_MBIST_AGGRESSORS_CHNL_ALL         = 2,  ///<All Channels
} MEM_MBIST_AGGRESSORS_CHNL_VALIDVAL;

/// @ingroup Memory
/// @brief This token determine the pattern length for data eye tests
/// @brief Permitted Choices: (Type: Numerical)
/// @li 3~0xC
  #define APCB_TOKEN_UID_MEM_MBIST_PATTERN_LENGTH_DDR                       0x108BB3E6

/// @ingroup Memory
/// @brief MBIST Data Eye Pattern Type.
/// @brief Permitted Choices: (Type: List)
/// @li 0 - PRBS
/// @li 1 - SSO
/// @li 2 - Both (PRBS and SSO)
  #define APCB_TOKEN_UID_MEM_MBIST_PATTERN_SELECT_DDR                       0x5988CFA6

/// @brief  OPN Platform Compatibility fusing
/// @details Type:UINT32
/// @li 0~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_OPN_PLT_COMPAT_FUSING                              0x24B45ECD

/// @ingroup DF
/// @brief DF XGMI Preset P11
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_PRESET_P11                                 0x088B9701

/// @ingroup DF
/// @brief DF XGMI Preset P12
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_PRESET_P12                                 0x5C22C08A

/// @ingroup DF
/// @brief DF XGMI Preset P13
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_PRESET_P13                                 0x27530C2F

/// @ingroup DF
/// @brief DF XGMI Preset P14
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_PRESET_P14                                 0x76ECF33F

/// @ingroup DF
/// @brief DF XGMI Preset P15
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_PRESET_P15                                 0x532EB058

/// @ingroup DF
/// @brief XGMI Initial Preset
/// @details Type:UINT32
/// @li 0x0~0xFFFFFFFF
  #define APCB_TOKEN_UID_DF_XGMI_INIT_PRESET_DEFAULT                        0xC6F86640

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 0 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L0_P01                             0xE53519B1

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 0 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L0_P23                             0xC50E790E

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 1 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L1_P01                             0x68CAED33

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 1 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L1_P23                             0xAF56AFAA

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 2 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L2_P01                             0xD6CAD603

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 2 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L2_P23                             0x17E59442

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 3 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L3_P01                             0x6061EDCE

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 0 Link 3 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S0_L3_P23                             0x34DBC7AF

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 0 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L0_P01                             0xD32408F4

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 0 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L0_P23                             0x5243AF4A

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 1 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L1_P01                             0x026B4760

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 1 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L1_P23                             0x72BF1CDF

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 2 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L2_P01                             0xC8B848A9

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 2 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L2_P23                             0x0F3A8F7F

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 3 Pstate0/1
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L3_P01                             0x6566D661

/// @ingroup DF
/// @brief DF XGMI TXEQ Search Mask Socket 1 Link 3 Pstate2/3
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
  #define APCB_TOKEN_UID_DF_XGMI_TXEQ_S1_L3_P23                             0x902D0192

#define MEM_CHANNEL_DISABLE_BITMASK_DEFAULT                                 0
#define MEM_CHANNEL_DISABLE_BITMASK_SOCKET_SHIFT                            16

/// @ingroup Memory
/// @brief Memory Channel Disable Bitmask
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
/// @li Bit[0:11]  Disable Socket 0 Channel [0:11]
/// @li Bit[12:15] Reserved
/// @li Bit[16:27] Disable Socket 1 Channel [0:11]
/// @li Bit[28:31] Reserved
  #define APCB_TOKEN_UID_MEM_CHANNEL_DISABLE_BITMASK_DDR                    0x9E48FAD6

/// @ingroup DF
/// @brief XGMI Channel Type
/// @details Type:UINT32
/// @li 0x00000000~0xFFFFFFFF = UINT32 Valid Range
/// @li Bit[00:03] Channel Type of socket 0 link 0
/// @li Bit[04:07] Channel Type of socket 0 link 1
/// @li Bit[08:11] Channel Type of socket 0 link 2
/// @li Bit[12:15] Channel Type of socket 0 link 3
/// @li Bit[16:19] Channel Type of socket 1 link 0
/// @li Bit[20:23] Channel Type of socket 1 link 1
/// @li Bit[24:27] Channel Type of socket 1 link 2
/// @li Bit[28:31] Channel Type of socket 1 link 3
/// @li Valid channel type: 0: Disabled 1: Long Reach
  #define APCB_TOKEN_UID_XGMI_CHANNEL_TYPE                                  0x0DB989C4

/// @ingroup NBIO
/** X3DSTACKOVERRIDE_ALL_VALIDVAL
*   Value range for APCB_TOKEN_UID_X3DSTACKOVERRIDE
*/
typedef enum {
  X3DSTACKOVERRIDE_DISABLE        = 0,///<disable X3D
  X3DSTACKOVERRIDE_1X3DSTACK      = 1,///<1 X3D stack enabled
  X3DSTACKOVERRIDE_2X3DSTACK      = 2,///<2 X3D stacks enabled
  X3DSTACKOVERRIDE_4X3DSTACK      = 4,///<4 X3D stacks enabled
} X3DSTACKOVERRIDE_VALIDVAL;

/// @ingroup NBIO
/// @brief This control sets the number of X3D stacks being used. This is available for debug of 3D V-Cache issues.
/// @brief Permitted Choices (Type: Value) (Default: 0xF Auto)
/// @li 0 - disable all X3D.
/// @li 1 - Use 1 X3D stack.
/// @li 2 - use 2 X3D stacks.
/// @li 4 - use 4 X3D stacks.
/// @li 0xF - Auto
  #define APCB_TOKEN_UID_X3DSTACKOVERRIDE                                        0x10580654

/** I2C_I3C_SMBUS_SELECT enables I3c, I2c, or Smbus controller
*   Value range for I2C_I3C_SMBUS_SELECT
*/
typedef enum {
  I3C_ENABLE        = 0,///<0 Enable I3C
  I2C_ENABLE        = 1,///<1 Enable I2C
  SMBUS_ENABLE      = 2,///<2 Enable SMBUS
} I2C_I3C_SMBUS_SELECT;

/// @ingroup FCH
/// @brief Select I3C, I2C, or SMBUS
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2C_I3C_SMBUS_0                                    0x811F7FBD  //dh, uint8
/// @ingroup FCH
/// @brief Select I3C, I2C, or SMBUS
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2C_I3C_SMBUS_1                                    0x32BD7F95  //dh, uint8
/// @ingroup FCH
/// @brief Select I3C, I2C, or SMBUS
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2C_I3C_SMBUS_2                                    0x8E275326  //dh, uint8
/// @ingroup FCH
/// @brief Select I3C, I2C, or SMBUS
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2C_I3C_SMBUS_3                                    0xED139DE8  //dh, uint8
/// @ingroup FCH
/// @brief Select I3C, I2C, or SMBUS
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2C_I3C_SMBUS_4                                    0x2158EFCA  //dh, uint8
/// @ingroup FCH
/// @brief Select I3C, I2C, or SMBUS
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2C_I3C_SMBUS_5                                    0x5CAAA37B  //dh, uint8

/** I2C_I3C_MODE_SELECT on I3C controller
*   Value range for I2C_I3C_MODE_SELECT
*/
typedef enum {
  I3C_MODE        = 0,///<0 Select I3C mode
  I2C_MODE        = 1,///<1 Select I2C mode
} I2C_I3C_MODE_SELECT;

/// @ingroup FCH
/// @brief Select I2C or I3C mode on I3C controller
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2CI3C_CONTROLLER0                                 0xB6633A33  //dh, uint8
/// @ingroup FCH
/// @brief Select I2C or I3C mode on I3C controller
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2CI3C_CONTROLLER1                                 0xD2C7BE74  //dh, uint8
/// @ingroup FCH
/// @brief Select I2C or I3C mode on I3C controller
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2CI3C_CONTROLLER2                                 0x9EC3F26B  //dh, uint8
/// @ingroup FCH
/// @brief Select I2C or I3C mode on I3C controller
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2CI3C_CONTROLLER3                                 0x83A0B3D6  //dh, uint8
/// @ingroup FCH
/// @brief Select I2C or I3C mode on I3C controller
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2CI3C_CONTROLLER4                                 0xD7AC3048  //dh, uint8
/// @ingroup FCH
/// @brief Select I2C or I3C mode on I3C controller
/// @details Type:UINT8
  #define APCB_TOKEN_UID_I2CI3C_CONTROLLER5                                 0xEBC33806  //dh, uint8

/// @ingroup FCH
/// @brief Some platforms need an adjustment to the I2C bus timing for reading the Board ID value that is located in an I2C EEPROM device. This control specifies
/// that the standard power-up value is to be adjusted by the following two controls: IC_SDA_TX_HOLD and IC_SDA_RX_HOLD.
/// @brief Caution: These controls must be synced with the x86 side controls for the same topic. See the PCDs for FchI2cSdaHold .
/// @brief Permitted Choices: (Type: Boolean)(Default: FALSE)
/// @li FALSE - no adjustment is provided. Use standard silicon power-up value.
/// @li TRUE - Replace the standard value with the user specified values.
  #define APCB_TOKEN_UID_FCH_IC_SDA_HOLD_OVERRIDE                           0x545D7662  //dh, uint8

/// @ingroup FCH
/// @brief This control specifies the hold time for the TX signal on the I2C bus.
/// @brief The bus number to which this is applied is determined from entries in the file describing the Platform ID (ApcbData_GN_GID_0x1704_Type_BoardIdGettingM
/// ethod.c). The value is in units of ic_clk periods.
/// @brief Permitted Choices: (Type: Value)(Default: 0x01)
  #define APCB_TOKEN_UID_FCH_IC_SDA_TX_HOLD                                 0x9518F953  //dh, uint16

/// @ingroup FCH
/// @brief This control specifies the hold time for the TX signal on the I2C bus. The value is in units of ic_clk periods.
/// @brief Permitted Choices: (Type: Value)(Default: 0x00)
  #define APCB_TOKEN_UID_FCH_IC_SDA_RX_HOLD                                 0xA4BAC3D5  //dh, uint8

/// @ingroup FCH
/// @brief I3C transfer speed. This APCB token is connected with
/// PcdFchI3cSpeed. Please make sure to sync any changes to
/// PcdFchI3cSpeed if there is any modification to this APCB.
/// @details Type:UINT8
  #define APCB_TOKEN_UID_FCH_I3C_TRANSFER_SPEED                             0x1ED8FAE5  //dh, uint8

/// @ingroup FCH
/// @brief I3C I3C_SDA_HOLD_SWITCH_DLY_TIMING time
/// @details Type:UINT8
  #define APCB_TOKEN_UID_FCH_I3C_SDA_HOLD_SWITCH_DLY_TIMING                 0xCCAE84E7  //dh, uint8

/// @ingroup NBIO
/// @brief SATA Mode
/// @details Type:UINT8
  #define APCB_TOKEN_UID_NBIO_SATA_MODE                                     0xE8FDE3B2  //dh, uint8

/// @ingroup NBIO
/// @brief Program SDXI class code
/// @details Type:UINT8
/// @li 0x0 - Disabled
/// @li 0x1 - Enabled
  #define APCB_TOKEN_UID_PROG_SDXI_CLASS_CODE                               0x0C4382E8  // uint8

/// @ingroup FCH
/// @brief FCH SPD Host Control Ownership (BOOLEAN)
/// @details Two designs for system I2C/I3C ownership.
/// @li Linked   - System I2C/I3C bus ownership is only controlled by BSP SPD_HOST_CTRL_L.
/// @li Separate - BSP & AP SPD_HOST_CTRL_L control each socket's I2C/I3C bus ownership.
  #define APCB_TOKEN_UID_FCH_SPD_CONTROL_OWNERSHIP                          0x23295D81  //dh, bool
/// @ingroup FCH
typedef enum {
  ApcbFchSpdCtrlOwnershipLinked        = 0,///<0 Linked   - System I2C/I3C bus ownership is only controlled by BSP SPD_HOST_CTRL_L.
  ApcbFchSpdCtrlOwnershipSeparate      = 1,///<1 Separate - BSP & AP SPD_HOST_CTRL_L control each socket's I2C/I3C bus ownership.
} APCB_FCH_SPD_CONTROL_OWNERSHIP;


#endif // _APCB_V3_TOKEN_UID_H_
