@ECHO OFF
REM -------------------------------------------------------------------
REM BOARD NAME is set by caller
REM -------------------------------------------------------------------
ECHO *********************************
ECHO BOARD NAME : %BOARD_NAME%
ECHO *********************************
REM SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\<FileToBeModified>

SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x1704_Type_DimmInfoSpd

REM This token boolean file should be synced with GenoaCommon with additional compliance board token added
SET APCB_DATA_TYPE_FILE_LIST=%APCB_DATA_TYPE_FILE_LIST% %BOARD_NAME%\ApcbData_Genoa_GID_0x3000_Type_TokenBoolean


:END
EXIT /B 0
