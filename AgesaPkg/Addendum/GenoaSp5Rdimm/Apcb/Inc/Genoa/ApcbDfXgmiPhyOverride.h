/*****************************************************************************
 *
 * Copyright (C) 2019-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_DF_XGMI_PHY_OVERRIDE_H_
#define _APCB_DF_XGMI_PHY_OVERRIDE_H_

//
// @APCB_START
//

/**
 *  @brief xGMI PHY override table header.
 *  @details This data structure is used to pass xGMI override parameters to DXIO PHY FW.
 */
typedef struct _XGMI_PHY_OVERRIDE_HEADER {
  UINT32   DescriptorType :8;   ///< PHY FW table descriptor type (6 for xGMI)
  UINT32   Version        :4;   ///< PHY FW table version number
  UINT32                  :4;   ///< Reserved
  UINT32   NumEntries     :8;   ///< Number of xGMI PHY override link entries
  UINT32                  :8;   ///< Reserved
} XGMI_PHY_OVERRIDE_HEADER;

/**
 *  @brief xGMI PHY override link entry.
 *  @details This data structure is used to pass xGMI link override parameters to DXIO PHY FW.
 */
typedef struct _XGMI_PHY_OVERRIDE_LINK_ENTRY {
  UINT32   ParameterId  :8;     ///< PHY FW table parameter ID
  UINT32   ColumnId     :8;     ///< PHY FW table column ID (correspond to PHY speeds(Gbps): 1:1.5-2, 2:2.5-6, 3:6.4-9, 4:10-15, 5:16-18, 6:19-25)
  UINT32   Value        :8;     ///< PHY FW table value
  UINT32   LaneNumber   :8;     ///< Lane numbers to apply setting to
} XGMI_PHY_OVERRIDE_LINK_ENTRY;

/**
 *  @brief xGMI PHY override table.
 *  @details This data structure is used to pass xGMI override parameters to DXIO PHY FW.
 */
typedef struct _XGMI_PHY_OVERRIDE_TABLE {
  XGMI_PHY_OVERRIDE_HEADER        Header;       ///< xGMI PHY Override header. @see XGMI_PHY_OVERRIDE_HEADER
  XGMI_PHY_OVERRIDE_LINK_ENTRY    LinkEntry[];  ///< xGMI PHY Override entries. @see XGMI_PHY_OVERRIDE_LINK_ENTRY
} XGMI_PHY_OVERRIDE_TABLE;

#endif // _APCB_DF_XGMI_PHY_OVERRIDE_H_

