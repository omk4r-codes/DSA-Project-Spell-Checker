#include "struct.h"

// Returns new TRIE node (initialized to NULL)
Node *getNode(void)
{
    Node *pNode = NULL; // initialize pNode

    pNode = (Node *)malloc(sizeof(Node)); // Dynamic memory allocation for pNode

    if (pNode) // If pNode is not equal to NULL
    {
        // int i;

        pNode->isLeaf = 0; // Making leaf as 0

        for (int i = 0; i < ALPHABET_SIZE; i++) // To make new node
            pNode->children[i] = NULL;//empty array created
    }

    return pNode; // returning pNode
}


/*
The below function will be used to insert the word (key) in the Trie.
We'll modify the main program such that,
if the specified key (word) entered by the user is not present,
we'll give options to insert the key (word) in the Trie as well as to append the word in the .txt file we created.
*/
// If the key is prefix of TRIE node, just marks leaf node

void insert(Node *root, char *key) // This function is for inserting words in TRIE tree
{
    // initialization of variables
    int level;
    int index;
    int length;
    Node *curr = root;//current pointing at empty space initially when trie is empty

    length = strlen(key); // Finding length of the word

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]); // To find index of every character
        if (!curr->children[index])
            curr->children[index] = getNode(); // calling getNode function for creating new node

        curr = curr->children[index]; // Traverse to the children
    }

    //                                                  // mark last node as leaf
    curr->isLeaf = 1; // is leaf is 1 means that spelling is complete there
}

/*
Note that the below function (search) is searching for the
word/key (node) in the created Trie data structure.


So the conclusion is it returns true if the word is present in TRIE tree, else false.
*/

bool search(Node *root, const char *key)
{
    // initialization of variables
    int level;
    int length;
    int index;
    Node *curr = root;

    length = strlen(key); // Finding length of the word

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]); // To find index of every character
        if (!curr->children[index])
            return false;

        curr = curr->children[index]; // Traverse to the children
    }

    return (curr != NULL && curr->isLeaf); // returning word to the user (It means the word which you were finding is present in TRIE)
}
