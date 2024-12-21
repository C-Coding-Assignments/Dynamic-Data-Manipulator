//header file
#include "pokemon.h"

//C libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//function pointer which points to the removeNewline function
void (*removeNewlinePtr) (char *) = removeNewline;

//function pointer which points to the balls function
void (*ballsPtr) (const int *, const int *, const int *) = balls;

//function pointer which points to the pokeCaught function
struct Pokemon *(*pokeCaughtPtr) (struct Pokemon *, const int *, int *, int *, struct Pokemon **, const struct PokemonManager *) = pokeCaught;

//function pointer which points to the pokeRan function
void (*pokeRanPtr) (struct Pokemon *, const int *, int *) = pokeRan;

//function pointer which points to the sortMenu function
int (*sortMenuPtr) () = sortMenu;

//function definition for removeNewline which removes the new-line characters from the string and replaces them with the null character
void removeNewline(char *name)
{
    //for loop which iterates through the string until the first null-character is being pointed to by ptr and replaces each new-line character with the null character
    for (char *ptr = name; *ptr != '\0'; ptr++)
        //selection statement which evaluates to true if *ptr points to a new-line character; if so, it replaces the new-line character with a null character
        if (*ptr == '\n')
            *ptr = '\0';
}

//function defintion for validRegion which determines if the user entered a valid region
bool validRegion(char *region)
{
    //converting first character in region to upper case
    *region = toupper(*region);

    //for loop which iterates through all characters within region, converts the remainder of characters to lower case, and converts any new-line characters to NULL characters
    for (char *ptr = region + 1; *ptr != '\0'; *ptr = tolower(*ptr), ptr++);
    removeNewlinePtr(region);

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
    //getting the user's input
    printf("Selection > ");
    fgets(input, MAX_DEX_ENTRY, stdin);
    //removing the newline character from the user's input
    removeNewlinePtr(input); 

    //for loop which iterates through the user's input, converts the first character in the user's input to upper case, converts the remainder of the user's input to lower case, and converts any new-line characters to NULL characters
    for (char *ptr = input; *ptr != '\0'; ptr++)
        //ternary expression which evaluates to true if ptr points to the first character in the user's input; if so, make the first character uppercase; otherwise, make the rest of the characters lowercase
        (ptr == input) ? (*ptr = toupper(*ptr)) : (*ptr = tolower(*ptr));   
}   

//function definition for hunt which facilitates the Hunt menu option for catching Pokémon
void hunt(char *region, struct Pokemon *pokemons, const int *size, void (*balls) (const int *, const int *, const int *), int *pokeBalls, int *greatBalls, int *ultraBalls, int *caught, int *seen, struct Pokemon **head, const struct PokemonManager *manager)
{
    //random number generator seed
    srand(time(NULL));

    //variable declarations and initialization
    int randomNum, catchNum = rand() % 100 + 1, selectedBall;
    char temp[MAX_DEX_ENTRY];

    removeNewlinePtr(region);

    //selection statement which evaluates to true if region is equal to Kanto; if so, generate a random number between 1 and 151 (inclusive)
    if (!strcmp(region, "Kanto"))
        randomNum = rand() % 151 + 1;
    //selection statement which evaluates to true if region is equal to Johto; if so, generate a random number between 152 and 251 (inclusive)
    else if (!strcmp(region, "Johto"))
        randomNum = rand() % 100 + 152;
    //selection statement which evaluates to true if region is equal to Hoenn; if so, generate a random number between 252 and 386 (inclusive)
    else if (!strcmp(region, "Hoenn")) 
        randomNum = rand() % 135 + 252;
    //selection statement which evaluates to true if region is equal to Sinnoh; if so, generate a random number between 387 and 493 (inclusive)
    else
        randomNum = rand() % 107 + 387;

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
        ballsPtr(pokeBalls, greatBalls, ultraBalls);    
        
        //getting the user's input and then converting the user's input into an integer using the atoi function within the stdlib library
        printf("Choose ball (1, 2, or 3) > ");    
        fgets(temp, sizeof(temp), stdin);
        selectedBall = atoi(temp);

        //selection statement which evaluates to true if the user has chosen a Poké Ball and if the user has more than zero Poké Balls
        if (selectedBall == 1 && *pokeBalls > 0)
        {
            printf("\nThrew a Poké Ball!\n");

            //decrementing the number of Pokéballs the user has since one of them was used in the attempt to catch the Pokémon
            (*pokeBalls)--;

            //ternary expression which evaluates to true if the randomly generated integer, catchNum, is greater than the catch percentage of the Pokémon at index randomNum; if so, call the pokeCaught function which facilitates the catching process; otherwise, call the pokeRan function which facilitates the Pokémon fleeing process
            (catchNum <= pokemons[randomNum].catchPercentage) ? (pokeCaughtPtr(pokemons, &randomNum, caught, seen, head, manager)) : (pokeRanPtr(pokemons, &randomNum, seen));
        }

        //selection statement which evaluates to true if the user has chosen a Great Ball and if the user has more than one Great Ball    
        else if (selectedBall == 2 && *greatBalls > 0)
        {
            printf("\nThrew a greatBall!\n");

            //decrementing the number of Great Balls the user has since one of them was used in the attempt to catch the Pokémon
            (*greatBalls)--;

            //ternary expression which evaluates to true if the randomly generated integer, catchNum, is greater than the catch percentage of the Pokémon at index randomNum plus 20 since the Great Ball increases the chance of catching the Pokémon; if so, call the pokeCaught function which facilitates the catching process; otherwise, call the pokeRan function which facilitates the Pokémon fleeing process
            (catchNum <= pokemons[randomNum].catchPercentage + 20) ? (pokeCaughtPtr(pokemons, &randomNum, caught, seen, head, manager)) : (pokeRanPtr(pokemons, &randomNum, seen));
        }

        //selection statement which evaluates to true if the user has chosen an Ultra Ball and if the user has more than one Ultra Ball
        else if (selectedBall == 3 && *ultraBalls > 0)
        {
            printf("\nThrew an Ultra Ball!\n");

            //decrementing the number of Ultra Balls the user has since one of them was used in the attempt to catch the Pokémon
            (*ultraBalls)--;

            //ternary expression which evaluates to true if the randomly generated integer, catchNum, is greater than the catch percentage of the Pokémon at index randomNum plus 40 since the Ultra Ball increases the chance of catching the Pokémon; if so, call the pokeCaught function which facilitates the catching process; otherwise, call the pokeRan function which facilitates the Pokémon fleeing process
            (catchNum <= pokemons[randomNum].catchPercentage + 40) ? (pokeCaughtPtr(pokemons, &randomNum, caught, seen, head, manager)) : (pokeRanPtr(pokemons, &randomNum, seen));
        }

        //selection statement which evaluates to true if the user has chosen to throw a Poké Ball, but the user has zero Poké Balls
        else if (selectedBall == 1 && *pokeBalls == 0)
            printf("\nYou don't have any Poké Balls.\n");

        //selection statement which evaluates to true if the user has chosen to throw a Great Ball, but the user has zero Great Balls
        else if (selectedBall == 2 && *greatBalls == 0)
            printf("\nYou don't have any Great Balls.\n");

        //selection statement which evaluates to true if the user has chosen to throw an Ultra Ball, but the user has zero Ultra Balls
        else if (selectedBall == 3 && *ultraBalls == 0)
            printf("\nYou don't have any Ultra Balls.\n");

        //selection statement which evaluates to true if the user has chosen an invalid option
        else
            printf("\nInvalid input. Please try again.\n");
    } while (selectedBall != 1 && selectedBall != 2 && selectedBall != 3);
}

//function defintion for balls which prints a neat display of how many Poké Balls, Great Balls, and Ultra Balls the user currently has
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
struct Pokemon *pokeCaught(struct Pokemon *pokemons, const int *random, int *caught, int *seen, struct Pokemon **head, const struct PokemonManager *manager)
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

//function defintion for pokemonCaught which displays all the Pokémon that the user has caught
void pokemonCaught(const struct Pokemon *head)
{
    //variable declaration and initialization
    const struct Pokemon *ptr = head;
    int counter = 1;

    //selection statement which evaluates to true if the user has yet to catch any Pokémon
    if (head == NULL)
        printf("\nYou have not caught any pokémon yet!\n\n");

    //selection statement which evaluates to true if the user has caught at least one Pokémon
    else
    {
        printf("\n==== Your Caught Pokémon ====\n");

        //for loop which iterates through the linked list and prints each of the Pokémons' name
        for (; ptr != NULL; ptr = ptr->next)
            printf("%d. %s\n", counter++, ptr->name);

        //printing the total number of Pokémons caught
        printf("===============================\nTotal Pokémon Caught: %d\n\n", --counter);
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

//function defintion for sortMenu which prints the sorting menu
int sortMenu()
{
    //variable declarations
    char temp[MAX_DEX_ENTRY];
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
        fgets(temp, sizeof(temp), stdin);
        selection = atoi(temp);
    } while (selection < 1 || selection > 6);
    
    //returning the selected sorting option
    return selection;
}

//function definiton for sort which is responsible for sorting the linked list of Pokémon caught
struct Pokemon *sort(struct Pokemon *head, const struct PokemonManager *manager)
{
    //variable declarations and initializations using dynamically allocated memory 
    int selection;
    struct Pokemon *ptr = head, *ptr2 = head;
    
    //selection statement which evaluates to true if the head of the linked list is NULL, meaning there are no nodes within the linked list; if so, return NULL
    if (head == NULL)
    {
        printf("\nThere are no Pokémon to sort since you have not caught any yet.\n\n");

        return NULL;
    }    
    
    //getting the user's input for which type of sorting to take place on the linked list
    selection = sortMenuPtr();

    //selection statement which evaluates to true if the user requested to sort their caught Pokémon lexicographically, in ascending order
    if (selection == 1)
    {   
        //nested for loop responsible for swapping nodes within the linked list
        for (; ptr != NULL; ptr = ptr->next)
            for (ptr2 = ptr->next; ptr2 != NULL;)
                //ternary expression which evaluates to true if the name of the Pokémon that ptr2 points to comes before the name of the Pokémon that ptr points to; if so, call the swap function to swap the Pokémon within the list; otherwise, traverse to the next node
                (strcmp(ptr->name, ptr2->name) > 0) ? (manager->swapPtr(ptr, ptr2, head), ptr = head, ptr2 = ptr->next) : (ptr2 = ptr2->next);

        printf("\nYour Pokémon were successfully sorted lexicographically (ascending)!\n\n");
    }

    //selection statement which evaluates to true if the user requested to sort their caught Pokémon lexicographically, in descending order
    else if (selection == 2)
    {   
        //nested for loop responsible for swapping nodes within the linked list
        for (; ptr != NULL; ptr = ptr->next)
            for (ptr2 = ptr->next; ptr2 != NULL;)
                //ternary expression which evaluates to true if the name of the Pokémon that ptr points to comes before the name of the Pokémon that ptr2 points to; if so, call the swap function to swap the Pokémon within the list; otherwise, traverse to the next node
                (strcmp(ptr2->name, ptr->name) > 0) ? (manager->swapPtr(ptr, ptr2, head), ptr = head, ptr2 = ptr->next) : (ptr2 = ptr2->next);

        printf("\nYour Pokémon were successfully sorted lexicographically (descending)!\n\n");
    }

    //selection statement which evaluates to true if the user requested to sort their caught Pokémon by type
    else if (selection == 3)
    {
        //nested for loop responsible for swapping nodes within the linked list
        for (; ptr != NULL; ptr = ptr->next)
            for (ptr2 = ptr->next; ptr2 != NULL;)
                //ternary expression which evaluates to true if the type of the Pokémon that ptr2 points to comes before the type of the Pokémon that ptr points to; if so, call the swap function to swap the Pokémon within the list; otherwise, traverse to the next node
                (strcmp(ptr->type, ptr2->type) > 0) ? (manager->swapPtr(ptr, ptr2, head), ptr = head, ptr2 = ptr->next) : (ptr2 = ptr2->next);

        printf("\nYour Pokémon were successfully sorted by region!\n\n");        
    }

    //selection statement which evaluates to true if the user requested to sort their caught Pokémon by Pokémon number, in ascending order
    else if (selection == 4)
    {
        //nested for loop responsible for swapping nodes within the linked list
        for (; ptr != NULL; ptr = ptr->next)
            for (ptr2 = ptr->next; ptr2 != NULL;)
                //ternary expression which evaluates to true if the Pokémon number associated with the Pokémon that ptr2 points to is greater than the Pokémon number associated with the Pokémon that ptr points to; if so, call the swap function to swap the Pokémon within the list; otherwise, traverse to the next node
                (ptr2->pokemonNum > ptr->pokemonNum) ? (manager->swapPtr(ptr, ptr2, head), ptr = head, ptr2 = ptr->next) : (ptr2 = ptr2->next);

        printf("\nYour Pokémon were successfully sorted number (ascending)!\n\n");        
    }

    //selection statement which evaluates to true if the user requested to sort their caught Pokémon by Pokémon number, in descending order
    else if (selection == 5)
    {
        //nested for loop responsible for swapping nodes within the linked list
        for (; ptr != NULL; ptr = ptr->next)
            for (ptr2 = ptr->next; ptr2 != NULL;)
                //ternary expression which evaluates to true if the Pokémon number associated with the Pokémon that ptr2 points to is greater than the Pokémon number associated with the Pokémon that ptr points to; if so, call the swap function to swap the Pokémon within the list; otherwise, traverse to the next node
                (ptr2->pokemonNum < ptr->pokemonNum) ? (manager->swapPtr(ptr, ptr2, head), ptr = head, ptr2 = ptr->next) : (ptr2 = ptr2->next);

        printf("\nYour Pokémon were successfully sorted number (ascending)!\n\n");        
    }

    //selection statement which evaluates to true if the user requested to reverse the order of their caught Pokémon
    else if (selection == 6)
    {
        //calling the reverse function to reverse the Pokémon within the list
        head = manager->reversePtr(head, manager);

        printf("\nYour Pokémon were successfully sorted in reverse!\n\n");
    }    

    //selection statement which evaluates to true if the user requested to sort their caught Pokémon by Pokémon number, in descending order
    else
    {
        //nested for loop responsible for swapping nodes within the linked list
        for (; ptr != NULL; ptr = ptr->next)
            for (ptr2 = ptr->next; ptr2 != NULL;)
                //ternary expression which evaluates to true if the Pokémon number associated with the Pokémon that ptr2 points to is less than the Pokémon number associated with the Pokémon that ptr points to; if so, call the swap function to swap the Pokémon within the list; otherwise, traverse to the next node
                (ptr->pokemonNum > ptr2->pokemonNum) ? (manager->swapPtr(ptr, ptr2, head), ptr = head, ptr2 = ptr->next) : (ptr2 = ptr2->next);

        printf("\nYour Pokémon were successfully sorted number (descending)!\n\n");        
    }

    //returning the head of the sorted linked list
    return head;
}

//function definiton for deleteNodes which is responsible for freeing the dynamically allocated memory for all nodes within the linked list
struct Pokemon *deleteNodes(struct Pokemon *head)
{
    //variable declaration and initialization
    struct Pokemon *temp = head;

    //while loop which traverses the linked list and frees each node that has been dynamically allocated
    while (temp != NULL)
    {
        temp = head->next;
        free(temp);
        head = temp;
    }

    //returning NULL after all nodes have been freed
    return NULL;
}

//function definition for swap which facilitates the sorting of the linked list
void swap(struct Pokemon *ptr, struct Pokemon *ptr2, struct Pokemon *head)
{
    //variable declaration and initialization using dynamically allocated memory
    struct Pokemon *temp = malloc(sizeof(struct Pokemon));

    //swapping the data members of the two nodes
    strcpy(temp->name, ptr->name);
    strcpy(temp->type, ptr->type);
    strcpy(temp->dexEntry, ptr->dexEntry);
    strcpy(temp->region, ptr->region);
    temp->pokemonNum = ptr->pokemonNum;
    temp->catchPercentage = ptr->catchPercentage;

    //swapping the data members of the two nodes
    strcpy(ptr->name, ptr2->name);
    strcpy(ptr->type, ptr2->type); 
    strcpy(ptr->dexEntry, ptr2->dexEntry);
    strcpy(ptr->region, ptr2->region);
    ptr->pokemonNum = ptr2->pokemonNum;
    ptr->catchPercentage = ptr2->catchPercentage;

    //swapping the data members of the two nodes
    strcpy(ptr2->name, temp->name);
    strcpy(ptr2->type, temp->type);
    strcpy(ptr2->dexEntry, temp->dexEntry);
    strcpy(ptr2->region, temp->region);
    ptr2->pokemonNum = temp->pokemonNum;
    ptr2->catchPercentage = temp->catchPercentage;

    //freeing the dynamically allocated memory for the temporary node
    free(temp);
}

//function definition for reverse which reverses the nodes within the doubly linked list
struct Pokemon *reverse(struct Pokemon *head, const struct PokemonManager *manager)
{
    //variable declarations and initializations
    struct Pokemon *ptr = head, *ptr2 = head, *temp = malloc(sizeof(struct Pokemon));
    int nodes = 1;

    //for loop which counts the number of nodes in the list
    for (; ptr2->next != NULL; ptr2 = ptr2->next, nodes++);

    //for loop which iterates through the nodes in the list, swaps the list to be in reverse, reassigns the pointers, and frees the dynamically allocated memory
    for (int i = 0; i < nodes / 2; manager->swapPtr(ptr, ptr2, head), ptr = ptr->next, ptr2 = ptr2->previous, free(temp), i++);

    //returning the head of the reversed linked list
    return head;
}

void writeToFile(const struct Pokemon *head)
{
    //function declarations
    FILE *fptr;
    const struct Pokemon *ptr = head;

    //opening the file in write mode
    fptr = fopen("pokemons.txt", "w");

    //writing the header row to the file
    fprintf(fptr, "==========================================================================================================================================================================================================================================\n");
    fprintf(fptr, "                                Pokémon List                                  \n");
    fprintf(fptr, "==========================================================================================================================================================================================================================================\n");

    //for loop which iterates through the linked list and writes each of the user's caught Pokémon to the file
    for (; ptr != NULL; ptr = ptr->next)
    {
        //printing Pokémons' information to the file
        fprintf(fptr, "| %-5s | %-20s | %-12s | %-12s | %-10s | %-35s |\n", "Num", "Name", "Type", "Region", "Catch %", "Dex Entry");
        fprintf(fptr, "==========================================================================================================================================================================================================================================\n");
        fprintf(fptr, "| %-5d | %-20s | %-12s | %-12s | %-10d | %-35s |\n", ptr->pokemonNum, ptr->name, ptr->type, ptr->region, ptr->catchPercentage, ptr->dexEntry);
        fprintf(fptr, "| %-5s | %-20s | %-12s | %-12s | %-10s | Seen: %-4d  Caught: %-4d             |\n", "", "", "", "", "", ptr->data->seen, ptr->data->caught);
        fprintf(fptr, "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    //printing the footer to the file
    fprintf(fptr, "==========================================================================================================================================================================================================================================\n");
    fprintf(fptr, "                            End of Pokémon List                               \n");
    fprintf(fptr, "==========================================================================================================================================================================================================================================\n");

    //closing the file
    fclose(fptr);
}   
