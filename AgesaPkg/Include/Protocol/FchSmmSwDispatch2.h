/*****************************************************************************
 * Copyright (C) 2008-2022 Advanced Micro Devices, Inc. All rights reserved.
 *
*****************************************************************************
*/
/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD FCH SMM SW Dispacther Protocol
 *
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AMD FCH UEFI Drivers
 * @e sub-project:  Protocols
 * @e \$Revision: 309090 $   @e \$Date: 2014-12-09 10:28:05 -0800 (Tue, 09 Dec 2014) $
 *
 */
#ifndef _FCH_SMM_SW_DISPATCH2_PROTOCOL_H_
#define _FCH_SMM_SW_DISPATCH2_PROTOCOL_H_

#include <Pi/PiSmmCis.h>

/**
 * @brief AMD FCH SMM SW Dispatch2 protocol GUID
 */
extern EFI_GUID gFchSmmSwDispatch2ProtocolGuid;

/// Forward declaration for the FCH_SMM_SW_DISPATCH2_PROTOCOL
typedef struct _FCH_SMM_SW_DISPATCH2_PROTOCOL FCH_SMM_SW_DISPATCH2_PROTOCOL;

/// FCH SW SMM Register Context structure
typedef struct {
  UINTN AmdSwValue;                 ///< Soft SMI value
  UINT8 Order;                      ///< Priority 0-Highest (reserved), 0xFF-Lowest (reserved)
} FCH_SMM_SW_REGISTER_CONTEXT;

/// SMM Software SMI Context
typedef struct {
  UINTN    SwSmiCpuIndex;   ///< 0-based CPU ID
  UINT8    CommandPort;     ///< SMI Command port
  UINT8    DataPort;        ///< SMI Data Port
} FCH_SMM_SW_CONTEXT;

/**
 * @brief Prototype of FCH_SMM_SW_HANDLER_ENTRY_POINT2
 * @param DispatchHandle Dispatch handle
 * @param DispatchContext Pointer to FCH_SMM_SW_REGISTER_CONTEXT structure
 * @param SwContext Pointer to FCH_SMM_SW_CONTEXT
 * @param SizeOfSwContext Size of SW Context
 */
typedef
EFI_STATUS
(EFIAPI *FCH_SMM_SW_HANDLER_ENTRY_POINT2) (
  IN       EFI_HANDLE                          DispatchHandle,
  IN CONST FCH_SMM_SW_REGISTER_CONTEXT         *DispatchContext,
  IN OUT   FCH_SMM_SW_CONTEXT                  *SwContext,
  IN OUT   UINTN                               *SizeOfSwContext
);

/**
 * @brief Prototype of FCH_SMM_SW_DISPATCH2_REGISTER
 * @param This Pointer to FCH SMM SW DISPATCH2 PROTOCOL
 * @param DispatchFunction Callback function for SMM SW
 * @param SwRegisterContext Pointer to the SW Register Context
 * @param DispatchHandle Dispatch Handle
 */
typedef
EFI_STATUS
(EFIAPI *FCH_SMM_SW_DISPATCH2_REGISTER) (
  IN CONST FCH_SMM_SW_DISPATCH2_PROTOCOL       *This,
  IN       FCH_SMM_SW_HANDLER_ENTRY_POINT2     DispatchFunction,
  IN CONST FCH_SMM_SW_REGISTER_CONTEXT         *SwRegisterContext,
     OUT   EFI_HANDLE                          *DispatchHandle
);

/**
 * @brief Prototype of FCH_SMM_SW_DISPATCH2_UNREGISTER
 * @param This Pointer to FCH_SMM_SW_DISPATCH2_PROTOCOL
 * @param DispatchHandle Dispatch Handle
 */
typedef
EFI_STATUS
(EFIAPI *FCH_SMM_SW_DISPATCH2_UNREGISTER) (
  IN CONST FCH_SMM_SW_DISPATCH2_PROTOCOL       *This,
  IN       EFI_HANDLE                          DispatchHandle
);

/// FCH_SMM_SW_DISPATCH2_PROTOCOL Structure
struct  _FCH_SMM_SW_DISPATCH2_PROTOCOL {
  FCH_SMM_SW_DISPATCH2_REGISTER    Register;          ///< Register function
  FCH_SMM_SW_DISPATCH2_UNREGISTER  UnRegister;        ///< UnRegister function
  UINTN                            MaximumSwiValue;   ///< Maximum of SMI value
};


#endif


