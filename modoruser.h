#include <string.h>
#include "additionslfun.h"
// #include "modfunctions.h"

int modoruser()
{
    int mod_or_user;
    back: printf("\n>>>>> Press 1 for general users, press 2 for mod, press 3 to exit: ");
    scanf("%d", &mod_or_user);
    if (mod_or_user == 2)
    {
        // code for mod!
        // means destroy trie,
        // delete the dictionary,
        char password[10];

        while (1)
        {
            printf(">>>>> Enter Password: ");
            scanf("%s", password);
            if (strcmp(password, "admin") == 0)
            {
                printf("\n-----------------------> You are in the DEVELOPER MODE. Be careful while using it. <-----------------------\n");
                while (1)
                {
                    printf(">>>>> How can I help you?\n>>>>> Press 1 to destroy the trie\n>>>>> Press 2 to clear the dictionary\n>>>>> Press 3 to go back\n>>>>> Press any other numkey to exit: ");
                    int mod_choice;
                    scanf("%d", &mod_choice);
                    if (mod_choice == 1)
                    {
                        Node *root = getNode();
                        destroyTrie(root);
                        printf("\nPress 1 to continue or 0 to exit: ");
                        int after_choice;
                        scanf("%d", &after_choice);
                        if (after_choice == 1)
                            continue;
                        else
                            goto label;

                    }
                    else if (mod_choice == 2)
                    {
                        // code for clearing the dictionary.
                        char two_step_verification[10];
                        printf("\n>>>>> Do you really want to CLEAR THE WHOLE DICTIONARY?\n>>>>> Type 'yes' for confirmation: ");
                        scanf("%s", two_step_verification);
                        if (strcmp(two_step_verification, "yes") == 0)
                        {
                            clear_dictionary();
                            printf("\n");
                        }
                        else
                        {
                            printf(">>>>> Dictionary deletion terminated.\n");
                            printf("\n");
                        }
                    }
                    else if (mod_choice == 3)
                    {
                        goto back;
                    }
                    
                    else
                    {
                        goto label;
                    }
                }
            }
            else if(strcmp(password, "exit") == 0){
                goto label;
            }
            else if (strcmp(password, "admin") != 0)
            {
                printf(">>>>> Wrong Password! Try again. Press 'exit' to exit:\n");
                continue;
            }
            
            else{
                label: break;
            }

        }
    }

    else if (mod_or_user == 1)
    {
        while (1)
        {
            printf("\n>>>>> How can I help you?\n>>>>> Press 1 for Autocorrect suggestions/spell checker\n>>>>> Press 2 for Adding a word to dictionary\n>>>>> Press 3 to add word file to dictionary\n>>>>> Press 4 to go back\n>>>>> Press 0 to exit: ");
            int choice;
            scanf("%d", &choice);

            if (choice == 0)
                break;

            else if (choice == 2)
            {
                Node *root = getNode();
                addword(root);
            }

            else if (choice == 1)
            {
                executioner();
            }
            else if(choice == 3)
            {
                char * filename;
                printf(">>>>> Enter the name of file you want to insert from: ");
                scanf("%s", filename);
                insert_dict(filename);
            }
            else if (choice == 4)
            {
                goto back;
            }
            

            else
            {
                printf("\n>>>>> Invalid selection! Try Again.\n");
                continue;
            }
        }
    }

    else if (mod_or_user == 3)
    {
        goto label;
    }
    else
    {
        printf(">>>>> Invalid selection! Try Again.\n");
    }

    return 0;
}