/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_DF_XGMI_TX_EQ_H_
#define _APCB_DF_XGMI_TX_EQ_H_

/**
 *  @brief Macro for setting specifed bit postion to one.
 *  @param[in] Position Specifies the bit postion to set to one.
 *  @details This is a macro that shifts one into the specified position.
 */
#define XGMI_BIT_POS(Position)                  (1 << Position)

#define XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT       28        ///< xGMI TX EQ common node type shift distance (NOTE: Bit28~31 are used as NodeType in common).
#define XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK   0x0F      ///< xGMI TX EQ common node type bit mask size.
#define XGMI_TX_EQ_COMMON_NODE_TYPE_MASK        (XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT)      ///< xGMI TX EQ common node type bit mask.

/**
 *  @brief xGMI TX EQ shared node type definitions.
 *  @details This enumerator provides xGMI TX EQ node types.
 */
typedef enum {
   XGMI_TX_EQ_NODE_TYPE_RSVD      = 0x0,      ///< Reserved node.
   XGMI_TX_EQ_NODE_TYPE_DATA      = 0x1,      ///< Data node.
   XGMI_TX_EQ_NODE_TYPE_LOC       = 0x2,      ///< Location node
   XGMI_TX_EQ_NODE_TYPE_FREQ      = 0x3,      ///< Frequency node.
   XGMI_TX_EQ_NODE_TYPE_FREQ_TBL  = 0x4,      ///< Frequency Table node.
   XGMI_TX_EQ_NODE_TYPE_FREQ_END  = 0x5,      ///< Frequency Table Termination node.
   XGMI_TX_EQ_NODE_TYPE_END       = 0xF       ///< Termination node.
} XGMI_TX_EQ_NODE_TYPE;

/**
 *  @brief xGMI TX EQ common attribute.
 *  @details xGMI TX EQ MAKE_TX_EQ_FREQ_TABLE attribute. @see MAKE_TX_EQ_FREQ_TABLE
 */
typedef struct _XGMI_TX_EQ_COMMON {
  UINT32  :24;                      ///< Reserved
  UINT32  :4;                       ///< Reserved
  UINT32  NodeType:4;               ///< Node type
} XGMI_TX_EQ_COMMON;

#define XGMI_TX_EQ_FREQ_SPEED_MASK_SHIFT        0                   ///< xGMI TX EQ frequency speed shift distance.
#define XGMI_TX_EQ_FREQ_SPEED_MASK_SIZE_MASK    0xFF                ///< xGMI TX EQ frequency speed bit mask size.
#define XGMI_TX_EQ_FREQ_SPEED_MASK_MASK         (XGMI_TX_EQ_FREQ_SPEED_MASK_SIZE_MASK << XGMI_TX_EQ_FREQ_SPEED_MASK_SHIFT)      ///< xGMI TX EQ frequency speed bit mask.
#define   XGMI_TX_EQ_SPEED_53                   XGMI_BIT_POS(0)     ///< Instance ID of 5.3G speed.
#define   XGMI_TX_EQ_SPEED_64                   XGMI_BIT_POS(1)     ///< Instance ID of 6.4G speed.
#define   XGMI_TX_EQ_SPEED_75                   XGMI_BIT_POS(2)     ///< Instance ID of 7.5G speed.
#define   XGMI_TX_EQ_SPEED_85                   XGMI_BIT_POS(3)     ///< Instance ID of 8.5G speed.
#define   XGMI_TX_EQ_SPEED_96                   XGMI_BIT_POS(4)     ///< Instance ID of 9.6G speed.
#define   XGMI_TX_EQ_SPEED_107                  XGMI_BIT_POS(5)     ///< Instance ID of 10.7G speed.
#define   XGMI_TX_EQ_SPEED_117                  XGMI_BIT_POS(6)     ///< Instance ID of 11.7G speed.
#define   XGMI_TX_EQ_SPEED_128                  XGMI_BIT_POS(7)     ///< Instance ID of 12.8G speed.
/// All xGMI TX EQ speeds.
#define   XGMI_TX_EQ_SPEED_ALL                  (XGMI_TX_EQ_SPEED_53 | XGMI_TX_EQ_SPEED_64 | XGMI_TX_EQ_SPEED_75 | XGMI_TX_EQ_SPEED_85 | XGMI_TX_EQ_SPEED_96 | XGMI_TX_EQ_SPEED_107 | XGMI_TX_EQ_SPEED_117 | XGMI_TX_EQ_SPEED_128)

/**
 *  @brief xGMI TX EQ frequency attribute.
 *  @details xGMI TX EQ MAKE_TX_EQ_FREQ_TABLE attribute. @see MAKE_TX_EQ_FREQ_TABLE
 */
typedef struct _XGMI_TX_EQ_FREQ {
  UINT32  SpeedMask:8;            ///< Speed mask
  UINT32  :16;                    ///< Reserved
  UINT32  :4;                     ///< Reserved
  UINT32  NodeType:4;             ///< Node type: MAKE_TX_EQ_FREQ_TABLE
} XGMI_TX_EQ_FREQ;

/**
 *  @brief Macro for creating xGMI TX EQ frequency entry.
 *  @param[in] SpeedMask Specifies speeds (or instance IDs) for this entry.
 *  @details This is a macro that masks & shifts the speed mask into position. @see XGMI_TX_EQ_FREQ
 */
#define MAKE_TX_EQ_FREQ(SpeedMask)               ((UINT32) (((XGMI_TX_EQ_NODE_TYPE_FREQ & XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK) << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT) | \
                                                                   ((SpeedMask & XGMI_TX_EQ_FREQ_SPEED_MASK_SIZE_MASK) << XGMI_TX_EQ_FREQ_SPEED_MASK_SHIFT)))
/**
 *  @brief Macro for creating xGMI TX EQ frequency table entry.
 *  @param[in] SpeedMask Specifies xGMI TX EQ speeds (or instance IDs) for this entry.
 *  @details This is a macro that masks & shifts the speed mask into position. @see XGMI_TX_EQ_FREQ
 */
#define MAKE_TX_EQ_FREQ_TBL(SpeedMask)           ((UINT32) (((XGMI_TX_EQ_NODE_TYPE_FREQ_TBL & XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK) << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT) | \
                                                                   ((SpeedMask & XGMI_TX_EQ_FREQ_SPEED_MASK_SIZE_MASK) << XGMI_TX_EQ_FREQ_SPEED_MASK_SHIFT)))

#define XGMI_TX_EQ_ATTR_LANE_MASK_SHIFT         0           ///< xGMI TX EQ lane attribute mask shift distance.
#define XGMI_TX_EQ_ATTR_LANE_MASK_SIZE_MASK     0xFFFF      ///< xGMI TX EQ lane attribute mask size mask.
#define XGMI_TX_EQ_ATTR_LANE_MASK_MASK          (XGMI_TX_EQ_ATTR_LANE_MASK_SIZE_MASK << XGMI_TX_EQ_ATTR_LANE_MASK_SHIFT)        ///< xGMI TX EQ lane attribute mask.
#define XGMI_TX_EQ_ATTR_DIE_MASK_SHIFT          16          ///< xGMI TX EQ die attribute mask shift distance.
#define XGMI_TX_EQ_ATTR_DIE_MASK_SIZE_MASK      0xFF        ///< xGMI TX EQ die attribute mask size mask.
#define XGMI_TX_EQ_ATTR_DIE_MASK_MASK           (XGMI_TX_EQ_ATTR_DIE_MASK_SIZE_MASK << XGMI_TX_EQ_ATTR_DIE_MASK_SHIFT)          ///< xGMI TX EQ die attribute mask.
#define XGMI_TX_EQ_ATTR_SOCKET_MASK_SHIFT       24          ///< xGMI TX EQ socket attribute mask shift distance.
#define XGMI_TX_EQ_ATTR_SOCKET_MASK_SIZE_MASK   0x03        ///< xGMI TX EQ socket attribute mask size mask.
#define XGMI_TX_EQ_ATTR_SOCKET_MASK_MASK        (XGMI_TX_EQ_ATTR_SOCKET_MASK_SIZE_MASK << XGMI_TX_EQ_ATTR_SOCKET_MASK_SHIFT)    ///< xGMI TX EQ socket attribute mask.
#define XGMI_TX_EQ_ATTR_DATA_MODE_SHIFT         26          ///< xGMI TX EQ data mode attribute mask shift distance.
#define XGMI_TX_EQ_ATTR_DATA_MODE_SIZE_MASK     0x03        ///< xGMI TX EQ data mode attribute mask size mask.
#define XGMI_TX_EQ_ATTR_DATA_MODE_MASK          (XGMI_TX_EQ_ATTR_DATA_MODE_SIZE_MASK << XGMI_TX_EQ_ATTR_DATA_MODE_SHIFT)        ///< xGMI TX EQ data mode attribute mask.

/**
 *  @brief xGMI TX EQ data mode definitions.
 *  @details This enumerator provides xGMI TX EQ data modes.
 */
typedef enum {
   XGMI_TX_EQ_DATA_MODE_PAIR         = 0,       ///< Pair mode, same value for all matched lanes.
   XGMI_TX_EQ_DATA_MODE_LIST         = 1,       ///< List mode, list each value for each matched lanes from low to high socket/die/lane.
   XGMI_TX_EQ_DATA_MODE_LIST_COMPACT = 2,       ///< List compact mode, list each value for each matched lanes from low to high socket/die/lane in compact format
   XGMI_TX_EQ_DATA_MODE_MAX          = 3        ///< Maximum data mode
} XGMI_TX_EQ_DATA_MODE;

#define XGMI_ALL_SOCKETS                        0x03                  ///< Bit mask for all sockets per system.
#define XGMI_MAX_SOCKET_COUNT                   2                     ///< Maximum number of sockets per system.
#define XGMI_ALL_DIES                           0x0F                  ///< Bit mask for all dies per socket.
#define XGMI_MAX_DIE_COUNT_PER_SOCKET           4                     ///< Maximum number of die per socket.
#define XGMI_ALL_LANES                          0xFFFF                ///< Bit mask for all lanes per die.
#define XGMI_MAX_LANE_COUNT_PER_DIE             16                    ///< Maximum number of lanes per die.
#define XGMI_SOCKET0                            XGMI_BIT_POS(0)       ///< Bit mask for socket 0.
#define XGMI_SOCKET1                            XGMI_BIT_POS(1)       ///< Bit mask for socket 1.
#define XGMI_DIE0                               XGMI_BIT_POS(0)       ///< Bit mask for die 0 on socket.
#define XGMI_DIE1                               XGMI_BIT_POS(1)       ///< Bit mask for die 1 on socket.
#define XGMI_DIE2                               XGMI_BIT_POS(2)       ///< Bit mask for die 2 on socket.
#define XGMI_DIE3                               XGMI_BIT_POS(3)       ///< Bit mask for die 3 on socket.
#define XGMI_DIE4                               XGMI_BIT_POS(4)       ///< Bit mask for die 4 on socket.
#define XGMI_DIE5                               XGMI_BIT_POS(5)       ///< Bit mask for die 5 on socket.
#define XGMI_DIE6                               XGMI_BIT_POS(6)       ///< Bit mask for die 6 on socket.
#define XGMI_DIE7                               XGMI_BIT_POS(7)       ///< Bit mask for die 7 on socket.
#define XGMI_LANE0                              XGMI_BIT_POS(0)       ///< Bit mask for lane 0 on die.
#define XGMI_LANE1                              XGMI_BIT_POS(1)       ///< Bit mask for lane 1 on die.
#define XGMI_LANE2                              XGMI_BIT_POS(2)       ///< Bit mask for lane 2 on die.
#define XGMI_LANE3                              XGMI_BIT_POS(3)       ///< Bit mask for lane 3 on die.
#define XGMI_LANE4                              XGMI_BIT_POS(4)       ///< Bit mask for lane 4 on die.
#define XGMI_LANE5                              XGMI_BIT_POS(5)       ///< Bit mask for lane 5 on die.
#define XGMI_LANE6                              XGMI_BIT_POS(6)       ///< Bit mask for lane 6 on die.
#define XGMI_LANE7                              XGMI_BIT_POS(7)       ///< Bit mask for lane 7 on die.
#define XGMI_LANE8                              XGMI_BIT_POS(8)       ///< Bit mask for lane 8 on die.
#define XGMI_LANE9                              XGMI_BIT_POS(9)       ///< Bit mask for lane 9 on die.
#define XGMI_LANE10                             XGMI_BIT_POS(10)      ///< Bit mask for lane 10 on die.
#define XGMI_LANE11                             XGMI_BIT_POS(11)      ///< Bit mask for lane 11 on die.
#define XGMI_LANE12                             XGMI_BIT_POS(12)      ///< Bit mask for lane 12 on die.
#define XGMI_LANE13                             XGMI_BIT_POS(13)      ///< Bit mask for lane 13 on die.
#define XGMI_LANE14                             XGMI_BIT_POS(14)      ///< Bit mask for lane 14 on die.
#define XGMI_LANE15                             XGMI_BIT_POS(15)      ///< Bit mask for lane 15 on die.

/**
 *  @brief xGMI TX EQ apply attribute.
 *  @details xGMI TX EQ MAKE_TX_EQ_ATTR attribute. @see MAKE_TX_EQ_ATTR
 */
typedef struct _XGMI_TX_EQ_ATTR {
  UINT32  LaneMask:16;            ///< Lane mask per die       (2^4)
  UINT32  DieMask:8;              ///< Die mask per socket     (2^3)
  UINT32  SocketMask:2;           ///< Socket mask per system  (2^1)
  UINT32  DataMode:2;             ///< Data mode. Pair or List
  UINT32  NodeType:4;             ///< Node type: Location
} XGMI_TX_EQ_ATTR;

/**
 *  @brief Macro for creating xGMI TX EQ attribute.
 *  @param[in] SocketMask   Specifies socket bit mask for this attribute.
 *  @param[in] DieMask      Specifies die bit mask for this attribute.
 *  @param[in] LaneMask     Specifies lane bit mask for this attribute.
 *  @param[in] DataMask     Specifies data bit mask for this attribute.
 *  @details This is a macro that combines socket, die, lane, and data bit masks to make an xGMI TX EQ attribute. @see XGMI_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_ATTR(SocketMask, DieMask, LaneMask, DataMode)  ((UINT32) (((XGMI_TX_EQ_NODE_TYPE_LOC & XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK) << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT) | \
                                                                   ((DataMode & XGMI_TX_EQ_ATTR_DATA_MODE_SIZE_MASK) << XGMI_TX_EQ_ATTR_DATA_MODE_SHIFT) | \
                                                                   ((SocketMask & XGMI_TX_EQ_ATTR_SOCKET_MASK_SIZE_MASK) << XGMI_TX_EQ_ATTR_SOCKET_MASK_SHIFT) | \
                                                                   ((DieMask & XGMI_TX_EQ_ATTR_DIE_MASK_SIZE_MASK) << XGMI_TX_EQ_ATTR_DIE_MASK_SHIFT) | \
                                                                   ((LaneMask & XGMI_TX_EQ_ATTR_LANE_MASK_SIZE_MASK) << XGMI_TX_EQ_ATTR_LANE_MASK_SHIFT)))

#define XGMI_TX_EQ_DATA_EQ_PRE_SHIFT            0         ///< xGMI TX EQ pre data shift distance.
#define XGMI_TX_EQ_DATA_EQ_PRE_SIZE_MASK        0x3F      ///< xGMI TX EQ pre data mask size.
#define XGMI_TX_EQ_DATA_EQ_PRE_MASK             (XGMI_TX_EQ_DATA_EQ_PRE_SIZE_MASK << XGMI_TX_EQ_DATA_EQ_PRE_SHIFT)        ///< xGMI TX EQ pre data mask.
#define XGMI_TX_EQ_DATA_EQ_MAIN_SHIFT           8         ///< xGMI TX EQ main data shift distance.
#define XGMI_TX_EQ_DATA_EQ_MAIN_SIZE_MASK       0x3F      ///< xGMI TX EQ main data mask size.
#define XGMI_TX_EQ_DATA_EQ_MAIN_MASK            (XGMI_TX_EQ_DATA_EQ_MAIN_SIZE_MASK << XGMI_TX_EQ_DATA_EQ_MAIN_SHIFT)      ///< xGMI TX EQ main data mask.
#define XGMI_TX_EQ_DATA_EQ_POST_SHIFT           16        ///< xGMI TX EQ post data shift distance.
#define XGMI_TX_EQ_DATA_EQ_POST_SIZE_MASK       0x3F      ///< xGMI TX EQ post data mask size.
#define XGMI_TX_EQ_DATA_EQ_POST_MASK            (XGMI_TX_EQ_DATA_EQ_POST_SIZE_MASK << XGMI_TX_EQ_DATA_EQ_POST_SHIFT)      ///< xGMI TX EQ post data mask.
// NOTE: Bit28~31 are used as NodeType in common.

/**
 *  @brief xGMI TX EQ settings.
 *  @details xGMI TX EQ MAKE_TX_EQ_DATA settings. @see MAKE_TX_EQ_DATA
 */
typedef struct _XGMI_TX_EQ_DATA {
  UINT32  EqPre:6;                ///< EQ_PRE/TxCoeffPre
  UINT32  :2;                     ///< Reserved
  UINT32  EqMain:6;               ///< EQ_MAIN/TxCoeffCurs
  UINT32  :2;                     ///< Reserved
  UINT32  EqPost:6;               ///< EQ_POST/TxCoeffPost
  UINT32  :2;                     ///< Reserved
  UINT32  :4;                     ///< Reserved
  UINT32  NodeType:4;             ///< Node type: Data
} XGMI_TX_EQ_DATA;

/**
 *  @brief Macro for creating xGMI TX EQ data entry.
 *  @param[in] EqMain   Specifies EQ main data for this entry.
 *  @param[in] EqPost   Specifies EQ post data for this entry.
 *  @param[in] EqPre    Specifies EQ pre data for this entry.
 *  @details This is a macro that combines EqMain, EqPost, and EqPre data to make an xGMI TX EQ settings entry. @see XGMI_TX_EQ_DATA
 */
#define MAKE_TX_EQ_DATA(EqMain, EqPost, EqPre)          ((UINT32) (((XGMI_TX_EQ_NODE_TYPE_DATA & XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK) << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT) | \
                                                                   ((EqPost & XGMI_TX_EQ_DATA_EQ_POST_SIZE_MASK) << XGMI_TX_EQ_DATA_EQ_POST_SHIFT) | \
                                                                   ((EqMain & XGMI_TX_EQ_DATA_EQ_MAIN_SIZE_MASK) << XGMI_TX_EQ_DATA_EQ_MAIN_SHIFT) | \
                                                                   ((EqPre & XGMI_TX_EQ_DATA_EQ_PRE_SIZE_MASK) << XGMI_TX_EQ_DATA_EQ_PRE_SHIFT)))

#define XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_SHIFT            0                                     ///< Compact xGMI TX EQ pre data shift distance.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_SIZE_MASK        XGMI_TX_EQ_DATA_EQ_PRE_SIZE_MASK      ///< Compact xGMI TX EQ pre data mask size.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_MASK             (XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_SIZE_MASK << XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_SHIFT)        ///< Compact xGMI TX EQ pre data mask.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_SHIFT           6                                     ///< Compact xGMI TX EQ main data shift distance.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_SIZE_MASK       XGMI_TX_EQ_DATA_EQ_MAIN_SIZE_MASK     ///< Compact xGMI TX EQ main data mask size.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_MASK            (XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_SIZE_MASK << XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_SHIFT)      ///< Compact xGMI TX EQ main data mask.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_POST_SHIFT           12                                    ///< Compact xGMI TX EQ post data shift distance.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_POST_SIZE_MASK       XGMI_TX_EQ_DATA_EQ_POST_SIZE_MASK     ///< Compact xGMI TX EQ post data mask size.
#define XGMI_TX_EQ_DATA_COMPACT_EQ_POST_MASK            (XGMI_TX_EQ_DATA_COMPACT_EQ_POST_SIZE_MASK << XGMI_TX_EQ_DATA_COMPACT_EQ_POST_SHIFT)      ///< Compact xGMI TX EQ post data mask.

/**
 *  @brief Compact xGMI TX EQ data list.
 *  @details xGMI TX EQ lane settings arranged compactly, divided on double word (32-bit) boundaries.
 */
typedef struct _XGMI_TX_EQ_DATA_LIST_COMPACT {
  UINT32  EqPre0:6;                           ///< EQ_PRE/TxCoeffPre for 0
  UINT32  EqMain0:6;                          ///< EQ_MAIN/TxCoeffCurs for 0
  UINT32  EqPost0:6;                          ///< EQ_POST/TxCoeffPost for 0
  UINT32  EqPre1:6;                           ///< EQ_PRE/TxCoeffPre for 1
  UINT32  EqMain1:6;                          ///< EQ_MAIN/TxCoeffCurs for 1
  UINT32  EqPost1_1_0:2;                      ///< EQ_POST/TxCoeffPost for 1

  UINT32  EqPost1_5_2:4;                      ///< EQ_POST/TxCoeffPost for 1
  UINT32  EqPre2:6;                           ///< EQ_PRE/TxCoeffPre for 2
  UINT32  EqMain2:6;                          ///< EQ_MAIN/TxCoeffCurs for 2
  UINT32  EqPost2:6;                          ///< EQ_POST/TxCoeffPost for 2
  UINT32  EqPre3:6;                           ///< EQ_PRE/TxCoeffPre for 3
  UINT32  EqMain3_3_0:4;                      ///< EQ_MAIN/TxCoeffCurs for 3

  UINT32  EqMain3_5_4:2;                      ///< EQ_MAIN/TxCoeffCurs for 3
  UINT32  EqPost3:6;                          ///< EQ_POST/TxCoeffPost for 3
  UINT32  EqPre4:6;                           ///< EQ_PRE/TxCoeffPre for 4
  UINT32  EqMain4:6;                          ///< EQ_MAIN/TxCoeffCurs for 4
  UINT32  EqPost4:6;                          ///< EQ_POST/TxCoeffPost for 4
  UINT32  EqPre5:6;                           ///< EQ_PRE/TxCoeffPre for 5

  UINT32  EqMain5:6;                          ///< EQ_MAIN/TxCoeffCurs for 5
  UINT32  EqPost5:6;                          ///< EQ_POST/TxCoeffPost for 5
  UINT32  EqPre6:6;                           ///< EQ_PRE/TxCoeffPre for 6
  UINT32  EqMain6:6;                          ///< EQ_MAIN/TxCoeffCurs for 6
  UINT32  EqPost6:6;                          ///< EQ_POST/TxCoeffPost for 6
  UINT32  EqPre7_1_0:2;                       ///< EQ_PRE/TxCoeffPre for 7

  UINT32  EqPre7_5_2:4;                       ///< EQ_PRE/TxCoeffPre for 7
  UINT32  EqMain7:6;                          ///< EQ_MAIN/TxCoeffCurs for 7
  UINT32  EqPost7:6;                          ///< EQ_POST/TxCoeffPost for 7
  UINT32  EqPre8:6;                           ///< EQ_PRE/TxCoeffPre for 8
  UINT32  EqMain8:6;                          ///< EQ_MAIN/TxCoeffCurs for 8
  UINT32  EqPost8_3_0:4;                      ///< EQ_POST/TxCoeffPost for 8

  UINT32  EqPost8_5_4:2;                      ///< EQ_POST/TxCoeffPost for 8
  UINT32  EqPre9:6;                           ///< EQ_PRE/TxCoeffPre for 9
  UINT32  EqMain9:6;                          ///< EQ_MAIN/TxCoeffCurs for 9
  UINT32  EqPost9:6;                          ///< EQ_POST/TxCoeffPost for 9
  UINT32  EqPre10:6;                          ///< EQ_PRE/TxCoeffPre for 10
  UINT32  EqMain10:6;                         ///< EQ_MAIN/TxCoeffCurs for 10

  UINT32  EqPost10:6;                         ///< EQ_POST/TxCoeffPost for 10
  UINT32  EqPre11:6;                          ///< EQ_PRE/TxCoeffPre for 11
  UINT32  EqMain11:6;                         ///< EQ_MAIN/TxCoeffCurs for 11
  UINT32  EqPost11:6;                         ///< EQ_POST/TxCoeffPost for 11
  UINT32  EqPre12:6;                          ///< EQ_PRE/TxCoeffPre for 12
  UINT32  EqMain12_1_0:2;                     ///< EQ_MAIN/TxCoeffCurs for 12

  UINT32  EqMain12_5_2:4;                     ///< EQ_MAIN/TxCoeffCurs for 12
  UINT32  EqPost12:6;                         ///< EQ_POST/TxCoeffPost for 12
  UINT32  EqPre13:6;                          ///< EQ_PRE/TxCoeffPre for 13
  UINT32  EqMain13:6;                         ///< EQ_MAIN/TxCoeffCurs for 13
  UINT32  EqPost13:6;                         ///< EQ_POST/TxCoeffPost for 13
  UINT32  EqPre14_3_0:4;                      ///< EQ_PRE/TxCoeffPre for 14

  UINT32  EqPre14_5_4:2;                      ///< EQ_PRE/TxCoeffPre for 14
  UINT32  EqMain14:6;                         ///< EQ_MAIN/TxCoeffCurs for 14
  UINT32  EqPost14:6;                         ///< EQ_POST/TxCoeffPost for 14
  UINT32  EqPre15:6;                          ///< EQ_PRE/TxCoeffPre for 15
  UINT32  EqMain15:6;                         ///< EQ_MAIN/TxCoeffCurs for 15
  UINT32  EqPost15:6;                         ///< EQ_POST/TxCoeffPost for 15

} XGMI_TX_EQ_DATA_LIST_COMPACT;

/**
 *  @brief Macro for creating compact xGMI TX EQ data list entry.
 *  @param[in] EqMain   Specifies EQ main data for this entry.
 *  @param[in] EqPost   Specifies EQ post data for this entry.
 *  @param[in] EqPre    Specifies EQ pre data for this entry.
 *  @details This is a macro that combines EqMain, EqPost, and EqPre data to make a compact xGMI TX EQ list entry.
 *  @see XGMI_TX_EQ_DATA
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB(EqMain, EqPost, EqPre)     ((UINT32) ( \
                                                                                ((EqPost & XGMI_TX_EQ_DATA_COMPACT_EQ_POST_SIZE_MASK) << XGMI_TX_EQ_DATA_COMPACT_EQ_POST_SHIFT) | \
                                                                                ((EqMain & XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_SIZE_MASK) << XGMI_TX_EQ_DATA_COMPACT_EQ_MAIN_SHIFT) | \
                                                                                ((EqPre & XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_SIZE_MASK) << XGMI_TX_EQ_DATA_COMPACT_EQ_PRE_SHIFT)))
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW0_1ST(EqDw0)         ((UINT32)  EqDw0 & 0x3FFFF)         ///< Lane0 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW0
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW0_2ND(EqDw1)         (((UINT32) EqDw1 & 0x03FFF) << 18)  ///< Lane1 14 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW0

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW1_1ST(EqDw1)         (((UINT32) EqDw1 & 0x3C000) >> 14)  ///< Lane1  4 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW1
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW1_2ND(EqDw2)         (((UINT32) EqDw2 & 0x3FFFF) << 4)   ///< Lane2 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW1
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW1_3RD(EqDw3)         (((UINT32) EqDw3 & 0x003FF) << 22)  ///< Lane3 10 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW1

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW2_1ST(EqDw3)         (((UINT32) EqDw3 & 0x3FC00) >> 10)  ///< Lane3  8 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW2
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW2_2ND(EqDw4)         (((UINT32) EqDw4 & 0x3FFFF) << 8)   ///< Lane4 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW2
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW2_3RD(EqDw5)         (((UINT32) EqDw5 & 0x0003F) << 26)  ///< Lane5  6 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW2

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW3_1ST(EqDw5)         (((UINT32) EqDw5 & 0x3FFC0) >> 6)   ///< Lane5 12 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW3
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW3_2ND(EqDw6)         (((UINT32) EqDw6 & 0x3FFFF) << 12)  ///< Lane6 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW3
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW3_3RD(EqDw7)         (((UINT32) EqDw7 & 0x00003) << 30)  ///< Lane7  2 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW3

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW4_1ST(EqDw7)         (((UINT32) EqDw7 & 0x3FFFC) >> 2)   ///< Lane7 16 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW4
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW4_2ND(EqDw8)         (((UINT32) EqDw8 & 0x0FFFF) << 16)  ///< Lane8 16 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW4

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW5_1ST(EqDw8)         (((UINT32) EqDw8 & 0x30000) >> 16)  ///< Lane8  2 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW5
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW5_2ND(EqDw9)         (((UINT32) EqDw9 & 0x3FFFF) << 2)   ///< Lane9 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW5
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW5_3RD(EqDw10)        (((UINT32) EqDw10 & 0x00FFF) << 20) ///< Lane10 12 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW5

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW6_1ST(EqDw10)        (((UINT32) EqDw10 & 0x3F000) >> 12) ///< Lane10  6 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW6
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW6_2ND(EqDw11)        (((UINT32) EqDw11 & 0x3FFFF) << 6)  ///< Lane11 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW6
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW6_3RD(EqDw12)        (((UINT32) EqDw12 & 0x000FF) << 24) ///< Lane12  8 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW6

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW7_1ST(EqDw12)        (((UINT32) EqDw12 & 0x3FF00) >> 8)  ///< Lane12 10 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW7
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW7_2ND(EqDw13)        (((UINT32) EqDw13 & 0x3FFFF) << 10) ///< Lane13 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW7
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW7_3RD(EqDw14)        (((UINT32) EqDw14 & 0x0000F) << 28) ///< Lane14  4 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW7

#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW8_1ST(EqDw14)        (((UINT32) EqDw14 & 0x3FFF0) >> 4)  ///< Lane14 14 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW8
#define MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW8_2ND(EqDw15)        (((UINT32) EqDw15 & 0x3FFFF) << 14) ///< Lane15 18 bits. Sub-macro @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW8

/**
 *  @brief Macro for filling the 1st double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw0   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw1   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw0 and EqDw1 data to fill in the 1st set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW0(EqDw0, EqDw1)              (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW0_1ST(EqDw0) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW0_2ND(EqDw1))
/**
 *  @brief Macro for filling the 2nd double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw1   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw2   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw3   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw1, EqDw2, and EqDw3 data to fill in the 2nd set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW1(EqDw1, EqDw2, EqDw3)       (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW1_1ST(EqDw1) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW1_2ND(EqDw2) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW1_3RD(EqDw3))
/**
 *  @brief Macro for filling the 3rd double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw3   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw4   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw5   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw3, EqDw4, and EqDw5 data to fill in the 3rd set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW2(EqDw3, EqDw4, EqDw5)       (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW2_1ST(EqDw3) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW2_2ND(EqDw4) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW2_3RD(EqDw5))
/**
 *  @brief Macro for filling the 4th double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw5   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw6   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw7   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw5, EqDw6, and EqDw7 data to fill in the 4th set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW3(EqDw5, EqDw6, EqDw7)       (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW3_1ST(EqDw5) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW3_2ND(EqDw6) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW3_3RD(EqDw7))
/**
 *  @brief Macro for filling the 5th double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw7   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw8   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw7 and EqDw8 data to fill in the 5th set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW4(EqDw7, EqDw8)              (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW4_1ST(EqDw7) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW4_2ND(EqDw8))
/**
 *  @brief Macro for filling the 6th double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw8   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw9   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw10  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw8, EqDw9, and EqDw10 data to fill in the 6th set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW5(EqDw8, EqDw9, EqDw10)      (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW5_1ST(EqDw8) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW5_2ND(EqDw9) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW5_3RD(EqDw10))
/**
 *  @brief Macro for filling the 7th double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw10  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw11  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw12  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw10, EqDw11, and EqDw12 data to fill in the 7th set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW6(EqDw10, EqDw11, EqDw12)    (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW6_1ST(EqDw10) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW6_2ND(EqDw11) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW6_3RD(EqDw12))
/**
 *  @brief Macro for filling the 8th double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw12  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw13  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw14  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw12, EqDw13, and EqDw14 data to fill in the 8th set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW7(EqDw12, EqDw13, EqDw14)    (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW7_1ST(EqDw12) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW7_2ND(EqDw13) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW7_3RD(EqDw14))
/**
 *  @brief Macro for filling the 9th double word in a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw14  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @param[in] EqDw15  Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines EqDw14 and EqDw15 data to fill in the 9th set of 32-bits of a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA_DW8(EqDw14, EqDw15)            (MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW8_1ST(EqDw14) | MAKE_TX_EQ_LIST_COMPACT_DATA_SUB_POS_DW8_2ND(EqDw15))

/**
 *  @brief Macro for creating a compact xGMI TX EQ data list entry.
 *  @param[in] EqDw0-EqDw15 Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that combines all input data to create a compact xGMI TX EQ list entry. @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW0 @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW1 @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW2
 *  @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW3 @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW4 @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW5
 *  @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW6 @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW7 @see MAKE_TX_EQ_LIST_COMPACT_DATA_DW8
 */
#define MAKE_TX_EQ_LIST_COMPACT_DATA(EqDw0, EqDw1, EqDw2, EqDw3, EqDw4, EqDw5, EqDw6, EqDw7, EqDw8, EqDw9, EqDw10, EqDw11, EqDw12, EqDw13, EqDw14, EqDw15) \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW0(EqDw0, EqDw1),           \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW1(EqDw1, EqDw2, EqDw3),    \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW2(EqDw3, EqDw4, EqDw5),    \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW3(EqDw5, EqDw6, EqDw7),    \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW4(EqDw7, EqDw8),           \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW5(EqDw8, EqDw9, EqDw10),   \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW6(EqDw10, EqDw11, EqDw12), \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW7(EqDw12, EqDw13, EqDw14), \
                                                                    MAKE_TX_EQ_LIST_COMPACT_DATA_DW8(EqDw14, EqDw15)


/**
 *  @brief Termination node of XGMI TX EQ setting of frequency table.
 *  @details This is a macro that constructs the bit mask that terminates an XGMI TX EQ settings frequency table.
 */
#define MAKE_TX_EQ_FREQ_END()                           ((UINT32) (((XGMI_TX_EQ_NODE_TYPE_FREQ_END & XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK) << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT)))

/**
 *  @brief Termination node of XGMI TX EQ setting table.
 *  @details This is a macro that constructs the bit mask that terminates an XGMI TX EQ settings table.
 */
#define MAKE_TX_EQ_END()                                ((UINT32) (((XGMI_TX_EQ_NODE_TYPE_END & XGMI_TX_EQ_COMMON_NODE_TYPE_SIZE_MASK) << XGMI_TX_EQ_COMMON_NODE_TYPE_SHIFT)))


/**
 *  @brief xGMI TX EQ union.
 *  @details Union of TX EQ data, attribute, & frequency structures.
 */
typedef union _XGMI_TX_EQ_UNION {
  UINT32                  Raw;                  ///< Raw data.
  XGMI_TX_EQ_COMMON       Common;               ///< Common structure. @see XGMI_TX_EQ_COMMON
  XGMI_TX_EQ_FREQ         Freq;                 ///< Frequency structure. @see XGMI_TX_EQ_FREQ
  XGMI_TX_EQ_ATTR         Attr;                 ///< Attribute structure. @see XGMI_TX_EQ_ATTR
  XGMI_TX_EQ_DATA         Data;                 ///< Data structure. @see XGMI_TX_EQ_DATA
} XGMI_TX_EQ_UNION;

/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_ALL_SYS_LANES()                      MAKE_TX_EQ_ATTR(XGMI_ALL_SOCKETS, XGMI_ALL_DIES, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_EACH_SYS_LANES()                     MAKE_TX_EQ_ATTR(XGMI_ALL_SOCKETS, XGMI_ALL_DIES, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)



/**
 *  @brief Macro for creating xGMI TX EQ attribute for socket 0.
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE_LANE(DieMask, LaneMask, DataMode)    MAKE_TX_EQ_ATTR(XGMI_SOCKET0, DieMask, LaneMask, DataMode)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for socket 0 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE_LANE_PAIR(DieMask, LaneMask)         MAKE_TX_EQ_ATTR(XGMI_SOCKET0, DieMask, LaneMask, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for socket 0 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE_LANE_LIST(DieMask, LaneMask)         MAKE_TX_EQ_ATTR(XGMI_SOCKET0, DieMask, LaneMask, XGMI_TX_EQ_DATA_MODE_LIST)


/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 0 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE0_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE0, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 1 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE1_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE1, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 2 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE2_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE2, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 3 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE3_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE3, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 4 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE4_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE4, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 5 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE5_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE5, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 6 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE6_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE6, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 7 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE7_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE7, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)


/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 0 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE0_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE0, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 1 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE1_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE1, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 2 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE2_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE2, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 3 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE3_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE3, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 4 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE4_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE4, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 5 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE5_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE5, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 6 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE6_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE6, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 7 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE7_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE7, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)


/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 0 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE0_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE0, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 1 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE1_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE1, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 2 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE2_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE2, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 3 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE3_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE3, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 4 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE4_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE4, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 5 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE5_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE5, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 6 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE6_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE6, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 0, die 7 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET0_DIE7_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET0, XGMI_DIE7, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)



/**
 *  @brief Macro for creating xGMI TX EQ attribute for socket 1.
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE_LANE(DieMask, LaneMask, DataMode)    MAKE_TX_EQ_ATTR(XGMI_SOCKET1, DieMask, LaneMask, DataMode)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for socket 1 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE_LANE_PAIR(DieMask, LaneMask)         MAKE_TX_EQ_ATTR(XGMI_SOCKET1, DieMask, LaneMask, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for socket 1 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE_LANE_LIST(DieMask, LaneMask)         MAKE_TX_EQ_ATTR(XGMI_SOCKET1, DieMask, LaneMask, XGMI_TX_EQ_DATA_MODE_LIST)


/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 0 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE0_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE0, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 1 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE1_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE1, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 2 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE2_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE2, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 3 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE3_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE3, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 4 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE4_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE4, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 5 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE5_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE5, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 6 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE6_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE6, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 7 (pair mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE7_ALL_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE7, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_PAIR)


/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 0 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE0_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE0, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 1 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE1_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE1, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 2 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE2_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE2, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 3 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE3_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE3, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 4 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE4_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE4, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 5 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE5_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE5, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 6 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE6_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE6, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 7 (list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE7_EACH_LANES()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE7, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST)


/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 0 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE0_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE0, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 1 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE1_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE1, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 2 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE2_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE2, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 3 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE3_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE3, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 4 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE4_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE4, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 5 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE5_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE5, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 6 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE6_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE6, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)
/**
 *  @brief Macro for creating xGMI TX EQ attribute for all lanes of socket 1, die 7 (compact list mode).
 *  @details @see MAKE_TX_EQ_ATTR
 */
#define MAKE_TX_EQ_SOCKET1_DIE7_EACH_LANES_COMPACT()             MAKE_TX_EQ_ATTR(XGMI_SOCKET1, XGMI_DIE7, XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT)



/**
 *  @brief Macro for creating an xGMI TX EQ attribute/data pair.
 *  @param[in] Attr Specifies the attributes. @see XGMI_TX_EQ_ATTR
 *  @param[in] Data Specifies the data. @see XGMI_TX_EQ_DATA
 *  @details This is a macro that comma separates the passed in attribute & data.
 */
#define MAKE_TX_EQ_PAIR(Attr, Data)                           Attr, Data
/**
 *  @brief Macro for creating a xGMI TX EQ data list entry.
 *  @param[in] Attr   Specifies the attributes associated with this list of data. @see XGMI_TX_EQ_ATTR
 *  @param[in] Data0  Specifies the 1st data to put in this list. @see XGMI_TX_EQ_DATA
 *  @param[in] ARGS   Specifies data to put in this list. @see XGMI_TX_EQ_DATA
 *  @details This is a macro that comma separates the passed in attribute & data.
 */
#define MAKE_TX_EQ_LIST(Attr, Data0, ...)                     Attr, Data0, __VA_ARGS__
/**
 *  @brief Macro for creating a compact xGMI TX EQ data list entry.
 *  @param[in] Attr           Specifies the attributes associated with this list of data. @see XGMI_TX_EQ_ATTR
 *  @param[in] Lane0-Lane15   Specifies EQ pre, main, post data for this entry. @see XGMI_TX_EQ_DATA @see XGMI_TX_EQ_DATA_LIST_COMPACT
 *  @details This is a macro that comma separates the passed in attribute & compact list data. @see MAKE_TX_EQ_LIST_COMPACT_DATA
 */
#define MAKE_TX_EQ_LIST_COMPACT(Attr, Lane0, Lane1, Lane2, Lane3, Lane4, Lane5, Lane6, Lane7, Lane8, Lane9, Lane10, Lane11, Lane12, Lane13, Lane14, Lane15)  \
                                                              Attr, MAKE_TX_EQ_LIST_COMPACT_DATA(Lane0, Lane1, Lane2, Lane3, Lane4, Lane5, Lane6, Lane7, Lane8, Lane9, Lane10, Lane11, Lane12, Lane13, Lane14, Lane15)
/**
 *  @brief Macro for creating xGMI TX EQ frequency table.
 *  @param[in] SpeedMask        Specifies xGMI TX EQ speeds for this table.
 *  @param[in] TxEqPairOrList   Specifies if this table is in pair or list mode. @see XGMI_TX_EQ_DATA_MODE
 *  @param[in] ARGS             Specifies the data to put in this table. @see XGMI_TX_EQ_DATA
 *  @details This is a macro that builds a complete TX EQ frequency table. @see MAKE_TX_EQ_FREQ_TBL @see MAKE_TX_EQ_FREQ_END
 */
#define MAKE_TX_EQ_FREQ_TABLE(SpeedMask, TxEqPairOrList, ...)  MAKE_TX_EQ_FREQ_TBL(SpeedMask), TxEqPairOrList, __VA_ARGS__, MAKE_TX_EQ_FREQ_END()

typedef struct _XGMI_TX_EQ_COMPACT_LANE_PER_DIE {
  union {
    UINT32                  AttrLoc;                ///< Must be XGMI_ALL_LANES, XGMI_TX_EQ_DATA_MODE_LIST_COMPACT.
    XGMI_TX_EQ_ATTR         Attr;                   ///< Attribute structure. @see XGMI_TX_EQ_ATTR
  } unionAttr;                                      ///< xGMI TX EQ Atrributes.
  XGMI_TX_EQ_DATA_LIST_COMPACT    CompactListData;  ///< Compact xGMI TX EQ data list. @see XGMI_TX_EQ_DATA_LIST_COMPACT
} XGMI_TX_EQ_COMPACT_LANE_PER_DIE;

/**
 *  @brief Macro for creating a compact xGMI TX EQ frequency table.
 *  @param[in] SpeedMask  Specifies xGMI TX EQ speeds for this table.
 *  @param[in] SD0-SD7    Specifies compact xGMI TX EQ data list entry for socket die incdice 0-7 . @see MAKE_TX_EQ_LIST_COMPACT_DATA_SUB
 *  @details This is a macro that builds a complete compact TX EQ frequency table with a total of 8 socket
 *  die indices, no direct mapping. @see MAKE_TX_EQ_FREQ_TBL @see MAKE_TX_EQ_FREQ_END
 */
#define MAKE_TX_EQ_FREQ_TABLE_COMPACT(SpeedMask, SD0, SD1, SD2, SD3, SD4, SD5, SD6, SD7)  \
      MAKE_TX_EQ_FREQ_TBL(SpeedMask), SD0, SD1, SD2, SD3, SD4, SD5, SD6, SD7, MAKE_TX_EQ_FREQ_END()

/**
 *  @brief Macro for creating compact xGMI TX EQ data list entry.
 *  @details @see MAKE_TX_EQ_LIST_COMPACT_DATA_SUB
 */
#define MAKE_TX_EQ_LANE_DATA(EqMain, EqPost, EqPre)         MAKE_TX_EQ_LIST_COMPACT_DATA_SUB(EqMain, EqPost, EqPre)

/**
 *  @brief APCB_DF_TYPE_XGMI_TX_EQ.
 *  @details xGMI TX EQ settings. TypeId: APCB_DF_TYPE_XGMI_TX_EQ (0xD0),
 *  InstanceId: APCB_DF_TYPE_XGMI_INSTANCE_SPEED_COMBINED, GroupId: APCB_GROUP_DF
 */
typedef struct {
  UINT32  XgmiTxEqEntry1st;   ///< 1st xGMI TX EQ entry.
  UINT32  XgmiTxEqEntry[];    ///< xGMI TX EQ entries.
} XGMI_TX_EQ_SETTING;

#endif // _APCB_DF_XGMI_TX_EQ_H_


