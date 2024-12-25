#include "pokemon.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    //function declarations and initializations using dynamic memory allocation
    FILE *fptr;
    char name[MAX_NAME_LENGTH], region[MAX_NAME_LENGTH], temp[MAX_DEX_ENTRY + 1];
    int returnSize, size, pokeBalls = 10, greatBalls = 10, ultraBalls = 10, caught = 0, seen = 0, selection = 0;
    struct Pokemon *pokemons, *head = NULL;
    bool nameInput = true;
    struct ListManager *listManager = malloc(sizeof(struct ListManager));
    struct MenuManager *menuManager = malloc(sizeof(struct MenuManager));

    //selection statement which evaluates to true if dynamic memory allocation failed for menuManager and/or listManager
    if (listManager == NULL || menuManager == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    //calling the initializeListManager function and initializing the listManager variable
    initializeListManager(listManager);
    //calling the initializeMenuManager function and initializing the menuManager variable
    initializeMenuManager(menuManager);

    //function pointer which points to the removeNewline function
    void (*removeNewlinePtr) (char *) = removeNewline;
    //function pointer which points to the validRegion function
    bool (*validRegionPtr) (char *) = validRegion;
    //function pointer which points to getSelection function
    void (*getSelectionPtr) (char *) = getSelection;
    //function pointer which points to pokeBalls function
    void (*pokeBallsPtr) (const int *, const int *, const int *) = balls;

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
    fgets(temp, sizeof(temp), fptr);

    //for loop which iterates throughout the entire file
    for (int i = 0; i < size; i++)
    {
        //reading the data from the file and validating the input
        if (fgets(temp, sizeof(temp), fptr) == NULL)
        {
            printf("Error reading poke.txt\n");
            exit(EXIT_FAILURE);
        }
    
        //reading the data from the file
        returnSize = sscanf(temp, "%d,%99[^,],%99[^,],%99[^,],%d,%[^\n]", &pokemons[i].pokemonNum, pokemons[i].name, pokemons[i].type, pokemons[i].region, &pokemons[i].catchPercentage, pokemons[i].dexEntry);
        
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
    }

    //closing the poke.txt file
    fclose(fptr);

    //getting the user's name and manipulating the string to remove the new-line character and replace that with a NULL character
    printf("What's your name, trainer? > ");
    fgets(name, sizeof(name), stdin);
    //calling the removeNewline function to remove the new-line character and replace that with a NULL character
    removeNewlinePtr(name);

    //welcoming the user to the application
    printf("\nWelcome, %s, to the Programming I Safari Zone!\nYou'll have 30 chances to catch Pokemon, make them count!\n", name);
    printf("The hunt will end when you choose or when you run out of Pokeballs.\nWhich region would you like to visit?\n\n");

    //do-while loop which iterates until the user enters a valid region
    do
    {
        //getting the user's region input
        printf("Enter Kanto, Johto, Hoenn, or Sinnoh > ");
        fgets(region, sizeof(region), stdin);
        //calling the removeNewline function to remove the new-line character and replace that with a NULL character
        removeNewlinePtr(region);
    } while (!validRegionPtr(region));

    printf("\nTraveling to %s\n", region);

    //do-while loop which iterates until the user chooses to exit the application
    do
    {
        //initializing selection to equal 0 so printing menu appears when user wants to display its caught Pokémon
        selection = 0;

        //calling the menu function to print the menu to the user
        menuManager->menuPtr();
        //calling the getSelection function to get the user's menu selection
        getSelectionPtr(temp);

        //selection statement which evaluates to true if the user enters Hunt
        if (!strcmp(temp, "Hunt"))
            //calling the hunt function to facilitate the program's Hunt option
            menuManager->huntPtr(region, pokemons, &size, pokeBallsPtr, &pokeBalls, &greatBalls, &ultraBalls, &caught, &seen, &head, listManager);

        //selection statement which evaluates to true if the user enters Pokemon
        else if (!strcmp(temp, "Pokemon"))
            //calling the Pokemon function to facilitate the program's Pokemon option
            menuManager->pokemonCaughtPtr(head, &selection);   

        //selection statement which evaluates to true if the user enters Sort
        else if (!strcmp(temp, "Sort"))
            //calling the sort function to sort the user's caught Pokemon
            listManager->sortPtr(head, listManager);

        //selection statement which evaluates to true if the user enters Stats
        else if (!strcmp(temp, "Stats"))
            //calling the stats function which calculates the player's statistics
            menuManager->statsPtr(&caught, &seen);

        //selection statement which evaluates to true if the user enters Inventory
        else if (!strcmp(temp, "Inventory"))
            //calling the inventory function to print out how many of each type of ball the user has
            menuManager->inventoryPtr(&pokeBalls, &greatBalls, &ultraBalls);     
        
        //selection statement which evaluates to true if the user enters any other string that does not match the ones above
        else
        {
            nameInput = false;

            //for loop which iterates through all characters in the user's input and converts them to different cases
            for (char *ptr = temp; *ptr != '\0'; ptr++)
                //ternary expression which evaluates to try if ptr points to the first character in temp; if so, convert the first character to uppercase; otherwise, convert the rest of the characters to lowercase
                (ptr == temp) ? (*ptr = toupper(*ptr)) : (*ptr = tolower(*ptr));
        
            //for loop which iterates through all elements within the pokemons array
            for (int i = 0; i < size; i++)
                //selection statement which evaluates to true if the user entered a Pokemon's name
                if (!strcmp(temp, pokemons[i].name))
                {
                    //calling the displayPoke function which will print out information about the Pokemon that the user entered
                    menuManager->displayPokePtr(pokemons, &i);  
                    nameInput = true;
                    break;
                }  

            if (!nameInput && strcmp(temp, "Exit"))
                printf("Invalid entry, try again.\n\n");        
        }                     
    } while (strcmp(temp, "Exit") && pokeBalls + greatBalls + ultraBalls != 0);

    //calling the writeToFile function to write the user's caught Pokémon to a file named "pokemons.txt" for future reference
    menuManager->writeToFilePtr(head);

    //initializing selection to equal 1 so a detailed description of each Pokémon can be printed to the screen at the end of the program
    selection = 1;

    //closing the application with a farewell message and freeing the dynamically allocated memory
    printf("Thanks for playing, %s!\n", name);
    if (head != NULL)
    {
        //calling the pokemonCaught function to print the Pokemon that the user has caught
        menuManager->pokemonCaughtPtr(head, &selection);
        //calling the stats function to print out the user's stats
        menuManager->statsPtr(&caught, &seen);
        //calling the deleteNodes function to free the dynamically allocated memory from the linked list of caught Pokémon
        head = listManager->deleteNodesPtr(head);
    }

    //freeing the dynamically allocated memory from the pokemons array, listManager, and menuManager
    free(pokemons);
    free(listManager);
    free(menuManager);

    return 0;
}
