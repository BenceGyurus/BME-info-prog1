#include "debugmalloc.h"

char* masolat(char* string)
{
    int length = strlen(string);
    char* memoria = malloc(length + 1);
    strcpy(memoria, string);
    memoria[length] = '\0';
    return memoria;
}

char* hozzafuz(char* memoria, char* toAdd)
{
    int length1 = strlen(memoria);
    int length2 = 0;
    for (int i = 0; toAdd[i] != '\0'; i++)
    {
        length2++;
    }
    char* temp = malloc((length1 + length2 + 1)*sizeof(char));
    strcpy(temp, memoria);
    free(memoria);
    for (int i = length1; i < length1+length2; i++)
    {
        temp[i] = toAdd[i-length1];
    }
    temp[length1+length2] = '\0';
    return temp;
}

int main(void)
{
    char* str = masolat("Hello, World!");
    str = hozzafuz(str, " Hello, World");
    free(str);
    return 0;
}
