#include "logic.h"

void executioner()
{
    Node *root = getNode();

    // from the below file we are inserting the words to trie.
    FILE *fmain = fopen("trie.txt", "r");

    if (fmain == NULL) {
        printf(">>>>> Error opening file.\n");
        return;
    }

    char ch[100];

    while (fscanf(fmain, "%s", ch) != EOF) {
        insert(root, ch);       
    }

    fclose(fmain);

    printf(">>>>> Start writing here:\n");
    char string[1000];
    scanf(" %[^\n]", string);


    
    char string_backup[1100];
    strcpy(string_backup, string);

    // we are storimg the words in the string one by one in the temp_word

    printf("\n>>>>> Analysing words...\n");
    int countofwrongwords = 0;
    char *temp_word;
    temp_word = strtok(string, " ,.-!~=_()/+*:");

    while (temp_word != NULL) {
              
        if (!search(root, temp_word)) {

            countofwrongwords = 1;
            printf("\n>>>>> seems incorrect : ------------ %s", temp_word);
            printf("\n>>>>> Did you intend to write: ");

            uppercase_logic(root, temp_word);
            // if(count != 0)
            //     goto here;
            swapping_logic(root, temp_word);
            repeat_logic(root, temp_word);
            wrong_letter_logic(root, temp_word);         
            extra_letter_logic(root, temp_word);


            if (count == 0)
            {
                printf(">>>>> Sorry, no suggestion(s) possible for the word!\n");
            }
            
        }
        
        // here:
        temp_word = strtok(NULL, " ,.-!~=_()+*:");

    }

    if(countofwrongwords == 0)
    {
        printf(">>>>> No incorrect words found!\n");
    }

    else
    {
        int choice;
        printf("\n\n>>>>> Do you want to add the word to the dictionary?\n>>>>> Press 1 for 'add', 0 for 'don't add':");
        scanf("%d", &choice);

        if (choice == 1) {
            printf(">>>>> Enter the word again: ");
            char data[100];
            scanf("%s", data);

            if (search(root, data) == 0)
            {
                fmain = fopen("trie.txt", "a");
                if (fmain == NULL) {
                    printf(">>>>> Error opening file.\n");
                    return;
                }

                fputs(data, fmain);
                fputs("\n", fmain);

                printf(">>>>> Word successfully added!\n");

                fclose(fmain);
            }

            else
            {
                printf(">>>>> Word already exists in the list!\n");
            }
        }
    }
    

}

// function to add word to the dictionary for insertion:
void addword(Node *root){
    char data[100];
    printf("\n>>>>> Give the word which you want to add into list : ");
        scanf("%s", data);

            FILE *fmain = NULL;
            fmain = fopen("trie.txt", "a"); 
            fputs(data, fmain);
            fputs("\n", fmain);
            printf("\n>>>>> Your word is successfully added to the dictionary!!!\n\n");
            fclose(fmain);
        
}

void interface(){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\tWelcome to Spell Checker/ Autocorrect Suggestions Wizard!\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}


/////////////////////////////////////////////////////////////////////////////
// Mod functions:


// function to destroy the trie:
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
    printf(">>>>> The trie structure is successfully destroyed.\n");
}


// function to clear the dictionary:
void clear_dictionary(){
    FILE * dict = fopen("demo2.txt", "w");

    if (dict == NULL)
    {
        printf(">>>>> Failed to open the file.\n");
        return;
    }
    
    fclose(dict);
    printf(">>>>> Dictionary cleared successfully.\n");
}



// to insert other text file's content in the dictionary:
void insert_dict(char* sourcefile)
{
    FILE* source = fopen(sourcefile, "r");

    if (source == NULL)
    {
        printf(">>>>> Failed to open file.\n");
        return;
    }

    FILE* destination = fopen("trie.txt", "a");
    char ch;
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
    printf(">>>>> Dictionary added successfully.\n");
}
