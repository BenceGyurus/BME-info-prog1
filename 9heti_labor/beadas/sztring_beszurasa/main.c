#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
int stringLength(char* string)
{
    int i = 0;for (; string[i] != '\0'; i++){}return i;
}

char* beszur(char* elso, int beszur_index, char* masodik)
{
    char* memoria = malloc((stringLength(elso) + stringLength(masodik) + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < stringLength(elso); i++)
    {
        if (i == beszur_index) for(int j = 0; masodik[j] != '\0'; j++)
        {
            memoria[index] = masodik[j];
            index++;
        }
        memoria[index] = elso[i];
        index++;
    }
    memoria[index] = '\0';
    return memoria;
}


int main(void)
{
    char* str = beszur("hello!", 5, ", vilag");
    printf("%s\n", str);
    free(str);
    return 0;
}
