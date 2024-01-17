@ECHO OFF
REM -------------------------------------------------------------------
REM Set execution environment base line
SETLOCAL
SETLOCAL EnableDelayedExpansion
IF ERRORLEVEL 1 ECHO Failed to turn on EnableDelayedExpansion! Build system might not work properly!&&PAUSE
VERIFY ON
REM -------------------------------------------------------------------

REM ============================================================================
REM ============================================================================
REM ============================================================================
REM Start of customization section
REM ============================================================================
REM ============================================================================
REM ============================================================================
SET APCB_VER=V3
SET APCB_BUILD_MODE_C_FLAGS=/D APCB_EXTERNAL_BUILD=1
SET APCB_BIN_LIST_CUSTOM=ApcbDataDefaultRecovery ApcbDataUpdatable ApcbDataEventLog
REM Multiple Board support building flag. Default disable for external build.
REM NOTE: The APCB_MULTI_BOARD_SUPPORT setup is moved to SetApcbBoardList.bat
REM SET APCB_MULTI_BOARD_SUPPORT=0

REM ============================================================================
REM Customize the APCB output binary and input data files
REM ============================================================================

REM ----------------------------------------------------------------------------
REM First thing, setup ApcbTool!APCB_VER!.exe
REM ----------------------------------------------------------------------------
IF NOT DEFINED TOOL_DIR SET TOOL_DIR=%CD%\..\..\..\..\AgesaModulePkg\AMDTools\ApcbTool!APCB_VER!\Tools

REM ----------------------------------------------------------------------------
REM Building flow control. Do not remove. Continue to cutomize build files below
GOTO START_MAIN_FLOW
REM ----------------------------------------------------------------------------
REM ============================================================================
REM ============================================================================
REM Customize the APCB data files and output binary
REM ============================================================================
REM ============================================================================
:CUSTOMIZE_DATA_BIN
SET APCB_DATA_BIN_IN_BUILD=%1
REM ============================================================================
REM Customize the APCB read-only binary for default and recovery binary
REM ============================================================================
IF NOT "%APCB_DATA_BIN_IN_BUILD%" == "ApcbDataDefaultRecovery" GOTO END_ApcbDataDefaultRecovery
ECHO APCB Data File setup for ApcbDataDefaultRecovery binary
REM ----------------------------------------------------------------------------
REM Target APCB binary will be put in RELEASE_DIR
REM ----------------------------------------------------------------------------
SET APCB_BIN_FILE_BASE_NAME=APCB_GENOA_D4_DefaultRecovery
SET APCB_BIN_FILE_CLONE_BASE_NAME=APCB_GENOA_D4

REM ----------------------------------------------------------------------------
REM Reset variable then start adding APCB data source C files (base name only)
REM ----------------------------------------------------------------------------
SET APCB_DATA_PREPROCESS_OUTPUT=1
REM APCB V3 three binaries model
SET APCB_DATA_DIR=ApcbDataDefaultRecovery
SET APCB_DATA_TYPE_FILE_LIST=

REM ----------------------------------------
REM Set board list
REM ----------------------------------------
SET APCB_BOARD_LIST_SETUP_BAT=SetApcbBoardList.bat
IF NOT EXIST %APCB_DATA_BIN_IN_BUILD%\%APCB_BOARD_LIST_SETUP_BAT% ECHO.&&ECHO WARNING: Missing %APCB_DATA_FILE_LIST_SETUP_BAT% for %APCB_DATA_BIN_IN_BUILD% for binary specific board list setup.
IF EXIST %APCB_DATA_BIN_IN_BUILD%\%APCB_BOARD_LIST_SETUP_BAT% ECHO Calling %APCB_DATA_BIN_IN_BUILD%\%APCB_BOARD_LIST_SETUP_BAT% binary specific board list setup.
IF EXIST %APCB_DATA_BIN_IN_BUILD%\%APCB_BOARD_LIST_SETUP_BAT% CALL %APCB_DATA_BIN_IN_BUILD%\%APCB_BOARD_LIST_SETUP_BAT% %APCB_DATA_BIN_IN_BUILD% || ECHO ERROR&&EXIT /B 1

REM ----------------------------------------
REM Set data file list for each board
REM ----------------------------------------
SET APCB_DATA_FILE_LIST_SETUP_BAT=SetApcbDataFileList.bat
FOR %%F IN (!APCB_DATA_BOARD_DIR_LIST!) DO (
  IF NOT EXIST %APCB_DATA_BIN_IN_BUILD%\%%F\%APCB_DATA_FILE_LIST_SETUP_BAT% ECHO.&&ECHO WARNING: Missing %APCB_DATA_FILE_LIST_SETUP_BAT% for board %APCB_DATA_BIN_IN_BUILD%\%%F for board specific data file list setup.
  IF EXIST %APCB_DATA_BIN_IN_BUILD%\%%F\%APCB_DATA_FILE_LIST_SETUP_BAT% ECHO Calling %APCB_DATA_BIN_IN_BUILD%\%%F board specific data file list setup.
  SET BOARD_NAME=%%F
  IF EXIST %APCB_DATA_BIN_IN_BUILD%\%%F\%APCB_DATA_FILE_LIST_SETUP_BAT% CALL %APCB_DATA_BIN_IN_BUILD%\%%F\%APCB_DATA_FILE_LIST_SETUP_BAT%
  REM SET APCB_DATA_TYPE_FILE_LIST
  SET BOARD_NAME=
)

EXIT /B 0
:END_ApcbDataDefaultRecovery
REM ============================================================================
REM Customize the APCB binary for boot time and runtime update binary
REM ============================================================================
IF NOT "%APCB_DATA_BIN_IN_BUILD%" == "ApcbDataUpdatable" GOTO END_ApcbDataUpdatable
IF NOT "!APCB_VER!" == "V3" GOTO SKIP_V3_UPDATABLE_TOKEN_FILES
ECHO APCB Data File setup for ApcbDataUpdatable binary
REM ----------------------------------------------------------------------------
REM Target APCB binary will be put in RELEASE_DIR
REM ----------------------------------------------------------------------------
SET APCB_BIN_FILE_BASE_NAME=APCB_GENOA_D4_Updatable
SET APCB_DATA_PREPROCESS_OUTPUT=1
SET APCB_DATA_DIR=ApcbDataUpdatable
SET BOARD_NAME=.
SET APCB_DATA_TYPE_FILE_LIST=
REM APCB V3 Tokens
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_TokenBoolean
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_Token1Byte
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_Token2Bytes
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_Token4Bytes
REM Debug Instance
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_TokenBooleanDebug
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_Token1ByteDebug
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_Token2BytesDebug
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_Token4BytesDebug
REM CXL_CONFIG
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x1703_Type_CxlConfig
:SKIP_V3_UPDATABLE_TOKEN_FILES
EXIT /B 0
:END_ApcbDataUpdatable
REM ============================================================================
REM Customize the APCB binary for event log binary
REM ============================================================================
IF NOT "%APCB_DATA_BIN_IN_BUILD%" == "ApcbDataEventLog" GOTO END_ApcbDataEventLog
IF NOT "!APCB_VER!" == "V3" GOTO SKIP_V3_EVENTLOG_TOKEN_FILES
ECHO APCB Data File setup for ApcbDataUpdatable binary
REM ----------------------------------------------------------------------------
REM Target APCB binary will be put in RELEASE_DIR
REM ----------------------------------------------------------------------------
SET APCB_BIN_FILE_BASE_NAME=APCB_GENOA_D4_EventLog
SET APCB_DATA_PREPROCESS_OUTPUT=1
SET APCB_DATA_DIR=ApcbDataEventLog
SET BOARD_NAME=.
SET APCB_DATA_TYPE_FILE_LIST=
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x1704_Type_DdrPostPackageRepair
:SKIP_V3_EVENTLOG_TOKEN_FILES
EXIT /B 0
:END_ApcbDataEventLog
:CUSTOMIZE_DATA_BIN_END
EXIT /B 0
REM Should never come here!
GOTO :EOF

REM ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
REM End of customization section
REM ============================================================================
REM ============================================================================
REM ============================================================================


REM ============================================================================
REM Environment Checks
REM ============================================================================
:ENV_CHECK
  SET APCB_TOOL_NAME=ApcbTool!APCB_VER!.exe
  IF NOT DEFINED TOOL_DIR ECHO
  IF NOT EXIST %TOOL_DIR%\%APCB_TOOL_NAME%  GOTO ERROR_TOOLDIR&& EXIT /B 10
  IF EXIST %TOOL_DIR%\%APCB_TOOL_NAME%  ECHO Found %APCB_TOOL_NAME% at "%TOOL_DIR%".
  GOTO :EOF

REM ============================================================================
REM ============================================================================
REM ============================================================================
REM Start of main flow
REM ============================================================================
REM ============================================================================
REM ============================================================================
:START_MAIN_FLOW
CALL :DISP_HEADER
REM cls
CALL :ENV_CHECK
CALL :GET_WORK_DIR
CALL :GET_SYS_TIME
IF /I "%1" == "--HELP" CALL :DISP_HELP && GOTO END
IF /I "%1" == "-H"     CALL :DISP_HELP && GOTO END
IF /I "%1" == ""       CALL :DISP_HELP && GOTO END

SET BUILD_DIR=Build
SET RELEASE_DIR=Release
SET LOG_DIR=Log

:PARSE_PARAM
IF /I "%1" == "CLEAN"  CALL :CLEAN_OUTPUT
REM Force to use parameter to continue the build
IF /I "%1" == "BUILD"  GOTO START_BUILDING
IF /I "%1" == ""       GOTO END
REM Parse the next parameter
SHIFT
GOTO PARSE_PARAM
GOTO END

REM ============================================================================
REM Start building if input proper parameter
REM ============================================================================
:START_BUILDING
IF NOT DEFINED APCB_BIN_LIST_CUSTOM SET APCB_BIN_LIST=ApcbDataDefaultRecovery ApcbDataUpdatable ApcbDataEventLog
IF DEFINED APCB_BIN_LIST_CUSTOM SET APCB_BIN_LIST=!APCB_BIN_LIST_CUSTOM!

SET APCB_SIG_FILE_BUILT=FALSE
SET APCB_DATA_TYPE_SIG_FILE_REL_PATH=..\Common
SET APCB_DATA_TYPE_SIG_START_FILE=ApcbDataSigStart
SET APCB_DATA_TYPE_SIG_END_FILE=ApcbDataSigEnd
IF "!APCB_BIN_LIST!" == "" ECHO ERROR: NO BINARY IS REQUESTED TO BUILD!
FOR %%B IN (!APCB_BIN_LIST!) DO (
  SET APCB_BIN_FILE_BASE_NAME=
  SET APCB_BIN_FILE_CLONE_BASE_NAME=
  SET APCB_DATA_TYPE_FILE_LIST=
  IF DEFINED APCB_DATA_BOARD_DIR_LIST ECHO INFO: Environment variable customization of APCB_DATA_BOARD_DIR_LIST=%APCB_DATA_BOARD_DIR_LIST%
  SET BUILD_DIR=Build\%%B
  CALL :CUSTOMIZE_DATA_BIN %%B || EXIT /B 1
  SET APCB_DATA_TYPE_FILE_LIST
  CALL :COMMON_BUILD_FLOW %%B || EXIT /B 1
)
GOTO END
REM ============================================================================
REM ============================================================================
REM ============================================================================
REM End of main flow
REM ============================================================================
REM ============================================================================
REM ============================================================================
REM ============================================================================
REM ============================================================================
REM Start of common build flow
REM ============================================================================
REM ============================================================================
:COMMON_BUILD_FLOW

REM ============================================================================
@ECHO.
@ECHO Building APCB data ...
REM ============================================================================
CALL :SETUP_OUTPUT_DIR
IF "!APCB_DATA_BOARD_DIR_LIST!" == "" SET APCB_DATA_BOARD_DIR_LIST=.
REM FOR %%D IN (!APCB_DATA_BOARD_DIR_LIST!) DO (
  SET BUILD_SUB_DIR=%%D
  CALL :BUILD_SIG_C_SOURCES || ECHO BUILD C ERROR && PAUSE && GOTO ERR_END
  CALL :BUILD_ALL_C_SOURCES || ECHO BUILD C ERROR && PAUSE && GOTO ERR_END
REM )

REM ============================================================================
@ECHO.
@ECHO Prepare APCB data for building ...
REM ============================================================================

REM ============================================================================
REM Prepare parameter for data files from APCB_DATA_TYPE_FILE_LIST
REM ============================================================================
CALL :PREPARE_DATA_FILE_LIST_IN_TOOL_PARAM_FORM

REM ============================================================================
@ECHO.
@ECHO APCB binary generation ...
REM ============================================================================
SET APCB_BIN_FILE=%APCB_LOCAL_WORK_DIR%\%RELEASE_DIR%\%APCB_BIN_FILE_BASE_NAME%.bin
IF DEFINED APCB_BIN_FILE_CLONE_BASE_NAME SET APCB_CLONE_BIN_FILE=%APCB_LOCAL_WORK_DIR%\%RELEASE_DIR%\%APCB_BIN_FILE_CLONE_BASE_NAME%.bin
REM File extension .txt will be added
SET APCB_EXE_LOG=ApcbBuild_ExeLog_%1
CALL :RUN_APCB_TOOL_WITH_EXE_LOG || GOTO ERR_END
IF DEFINED APCB_BIN_FILE_CLONE_BASE_NAME COPY /Y %APCB_BIN_FILE% %APCB_CLONE_BIN_FILE%
IF DEFINED APCB_BIN_FILE_CLONE_BASE_NAME SET APCB_CLONE_BIN_FILE=
EXIT /B 0
REM ============================================================================
REM ============================================================================
REM ============================================================================
REM End of common build flow
REM ============================================================================
REM ============================================================================
REM ============================================================================






REM ============================================================================
REM Local functions
REM ============================================================================

REM ----------------------------------------------------------------------------
REM Display header
REM ----------------------------------------------------------------------------
:DISP_HEADER
  SET BAT_TOOL_NAME=%~n0
  @ECHO.
  @ECHO **************************
  @ECHO  Start %BAT_TOOL_NAME%
  @ECHO **************************
  @ECHO.
  GOTO :EOF


REM ----------------------------------------------------------------------------
REM Display help info
REM ----------------------------------------------------------------------------
:DISP_HELP
  @ECHO.
  @ECHO %~n0 help info
  @ECHO.
  @ECHO USAGE:
  @ECHO       For clean up output directories (Release, Build and Log directoies)
  @ECHO   %~n0  CLEAN
  @ECHO.
  @ECHO       For build APCB data and tool
  @ECHO   %~n0  BUILD
  @ECHO.
  @ECHO       You may combine both
  @ECHO   %~n0  CLEAN BUILD
  @ECHO.
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM This is a "function" to do common Error tasks
REM ----------------------------------------------------------------------------
:GOT_ERROR
  ECHO:**** BUILD FAILED ****
  EXIT /B 1

REM ----------------------------------------------------------------------------
REM Get current working director and set variable APCB_LOCAL_WORK_DIR for later use
REM ----------------------------------------------------------------------------
:GET_WORK_DIR
  SET APCB_LOCAL_WORK_DIR=%CD%
  IF DEFINED APCB_WORK_DIR SET APCB_LOCAL_WORK_DIR=%APCB_WORK_DIR%

REM ----------------------------------------------------------------------------
REM Setup output folder
REM ----------------------------------------------------------------------------
:SETUP_OUTPUT_DIR
  REM --------------------------------------------------------------------
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%BUILD_DIR% md %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%
  FOR %%D IN (%APCB_DATA_BOARD_DIR_LIST%) DO (
    IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%D md %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%D
  )

  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR% md %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR%
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%LOG_DIR% md %APCB_LOCAL_WORK_DIR%\%LOG_DIR%
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM Clean up output folder
REM ----------------------------------------------------------------------------
:CLEAN_OUTPUT
    for %%O IN (%APCB_LOCAL_WORK_DIR%\%BUILD_DIR% %APCB_LOCAL_WORK_DIR%\%LOG_DIR% %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR%) DO (
        IF EXIST  %%O ECHO Deleting directory "%%O"...
        IF EXIST  %%O rd /s /q %%O
    )
    GOTO :EOF

REM ----------------------------------------------------------------------------
REM Prepare data file list in tool parameter form
REM ----------------------------------------------------------------------------
:PREPARE_DATA_FILE_LIST_IN_TOOL_PARAM_FORM
  SET APCB_DATA_TYPE_FILE_LIST_TOOL_PARAM=
  for %%D IN ( %APCB_DATA_TYPE_FILE_LIST%) DO (
    CALL :APPEND_DATA_FILE_LIST_IN_TOOL_PARAM_FORM %%D
  )
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM Append data file list in tool parameter form
REM ----------------------------------------------------------------------------
:APPEND_DATA_FILE_LIST_IN_TOOL_PARAM_FORM
  REM Specify the build data file extension
  SET APCB_DATA_OUTPUT_FILE_EXT=exe
  SET APCB_DATA_TYPE_FILE_LIST_TOOL_PARAM=%APCB_DATA_TYPE_FILE_LIST_TOOL_PARAM% -I %1.%APCB_DATA_OUTPUT_FILE_EXT%
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM Get system time
REM
REM OUTPUT: Environment varibles SysTime, SysTimeHour, SysTimeMin and SysDate
REM ----------------------------------------------------------------------------
: GET_SYS_TIME
  REM Get the system date and time
  FOR /F "tokens=1-4 delims=/ " %%a IN ("%date%") DO (
    SET SysDate=%%a%%b%%c
  )
  FOR /F "tokens=1-4 delims=:. " %%a IN ("%time%") DO (
    SET SysTimeHour=%%a
    SET SysTimeMin=%%b%%c
  )
  set SysTime=%SysTimeHour%%SysTimeMin%
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM Build all C source files in APCB_DATA_TYPE_FILE_LIST
REM ----------------------------------------------------------------------------
:BUILD_ALL_C_SOURCES
  SET C_FLAGS=/nologo %APCB_PLAT_C_FLAGS% %APCB_BUILD_MODE_C_FLAGS%
  SET C_INCLUDE_PATH_FLAG=/I Include /I ..\Inc\Genoa /I ..\Inc\Common

  ECHO Compile C_FLAG=%C_FLAGS%
  ECHO Compile C_INCLUDE_PATH_FLAG=%C_INCLUDE_PATH_FLAG%
  REM --------------------------------------------------------------------
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%BUILD_DIR% md %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR% md %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR%
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%LOG_DIR% md %APCB_LOCAL_WORK_DIR%\%LOG_DIR%
  REM --------------------------------------------------------------------
  REM Build APCB data files
  REM --------------------------------------------------------------------
  FOR %%F IN (%APCB_DATA_TYPE_FILE_LIST%) DO (
    IF NOT EXIST %APCB_DATA_DIR%\%%F.c ECHO.&&ECHO WARNING: Cannot open file "%APCB_DATA_DIR%\%%F.c"! && EXIT /B 1
    @ECHO File: %APCB_DATA_DIR%\%%F.c
    IF %APCB_DATA_PREPROCESS_OUTPUT% == 1 (
      @ECHO Preprocessing ...
      cl %C_FLAGS% %APCB_DATA_DIR%\%%F.c %C_INCLUDE_PATH_FLAG% /EP > %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%F.cod /D BUILD_APCB_DATA=1
    )
    @ECHO Compiling ...
    cl %C_FLAGS% %APCB_DATA_DIR%\%%F.c /c  %C_INCLUDE_PATH_FLAG% /Fo%APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%F.obj /D BUILD_APCB_DATA=1
    link /nologo %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%APCB_DATA_TYPE_SIG_START_FILE%.obj  %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%F.obj %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%APCB_DATA_TYPE_SIG_END_FILE%.obj /OUT:%APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%F.exe /MAP:%APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%%F.map
    IF ERRORLEVEL 1 EXIT /B 1
    @ECHO.
  )
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM Build signature C source files in APCB_DATA_TYPE_SIG_START_FILE and APCB_DATA_TYPE_SIG_END_FILE
REM ----------------------------------------------------------------------------
:BUILD_SIG_C_SOURCES
  SET C_FLAGS=/nologo %APCB_PLAT_C_FLAGS% %APCB_BUILD_MODE_C_FLAGS%
  SET C_INCLUDE_PATH_FLAG=/I Include /I ..\Inc\Genoa /I ..\Inc\Common
  SET APCB_DATA_TYPE_SIG_FILE_LIST=%APCB_DATA_TYPE_SIG_START_FILE% %APCB_DATA_TYPE_SIG_END_FILE%
  SET APCB_SIG_FILE_BUILT
  IF "%APCB_SIG_FILE_BUILT%" == "TRUE" GOTO :EOF

  ECHO Compile C_FLAG=%C_FLAGS%
  ECHO Compile C_INCLUDE_PATH_FLAG=%C_INCLUDE_PATH_FLAG%
  REM --------------------------------------------------------------------
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%BUILD_DIR% md %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH% md %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR% md %APCB_LOCAL_WORK_DIR%\%RELEASE_DIR%
  IF NOT EXIST %APCB_LOCAL_WORK_DIR%\%LOG_DIR% md %APCB_LOCAL_WORK_DIR%\%LOG_DIR%
  REM --------------------------------------------------------------------
  REM Build APCB signature files
  REM --------------------------------------------------------------------
  FOR %%F IN (%APCB_DATA_TYPE_SIG_FILE_LIST%) DO (
    IF NOT EXIST %APCB_DATA_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.c ECHO.&&ECHO WARNING: Cannot open file "%APCB_DATA_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.c"! && EXIT /B 1
    @ECHO File: %APCB_DATA_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.c
    IF %APCB_DATA_PREPROCESS_OUTPUT% == 1 (
      @ECHO Preprocessing ...
      cl %C_FLAGS% %APCB_DATA_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.c %C_INCLUDE_PATH_FLAG% /EP > %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.cod /D BUILD_APCB_SIG=1
    )
    @ECHO Compiling ...
    cl %C_FLAGS% %APCB_DATA_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.c /c %C_INCLUDE_PATH_FLAG% /Fo%APCB_LOCAL_WORK_DIR%\%BUILD_DIR%\%APCB_DATA_TYPE_SIG_FILE_REL_PATH%\%%F.obj /D BUILD_APCB_SIG=1
    IF ERRORLEVEL 1 EXIT /B 1
    @ECHO.
  )
  SET APCB_SIG_FILE_BUILT=TRUE
  GOTO :EOF


REM ----------------------------------------------------------------------------
REM Run APCB Tool and generate log
REM
REM INPUT:
REM        BUILD_DIR
REM        APCB_BIN_FILE
REM        APCB_DATA_TYPE_FILE_LIST_TOOL_PARAM
REM        APCB_EXE_LOG
REM OUTPUT:
REM        APCB_BIN_FILE - APCB binary file specified
REM        APCB_EXE_LOG  - Execution log specified (create a new file)
REM ----------------------------------------------------------------------------
:RUN_APCB_TOOL_WITH_EXE_LOG
  SET APCB_EXE_LOG_INPUT=%APCB_EXE_LOG%
  REM --------------------------------------------------------------------
    SET APCB_EXE_LOG=%APCB_LOCAL_WORK_DIR%\%LOG_DIR%\%APCB_EXE_LOG_INPUT%.txt
    @ECHO Run APCB tool with log ...      (Log:%APCB_EXE_LOG%)
    PUSHD %APCB_LOCAL_WORK_DIR%\%BUILD_DIR%
    CALL :APCB_TOOL || EXIT /B 1
  POPD
  REM --------------------------------------------------------------------
  REM Restor variable
  SET APCB_EXE_LOG=%APCB_EXE_LOG_INPUT%
  SET APCB_EXE_LOG_INPUT=
  GOTO :EOF

REM ----------------------------------------------------------------------------
REM Run APCB Generator tool !APCB_VER! by ApcbTool!APCB_VER!
REM
REM INPUT:
REM        BUILD_DIR
REM        APCB_BIN_FILE
REM        APCB_DATA_TYPE_FILE_LIST_TOOL_PARAM
REM        APCB_EXE_LOG
REM OUTPUT:
REM        APCB_BIN_FILE - APCB binary file specified
REM        APCB_EXE_LOG  - Execution log specified (create a new file)
REM ----------------------------------------------------------------------------
:APCB_TOOL
  %TOOL_DIR%\%APCB_TOOL_NAME% --outputfile %APCB_BIN_FILE% %APCB_DATA_TYPE_FILE_LIST_TOOL_PARAM% > %APCB_EXE_LOG% || EXIT /B 1
  GOTO :EOF


REM ============================================================================
:ERROR_TOOLDIR
  ECHO.
  ECHO.
  ECHO ***********************************************************************
  ECHO  ERROR : %APCB_TOOL_NAME% cannot be found at "%TOOL_DIR%" (TOOL_DIR)
    SET TOOL_DIR
  ECHO.
  ECHO  Environment variable TOOL_DIR should be set properly.
  ECHO  %APCB_TOOL_NAME% should be found under folder of "AgesaModulePkg\AMDTools\ApcbTool!APCB_VER!\Tools".
  ECHO ***********************************************************************
  ECHO.
  ECHO.
  PAUSE
  GOTO :EOF

REM ============================================================================
:ERR_END
  @ECHO.
  @ECHO **************************
  @ECHO  Exit with error!
  @ECHO **************************
  EXIT /B 1

:END
  @ECHO.
  @ECHO **************************
  @ECHO  %BAT_TOOL_NAME% completed!
  @ECHO **************************
  @ECHO.
  EXIT /B 0
