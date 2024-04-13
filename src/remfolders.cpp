#include "common/common.h"
#include "common/consts.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

void RemoveFolders()
{
    if (!std::filesystem::exists(LOIDR))
    {
        std::cout << "Program is wasn't installed" << '\n';
        exit(0);
    }

    if (std::filesystem::exists(LOIDR))
    {
        std::cout << "Reinstalling..." << '\n';

        std::filesystem::remove_all(LOIDR);
        std::filesystem::create_directories(LOIDR);

        chdir(LOIDR);
    }
}

