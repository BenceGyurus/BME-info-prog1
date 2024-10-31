#include <stdio.h>
#include <stdlib.h>

#include "debugmalloc.h"

int main(void)
{
    int hossz = 1;
    char* memoria = malloc(sizeof(char)*hossz);
    char be;
    memoria[0] = '\0';
    while (scanf("%c", &be) != EOF && be!='\n')
    {
        char* memoria2 = malloc(sizeof(char)*hossz);
        for (int i = 0; i < hossz-1; i++)
        {
            memoria2[i] = memoria[i];
        }
        free(memoria);
        memoria = malloc(sizeof(char)*(hossz+1));
        for (int i = 0; i < hossz; i++)
        {
            memoria[i] = memoria2[i];
        }
        free(memoria2);
        hossz++;
        memoria[hossz-2] = be;
        memoria[hossz-1] = '\0';
    }
    printf("%s\n", memoria);
    free(memoria);
    return 0;
}
