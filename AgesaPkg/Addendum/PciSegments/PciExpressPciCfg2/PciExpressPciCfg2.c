/*****************************************************************************
 *
 * Copyright (C) 2018-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#include <PiPei.h>
#include <Ppi/PciCfg2.h>
#include <Library/BaseLib.h>
#include <Library/PcdLib.h>
#include <Library/DebugLib.h>
//#include <Library/PeimEntryPoint.h>
#include "VirtualMemory.h"

#define PCI_SEGMENT_COUNT 8

//
// Global Descriptor Table (GDT)
//
GLOBAL_REMOVE_IF_UNREFERENCED IA32_GDT gGdtEntries[] = {
/* selector { Global Segment Descriptor                              } */
/* 0x00 */  {{0,      0,  0,  0,    0,  0,  0,  0,    0,  0, 0,  0,  0}}, //null descriptor
/* 0x08 */  {{0xffff, 0,  0,  0x2,  1,  0,  1,  0xf,  0,  0, 1,  1,  0}}, //linear data segment descriptor
/* 0x10 */  {{0xffff, 0,  0,  0xf,  1,  0,  1,  0xf,  0,  0, 1,  1,  0}}, //linear code segment descriptor
/* 0x18 */  {{0xffff, 0,  0,  0x3,  1,  0,  1,  0xf,  0,  0, 1,  1,  0}}, //system data segment descriptor
/* 0x20 */  {{0xffff, 0,  0,  0xa,  1,  0,  1,  0xf,  0,  0, 1,  1,  0}}, //system code segment descriptor
/* 0x28 */  {{0,      0,  0,  0,    0,  0,  0,  0,    0,  0, 0,  0,  0}}, //spare segment descriptor
/* 0x30 */  {{0xffff, 0,  0,  0x2,  1,  0,  1,  0xf,  0,  0, 1,  1,  0}}, //system data segment descriptor
/* 0x38 */  {{0xffff, 0,  0,  0xa,  1,  0,  1,  0xf,  0,  1, 0,  1,  0}}, //system code segment descriptor
/* 0x40 */  {{0,      0,  0,  0,    0,  0,  0,  0,    0,  0, 0,  0,  0}}, //spare segment descriptor
};

//
// IA32 Gdt register
//
GLOBAL_REMOVE_IF_UNREFERENCED CONST IA32_DESCRIPTOR gGdt = {
  sizeof (gGdtEntries) - 1,
  (UINTN) gGdtEntries
  };

UINTN                     PageTables = 0;

UINT32
EFIAPI
AsmPciReadWrite (
  IN       UINT64                    Address,
  IN       UINT8                     Width,
  IN       UINT32                    Value,
  IN       UINT32                    RW,
  IN CONST IA32_DESCRIPTOR           *Gdt
  );

STATIC
UINT32
EFIAPI
PciReadWrite (
  IN      UINT64                    Address,
  IN      UINT8                     Width,
  IN      UINT32                    Value,
  IN      UINT32                    RW
  )
{
  UINT32 ReturnValue;
  UINTN  OrgCr3;

  if (Width != 8 && Width != 16 && Width != 32) {
    ASSERT (FALSE);
    return 0;
  }

  AsmWriteCr0 (AsmReadCr0 () & (~BIT31));
  OrgCr3 = AsmReadCr3 ();
  AsmWriteCr3 (PageTables);

  ReturnValue = AsmPciReadWrite (Address, Width, Value, RW, &gGdt);

  AsmWriteCr3 (OrgCr3);

  return ReturnValue;
}

STATIC
UINT32
EFIAPI
PciRead (
  IN      UINT64                    Address,
  IN      UINT8                     Width
  )
{
  UINT32 Value;

  Value = PciReadWrite (Address, Width, 0, 0);

  return Value;
}

STATIC
VOID
EFIAPI
PciWrite (
  IN      UINT64                    Address,
  IN      UINT32                    Value,
  IN      UINT8                     Width
  )
{
  PciReadWrite (Address, Width, Value, 1);
}

STATIC
UINT8
EFIAPI
PciRead8 (
  IN      UINT64                    Address
  )
{
  return (UINT8) PciRead (Address, 8);
}

STATIC
VOID
EFIAPI
PciWrite8 (
  IN      UINT64                    Address,
  IN      UINT8                     Value
  )
{
  PciWrite (Address, Value, 8);
}

STATIC
UINT16
EFIAPI
PciRead16 (
  IN      UINT64                    Address
  )
{
  return (UINT16) PciRead (Address, 16);
}

STATIC
VOID
EFIAPI
PciWrite16 (
  IN      UINT64                    Address,
  IN      UINT16                    Value
  )
{
  PciWrite (Address, Value, 16);
}

STATIC
UINT32
EFIAPI
PciRead32 (
  IN      UINT64                    Address
  )
{
  return (UINT32) PciRead (Address, 32);
}

STATIC
VOID
EFIAPI
PciWrite32 (
  IN      UINT64                    Address,
  IN      UINT32                    Value
  )
{
  PciWrite (Address, Value, 32);
}

STATIC
VOID
EFIAPI
PciAndThenOr8 (
  IN      UINT64                    Address,
  IN      UINT8                     AndData,
  IN      UINT8                     OrData
  )
{
  PciWrite8 (Address, (UINT8) ((PciRead8 (Address) & AndData) | OrData));
}

STATIC
VOID
EFIAPI
PciAndThenOr16 (
  IN      UINT64                    Address,
  IN      UINT16                    AndData,
  IN      UINT16                    OrData
  )
{
  PciWrite16 (Address, (UINT16) ((PciRead16 (Address) & AndData) | OrData));
}

STATIC
VOID
EFIAPI
PciAndThenOr32 (
  IN      UINT64                    Address,
  IN      UINT32                    AndData,
  IN      UINT32                    OrData
  )
{
  PciWrite32 (Address, (UINT32) ((PciRead32 (Address) & AndData) | OrData));
}

STATIC
UINT64
PciCfgAddressConvert (
  IN CONST  EFI_PEI_PCI_CFG2_PPI            *This,
  IN        EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS *Address
  )
{
  UINT64 PcieBase, seg, bus, dev, func, reg;

  PcieBase = PcdGet64 (PcdPciExpressBaseAddress);
  seg = LShiftU64 (This->Segment, 28);
  bus = LShiftU64 (Address->Bus, 20);
  dev = LShiftU64 (Address->Device, 15);
  func = LShiftU64 (Address->Function, 12);
  reg = (Address->ExtendedRegister == 0 ? Address->Register : Address->ExtendedRegister);

  return PcieBase + seg + bus + dev + func + reg;
}

/**
  Reads from a given location in the PCI configuration space.

  @param  PeiServices     An indirect pointer to the PEI Services Table published by the PEI Foundation.
  @param  This            Pointer to local data for the interface.
  @param  Width           The width of the access. Enumerated in bytes.
                          See EFI_PEI_PCI_CFG_PPI_WIDTH above.
  @param  Address         The physical address of the access. The format of
                          the address is described by EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS.
  @param  Buffer          A pointer to the buffer of data.

  @retval EFI_SUCCESS           The function completed successfully.
  @retval EFI_INVALID_PARAMETER The invalid access width.

**/
STATIC
EFI_STATUS
EFIAPI
PciCfg2Read (
  IN CONST  EFI_PEI_SERVICES          **PeiServices,
  IN CONST  EFI_PEI_PCI_CFG2_PPI      *This,
  IN        EFI_PEI_PCI_CFG_PPI_WIDTH Width,
  IN        UINT64                    Address,
  IN OUT    VOID                      *Buffer
  )
{
  UINT64  PcieAddress;

  PcieAddress = PciCfgAddressConvert (This, (EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS *) &Address);

  if (Width == EfiPeiPciCfgWidthUint8) {
    *((UINT8 *) Buffer) = PciRead8 (PcieAddress);
  } else if (Width == EfiPeiPciCfgWidthUint16) {
    if ((PcieAddress & 0x01) == 0) {
      //
      // Aligned Pci address access
      //
      WriteUnaligned16 (((UINT16 *) Buffer), PciRead16 (PcieAddress));
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      *((UINT8 *) Buffer) = PciRead8 (PcieAddress);
      *((UINT8 *) Buffer + 1) = PciRead8 (PcieAddress + 1);
    }
  } else if (Width == EfiPeiPciCfgWidthUint32) {
    if ((PcieAddress & 0x03) == 0) {
      //
      // Aligned Pci address access
      //
      WriteUnaligned32 (((UINT32 *) Buffer), PciRead32 (PcieAddress));
    } else if ((PcieAddress & 0x01) == 0) {
      //
      // Unaligned Pci address access, break up the request into word by word.
      //
      WriteUnaligned16 (((UINT16 *) Buffer), PciRead16 (PcieAddress));
      WriteUnaligned16 (((UINT16 *) Buffer + 1), PciRead16 (PcieAddress + 2));
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      *((UINT8 *) Buffer) = PciRead8 (PcieAddress);
      *((UINT8 *) Buffer + 1) = PciRead8 (PcieAddress + 1);
      *((UINT8 *) Buffer + 2) = PciRead8 (PcieAddress + 2);
      *((UINT8 *) Buffer + 3) = PciRead8 (PcieAddress + 3);
    }
  } else if (Width == EfiPeiPciCfgWidthUint64) {
    if ((PcieAddress & 0x03) == 0) {
      //
      // Aligned Pci address access
      //
      WriteUnaligned32 (((UINT32 *) Buffer), PciRead32 (PcieAddress));
      WriteUnaligned32 (((UINT32 *) Buffer + 1), PciRead32 (PcieAddress + 4));
    } else if ((PcieAddress & 0x01) == 0) {
      //
      // Unaligned Pci address access, break up the request into word by word.
      //
      WriteUnaligned16 (((UINT16 *) Buffer), PciRead16 (PcieAddress));
      WriteUnaligned16 (((UINT16 *) Buffer + 1), PciRead16 (PcieAddress + 2));
      WriteUnaligned16 (((UINT16 *) Buffer + 2), PciRead16 (PcieAddress + 4));
      WriteUnaligned16 (((UINT16 *) Buffer + 3), PciRead16 (PcieAddress + 6));
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      *((UINT8 *) Buffer) = PciRead8 (PcieAddress);
      *((UINT8 *) Buffer + 1) = PciRead8 (PcieAddress + 1);
      *((UINT8 *) Buffer + 2) = PciRead8 (PcieAddress + 2);
      *((UINT8 *) Buffer + 3) = PciRead8 (PcieAddress + 3);
      *((UINT8 *) Buffer + 4) = PciRead8 (PcieAddress + 4);
      *((UINT8 *) Buffer + 5) = PciRead8 (PcieAddress + 5);
      *((UINT8 *) Buffer + 6) = PciRead8 (PcieAddress + 6);
      *((UINT8 *) Buffer + 7) = PciRead8 (PcieAddress + 7);
    }
  } else {
    return EFI_INVALID_PARAMETER;
  }

  return EFI_SUCCESS;
}

/**
  Write to a given location in the PCI configuration space.

  @param  PeiServices     An indirect pointer to the PEI Services Table published by the PEI Foundation.
  @param  This            Pointer to local data for the interface.
  @param  Width           The width of the access. Enumerated in bytes.
                          See EFI_PEI_PCI_CFG_PPI_WIDTH above.
  @param  Address         The physical address of the access. The format of
                          the address is described by EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS.
  @param  Buffer          A pointer to the buffer of data.

  @retval EFI_SUCCESS           The function completed successfully.
  @retval EFI_INVALID_PARAMETER The invalid access width.

**/
STATIC
EFI_STATUS
EFIAPI
PciCfg2Write (
  IN CONST  EFI_PEI_SERVICES          **PeiServices,
  IN CONST  EFI_PEI_PCI_CFG2_PPI      *This,
  IN        EFI_PEI_PCI_CFG_PPI_WIDTH Width,
  IN        UINT64                    Address,
  IN OUT    VOID                      *Buffer
  )
{
  UINT64  PcieAddress;

  PcieAddress = PciCfgAddressConvert (This, (EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS *) &Address);

  if (Width == EfiPeiPciCfgWidthUint8) {
    PciWrite8 (PcieAddress, *((UINT8 *) Buffer));
  } else if (Width == EfiPeiPciCfgWidthUint16) {
    if ((PcieAddress & 0x01) == 0) {
      //
      // Aligned Pci address access
      //
      PciWrite16 (PcieAddress, ReadUnaligned16 ((UINT16 *) Buffer));
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      PciWrite8 (PcieAddress, *((UINT8 *) Buffer));
      PciWrite8 (PcieAddress + 1, *((UINT8 *) Buffer + 1));
    }
  } else if (Width == EfiPeiPciCfgWidthUint32) {
    if ((PcieAddress & 0x03) == 0) {
      //
      // Aligned Pci address access
      //
      PciWrite32 (PcieAddress, ReadUnaligned32 ((UINT32 *) Buffer));
    } else if ((PcieAddress & 0x01) == 0) {
      //
      // Unaligned Pci address access, break up the request into word by word.
      //
      PciWrite16 (PcieAddress, ReadUnaligned16 ((UINT16 *) Buffer));
      PciWrite16 (PcieAddress + 2, ReadUnaligned16 ((UINT16 *) Buffer + 1));
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      PciWrite8 (PcieAddress, *((UINT8 *) Buffer));
      PciWrite8 (PcieAddress + 1, *((UINT8 *) Buffer + 1));
      PciWrite8 (PcieAddress + 2, *((UINT8 *) Buffer + 2));
      PciWrite8 (PcieAddress + 3, *((UINT8 *) Buffer + 3));
    }
  } else if (Width == EfiPeiPciCfgWidthUint64) {
    if ((PcieAddress & 0x03) == 0) {
      //
      // Aligned Pci address access
      //
      PciWrite32 (PcieAddress, ReadUnaligned32 ((UINT32 *) Buffer));
      PciWrite32 (PcieAddress+4, ReadUnaligned32 ((UINT32 *) Buffer + 1));
    } else if ((PcieAddress & 0x01) == 0) {
      //
      // Unaligned Pci address access, break up the request into word by word.
      //
      PciWrite16 (PcieAddress, ReadUnaligned16 ((UINT16 *) Buffer));
      PciWrite16 (PcieAddress + 2, ReadUnaligned16 ((UINT16 *) Buffer + 1));
      PciWrite16 (PcieAddress + 4, ReadUnaligned16 ((UINT16 *) Buffer + 2));
      PciWrite16 (PcieAddress + 6, ReadUnaligned16 ((UINT16 *) Buffer + 3));
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      PciWrite8 (PcieAddress, *((UINT8 *) Buffer));
      PciWrite8 (PcieAddress + 1, *((UINT8 *) Buffer + 1));
      PciWrite8 (PcieAddress + 2, *((UINT8 *) Buffer + 2));
      PciWrite8 (PcieAddress + 3, *((UINT8 *) Buffer + 3));
      PciWrite8 (PcieAddress + 4, *((UINT8 *) Buffer + 4));
      PciWrite8 (PcieAddress + 5, *((UINT8 *) Buffer + 5));
      PciWrite8 (PcieAddress + 6, *((UINT8 *) Buffer + 6));
      PciWrite8 (PcieAddress + 7, *((UINT8 *) Buffer + 7));
    }
  } else {
    return EFI_INVALID_PARAMETER;
  }

  return EFI_SUCCESS;
}


/**
  This function performs a read-modify-write operation on the contents from a given
  location in the PCI configuration space.

  @param  PeiServices     An indirect pointer to the PEI Services Table
                          published by the PEI Foundation.
  @param  This            Pointer to local data for the interface.
  @param  Width           The width of the access. Enumerated in bytes. Type
                          EFI_PEI_PCI_CFG_PPI_WIDTH is defined in Read().
  @param  Address         The physical address of the access.
  @param  SetBits         Points to value to bitwise-OR with the read configuration value.
                          The size of the value is determined by Width.
  @param  ClearBits       Points to the value to negate and bitwise-AND with the read configuration value.
                          The size of the value is determined by Width.

  @retval EFI_SUCCESS           The function completed successfully.
  @retval EFI_INVALID_PARAMETER The invalid access width.

**/
STATIC
EFI_STATUS
EFIAPI
PciCfg2Modify (
  IN CONST  EFI_PEI_SERVICES          **PeiServices,
  IN CONST  EFI_PEI_PCI_CFG2_PPI      *This,
  IN        EFI_PEI_PCI_CFG_PPI_WIDTH Width,
  IN        UINT64                    Address,
  IN        VOID                      *SetBits,
  IN        VOID                      *ClearBits
  )
{
  UINT64  PcieAddress;
  UINT16  ClearValue16;
  UINT16  SetValue16;
  UINT32  ClearValue32;
  UINT32  SetValue32;

  PcieAddress = PciCfgAddressConvert (This, (EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS *) &Address);

  if (Width == EfiPeiPciCfgWidthUint8) {
    PciAndThenOr8 (PcieAddress, (UINT8) (~(*(UINT8 *) ClearBits)), *((UINT8 *) SetBits));
  } else if (Width == EfiPeiPciCfgWidthUint16) {
    if ((PcieAddress & 0x01) == 0) {
      //
      // Aligned Pci address access
      //
      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits);
      PciAndThenOr16 (PcieAddress, ClearValue16, SetValue16);
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      PciAndThenOr8 (PcieAddress, (UINT8) (~(*(UINT8 *) ClearBits)), *((UINT8 *) SetBits));
      PciAndThenOr8 (PcieAddress + 1, (UINT8) (~(*((UINT8 *) ClearBits + 1))), *((UINT8 *) SetBits + 1));
    }
  } else if (Width == EfiPeiPciCfgWidthUint32) {
    if ((PcieAddress & 0x03) == 0) {
      //
      // Aligned Pci address access
      //
      ClearValue32  = (UINT32) (~ReadUnaligned32 ((UINT32 *) ClearBits));
      SetValue32    = ReadUnaligned32 ((UINT32 *) SetBits);
      PciAndThenOr32 (PcieAddress, ClearValue32, SetValue32);
    } else if ((PcieAddress & 0x01) == 0) {
      //
      // Unaligned Pci address access, break up the request into word by word.
      //
      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits);
      PciAndThenOr16 (PcieAddress, ClearValue16, SetValue16);

      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits + 1));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits + 1);
      PciAndThenOr16 (PcieAddress + 2, ClearValue16, SetValue16);
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      PciAndThenOr8 (PcieAddress, (UINT8) (~(*(UINT8 *) ClearBits)), *((UINT8 *) SetBits));
      PciAndThenOr8 (PcieAddress + 1, (UINT8) (~(*((UINT8 *) ClearBits + 1))), *((UINT8 *) SetBits + 1));
      PciAndThenOr8 (PcieAddress + 2, (UINT8) (~(*((UINT8 *) ClearBits + 2))), *((UINT8 *) SetBits + 2));
      PciAndThenOr8 (PcieAddress + 3, (UINT8) (~(*((UINT8 *) ClearBits + 3))), *((UINT8 *) SetBits + 3));
    }
  } else if (Width == EfiPeiPciCfgWidthUint64) {
    if ((PcieAddress & 0x03) == 0) {
      //
      // Aligned Pci address access
      //
      ClearValue32  = (UINT32) (~ReadUnaligned32 ((UINT32 *) ClearBits));
      SetValue32    = ReadUnaligned32 ((UINT32 *) SetBits);
      PciAndThenOr32 (PcieAddress, ClearValue32, SetValue32);

      ClearValue32  = (UINT32) (~ReadUnaligned32 ((UINT32 *) ClearBits + 1));
      SetValue32    = ReadUnaligned32 ((UINT32 *) SetBits + 1);
      PciAndThenOr32 (PcieAddress + 4, ClearValue32, SetValue32);
    } else if ((PcieAddress & 0x01) == 0) {
      //
      // Unaligned Pci address access, break up the request into word by word.
      //
      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits);
      PciAndThenOr16 (PcieAddress, ClearValue16, SetValue16);

      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits + 1));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits + 1);
      PciAndThenOr16 (PcieAddress + 2, ClearValue16, SetValue16);

      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits + 2));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits + 2);
      PciAndThenOr16 (PcieAddress + 4, ClearValue16, SetValue16);

      ClearValue16  = (UINT16) (~ReadUnaligned16 ((UINT16 *) ClearBits + 3));
      SetValue16    = ReadUnaligned16 ((UINT16 *) SetBits + 3);
      PciAndThenOr16 (PcieAddress + 6, ClearValue16, SetValue16);
    } else {
      //
      // Unaligned Pci address access, break up the request into byte by byte.
      //
      PciAndThenOr8 (PcieAddress, (UINT8) (~(*(UINT8 *) ClearBits)), *((UINT8 *) SetBits));
      PciAndThenOr8 (PcieAddress + 1, (UINT8) (~(*((UINT8 *) ClearBits + 1))), *((UINT8 *) SetBits + 1));
      PciAndThenOr8 (PcieAddress + 2, (UINT8) (~(*((UINT8 *) ClearBits + 2))), *((UINT8 *) SetBits + 2));
      PciAndThenOr8 (PcieAddress + 3, (UINT8) (~(*((UINT8 *) ClearBits + 3))), *((UINT8 *) SetBits + 3));
      PciAndThenOr8 (PcieAddress + 4, (UINT8) (~(*((UINT8 *) ClearBits + 4))), *((UINT8 *) SetBits + 4));
      PciAndThenOr8 (PcieAddress + 5, (UINT8) (~(*((UINT8 *) ClearBits + 5))), *((UINT8 *) SetBits + 5));
      PciAndThenOr8 (PcieAddress + 6, (UINT8) (~(*((UINT8 *) ClearBits + 6))), *((UINT8 *) SetBits + 6));
      PciAndThenOr8 (PcieAddress + 7, (UINT8) (~(*((UINT8 *) ClearBits + 7))), *((UINT8 *) SetBits + 7));
    }
  } else {
    return EFI_INVALID_PARAMETER;
  }

  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
EFIAPI
PrepareX64PageTable (
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )
{
  PageTables = CreateIdentityMappingPageTables (0, 0, 0, 0);

  if (PageTables) {
    return EFI_SUCCESS;
  } else {
    return EFI_OUT_OF_RESOURCES;
  }
}

typedef struct {
  EFI_PEI_PPI_DESCRIPTOR PpiDescriptor;
  EFI_PEI_PCI_CFG2_PPI   PciCfg2;
} PEI_PCI_SEGMENT_STRUCT;

/**
  Module's entry function.
  This routine will install EFI_PEI_PCI_CFG2_PPI.

  @param  FileHandle  Handle of the file being invoked.
  @param  PeiServices Describes the list of possible PEI Services.

  @return Whether success to install service.
**/
EFI_STATUS
EFIAPI
PeimInitializePciCfg (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )
{
  EFI_STATUS             Status;
  UINT16                 Index;
  PEI_PCI_SEGMENT_STRUCT *PciSegStruct;
  EFI_PHYSICAL_ADDRESS   PhysicalAddress;

  Status = PrepareX64PageTable (PeiServices);
  if (Status != EFI_SUCCESS) {
    DEBUG ((EFI_D_ERROR, "[PeimInitializePciCfg] Unable to prepare x64 page table: %r\n", Status));
    return Status;
  }

  Status = (*PeiServices)->AllocatePages (PeiServices, EfiBootServicesData, EFI_SIZE_TO_PAGES (sizeof (PEI_PCI_SEGMENT_STRUCT) * PCI_SEGMENT_COUNT), &PhysicalAddress);
  if (Status != EFI_SUCCESS) {
    DEBUG ((EFI_D_ERROR, "[PeimInitializePciCfg] Unable to allocate page: %r\n", Status));
    return Status;
  }

  PciSegStruct = (PEI_PCI_SEGMENT_STRUCT *) (UINTN) PhysicalAddress;
  for (Index = 0; Index < PCI_SEGMENT_COUNT; Index++) {
    PciSegStruct[Index].PciCfg2.Read = PciCfg2Read;
    PciSegStruct[Index].PciCfg2.Write = PciCfg2Write;
    PciSegStruct[Index].PciCfg2.Modify = PciCfg2Modify;
    PciSegStruct[Index].PciCfg2.Segment = Index;

    PciSegStruct[Index].PpiDescriptor.Flags = EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST;
    PciSegStruct[Index].PpiDescriptor.Guid = &gEfiPciCfg2PpiGuid;
    PciSegStruct[Index].PpiDescriptor.Ppi = &PciSegStruct[Index].PciCfg2;

    Status = (*PeiServices)->InstallPpi (PeiServices, &PciSegStruct[Index].PpiDescriptor);
    DEBUG ((EFI_D_INFO, "[PeimInitializePciCfg] Install EFI_PEI_PCI_CFG2_PPI for segment 0x%x: %r\n", Index, Status));
    ASSERT_EFI_ERROR (Status);
  }

  return Status;
}
