/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

#ifndef _APCB_MEM_EVENT_CONTROL_H_
#define _APCB_MEM_EVENT_CONTROL_H_
//
// @APCB_START
//


///===============================================================================
/// PSP_EVENT_OUT_CONTROL_STRUCT
/// This data structure is used to control sending AGESA Event info to the specified port
///
typedef struct PSP_ERROR_OUT_CONTROL_STRUCT {
  IN
  BOOLEAN EVENT_OUT_PORT_ENABLED; ///< Indicates if AGESA PSP will output Event Info to specificed port
  IN
  BOOLEAN HALT_ON_CRITICAL_FATAL_EVENT_ENABLED; ///< Indicates if AGESA PSP will halt on critical/fatal event
  IN
  UINT64  EventInfoPort;    //< Port to output AGESA Event Info
} PSP_EVENT_OUT_CONTROL_STRUCT;


#endif // _APCB_MEM_EVENT_CONTROL_H_


