/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define Memory Dimm Info Data Structure
 */
#ifndef _APCB_MEM_DIMM_INFO_SMBUS_H_
#define _APCB_MEM_DIMM_INFO_SMBUS_H_

/**
 * @brief Memory Board Layout type - containing Dimm
 */
#define MEMORY_LAYOUT_TYPE_DIMM           1

/**
 * @brief Memory Board Layout type - No Dimm. Onboard Memory
 */
#define MEMORY_LAYOUT_TYPE_ONBOARD        2

/**
 * @brief Struct defining SPD Data for each DIMM
 * @details This data structure is used to pass wrapper parameters to the memory configuration code
 * regarding Memory DIMM SMUBS information. Group ID: APCB_GROUP_MEMORY and TYPEID: APCB_MEM_TYPE_DIMM_INFO_SMBUS
 */
typedef struct _DIMM_INFO {
  UINT8  DimmSlotPresent;     ///< Indicates that the DIMM is present and Data is valid
  UINT8  SocketId;            ///< Indicates the socket number
  UINT8  ChannelId;           ///< Indicates the channel number
  UINT8  DimmId;              ///< Indicates the channel number
  UINT8  DimmSmbusAdderess;   ///< SMBus address of the DRAM
  UINT8  I2CMuxAddress;       ///< I2C Mux Address
  UINT8  MuxControlAddress;   ///< Mux Control Address
  UINT8  MuxChannel;          ///< I2C Mux Channel assocaited iwth this SPD
} DIMM_INFO_SMBUS;

#endif // _APCB_MEM_DIMM_INFO_SMBUS_H_


