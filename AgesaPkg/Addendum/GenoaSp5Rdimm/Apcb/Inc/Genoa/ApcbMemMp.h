/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define general Memory Configuration Data Structures
 */
#ifndef _MP_H_
#define _MP_H_

/**
 * @brief Type of an entry for Dram Termination table
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Speed;           ///< BitMap for the supported speed
  _1BYTE_ALIGN UINT8  Dimms;           ///< BitMap for supported number of dimm
  _1BYTE_ALIGN UINT8  QR_Dimms;        ///< BitMap for supported number of QR dimm
  _1BYTE_ALIGN UINT8  DramTerm;        ///< DramTerm value
  _1BYTE_ALIGN UINT8  QR_DramTerm;     ///< DramTerm value for QR
  _1BYTE_ALIGN UINT8  DynamicDramTerm; ///< Dynamic DramTerm
} DRAM_TERM_ENTRY;

/**
 * @brief Type of an entry for POR speed limit table
 */
typedef struct {
  _2BYTE_ALIGN UINT16   DIMMRankType;      ///< Bitmap of Ranks
  _1BYTE_ALIGN UINT8    Dimms;             ///< Number of dimm
  _2BYTE_ALIGN UINT16    SpeedLimit_1_5V;  ///< POR speed limit for 1.5V
  _2BYTE_ALIGN UINT16    SpeedLimit_1_35V; ///< POR speed limit for 1.35V
  _2BYTE_ALIGN UINT16    SpeedLimit_1_25V; ///< POR speed limit for 1.25V
} POR_SPEED_LIMIT;

/**
 * @brief UDIMM and RDIMM Max Frequency entry Info
 */
typedef union {
  /**
  * @brief UDIMM and RDIMM Max Frequency entry Info _MAXFREQ_ENTRY structure
  */
  struct {
    _1BYTE_ALIGN UINT8 DimmPerCh;           ///< Dimm slot per chanel
    _2BYTE_ALIGN UINT16 Dimms;              ///< Number of Dimms on a channel
    _2BYTE_ALIGN UINT16 SR;                 ///< Number of single-rank Dimm
    _2BYTE_ALIGN UINT16 DR;                 ///< Number of dual-rank Dimm
    _2BYTE_ALIGN UINT16 QR;                 ///< Number of quad-rank Dimm
    _2BYTE_ALIGN UINT16 Speed1_5V;          ///< Speed limit with voltage 1.5V
    _2BYTE_ALIGN UINT16 Speed1_35V;         ///< Speed limit with voltage 1.35V
    _2BYTE_ALIGN UINT16 Speed1_25V;         ///< Speed limit with voltage 1.25V
  } _MAXFREQ_ENTRY;
  /**
  * @brief UDIMM and RDIMM Max Frequency entry Info MAXFREQ_ENTRY structure
  */
  struct {
    _1BYTE_ALIGN UINT8 DimmSlotPerCh;       ///< Dimm Slots per Channel
    _2BYTE_ALIGN UINT16 CDN;                ///< Condition
    _2BYTE_ALIGN UINT16 CDN1;               ///< Condition
    _2BYTE_ALIGN UINT16 CDN2;               ///< Condition
    _2BYTE_ALIGN UINT16 CDN3;               ///< Condition
    _2BYTE_ALIGN UINT16 Speed[3];           ///< Speed limit
  } MAXFREQ_ENTRY;
} PSCFG_MAXFREQ_ENTRY;

/**
 * @brief Data Structure used to pass Max Frequenty Entry Data
 * @details  Different entries based on Dimm Type and Freq data:
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_UDIMM_DDR4_MAX_FREQ (0x44)
 *    This data structure is used to pass memory PSCFG_MAXFREQ_ENTRY data
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_RDIMM_DDR4_MAX_FREQ (0x49)
 *    This data structure is used to pass memory PSCFG_MAXFREQ_ENTRY data
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_3DS_RDIMM_DDR4_MAX_FREQ (0x4B)
 *    This data structure is used to pass memory PSCFG_MAXFREQ_ENTRY data
 */
typedef struct {
  PSCFG_MAXFREQ_ENTRY         PscfgMaxFreqEntry1st; ///< Max Frequency Entry First value in list of Values
  PSCFG_MAXFREQ_ENTRY         PscfgMaxFreqEntry[];  ///< Max Frequency Entry List of Values
} PSCFG_MAXFREQ_ENTRY_STRUCTURE;

/**
 * @brief LRDIMM Max. Frequency entry Info
 */
typedef union {
  struct {
    _1BYTE_ALIGN UINT8 DimmPerCh;      ///< Dimm slot per chanel
    _2BYTE_ALIGN UINT16 Dimms;         ///< Number of Dimms on a channel
    _2BYTE_ALIGN UINT16 LR;            ///< Number of LR-DIMM
    _2BYTE_ALIGN UINT16 Speed1_5V;     ///< Speed limit with voltage 1.5V
    _2BYTE_ALIGN UINT16 Speed1_35V;    ///< Speed limit with voltage 1.35V
    _2BYTE_ALIGN UINT16 Speed1_25V;    ///< Speed limit with voltage 1.25V
  } _LR_MAXFREQ_ENTRY;
  struct {
    _1BYTE_ALIGN UINT8 DimmSlotPerCh;  ///< Number of Dimm Slots per Channel
    _2BYTE_ALIGN UINT16 CDN;           ///< Condition
    _2BYTE_ALIGN UINT16 CDN1;          ///< Condition
    _2BYTE_ALIGN UINT16 CDN2;          ///< Condition
    _2BYTE_ALIGN UINT16 CDN3;          ///< Condition
    _2BYTE_ALIGN UINT16 Speed[3];      ///< Speed Limit
  } LR_MAXFREQ_ENTRY;
} PSCFG_LR_MAXFREQ_ENTRY;

/**
 * @brief Data Structure used to pass Max Frequenty Entry Data
 * @details  Different entries based on Dimm Type and Freq data:
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_LRDIMM_DDR4_MAX_FREQ (0x57)
 *    This data structure is used to pass memory PSCFG_MAXFREQ_ENTRY data
 */
typedef struct {
  PSCFG_LR_MAXFREQ_ENTRY         PscfgLrMaxFreqEntry1st; ///< Max Frequency Entry First value in list of Values
  PSCFG_LR_MAXFREQ_ENTRY         PscfgLrMaxFreqEntry[];  ///< Max Frequency Entry List of Values
} PSCFG_LR_MAXFREQ_ENTRY_STRUCTURE;

/**
 * @brief UDIMM and RDIMM RRT Entry Data Structure for RttNom and RttWr Values
 */
typedef struct {
  _8BYTE_ALIGN UINT64 DimmPerCh;          ///< Dimm slot per chanel
  _8BYTE_ALIGN UINT64 DDRrate;            ///< Bitmap of DDR rate
  _8BYTE_ALIGN UINT64 VDDIO;              ///< Bitmap of VDDIO
  _8BYTE_ALIGN UINT64 Dimm0;              ///< Bitmap of rank type of Dimm0
  _8BYTE_ALIGN UINT64 Dimm1;              ///< Bitmap of rank type of Dimm1
  _8BYTE_ALIGN UINT64 Dimm2;              ///< Bitmap of rank type of Dimm2
  _8BYTE_ALIGN UINT64 Dimm;               ///< Bitmap of rank type of Dimm
  _8BYTE_ALIGN UINT64 Rank;               ///< Bitmap of rank
  _1BYTE_ALIGN UINT8 RttNom;              ///< Dram term
  _1BYTE_ALIGN UINT8 RttWr;               ///< Dynamic dram term
} PSCFG_RTT_ENTRY;

/**
 * @brief LRDIMM RRT Entry Data Structure for RttNom and RttWr Values
 */
typedef struct {
  _8BYTE_ALIGN UINT64 DimmPerCh;         ///< Dimm slot per chanel
  _8BYTE_ALIGN UINT64 DDRrate;           ///< Bitmap of DDR rate
  _8BYTE_ALIGN UINT64 VDDIO;             ///< Bitmap of VDDIO
  _8BYTE_ALIGN UINT64 Dimm0;             ///< Dimm0 population
  _8BYTE_ALIGN UINT64 Dimm1;             ///< Dimm1 population
  _8BYTE_ALIGN UINT64 Dimm2;             ///< Dimm2 population
  _1BYTE_ALIGN UINT8 RttNom;             ///< Dram term
  _1BYTE_ALIGN UINT8 RttWr;              ///< Dynamic dram term
} PSCFG_LR_RTT_ENTRY;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure for ODT pattern of 1 Dimm Per Channel Configuration
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Dimm0;              ///< Bitmap of dimm0 rank type or dimm0 population of LRDIMM
  _4BYTE_ALIGN UINT32 ODTPatCS0;          ///< ODT Pattern for CS0
  _4BYTE_ALIGN UINT32 ODTPatCS1;          ///< ODT Pattern for CS1
  _4BYTE_ALIGN UINT32 ODTPatCS2;          ///< ODT Pattern for CS2
  _4BYTE_ALIGN UINT32 ODTPatCS3;          ///< ODT Pattern for CS3
} PSCFG_1D_ODTPAT_ENTRY;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure for ODT pattern of 2 Dimms Per Channel Configuration
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Dimm0:4;            ///< Bitmap of dimm0 rank type or dimm0 population of LRDIMM
  _4BYTE_ALIGN UINT32 Dimm1:28;           ///< Bitmap of dimm1 rank type or dimm1 population of LRDIMM
  _4BYTE_ALIGN UINT32 ODTPatCS0;          ///< ODT Pattern for CS0
  _4BYTE_ALIGN UINT32 ODTPatCS1;          ///< ODT Pattern for CS1
  _4BYTE_ALIGN UINT32 ODTPatCS2;          ///< ODT Pattern for CS2
  _4BYTE_ALIGN UINT32 ODTPatCS3;          ///< ODT Pattern for CS3
} PSCFG_2D_ODTPAT_ENTRY;

/**
 * @brief Data Structure to Store ODT Pattern Entry Data
 * @details Various Entries are possible based on Dimm Type:
 *   GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_UDIMM_DDR4_ODT_PAT (0x41)
 *    This data structure is used to pass memory PS_UDIMM_DDR4_ODT_PAT data
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_RDIMM_DDR4_ODT_PAT (0x46)
 *    This data structure is used to pass memory PS_UDIMM_DDR4_ODT_PAT data
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_LRDIMM_DDR4_ODT_PAT (0x54)
 *    This data structure is used to pass memory PS_UDIMM_DDR4_ODT_PAT data
 */
typedef struct {
  PSCFG_2D_ODTPAT_ENTRY       PscfgTwodOdtPatEntry1st; ///< 2D ODT Pattern First Entry
  PSCFG_2D_ODTPAT_ENTRY       PscfgTwodOdtPatEntry[];  ///< 2D ODT Pattern List of Entries
} PSCFG_TWO_D_ODTPAT;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure for ODT pattern of 3 Dimms Per Channel Configuration
 */
typedef struct {
  _4BYTE_ALIGN UINT32 Dimm0:4;            ///< Bitmap of dimm0 rank type or dimm0 population of LRDIMM
  _4BYTE_ALIGN UINT32 Dimm1:4;            ///< Bitmap of dimm1 rank type or dimm1 population of LRDIMM
  _4BYTE_ALIGN UINT32 Dimm2:24;           ///< Bitmap of dimm2 rank type or dimm2 population of LRDIMM
  _4BYTE_ALIGN UINT32 ODTPatCS0;          ///< ODT Pattern for CS0
  _4BYTE_ALIGN UINT32 ODTPatCS1;          ///< ODT Pattern for CS1
  _4BYTE_ALIGN UINT32 ODTPatCS2;          ///< ODT Pattern for CS2
  _4BYTE_ALIGN UINT32 ODTPatCS3;          ///< ODT Pattern for CS3
} PSCFG_3D_ODTPAT_ENTRY;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure to pass SLowMode, AddrTmgCtl and ODC settings
 */
typedef struct {
  _8BYTE_ALIGN UINT64 DimmPerCh;         ///< Dimm slot per channel
  _8BYTE_ALIGN UINT64 DDRrate;           ///< Bitmap of DDR rate
  _8BYTE_ALIGN UINT64 VDDIO;             ///< Bitmap of VDDIO
  _8BYTE_ALIGN UINT64 Dimm0;             ///< Bitmap of dimm0 rank type or dimm0 population of LRDIMM
  _8BYTE_ALIGN UINT64 Dimm1;             ///< Bitmap of dimm1 rank type or dimm1 population of LRDIMM
  _8BYTE_ALIGN UINT64 Dimm2;             ///< Bitmap of dimm2 rank type or dimm2 population of LRDIMM
  _8BYTE_ALIGN UINT64 SlowMode;          ///< SlowMode
  _4BYTE_ALIGN UINT32 AddTmgCtl;         ///< AddTmgCtl
  _4BYTE_ALIGN UINT32 ODC;               ///< ODC
  _1BYTE_ALIGN UINT8 POdtOff;            ///< POdtOff
} PSCFG_SAO_ENTRY;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure for 2D Training Config Entry
 */
typedef struct {
  _8BYTE_ALIGN UINT64 DimmPerCh;         ///< Dimm per channel
  _8BYTE_ALIGN UINT64 DDRrate;           ///< Bitmap of DDR rate
  _8BYTE_ALIGN UINT64 VDDIO;             ///< Bitmap of VDDIO
  _8BYTE_ALIGN UINT64 Dimm0;             ///< Bitmap of dimm0 rank type or dimm0 population of LRDIMM
  _8BYTE_ALIGN UINT64 Dimm1;             ///< Bitmap of dimm1 rank type or dimm1 population of LRDIMM
  _8BYTE_ALIGN UINT64 Dimm2;             ///< Bitmap of dimm2 rank type or dimm2 population of LRDIMM
  _8BYTE_ALIGN UINT64 Enable2D;          ///< SlowMode
} PSCFG_S2D_ENTRY;

/**
 * @brief UDIMM and RDIMM Data Structure to pass MR0[WR] Value
 */
typedef struct {
  _1BYTE_ALIGN UINT8 Timing;             ///< Fn2_22C_dct[1:0][Twr]
  _1BYTE_ALIGN UINT8 Value;              ///< MR0[WR] : bit0 - bit2 available
} PSCFG_MR0WR_ENTRY;

/**
 * @brief UDIMM and RDIMM Data Structure to pass MR0[Cl] Value
 */
typedef struct {
  _1BYTE_ALIGN UINT8 Timing;              ///< Fn2_200_dct[1:0][Tcl]
  _1BYTE_ALIGN UINT8 Value;               ///< MR0[CL] : bit0 - bit2 CL[3:1]
  _1BYTE_ALIGN UINT8 Value1;              ///< MR0[CL] : bit3 CL[0]
} PSCFG_MR0CL_ENTRY;

/**
 * @brief UDIMM and RDIMM Data Structure to pass MR2[IBT] Value
 */
typedef struct {
  _8BYTE_ALIGN UINT64 DimmPerCh;          ///< Dimm per channel
  _8BYTE_ALIGN UINT64 DDRrate;            ///< Bitmap of DDR rate
  _8BYTE_ALIGN UINT64 VDDIO;              ///< Bitmap of VDDIO
  _8BYTE_ALIGN UINT64 Dimm0;              ///< Bitmap of dimm0 rank type
  _8BYTE_ALIGN UINT64 Dimm1;              ///< Bitmap of dimm1 rank type
  _8BYTE_ALIGN UINT64 Dimm2;              ///< Bitmap of dimm2 rank type
  _8BYTE_ALIGN UINT64 Dimm;               ///< Bitmap of rank type of Dimm
  _8BYTE_ALIGN UINT64 NumOfReg;           ///< Number of registers
  _8BYTE_ALIGN UINT64 IBT;                ///< MR2[IBT] value
} PSCFG_MR2IBT_ENTRY;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure to pass Operating Speed
 */
typedef struct {
  _4BYTE_ALIGN UINT32 DDRrate;              ///< Bitmap of DDR rate
  _1BYTE_ALIGN UINT8 OPSPD;                 ///< RC10[OperatingSpeed]
} PSCFG_OPSPD_ENTRY;

/**
 * @brief Data Structure to pass LRDIMM IBT Value
 */
typedef struct {
  _8BYTE_ALIGN UINT64 DimmPerCh;          ///< Dimm per channel
  _8BYTE_ALIGN UINT64 DDRrate;           ///< Bitmap of DDR rate
  _8BYTE_ALIGN UINT64 VDDIO;              ///< Bitmap of VDDIO
  _8BYTE_ALIGN UINT64 Dimm0;              ///< Dimm0 population
  _8BYTE_ALIGN UINT64 Dimm1;              ///< Dimm1 population
  _8BYTE_ALIGN UINT64 Dimm2;              ///< Dimm2 population
  _8BYTE_ALIGN UINT64 F0RC8;              ///< F0RC8
  _8BYTE_ALIGN UINT64 F1RC0;              ///< F1RC0
  _8BYTE_ALIGN UINT64 F1RC1;              ///< F1RC1
  _8BYTE_ALIGN UINT64 F1RC2;              ///< F1RC2
} PSCFG_L_IBT_ENTRY;

/**
 * @brief LRDIMM Data Structure to pass Number of Physical Ranks Value FORC13[NumPhysicalRanks]
 */
typedef struct {
  _1BYTE_ALIGN UINT8 NumRanks : 3;        ///< NumRanks
  _1BYTE_ALIGN UINT8 NumPhyRanks : 5;     ///< NumPhyRanks
} PSCFG_L_NPR_ENTRY;

/**
 * @brief LRDIMM Data Structure to pass Number of Logical Ranks Value FORC13[NumLogicalRanks]
 */
typedef struct {
  _2BYTE_ALIGN UINT16 NumPhyRanks;        ///< NumPhyRanks
  _2BYTE_ALIGN UINT16 DramCap;            ///< DramCap
  _2BYTE_ALIGN UINT16 NumDimmSlot;        ///< NumDimmSlot
  _1BYTE_ALIGN UINT8 NumLogRanks;         ///< NumLogRanks
} PSCFG_L_NLR_ENTRY;

/**
 * @brief UDIMM, RDIMM and LRDIMM Data Structure for Pass1 Seed Entry Value
 */
typedef struct {
  _1BYTE_ALIGN UINT8 DimmPerCh;           ///< Dimm per channel
  _1BYTE_ALIGN UINT8 Channel;             ///< Channel number
  _2BYTE_ALIGN UINT16 SeedVal;            ///< Seed value
} PSCFG_SEED_ENTRY;

/**
 * @brief Platform specific configuration types
 */
typedef enum {
  PSCFG_MAXFREQ,               ///< PSCFG_MAXFREQ
  PSCFG_LR_MAXFREQ,            ///< PSCFG_LR_MAXFREQ
  PSCFG_RTT,                   ///< PSCFG_RTT
  PSCFG_LR_RTT,                ///< PSCFG_LR_RTT
  PSCFG_ODT_PAT_1D,            ///< PSCFG_ODT_PAT_1D
  PSCFG_ODT_PAT_2D,            ///< PSCFG_ODT_PAT_2D
  PSCFG_ODT_PAT_3D,            ///< PSCFG_ODT_PAT_3D
  PSCFG_LR_ODT_PAT_1D,         ///< PSCFG_LR_ODT_PAT_1D
  PSCFG_LR_ODT_PAT_2D,         ///< PSCFG_LR_ODT_PAT_2D
  PSCFG_LR_ODT_PAT_3D,         ///< PSCFG_LR_ODT_PAT_3D
  PSCFG_SAO,                   ///< PSCFG_SAO
  PSCFG_LR_SAO,                ///< PSCFG_LR_SAO
  PSCFG_MR0WR,                 ///< PSCFG_MR0WR
  PSCFG_MR0CL,                 ///< PSCFG_MR0CL
  PSCFG_RC2IBT,                ///< PSCFG_RC2IBT
  PSCFG_RC10OPSPD,             ///< PSCFG_RC10OPSPD
  PSCFG_LR_IBT,                ///< PSCFG_LR_IBT
  PSCFG_LR_NPR,                ///< PSCFG_LR_NPR
  PSCFG_LR_NLR,                ///< PSCFG_LR_NLR
  PSCFG_S2D,                   ///< PSCFG_S2D
  PSCFG_WL_PASS1_SEED,         ///< PSCFG_WL_PASS1_SEED
  PSCFG_HWRXEN_PASS1_SEED,     ///< PSCFG_HWRXEN_SEED
  PSCFG_CADBUS,                ///< PSCFG_CADBUS
  PSCFG_CADBUS_DRAMDN,         ///< PSCFG_CADBUS_DRAMDN
  PSCFG_DATABUS,               ///< PSCFG_DATABUS
  PSCFG_DATABUS_DRAMDN,        ///< PSCFG_DATABUS_DRAMDN
  PSCFG_GEN_START,             /**< PSCFG_GEN_START -
                                * The type of general table entries could be added between
                                * PSCFG_GEN_START and PSCFG_GEN_END so that the PSCGen routine
                                * is able to look for the entries per the PSCType.
                                */
  PSCFG_CLKDIS,                ///< PSCFG_CLKDIS
  PSCFG_CKETRI,                ///< PSCFG_CKETRI
  PSCFG_ODTTRI,                ///< PSCFG_ODTTRI
  PSCFG_CSTRI,                 ///< PSCFG_CSTRI
  PSCFG_GEN_END                ///< PSCFG_GEN_END
} PSCFG_TYPE;

/**
 * @brief Structure to define Dimm Types
 */
typedef enum {
  UDIMM_TYPE = 0x01,           ///< UDIMM_TYPE
  RDIMM_TYPE = 0x02,           ///< RDIMM_TYPE
  SODIMM_TYPE = 0x04,          ///< SODIMM_TYPE
  LRDIMM_TYPE = 0x08,          ///< LRDIMM_TYPE
  SODWN_SODIMM_TYPE = 0x10,    ///< SODWN_SODIMM_TYPE
  DT_DONT_CARE = 0xFF          ///< DT_DONT_CARE
} DIMM_TYPE;

/**
 * @brief Structure to define Number of DRAM devices or DIMM slots
 */
typedef enum {
  _1DIMM = 0x01,               ///< _1DIMM
  _2DIMM = 0x02,               ///< _2DIMM
  _3DIMM = 0x04,               ///< _3DIMM
  _4DIMM = 0x08,               ///< _4DIMM
  _DIMM_NONE = 0xF0,           ///< _DIMM_NONE (no DIMM slot)
  NOD_DONT_CARE = 0xFF         ///< NOD_DONT_CARE
} NOD_SUPPORTED;

/**
 * @brief Structure to pass Motherboard layer type
 */
typedef enum {
  _4LAYERS = 0x01,             ///< 4 Layers
  _6LAYERS = 0x02,             ///< 6 Layers
  MBL_DONT_CARE = 0xFF         ///< MBL_DONT_CARE
} MB_LAYER_TYPE;

/**
 * @brief Structure to pass Motherboard power type
 */
typedef enum {
  LPM = 0x01,                  ///< Low power motherboard
  HPM = 0x02,                  ///< High power motherboard
  MBP_DONT_CARE = 0xFF         ///< MBP_DONT_CARE
} MB_POWER_TYPE;

/**
 * @brief Structures use to pass system Logical CPU-ID
 */
typedef struct {
  IN OUT   UINT16 Family;      ///< Indicates logical ID Family
  IN OUT   UINT16 Revision;    ///< Indicates logical ID Revision
} APCB_SOC_LOGICAL_ID;

/**
 * @brief Table header related definitions
 */
typedef struct {
  PSCFG_TYPE PSCType;                ///< PSC Type
  DIMM_TYPE DimmType;                ///< Dimm Type
  NOD_SUPPORTED NumOfDimm;           ///< Numbef of dimm
  APCB_SOC_LOGICAL_ID LogicalCpuid;  ///< Logical Cpuid
  _1BYTE_ALIGN UINT8 PackageType;    ///< Package Type
  TECHNOLOGY_TYPE TechType;          ///< Technology type
  MB_LAYER_TYPE MotherboardLayer;    ///< Motherboard layer type
  MB_POWER_TYPE MotherboardPower;    ///< Motherboard power type
} PSC_TBL_HEADER;

/**
 * @brief PLatform Specific Table Entry related details
 */
typedef struct {
  PSC_TBL_HEADER Header;        ///< PSC_TBL_HEADER
  _1BYTE_ALIGN UINT8 TableSize; ///< Table size
  VOID *TBLPtr;                 ///< Pointer of the table
} PSC_TBL_ENTRY;

/**
 * @brief PT_DONT_CARE default value
 */
#define PT_DONT_CARE 0xFF
/**
 * @brief NP Value
 */
#define NP 1
/**
 * @brief V1 = 5 encoded value
 */
#define V1_5  1
/**
 * @brief V1 = 35 encoded value
 */
#define V1_35  2
/**
 * @brief V1 = 25 encoded value
 */
#define V1_25  4
/**
 * @brief V1 = 2 encoded value
 */
#define V1_2   1
/**
 * @brief TBD1 encoded value
 */
#define V_TBD1 2
/**
 * @brief TBD2 encoded value
 */
#define V_TBD2 4
/**
 * @brief Voltage All encoded value
 */
#define VOLT_ALL (7)
/**
 * @brief Single Rank Dimm encoded value
 */
#define DIMM_SR 2
/**
 * @brief Dual Rank Dimm encoded value
 */
#define DIMM_DR 4
/**
 * @brief Quad Rank Dimm encoded value
 */
#define DIMM_QR 8
/**
 * @brief  LrDimm encoded value according to Dimm Present Bits rather than Rank Type Bits
 */
#define DIMM_LR 2
/**
 * @brief Rank0 OneHot encoded value
 */
#define R0 1
/**
 * @brief Rank1 OneHot encoded value
 */
#define R1 2
/**
 * @brief Rank2 OneHot encoded value
 */
#define R2 4
/**
 * @brief Rank3 OneHot encoded value
 */
#define R3 8
/**
 * @brief Channel_0 OneHot encoded value
 */
#define CH_A 0x01
/**
 * @brief Channel_1 OneHot encoded value
 */
#define CH_B 0x02
/**
 * @brief Channel_2 OneHot encoded value
 */
#define CH_C 0x04
/**
 * @brief Channel_3 OneHot encoded value
 */
#define CH_D 0x08
/**
 * @brief ALL Channel OneHot encoded value
 */
#define CH_ALL 0x0F
/**
 * @brief Device width 16 encoded value
 */
#define DEVWIDTH_16 1
/**
 * @brief Device width 32 encoded value
 */
#define DEVWIDTH_32 2

/**
 * @brief Data Structure to pass CAD Bus Configuration
 */
typedef struct {
  _4BYTE_ALIGN UINT32 DimmPerCh;       ///< Bitmap of Dimm slot per chanel
  _4BYTE_ALIGN UINT32 DDRrate;         ///< Bitmap of DDR rate
  _4BYTE_ALIGN UINT32 VDDIO;           ///< Bitmap of VDDIO
  _4BYTE_ALIGN UINT32 Dimm0;           ///< Bitmap of rank type of Dimm0
  _4BYTE_ALIGN UINT32 Dimm1;           ///< Bitmap of rank type of Dimm1
  _4BYTE_ALIGN UINT16 GearDownMode;    ///< GearDownMode
  _4BYTE_ALIGN UINT16 SlowMode;        ///< SlowMode
  _4BYTE_ALIGN UINT32 AddrCmdCtl;      ///< AddrCmdCtl
  _1BYTE_ALIGN UINT8  CkeStrength;     ///< CKE drive strength
  _1BYTE_ALIGN UINT8  CsOdtStrength;   ///< CS ODT drive strength
  _1BYTE_ALIGN UINT8  AddrCmdStrength; ///< Addr Cmd drive strength
  _1BYTE_ALIGN UINT8  ClkStrength;     ///< CLK drive strength
} PSCFG_CADBUS_ENTRY;

/**
 * @brief Data Structure to Store CAD Bus Entry Data
 * @details Various Entries based on Dimm Type are:
 *    ROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_UDIMM_DDR4_CAD_BUS (0x42)
 *    This data structure is used to pass memory PSCFG_CADBUS_ENTRY data
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_RDIMM_DDR4_CAD_BUS (0x47)
 *    This data structure is used to pass memory PSCFG_CADBUS_ENTRY data
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_LRDIMM_DDR4_CAD_BUS (0x55)
 *    This data structure is used to pass memory PSCFG_CADBUS_ENTRY data
 */
typedef struct {
  PSCFG_CADBUS_ENTRY          PscfgCadbusEntry1st; ///< Cad Bus First Entry
  PSCFG_CADBUS_ENTRY          PscfgCadbusEntry[];  ///< List of CAD Bus Entries
} PSCFG_CADBUS_ENTRY_STRUCTURE;

/**
 * @brief CAD Bus configuration for Soldered Down DRAM
 */ 
typedef struct {
  _4BYTE_ALIGN UINT32 DimmPerCh;       ///< Bitmap of Dimm slot per chanel
  _4BYTE_ALIGN UINT32 DDRrate;         ///< Bitmap of DDR rate
  _4BYTE_ALIGN UINT32 VDDIO;           ///< Bitmap of VDDIO
  _4BYTE_ALIGN UINT32 Dimm0;           ///< Bitmap of rank type of Dimm0
  _4BYTE_ALIGN UINT32 DevWidth;        ///< Device Width

  _4BYTE_ALIGN UINT32 SlowMode;        ///< SlowMode
  _4BYTE_ALIGN UINT32 AddrCmdCtl;      ///< AddrCmdCtl

  _1BYTE_ALIGN UINT8  CkeStrength;     ///< CKE drive strength
  _1BYTE_ALIGN UINT8  CsOdtStrength;   ///< CS ODT drive strength
  _1BYTE_ALIGN UINT8  AddrCmdStrength; ///< Addr Cmd drive strength
  _1BYTE_ALIGN UINT8  ClkStrength;     ///< CLK drive strength
} PSCFG_DRAMDN_CADBUS_ENTRY;

/**
 * @brief On die termination encoding Types
 */
typedef enum {
  ODT_OFF = 0,    ///<  0 On die termination disabled
  ODT_60 = 1,     ///<  1 60 ohms
  ODT_120 = 2,    ///<  2 120 ohms
  ODT_40 = 3,     ///<  3 40 ohms
  ODT_20 = 4,     ///<  4 20 ohms
  ODT_30 = 5,     ///<  5 30 ohms
} ODT_ENC;

/**
 * @brief DDR4 Rtt_Nom termination encoding Types
 */
typedef enum {
  RTTNOM_OFF = 0, ///<  0 Rtt_Nom Disabled
  RTTNOM_60 = 1,  ///<  1 60 ohms
  RTTNOM_120 = 2, ///<  2 120 ohms
  RTTNOM_40 = 3,  ///<  3 40 ohms
  RTTNOM_240 = 4, ///<  4 240 ohms
  RTTNOM_48 = 5,  ///<  5 48 ohms
  RTTNOM_80 = 6,  ///<  5 80 ohms
  RTTNOM_34 = 7,  ///<  5 34 ohms
} D4_RTT_NOM_ENC;

/**
 * @brief  DDR4 Rtt_Wr termination encoding Types
 */
typedef enum {
  RTTWR_OFF = 0, ///<  0 Rtt_Nom Disabled
  RTTWR_120 = 1, ///< 1 120 ohms
  RTTWR_240 = 2, ///<  2 24 ohms
  RTTWR_HIZ = 3, ///<  3 Hi-Z
  RTTWR_80 = 4,  ///<  4 80 ohms
} D4_RTT_WR_ENC;

/**
 * @brief DDR4 Rtt_Park termination encoding Types
 */
typedef enum {
  RTTPRK_OFF = 0, ///<  0 Rtt_Park Disabled
  RTTPRK_60 = 1,  ///<  1 60 ohms
  RTTPRK_120 = 2, ///<  2 120 ohms
  RTTPRK_40 = 3,  ///<  3 40 ohms
  RTTPRK_240 = 4, ///<  4 240 ohms
  RTTPRK_48 = 5,  ///<  5 48 ohms
  RTTPRK_80 = 6,  ///<  5 80 ohms
  RTTPRK_34 = 7,  ///<  5 34 ohms
} D4_RTT_PRK_ENC;

/**
 * @brief Structure to pass Data Bus Configuration
 */
typedef struct {
  _4BYTE_ALIGN UINT32 DimmPerCh;   ///< Bitmap of Dimm slot per chanel
  _4BYTE_ALIGN UINT32 DDRrate;     ///< Bitmap of DDR rate
  _4BYTE_ALIGN UINT32 VDDIO;       ///< Bitmap of VDDIO
  _4BYTE_ALIGN UINT32 Dimm0;       ///< Bitmap of rank type of Dimm0
  _4BYTE_ALIGN UINT32 DevWidth;    ///< Device Width

  _4BYTE_ALIGN UINT32 RttNom;      ///< Rtt_Nom
  _4BYTE_ALIGN UINT32 RttWr;       ///< Rtt_Wr
  _4BYTE_ALIGN UINT32 DqStrength;  ///< Data drive strength
  _4BYTE_ALIGN UINT32 DqsStrength; ///< DQS drive strength
  _4BYTE_ALIGN UINT32 OdtStrength; ///< ODT drive strength
} PSCFG_DRAMDN_DATABUS_ENTRY;

/**
 * @brief Structure to pass DDR4 Data Bus Configuration
 */
typedef struct {
  _4BYTE_ALIGN UINT8 DimmPerCh;    ///< Bitmap of Dimm slot per chanel
  _4BYTE_ALIGN UINT32 DDRrate;     ///< Bitmap of DDR rate
  _4BYTE_ALIGN UINT32 VDDIO;       ///< Bitmap of VDDIO
  _4BYTE_ALIGN UINT32 Dimm0;       ///< Bitmap of rank type of Dimm0
  _4BYTE_ALIGN UINT32 Dimm1;       ///< Bitmap of rank type of Dimm1

  _4BYTE_ALIGN UINT32 RttNom;      ///< Rtt_Nom
  _4BYTE_ALIGN UINT32 RttWr;       ///< Rtt_Wr
  _4BYTE_ALIGN UINT32 RttPark;     ///< Rtt_Park
  _4BYTE_ALIGN UINT32 DqStrength;  ///< Data drive strength
  _4BYTE_ALIGN UINT32 DqsStrength; ///< DQS drive strength
  _4BYTE_ALIGN UINT32 OdtStrength; ///< ODT drive strength
  _4BYTE_ALIGN UINT32 PMUPhyVref;  ///< Message Block Seed for Host Vref
  _4BYTE_ALIGN UINT32 VrefDq;      ///< Message Block Seed for DRAM MR6 Vref
} PSCFG_DATABUS_ENTRY_D4;

/**
 * @brief Data Structure to Store DDR4 Data Bus Entry Info
 * @details Various Entries based on Dimm Type are:
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_UDIMM_DDR4_DATA_BUS (0x43)
 *    APCB_GROUP_MEMORY  APCB_MEM_TYPE_PS_UDIMM_DDR4_DATA_BUS
 *    DDR4 Data Bus configuration
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_RDIMM_DDR4_DATA_BUS (0x48)
 *    APCB_GROUP_MEMORY  APCB_MEM_TYPE_PS_RDIMM_DDR4_DATA_BUS
 *    DDR4 Data Bus configuration
 *
 *    GROUPID: APCB_GROUP_MEMORY (0x1704)
 *    TYPEID: APCB_MEM_TYPE_PS_LRDIMM_DDR4_DATA_BUS (0x56)
 *    APCB_GROUP_MEMORY  APCB_MEM_TYPE_PS_LRDIMM_DDR4_DATA_BUS
 *    DDR4 Data Bus configuration
 */
typedef struct {
  PSCFG_DATABUS_ENTRY_D4          PscfgDatabusEntryD41st; ///< DDR4 Data Bus Entry First value
  PSCFG_DATABUS_ENTRY_D4          PscfgDatabusEntryD4[];  ///< DDR4 Data Bus Entry List of Values
} PSCFG_DATABUS_ENTRY_D4_STRUCTURE;

#endif // _MP_H_
