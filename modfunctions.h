#include"functions.h"

void destroyTrie(Node *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != NULL)
        {
            destroyTrie(root->children[i]);
            root->children[i] = NULL;
        }
    }

    free(root);
}