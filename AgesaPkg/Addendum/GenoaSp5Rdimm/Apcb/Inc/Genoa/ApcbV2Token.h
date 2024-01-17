/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_V2_TOKEN_H_
#define _APCB_V2_TOKEN_H_


#define APCB_ENABLED                                   1
#define APCB_MANUAL                                    1
#define APCB_AUTO_U8                                   0xFF
#define APCB_AUTO_U16                                  0xFFFF
#define APCB_AUTO_U32                                  0xFFFFFFFFul
#define APCB_AUTO_U64                                  0xFFFFFFFFFFFFFFFFull

typedef enum {
  APCB_PSP_TYPE_CONFIG_DEFAULT_PARAMETERS = 1,
  APCB_PSP_TYPE_CONFIG_PARAMETERS,
  APCB_CCX_TYPE_CONFIG_DEFAULT_PARAMETERS = 3,
  APCB_CCX_TYPE_CONFIG_PARAMETERS,
  APCB_DF_TYPE_CONFIG_DEFAULT_PARAMETERS = 5,
  APCB_DF_TYPE_CONFIG_PARAMETERS,
  APCB_MEM_TYPE_CONFIG_DEFAULT_PARAMETERS = 7,
  APCB_MEM_TYPE_CONFIG_PARAMETERS,
  APCB_GNB_TYPE_CONFIG_DEFAULT_PARAMETERS = 9,
  APCB_GNB_TYPE_CONFIG_PARAMETERS,
  APCB_FCH_TYPE_CONFIG_DEFAULT_PARAMETERS = 11,
  APCB_FCH_TYPE_CONFIG_PARAMETERS,
  APCB_TYPE_CBS_COMMON_PARAMETERS = 13,
  APCB_TYPE_CBS_COMMON_DUMMY_PARAMETERS,
  APCB_TYPE_CBS_DEBUG_PARAMETERS = 15,
  APCB_TYPE_CBS_DEBUG_DUMMY_PARAMETERS
} APCB_PARAM_TYPE;



/// CBS Items Start
#define BSU08(u8)     ((UINT8) (u8)  & 0xFF)
#define BSU16(u16)    ((UINT16) (u16) & 0xFF), (((UINT16) (u16) >> 8) & 0xFF)
#define BSU32(u32)    ((UINT32) (u32) & 0xFF), (((UINT32) (u32) >> 8) & 0xFF), (((UINT32) (u32) >> 16) & 0xFF), (((UINT32) (u32) >> 24) & 0xFF)
#define BSU64(u64)    ((UINT64) (u64) & 0xFF), (((UINT64) (u64) >> 8) & 0xFF), (((UINT64) (u64) >> 16) & 0xFF), (((UINT64) (u64) >> 24) & 0xFF), \
                      (((UINT64) (u64) >> 32) & 0xFF), (((UINT64) (u64) >> 40) & 0xFF), (((UINT64) (u64) >> 48) & 0xFF), (((UINT64) (u64) >> 56) & 0xFF)
#define BSBLN(bl)     ((UINT8) (bl)  & 0xFF)


typedef enum {
  APCB_TIME_POINT_NONE = 0,
  APCB_TIME_POINT_ANY = 1,
  APCB_TIME_POINT_BEFORE_DRAM_INIT,
  APCB_TIME_POINT_AFTER_DRAM_SPD_TIMING_INIT,
  APCB_TIME_POINT_AFTER_DRAM_DATASHEET_TIMING_INIT,
  APCB_TIME_POINT_AFTER_DRAM_PHY_INIT,
  APCB_TIME_POINT_AFTER_DRAM_INIT,
  APCB_TIME_POINT_BEFORE_PMU_TRAINING,
  APCB_TIME_POINT_AFTER_PMU_TRAINING,
  APCB_TIME_POINT_AFTER_DRAM_FINALIZATION,
  APCB_TIME_POINT_BEFORE_GMI_TRAINING,
  APCB_TIME_POINT_AFTER_GMI_TRAINING,
  APCB_TIME_POINT_AFTER_DF_FINAL_INIT,
  APCB_TIME_POINT_BEFORE_DF_SPF_INIT,
  APCB_TIME_POINT_BEFORE_DF_CREDIT_RELEASE,
  APCB_TIME_POINT_DF_EARLY,
  APCB_TIME_POINT_END
} APCB_TIME_POINT;

typedef struct {
  UINT32                TimePoint:8;  ///< Specify when the parameter can be retrieved
  UINT32                Token:13;
  UINT32                Size:3;       ///< The actual size of the parameter - 1
  UINT32                Reserved:8;
} APCB_PARAM_ATTRIBUTE;

typedef struct {
  UINT8                 *BaseAddr;   ///< Pointers to the value stream
} APCB_PARAM_BASE_ADDRESS;

typedef struct {
  UINT8                 Valid:1;      ///< Indicator if the map entry is valid
  UINT8                 Size:3;
  UINT8                 Reserved:4;
  UINT8                 TimePoint;
  UINT16                Offset;       ///< Offset to the parameter
                                      ///< within the APCB parameter block
} APCB_PARAM_MAP;

typedef struct {
  UINT32                ApcbTokenConfig;      ///< The APCB Config Token to be linked
  UINT32                ApcbTokenCbs;         ///< The APCB CBS Token to be linked
} APCB_LINKED_TOKENS;


#endif // _APCB_V2_TOKEN_H_


