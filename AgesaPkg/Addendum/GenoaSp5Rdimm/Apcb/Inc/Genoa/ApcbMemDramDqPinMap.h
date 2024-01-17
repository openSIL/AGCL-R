/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define Dimm DQ and CA Pin to ProcPin Mapping on the Platform
 */
#ifndef _APCB_MEM_DRAM_DQ_PIN_MAP_H_
#define _APCB_MEM_DRAM_DQ_PIN_MAP_H_

/**
 * @brief Enumerated type for Data DQ Pins
 */
typedef enum {
  MEM_MX_DATA_00, ///< Data Pin_0 value = 0
  MEM_MX_DATA_01, ///< Data Pin_1 Value = 1
  MEM_MX_DATA_02, ///< Data Pin_2 Value = 2
  MEM_MX_DATA_03, ///< Data Pin_3 Value = 3
  MEM_MX_DATA_04, ///< Data Pin_4 Value = 4
  MEM_MX_DATA_05, ///< Data Pin_5 Value = 5
  MEM_MX_DATA_06, ///< Data Pin_6 Value = 6
  MEM_MX_DATA_07, ///< Data Pin_7 Value = 7
  MEM_MX_DATA_08, ///< Data Pin_8 Value = 8
  MEM_MX_DATA_09, ///< Data Pin_9 Value = 9
  MEM_MX_DATA_10, ///< Data Pin_10 Value = 10
  MEM_MX_DATA_11, ///< Data Pin_11 Value = 11
  MEM_MX_DATA_12, ///< Data Pin_12 Value = 12
  MEM_MX_DATA_13, ///< Data Pin_13 Value = 13
  MEM_MX_DATA_14, ///< Data Pin_14 Value = 14
  MEM_MX_DATA_15, ///< Data Pin_15 Value = 15
  MEM_MX_DATA_16, ///< Data Pin_16 Value = 16
  MEM_MX_DATA_17, ///< Data Pin_17 Value = 17
  MEM_MX_DATA_18, ///< Data Pin_18 Value = 18
  MEM_MX_DATA_19, ///< Data Pin_19 Value = 19
  MEM_MX_DATA_20, ///< Data Pin_20 Value = 20
  MEM_MX_DATA_21, ///< Data Pin_21 Value = 21
  MEM_MX_DATA_22, ///< Data Pin_22 Value = 22
  MEM_MX_DATA_23, ///< Data Pin_23 Value = 23
  MEM_MX_DATA_24, ///< Data Pin_24 Value = 24
  MEM_MX_DATA_25, ///< Data Pin_25 Value = 25
  MEM_MX_DATA_26, ///< Data Pin_26 Value = 26
  MEM_MX_DATA_27, ///< Data Pin_27 Value = 27
  MEM_MX_DATA_28, ///< Data Pin_28 Value = 28
  MEM_MX_DATA_29, ///< Data Pin_29 Value = 29
  MEM_MX_DATA_30, ///< Data Pin_30 Value = 30
  MEM_MX_DATA_31, ///< Data Pin_31 Value = 31
} MEM_32B_PIN_NAME;

/**
 * @brief Maximum number of Dq bits in a Byte Lane
 */
#define MEM_BYTE_LANE_PIN_MAX    (8)

/**
 * @brief Dram Dq Pin Mapping consisting of individual Byte lanes
 */
typedef struct {
  UINT8 DramDqLn0[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_0 array
  UINT8 DramDqLn1[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_1 array
  UINT8 DramDqLn2[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_2 array
  UINT8 DramDqLn3[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_3 array
  UINT8 DramDqLn4[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_4 array
  UINT8 DramDqLn5[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_5 array
  UINT8 DramDqLn6[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_6 array
  UINT8 DramDqLn7[MEM_BYTE_LANE_PIN_MAX]; ///< DQ Byte lane_7 array
} DRAM_DQ_PIN_MAP;

/**
 * @brief Enumerated type for CA Pins
 */
typedef enum {
  MEM_MX_CA_00, ///< CA Pin_0 Value = 0
  MEM_MX_CA_01, ///< CA Pin_1 Value = 1
  MEM_MX_CA_02, ///< CA Pin_2 Value = 2
  MEM_MX_CA_03, ///< CA Pin_3 Value = 3
  MEM_MX_CA_04, ///< CA Pin_4 Value = 4
  MEM_MX_CA_05, ///< CA Pin_5 Value = 5
  MEM_MX_CA_06, ///< CA Pin_6 Value = 6
  MEM_MX_CA_07, ///< CA Pin_7 Value = 7
  MEM_MX_CA_08, ///< CA Pin_8 Value = 8
  MEM_MX_CA_09, ///< CA Pin_9 Value = 9
  MEM_MX_CA_10, ///< CA Pin_10 Value = 10
  MEM_MX_CA_11, ///< CA Pin_11 Value = 11
  MEM_MX_CA_12, ///< CA Pin_12 Value = 12
  MEM_MX_CA_13, ///< CA Pin_13 Value = 13
  MEM_MX_CA_NC = 0xFF, ///< Unmapped default case = 0xFF
} MEM_CA_PIN_NAME;

/**
 * @brief Maximum number of CA bits in a Byte Lane
 */
#define MEM_CA_LANE_PIN_MAX      (7)

/**
 * @brief Dram CA Pin Mapping consisting of individual Byte lanes
 */
typedef struct {
  UINT8 DramCaLn0[MEM_CA_LANE_PIN_MAX]; ///< CA Byte Lane_0 array
  UINT8 DramCaLn1[MEM_CA_LANE_PIN_MAX]; ///< CA Byte Lane_1 array
} DRAM_CA_PIN_MAP;

/**
 * @brief Maximum number of CA bits in a Byte Lane for DDR5
 */
#define MEM_CA_LANE_PIN_MAX_DDDR5 (14)

/**
 * @brief Dram CA Pin Mapping consisting of individual Byte lanes for DDR5
 */
typedef struct {
  UINT8 DramCaLn0[MEM_CA_LANE_PIN_MAX_DDDR5]; ///< CA Byte Lane_0 array
  UINT8 DramCaLn1[MEM_CA_LANE_PIN_MAX_DDDR5]; ///< CA Byte Lane_1 array
} DRAM_CA_PIN_MAP_DDR;

#endif // _APCB_MEM_DRAM_DQ_PIN_MAP_H_



