#include "binary_tree.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "debugmalloc.h"

void free_Tree(Node* tree)
{
    if (tree == NULL) return;
    free_Tree(tree->left);
    free_Tree(tree->right);
    free(tree);
}

void build_Binary_tree(Node* node, char* string, char value)            // elkészíti a bináris fát
{
    if (string[0] == '\0')
    {
        node->value = value;
    }else
    {
        if (string[0] == '.'){
            if (node->left == NULL)
            {
                node->left = malloc(sizeof(Node));
                if (node->left == NULL)
                {
                    printf("\nNem sikerült memóriát lefoglalni\n");
                } else
                {
                    node->left->left = NULL;
                    node->left->right = NULL;
                    node->left->value = '\0';
                }
            }
            build_Binary_tree(node->left, &string[1], value);
        }else
        {
            if (node->right == NULL)
            {
                node->right = malloc(sizeof(Node));
                if (node->right == NULL)
                {
                    printf("\nNem sikerült memóriát lefoglalni\n");
                } else
                {
                    node->right->left = NULL;
                    node->right->right = NULL;
                    node->right->value = '\0';
                }
            }
            build_Binary_tree(node->right, &string[1], value);
        }
    }
}

Node* forward_Morse_Data(Morse* morse_Array, int length)            //előkészíti az adatokat a a bináris fa elkészítéséhez --> létrehozza az első elemét a fának, végigmegy
{
    Node* tree = malloc(sizeof(Node));
    if (tree == NULL) return memory_error();
    tree->left = NULL;
    tree->right = NULL;
    tree->value = '\0';
    for (int i = 0; i < length; i++)
    {
        build_Binary_tree(tree, morse_Array[i].value, morse_Array[i].key);
    }
    return tree;
}


char* reverse_Search_In_Morse_Tree(Node* node, char value,char* morse_Code)
{
    if (!node) return NULL;
    if (node->value == value) {
        return masolat(morse_Code);
    }
    if (node->left) {
        char* left_path = add_Char_Without_Free_Memory(morse_Code, '.');
        char* result = reverse_Search_In_Morse_Tree(node->left, value, left_path);
        free(left_path);

        if (result) return result;
    }
    if (node->right) {
        char* right_path = add_Char_Without_Free_Memory(morse_Code, '-');
        char* result = reverse_Search_In_Morse_Tree(node->right, value, right_path);
        free(right_path);

        if (result) return result;
    }
    return NULL;
}


bool find_Morze(char character, Node* binary_Tree)
{
    if (character == ' ') printf("/ ");
    else
    {
        char* morse = reverse_Search_In_Morse_Tree(binary_Tree,  toupper(character), "\0");
        if (morse == NULL) {printf("\nHibatörtént! Ismeretlen karakter: %c\n", character); return false;}
        printf("%s ", morse);
        free(morse);
    }
    return true;
}

char search_In_tree(Node* node, char* string)
{
    if (node != NULL)
    {
        if (string[0] == '\0') return node->value;
        else if (string[0] =='.') return search_In_tree(node->left, &string[1]);
        else if (string[0] =='-') return search_In_tree(node->right, &string[1]);
    }
    return '\0';
}
