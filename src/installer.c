#include "common/common.h"
#include "common/consts.h"

#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZ 4096
#define BUF_SIZ 2048
#define MAX_LEN 1024

void Install()
{
    FILE* lock;
    char* Path = (char*)malloc(MAX_SIZ * sizeof(char));

    char* DownloadCommand;
    unsigned long Buf = MAX_SIZ;

    DownloadCommand = (char*)malloc(BUF_SIZ * sizeof(char));

    #ifdef _WIN32
        Path = Win32_Path();
    #else
        Path = Posix_Path();
    #endif

    chdir(Path);

    RemoveFolders();

    printf("Downloading files required...\n");
    printf("If the download fails, please manually install wget\n");

    snprintf(DownloadCommand, Buf, "wget %s", DEPS);

    int Status = system(DownloadCommand);

    if (Status != 0)
        DispErrMsg();

    printf("Extracting...\n");
    printf("If extraction fails, please manually install 'tar'\n");

    Status = system("tar -xzf flask_server.tar.gz");

    if (Status != 0)
        DispErrMsg();

    printf("Processing...\n");

    char* NewDownloadCommand = (char*)malloc(MAX_SIZ * sizeof(char));
    unsigned long NewBuf = MAX_SIZ;

    printf("Note: If Python is already installed, the script will detect it\n");
    printf("Installing Python...\n");
    printf("Fetching scripts...\n");

    snprintf(NewDownloadCommand, NewBuf, "wget %s", PYPK);

    Status = system(NewDownloadCommand);

    if (Status != 0)
        DispErrMsg();

    printf("Extracting...\n");

    Status = system("tar -xzf py_install.tar.gz");

    if (Status != 0)
        DispErrMsg();

    #ifdef _WIN32
        printf("Installing Python...\n");
        system("win32_installer.bat");
    #else
        // No fucking idea why this is giving me a warning
        // mIsLeaDinG iNdEnTAtIo-- go fucking kill yourself
        // Bitch, I was misleading your mother's indentation
        system("chmod +x posix_installer.sh");
        system("./posix_installer.sh");
    #endif

    free(NewDownloadCommand);

    lock = fopen("lock.pa", "w");
    fprintf(lock, "If you delete this file, LOIDR will reinstall itself\n");

    if (lock != NULL)
        fclose(lock);

    else
    {
        printf("Failure (1)");

        free(DownloadCommand);
        free(Path);

        exit(1);
    }

    free(DownloadCommand);
    free(Path);

    exit(0);
}

