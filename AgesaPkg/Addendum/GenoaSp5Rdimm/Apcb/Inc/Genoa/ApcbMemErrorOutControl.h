/*****************************************************************************
 *
 * Copyright (C) 2016-2024 Advanced Micro Devices, Inc. All rights reserved.
 *
 *******************************************************************************
 */

/**
 * @brief Include guard to define Memory Error Messages 
 */
#ifndef _APCB_MEM_ERROR_OUT_CONTROL_H_
#define _APCB_MEM_ERROR_OUT_CONTROL_H_

/**
 * @brief ERROR_ABL_GPIO. This data structure is user-defined GPIO indicator of a failure
 */
typedef struct _ERROR_ABL_GPIO {
  UINT8     Gpio;          ///< FCH GPIO number of failure indicator
  UINT8     GpioIoMUX;     ///< Value write to IOMUX to configure this GPIO pin
  UINT8     GpioBankCtl;   ///< Value write to GPIOBankCtl[23:16] to configure this GPIO pin
} ERROR_ABL_GPIO;

/**
 * @brief BEEP_ERROR_TYPE_MASK. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_MASK       0xF000
/**
 * @brief BEEP_ERROR_OPERATION_MASK. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_OPERATION_MASK  0x0FFF
/**
 * @brief BEEP_ERROR_TYPE_GENERAL. Indicating general Error type. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_GENERAL    0x3000
/**
 * @brief BEEP_ERROR_TYPE_MEMORY. Indicating Error in Memory. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_MEMORY     0x4000
/**
 * @brief BEEP_ERROR_TYPE_DF. Indicating Error in DF. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_DF         0x5000
/**
 * @brief BEEP_ERROR_TYPE_CCX. Indicating Error in CCX. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_CCX        0x6000
/**
 * @brief BEEP_ERROR_TYPE_GNB. Indicating Error in GNB. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_GNB        0x7000
/**
 * @brief BEEP_ERROR_TYPE_PSP. Indicating Error in PSP. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_PSP        0x8000
/**
 * @brief BEEP_ERROR_TYPE_SMU. Indicating Error in SMU. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_SMU        0x9000
/**
 * @brief BEEP_ERROR_TYPE_UNKNOWN. Indicating Unknown Error Type. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TYPE_UNKNOW     0xFFFF
/**
 * @brief BEEP_ERROR_TABLE_SIZE. Indicating Error in Beep Error Table Size. This data structure can be customized/enhanced as per platform need
 */
#define BEEP_ERROR_TABLE_SIZE      8

/**
 * @brief Peak Attributes Data Structure
 */
typedef union {
  /**
  * @brief Each individual Peak Attributes
  */
  struct {
    UINT32  PeakCnt:5;        ///< number of valid bit, zero based
    UINT32  PulseWidths:3;    ///< pulse widths of positive peak, multiple of 0.1s
    UINT32  RepeatCnt:4;      ///< waves repeat count
    UINT32  Reserved :20;     ///< Reserved
  } Bits;
  UINT32  Uint32;             ///< 32 bit Value to access all Individual fields together
} PEAK_ATTR;

/**
 * @brief Memory Overclock error type: RRW_Test
 */
#define ABL_MEM_OVERCLOCK_ERROR_RRW_TEST       0x4024
/**
 * @brief Memory Overclock error type: PMU_Training
 */
#define ABL_MEM_OVERCLOCK_ERROR_PMU_TRAINING   0x4025
/**
 * @brief Memory Overclock error type: Memory Initialization
 */
#define ABL_MEM_OVERCLOCK_ERROR_MEM_INIT       0x4026
/**
 * @brief Memory Overclock error type: Other Not indicating RRW, PMU Training or MemoryInit
 */
#define ABL_MEM_OVERCLOCK_ERROR_MEM_OTHER      0x4027

/**
 * @brief Error Beep Code Table Structure
 */
typedef struct _ERROR_BEEP_CODE_TABLE {
  UINT16    ErrorType;     ///< Error type is specified for the beep codes
  UINT16    PeakMap;       ///< Peak bitmap value to indicated the error
  PEAK_ATTR PeakAttr;      ///< Attribute structure for PeakMap
} ERROR_BEEP_CODE_TABLE;

/**
 * @brief This data structure is used to control sending AGESA PSP Error Event info to the specified port
 */
typedef struct _PSP_ERROR_OUT_CONTROL_STRUCT {
  IN
  BOOLEAN ErrorLogPortReportingEnable;         /**< Indicates if ABL will report errors via a port
                                                * TRUE - Error logging will be reported via a port
                                                * FALSE - Error logging will not be reported via a port
                                                */
  IN
  BOOLEAN ErrorReportErrorGpioEnable;          /**< Indicates if ABL will report errors via GPIO
                                                * TRUE - Error logging will be reported via a GPIO
                                                * FALSE - Error logging will not be reported via a GPIO
                                                * (only valid if ErrorLogPortReportingEnable = TRUE)
                                                */
  IN
  BOOLEAN ErrorReportErrorBeepCodeEnable;      /**< This flag indicates if the ABL will report error via beep codes
                                                * TRUE - Error logging will be reported via FCH speaker
                                                * FALSE - Error logging will not be reported via FCH speaker
                                                * (only valid if ErrorLogPortReportingEnable = TRUE)
                                                */
  IN
  BOOLEAN ErrorLogReportUsingHandshakeEnable;  /**< This flag indicates if the ABL will use an handshake for the Error Log
                                                * TRUE - Error log reported using a handshake with the "ErrorLogOutputPort" and "ErrorLogInputPort"
                                                * FALSE - Error log reported using "ErrorLogOutputPort" only with each DWORD in log delayed by
                                                * ErrorLogOutputDwordDelay
                                                */
  IN
  UINT32  ErrorLogInputPort;                   /**< Input Port to receive ABL Error information
                                                *  (only valid if ReportErrorLogUsingHandshakeEnable = TRUE)
                                                */
  IN
  UINT32  ErrorLogOutputDwordDelay;            /**< Number of "10ns" to wait before sending the next Log Dword informaiton via "ErrorLogOutputPort"
                                                * (only valid if ReportErrorLogUsingHandshakeEnable = FALSE)
                                                */
  IN
  UINT32  ErrorLogOutputPort;                  ///< Output Port for ABL Error information
  IN
  BOOLEAN  ErrorStopOnFirstFatalErrorEnable;   /**< Indicates that ABL will stop on the first fatal error
                                                * TRUE - Stop and report the first FATAL error
                                                * FALSE - Report all errors
                                                */
  IN
  UINT32  ErrorLogReportInputPortSize;          /**< Indicates the sie of the input and outut port
                                                 * 1 - 8 bit port
                                                 * 2 - 16 bit port
                                                 * 4 - 32 bit port
                                                 */
  IN
  UINT32  ErrorLogReportOutputPortSize;         /**< Indicates the sie of the input and outut port
                                                 * 1 - 8 bit port
                                                 * 2 - 16 bit port
                                                 * 4 - 32 bit port
                                                 */
  IN
  UINT32  ErrorLogReportInputPortType;          /**< Indicates the type of Input Port or location of the port
                                                 * 0 - PCIE HT0
                                                 * 2 - PCIE HT1
                                                 * 5 - PCIE MMIO
                                                 * 6 - FCH_HT_IO (Default)
                                                 * 7 - FCH_MMIO
                                                 */
  IN
  UINT32  ErrorLogReportOutputPortType;          /**< Indicates the type of Output Port or location of the port
                                                  * 0 - PCIE HT0
                                                  * 2 - PCIE HT1
                                                  * 5 - PCIE MMIO
                                                  * 6 - FCH_HT_IO (Default)
                                                  * 7 - FCH_MMIO
                                                  */
  IN
  BOOLEAN  ErrorLogReportClearAcknowledgement;   /**< Indicates if the ABL will clear acknolgements during protocol
                                                  * TRUE - Clear acknowledgemetns
                                                  * FALSE - Do not clear acknologements
                                                  */

  _4BYTE_ALIGN  ERROR_ABL_GPIO   ErrorLogReportGpioReport;     /**< Structure for the GPIO definition
                                                                * (only valid if ErrorReportErrorGpioEnable = TRUE)
                                                                */

  ERROR_BEEP_CODE_TABLE  BeepCodeTable[BEEP_ERROR_TABLE_SIZE]; /**< Structure for definition of beep codes
                                                                * (only valid if ErrorReportErrorBeepCodeEnable = TRUE)
                                                                */
  IN
  BOOLEAN ErrorLogHeartBeatEnable;             /**< Indicates if ABL will provide periodic status to a port as a heart beat
                                                * TRUE - Heartbeat Error log will be reported via a port
                                                * FALSE - Heartbeat Error log will not be reported via a port
                                                * Notes:
                                                *   1) This feature is only valid if ErrorLogPortReportingEnable
                                                *   2) This is can be mono-directional or bi-directional based on "ErrorLogReportUsingHandshakeEnable"
                                                *        "ErrorLogReportUsingHandshakeEnable" = TRUE - bi-directional
                                                *        "ErrorLogReportUsingHandshakeEnable" = FALSE - mono-directional
                                                *   3) Requires the following to be defined:
                                                *    - "ErrorLogReportInputPortType", "ErrorLogInputPort, "ErrorLogReportInputPortSize"
                                                *    - "ErrorLogReportInputPortType", "ErrorLogInputPort, "ErrorLogReportInputPortSize"
                                                */
  IN
  BOOLEAN ErrorLogPowerGoodGpioEnable;         /**< Indicates if ABL will report power good status via GPIO
                                                * TRUE - ABL will report power good status via a GPIO
                                                * FALSE - ABL will not report power good status via a GPIO
                                                * (only valid if ErrorLogPortReportingEnable = TRUE)
                                                */

  ERROR_ABL_GPIO   ErrorLogPowerGoodGpio;      /**< Structure for Power Good GPIO definition
                                                * (only valid if ErrorLogPowerGoodGpioEnable = TRUE)
                                                */
} PSP_ERROR_OUT_CONTROL_STRUCT;


#endif // _APCB_MEM_ERROR_OUT_CONTROL_H_


