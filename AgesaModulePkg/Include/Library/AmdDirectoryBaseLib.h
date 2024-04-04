/*****************************************************************************
 *
 * Copyright (C) 2020-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *****************************************************************************/

/**

 @file  AmdDirectoryBaseLib.h
 @brief Interface to the PSP library header.

**/

#include <AmdPspDirectory.h>

#pragma once

#pragma pack(push, 1)

#define FORCE_SPIADDR_BIT24(SpiAddress) (SpiAddress | 0xFF000000)

#define FCH_ROM_INVALID_START_ADDRESS_2 0xFFFFFFFFul
#define FCH_ROM_START_ADDRESS_2 0xFF000000ul
#define FCH_ROM_END_ADDRESS_2 0xFFFFFFFFul

#define MAX_DIR_ENTRY_COUNT 64

#define IS_SPI_ROM2_OFFSET(a) (((a) < 0x1000000) ? TRUE : FALSE)
#define IS_IN_SPI_ROM2_WINDOW(a) ((((a) & ~(0xFFFFFF)) == 0xFF000000) ? TRUE : FALSE)

#define FIRMWARE_TABLE_SIGNATURE 0x55AA55AAul

#define FCH_ROM_SIZE_16M 0x1000000
#define FCH_ROM_SIZE_32M (2 * FCH_ROM_SIZE_16M)
#define FCH_ROM_SIZE_64M (4 * FCH_ROM_SIZE_16M)

#define BYTE0 0x00
#define BYTE1 0x01
#define BYTE2 0x02
#define BYTE3 0x03
#define BYTE4 0x04
#define BYTE5 0x05
#define BYTE6 0x06
#define BYTE7 0x07
#define BYTE_MASK 0xFF
#define BYTE_OFFSET 0x08

#define IS_ADDRESS_MODE_1(a) (RShiftU64((a), 62) == 1 ? TRUE : FALSE) // relative to BIOS image base 0
#define IS_ADDRESS_MODE_2(a) (RShiftU64((a), 62) == 2 ? TRUE : FALSE) // relative to current directory header
#define IS_ADDRESS_MODE_3(a) (RShiftU64((a), 62) == 3 ? TRUE : FALSE) // relative to active image slot address (as of now, active image slot address is equal to PSP L2 base address)
#define IS_SPI_OFFSET(a) (((a)&0xFF000000) != 0xFF000000 ? TRUE : FALSE)

#pragma pack(pop)

/**
 * @brief translate entry offset to correct location based on address mode
 *
 * @param[in] EntryLocation     The location of the entry before translation
 * @param[in] DirectoryHdrAddr  Directory header address
 * @param[in] ImageSlotAddr     Image slot address if applicable, if no image slot, leave it as 0
 *
 * @return UINT64           return translated entry location
 */
UINT64
TranslateEntryLocation(
    IN UINT64 EntryLocation,
    IN UINT64 DirectoryHdrAddr);

/**
 *
 *  Get BIOS Directory Entry 's properties by 2 Attributes: EntryType, EntryInstance.
 *
 *  @param[in]     EntryType        BIOS Directory Entry type
 *  @param[in]     EntryInstance    Return the entry which both EntryType & EntryInstance matched
 *  @param[in,out] TypeAttrib       TypeAttrib of entry
 *  @param[in,out] EntryAddress     Address of entry
 *  @param[in,out] EntrySize        Size of entry
 *  @param[in,out] EntryDestination Destination of entry
 *
 *  @retval TRUE   Success to get the Entry 's properties
 *  @retval FALSE  Fail to get the Entry 's properties
 *
 **/
BOOLEAN
BIOSEntryInfo (
  IN       UINT8                       EntryType,
  IN       UINT8                       EntryInstance,
  IN OUT   TYPE_ATTRIB                 *TypeAttrib,
  IN OUT   UINT64                      *EntryAddress,
  IN OUT   UINT32                      *EntrySize,
  IN OUT   UINT64                      *EntryDestination
  );

