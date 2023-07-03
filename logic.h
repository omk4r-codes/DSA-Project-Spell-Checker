#include "functions.h"

int count = 0;


/*Logic of AUTO correction of words*/

/*Function correct the word 'aplpe' to 'apple' basically it means swap the character in the word*/
void swapping_logic(Node *root, char word[100]) // Swapping of character in word
{
    // initialization of variables
    int length_word;
    int i, j, k;
    char temp, original[100];

    length_word = strlen(word); // find length of the word which user enter (This length will need for finding similar size of word)

    // converting word to array:
    for (i = 0; i < length_word; i++) 
        original[i] = word[i];

    for (i = 0; i < length_word; i++)
    {
        for (j = i + 1; j < length_word; j++)
        {
            /*swapping logic*/
            temp = word[i];
            word[i] = word[j];
            word[j] = temp;
            if (search(root, word) == 1) // calling search function if the function returns 1 means the word is correct
            {
                printf("%s, ", word);
                count++;
                // return word;
            }

            // now, to restore the original word;
            for (k = 0; k < length_word; k++) 
                word[k] = original[k];
        }
    }
}

/*Function correct the word by character which are repeat it self in that word . if we enter 'aray' it will give output 'array'*/
void repeat_logic(Node *root, char word[100]) // adding repeat character in word
{
    // initialization of variables and array
    int i, j, cn = 0, length_word;
    char new2[100];
    char new1[100];

    length_word = strlen(word); // finding length of word which user entered

    while (cn < length_word)
    {
        i = 0;

        while (i <= cn) // for copying every character of word to new
        {
            new2[i] = word[i];
            i++;
        }
        /*logic for entering every character to word at once*/
        for (j = i - 1; i <= length_word; i++, j++)
        {
            new2[i] = word[j];
        }
        for (i = 0; i <= length_word; i++)
        {
            new1[i] = new2[i];
        }
        new1[length_word + 1] = 0;
        if (search(root, new1) == 1) // calling search function if the function returns 1 means the word is correct
        {
            printf("%s, ", new1);
            count++;
        }
        cn++;
    }
}

/*auto correction of character which is not correct in our word e.g. if user enters "realise" then it will suggest "realize" */
void wrong_letter_logic(Node *root, char word[100]) // correct the character which is not correct in the word
{
    // initialization of variables and array
    int i = 0, length_word, j, cn = 0;
    char c;
    char new2[100];

    length_word = strlen(word); // finding length of word which user entered

    while (cn < length_word)
    {
        j = 0;
        while (j < 26) // while loop will change value of every character to a to z
        {
            i = 0;
            while (i < cn) // for copying every character of word to new2
            {
                new2[i] = word[i];
                i++;
            }

            c = j + 'a'; // making integer to character
            new2[i] = c;
            i++;
            while (i < length_word) // putting other elements in the array
            {
                new2[i] = word[i];
                i++;
            }
            new2[i] = 0;
            if (search(root, new2) == 1) // calling search function if the function returns 1 means the word is correct
            {
                printf("%s, ", new2);
                count++;
            }
            j++;
        }
        cn++;
    }
}


void extra_letter_logic(Node* root, char word[100])
{
    int len = strlen(word);

    // Iterate through all positions in the word
    for (int i = 0; i <= len; i++)
    {
        // Iterate through all letters of the alphabet
        for (char c = 'a'; c <= 'z'; c++)
        {
            // Create a new word by inserting the current letter at position i
            char newWord[101];
            strcpy(newWord, word);
            memmove(&newWord[i + 1], &newWord[i], len - i + 1);
            newWord[i] = c;

            // Check if the new word is present in the Trie
            if (search(root, newWord))
            {
                printf("%s, ", newWord);
                // return;
                continue;
            }
        }
    }

    // printf("No suggestion found for word: %s\n", word);
}


// doing the 1st letter uppercase logic:
void uppercase_logic(Node* root, char word[100])
{
    
    char word2[10];
    word2[0] = word[0] - 32;

    if (search(root, word2) == 1)
    {
        printf("%s, ", word2);
        count++;
        // return word2;
    }
    // else{
    //     return word2;
    // }
}

// Logic if user forgot space. Like the word: "itwas", if we add space after t, "it" and "was" both are correct.
// void space_logic(Node* root, char word[100])
// {
//     char newword[101];
//     strcpy(newword, word);
//     int len = strlen(word);

//     int i = 0;
//     for (int j = len - 1; j > i; j--)
//     {
//         newword[j+1] = newword[j];
//         newword[j] = " ";

//         char new2[100];
//         char new1[100];

//         int k = 0;
//         while (newword[k] != " ")
//         {
//             new1[k] = newword[k];
//             k++;
//         }
//         // now k is at the index of space.
//         k++;
//         while (newword[k] != '\0')
//         {
//             new2[k] = newword[k];
//             k++;
//         }
        
//         if (search(root, new1) == 1 && search(root, new2) == 1)
//         {
//             printf("%s %s, ", new1, new2);
//             count++;
            
//         }
        
//     }
    
// }
