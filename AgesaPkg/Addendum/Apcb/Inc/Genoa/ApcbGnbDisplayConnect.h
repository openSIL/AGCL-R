/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_GNB_DISPLAY_CONNECT_H_
#define _APCB_GNB_DISPLAY_CONNECT_H_

//
// @APCB_START
//

/// External Display Path
/** APCB_DISPLAY_CONNECT_ENTRY
*   @GROUPID: APCB_GROUP_GNB
*   @TYPEID: APCB_GNB_TYPE_DISPLAY_CONNECT (0x1001)
*   @INSTANCEID: 0
*   N/A
*/
typedef struct _APCB_DISPLAY_CONNECT_ENTRY {
  UINT16                      usDeviceTag;          ///< A bit vector to show what devices are supported
  UINT16                      usDeviceACPIEnum;     ///< 16bit device ACPI id.
  UINT16                      usDeviceConnector;    ///< A physical connector for displays to plug in, using object connector definitions
  UINT8                       ucExtAUXDDCLutIndex;  ///< An index into external AUX/DDC channel LUT
  UINT8                       ucExtHPDPINLutIndex;  ///< An index into external HPD pin LUT
  UINT16                      usExtEncoderObjId;    ///< external encoder object id
  UINT8                       ucChannelMapping;     ///< lane mapping on connector (ucChannelMapping=0 use default)
  UINT8                       ucChPNInvert;         ///< Bit vector for up to 8 lanes. 0: P and N is not invert, 1: P and N is inverted
  UINT16                      usCaps;               ///< Capabilities IF BIT[0] == 1, downgrade phy link to DP1.1
  UINT16                      usReserved;           ///< Reserved
} APCB_DISPLAY_CONNECT_ENTRY;
#endif // _APCB_GNB_DISPLAY_CONNECT_H_
