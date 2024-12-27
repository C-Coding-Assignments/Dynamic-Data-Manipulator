#include "pokemon.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main()
{
    //random number generator seed
    srand(time(NULL));

    //function declarations and initializations using dynamic memory allocation
    FILE *fptr;
    char name[MAX_NAME_LENGTH], region[MAX_NAME_LENGTH], inputBuffer[MAX_DEX_ENTRY + 1];
    int returnSize, size, pokeBalls = 10, greatBalls = 10, ultraBalls = 10, caught = 0, seen = 0, selection = 0, index;
    bool isValidName = true;
    struct Pokemon *pokemons, *head = NULL;
    struct Trie *trie = NULL;
    struct ListManager *listManager = malloc(sizeof(struct ListManager));
    struct MenuManager *menuManager = malloc(sizeof(struct MenuManager));
    struct TrieManager *trieManager = malloc(sizeof(struct TrieManager));

    //selection statement which evaluates to true if dynamic memory allocation failed for menuManager and/or listManager and/or trieManager
    if (listManager == NULL || menuManager == NULL || trieManager == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    //calling the initializeListManager function and initializing the listManager variable
    initializeListManager(listManager);
    //calling the initializeMenuManager function and initializing the menuManager variable
    initializeMenuManager(menuManager);
    //calling the initializeTrieManager function and initializing the trieManager variable
    initializeTrieManager(trieManager);

    //initializing the root of the trie to validate whether the user has entered a correct name for a Pokémon it has entered
    trie = trieManager->getNodePtr();

    //opening the poke.txt file and reading the Pokémon data
    fptr = fopen("poke.txt", "r");

    //selection statement which checks if the file opened in read mode successfully
    if (fptr == NULL)
    {
        printf("Couldn't open poke.txt");
        exit(EXIT_FAILURE);
    }

    //reading the number of Pokémon entries from the file and validating the input
    returnSize = fscanf(fptr, "%d", &size);

    //selection statement which evaluates to true if the file read in more or less than one element
    if (returnSize != 1)
    {
        printf("Invalid file format.\n");
        exit(EXIT_FAILURE);
    }

    //allocating memory for the Pokémon array
    pokemons = malloc(sizeof(struct Pokemon) * size);

    //selection statement which evaluates to true if memory was not successfully allocated for the dynamic Pokémon array
    if (pokemons == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    //reading the Pokémon data from the file and validating the input
    fgets(inputBuffer, sizeof(inputBuffer), fptr);

    //for loop which iterates throughout the entire file
    for (int i = 0; i < size; i++)
    {
        //reading the data from the file and validating the input
        if (fgets(inputBuffer, sizeof(inputBuffer), fptr) == NULL)
        {
            printf("Error reading poke.txt\n");
            exit(EXIT_FAILURE);
        }
    
        //reading the data from the file
        returnSize = sscanf(inputBuffer, "%d,%99[^,],%99[^,],%99[^,],%d,%[^\n]", &pokemons[i].pokemonNum, pokemons[i].name, pokemons[i].type, pokemons[i].region, &pokemons[i].catchPercentage, pokemons[i].dexEntry);
        
        //selection statement which returns true if the more or less than six elements were read from the file
        if (returnSize != 6)
        {
            printf("Invalid file format.\n");
            exit(EXIT_FAILURE);
        }

        //allocating memory for the status data of each Pokémon
        pokemons[i].data = malloc(sizeof(struct PokemonStatus));
        
        //selection statement which evaluates to true if memory was not successfully allocated for the status data of each Pokémon
        if (pokemons[i].data == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        //initializing the caught and seen attributes for each Pokémon to zero since no Pokémon has been encountered yet    
        pokemons[i].data->caught = 0;
        pokemons[i].data->seen = 0;

        //calling the insertPtr function to initialize a new children tries based on the name of the Pokémon that was just read from the file
        trieManager->insertPtr(trie, pokemons[i].name, &i, trieManager);
    }

    //closing the poke.txt file
    fclose(fptr);

    //do-while loop which iterates until the user enters a name that is at least two characters long
    do
    {
        ///getting the user's name and manipulating the string to remove the new-line character and replace that with a NULL character
        printf("What's your name, trainer? > ");
        fgets(name, sizeof(name), stdin);
        //calling the removeNewline function to remove the new-line character and replace that with a NULL character
        removeNewline(name);

        //selection statement which evaluates to true if the user entered a name that is less than two characters long; if so, an error message is displayed to the screen
        if (strlen(name) < 2)
            printf("Name must be at least two characters.\n\n");
    } while (strlen(name) < 2);

    //welcoming the user to the application
    printf("\nWelcome, %s, to the Programming I Safari Zone!\nYou'll have 30 chances to catch Pokémon, make them count!\n", name);
    printf("The hunt will end when you choose or when you run out of poké balls, great balls, and ultra balls.\nWhich region would you like to visit?\n\n");

    //do-while loop which iterates until the user enters a valid region
    do
    {
        //getting the user's region input
        printf("Enter Kanto, Johto, Hoenn, or Sinnoh > ");
        fgets(region, sizeof(region), stdin);
        //calling the removeNewline function to remove the new-line character and replace that with a NULL character
        removeNewline(region);

        //selection statement which evaluates to true if the user entered an invalid region; if so, an error message is displayed to the screen
        if (!validRegion(region))
            printf("Invalid region. Please enter Kanto, Johto, Hoenn, or Sinnoh.\n\n");
    } while (!validRegion(region));

    printf("\nTraveling to %s\n", region);

    //do-while loop which iterates until the user chooses to exit the application or until the user runs out of balls
    do
    {
        //initializing selection to equal 0 instead of passing 2 to the pokemonCaught function. passing 0 allows for the user to select how it would like to view its caught Pokémon
        selection = 0;

        //calling the menu function to print the menu to the user
        menuManager->menuPtr();
        //calling the getSelection function to get the user's menu selection
        getSelection(inputBuffer);

        //selection statement which evaluates to true if the user has requested to hunt a Pokémon
        if (!strcmp(inputBuffer, "Hunt"))
            //calling the hunt function to have the user encounter a Pokémon, attempt to catch the Pokémon, to update the ball count, and add the Pokémon to the linked list if the Pokémon was caught
            menuManager->huntPtr(region, pokemons, &size, balls, &pokeBalls, &greatBalls, &ultraBalls, &caught, &seen, &head, listManager);

        //selection statement which evaluates to true if the user would like to view its caught Pokémon
        else if (!strcmp(inputBuffer, "Pokemon"))
            //calling the pokemonCaught function to show the user which Pokémon they have successfully caught
            menuManager->pokemonCaughtPtr(head, &selection);   

        //selection statement which evaluates to true if the user would like to sort its caught Pokémon
        else if (!strcmp(inputBuffer, "Sort"))
            //calling the sort function to sort the user's caught Pokémon that are stored in a linked list
            listManager->sortPtr(head, listManager);

        //selection statement which evaluates to true if the user would like to view its Pokémon catching statistics
        else if (!strcmp(inputBuffer, "Stats"))
            //calling the stats function which calculates the player's statistics and prints those to the screen
            menuManager->statsPtr(&caught, &seen);

        //selection statement which evaluates to true if the user would like to view how many of each ball type the user has left before the game ends
        else if (!strcmp(inputBuffer, "Inventory"))
            //calling the inventory function to print out how many of each type of ball the user has
            menuManager->inventoryPtr(&pokeBalls, &greatBalls, &ultraBalls);     
        
        //selection statement which evaluates to true if the user has entered a menu option different than one of the ones; instead, enters a Pokémon's name; if so, print information about the Pokémon by calling the displayPoke function; otherwise, reinitialize isValidName to false so an error message can be printed to the screen indicating that the user entered garbage
        else
        {
            ///ternary expression which evaluates to true if the user entered a Pokémon's name; if so, call the displayPoke function to print information about that Pokémon; otherwise, initialize isValidName to false so an error message can be printed to the screen
            (isValidName = trieManager->searchPtr(trie, inputBuffer, &index, trieManager)) ? (menuManager->displayPokePtr(pokemons, &index)) : (isValidName = false);
            
            //selection statement which evaluates to true if the user entered garbage and if the user entered anything other than Exit; if so, print an error message to the screen indicating that the user entered
            if (!isValidName && strcmp(inputBuffer, "Exit"))
                printf("Invalid entry, try again.\n\n");        
        }                     
    } while (strcmp(inputBuffer, "Exit") && pokeBalls + greatBalls + ultraBalls != 0);

    //calling the writeToFile function to write the user's caught Pokémon to a file named "pokemons.txt" for future reference
    menuManager->writeToFilePtr(head);

    //initializing selection to equal 1 so a detailed description of each Pokémon can be printed to the screen at the end of the program by bypassing the menu and menu options for viewing caught Pokémon
    selection = 1;

    //closing the application with a farewell message and freeing the dynamically allocated memory
    printf("Thanks for playing, %s!\n", name);
    if (head != NULL)
    {
        //calling the pokemonCaught function to print a detailed description of all the user's caught Pokémon
        menuManager->pokemonCaughtPtr(head, &selection);
        //calling the stats function to print out the user's Pokémon catching statistics
        menuManager->statsPtr(&caught, &seen);
        //calling the deleteNodes function to free the dynamically allocated memory from the linked list of caught Pokémon
        head = listManager->deleteNodesPtr(head);
    }

    //calling the freeTrie function to free the dynamically allocated memory within the trie structure
    trieManager->freeTriePtr(trie);

    //freeing the dynamically allocated memory from the pokemons array, listManager, menuManager, and trieManager
    free(pokemons);
    free(listManager);
    free(menuManager);
    free(trieManager);

    return 0;
}
