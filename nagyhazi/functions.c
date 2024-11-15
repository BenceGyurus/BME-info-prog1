#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"

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

char* add_Char_Without_Free_Memory(const char* path, char new_char) {               // ugyanazt csinálja
    int len = strlen(path);
    char* new_path = malloc(sizeof(char)*(len + 2));
    if (!new_path) return NULL;
    strcpy(new_path, path);
    new_path[len] = new_char;
    new_path[len + 1] = '\0';

    return new_path;
}


char* add_Char_To_String(char* string1, char character){             // string1 muss pointer sein
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
        result = add_Char_To_String(result, be);
        if (result == NULL)
            return NULL;
    }
    return result;
}
