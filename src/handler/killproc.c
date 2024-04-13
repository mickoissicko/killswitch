#include "../common/consts.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_SIZ 8192
#define MAX_PATH_SIZ 8192
#define MAX_SIZ 4096

char* Posix_Path();
char* Win32_Path();

int main()
{
    char* Path = (char*)malloc(MAX_SIZ * sizeof(char));

    // I know I just broke code consistency
    // Because the whole codebase uses ifdef
    // But I'm in a rut
    // Let's switch things up

    #ifndef _WIN32
        Path = Posix_Path();
    #else
        Path = Win32_Path();
    #endif

    chdir(Path);
    // If it doesn't exist
    // The program will crash
    // And I'm not gonna do shit about it
    chdir(LOIDR);

    FILE* ProcFile;
    ProcFile = fopen("ProcFile.txt", "r");

    if (ProcFile == NULL)
    {
        printf("Error reading file");
        exit(1);
    }

    unsigned long MaxKillBuf = MAX_PATH_SIZ;
    unsigned long MaxBuf = MAX_PATH_SIZ;

    char KillCommand[MAX_PATH_SIZ];
    char Ln[MAX_LINE_SIZ];

    fgets(Ln, MaxBuf, ProcFile);

    // Let's switch things up again
    #ifdef _WIN32
        snprintf(KillCommand, MaxKillBuf, "taskkill /f /im %s", Ln);
        system(KillCommand);
    #else
        snprintf(KillCommand, MaxKillBuf, "pkill %s", Ln);
        system(KillCommand);
    #endif

    fclose(ProcFile);
    free(Path);

    return 0;
}

