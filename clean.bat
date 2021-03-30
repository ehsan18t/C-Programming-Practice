@ECHO OFF
CD /d %~dp0
TITLE Project Cleaner (*.exe, *.bin)
DEL /S /Q *.exe
DEL /S /Q *.bin
PAUSE
