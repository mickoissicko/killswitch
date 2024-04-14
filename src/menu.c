#include "common/common.h"
#include "common/consts.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZ 4096

void Menu()
{
    char* Path = (char*)malloc(MAX_SIZ * sizeof(char));

    #ifdef _WIN32
        Path = Win32_Path();
    #else
        Path = Posix_Path();
    #endif

    chdir(Path);
    chdir(LOIDR);

    printf("Loading...\n");

    #ifdef _WIN32
        system("win32_starter.bat");
    #else
        system("sudo python3 server.py");
    #endif

    free(Path);
    exit(0);
}

