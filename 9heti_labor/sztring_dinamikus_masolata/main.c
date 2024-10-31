#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"


char* masolat(char* string)
{
    int length = strlen(string);
    char* memoria = malloc(length + 1);
    strcpy(memoria, string);
    memoria[length] = '\0';
    return memoria;
}


int main(void)
{
    char* str = masolat("Hello, World!\n");
    printf("%s", str);
    free(str);
    return 0;
}
