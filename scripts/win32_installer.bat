@echo off

REM I miss bash...
REM It's so elegant, and cute
REM And batch... not-so-cute-or-elegant
REM :(
REM Batch is like... the APL of shell scripting languages
REM Yk what I mean?
REM Oh and I didn't code this
REM Thanks green-coloured chat-bot
REM I'll test this on windows later
REM Just have a base right now..
REM Also, I hate no quotes after echo statement
REM Like wtf is 'echo hello world,' blechh

where python > nul 2 > nul

if %ERRORLEVEL% equ 0
(
    echo Python is already installed.
    exit /b 0
)

REM This probably won't work
REM Pray to god

set "PYTHON_VERSION=3.9.11"
set "INSTALL_DIR=C:\Python39"

echo Downloading Python %PYTHON_VERSION%...
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://www.python.org/ftp/python/%PYTHON_VERSION%/python-%PYTHON_VERSION%-amd64.exe', 'python_installer.exe')"

echo Installing Python %PYTHON_VERSION%...
python_installer.exe /quiet InstallAllUsers=1 PrependPath=1 Include_test=0

del python_installer.exe

where python > nul 2 > nul
if %ERRORLEVEL% equ 0
(
    echo Python installed successfully.
    exit /b 0
)

else
(
    echo Failed to install Python.
    exit /b 1
)

