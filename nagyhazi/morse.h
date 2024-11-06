#ifndef MORSE_H
#define MORSE_H
#include "functions.h"
#include <stdbool.h>
#include "binary_tree.h"



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


bool find_Morze(char character, Morse* dictionary, int length)
{
    if (character == ' ') printf("/ ");
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (toupper(character) == dictionary[i].key)
            {
                printf("%s ", dictionary[i].value);
                return true;
            }
        }
        printf("\nHibatörtént! Ismeretlen karakter: %c", character); return false;
    }
    return true;
}

Morse create_Morse(char* string)
{
    Morse morse;
    morse.value = malloc(1 * sizeof(char));
    if (morse.value == NULL) return morse;
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




void encode_Morse(Morse* morse_Array, int length, char* read_Input)
{
    for (int i = 0; read_Input[i] != 0; i++)
    {
        if (!find_Morze(read_Input[i], morse_Array, length)) break;
    }
}

void free_Tree(Node* tree)
{
    if (tree == NULL) return;
    free_Tree(tree->left);
    free_Tree(tree->right);
    free(tree);
}

bool control_Morse_Code(char* morse)
{
    for (int i = 0; morse[i] != '\0'; i++)
    {
        if (morse[i] != ' ' && morse[i] != '.' && morse[i] != '-' && morse[i] != '/') {printf("A dekódolandó szöveg nem tartalmazhat a szóköztől, '.'-tól '-'-től és '/'-től különböző karaktert." ); return false;}
    }
    return true;
}

void decode_Morse(Node* tree, char* input)
{
    if (control_Morse_Code(input))
    {
        char* word = malloc(sizeof(char));
        word[0] = '\0';
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == '/') printf(" ");
            else if (input[i] == ' ' && word[0] != '\0')
            {
                printf("%c", search_In_tree(tree, word));
                free(word);
                word = malloc(sizeof(char));
                word[0] = '\0';
            }else if (input[i] != ' ')
            {
                word = to_String_Together(word, input[i]);
            }
        }
        if (word[0] != '\0') printf("%c", search_In_tree(tree, word));
        free(word);
    }
}

Morse* read_Morse_From_File(char* fileName, int* length){
    FILE* file = fopen(fileName, "r");
    if (file == NULL){ perror("Nem sikerült a fájlt megnyitni"); return NULL;}
    char* data = malloc(1 * sizeof(char)); data[0] = '\0';
    if (data == NULL) {perror("Nem sikerült memóriát lefoglalni"); return NULL;}
    char readChar;
    Morse* morse_Array = malloc(sizeof(Morse));
    if (morse_Array == NULL) return memory_error();
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
            free(data);
            data = malloc(1 * sizeof(char)); data[0] = '\0';
            if (data == NULL) return memory_error();
            morse_Length++;
        }

    }
    *length = morse_Length;
    free(data);
    fclose(file);
    return morse_Array;
}



#endif //MORSE_H
