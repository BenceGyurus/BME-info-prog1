#include "debugmalloc.h"
#include <stdio.h>
#include "functions.h"
#include "morse.h"
#include "binary_tree.h"


int main(void)
{
    int morse_Length;
    Morse* morse_Array = read_Morse_From_File("../szotar.txt", &morse_Length);
    int inFunction = 0;
    if (morse_Array != NULL && morse_Length > 0)
    {
        Node* tree = forward_Morse_Data(morse_Array, morse_Length);
        printf("\nEnkódolni (e) vagy dekódolni (d) szeretne? Kilépés: /e [e/d]: ");
        char* function = read_From_Input();
        while ((strcmp(function, "/e") && inFunction < 1) || inFunction >= 1)
        {
            if (toupper(function[0]) == 'E' && function[1] == '\0') inFunction = 1;
            else if (toupper(function[0]) == 'D' && function[1] == '\0') inFunction = 2;
            else if (inFunction == 1) {encode_Morse(morse_Array, morse_Length, function);inFunction = 0; }
            else if (inFunction == 2) {decode_Morse(tree, function); inFunction = 0;}
            else
            {
                printf("Kérem válasszon funkciót!");
            }
            if (inFunction < 1) printf("\nEnkódolni (e) vagy dekódolni (d) szeretne? Kilépés: /e [e/d]: ");
            else if (inFunction == 1) printf("\nÍrja be a kódolandó szöveget >>");
            else printf("\nÍrja be a dekódolandó morze kódot >>");
            free(function);
            function = read_From_Input();
            if (function == NULL) printf("Nem sikerült beolvasni a bemenetet");
        }
        free(function);
        free_Tree(tree);
        free_Morse(morse_Array, morse_Length);
    }
    return 0;
}
