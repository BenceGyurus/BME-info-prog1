#ifndef BINARY_TREE_H
#define BINARY_TREE_H


#include "binary_tree.h"
#include "functions.h"

typedef struct Morse
{
    char key;
    char* value;
}Morse;

typedef struct Node
{
    char value;
    struct Node* left;
    struct Node* right;

} Node;

void build_Binary_tree(Node* node, char* string, char value)
{
    if (string[0] == '\0')
    {
        node->value = value;
    }else
    {
        if (string[0] == '.'){
            if (node->left == NULL){node->left = malloc(sizeof(Node)); if (node->left == NULL) {printf("\nNem sikerült memóriát lefoglalni");} else {node->left->left = NULL; node->left->right = NULL; node->left->value = '\0';}}
            build_Binary_tree(node->left, &string[1], value);
        }else
        {
            if (node->right == NULL){node->right = malloc(sizeof(Node)); if (node->right == NULL) {printf("\nNem sikerült memóriát lefoglalni");} else {node->right->left = NULL; node->right->right = NULL; node->right->value = '\0';}}
            build_Binary_tree(node->right, &string[1], value);
        }
    }
}

Node* forward_Morse_Data(Morse* morse_Array, int length)
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

#endif //BINARY_TREE_H
