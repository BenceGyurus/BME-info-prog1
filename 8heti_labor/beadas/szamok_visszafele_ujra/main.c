#include <stdio.h>

#include "debugmalloc.h"

int main(void){
    double* memoria = malloc(sizeof(double));
    int hossz = 1;
    double be;
    while (scanf("%lf", &be) != EOF && be != -1)
    {
        memoria[hossz-1] = be;
        double* memoria2 = malloc(sizeof(double)*(hossz));
        for (int i = 0; i < hossz; i++)
        {
            memoria2[i] = memoria[i];
        }
        free(memoria);
        memoria = malloc(sizeof(double)*(hossz+1));
        for (int i = 0; i < hossz; i++)
        {
            memoria[i] = memoria2[i];
        }
        free(memoria2);
        hossz++;
    }
    hossz -= 1;
    for (int i = hossz-1; i >= 0; i--)
    {
        printf("memoria[%d] = %lf\n", i, memoria[i]);
    }
    free(memoria);
    return 0;
}
