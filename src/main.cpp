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

const static char LOIDR[] = "Loidr";
const static char DEPS[] = "https://raw.githubusercontent.com/mickoissicko/killswitch/main/pkgs/test_tarball_1.tar.gz";

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

                if (!std::filesystem::exists(LOIDR))
                    DispUnknownErr();

                else
                    chdir(LOIDR);

                std::cout << "Downloading files required..." << '\n';
                std::cout << "If the download fails, please manually install 'wget'" << '\n';

                int Status = std::system(DownloadCommand);

                if (Status != 0)
                    DispErrMsg();

                std::cout << "Extracting..." << '\n';
                std::cout << "If extracting fails, please manually install 'tar'" << '\n';

                Status = std::system("tar -xzf test_tarball_1.tar.gz");

                if (Status != 0)
                    DispErrMsg();
            }
        break;

        default: break;
    }

    free (DownloadCommand);
    free (Path);
    free (Ui);

    return 0;
}

void DispErrMsg()
{
    std::cerr << "An error occurred: " << stderr << '\n';
    std::cout << "Please check the wiki for instructions" << '\n';

    exit(1);
}

void DispUnknownErr()
{
    std::cerr << "An unexpected exception occurred: " << stderr << '\n';
    std::cout << "Please check the wiki for instructions" << '\n';

    exit(1);
}

