#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hossz;
    printf("Milyen hosszú tömböt szeretnél? >> ");
    scanf("%d", &hossz);
    double* memoria = malloc(sizeof(double) * hossz);
    for (int i = 0; i < hossz; i++)
    {
        printf("%d. szám >> ", i+1);
        scanf("%lf", &memoria[i]);
    }
    for (int i = hossz-1; i >= 0; i--)
    {
        printf("%lf\n", memoria[i]);
    }
    free(memoria);
    return 0;
}
