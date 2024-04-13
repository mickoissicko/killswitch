@ECHO OFF

choco > NUL 2 >& 1

IF %errorlevel% NEQ 0
(
    @"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
)

choco > NUL 2 >& 1

IF %errorlevel% NEQ 0
(
    EXIT 1
)

choco install tartool -y

