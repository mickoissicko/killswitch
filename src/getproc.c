#include "common/common.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 8192

void GetProc(int argc, char** argv)
{
    FILE* Proc;

    Proc = fopen("process.txt", "w");

    if (Proc == NULL)
    {
        printf("Error making file\n");
        printf("Run with elevated privileges\n");
     
        exit(1);
    }

    char ProcName[MAX_LEN];

    printf("Enter process name (can be [absolute] path): ");
    scanf("%s", ProcName);

    fprintf(Proc, "%s", ProcName);
    fclose(Proc);

    // I know, righttt?!
    main(argc, argv);
}

