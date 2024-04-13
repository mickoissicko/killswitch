@ECHO OFF

REM Thanks stackoverflow
REM Funny how you have to write all of this just for elevated privileges
REM And on POSIX you can just use 'sudo'
REM ...lol

SET "params=%*"
CD /D "%~dp0" && ( IF EXIST "%temp%\getadmin.vbs" DEL "%temp%\getadmin.vbs" ) && FSUTIL dirty QUERY %systemdrive% 1 > NUL 2 > NUL || (  ECHO Set UAC = CreateObject^("Shell.Application"^) : UAC.ShellExecute "cmd.exe", "/k cd ""%~sdp0"" && ""%~s0"" %params%", "", "runas", 1 >> "%temp%\getadmin.vbs" && "%temp%\getadmin.vbs" && EXIT /B )

python server.py

