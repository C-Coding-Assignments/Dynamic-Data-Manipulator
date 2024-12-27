#ifndef POKEMON
#define POKEMON

#include <stdbool.h>
#include <stdio.h>

//macro definition for the maximum number of characters within the user's name
#define MAX_NAME_LENGTH 101
//macro definition for the maximum number of characters within the Pokémon's dex entry
#define MAX_DEX_ENTRY 10001
//macro definition for the number of letters in the alphabet
#define ALPHABET_SIZE 56
//macro definition for the ASCII value of an apostrophe
#define APOSTROPHE 39
//macro definition for the ASCII value of a period
#define PERIOD 46
//macro definition for the character digit two character, '2'
#define TWO '2'
//macro definition for the character hyphen character, '-'
#define HYPHEN '-'
//macro definition for the maximum number of Pokémon in the Kanto region
#define KANTO_MAX_POKEMON 151
//macro definition for the maximum number of Pokémon in the Johto region
#define JOHTO_MAX_POKEMON 100
//macro definition for the maximum number of Pokémon in the Hoenn region
#define HOENN_MAX_POKEMON 135
//macro definition for the maximum number of Pokémon in the Sinnoh region
#define SINNOH_MAX_POKEMON 107
//macro definition for the trie index representing an apostrophe
#define APOSTOPHE_INDEX ALPHABET_SIZE - 4
//macro definition for the trie index representing a period
#define PERIOD_INDEX ALPHABET_SIZE - 3
//macro definition for the trie index representing the integer two
#define TWO_INDEX ALPHABET_SIZE - 2
//macro definition for the trie index representing the hyphen
#define HYPHEN_INDEX ALPHABET_SIZE - 1

//struct definition for Pokemon which defines the attributes that make up an individual Pokémon
struct Pokemon
{
    int pokemonNum, catchPercentage;
    char name[MAX_NAME_LENGTH], type[MAX_NAME_LENGTH], region[MAX_NAME_LENGTH], dexEntry[MAX_DEX_ENTRY];
    struct PokemonStatus *data;
    struct Pokemon *next, *previous;
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
    //adds a Pokémon to the linked list
    struct Pokemon *(*addPtr) (struct Pokemon **, const struct Pokemon *, const int *);
    //sorts the Pokémon in the linked list based on how the user would like the list to be sorted
    struct Pokemon *(*sortPtr) (struct Pokemon *, const struct ListManager *);
    //reverses the Pokémon in the linked list
    struct Pokemon *(*reversePtr) (struct Pokemon *, const struct ListManager *);
    //deletes all the Pokémon in the linked list
    struct Pokemon *(*deleteNodesPtr) (struct Pokemon *);
    //swaps the Pokémon in the linked list according to how the user would like the list to be sorted
    void (*swapPtr) (struct Pokemon *, struct Pokemon *, struct Pokemon *);
};

//struct definition for ListManager which contains the function pointers that are responsible for facilitating the menu operations and calls to functions once the user exits the program
struct MenuManager
{
    //prints the application's main menu to the user
    void (*menuPtr) ();
    //responsible for the functionality of catching Pokémon
    void (*huntPtr) (char *, struct Pokemon *, const int *, void (*) (const int *, const int *, const int *), int *, int *, int *, int *, int *, struct Pokemon **, const struct ListManager *);
    //prints which Pokémon that user has caught
    void (*pokemonCaughtPtr) (const struct Pokemon *, int *);
    //prints the user's catching statistics to the screen
    void (*statsPtr) (const int *, const int *);
    //prints the user's inventory of balls
    void (*inventoryPtr) (const int *, const int *, const int *);
    //displays the Pokémon's information that the user input as a menu selection
    void (*displayPokePtr) (const struct Pokemon *, const int *);
    //writes all the Pokémon that the user has caught to a txt file
    void (*writeToFilePtr) (const struct Pokemon *);
};

//struct definition for Trie which defines a trie structure for storing characters within a string for efficiency
struct Trie
{
    struct Trie *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int index;
};


//struct definition for TrieManager which defines a trie manager structure for efficient Pokémon searching and insertion in the trie
struct TrieManager
{
    //initializes a trie structure for the root of the trie and all child tries
    struct Trie *(*getNodePtr) ();
    //helps determine which index of a trie child structure should be accessed
    int (*getCharIndexPtr) (const char *);
    //inserts a new string within the trie structure
    void (*insertPtr) (struct Trie *, const char *, const int *, const struct TrieManager *);
    //searches a trie structure to see if a string that is passed through the function is within the function. the function then returns a boolean value regarding whether or not that string exists in the trie
    bool (*searchPtr) (struct Trie *, const char *, int *, const struct TrieManager *);
    //frees all the dynamically allocated parent tries and child tries in the structure
    void (*freeTriePtr) (struct Trie *);
};

//function prototype for initializeListManager which initializes the variable of type struct ListManager * in order to apply operations to the list of caught Pokémon
void initializeListManager(struct ListManager *);

//function prototype for initializeListManager which initializes the variable of type struct MenuManager * to run menu options
void initializeMenuManager(struct MenuManager *);

//function prototype for initializeTrieManager which initializes the variable of type struct TrieManager * for efficient searching of Pokémon
void initializeTrieManager(struct TrieManager *);

//function prototype for getNode which creates a Trie root for efficient Pokémon searchin
struct Trie *getNode();

//function prototype for getCharIndex which returns the index of the trie child node needed for the trie structure
int getCharIndex(const char *);

//function prototype for insert which inserts children underneath the parent node
void insert(struct Trie *, const char *, const int *, const struct TrieManager *);

//function prototype for search which searches a Trie for matching Pokémon
bool search(struct Trie *, const char *, int *, const struct TrieManager *); 

//function prototype for assignPokemon which reads the information from poke.txt and assigns the array of type struct Pokémon
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

//function prototype for huntHelper which determines whether the user has successfully caught the Pokémon it is encountering or if the Pokémon has fled
void huntHelper(int *, int *, struct Pokemon *, const int *, int *, int *, struct Pokemon **, const struct ListManager *);

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

//function prototype for freeTrie which frees the dynamically allocated memory within the trie structure
void freeTrie(struct Trie *);

#endif
