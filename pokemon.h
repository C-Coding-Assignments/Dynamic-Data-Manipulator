#ifndef POKEMON
#define POKEMON

#include <stdbool.h>
#include <stdio.h>

//macro definition for the maximum number of characters within the user's name
#define MAX_NAME_LENGTH 101
//macro definition for the maximum number of characters within the Pokémon's dex entry
#define MAX_DEX_ENTRY 10001

//struct definition for Pokemon which defines the attributes that make up an individual Pokémon
struct Pokemon
{
    int pokemonNum, catchPercentage;
    char name[MAX_NAME_LENGTH], type[MAX_NAME_LENGTH], region[MAX_NAME_LENGTH], dexEntry[MAX_DEX_ENTRY];
    struct PokemonStatus *data;
    struct Pokemon *next;
    struct Pokemon *previous;
};


//struct definition for PokemonStatus which defines that a Pokémon can be either caught, seen, or both and defines the individual values of each Pokémon
struct PokemonStatus
{
    int caught, seen, attackIV, defenseIV, staminaIV;
    double percentIV;
};

//struct definition for ListManager which contains the function pointers that are responsible for manipulating the linked list containing all the Pokémon that the user has caught
struct ListManager
{
    //function pointer which points to the add function
    struct Pokemon *(*addPtr) (struct Pokemon **, const struct Pokemon *, const int *);
    //function pointer which points to the sort function
    struct Pokemon *(*sortPtr) (struct Pokemon *, const struct ListManager *);
    //function pointer which points to the reverse function
    struct Pokemon *(*reversePtr) (struct Pokemon *, const struct ListManager *);
    //function pointer which points to the deleteNodes function
    struct Pokemon *(*deleteNodesPtr) (struct Pokemon *);
    //function pointer which points to the swap function
    void (*swapPtr) (struct Pokemon *, struct Pokemon *, struct Pokemon *);
};

//struct definition for ListManager which contains the function pointers that are responsible for facilitating the menu operations and calls to functions once the user exits the program
struct MenuManager
{
    //function pointer which points to the menu function
    void (*menuPtr) ();
    //function pointer which points to the hunt function
    void (*huntPtr) (char *, struct Pokemon *, const int *, void (*) (const int *, const int *, const int *), int *, int *, int *, int *, int *, struct Pokemon **, const struct ListManager *);
    //function pointer which points to the sortMenu function
    void (*pokemonCaughtPtr) (const struct Pokemon *, int *);
    //function pointer which points to the stats function
    void (*statsPtr) (const int *, const int *);
    //function pointer which points to the inventory function
    void (*inventoryPtr) (const int *, const int *, const int *);
    //function pointer which points to the displayPoke function
    void (*displayPokePtr) (const struct Pokemon *, const int *);
    //function pointer which points to the writeToFile function
    void (*writeToFilePtr) (const struct Pokemon *);
};

//function prototype for initializeListManager which initializes the variable of type struct ListManager * in order to apply operations to the list of caught Pokémon
void initializeListManager(struct ListManager *);

//function prototype for initializeListManager which initializes the variable of type struct MenuManager * to run menu options
void initializeMenuManager(struct MenuManager *);

//function prototype for assignPokemon which reads the information from poke.txt and assigns the array of type struct Pokemon
void assignPokemon(FILE *, int *, struct Pokemon **);

//function prototype for removeNewline which removes new-line characters from a string
void removeNewline(char *);

//function prototype for validRegion which is responsible for getting the user's input and returning a boolean value whether the user entered a valid Pokémon region it would like to play in
bool validRegion(char *);

//function prototype for menu which prints a neat menu of player options
void menu();

//function prototype for getSelection which is responsible for getting the user's menu selection and manipulating the string into a friendly format
void getSelection(char *);

//function prototype for hunt which facilitates the hunt menu option. This function provides the functionality for the Pokémon catching process
void hunt(char *, struct Pokemon *, const int *, void (*) (const int *, const int *, const int *), int *, int *, int *, int *, int *, struct Pokemon **, const struct ListManager *);

//function prototype for balls which prints a neat display and informing the user about how many of each type of ball it has within its inventory
void balls(const int *, const int *, const int *);

//function prototype for add which appends a newly caught Pokémon to the end of a linked list
struct Pokemon *add(struct Pokemon **, const struct Pokemon *, const int *);

//function prototype for pokeCaught which facilitates the catching process and updates the user's inventory
struct Pokemon *pokeCaught(struct Pokemon *, const int *, int *, int *, struct Pokemon **, const struct ListManager *);

//function prototype for pokeRan which facilitates the fleeing process and updates the user's inventory
void pokeRan(struct Pokemon *, const int *, int *);

//function prototype for pokemonCaught which displays all the Pokémon which the user has caught
void pokemonCaught(const struct Pokemon *, int *);

//function prototype for stats which prints the user's catch statistics in a neat format
void stats(const int *, const int *);

//function prototype for inventory which prints the user's inventory in a neat format
void inventory(const int *, const int *, const int *);

//function prototype for displayPoke which displays the details of a single Pokémon in a neat format
void displayPoke(const struct Pokemon *, const int *);

//function prototype for sortMenu which prints a neat menu of sorting options
int sortMenu();

//function prototype for sort which sorts the linked list of Pokémon based on the user's selection
struct Pokemon *sort(struct Pokemon *, const struct ListManager *);

//function prototype for deleteNodes which deletes all the nodes within the linked list
struct Pokemon *deleteNodes(struct Pokemon *);

//function prototype for swap which swaps two nodes within the linked list based on the user's selection of sorting criteria and order (ascending or descending)
void swap(struct Pokemon *, struct Pokemon *, struct Pokemon *);

//function prototype for reverse which reverses the linked list of Pokémon
struct Pokemon *reverse(struct Pokemon *, const struct ListManager *);

//function prototype for writeToFile which writes the linked list of Pokémon and stores the information in the file given by the file pointer
void writeToFile(const struct Pokemon *);

#endif
