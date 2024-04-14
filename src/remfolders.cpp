#include "common/common.h"
#include "common/consts.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>

void RemoveFolders()
{
    if (!std::filesystem::exists(LOIDR))
        std::filesystem::create_directories(LOIDR);

    if (std::filesystem::exists(LOIDR))
    {
        std::filesystem::remove_all(LOIDR);
        std::filesystem::create_directories(LOIDR);

        chdir(LOIDR);
    }
}

