#include "debugmalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>


typedef struct Morse
{
    char key;
    char* value;
}Morse;

char* masolat(char* string)
{
    int length = strlen(string);
    char* memoria = malloc(length + 1);
    strcpy(memoria, string);
    memoria[length] = '\0';
    return memoria;
}

Morse morse_cpy(Morse morse)
{
    Morse new_Morse;
    new_Morse.key = morse.key;
    new_Morse.value = masolat(morse.value);
    free(morse.value);
    return new_Morse;
}


Morse* morse_Linked_List(Morse* pointer, int length, Morse new_Morse){
    Morse* new_Morse_Array = malloc(sizeof(Morse)*(length+1));
    for (int i = 0; i < length; i++)
    {
        new_Morse_Array[i] = morse_cpy(pointer[i]);
    }
    free(pointer);
    new_Morse_Array[length] = morse_cpy(new_Morse);
    return new_Morse_Array;
}


char* find_Morze(char character, Morse* dictionary, int length)
{
    if (character == ' ') printf("/ ");
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (toupper(character) == dictionary[i].key)
            {
                printf("%s ", dictionary[i].value);
            }
        }
    }
}



char* to_String_Together(char* string1, char character){             // string1 muss pointer sein
    char* result = malloc((strlen(string1) + 2) * sizeof(char));
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
    result[0] = '\0';
    while (scanf("%c", &be) != EOF && be != '\n')
    {
        result = to_String_Together(result, be);
    }
    return result;
}


Morse create_Morse(char* string)
{
    Morse morse;
    morse.value = malloc(1 * sizeof(char));
    morse.value[0] = '\0';
    bool key = false;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ' && !key)
        {
            key = true;
            morse.key = string[i];
        }else if (key == true && string[i] != ' ') morse.value = to_String_Together(morse.value, string[i]);
    }
    return morse;
}

void free_Morse(Morse* morse_Array, int length)
{
    for (int i = 0; i<length; i++)
    {
        free(morse_Array[i].value);
    }
    free(morse_Array);
}


Morse* read_Morse_From_File(char* fileName, int* length){
    FILE* file = fopen(fileName, "r");
    if (file == NULL) return NULL;
    char* data = malloc(1 * sizeof(char)); data[0] = '\0';
    char readChar;
    Morse* morse_Array = malloc(sizeof(Morse));
    int morse_Length = 0;
    while (fread(&readChar, sizeof(char), 1, file) == 1)
    {
        if (readChar != '\n')
        {
            data = to_String_Together(data, readChar);
        }else
        {
            Morse morse = create_Morse(data);
            morse_Array = morse_Linked_List(morse_Array, morse_Length, morse);
            free(data);data = malloc(1 * sizeof(char)); data[0] = '\0';
            morse_Length++;
        }

    }
    *length = morse_Length;
    free(data);
    return morse_Array;
}


int main(void)
{
    int morse_Length;
    Morse* morse_Array = read_Morse_From_File("../szotar.txt", &morse_Length);
    if (morse_Array != NULL)
    {
        printf("%d\n", morse_Length);
        char* read_Input = read_From_Input();
        for (int i = 0; read_Input[i] != 0; i++)
        {
            find_Morze(read_Input[i], morse_Array, morse_Length);
        }
        free_Morse(morse_Array, morse_Length);
        free(read_Input);
    }else
    {
        printf("Hiba történt a fájl beolvasása közben");
    }
    return 0;
}
