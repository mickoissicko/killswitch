#include <stdlib.h>
#include <stdio.h>

void DispErrMsg()
{
    printf("An error occurred\n%s\n", stderr);
    printf("Read the wiki for instructions!\n");

    exit(1);
}

void DispUnknownErr()
{
    printf("An unexpected exception occurred\n%s\n", stderr);
    printf("Read the wiki for instructions!\n");

    exit(1);
}

