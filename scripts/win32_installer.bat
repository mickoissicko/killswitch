@ECHO OFF

REM Batch sucks
REM It's dumb

python --version > NUL 2 >& 1

IF %errorlevel% EQU 0
(
    EXIT
)

SETLOCAL
SET "python_url=https://www.python.org/downloads/release/python-3118/"

POWERSHELL -Command "(New-Object System.Net.WebClient).DownloadFile('%python_url%', 'python_installer.exe')"

python_installer.exe /quiet InstallAllUsers=1 PrependPath=1 Include_launcher=0
python -m ensurepip

