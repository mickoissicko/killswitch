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

    int Status = system("wget https://github.com/mickoissicko/killswitch/raw/main/packages/posix_tar.sh");

    if (Status != 0)
        DispErrMsg();

    system("wget https://github.com/mickoissicko/killswitch/raw/main/packages/win32_tar.bat");

    #ifdef _WIN32
        system("win32_tar.bat");
    #else
        system("chmod +x posix_tar.sh");
        system("./posix_tar.sh");
    #endif

    snprintf(DownloadCommand, Buf, "wget %s", DEPS);

    Status = system(DownloadCommand);

    if (Status != 0)
        DispErrMsg();

    system("wget https://github.com/mickoissicko/killswitch/raw/main/packages/handler.tar.gz");

    printf("Extracting...\n");

    Status = system("tar -xzf server.tar.gz");

    if (Status != 0)
        DispErrMsg();

    system("tar -xzf handler.tar.gz");

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

    Status = system("tar -xzf scripts.tar.gz");

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

    printf("Installation completed\n");
    printf("No reported errors\n");

    char Ui[1];
    while (
        !!strcasecmp(Ui, "y") &&
        !!strcasecmp(Ui, "n")
    ){
        printf("Start the program? [y/n]: ");
        scanf("%s", Ui);
    }

    if (!strcasecmp(Ui, "y"))
        Menu();

    exit(0);
}

