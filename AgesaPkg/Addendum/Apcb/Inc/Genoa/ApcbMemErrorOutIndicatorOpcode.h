/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */
/**
 * ApcbMemErrorOutIndicatorOpcode.h
 *
 * APCB Memory Error Out Indicator Opcode definitions
 *
 */

#ifndef _APCB_MEM_ERROR_OUT_INDICATOR_OPCODE_H_
#define _APCB_MEM_ERROR_OUT_INDICATOR_OPCODE_H_
//
// @APCB_START
//

///===============================================================================
/**
 * @brief Script I/O Write operation structure
 * @details Contains the necessary parameters for an I/O Write operation
 */
typedef struct {
  UINT16                OpCode;   ///< Opcode for a Script I/O Write operation
  UINT16                Length;   ///< Script I/O Write structure length
  UINT32                Width;    ///< Width of the operation
  UINT32                Address;  ///< Address of the operation
} SCRIPT_IO_WRITE;

/**
 * @brief Script MMIO Write operation structure
 * @details Contains the necessary parameters for an MMIO Write operation
 */
typedef struct {
  UINT16                OpCode;   ///< Opcode for a Script MMIO Write operation
  UINT16                Length;   ///< Script MMIO Write structure length
  UINT32                Width;    ///< Width of the operation
  UINT32                Address;  ///< Address of the operation
} SCRIPT_MMIO_WRITE;

/**
 * @brief Script PCI Config Write operation
 * @details Contains the necessary parameters for a PCI Config Write operation
 */
typedef struct {
  UINT16                OpCode;   ///< Opcode for a Script PCI Config Write operation
  UINT16                Length;   ///< Script PCI Config Write structure length
  UINT32                Width;    ///< Width of the operation
  UINT32                Address;  ///< Address of the operation
} SCRIPT_PCICFG_WRITE;

/**
 * @brief Script Stall operation structure
 * @details Contains the necessary parameters for a Script Stall operation
 */
typedef struct {
  UINT16                OpCode;   ///< Opcode for a Script Stall operation
  UINT16                Length;   ///< Script Stall structure length
  UINT32                Duration; ///< Stall duration in microseconds
  UINT32                Reserved; ///< Reserved
} SCRIPT_STALL;

/**
 * @brief Script I/O Poll operation structure
 * @details Contains the necessary parameters for a Script I/O Poll operation
 */
typedef struct {
  UINT16                OpCode;   ///< Opcode for a Script I/O Poll operation
  UINT16                Length;   ///< Script I/O Poll structure length
  UINT32                Width;    ///< Width of the operation
  UINT32                Address;  ///< Address of the operation
  UINT32                Delay;    ///< Poll count
} SCRIPT_IO_POLL;

/**
 * @brief Script Table Header structure for executing Script Operations
 */
typedef struct {
  UINT16  OpCode;       ///< Opcode for Script Table execution
  UINT16  Length;       ///< Script Table Header structure length
  UINT32  Version;      ///< Script Table Header version
  UINT32  TableLength;  ///< Length of the Script Header Table
  UINT16  Reserved[2];  ///< Reserved
} SCRIPT_TABLE_HEADER;

/**
 * @brief Script Terminate operation structure
 * @details Contains the necessary parameters for a Script Terminate operation
 */
typedef struct {
  UINT16  OpCode; ///< Opcode for Script Termination operation
  UINT16  Length; ///< Script Termination structure length
} SCRIPT_TERMINATE;

///===============================================================================
/// Script Operation opcodes
#define SCRIPT_IO_WRITE_OPCODE                 0x00 ///< Script I/O Write opcode
#define SCRIPT_MMIO_WRITE_OPCODE               0x02 ///< Script MMIO Write opcode
#define SCRIPT_PCICFG_WRITE_OPCODE             0x04 ///< Script PCI Config Write opcode
#define SCRIPT_STALL_OPCODE                    0x07 ///< Script Stall opcode
#define SCRIPT_IO_POLL_OPCODE                  0x0D ///< Script I/O Poll opcode
#define SCRIPT_TERMINATE_OPCODE                0xFF ///< Script Terminate opcode

/**
 * @brief Script access widths
 */
typedef enum {
  ScriptAccessWidthNone = 0,  ///< dummy access width
  ScriptAccessWidth8    = 1,  ///< Access width is 8 bits.
  ScriptAccessWidth16,        ///< Access width is 16 bits.
  ScriptAccessWidth32,        ///< Access width is 32 bits.
} SCRIPT_ACCESS_WIDTH;

#endif // _APCB_MEM_ERROR_OUT_INDICATOR_OPCODE_H_
