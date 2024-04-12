#include "common/common.h"
// I have no idea why it isn't 'cstring' or 'string.h'
// Keeps giving me a warning when I use 'cstring'
// Says unused
// So I have to include strings.h because there is no cstrings
// And that's why I'm doing the same for stdlib.h
#include <filesystem>
#include <strings.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PATH_SIZ 4096
#define BUF_SIZ 1024
#define MAX_SIZ 1

const static std::string LOIDR = "Loidr";
const static char DEPS[] = "";

int main()
{
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
        !!strcasecmp(Ui, "2") &&
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
            {
                std::filesystem::create_directories(LOIDR);
                std::cout << "Downloading files required..." << '\n';
                std::cout << "If the download fails, please manually install 'wget'" << '\n';
                std::system("wget ");
            }
        break;
    }

    free (Path);
    free (Ui);
    return 0;
}

