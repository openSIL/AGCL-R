/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_EXT_VOLTAGE_CONTROL_H_
#define _APCB_MEM_EXT_VOLTAGE_CONTROL_H_
//
// @APCB_START
//


///===============================================================================
/// PSP_EXT_VOLTAGE_CONTROL_STRUCT
/// This data structure is used to control sending AGESA volatage info to the specified port
///
typedef struct _PSP_EXT_VOLTAGE_CONTROL_STRUCT {
  IN
  BOOLEAN ExtVoltageControlEnable;             ///< Indicates if ABL will supprot external voltage changes
                                               ///< TRUE - External voltage change are supported
                                               ///< FALSE - No external voltage change are supported (Default)
  IN
  UINT32  ExtVoltageInputPort;                 ///< Input Port to receive voltage information  (Default = 0x84)
  IN
  UINT32  ExtVoltageOutputPort;                ///< Output Port to send voltage (Default = 0x80)
  IN
  UINT32  ExtVoltageInputPortSize;             ///< Indicates the sie of the input and outut port
                                               ///< 1 - 8 bit port
                                               ///< 2 - 16 bit port
                                               ///< 4 - 32 bit port (Default)
  IN
  UINT32  ExtVoltageOutputPortSize;            ///< Indicates the sie of the input and outut port
                                               ///< 1 - 8 bit port
                                               ///< 2 - 16 bit port
                                               ///< 4 - 32 bit port (Default)
  IN
  UINT32  ExtVoltageInputPortType;              ///< Indicates the type of Input Port or location of the port
                                                ///< 0 - PCIE HT0
                                                ///< 2 - PCIE HT1
                                                ///< 5 - PCIE MMIO
                                                ///< 6 - FCH_HT_IO (Default)
                                                ///< 7 - FCH_MMIO
  IN
  UINT32  ExtVoltageOutputPortType;             ///< Indicates the type of Output Port or location of the port
                                                ///< 0 - PCIE HT0
                                                ///< 2 - PCIE HT1
                                                ///< 5 - PCIE MMIO
                                                ///< 6 - FCH_HT_IO (Default)
                                                ///< 7 - FCH_MMIO

  IN
  BOOLEAN  ExtVoltageClearAcknowledgement;     ///< Indicates if the ABL will clear acknolgements during protocol
                                               ///< TRUE - Clear acknowledgemetns (Default)
                                               ///< FALSE - Do not clear acknologements
} PSP_EXT_VOLTAGE_CONTROL_STRUCT;

#endif // _APCB_MEM_EXT_VOLTAGE_CONTROL_H_


