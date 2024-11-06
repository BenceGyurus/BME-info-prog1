//
// Created by Bence Gyürüs on 2024. 11. 05..
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>


void* memory_error()
{
    perror("Nem sikerült memóriát lefoglalni");
    return NULL;
}


char* masolat(char* string)
{
    int length = strlen(string);
    char* memoria = malloc(length + 1);
    if (memoria == NULL) return memory_error();
    strcpy(memoria, string);
    memoria[length] = '\0';
    return memoria;
}


char* to_String_Together(char* string1, char character){             // string1 muss pointer sein
    char* result = malloc((strlen(string1) + 2) * sizeof(char));
    if (result == NULL) return memory_error();
    strcpy(result, string1);
    int i = strlen(string1);
    free(string1);
    result[i] = character; result[i+1] = '\0';
    return result;
}

char* read_From_Input()
{
    char be;
    int length = 1;
    char* result = malloc(length * sizeof(char));
    if (result == NULL) return memory_error();
    result[0] = '\0';
    while (scanf("%c", &be) != EOF && be != '\n')
    {
        result = to_String_Together(result, be);
        if (result == NULL)
            return NULL;
    }
    return result;
}

#endif //FUNCTIONS_H
