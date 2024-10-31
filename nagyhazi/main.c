#include "debugmalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Morze
{
    char key;
    char* value;
}Morze;


void read_from_Input(char **memoria)
{
    int hossz = 1;
    *memoria = malloc(sizeof(char)*hossz);
    char be;
    (*memoria)[0] = '\0';
    while (scanf("%c", &be) != EOF && be!='\n')
    {
        char* memoria2 = malloc(sizeof(char)*hossz);
        strcpy(memoria2, *memoria);
        free(*memoria);
        *memoria = malloc(sizeof(char)*(hossz+1));
        strcpy(*memoria, memoria2);
        free(memoria2);
        hossz++;
        (*memoria)[hossz-2] = be;
        (*memoria)[hossz-1] = '\0';
    }
}


Morze create_Struct(char* string)
{
    Morze m;
    bool key = false;
    int length = 1;
    m.value = malloc(sizeof(char)*length);
    m.value[0] = '\0';
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ' && key == false)
        {
            key = true;
            m.key = string[i];
        }else if (key == true && string[i] != ' ')
        {
            char* temp = malloc(sizeof(char)*length);
            temp[0] = '\0';
            strcpy(temp, m.value);
            free(m.value);
            m.value = malloc(sizeof(char)*(length+1));
            strcpy(m.value, temp);
            free(temp);
            length++;
            m.value[length-2] = string[i];
            m.value[length-1] = '\0';
        }
    }
    return m;
}


void read_File(char* fileName, Morze** result, int* lengthOfMorze)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {perror("Error opening file"); return;}
    int hossz = 1;
    char *memoria = malloc(sizeof(char)*hossz);
    char be;
    (memoria)[0] = '\0';
    int morzeLength = 0;
    Morze* morzeArray = malloc(hossz*sizeof(Morze));
    while (fread(&be, sizeof(char), 1, file) == 1)
    {
        if (be != '\n')
        {
            char* memoria2 = malloc(sizeof(char)*hossz);
            strcpy(memoria2, memoria);
            free(memoria);
            memoria = malloc(sizeof(char)*(hossz+1));
            strcpy(memoria, memoria2);
            free(memoria2);
            hossz++;
            (memoria)[hossz-2] = be;
            (memoria)[hossz-1] = '\0';
        }else
        {
            morzeLength++;
            Morze* temp = malloc(sizeof(Morze)*(morzeLength-1));
            for (int i = 0; i < (morzeLength-1); i++)
            {
                temp[i] = morzeArray[i];
            }
            free(morzeArray);
            morzeArray = malloc(sizeof(Morze)*(morzeLength));
            for (int i = 0; i < (morzeLength-1); i++)
            {
                morzeArray[i] = temp[i];
            }
            free(temp);
            morzeArray[morzeLength-1] = create_Struct(memoria);
            hossz = 1;
            free(memoria);
            memoria = malloc(sizeof(char)*hossz);
            memoria[0] = '\0';
        }
    }
    *result = malloc(sizeof(Morze)*morzeLength);
    for (int i = 0; i < (morzeLength); i++)
    {
        (*result)[i].value = malloc(sizeof(char)*(strlen(morzeArray[i].value)+1));
        for (int j = 0; j < strlen(morzeArray[i].value); j++)
        {
            (*result)[i].value[j] = morzeArray[i].value[j];
        }
        (*result)[i].value[strlen(morzeArray[i].value)] = '\0';
        (*result)[i].key = morzeArray[i].key;
    }
    for (int i = 0; i < (morzeLength); i++)
    {
        free(morzeArray[i].value);
    }
    *lengthOfMorze = morzeLength;
    free(morzeArray);
    free(memoria);
}

int main(void)
{
    /*char** input;
    input = malloc(sizeof(char*));
    read_from_Input(input);
    free(*input);
    free(input);*/
    Morze** morzeChars = malloc(sizeof(Morze*));
    //printf("%p", morzeChars);
    int morzeLength;
    read_File("../szotar.txt", morzeChars, &morzeLength);
    for (int i = 0; i < morzeLength; i++)
    {
        printf("%c: %s\n", (*morzeChars)[i].key, (*morzeChars)[i].value);
    }
    for (int i = 0; i < (morzeLength); i++)
    {
        free((*morzeChars)[i].value);
    }
    free(*morzeChars);
    free(morzeChars);
    //Morze m = create_Struct("@ .--.-.");
    return 0;
}
