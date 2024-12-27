#include "pokemon.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//function definition for initializeListManager which initializes an instance of ListManager and assigns function pointers for altering the user's linked list of caught Pokémon
void initializeListManager(struct ListManager *manager)
{
    manager->addPtr = add;
    manager->sortPtr = sort;
    manager->reversePtr = reverse;
    manager->deleteNodesPtr = deleteNodes;
    manager->swapPtr = swap;
}

//function definition for initializeMenuManager which initializes an instance of MenuManager and assigns function pointers to facilitate the menu selection options that the user selects
void initializeMenuManager(struct MenuManager *manager)
{
    manager->menuPtr = menu;
    manager->huntPtr = hunt;
    manager->pokemonCaughtPtr = pokemonCaught;
    manager->statsPtr = stats;
    manager->inventoryPtr = inventory;
    manager->displayPokePtr = displayPoke;
    manager->writeToFilePtr = writeToFile;
}

//function definition for initializeTrieManager which initializes an instance of TrieManager and assigns function pointers for creating a trie, searching a trie, and freeing a trie from memory
void initializeTrieManager(struct TrieManager *manager)
{
    manager->getNodePtr = getNode;
    manager->getCharIndexPtr = getCharIndex;
    manager->insertPtr = insert;
    manager->searchPtr = search;
    manager->freeTriePtr = freeTrie;
}

//function definition for getNode which creates the root node within the trie
struct Trie *getNode()
{
    //variable declarations and initializations using dynamic memory allocation
    struct Trie *parent = malloc(sizeof(struct Trie));

    //selection statement which evaluates to true if memory allocation failed for the parent node; if so, exit the program
    if (parent == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    parent->isEndOfWord = false;
    parent->index = -1;

    //for loop which initializes each child node within the children array to point to NULL
    for (int i = 0; i < ALPHABET_SIZE; i++)
        parent->children[i] = NULL;

    return parent;
}

//function definition for trieImplementation which finds and returns the appropriate integer index that is associated with the character that ptr points to
int getCharIndex(const char *ptr)
{
    //selection statement which evaluates to true if the letter in the stirng that ptr points to is an upper-case letter; if so, index is initialized to *ptr - 'A'
    if (*ptr >= 'A' && *ptr <= 'Z')
        return *ptr - 'A';

    //selection statement which evaluates to true if the letter in the stirng that ptr points to is a lower-case letter; if so, index is initialized to *ptr - 'a' + 26
    else if (*ptr >= 'a' && *ptr <= 'z')
        return *ptr - 'a' + 26;

    //selection statement which evaluates to true if the letter in the string that ptr points to is an apostrophe; if so, index is initialized to 52
    else if (*ptr == APOSTROPHE)
        return APOSTOPHE_INDEX;

    //selection statement which evaluates to true if the letter in the string that ptr points to is a period; if so, index is initialized to 53
    else if (*ptr == PERIOD)    
        return PERIOD_INDEX;

    //selection statement which evaluates to true if the letter in the string that ptr points to is 2; if so, index is initialized to 54
    else if (*ptr == TWO)
        return TWO_INDEX;

    //selection statement which evaluates to true if the letter in the string that ptr points to is a hyphen; if so, index is initialized to 55
    else if (*ptr == HYPHEN)
        return HYPHEN_INDEX;  

    return 0;
}


//function definition for insert which inserts a new node into the trie with the given string and number
void insert(struct Trie *root, const char *string, const int *number, const struct TrieManager *manager)
{
    //variable declarations and initialization
    struct Trie *parent = root;
    int index;
    
    //for loop which iterates through the string and inserts each character as a new node within the trie
    for (const char *ptr = string; *ptr != '\0'; ptr++)
    {
        //calling the trieImplementation function to get the index that is associated with the character that ptr points to
        index = manager->getCharIndexPtr(ptr);

        //selection statement which evaluates to true if the child node at index character is NULL; if so, declare and initialize a node that is pointed to by parent
        if (parent->children[index] == NULL)
            parent->children[index] = getNode();

        //updating the parent node to point to the child node at index character
        parent = parent->children[index];
    }

    //updating the index of the last node in the string to the given number and marking it as the end of a word in the trie
    parent->index = *number;
    parent->isEndOfWord = true;
}

//function definition for search which searches the trie to see if string is a valid string that exists in the trie
bool search(struct Trie *root, const char *string, int *number, const struct TrieManager *manager)
{
    //variable declarations and initialization
    struct Trie *parent = root;
    int index;

    //for loop which iterates through the string and checks if each character exists as a node within the trie
    for (const char *ptr = string; *ptr != '\0'; ptr++)
    {
        //calling the trieImplementation function to get the index that is associated with the character that ptr points to
        index = manager->getCharIndexPtr(ptr);

        //selection statement which evaluates to true if the child node at index character is NULL; if so, the string does not exist in the trie and the function returns false
        if (parent->children[index] == NULL)
            return false;

        //updating the parent node to point to the child node at index character
        parent = parent->children[index];
    }
    
    //if the loop completes without finding a null node, the string exists in the trie and the function returns true; the number associated with the string is also stored in *number
    *number = parent->index;

    return (parent != NULL && parent->isEndOfWord);
}

//function definition for removeNewline which removes the new-line characters from the string and replaces them with the null character
void removeNewline(char *name)
{
    //selection statement which evaluates to true if name points to an empty string; if so, this function returns back to where the function was called
    if (name == NULL)
        return;

    //for loop which iterates through the string until the first null-character is found
    for (char *ptr = name; *ptr != '\0'; ptr++)
        //selection statement which evaluates to true if *ptr points to a new-line character; if so, it replaces the new-line character with a null character
        if (*ptr == '\n')
            *ptr = '\0';
}

//function definition for validRegion which determines if the user entered a valid region
bool validRegion(char *region)
{
    //converting first character in region to upper case
    *region = toupper(*region);

    //for loop which iterates through all characters within region, converts the remainder of characters to lower case, and converts any new-line characters to NULL characters
    for (char *ptr = region + 1; *ptr != '\0'; *ptr = tolower(*ptr), ptr++);
    removeNewline(region);

    //returning true if the user entered a valid region; otherwise, returning false
    return (!strcmp(region, "Kanto") || !strcmp(region, "Johto") || !strcmp(region, "Hoenn") || !strcmp(region, "Sinnoh")) ? true : false;
}

//function definition for menu which prints the menu to the screen
void menu()
{
    printf("==================== MENU ====================\n");
    printf("• HUNT      - Go hunting for Pokémon!\n");
    printf("• POKÉMON   - See the Pokémon you've caught.\n");
    printf("• SORT      - Sort Pokémon you've caught.\n");
    printf("• STATS     - See your catch statistics.\n");
    printf("• INVENTORY - See your current inventory.\n");
    printf("• NAME      - View a Pokémon's Pokédex entry (e.g., BULBASAUR).\n");
    printf("• EXIT      - End your adventure.\n");
    printf("==============================================\n");
}

//function definition for getSelection which gets the user's menu selection and converts the input into a friendly form
void getSelection(char *input)
{
    //do-while loop which continues to prompt the user for input until a valid selection is provided
    do
    {
        //getting the user's input
        printf("Selection > ");
        fgets(input, MAX_DEX_ENTRY, stdin);
        //removing the newline character from the user's input
        removeNewline(input); 

        if (!strlen(input))
            printf("\nInput must at lease one or more characters long.\n\n");
    } while (!strlen(input));

    //for loop which iterates through the user's input, converts the first character in the user's input to upper case, converts the remainder of the user's input to lower case, and converts any new-line characters to NULL characters
    for (char *ptr = input; *ptr != '\0'; ptr++)
        //ternary expression which evaluates to true if ptr points to the first character in the user's input or if the previous character was either a . or a -; if so, make the first character uppercase; otherwise, make the rest of the characters lowercase
        (ptr == input || *(ptr - 1) == '.' || *(ptr - 1) == '-') ? (*ptr = toupper(*ptr)) : (*ptr = tolower(*ptr));       
}   

//function definition for hunt which facilitates the Hunt menu option for catching Pokémon
void hunt(char *region, struct Pokemon *pokemons, const int *size, void (*balls) (const int *, const int *, const int *), int *pokeBalls, int *greatBalls, int *ultraBalls, int *caught, int *seen, struct Pokemon **head, const struct ListManager *manager)
{
    //variable declarations and initialization
    int randomNum, catchNum = rand() % 100 + 1, choosenBallType;
    char inputBuffer[MAX_DEX_ENTRY];
    //calling removeNewline function to remove new-line characters from region and replace them with null characters
    removeNewline(region);

    //selection statement which evaluates to true if region is equal to Kanto; if so, generate a random number between 1 and 151 (inclusive)
    if (!strcmp(region, "Kanto"))
        randomNum = rand() % KANTO_MAX_POKEMON + 1;

    //selection statement which evaluates to true if region is equal to Johto; if so, generate a random number between 152 and 251 (inclusive)
    else if (!strcmp(region, "Johto"))
        randomNum = rand() % JOHTO_MAX_POKEMON + 152;

    //selection statement which evaluates to true if region is equal to Hoenn; if so, generate a random number between 252 and 386 (inclusive)
    else if (!strcmp(region, "Hoenn")) 
        randomNum = rand() % HOENN_MAX_POKEMON + 252;

    //selection statement which evaluates to true if region is equal to Sinnoh; if so, generate a random number between 387 and 493 (inclusive)
    else
        randomNum = rand() % SINNOH_MAX_POKEMON + 387;
    
    //randomly generating individual values for each Pokémon that the user encounters
    pokemons[randomNum].data->attackIV = rand() % 15 + 1;
    pokemons[randomNum].data->defenseIV = rand() % 15 + 1;
    pokemons[randomNum].data->staminaIV = rand() % 15 + 1;
    
    //calculating the Pokémon's individual value as a total percentage
    pokemons[randomNum].data->percentIV = 100 * ((pokemons[randomNum].data->attackIV + pokemons[randomNum].data->defenseIV + pokemons[randomNum].data->staminaIV) / 45.0);

    //printing the Pokémon's name since it has now appeared
    printf("\nA wild %s has appeared!\n\n", pokemons[randomNum].name);

    //selection statement which evaluates to true if the Pokémon's catch percentage is 0; if so, print a message saying that the Pokémon that has been encountered is a baby Pokémon. This baby Pokémon has now been caught without using any type of ball
    if (!pokemons[randomNum].catchPercentage) 
    {
        printf("Oh! That's a baby Pokémon! We'll take them to the daycare.\n");
        //incrementing the number of pokemon caught and seen at index randonNum by one
        pokemons[randomNum].data->caught++;
        pokemons[randomNum].data->seen++;

        return;
    }     

    //do-while loop which iterates until the user has thrown a ball in an attempt to catch the Pokémon
    do
    {
        //calling the balls function which is responsible for displaying how many of each type of ball the user has
        balls(pokeBalls, greatBalls, ultraBalls);    
        
        //getting the user's input and then converting the user's input into an integer using the atoi function within the stdlib library
        printf("Choose ball (1, 2, or 3) > ");    
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        choosenBallType = atoi(inputBuffer);

        //selection statement which evaluates to true if the user has chosen a Poké Ball and if the user has more than zero Poké Balls
        if (choosenBallType == 1 && *pokeBalls > 0 || choosenBallType == 2 && *greatBalls > 0 || choosenBallType == 3 && *ultraBalls > 0)
        {
            //selection statement which evaluates to true if the user has chosen to throw a Poké Ball
            if (choosenBallType == 1)
                printf("\nThrew a Poké Ball!\n");

            //selection statement which evaluates to true if the user has chosen to throw a Great Ball; if so, increase the chance of the user catching the Pokémon by 20 percent
            else if (choosenBallType == 2)
            {
                printf("\nThrew a Great Ball!\n");
                catchNum -= 20;
            }

            //selection statement which evaluates to true if the user has chosen to throw an Ultra Ball; if so, increase the chance of the user catching the Pokémon by 40 percent
            else if (choosenBallType == 3)
            {
                printf("\nThrew an Ultra Ball!\n");
                catchNum -= 40;
            }

            //calling the huntHelper function which determines whether the user has caught the Pokémon based on the catchNum argument; the function handles what to do if the Pokémon is caught or has ran
            huntHelper(&catchNum, ultraBalls, pokemons, &randomNum, caught, seen, head, manager);
        }

        //selection statement which evaluates to true if the user has chosen to throw a Poké Ball, but the user has zero Poké Balls
        else if (choosenBallType == 1 && *pokeBalls == 0 || choosenBallType == 2 && *greatBalls == 0 || choosenBallType == 3 && *ultraBalls == 0)
        {
            //selection statement which evaluates to true if the user has thrown a Poké ball
            if (choosenBallType == 1)
                printf("\nYou don't have any Poké Balls.\n");

            //selection statement which evaluates to true if the user has thrown a Great Ball     
            else if (choosenBallType == 2)    
                printf("\nYou don't have any Great Balls.\n"); 
            
            //selection statement which evaluates to true if the user has thrown an Ultra Ball
            else if (choosenBallType == 3)    
                printf("\nYou don't have any Ultra Balls.\n"); 
            
            choosenBallType = 4;
        }    

        //selection statement which evaluates to true if the user has chosen an invalid option
        else
            printf("\nInvalid input. Please try again.\n"); 
    } while (choosenBallType != 1 && choosenBallType != 2 && choosenBallType != 3 && (*pokeBalls + *greatBalls + *ultraBalls + *ultraBalls > 0));
}

//function definition for huntHelper which determines whether the user has successfully caught the Pokémon it is encountering or if the Pokémon has fled
void huntHelper(int *catchNum, int *balls, struct Pokemon *pokemons, const int *index, int *caught, int *seen, struct Pokemon **head, const struct ListManager *manager)
{
    //decrementing the number of Ultra Balls the user has since one of them was used in the attempt to catch the Pokémon
    (*balls)--;

    //ternary expression which evaluates to true if the randomly generated integer, catchNum, is greater than the catch percentage of the Pokémon at index randomNum plus 40 since the Ultra Ball increases the chance of catching the Pokémon; if so, call the pokeCaught function which facilitates the catching process; otherwise, call the pokeRan function which facilitates the Pokémon fleeing process
    (*catchNum <= pokemons[*index].catchPercentage) ? (pokeCaught(pokemons, index, caught, seen, head, manager)) : (pokeRan(pokemons, index, seen));
}

//function definition for balls which prints a neat display of how many Poké Balls, Great Balls, and Ultra Balls the user currently has
void balls(const int *pokeBalls, const int *greatBall, const int *ultraBall)
{
    printf("+-----------------+-------------+\n");
    printf("|     Item        |  Inventory  |\n");
    printf("+-----------------+-------------+\n");
    printf("| 1. Poké Ball    | %11d |\n", *pokeBalls);
    printf("| 2. Great Ball   | %11d |\n", *greatBall);
    printf("| 3. Ultra Ball   | %11d |\n", *ultraBall);
    printf("+-----------------+-------------+\n");
}

//function definiton for add which is responsible for adding a newly caught Pokémon to a linked list
struct Pokemon *add(struct Pokemon **head, const struct Pokemon *pokemons, const int *random)
{
    //variable declaration and initialization using dynamic memory allocation
    struct Pokemon *ptr = *head, *prev = NULL, *instance = malloc(sizeof(struct Pokemon));
    
    //checking if the memory allocation was successful
    if (instance == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    //copying the data from the provided Pokémon into the dynamically allocated memory
    *instance = pokemons[*random];
    //making instance point to the next item in the linked list which is NULL
    instance->next = NULL;

    //checking if the head of the linked list is NULL; if so, make the new instance the head
    if (*head == NULL)
    {
        *head = instance;
        instance->previous = NULL;
    }    

    //if the head of the linked list is not NULL, traverse to the end of the linked list and add the new instance there
    else
    {
        //for loop which traverses ptr to point to the last item in the linked list
        for (; ptr->next != NULL; prev = ptr, ptr = ptr->next);

        //adding the new instance to the end of the linked list by making the second last item in the linked list point to instance and have instance->previous point to the previous last item in the linked list
        ptr->next = instance;
        ptr->previous = prev;
    }    

    //returning the updated head of the linked list
    return *head;
}

//function definiton for pokeCaught which facilitates the process of the user successfully catching a Pokémon
struct Pokemon *pokeCaught(struct Pokemon *pokemons, const int *random, int *caught, int *seen, struct Pokemon **head, const struct ListManager *manager)
{ 
    //printing a congratulatory message saying that the user has caught a Pokémon
    printf("Congratulations! You caught %s!\n\n", pokemons[*random].name);

    //incrementing the caught and seen counters in the Pokémon struct of the caught Pokémon
    pokemons[*random].data->caught++;
    pokemons[*random].data->seen++;
    (*caught)++;
    (*seen)++;

    //calling the add function to add the caught Pokémon to the linked list and returning the updated head of the linked list
    return manager->addPtr(head, pokemons, random);;
}

//function definiton for pokeRan which facilitates the process of the user unsuccessfully catching a Pokémon
void pokeRan(struct Pokemon *pokemons, const int *random, int *seen)
{
    //printing a message saying that the user has unsuccessfully caught a Pokémon
    printf("%s ran away.\n\n", pokemons[*random].name);

    //incrementing the seen counter in the Pokémon struct of the uncaught Pokémon
    pokemons[*random].data->seen++;
    (*seen)++;
}

//function definition for pokemonCaught which displays all the Pokémon that the user has caught
void pokemonCaught(const struct Pokemon *head, int *selection)
{
    //variable declaration and initialization
    const struct Pokemon *ptr = head;
    int counter = 1;
    char inputBuffer[MAX_NAME_LENGTH];

    //selection statement which evaluates to true if the user has yet to catch any Pokémon
    if (head == NULL)
        printf("\nYou have not caught any pokémon yet!\n\n");

    //selection statement which evaluates to true if the user has caught at least one Pokémon
    else
    {
        //selection stateent which evaluates to true if *selection is equal to 2; if so, the function has passed this argument signaling to only print the detailed descriptions of all the Pokémon
        if (*selection != 1)
            //do-while loop which iterates until the user specifies how it would like to view its caught Pokémon
            do
            {
                //printing the menu for the user to choose how they would like to view their caught Pokémon
                printf("\n===== Pokemon Menu =====\n");
                printf("1. View Pokemon Details\n");
                printf("2. List Caught Pokemon\n");
                printf("3. Exit\n");
                printf("Choose an option: ");

                //taking user input and converting it to an integer
                fgets(inputBuffer, sizeof(inputBuffer), stdin);
                *selection = atoi(inputBuffer);
            } while (*selection < 1 || *selection > 3);
        
        //selection statement which evaluates to true if *selection is equal to 1; if so, print the detailed descriptions of all the Pokémon
        if (*selection == 1)
            //for loop which iterates through the linked list
            for (printf("\n==== All Pokémon ====\n"); ptr != NULL; ptr = ptr->next)
            {
                //printing the detailed description of each Pokémon
                printf("\n==== %s's Details ====\n", ptr->name);
                printf("Pokemon Number: %d\n", ptr->pokemonNum);
                printf("Type: %s\n", ptr->type);
                printf("Region: %s\n", ptr->region);
                printf("Caught: %d\n", ptr->data->caught);
                printf("Seen: %d\n", ptr->data->seen);
                printf("IV: (Attack: %d, Defense: %d, Stamina: %d) -> %.2f%%\n", ptr->data->attackIV, ptr->data->defenseIV, ptr->data->staminaIV, ptr->data->percentIV);
            }    

        //selection statement which evaluates to true if *selection is equal to 2; if so, print the names of all the Pokémon that the user has caught
        if (*selection == 2)
        {
            //for loop which iterates through the linked list and prints each of the Pokémon's name
            for (printf("\n==== Your Caught Pokémon ====\n"); ptr != NULL; ptr = ptr->next)
                printf("%d. %s\n", counter++, ptr->name);

            //printing the total number of Pokémon caught
            printf("===============================\nTotal Pokémon Caught: %d\n\n", --counter);
        }

        //selection statement which evaluates to true if *selection is equal to 3; if so, exit the function
        else
        {
            putchar('\n');
            return;
        }
    }    
}

//function definition for stats which prints the user's statistics
void stats(const int *caught, const int *seen)
{
    //printing the number of Pokémon caught and seen by the user
    printf("\n=== Catch Statistics ===\nPokémon Caught: %d\n", *caught);
    printf("Pokémon Seen: %d\n", *seen);

    //ternary expression which evaluates to true if the user has caught more than one Pokémon; if so, print the user's catch rate; otherwise, print a new-line character
    (*caught > 0) ? (printf("Catch Rate: %.2f%%\n\n", ((float) (*caught) / *seen) * 100)) : putchar('\n');
}

//function definition for inventory which prints the user's ball inventory
void inventory(const int *pokeBall, const int *greatBall, const int *ultraBall)
{
    //printing the user's ball inventory in a neat format
    printf("\n========= Ball Inventory =========\n");
    printf("%-15s%-15s\n", "Ball Type", "Count");
    printf("----------------------------------\n");
    printf("%-15s%-15d\n", "Poke Ball", *pokeBall);
    printf("%-15s%-15d\n", "Great Ball", *greatBall);
    printf("%-15s%-15d\n", "Ultra Ball", *ultraBall);
    printf("==================================\n\n");
}

//function definition for displayPoke which prints the specified Pokémon's information
void displayPoke(const struct Pokemon *pokemons, const int *index)
{
    //printing the specified Pokémon's information
    printf("\n=========================================\n");
    printf(" Pokémon Information\n");
    printf("=========================================\n");
    printf(" Name       : %s\n", pokemons[*index].name);
    printf(" Type       : %s\n", pokemons[*index].type);
    printf(" Dex Entry  : %s\n", pokemons[*index].dexEntry);
    printf("=========================================\n\n");
}

//function definition for sortMenu which prints the sorting menu
int sortMenu()
{
    //variable declarations
    char inputBuffer[MAX_DEX_ENTRY];
    int selection;

    //do-while loop which continues until a valid selection is made
    do
    {
        //printing the sorting menu
        printf("\n============================================\n");
        printf("            Pokémon Sorting Menu            \n");
        printf("============================================\n");
        printf("1. Sort Lexicographically (Ascending)\n");
        printf("2. Sort Lexicographically (Descending)\n");
        printf("3. Sort by Type\n");
        printf("4. Sort by Pokémon Number (Ascending)\n");
        printf("5. Sort by Pokémon Number (Descending)\n");
        printf("6. Reverse Current List\n");
        printf("============================================\n");
        printf("Enter your choice > ");

        //reading user input and converting it to an integer
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        selection = atoi(inputBuffer);
    } while (selection < 1 || selection > 6);
    
    //returning the selected sorting option
    return selection;
}

//function definiton for sort which is responsible for sorting the linked list of Pokémon caught
struct Pokemon *sort(struct Pokemon *head, const struct ListManager *manager)
{
    //variable declarations and initializations
    int selection;
    struct Pokemon *ptr = head, *ptr2 = head;
    bool swap;

    //selection statement which evaluates to true if head is equal to NULL, indicating that the user has yet to catch a Pokémon; if so, print an error message and exit the function
    if (head == NULL)
    {
        printf("\nYou have not caught any Pokémon yet so nothing can be sorted.\n\n");
        return NULL;
    }
    
    //getting the user's input for which type of sorting to take place on the linked list
    selection = sortMenu();

    //outer for loop which iterates over the linked list and sorts the students
    for (ptr = head; ptr != NULL && selection != 6; ptr = ptr->next)
        //inner for loop which iterates over the linked list and sorts the students
        for (ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            //switch statement which determines the sorting criteria based on the logic pointer's value
            switch (selection)
            {
                case 1: swap = (strcmp(ptr->name, ptr2->name) > 0); break;
                case 2: swap = (strcmp(ptr2->name, ptr->name) > 0); break;
                case 3: swap = (strcmp(ptr->type, ptr2->type) > 0); break;
                case 4: swap = (ptr2->pokemonNum > ptr->pokemonNum); break;
                case 5: swap = (ptr2->pokemonNum < ptr->pokemonNum); break;        
            }

            //selection statement which evaluates to true if swap is true, meaning that the students ptr and ptr2 point to should be swapped
            if (swap)
            {
                //calling the swapPtr function to swap the nodes within the doubly linked list of the students
                manager->swapPtr(ptr, ptr2, head);

                //updating the head pointer if the swapped node is the head
                ptr = head;

                break;
            }
        }

    //switch statement which is responsible for printing a message that the user's Pokémon have been successfully sorted
    switch (selection)
    {
        case 1: printf("\nYour Pokémon were successfully sorted lexicographically (ascending)!\n\n"); break;
        case 2: printf("\nYour Pokémon were successfully sorted lexicographically (descending)!\n\n"); break;
        case 3: printf("\nYour Pokémon were successfully sorted by region!\n\n"); break;       
        case 4: printf("\nYour Pokémon were successfully sorted number (ascending)!\n\n"); break;    
        case 5: printf("\nYour Pokémon were successfully sorted number (descending)!\n\n"); break; 
        case 6: head = manager->reversePtr(head, manager); printf("\nYour Pokémon were successfully sorted in reverse!\n\n"); break;
    }

    //returning the head of the sorted linked list
    return head;
}

//function definiton for deleteNodes which is responsible for freeing the dynamically allocated memory for all nodes within the linked list
struct Pokemon *deleteNodes(struct Pokemon *head)
{
    //variable declaration and initialization
    struct Pokemon *tempNode = head;

    //while loop which traverses the linked list and frees each node that has been dynamically allocated
    while (tempNode != NULL)
    {
        tempNode = head->next;
        free(tempNode);
        head = tempNode;
    }

    //returning NULL after all nodes have been freed
    return NULL;
}

//function definition for swap which facilitates the sorting of the linked list
void swap(struct Pokemon *ptr, struct Pokemon *ptr2, struct Pokemon *head)
{
    //variable declaration and initialization using dynamically allocated memory
    struct Pokemon *tempNode = malloc(sizeof(struct Pokemon));

    //swapping the data members of the two nodes
    strcpy(tempNode->name, ptr->name);
    strcpy(tempNode->type, ptr->type);
    strcpy(tempNode->dexEntry, ptr->dexEntry);
    strcpy(tempNode->region, ptr->region);
    tempNode->pokemonNum = ptr->pokemonNum;
    tempNode->catchPercentage = ptr->catchPercentage;
    tempNode->data = ptr->data;

    //swapping the data members of the two nodes
    strcpy(ptr->name, ptr2->name);
    strcpy(ptr->type, ptr2->type); 
    strcpy(ptr->dexEntry, ptr2->dexEntry);
    strcpy(ptr->region, ptr2->region);
    ptr->pokemonNum = ptr2->pokemonNum;
    ptr->catchPercentage = ptr2->catchPercentage;
    ptr->data = ptr2->data;

    //swapping the data members of the two nodes
    strcpy(ptr2->name, tempNode->name);
    strcpy(ptr2->type, tempNode->type);
    strcpy(ptr2->dexEntry, tempNode->dexEntry);
    strcpy(ptr2->region, tempNode->region);
    ptr2->pokemonNum = tempNode->pokemonNum;
    ptr2->catchPercentage = tempNode->catchPercentage;
    ptr2->data = tempNode->data;

    //freeing the dynamically allocated memory for the temporary node
    free(tempNode);
}

//function definition for reverse which reverses the nodes within the doubly linked list
struct Pokemon *reverse(struct Pokemon *head, const struct ListManager *manager)
{
    //variable declarations and initializations
    struct Pokemon *ptr = head, *ptr2 = head, *allNodes;
    int nodes = 0, i = 0;

    //for loop which iterates and counts all the nodes in the doubly linked list
    for (struct Pokemon *ptr = head; ptr != NULL; ptr = ptr->next, nodes++);

    //dynamically allocating memory for allNodes array
    allNodes = malloc(nodes * sizeof(struct Pokemon));

    //selection statement which evaluates to true if allNodes is equal to NULL, indicating that memory was not successfully allocated dynamically
    if (allNodes == NULL)
    {
        printf("\nMemory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    //for loop which copies all the nodes from the doubly linked list to an array
    for (struct Pokemon *ptr = head; ptr != NULL; ptr = ptr->next)
        allNodes[i++] = *ptr;

    //for loop which reverses the doubly linked list of students by swapping the nodes with the nodes in the array
    for (struct Pokemon *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        //swapping the data in the nodes
        ptr->pokemonNum = allNodes[--i].pokemonNum;
        ptr->catchPercentage = allNodes[i].catchPercentage;
        strcpy(ptr->name, allNodes[i].name);
        strcpy(ptr->type, allNodes[i].type);
        strcpy(ptr->region, allNodes[i].region);
        strcpy(ptr->dexEntry, allNodes[i].dexEntry);
        ptr->data->caught = allNodes[i].data->caught;
        ptr->data->seen = allNodes[i].data->seen;
        ptr->data = allNodes[i].data;
    }

    //freeing the dynamically allocated memory for allNodes array
    free(allNodes);

    return head;
}

void writeToFile(const struct Pokemon *head)
{
    //function declarations and initialization
    FILE *fptr;
    const struct Pokemon *ptr = head;

    //opening the file in write mode
    fptr = fopen("pokemons.txt", "w");

    //header that is written to the file
    fprintf(fptr, "=======================================================================================================================\n");
    fprintf(fptr, "                                          Pokémon List                                                                  \n");
    fprintf(fptr, "=======================================================================================================================\n");
    fprintf(fptr, "| %-5s | %-20s | %-12s | %-12s | %-10s | %-6s | %-6s | %-6s | %-6s | %-6s |\n", "Num", "Name", "Type", "Region", "Catch %", "Seen", "Caught", "Atk IV", "Def IV", "Sta IV");
    fprintf(fptr, "=======================================================================================================================\n");

    //for loop which iterates through the linked list and prints the detailed descriptions of each Pokémon
    for (; ptr != NULL; ptr = ptr->next)
        fprintf(fptr, "| %-5d | %-20s | %-12s | %-12s | %-10d | %-6d | %-6d | %-6d | %-6d | %-5.2d%% |\n", ptr->pokemonNum, ptr->name, ptr->type, ptr->region, ptr->catchPercentage, ptr->data->seen, ptr->data->caught, ptr->data->attackIV, ptr->data->defenseIV, ptr->data->staminaIV);

    //closer that is written to the file
    fprintf(fptr, "=======================================================================================================================\n");
    fprintf(fptr, "                                      End of Pokémon List                                                               \n");
    fprintf(fptr, "=======================================================================================================================\n");

    //closing the file
    fclose(fptr);
}   

//function definition for freeTrie which frees the dynamically allocated memory used for the creation of the trie structure
void freeTrie(struct Trie *trie)
{
    //selection statement which evaluates to true if the root of the trie structure is NULL; if so, simply return back to main
    if (trie == NULL)
        return;

    //for loop which iterates over all the children nodes of the current node and recursively frees the dynamically allocated memory for each child node
    for (int i = 0; i < ALPHABET_SIZE; i++)
        //selection statement which evaluates to true if the children nodes of the current node does not equal NULL; if so, recursively call the function to navigate to an inner node within the trie
        if (trie->children[i] != NULL)  
            //calling freeTrie function to free the trie structure
            freeTrie(trie->children[i]);

    //freeing the dynamically allocated memory for the current node
    free(trie);        
}
