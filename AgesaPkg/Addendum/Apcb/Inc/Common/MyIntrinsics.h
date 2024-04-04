/*****************************************************************************
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * MyIntrinsics.h
 *
 * Contains definition needed for PSP support
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:  AGCL-R
 * @e sub-project:  ApcbGenerator
 * @e \$Revision: 83676 $   @e \$Date: 2012-12-07 15:57:01 -0600 (Fri, 07 Dec 2012) $
 *
 */

 #ifndef _MYINTRINSICS_H_
 #define _MYINTRINSICS_H_

  #define IN
  #define OUT
  #define STATIC static
  #define VOLATILE volatile
      #ifndef TRUE
        #define TRUE  1
      #endif
      #ifndef FALSE
        #define FALSE 0
      #endif
  //#define CONST const - avoid const until the large job of making agesa use it consistently is complete
  #ifndef CONST
  #define CONST
  #endif
  #define ROMDATA
  #define CALLCONV
  #define _8BYTE_ALIGN __attribute__ ((aligned (8)))
  #define _4BYTE_ALIGN __attribute__ ((aligned (4)))
  #define _2BYTE_ALIGN __attribute__ ((aligned (2)))
  #define _1BYTE_ALIGN __attribute__ ((aligned (1)))
  #define NON_BIT_REGISTER_TYPE
#endif



