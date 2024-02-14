/*****************************************************************************
 *
 * Copyright (C) 2019-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_GNB_DP_PHY_STATIC_CONNECT_H_
#define _APCB_GNB_DP_PHY_STATIC_CONNECT_H_

#if defined __GNUC__
#include <stdint.h>
#else
typedef unsigned long long  uint64_t;
typedef long long           int64_t;
typedef unsigned int        uint32_t;
typedef int                 int32_t;
typedef unsigned short      uint16_t;
typedef short               int16_t;
typedef unsigned char       uint8_t;
typedef signed char         int8_t;
#endif
//
// @APCB_START
//

/// External Display Path
/** APCB_DP_PHY_STATIC_CONNECT_ENTRY
*   @GROUPID: APCB_GROUP_GNB
*   @TYPEID: APCB_GNB_TYPE_DP_PHY_STATIC_CONNECT (0x1002)
*   @INSTANCEID: 0
*   N/A
*/

/****************************************************************************
* Common header for all tables (Data table, Command function).
* Every table pointed in _ATOM_MASTER_DATA_TABLE has this common header.
* And the pointer actually points to this header.
****************************************************************************/
//IPCLEAN_END
typedef struct _atom_common_table_header {
  uint16_t structuresize;
  uint8_t  format_revision;   //mainly used for a hw function, when the parser is not backward compatible
  uint8_t  content_revision;  //change it when a data table has a structure change, or a hw function has a input/output parameter change
} atom_common_table_header;

/*
  ***************************************************************************
    Data Table ATOM_EXTERNAL_DISPLAY_CONNECTION_INFO  structure
  ***************************************************************************
*/
typedef struct _atom_ext_display_path
{
  uint16_t  device_tag;                      //A bit vector to show what devices are supported
  uint16_t  device_acpi_enum;                //16bit device ACPI id.
  uint16_t  connectorobjid;                  //A physical connector for displays to plug in, using object connector definitions
  uint8_t   auxddclut_index;                 //An index into external AUX/DDC channel LUT
  uint8_t   hpdlut_index;                    //An index into external HPD pin LUT
  uint16_t  ext_encoder_objid;               //external encoder object id
  uint8_t   channelmapping;                  // if ucChannelMapping=0, using default one to one mapping
  uint8_t   chpninvert;                      // bit vector for up to 8 lanes, =0: P and N is not invert, =1 P and N is inverted
  uint16_t  caps;
  uint16_t  reserved;
} atom_ext_display_path;

//usCaps
enum ext_display_path_cap_def {
  EXT_DISPLAY_PATH_CAPS__HBR2_DISABLE                             =0x0001,
  EXT_DISPLAY_PATH_CAPS__DP_FIXED_VS_EN                           =0x0002,
  EXT_DISPLAY_PATH_CAPS__EXT_CHIP_MASK                            =0x007C,
  EXT_DISPLAY_PATH_CAPS__HDMI20_PI3EQX1204                        =(0x01 << 2 ),     //PI redriver chip
  EXT_DISPLAY_PATH_CAPS__HDMI20_TISN65DP159RSBT                   =(0x02 << 2 ),     //TI retimer chip
  EXT_DISPLAY_PATH_CAPS__HDMI20_PARADE_PS175                      =(0x03 << 2 ),     //Parade DP->HDMI recoverter chip
  EXT_DISPLAY_PATH_CAPS__HBR3_DISABLE                             =0x0080,
  EXT_DISPLAY_PATH_CAPS__USB_C_TYPE                               =0x100,            // the DP connector is a USB-C type.
  EXT_DISPLAY_PATH_CAPS__HDMI20_DISABLE                           =0x200,            // HDMI2.0 6GBPS disable
};

typedef struct _atom_external_display_connection_info {
  atom_common_table_header  table_header;
  uint8_t                   guid[16];                                  // a GUID is a 16 byte long string
  atom_ext_display_path     path[7];                                   // total of fixed 7 entries.
  uint8_t                   checksum;                                  // a simple Checksum of the sum of whole structure equal to 0x0.
  uint8_t                   stereopinid;                               // use for eDP panel
  uint8_t                   remotedisplayconfig;
  uint8_t                   edptolvdsrxid;
  uint8_t                   fixdpvoltageswing;                         // usCaps[1]=1, this indicate DP_LANE_SET value
  uint8_t                   reserved[3];                               // for potential expansion
} atom_external_display_connection_info;

typedef struct _atom_phy_static_info_v1_0 {
  atom_common_table_header              table_header;
  atom_external_display_connection_info extdispconninfo;
  uint8_t                               modern_standby_resume;          /*0: Normal boot up; 1: Resume from modern standby/S3 */
  uint8_t                               DP_dphy_tx_vboost_lvl[5];
  uint8_t                               DP_dphy_tx_term_ctrl[5];
  uint8_t                               reserved[1];
  uint32_t                              reserved2[89];
} atom_phy_static_info_v1_0, APCB_STATIC_INFO_V1_0_CONNECT_ENTRY;
#endif // _APCB_GNB_DP_PHY_STATIC_CONNECT_H_
