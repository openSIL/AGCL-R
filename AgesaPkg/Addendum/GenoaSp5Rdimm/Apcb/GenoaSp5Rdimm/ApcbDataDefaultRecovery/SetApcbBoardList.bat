@ECHO OFF
REM -------------------------------------------------------------------
REM APCB_DATA_BIN_IN_BUILD is set by caller
REM -------------------------------------------------------------------
ECHO *********************************
ECHO APCB BIN: %APCB_DATA_BIN_IN_BUILD%
ECHO *********************************
REM Multiple Board support building flag. Default disable for external build.
IF NOT DEFINED APCB_MULTI_BOARD_SUPPORT SET APCB_MULTI_BOARD_SUPPORT=0

IF NOT DEFINED APCB_DATA_BOARD_DIR_LIST SET APCB_DATA_BOARD_DIR_LIST=GenoaCommon
REM IF NOT DEFINED APCB_DATA_BOARD_DIR_LIST SET APCB_DATA_BOARD_DIR_LIST=GenoaCommon  Onyx
REM IF NOT DEFINED APCB_DATA_BOARD_DIR_LIST SET APCB_DATA_BOARD_DIR_LIST=GenoaCommon  CustomBoard_YourBoardName

:END
EXIT /B 0
