/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */
/**
 * ApcbMemOverclockConfig.h
 *
 * APCB Memory Overclock Configuration file
 *
 */

#ifndef _APCB_MEM_OVERCLOCK_CONFIG_H_
#define _APCB_MEM_OVERCLOCK_CONFIG_H_
//
// @APCB_START
//

///===============================================================================
/// Memory Overclock configuration
#define MEM_OC_SAFE_BOOT_CONTROL_METHOD_DIS  0      ///< Safe Boot is disabled
#define MEM_OC_SAFE_BOOT_CONTROL_METHOD_G3   1      ///< Safe Boot is applied only when mechanical off
#define MEM_OC_SAFE_BOOT_CONTROL_METHOD_G2   2      ///< Safe Boot is applied only when soft-off or suspend to disk

/**
 * @brief Safe boot control index IO structure
 */
typedef struct _MEM_OC_SAFE_BOOT_CONTROL_INDEX_IO_STRUCT {
  UINT32                          Size;         ///< Size
  UINT8                           Method;       ///< Safe boot control Method
  UINT8                           IndexPort;    ///< Safe boot control index port
  UINT8                           DataPort;     ///< Safe boot control data port
  UINT8                           Address;      ///< Safe boot control address
  UINT8                           UnlockValue;  ///< Safe boot control unlock value
  UINT8                           LockValue;    ///< Safe boot control lock value
} MEM_OC_SAFE_BOOT_CONTROL_INDEX_IO_STRUCT;

#define MEM_OC_VDDIO_CONTROL_METHOD_DIS  0                  ///< VDDIO Voltage Control is disabled
#define MEM_OC_VDDIO_CONTROL_METHOD_EN   1                  ///< VDDIO Voltage Control is enabled when Memory OC mode
#define MEM_OC_VDDIO_CONTROL_METHOD_DEF  2                  ///< VDDIO Voltage Control default initialization is enabled
#define MEM_OC_VDDIO_CONTROL_ACCESS_TYPE_DIS      0         ///< VDDIO Voltage Control access type is disabled
#define MEM_OC_VDDIO_CONTROL_ACCESS_TYPE_INDEX_IO 1         ///< VDDIO Voltage Control access type index
#define MEM_OC_VDDIO_CONTROL_SMBUS_HC_0  0                  ///< System management bus host controller is disabled
#define MEM_OC_VDDIO_CONTROL_SMBUS_HC_1  1                  ///< System management bus host controller is enabled
#define MEM_OC_VDDIO_CONTROL_SMBUS_WRITE_BYTE 1             ///< Write system management bus host controller in bytes
#define MEM_OC_VDDIO_CONTROL_SMBUS_WRITE_WORD 2             ///< Write system management bus host controller in words
#define MEM_OC_VDDIO_CONTROL_SMBUS_ATTRIBUTE_FIXED     0    ///< System management bus (SmbusData0, SmbusData1) fixed attribute
#define MEM_OC_VDDIO_CONTROL_SMBUS_ATTRIBUTE_UPDATABLE 1    ///< System management bus (SmbusData0, SmbusData1) updatable attribute

/**
 * @brief VDDIO Voltage Control Info structure
 */
typedef struct _MEM_OC_VDDIO_VOLT_CTRL_INFO {
  UINT8                           SmbusHc;            ///< System management bus host controller
  UINT8                           SmbusAdderess;      ///< System management bus host controller address
  UINT8                           SmbusHostCmd;       ///< System management bus host controller command
  UINT8                           Operation;          ///< VDDIO Voltage Control operation mode
  UINT8                           Attr;               ///< VDDIO Voltage Control operation attribute (fixed or updatable)
  UINT8                           SmbusData0;         ///< System management data bus 0
  UINT8                           SmbusData1;         ///< System management data bus 1
} MEM_OC_VDDIO_VOLT_CTRL_INFO;

/**
 * @brief VDDIO voltage control index IO structure
 */
typedef struct _MEM_OC_VDDIO_VOLT_CTRL_INDEX_IO {
  UINT8                           AccessType;   ///< Index IO access type
  UINT8                           IndexPort;    ///< Index IO port
  UINT8                           DataPort;     ///< Index IO data port
  UINT8                           Offset;       ///< Index IO offset
} MEM_OC_VDDIO_VOLT_CTRL_INDEX_IO;

/**
 * @brief VDDIO System Management BUS control structure
 */
typedef struct _MEM_OC_VDDIO_CONTROL_SMBUS_STRUCT {
  UINT32                          Size;                     ///< Bus size
  UINT8                           Method;                   ///< Control method
  UINT8                           NumOfCtrlInfo;            ///< Number of control bus info
  MEM_OC_VDDIO_VOLT_CTRL_INDEX_IO VoltCtrlIndexIoData0;     ///< Index IO data 0
  MEM_OC_VDDIO_VOLT_CTRL_INDEX_IO VoltCtrlIndexIoData1;     ///< Index IO data 1
  MEM_OC_VDDIO_VOLT_CTRL_INFO     VoltCtrlInfo[];           ///< VDDIO voltage control info
} MEM_OC_VDDIO_CONTROL_SMBUS_STRUCT;

/**
 * @brief Config structure for Safe boot & VDDIO control bus
 */
typedef struct _MEM_OC_CONFIG_STRUCT {
  UINT32                                    Size;                     ///< Size of the configuration structure
  MEM_OC_SAFE_BOOT_CONTROL_INDEX_IO_STRUCT  SafeBootCtrlIndexIo;      ///< Instance of Safe boot control index IO structure
  MEM_OC_VDDIO_CONTROL_SMBUS_STRUCT         MemVddioCtrl;             ///< Instance of VDDIO SM BUS control structure
} MEM_OC_CONFIG_STRUCT;

#endif // _APCB_MEM_OVERCLOCK_CONFIG_H_
