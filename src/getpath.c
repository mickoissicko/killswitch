#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 4096

#ifndef _WIN32
    #include <sys/types.h>
    #include <pwd.h>

    char* Posix_Path()
    {
        struct passwd *Home;

        char* Path = NULL;

        if ((Home = getpwuid(getuid())) != NULL)
        {
            Path = (char*)malloc(MAX_STR_LEN);

            if (Path != NULL)
                strcpy(Path, Home->pw_dir);
        }

        return Path;
    }
#else
    char* Win32_Path()
    {
        unsigned long LEN = MAX_PATH_LEN;

        char* HomeDirectory = getenv("USERPROFILE");

        return HomeDirectory;
    }
#endif

