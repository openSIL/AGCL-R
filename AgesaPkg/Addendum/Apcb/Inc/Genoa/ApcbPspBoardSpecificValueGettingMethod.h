/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_PSP_BOARD_SPECIFIC_VALUE_GETTING_METHOD_H_
#define _APCB_PSP_BOARD_SPECIFIC_VALUE_GETTING_METHOD_H_
//
// @APCB_START
//



///===============================================================================
// Check the board and apply a value to target

#define TARGET_TYPE_XGMI_LINK_CONFIGURATION     0x00000000


#define ACCESS_METHOD_SMBUS       1
#define ACCESS_METHOD_I2C_EEPROM  2
#define ACCESS_METHOD_GPIO        3
#define ACCESS_METHOD_ESPI_IO     4
#define ACCESS_METHOD_ACPI_RD_EC  5

typedef struct _APCB_PSP_BOARD_SPEC_COMMON {
  IN       UINT32   TargetType;         ///< The target type to apply the value
  IN       UINT32   AppliedValue;       ///< The value to be applied
  IN       UINT32   CheckedValue;       ///< The value to be checked to match the access
  IN       UINT32   CheckedMask;        ///< The mask to be applied to the value
  IN       UINT16   AccessMethod;       ///< 1: Smbus, 2: I2 EEPROM, 3: FCH GPIO, 4: IO, 0x5: EC
} APCB_PSP_BOARD_SPEC_COMMON;

/// For Smbus device method
typedef struct _APCB_PSP_BOARD_SPEC_FROM_SMBUS {
  IN       APCB_PSP_BOARD_SPEC_COMMON       Common;             ///< The common structure.
  IN       UINT16                           I2cCtrlr;           ///< ZP I2C controller: 0: I2C_0, 1: I2C_1, 2: I2C_2, 3: I2C_3, 4: I2C_4, 5: I2C_5
  IN       UINT8                            I2cMuxAddress;      ///< I2C Mux Address
  IN       UINT8                            MuxControlAddress;  ///< Mux Control Address
  IN       UINT8                            MuxChannel;         ///< I2C Mux Channel assocaited with this SPD
  IN       UINT16                           SmbusAddr;          ///< Smbus address of the device to get the board ID
  IN       UINT16                           RegIndex;           ///< Register index of the Smbus device to get the board ID
} APCB_PSP_BOARD_SPEC_FROM_SMBUS;

/// For I2 EEPROM method
typedef struct _APCB_PSP_BOARD_SPEC_FROM_EEPROM {
  IN       APCB_PSP_BOARD_SPEC_COMMON       Common;             ///< The common structure.
  IN       UINT8                            I2cCtrlr;           ///< I2C controller: 0: I2C_0, 1: I2C_1, 2: I2C_2, 3: I2C_3, 4: I2C_4, 5: I2C_5
  IN       UINT8                            I2cMuxAddr;         ///< I2C Mux Address.
  IN       UINT8                            I2cMuxCtrlAddr;     ///< I2C Mux Control address.
  IN       UINT8                            I2cMuxChnlValue;    ///< I2C Mux Channel value to switch to specific channel
  IN       UINT8                            DeviceAddr;         ///< Device address
  IN       UINT16                           BoardIdByteOffset;  ///< Board ID byte offset to read out
} APCB_PSP_BOARD_SPEC_FROM_EEPROM;

/// For FCH GPIO method
typedef struct _APCB_PSP_BOARD_SPEC_FROM_GPIO {
  IN       APCB_PSP_BOARD_SPEC_COMMON       Common;             ///< The common structure.
  IN       UINT8                            Gpio0;              ///< FCH GPIO number of the board ID bit 0
  IN       UINT8                            Gpio0IoMUX;         ///< Value write to IOMUX to configure this GPIO pin
  IN       UINT8                            Gpio0BankCtl;       ///< Value write to GPIOBankCtl[23:16] to configure this GPIO pin
  IN       UINT8                            Gpio1;              ///< FCH GPIO number of the board ID bit 1
  IN       UINT8                            Gpio1IoMUX;         ///< Value write to IOMUX to configure this GPIO pin
  IN       UINT8                            Gpio1BankCtl;       ///< Value write to GPIOBankCtl[23:16] to configure this GPIO pin
  IN       UINT8                            Gpio2;              ///< FCH GPIO number of the board ID bit 2, put 0xff if does not exist
  IN       UINT8                            Gpio2IoMUX;         ///< Value write to IOMUX to configure this GPIO pin
  IN       UINT8                            Gpio2BankCtl;       ///< Value write to GPIOBankCtl[23:16] to configure this GPIO pin
  IN       UINT8                            Gpio3;              ///< FCH GPIO number of the board ID bit 3, put 0xff if does not exist
  IN       UINT8                            Gpio3IoMUX;         ///< Value write to IOMUX to configure this GPIO pin
  IN       UINT8                            Gpio3BankCtl;       ///< Value write to GPIOBankCtl[23:16] to configure this GPIO pin
} APCB_PSP_BOARD_SPEC_FROM_GPIO;

/// For eSPI IO method
typedef struct _APCB_PSP_BOARD_SPEC_FROM_ESPI_IO {
  IN       APCB_PSP_BOARD_SPEC_COMMON       Common;             ///< The common structure.
  IN       UINT8                            eSPICtrlr;          ///< 0: eSPI0, 1: eSPI1
  IN       UINT16                           ConfigValue;        ///< Value write to Configure IO Port for accessing the data
  IN       UINT16                           ConfigPortWidth;    ///< Width of Config Port
  IN       UINT32                           ConfigPortAddress;  ///< ConfigPort Address
  IN       UINT16                           DataPortWidth;      ///< DataPort Width
  IN       UINT32                           DataPortAddress;    ///< Data Port Address
} APCB_PSP_BOARD_SPEC_FROM_ESPI_IO;

/// For ACPI Read EC command method
typedef struct _APCB_PSP_BOARD_SPEC_FROM_EC {
  IN       APCB_PSP_BOARD_SPEC_COMMON       Common;             ///< The common structure.
  IN       UINT16                           CmdStsPort;         ///< Embedded Controller Status/Command Port
  IN       UINT16                           DataPort;           ///< Embedded Controller Data Port
  IN       UINT8                            IdOffset;           ///< Board ID byte offset in the address space of the embedded controller
} APCB_PSP_BOARD_SPEC_FROM_EC;


#endif // _APCB_PSP_BOARD_SPECIFIC_VALUE_GETTING_METHOD_H_


