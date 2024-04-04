/*****************************************************************************
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * ApcbV3Arch.h
 *
 * AGESA PSP Customization Block Architecture Definitions
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:  AGCL-R
 * @e sub-project: (Mem)
 * @e \$Revision: 192403 $ @e \$Date: 2012-12-12 15:46:25 -0600 (Wed, 12 Dec 2012) $
 *
 **/

#ifndef _APCB_V3_ARCH_H_
#define _APCB_V3_ARCH_H_
//
// @APCB_STRUCT
//

//APCB HEADER
#undef APCB_HEADER_VERSION_MAJOR
#undef APCB_HEADER_VERSION_MINOR
#undef APCB_HEADER_VERSION
#define APCB_HEADER_VERSION_MAJOR   3
#define APCB_HEADER_VERSION_MINOR   0
#define APCB_HEADER_VERSION         ((APCB_HEADER_VERSION_MAJOR << 4) | APCB_HEADER_VERSION_MINOR)

//
// APCB Header Definition Version 2
//
typedef struct {
  // APCB V2
  UINT32  Signature;          // ASCII "APCB", 'A' is LSB
  UINT16  SizeOfHeader;       // Size of header
  UINT16  Version;            // Version, BCD. Version 1.2 is 0x12
  UINT32  SizeOfApcb;         // Size of APCB
  UINT32  UniqueApcbInstance; // UniqueApcbInstance to ensure
                              // compatibilitly for given flashed BIOS life cycle
  UINT8   CheckSumByte;       // APCB Checksum Byte
  UINT8   Reserved1[3];       // Reserved, zeros
  UINT32  Reserved2[3];       // Reserved, zeros

} APCB_V2_HEADER;

//
// APCB Header Definition Version 3
//
typedef struct {
  // APCB V2
  UINT32  Signature;          // ASCII "APCB", 'A' is LSB
  UINT16  SizeOfHeader;       // Size of header
  UINT16  Version;            // Version, BCD. Version 1.2 is 0x12
  UINT32  SizeOfApcb;         // Size of APCB
  UINT32  UniqueApcbInstance; // UniqueApcbInstance to ensure
                              // compatibilitly for given flashed BIOS life cycle
  UINT8   CheckSumByte;       // APCB Checksum Byte
  UINT8   Reserved1[3];       // Reserved, zeros
  UINT32  Reserved2[3];       // Reserved, zeros

  // APCB V3

  UINT32  Signature2;         // ASCII "ECB2", 'E' is LSB
  UINT16  RsvdFixed1;         // Reserved, fixed with 0. To be compatible with APCB_GROUP_HEADER_COMP.GroupId
  UINT16  RsvdFixed2;         // Reserved, fixed with 0x10. To be compatible with APCB_GROUP_HEADER_COMP.SizeOfHeader
  UINT16  StructVersion;      // Version, Hex. integer. 0x12 is Version 18.
  UINT16  DataVersion;        // Version, Hex. integer. 0x100 is Version 256.
  UINT32  SizeOfExtHeader;    // Size of extended header (size of APCB_v3_HEADER minus APCB_v2_HEADER). To be compatible with APCB_GROUP_HEADER_COMP.SizeOfGroup

  UINT16  RsvdFixed3;         // Reserved, fixed with 0. To be compatible with APCB_TYPE_HEADER.GroupId
  UINT16  RsvdFixed4;         // Reserved, fixed with 0xFFFF. To be compatible with APCB_TYPE_HEADER.TypeId
  UINT16  RsvdFixed5;         // Reserved, fixed with 64d, 0x40, value to include extended header. To be compatible with APCB_TYPE_HEADER.SizeOfType
                              // Normal algorithsm will not touch here as GroupId does not match, TypeID is already extra reserved.
  UINT16  RsvdFixed6;         // Reserved, fixed with 0x0000. To be compatible with APCB_TYPE_HEADER.InstanceId
  UINT32  Reserved3[2];       // Reserved, zeris

  UINT16  DataOffset;         // Data starting offset, defined per APCB version. Fixed at size of APCB_V3_HEADER (88d, 0x58)
  UINT8   HeaderCheckSum;     // APCB V3 header Checksum Byte, needs to be filled
  UINT8   Reserved4;          // Reserved, zeros
  UINT32  Reserved5[3];       // Reserved, zeros
  UINT8   IntegritySign[32];  // APCB integrity signature, 0x20, 32 bytes
  UINT32  Reserved6[3];       // Reserved, zeros
  UINT32  SignatureEnding;    // ASCII "BCPA", 'B' is LSB, Mark ending of header

} APCB_V3_HEADER;


//
// APCB Header Definition Aligne with Version 3
//

typedef struct {
  // APCB V2
  UINT32  Signature;          // ASCII "APCB", 'A' is LSB
  UINT16  SizeOfHeader;       // Size of header
  UINT16  Version;            // Version, BCD. Version 1.2 is 0x12
  UINT32  SizeOfApcb;         // Size of APCB
  UINT32  UniqueApcbInstance; // UniqueApcbInstance to ensure
                              // compatibilitly for given flashed BIOS life cycle
  UINT8   CheckSumByte;       // APCB Checksum Byte
  UINT8   Reserved1[3];       // Reserved, zeros
  UINT32  Reserved2[3];       // Reserved, zeros

  // APCB V3

  UINT32  Signature2;         // ASCII "ECB2", 'E' is LSB
  UINT16  RsvdFixed1;         // Reserved, fixed with 0. To be compatible with APCB_GROUP_HEADER_COMP.GroupId
  UINT16  RsvdFixed2;         // Reserved, fixed with 0x10. To be compatible with APCB_GROUP_HEADER_COMP.SizeOfHeader
  UINT16  StructVersion;      // Version, Hex. integer. 0x12 is Version 18.
  UINT16  DataVersion;        // Version, Hex. integer. 0x100 is Version 256.
  UINT32  SizeOfExtHeader;    // Size of extended header (size of APCB_v3_HEADER minus APCB_v2_HEADER). To be compatible with APCB_GROUP_HEADER_COMP.SizeOfGroup

  UINT16  RsvdFixed3;         // Reserved, fixed with 0. To be compatible with APCB_TYPE_HEADER.GroupId
  UINT16  RsvdFixed4;         // Reserved, fixed with 0xFFFF. To be compatible with APCB_TYPE_HEADER.TypeId
  UINT16  RsvdFixed5;         // Reserved, fixed with 64d, 0x40, value to include extended header. To be compatible with APCB_TYPE_HEADER.SizeOfType
                              // Normal algorithsm will not touch here as GroupId does not match, TypeID is already extra reserved.
  UINT16  RsvdFixed6;         // Reserved, fixed with 0x0000. To be compatible with APCB_TYPE_HEADER.InstanceId
  UINT32  Reserved3[2];       // Reserved, zeris

  UINT16  DataOffset;         // Data starting offset, defined per APCB version. Fixed at size of APCB_V3_HEADER (88d, 0x58)
  UINT8   HeaderCheckSum;     // APCB V3 header Checksum Byte, needs to be filled
  UINT8   Reserved4;          // Reserved, zeros
  UINT32  Reserved5[3];       // Reserved, zeros
  UINT8   IntegritySign[32];  // APCB integrity signature, 0x20, 32 bytes
  UINT32  Reserved6[3];       // Reserved, zeros
  UINT32  SignatureEnding;    // ASCII "BCPA", 'B' is LSB, Mark ending of header

} APCB_HEADER;


//
// APCB Type Header Deinition of APCB V3
//
// * Structure size remains unchanged.
// * Add definitions in reserved area.
//
typedef struct {
  UINT16  GroupId;          // Group ID
  UINT16  TypeId;           // Type ID
  UINT16  SizeOfType;       // Size of type, in bytes
  UINT16  InstanceId;       // Instance ID
    struct {
    UINT8   ContextType;    // 0 - structure, 1 - APCB Parameter, 2 - APCB Token of V3
    UINT8   ContextFormat;  // 0 - native raw, 1 - sort ascending by UnitSize, 2 - sort descending bu UnitSize (unsupported)
    UINT8   UnitSize;       // Size in byte. Applicable when ContextType = 2, value should be 8.
    UINT8   PriorityMask;   // Priority mask
    UINT8   KeySize;        // Sorting key size. Should be smaller than or equal to UnitSize. Applicable when ContextFormat = 1. (or != 0)
    UINT8   KeyPos;         // Sorting key position of the unit specified of UnitSize.
    UINT16  BoardMask;      // Board specific APCB instance mask
    } sApcbTypeExtV3;
} APCB_V3_TYPE_HEADER;

//
// @CONSTANT
//
#define APCB_TYPE_ATTR_CONTEXT_TYPE_STRUCT      0
#define APCB_TYPE_ATTR_CONTEXT_TYPE_PARAMETER   1
#define APCB_TYPE_ATTR_CONTEXT_TYPE_TOKEN       2

#define APCB_TYPE_ATTR_CONTEXT_FORMAT_NATIVE_RAW  0
#define APCB_TYPE_ATTR_CONTEXT_FORMAT_ASCENDING   1
#define APCB_TYPE_ATTR_CONTEXT_FORMAT_DESCENDING  2

#define APCB_TYPE_ATTR_UNITSIZE_TOKEN_V3          8

#define APCB_TYPE_ATTR_RESERVED                   0

#define APCB_TYPE_ATTR_KEYSIZE_TOKEN_V3           4

#define APCB_TYPE_ATTR_KEYPOS_TOKEN_V3            0



#define APCB_INDEX_HEADER_VERSION_MAJOR   0
#define APCB_INDEX_HEADER_VERSION_MINOR   1
#define APCB_INDEX_HEADER_VERSION         ((APCB_INDEX_HEADER_VERSION_MAJOR << 4) | APCB_INDEX_HEADER_VERSION_MINOR)
//
// APCB Index of Data Type Header Definition
//
typedef struct {
  UINT16  SizeOfHeader;     // Size of header
  UINT16  Version;          // Version, BCD. Version 1.2 is 0x12
  UINT16  Reserved;         // Reserved
  UINT32  SizeOfIndexData;  // Size of index data, absolute address in PSP
                            // NOTE: Will we support it to be relative address to starging address of APCB?
} APCB_INDEX_HEADER;

//
// APCB Index of Data Type  Definition
//
typedef struct {
  UINT16  GroupId;          // Group ID
  UINT16  TypeId;           // Type ID
  UINT32  Address;          // Data address
} APCB_TYPE_INDEX;

//
// APCB Data Type Header Definition
//
typedef struct {
  UINT16  GroupId;          // Group ID
  UINT16  TypeId;           // Type ID
  UINT16  SizeOfType;       // Size of type, in bytes
  UINT16  InstanceId;       // Instance ID
  UINT32  Reserved1;
  UINT32  Reserved2;
} APCB_TYPE_HEADER;

#define ALIGN_SIZE_OF_TYPE    4


#define APCB_GROUP_HEADER_VERSION_MAJOR   0
#define APCB_GROUP_HEADER_VERSION_MINOR   1
#define APCB_GROUP_HEADER_VERSION         ((APCB_GROUP_HEADER_VERSION_MAJOR << 4) | APCB_GROUP_HEADER_VERSION_MINOR)

//
// @CONSTANT
//

#define INVALID_GROUP_ID    0xFFFF
#define UNKNOWN_GROUP_ID    0xFFFE

#define OVERRIDE_INSTANCE 0x8000
#define INSTANCE_ID_MASK 0xFFFF

//
// APCB Data Group Header Definition
//
typedef struct {
  UINT32  Signature;        // ASCII Signature
  UINT16  GroupId;          // Group ID
  UINT16  SizeOfHeader;     // Size of header
  UINT16  Version;          // Version, BCD. Version 1.2 is 0x12
  UINT16  Reserved;         // Reserved
  UINT32  SizeOfGroup;      // Size of group
} APCB_GROUP_HEADER;

//
// APCB Data Signatures for build time tool
//
#if BUILD_APCB_SIG && !BUILD_APCB_DATA
  #define APCB_TYPE_DATA_START_SIGNATURE()    _16BYTE_ALIGN CHAR8 SigStartTypeData[16] = { '$', 'A', 'P', 'C', 'B', '_', 'T', 'Y', 'P', 'E', '_', 'S', 'T', 'A', 'R', 'T' }
  #define APCB_TYPE_DATA_END_SIGNATURE()      _4BYTE_ALIGN CHAR8 SigEndTypeData[16]   = { '$', 'A', 'P', 'C', 'B', '_', 'T', 'Y', 'P', 'E', '_', 'E', 'N', 'D', '_', '$' }
#else
  #define APCB_TYPE_DATA_START_SIGNATURE()
  #define APCB_TYPE_DATA_END_SIGNATURE()
#endif

#define APCB_DUMMY_MAIN_FUNC()  \
  int main (IN int argc, IN char * argv [ ])  \
  { \
    return 0; \
  }


#define APCB_BOARD_INSTANCE_MASK_0 (1 << 0)   ///< @VALUE: 0x1
#define APCB_BOARD_INSTANCE_MASK_1 (1 << 1)   ///< @VALUE: 0x2
#define APCB_BOARD_INSTANCE_MASK_2 (1 << 2)   ///< @VALUE: 0x4
#define APCB_BOARD_INSTANCE_MASK_3 (1 << 3)   ///< @VALUE: 0x8
#define APCB_BOARD_INSTANCE_MASK_4 (1 << 4)   ///< @VALUE: 0x10
#define APCB_BOARD_INSTANCE_MASK_5 (1 << 5)   ///< @VALUE: 0x20
#define APCB_BOARD_INSTANCE_MASK_6 (1 << 6)   ///< @VALUE: 0x40
#define APCB_BOARD_INSTANCE_MASK_7 (1 << 7)   ///< @VALUE: 0x80
#define APCB_BOARD_INSTANCE_MASK_8 (1 << 8)   ///< @VALUE: 0x100
#define APCB_BOARD_INSTANCE_MASK_9 (1 << 9)   ///< @VALUE: 0x200
#define APCB_BOARD_INSTANCE_MASK_10 (1 << 10) ///< @VALUE: 0x400
#define APCB_BOARD_INSTANCE_MASK_11 (1 << 11) ///< @VALUE: 0x800
#define APCB_BOARD_INSTANCE_MASK_12 (1 << 12) ///< @VALUE: 0x1000
#define APCB_BOARD_INSTANCE_MASK_13 (1 << 13) ///< @VALUE: 0x2000
#define APCB_BOARD_INSTANCE_MASK_14 (1 << 14) ///< @VALUE: 0x4000
#define APCB_BOARD_INSTANCE_MASK_15 (1 << 15) ///< @VALUE: 0x8000

typedef enum {
  APCB_BOARD_INSTANCE_UNKNOWN              = 0,
  APCB_BOARD_INSTANCE_0              = APCB_BOARD_INSTANCE_MASK_0,    ///< Board0 Name
  APCB_BOARD_INSTANCE_1              = APCB_BOARD_INSTANCE_MASK_1,    ///< Board1 Name
  APCB_BOARD_INSTANCE_2              = APCB_BOARD_INSTANCE_MASK_2,    ///< Board2 Name
  APCB_BOARD_INSTANCE_3              = APCB_BOARD_INSTANCE_MASK_3,    ///< Board3 Name
  APCB_BOARD_INSTANCE_4              = APCB_BOARD_INSTANCE_MASK_4,    ///< Board4 Name
  APCB_BOARD_INSTANCE_5              = APCB_BOARD_INSTANCE_MASK_5,    ///< Board5 Name
  APCB_BOARD_INSTANCE_6              = APCB_BOARD_INSTANCE_MASK_6,    ///< Board6 Name
  APCB_BOARD_INSTANCE_7              = APCB_BOARD_INSTANCE_MASK_7,    ///< Board7 Name
  APCB_BOARD_INSTANCE_8              = APCB_BOARD_INSTANCE_MASK_8,    ///< Board8 Name
  APCB_BOARD_INSTANCE_9              = APCB_BOARD_INSTANCE_MASK_9,    ///< Board9 Name
  APCB_BOARD_INSTANCE_10             = APCB_BOARD_INSTANCE_MASK_10,   ///< Board10 Name
  APCB_BOARD_INSTANCE_11             = APCB_BOARD_INSTANCE_MASK_11,   ///< Board11 Name
  APCB_BOARD_INSTANCE_12             = APCB_BOARD_INSTANCE_MASK_12,   ///< Board12 Name
  APCB_BOARD_INSTANCE_13             = APCB_BOARD_INSTANCE_MASK_13,   ///< Board13 Name
  APCB_BOARD_INSTANCE_14             = APCB_BOARD_INSTANCE_MASK_14,   ///< Board14 Name
  APCB_BOARD_INSTANCE_15             = APCB_BOARD_INSTANCE_MASK_15,   ///< Board15 Name
  APCB_BOARD_INSTANCE_ALL_KNOWN     = 0xFFFF,        // BIT 0~15 all set
} APCB_BOARD_INSTANCE_TYPE;

#endif // _APCB_V3_ARCH_H_


