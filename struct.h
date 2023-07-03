#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0]) // evaluates the number of elements in the array a

#define ALPHABET_SIZE (26) // defining alphabet size = 26

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Making structure of TRIE node
typedef struct Node
{
    struct Node *children[ALPHABET_SIZE]; // making pointer array of size 26
    int isLeaf;                               // If isLeaf is 1 then end of word is true and if not then it is false
} Node;
