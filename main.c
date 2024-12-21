//header file
#include "pokemon.h"

//C libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    //function declarations and initializations
    FILE *fptr;
    char name[MAX_NAME_LENGTH], region[MAX_NAME_LENGTH], temp[MAX_DEX_ENTRY + 1];
    int returnSize, size, pokeBalls = 10, greatBalls = 10, ultraBalls = 10, caught = 0, seen = 0;
    struct Pokemon *pokemons, *head = NULL;
    bool nameInput = true;
    struct PokemonManager manager = {add, sort, reverse, deleteNodes, swap};

    //function pointer which points to the removeNewline function
    void (*removeNewlinePtr) (char *) = removeNewline;
    //function pointer which points to the validRegion function
    bool (*validRegionPtr) (char *) = validRegion;
    //function pointer which points to the menu function
    void (*menuPtr) () = menu;
    //function pointer which points to getSelection function
    void (*getSelectionPtr) (char *) = getSelection;
    //function pointer which points to pokeBalls function
    void (*pokeBallsPtr) (const int *, const int *, const int *) = balls;
    //function pointer which points to the hunt function
    void (*huntPtr) (char *, struct Pokemon *, const int *, void (*) (const int *, const int *, const int *), int *, int *, int *, int *, int *, struct Pokemon **, const struct PokemonManager *) = hunt;
    //function pointer which points to the pokemonCaught function
    void (*pokemonCaughtPtr) (const struct Pokemon *) = pokemonCaught;
    //function pointer which points to the stats function
    void (*statsPtr) (const int *, const int *) = stats;
    //function pointer which points to inventory function
    void (*inventoryPtr) (const int *, const int *, const int *) = inventory;
    //function pointer which points to displayPoke function
    void (*displayPokePtr) (const struct Pokemon *, const int *) = displayPoke;
    //function pointer which points to writeToFile function
    void (*writeToFilePtr) (const struct Pokemon *) = writeToFile;

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
        printf("Enter Kanto, Johto, Hoenn, or Sinnoh > ");
        fgets(region, sizeof(region), stdin);
        //calling the removeNewline function to remove the new-line character and replace that with a NULL character
        removeNewlinePtr(region);
    } while (!validRegionPtr(region));

    printf("\nTraveling to %s\n", region);

    //do-while loop which iterates until the user chooses to exit the application
    do
    {
        //calling the menu function to print the menu to the user
        menuPtr();
        //calling the getSelection function to get the user's menu selection
        getSelectionPtr(temp);

        //selection statement which evaluates to true if the user enters Hunt
        if (!strcmp(temp, "Hunt"))
            //calling the hunt function to facilitate the program's Hunt option
            huntPtr(region, pokemons, &size, pokeBallsPtr, &pokeBalls, &greatBalls, &ultraBalls, &caught, &seen, &head, &manager);

        //selection statement which evaluates to true if the user enters Pokemon
        else if (!strcmp(temp, "Pokemon"))
            //calling the Pokemon function to facilitate the program's Pokemon option
            pokemonCaughtPtr(head);   

        //selection statement which evaluates to true if the user enters Sort
        else if (!strcmp(temp, "Sort"))
            //calling the sort function to sort the user's caught Pokemon
            manager.sortPtr(head, &manager);

        //selection statement which evaluates to true if the user enters Stats
        else if (!strcmp(temp, "Stats"))
            //calling the stats function which calculates the player's statistics
            statsPtr(&caught, &seen);

        //selection statement which evaluates to true if the user enters Inventory
        else if (!strcmp(temp, "Inventory"))
            //calling the inventory function to print out how many of each type of ball the user has
            inventoryPtr(&pokeBalls, &greatBalls, &ultraBalls);     
        
        //selection statement which evaluates to true if the user enters any other string that does not match the ones above
        else
        {
            nameInput = false;

            //for loop which iterates through all characters in the user's input and converts them to different cases
            for (char *ptr = temp; *ptr != '\0'; ptr++)
                //ternary expression which evaluates to try if ptr points to the first character in temp; if so, convert the first character to uppercase; otherwise, convert the rest of the characters to lowercase
                (ptr == temp) ? (*ptr = toupper(*ptr)) : (*ptr = tolower(*ptr));
        
            //for loop which iterates through all elements within the pokemons function
            for (int i = 0; i < size; i++)
                //selection statement which evaluates to true if the user entered a Pokemon's name
                if (!strcmp(temp, pokemons[i].name))
                {
                    //calling the displayPoke function which will print out information about the Pokemon that the user entered
                    displayPokePtr(pokemons, &i);  
                    nameInput = true;
                    break;
                }  

            if (!nameInput)
                printf("Invalid entry, try again.\n\n");        
        }                     
    } while (strcmp(temp, "Exit"));

    //calling the writeToFile function to write the user's caught Pokémon to a file named "pokemons.txt" for future reference
    writeToFile(head);

    //closing the application with a farewell message and freeing the dynamically allocated memory
    printf("\nThanks for playing, %s!\n", name);
    if (head != NULL)
    {
        //calling the pokemonCaught function to print the Pokemon that the user has caught
        pokemonCaughtPtr(head);
        //calling the stats function to print out the user's stats
        statsPtr(&caught, &seen);
        //calling the deleteNodes function to free the dynamically allocated memory from the linked list of caught Pokémon
        head = manager.deleteNodesPtr(head);
    }

    //freeing the dynamically allocated memory from the pokemons array
    free(pokemons);

    return 0;
}
