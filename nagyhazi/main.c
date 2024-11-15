#include "debugmalloc.h"
#include <stdio.h>
#include "functions.h"
#include "morse.h"
#include "binary_tree.h"


int main(int numberOfArgs, char** arguments)
{
    int morse_Length;
    Morse* morse_Array = read_Morse_From_File("../szotar.txt", &morse_Length);
    int inFunction = 0;
    if (morse_Array != NULL && morse_Length > 0)
    {

        Node* tree = forward_Morse_Data(morse_Array, morse_Length);
        if (numberOfArgs == 1)
        {
            printf("\nEnkódolni (e) vagy dekódolni (d) szeretne? Kilépés: /e [e/d]: ");
            char* function = read_From_Input();
            printf("%s", function);
            while ((strcmp(function, "/e") && inFunction < 1) || inFunction >= 1)
            {
                if (toupper(function[0]) == 'E' && function[1] == '\0' && inFunction < 1) inFunction = 1;
                else if (toupper(function[0]) == 'D' && function[1] == '\0' && inFunction < 1) inFunction = 2;
                else if (inFunction == 1) {encode_Morse(tree, function);inFunction = 0; }
                else if (inFunction == 2) {decode_Morse(tree, function); inFunction = 0;}
                else
                {
                    printf("}\nKérem válasszon funkciót!\n");
                }
                if (inFunction < 1) printf("\nEnkódolni (e) vagy dekódolni (d) szeretne? Kilépés: /e [e/d]: ");
                else if (inFunction == 1) printf("\nÍrja be a kódolandó szöveget >>");
                else printf("\nÍrja be a dekódolandó morze kódot >>");

                free(function);
                function = read_From_Input();
                if (function == NULL) printf("\nNem sikerült beolvasni a bemenetet\n");
            }
            free(function);
        }
        else
        {   if (numberOfArgs == 3)
        {
            if (toupper(arguments[1][0]) == 'E') { encode_Morse(tree, arguments[2]);}
            else if (toupper(arguments[1][0]) == 'D') { decode_Morse(tree, arguments[2]);}
            else printf("\nHibás bemenet\n");
        }else printf("\nHibás bemenet\n");
        }
        free_Tree(tree);
        free_Morse(morse_Array, morse_Length);
    }
    return 0;
}
