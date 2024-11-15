#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h> // For the 'bool' type
#include <stddef.h>  // For NULL

// Struct definitions
typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Morse {
    char key;
    char* value;
} Morse;
void build_Binary_tree(Node* node, char* string, char value);
Node* forward_Morse_Data(Morse* morse_Array, int length);
char* reverse_Search_In_Morse_Tree(Node* node, char value, const char* morse_Code);
bool find_Morze(char character, Node* binary_Tree);
char search_In_tree(Node* node, char* string);

#endif // BINARY_TREE_H
