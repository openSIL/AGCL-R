/*
*****************************************************************************
*
 * Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*******************************************************************************
*/

/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */
#include <Filecode.h>
#include <Library/FchEspiGenoaLib.h>


/*----------------------------------------------------------------------------------------
 *                   D E F I N I T I O N S    A N D    M A C R O S
 *----------------------------------------------------------------------------------------
 */
#define FILECODE LIBRARY_FCHESPILIB_FCHESPIGENOALIB_FILECODE


/*----------------------------------------------------------------------------------------
 *                  T Y P E D E F S     A N D     S T R U C T U R E S
 *----------------------------------------------------------------------------------------
 */


/*----------------------------------------------------------------------------------------
 *           P R O T O T Y P E S     O F     L O C A L     F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */


/*----------------------------------------------------------------------------------------
 *                          E X P O R T E D    F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */
 /*----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------*/
/**
 * IsLegacyIORangeMatch - compare
 *
 * @param[in]  EspiIorange       Espi IO range base
 * @param[in]  LegacyIO          LegacyIO table array list LegacyIO[x]  0 :  the terminal of this array pointer
 *
 * @retval    TRUE       this espiIO range is matched with LegacyIO list
 * @retval    FALSE      this espiIO range is not matched with LegacyIO list
 */
static
BOOLEAN
IsLegacyIORangeMatch (
  IN  UINT16  EspiIorange,
  IN  UINT16  *LegacyIO
  )
{
  BOOLEAN  IsMatch = FALSE;
  UINT8    i;

  for ( i = 0; LegacyIO[i] != 0; i++) {
    if ( EspiIorange == LegacyIO[i] ) {
      // DEBUG ((DEBUG_INFO, "EspiIorange=0x%x matched LegacyIO[%d] \n", EspiIorange, i ));
      IsMatch = TRUE;
      break;
    }
  }

  return IsMatch;
}


/**
 * ClsEspiIOBaseForlegacyIO - clear espi IO range if it is equal to legacy Uart IO range.
 *
 * @param[in]  EspiBase
 * @param[in]  LegacyIO      LegacyIO[x]  0 :  the terminal of this array pointer    ex: LegacyIO[0] = 0x3F8;  LegacyIO[1] = 0;
 */
static
VOID
ClsEspiIOBaseForlegacyIO (
  IN  UINT32  EspiBase,
  IN  UINT16  *LegacyIO
  )
{
  UINT32   Secondary0DecodeEnBitMap    = 0;                     // SECONDARY0_DECODE_EN  BIT8-11 : IO range 0-3  BIT16-27 : IO Range 4-15
  UINT32   Secondary0DecodeEnBitMapNew = 0;
  UINT32   Secondary0IoBaseReg         = 0;
  UINT32   Secondary0IoBaseRegNew      = 0;
  UINT16   EspiIorange             = 0;
  UINT8    RegOffset[]             = { 0x44, 0x48, 0x80, 0x84, 0x8C, 0x90, 0xB0, 0xB4, 0xFF };           // SECONDARY0_IO_BASE_REG0 ~  SECONDARY0_IO_BASE_REG7
  UINTN    DecodeBitmap[]          = { BIT8, BIT10, BIT16, BIT18, BIT20, BIT22, BIT24, BIT26 };          //SECONDARY0_DECODE_EN BIT8-11 : IO range 0-3  BIT16-27 : IO Range 4-15
  UINT8    i;
  BOOLEAN  IsMatch = FALSE;


  Secondary0DecodeEnBitMap = *((volatile UINT32 *)((UINTN)(EspiBase + 0x40))); //  SECONDARY0_DECODE_EN reg offset :0x40
  Secondary0DecodeEnBitMapNew = Secondary0DecodeEnBitMap;
  #if 0
   // dump LegacyIO
   for ( i = 0; i < 5; i++) {
      DEBUG ((DEBUG_INFO, "LegacyIO[%d]=0x%x \n", i, LegacyIO[i] ));
   }
  #endif

  for ( i = 0; RegOffset[i] < 0xFF; i++) {
    Secondary0IoBaseReg = *((volatile UINT32 *)((UINTN)(EspiBase + RegOffset[i])));
    if ( Secondary0IoBaseReg == 0 ) {
      continue;
    }

    Secondary0IoBaseRegNew = Secondary0IoBaseReg;
    //check the lower IO range of this SECONDARY0_IO_BASE_REGx
    EspiIorange = (UINT16)(Secondary0IoBaseRegNew & 0xFFFF);
    if ( EspiIorange != 0 ) {
      IsMatch = IsLegacyIORangeMatch (EspiIorange, LegacyIO);
      if ( IsMatch) {
        // clear this IO rang and enable bit map
        Secondary0IoBaseRegNew      &= 0xFFFF0000;
        Secondary0DecodeEnBitMapNew &= (UINT32)(~DecodeBitmap[i]);
      }
    }
    //check the upper IO range of this SECONDARY0_IO_BASE_REGx
    EspiIorange = (UINT16)(Secondary0IoBaseRegNew >> 16);
    if ( EspiIorange != 0 ) {
      IsMatch = IsLegacyIORangeMatch (EspiIorange, LegacyIO);
      if ( IsMatch) {
        // clear this IO rang
        Secondary0IoBaseRegNew      &= 0x0000FFFF;
        Secondary0DecodeEnBitMapNew &= (UINT32)(~(DecodeBitmap[i] << 1));
      }
    }
    //Write SECONDARY0_IO_BASE_REGx with value if modifided.
    if ( Secondary0IoBaseReg != Secondary0IoBaseRegNew ) {
      *((volatile UINT32 *)((UINTN)(EspiBase + RegOffset[i]))) = Secondary0IoBaseRegNew;
    }
  }

  // disable decode Enbit map ( SECONDARY0_DECODE_EN reg offset :0x40 )
  if ( Secondary0DecodeEnBitMap != Secondary0DecodeEnBitMapNew ) {
    *((volatile UINT32 *)((UINTN)(EspiBase + 0x40))) = Secondary0DecodeEnBitMapNew;
  }
}


/**
 * ClsEspiIOForlegacyIO - clear espi IO range if it is equal to legacy Uart IO range.
 *
 * @param[in]  LegacyIO      LegacyIO[x]  0 :  the terminal of this array pointer   ex: LegacyIO[0] = 0x3F8; LegacyIO[1] = 0x2F8;  LegacyIO[2] = 0;
 */
VOID
ClsEspiIOForlegacyIO (
  IN  UINT16  *LegacyIO
  )
 {
   UINT32  EspiBase;

   EspiBase = 0xFEC20000;
   //espi0
   ClsEspiIOBaseForlegacyIO(EspiBase, LegacyIO);
   //espi1
   ClsEspiIOBaseForlegacyIO(EspiBase+0x10000, LegacyIO);
 }