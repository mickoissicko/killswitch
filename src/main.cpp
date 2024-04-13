#include "common/common.h"
#include "common/consts.h"

#include <filesystem>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAX_PATH_SIZ 4096
#define BUF_SIZ 1024
#define MAX_SIZ 1

int main(int argc, char* argv[])
{
    if (argc > 1 && !strcmp(argv[1], "--reinstall"))
    {
        std::cout << "Reinstalling..." << '\n';
        Reinstall();
    }

    char* DownloadCommand;
    unsigned long Buf = BUF_SIZ;

    DownloadCommand = (char*)malloc(BUFSIZ * sizeof(char));

    std::snprintf(DownloadCommand, BUF_SIZ, "wget %s", DEPS);

    std::cout << "Welcome to the Low Orbit ION Death-Ray" << std::endl
              << "[1] Start"                              << std::endl;
    std::cout << "[X] Quit"                               << std::endl;

    char* Path;
    char* Ui;

    Path = (char*)malloc(MAX_PATH_SIZ * sizeof(char));
    Ui = (char*)malloc(MAX_SIZ * sizeof(char));

    while (
        !!strcasecmp(Ui, "1") &&
        !!strcasecmp(Ui, "X")
    ){
        std::cout << "> ";
        std::cin >> Ui;
    }

    switch (*Ui)
    {
        case '1':
            #ifdef _WIN32
                Path = Win32_Path();
            #else
                Path = Posix_Path();
            #endif

            chdir(Path);

            if (!std::filesystem::exists(LOIDR))
                Install();

            CheckLockFile();
        break;

        default: break;
    }

    free(DownloadCommand);
    free(Path);
    free(Ui);

    return 0;
}

void CheckLockFile()
{
    chdir(LOIDR);
    std::ifstream LockFile("lock.pa");
    if (!LockFile.is_open())
    {
        std::cout << "Corrupt folder" << '\n';
        chdir("..");
        std::filesystem::remove_all(LOIDR);
        std::cout << "Run the program again" << '\n';
        std::cout << "The LOIDR folder seems to be corrupt..." << '\n';
        exit(1);
    }

    if (LockFile.is_open())
    {
        LockFile.close();
        Menu();
    }
}

