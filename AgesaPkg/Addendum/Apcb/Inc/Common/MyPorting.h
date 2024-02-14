/*****************************************************************************
 * Copyright (C) 2015-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * Describes compiler dependencies - to support several compile time environments
 *
 * Contains compiler environment porting descriptions
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:  AGCL-R
 * @e sub-project:  ApcbGenerator
 * @e \$Revision: 276922 $   @e \$Date: 2014-10-29 12:38:41 -0600 (Tue, 29 Oct 2013) $
 */

#ifndef _MY_PORTING_H_
#define _MY_PORTING_H_

#if defined (_MSC_VER)
  #pragma warning(push)
  #pragma warning(disable: 4103 4001 4324)
  #pragma data_seg (".data")
  // -----------------------------------------------------------------------
  //   Define a code_seg MACRO
  //
  #define MAKE_AS_A_STRING(arg) #arg

  //#include <intrin.h>  // MS has built-in functions

  #if _MSC_VER < 900
    // -----------------------------------------------------------------------
    //    Assume MSVC 1.52C (16-bit)
    //
    //    NOTE: When using MSVC 1.52C use the following command line:
    //
    //       CL.EXE /G3 /AL /O1i /Fa <FILENAME.C>
    //
    //    This will produce 32-bit code in USE16 segment that is optimized for code
    //    size.
    typedef void          VOID;

    // Create the universal 32, 16, and 8-bit data types
    typedef unsigned long   UINTN;
    typedef          long   INT32;
    typedef unsigned long   UINT32;
    typedef          int    INT16;
    typedef unsigned int    UINT16;
    typedef          char   INT8;
    typedef unsigned char   UINT8;
    typedef          char   CHAR8;
    typedef unsigned short  CHAR16;

    /// struct for 16-bit environment handling of 64-bit value
    typedef struct _UINT64 {
      IN OUT  UINT32 lo;      ///< lower 32-bits of 64-bit value
      IN OUT  UINT32 hi;      ///< highest 32-bits of 64-bit value
    } UINT64;

    // Create the Boolean type
    #define TRUE  1
    #define FALSE 0
    typedef unsigned char BOOLEAN;

    #define CONST const
    #define STATIC static
    #define VOLATILE volatile
    #define CALLCONV __pascal
    #define ROMDATA __based( __segname( "_CODE" ) )
    #define _16BYTE_ALIGN   __declspec(align(16))
    #define _8BYTE_ALIGN   __declspec(align(8))
    #define _4BYTE_ALIGN   __declspec(align(4))
    #define _2BYTE_ALIGN   __declspec(align(2))
    #define _1BYTE_ALIGN   __declspec(align(1))

    // Force tight packing of structures
    // Note: Entire AGESA (Project / Solution) will be using pragma pack 1
    #pragma warning( disable : 4103 ) // Disable '#pragma pack' in .h warning
    #pragma pack()

    //   Disable WORD->BYTE automatic conversion warnings.  Example:
    //   BYTE LocalByte;
    //   void MyFunc(BYTE val);
    //
    //   MyFunc(LocalByte*2+1); // Warning, automatic conversion
    //
    //   The problem is any time math is performed on a BYTE, it is converted to a
    //   WORD by MSVC 1.52c, and then when it is converted back to a BYTE, a warning
    //   is generated.  Disable warning C4761
    #pragma warning( disable : 4761 )

  #else
    // -----------------------------------------------------------------------
    //   Assume a 32-bit MSVC++
    //
    // Disable the following warnings:
    // 4100 - 'identifier' : unreferenced formal parameter
    // 4276 - 'function' : no prototype provided; assumed no parameters
    // 4214 - non standard extension used : bit field types other than int
    // 4001 - nonstandard extension 'single line comment' was used
    // 4142 - benign redefinition of type for following declaration
    //      - typedef char    INT8
    #if defined (_M_IX86)
      #pragma warning (disable: 4100 4276 4214 4001 4142 4305 4306)

      #ifndef VOID
        typedef void VOID;
      #endif
    // Create the universal 32, 16, and 8-bit data types
      #ifndef UINTN
        typedef unsigned __w64 UINTN;
      #endif
      typedef          __int64 INT64;
      typedef unsigned __int64 UINT64;
      typedef          int   INT32;
      typedef unsigned int   UINT32;
      typedef          short INT16;
      typedef unsigned short UINT16;
      typedef          char  INT8;
      typedef unsigned char  UINT8;
      typedef          char  CHAR8;
      typedef unsigned short CHAR16;

    // Create the Boolean type
      #ifndef TRUE
        #define TRUE  1
      #endif
      #ifndef FALSE
        #define FALSE 0
      #endif
      typedef unsigned char BOOLEAN;

      // Force tight packing of structures
      // Note: Entire AGESA (Project / Solution) will be using pragma pack 1
      #pragma pack()

      #define CONST const
      #define STATIC static
      #define VOLATILE volatile
      #define CALLCONV
      #define ROMDATA
      #define _16BYTE_ALIGN   __declspec(align(64))
      #define _8BYTE_ALIGN   __declspec(align(8))
      #define _4BYTE_ALIGN   __declspec(align(4))
      #define _2BYTE_ALIGN   __declspec(align(2))
      #define _1BYTE_ALIGN   __declspec(align(1))
      //Support for variadic macros was introduced in Visual C++ 2005.
      #if _MSC_VER >= 1400
        #define VA_ARGS_SUPPORTED
      #endif
      // 64 bit of compiler
    #else
      #pragma warning (disable: 4100 4276 4214 4001 4142 4305 4306 4366)

      #ifndef VOID
        typedef void VOID;
      #endif
      // Create the universal 32, 16, and 8-bit data types
      #ifndef UINTN
        typedef unsigned __int64 UINTN;
      #endif
      typedef          __int64 INT64;
      typedef unsigned __int64 UINT64;
      typedef          int   INT32;
      typedef unsigned int   UINT32;
      typedef          short INT16;
      typedef unsigned short UINT16;
      typedef          char  INT8;
      typedef unsigned char  UINT8;
      typedef          char  CHAR8;
      typedef unsigned short CHAR16;

      // Create the Boolean type
      #ifndef TRUE
        #define TRUE  1
      #endif
      #ifndef FALSE
        #define FALSE 0
      #endif
      typedef unsigned char BOOLEAN;
      #define _16BYTE_ALIGN   __declspec(align(16))
      #define _8BYTE_ALIGN   __declspec(align(8))
      #define _4BYTE_ALIGN   __declspec(align(4))
      #define _2BYTE_ALIGN   __declspec(align(2))
      #define _1BYTE_ALIGN   __declspec(align(1))
      // Force tight packing of structures
      // Note: Entire AGESA (Project / Solution) will be using pragma pack 1
      #pragma pack()

      #define CONST const
      #define STATIC static
      #define VOLATILE volatile
      #define CALLCONV
      #define ROMDATA
    #endif
  #endif
  // -----------------------------------------------------------------------
  // End of MS compiler versions


#elif defined __GNUC__
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
  #pragma warning(push)
  #define IN
  #define OUT
  #define STATIC static
  #define VOLATILE volatile
  #define TRUE true
  #define FALSE false
  //#define CONST const - avoid const until the large job of making agesa use it consistently is complete
  #define CONST
  #define ROMDATA
  #define CALLCONV
  #define _16BYTE_ALIGN __attribute__ ((aligned (16)))
  #define _8BYTE_ALIGN __attribute__ ((aligned (8)))
  #define _4BYTE_ALIGN __attribute__ ((aligned (4)))
  #define _2BYTE_ALIGN __attribute__ ((aligned (2)))
  #define _1BYTE_ALIGN __attribute__ ((aligned (1)))

  typedef bool           BOOLEAN;
  typedef int8_t         INT8;
  typedef int16_t        INT16;
  typedef int32_t        INT32;
  typedef unsigned char  CHAR8;
  typedef uint8_t        UINT8;
  typedef uint16_t       UINT16;
  typedef uint32_t       UINT32;
  typedef size_t         UINTN;
  typedef uint64_t       UINT64;
  typedef void           VOID;

  #include "MyIntrinsics.h"               // AGESA temp file for GCC until support is added to MinGW
#else
  // -----------------------------------------------------------------------
  // Unknown or unsupported compiler - use for ARM compiler
  //
  #include "MyIntrinsics.h"               // AGESA temp file for ARM GCC
#endif



// -----------------------------------------------------------------------
// Common definitions for all compilers
//

//Support forward reference construct
#define AGESA_FORWARD_DECLARATION(x) typedef struct _##x x

#undef NULL
#define NULL              0

// The following are use in conformance to the UEFI style guide
#define IN
#define OUT

#endif // _PORTING_H_
