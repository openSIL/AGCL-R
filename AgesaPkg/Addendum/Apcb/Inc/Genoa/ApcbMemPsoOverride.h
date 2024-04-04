/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define Memory PSO Override specific Data
 */
#ifndef _APCB_MEM_PSO_OVERRIDE_H_
#define _APCB_MEM_PSO_OVERRIDE_H_

/**
 * @brief This data structure is used to pass memory PSO override data
 * @details GROUPID: APCB_GROUP_MEMORY TYPEID: APCB_MEM_TYPE_PSO_DATDDR4
 */
typedef struct _PSP_PSO_STRUCT {
  PSO_ENTRY MemClkDisMap[MEMCLK_DIS_MAP_SIZE];                                              ///< Memory Clock Disable Mapping
  PSO_ENTRY CkeTriMap[CKE_TRI_MAP_SIZE];                                                    ///< CKE TriState Mapping
  PSO_ENTRY OdtTriMap[ODT_TRI_MAP_SIZE];                                                    ///< ODT TriState Mapping
  PSO_ENTRY CsTriMap[CS_TRI_MAP_SIZE];                                                      ///< CS TriState Mapping
  PSO_ENTRY NumberDimmSupported[NUMBER_OF_DIMMS_SUPPORTED_SIZE];                            ///< Number of Dimm Supported
  PSO_ENTRY NumberSolderedDownDimmsSupported[NUMBER_OF_SOLDERED_DOWN_DIMMS_SUPPORTED_SIZE]; ///< Number of Soldered Down Dimms Supported
  PSO_ENTRY NumberChipSelectsSupported[NUMBER_OF_CHIP_SELECTS_SUPPORTED_SIZE];              ///< NUmber of ChipSelects Supported
  PSO_ENTRY NumberChannelsSupported[NUMBER_OF_CHANNELS_SUPPORTED_SIZE];                     ///< Number of Channels Supported
  PSO_ENTRY OverrideBusSpeed[OVERRIDE_DDR_BUS_SPEED_SIZE];                                  ///< DDR Bus Speed/Frequency Override
  PSO_ENTRY DramTechnology[DRAM_TECHNOLOGY_SIZE];                                           ///< Dram Technology Type
  PSO_ENTRY SolderedDownSoDimmType[SOLDERED_DOWN_SODIMM_TYPE_SIZE];                         ///< Soldered Down Dimm Type
  PSO_ENTRY MemoryPowerPolicyOverride[MEMORY_POWER_POLICY_OVERRIDE_SIZE];                   ///< Memory Power Cycle Override Setting
  PSO_ENTRY MotherboardLayers[MOTHER_BOARD_LAYERS_SIZE];                                    ///< Number of Motherboard Layers. For example: 4 or 6 layers
} PSP_PSO_STRUCT;


#endif // _APCB_MEM_PSO_OVERRIDE_H_



