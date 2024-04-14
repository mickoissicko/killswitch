#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_SIZ 8192
#define MAX_PATH_SIZ 8192
#define MAX_SIZ 4096

int main()
{
    FILE* ProcFile;
    ProcFile = fopen("process.txt", "r");

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
    return 0;
}

