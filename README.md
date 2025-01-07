<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<header>
  <h1>Dynamic Data Manipulator 🛠️</h1>
  <p>
    This advanced C programming project showcases mastery of complex programming concepts, including data manipulation, pointer arithmetic, file handling, and dynamic memory management. The project consists of three intricately linked programs, each designed to demonstrate practical problem-solving and efficient algorithm design in C.
  </p>
  <h2>How to Run the Code</h2>
<p>To make it easy for you to run the code, I’ve created an account on Online GDB, a convenient online compiler. Below are the login details:</p>
<ul>
  <li><strong>Email:</strong> egarrett055@gmail.com</li>
  <li><strong>Password:</strong> tempUser</li>
</ul>
<p>Follow these steps to run the program:</p>
<ol>
  <li>Click <a href="https://www.onlinegdb.com/edit/CWdpI3IrF" target="_blank">here</a> to open the project.</li>
  <li>Enter the login credentials provided above (email and password).</li>
  <li>On the left side of the page, click on <strong>"My Projects"</strong>.</li>
  <li>Find and select the project titled <strong>"Dynamic Data Manipulator"</strong>.</li>
  <li>Click on the <strong>"Dynamic Data Manipulator"</strong> project to open it.</li>
  <li>Inside the project, locate and click the file named <strong>"main.c"</strong>.</li>
  <li>Click the <strong>"Run"</strong> button to execute the program.</li>
  <li>If prompted, select "C" from the "Language" dropdown near the top of the screen to proceed.</li>
  <li>The program’s output will appear at the bottom of the screen, allowing you to experience the results of my work.</li>
</ol>
<p>Enjoy exploring the program!</p>
</header>

<hr>

<details>
  <summary>Table of Contents 📖</summary>
  <ul>
    <li><a href="#overview">Overview</a></li>
    <li><a href="#features">Key Features</a></li>
    <li><a href="#structure-explanations">Structure Explanations</a></li>
    <li><a href="#function-explanations">Function Explanations</a></li>
    <li><a href="#usage">Usage</a></li>
  </ul>
</details>

<hr>

<section id="overview">
  <h2>Overview 📋</h2>
  <p>
    The <strong>Dynamic Data Manipulator</strong> is a set of three advanced programs that demonstrate a wide range of C programming skills:
  </p>
  <ul>
    <li><strong>Word Frequency Analyzer:</strong> Extracts and counts word occurrences in large text files, sorting them lexicographically.</li>
    <li><strong>Linked List Manipulator:</strong> Implements and manipulates dynamic linked lists with operations such as insertion, deletion, and traversal.</li>
    <li><strong>Matrix Processor:</strong> Performs complex matrix operations, showcasing array manipulation and numerical analysis.</li>
    <li><strong>Trie-Based Pokémon Search:</strong> Utilizes a Trie data structure to efficiently store and search Pokémon names. Custom character indexing optimizes memory usage and speeds up retrieval, ensuring fast performance with large datasets.</li>
  </ul>
</section>

<hr>

<section id="features">
  <h2>Key Features ✔️</h2>
  <ul>
    <li><strong>Efficiency and Scalability:</strong> Optimized algorithms and memory management ensure the programs handle large datasets with minimal overhead.</li>
    <li><strong>Structured Design:</strong> Adhering to clean code principles, each module emphasizes readability and reusability.</li>
    <li><strong>Error Handling and Robustness:</strong> Built-in mechanisms for input validation, memory safety, and runtime error detection ensure the programs are reliable.</li>
  </ul>
</section>

<hr>

<h2>Structure Explanations</h2>
    <div class="structure-explanation">
        <h2>1. <code>struct Pokemon</code></h2>
        <p>This structure defines the attributes of an individual Pokémon. It contains:</p>
        <ul>
            <li><code>pokemonNum</code>: The Pokémon's unique number in the Pokédex.</li>
            <li><code>catchPercentage</code>: The percentage chance of catching the Pokémon.</li>
            <li><code>name</code>: The name of the Pokémon (e.g., "Pikachu").</li>
            <li><code>type</code>: The type(s) of the Pokémon (e.g., "Electric").</li>
            <li><code>region</code>: The region from which the Pokémon hails (e.g., "Kanto").</li>
            <li><code>dexEntry</code>: A description of the Pokémon from the Pokédex.</li>
            <li><code>data</code>: A pointer to the <code>PokemonStatus</code> structure that stores the Pokémon's status (caught or seen).</li>
            <li><code>next</code>: A pointer to the next Pokémon in the linked list of caught Pokémon.</li>
        </ul>
    </div>
    <div class="structure-explanation">
    <h2>2. <code>struct PokemonStatus</code></h2>
    <p>This structure defines the status of a Pokémon, providing details about its visibility, attributes, and individual values:</p>
    <ul>
        <li><code>caught</code>: The number of times the Pokémon has been caught.</li>
        <li><code>seen</code>: The number of times the Pokémon has been seen by the player.</li>
        <li><code>attackIV</code>: The individual value (IV) representing the Pokémon's attack potential.</li>
        <li><code>defenseIV</code>: The individual value (IV) representing the Pokémon's defense potential.</li>
        <li><code>staminaIV</code>: The individual value (IV) representing the Pokémon's stamina potential.</li>
        <li><code>percentIV</code>: A calculated percentage representing the overall strength of the Pokémon based on its IVs.</li>
    </ul>
</div>
    <div class="structure-explanation">
    <h2>3. <code>struct ListManager</code></h2>
    <p>This structure contains function pointers responsible for managing and manipulating the linked list of Pokémon. Each function pointer performs a specific operation on the linked list:</p>
    <ul>
        <li><code>addPtr</code>: A function pointer pointing to the <code>add</code> function, which adds a new Pokémon to the linked list.</li>
        <li><code>sortPtr</code>: A function pointer pointing to the <code>sort</code> function, which sorts the Pokémon in the linked list.</li>
        <li><code>reversePtr</code>: A function pointer pointing to the <code>reverse</code> function, which reverses the order of Pokémon in the linked list.</li>
        <li><code>deleteNodesPtr</code>: A function pointer pointing to the <code>deleteNodes</code> function, which deletes nodes from the linked list.</li>
        <li><code>swapPtr</code>: A function pointer pointing to the <code>swap</code> function, which swaps two Pokémon within the linked list.</li>
    </ul>
</div>
<div class="structure-explanation">
    <h2>4. <code>struct MenuManager</code></h2>
    <p>This structure contains function pointers responsible for facilitating menu operations and calling various functions when the user interacts with the menu or exits the program. Each function pointer represents a specific operation or menu functionality:</p>
    <ul>
        <li><code>menuPtr</code>: A function pointer pointing to the <code>menu</code> function, which displays the main menu to the user and handles their selections.</li>
        <li><code>huntPtr</code>: A function pointer pointing to the <code>hunt</code> function, which manages Pokémon hunting operations, allowing the user to search for and encounter Pokémon.</li>
        <li><code>pokemonCaughtPtr</code>: A function pointer pointing to the <code>sortMenu</code> function, which handles operations related to sorting Pokémon caught by the user.</li>
        <li><code>statsPtr</code>: A function pointer pointing to the <code>stats</code> function, which displays statistical information such as total Pokémon seen and caught.</li>
        <li><code>inventoryPtr</code>: A function pointer pointing to the <code>inventory</code> function, which shows the user's inventory details, including resources like Poké Balls.</li>
        <li><code>displayPokePtr</code>: A function pointer pointing to the <code>displayPoke</code> function, which displays detailed information about individual Pokémon.</li>
        <li><code>writeToFilePtr</code>: A function pointer pointing to the <code>writeToFile</code> function, which saves the Pokémon data to a file for future reference.</li>
    </ul>
</div>
<div class="structure-explanation">
    <h2>5. <code>struct Trie</code></h2>
    <p>This structure defines a Trie for storing characters within a string efficiently. It contains:</p>
    <ul>
        <li><code>children[ALPHABET_SIZE]</code>: An array of pointers to child Tries, where each child corresponds to a character in the string.</li>
        <li><code>isEndOfWord</code>: A boolean indicating whether the current node marks the end of a word.</li>
        <li><code>index</code>: An integer used to store the index of the word, potentially for later reference or retrieval.</li>
    </ul>
</div>
<div class="structure-explanation">
    <h2>6. <code>struct TrieManager</code></h2>
    <p>This structure defines a Trie Manager for efficient Pokémon searching and insertion in the trie. It contains:</p>
    <ul>
        <li><code>getNodePtr()</code>: A function pointer that initializes and returns a pointer to a new Trie node.</li>
        <li><code>getCharIndexPtr()</code>: A function pointer that returns the index corresponding to a character within the trie.</li>
        <li><code>insertPtr()</code>: A function pointer that inserts a string into the trie, associating it with an index and using the TrieManager for management.</li>
        <li><code>searchPtr()</code>: A function pointer that searches the trie for a given string and returns a boolean indicating if the string exists.</li>
        <li><code>freeTriePtr()</code>: A function pointer that frees all dynamically allocated memory for the trie nodes.</li>
    </ul>
</div>


<hr>

<h2>Function Definitions</h2>
    <div class="function-explanation">
    <h2><code>void initializeListManager(struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function initializes an instance of the <code>ListManager</code> structure by assigning function pointers to the appropriate functions that will manipulate the linked list of Pokémon. It sets up the necessary functions for adding, sorting, reversing, deleting nodes, and swapping Pokémon within the list.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct ListManager *manager</code>: A pointer to a <code>ListManager</code> structure that will be initialized.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>void initializeMenuManager(struct MenuManager *manager)</code></h2>
    <p><strong>Description:</strong> This function initializes an instance of the <code>MenuManager</code> structure by assigning function pointers to the appropriate menu functions. It sets up the necessary functions for navigating the Pokémon game menu, managing hunting, displaying Pokémon caught, stats, inventory, and writing data to a file.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct MenuManager *manager</code>: A pointer to a <code>MenuManager</code> structure that will be initialized.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void initializeTrieManager(struct TrieManager *manager)</code></h2>
    <p><strong>Description:</strong> This function initializes an instance of the <code>TrieManager</code> structure by assigning function pointers for creating, searching, inserting, and freeing a trie from memory. It sets up the necessary functions for trie management.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct TrieManager *manager</code>: A pointer to the <code>TrieManager</code> instance to be initialized.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>struct Trie *getNode()</code></h2>
    <p><strong>Description:</strong> This function creates a new root node for the trie. It dynamically allocates memory for a <code>Trie</code> structure and initializes its fields, including setting <code>isEndOfWord</code> to false, <code>index</code> to -1, and setting all child nodes to <code>NULL</code>.</p>
    <p><strong>Returns:</strong> A pointer to the newly created <code>Trie</code> node.</p>
</div>

<div class="function-explanation">
    <h2><code>int getCharIndex(const char *ptr)</code></h2>
    <p><strong>Description:</strong> This function takes a character pointer and returns the corresponding index in the trie based on the character pointed to by <code>ptr</code>. It handles both uppercase and lowercase letters, as well as special characters like apostrophes, periods, and hyphens.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>const char *ptr</code>: A pointer to a character whose index in the trie is to be determined.</li>
    </ul>
    <p><strong>Returns:</strong> An integer representing the index of the character in the trie.</p>
</div>

<div class="function-explanation">
    <h2><code>void insert(struct Trie *root, const char *string, const int *number, const struct TrieManager *manager)</code></h2>
    <p><strong>Description:</strong> This function inserts a new string into the trie, creating new nodes as needed. It iterates through the string, adding characters to the trie, and marks the last node of the string as the end of a word with the associated index.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Trie *root</code>: A pointer to the root node of the trie.</li>
        <li><code>const char *string</code>: A pointer to the string to be inserted into the trie.</li>
        <li><code>const int *number</code>: A pointer to the integer value to be stored at the last node of the inserted string.</li>
        <li><code>const struct TrieManager *manager</code>: A pointer to the <code>TrieManager</code> instance, which provides necessary function pointers for trie operations.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>bool search(struct Trie *root, const char *string, int *number, const struct TrieManager *manager)</code></h2>
    <p><strong>Description:</strong> This function searches the trie for a given string. It traverses the trie based on the characters in the string, checking if each character exists in the trie. If the string is found, it returns true and stores the associated index in <code>number</code>.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Trie *root</code>: A pointer to the root node of the trie.</li>
        <li><code>const char *string</code>: A pointer to the string to be searched for in the trie.</li>
        <li><code>int *number</code>: A pointer to store the index associated with the string if found.</li>
        <li><code>const struct TrieManager *manager</code>: A pointer to the <code>TrieManager</code> instance, which provides necessary function pointers for trie operations.</li>
    </ul>
    <p><strong>Returns:</strong> A boolean indicating whether the string exists in the trie. Returns true if found, false otherwise.</p>
</div>
<div class="function-explanation">
    <h2><code>void removeNewline(char *name)</code></h2>
    <p><strong>Description:</strong> This function removes any new-line characters from the given string and replaces them with a null character (<code>\0</code>). This is useful for cleaning up user input or file data that may have trailing new-line characters.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>char *name</code>: A pointer to the string from which the new-line characters will be removed.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
    <div class="function-explanation">
        <h2><code>bool validRegion(char *)</code></h2>
        <p><strong>Description:</strong> This function checks whether the provided region string is a valid Pokémon region. It allows the user to specify a region in the game, ensuring that only valid regions are selected.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><code>char *region</code>: A pointer to a string containing the region input by the user.</li>
        </ul>
        <p><strong>Returns:</strong> A boolean value: <code>true</code> if the region is valid, <code>false</code> otherwise.</p>
    </div>
    <div class="function-explanation">
        <h2><code>void menu()</code></h2>
        <p><strong>Description:</strong> This function prints a neat and organized menu that provides the player with different options to interact with the Pokémon game. It serves as the starting point for navigating through various gameplay features.</p>
        <p><strong>Parameters:</strong> None</p>
        <p><strong>Returns:</strong> Nothing (void).</p>
    </div>
    <div class="function-explanation">
        <h2><code>void getSelection(char *)</code></h2>
        <p><strong>Description:</strong> This function captures the player's input from the menu selection and processes it into a friendly format. It helps ensure that user input is clean and valid for further processing in the game.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><code>char *selection</code>: A pointer to a character array where the formatted input will be stored.</li>
        </ul>
        <p><strong>Returns:</strong> Nothing (void).</p>
    </div>
    <div class="function-explanation">
    <h2><code>void hunt(char *region, struct Pokemon *pokemons, const int *size, void (*balls) (const int *, const int *, const int *), int *pokeBalls, int *greatBalls, int *ultraBalls, int *caught, int *seen, struct Pokemon **head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function facilitates the Hunt menu option for catching Pokémon. It handles the process of encountering Pokémon from a specific region, selecting a Poké Ball, and attempting to catch the Pokémon. The function uses a random number generator to determine the encounter and Pokémon statistics, and it updates the player's Pokémon collection based on the outcome of each catch attempt.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>char *region</code>: A pointer to a string containing the region where the Pokémon is encountered (e.g., "Kanto", "Johto").</li>
        <li><code>struct Pokemon *pokemons</code>: A pointer to an array of Pokémon structures, where each Pokémon has specific data such as catch percentage and individual values.</li>
        <li><code>const int *size</code>: A pointer to the total number of Pokémon in the game.</li>
        <li><code>void (*balls) (const int *, const int *, const int *)</code>: A function pointer to display the number of Poké Balls, Great Balls, and Ultra Balls the player has.</li>
        <li><code>int *pokeBalls</code>, <code>int *greatBalls</code>, <code>int *ultraBalls</code>: Pointers to integers representing the number of each type of Poké Ball the player has left.</li>
        <li><code>int *caught</code>, <code>int *seen</code>: Pointers to integers tracking the number of Pokémon caught and seen.</li>
        <li><code>struct Pokemon **head</code>: A pointer to the head of the linked list of caught Pokémon.</li>
        <li><code>const struct ListManager *manager</code>: A pointer to a ListManager instance containing function pointers for manipulating the linked list of Pokémon.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void huntHelper(int *catchNum, int *balls, struct Pokemon *pokemons, const int *index, int *caught, int *seen, struct Pokemon **head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function simulates the process of attempting to catch a Pokémon using an Ultra Ball. It checks whether the Pokémon can be caught based on a random number and the Pokémon's catch percentage, accounting for the increased chances provided by the Ultra Ball. Depending on the result, it either calls a function to handle the successful catch or the Pokémon fleeing.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>int *catchNum</code>: A pointer to an integer representing a randomly generated number used to determine the success of catching the Pokémon.</li>
        <li><code>int *balls</code>: A pointer to the integer representing the number of Ultra Balls the player has, which is decremented after each use.</li>
        <li><code>struct Pokemon *pokemons</code>: A pointer to an array of Pokémon structures, where each Pokémon has attributes like catch percentage.</li>
        <li><code>const int *index</code>: A pointer to the index of the current Pokémon being encountered.</li>
        <li><code>int *caught</code>: A pointer to an integer tracking the number of Pokémon successfully caught.</li>
        <li><code>int *seen</code>: A pointer to an integer tracking the number of Pokémon seen by the player.</li>
        <li><code>struct Pokemon **head</code>: A pointer to the head of the linked list of caught Pokémon.</li>
        <li><code>const struct ListManager *manager</code>: A pointer to a <code>ListManager</code> instance containing functions for manipulating the linked list of caught Pokémon.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
    <div class="function-explanation">
        <h2><code>void balls(const int *, const int *, const int *)</code></h2>
        <p><strong>Description:</strong> This function displays the player's current inventory of Poké Balls, giving information about how many of each type of ball the player possesses. It helps keep track of the player's available resources for catching Pokémon.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><code>const int *standardBalls</code>: A pointer to the number of standard Poké Balls.</li>
            <li><code>const int *greatBalls</code>: A pointer to the number of Great Balls.</li>
            <li><code>const int *ultraBalls</code>: A pointer to the number of Ultra Balls.</li>
        </ul>
        <p><strong>Returns:</strong> Nothing (void).</p>
    </div>
    <div class="function-explanation">
        <h2><code>struct Pokemon *add(struct Pokemon **, const struct Pokemon *, const int *)</code></h2>
        <p><strong>Description:</strong> This function adds a newly caught Pokémon to the end of the player's linked list of Pokémon. It allows the player to build their collection by adding new entries to the list.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><code>struct Pokemon **pokemonList</code>: A pointer to the list of Pokémon to which the new Pokémon will be added.</li>
            <li><code>const struct Pokemon *newPokemon</code>: A pointer to the Pokémon structure representing the new Pokémon being added.</li>
            <li><code>const int *pokemonCount</code>: A pointer to the total count of Pokémon caught by the player.</li>
        </ul>
        <p><strong>Returns:</strong> A pointer to the updated list of Pokémon.</p>
    </div>
    <div class="function-explanation">
    <h2><code>struct Pokemon *pokeCaught(struct Pokemon *pokemons, const int *random, int *caught, int *seen, struct Pokemon **head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function facilitates the process of the user successfully catching a Pokémon. It prints a congratulatory message, updates the caught and seen counters for the Pokémon, and adds the caught Pokémon to the linked list of caught Pokémon.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Pokemon *pokemons</code>: A pointer to an array of Pokémon structures, where each Pokémon has specific data such as name, caught, and seen counters.</li>
        <li><code>const int *random</code>: A pointer to the index of the Pokémon that has been successfully caught.</li>
        <li><code>int *caught</code>, <code>int *seen</code>: Pointers to integers tracking the number of Pokémon caught and seen by the user.</li>
        <li><code>struct Pokemon **head</code>: A pointer to the head of the linked list of caught Pokémon.</li>
        <li><code>const struct ListManager *manager</code>: A pointer to a ListManager instance containing function pointers for manipulating the linked list of Pokémon.</li>
    </ul>
    <p><strong>Returns:</strong> The updated head of the linked list of caught Pokémon.</p>
</div>
<div class="function-explanation">
    <h2><code>void pokeRan(struct Pokemon *pokemons, const int *random, int *seen)</code></h2>
    <p><strong>Description:</strong> This function handles the scenario when a Pokémon runs away from the user's attempt to catch it. It prints a message indicating the Pokémon fled and increments the 'seen' counter for the Pokémon.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Pokemon *pokemons</code>: A pointer to an array of Pokémon structures representing the available Pokémon.</li>
        <li><code>const int *random</code>: A pointer to the index of the randomly selected Pokémon that ran away.</li>
        <li><code>int *seen</code>: A pointer to the total number of Pokémon seen.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>void pokemonCaught(const struct Pokemon *head, int *selection)</code></h2>
    <p><strong>Description:</strong> This function displays the list of Pokémon that the user has caught and allows the user to select between viewing detailed information about the caught Pokémon or just listing their names. It also provides an option to exit the menu.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>const struct Pokemon *head</code>: A pointer to the head of the linked list of caught Pokémon.</li>
        <li><code>int *selection</code>: A pointer to the user's selection for how they wish to view their caught Pokémon (view details, list caught Pokémon, or exit).</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>void stats(const int *caught, const int *seen)</code></h2>
    <p><strong>Description:</strong> This function prints the user's statistics, including the number of Pokémon caught and seen, and calculates the catch rate if more than one Pokémon has been caught.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>const int *caught</code>: A pointer to the total number of Pokémon caught by the user.</li>
        <li><code>const int *seen</code>: A pointer to the total number of Pokémon seen by the user.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void inventory(const int *pokeBall, const int *greatBall, const int *ultraBall)</code></h2>
    <p><strong>Description:</strong> This function displays the user's inventory of Poké Balls, including Poke Balls, Great Balls, and Ultra Balls. The inventory is presented in a neat, tabular format.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>const int *pokeBall</code>: A pointer to the number of Poké Balls the user has.</li>
        <li><code>const int *greatBall</code>: A pointer to the number of Great Balls the user has.</li>
        <li><code>const int *ultraBall</code>: A pointer to the number of Ultra Balls the user has.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>void displayPoke(const struct Pokemon *pokemons, const int *index)</code></h2>
    <p><strong>Description:</strong> This function displays detailed information about a specific Pokémon, identified by the index passed to it. It prints the Pokémon's name, type, and Dex entry.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>const struct Pokemon *pokemons</code>: A pointer to the array of Pokémon.</li>
        <li><code>const int *index</code>: A pointer to the index of the Pokémon whose information is to be displayed.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>int sortMenu()</code></h2>
    <p><strong>Description:</strong> This function displays a menu that allows the user to choose how they would like to sort the Pokémon list. The menu offers various sorting options, including lexicographical sorting, sorting by type, and sorting by Pokémon number.</p>
    <p><strong>Parameters:</strong> None</p>
    <p><strong>Returns:</strong> The user's sorting selection as an integer (1 to 6).</p>
</div>

<div class="function-explanation">
    <h2><code>struct Pokemon *sort(struct Pokemon *head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function sorts the linked list of Pokémon based on the user's selection from the sorting menu. It allows sorting by name (lexicographically ascending or descending), type, and Pokémon number, as well as reversing the list. It utilizes a helper function for swapping nodes in the linked list and updates the head pointer when necessary.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Pokemon *head</code>: A pointer to the head of the linked list of Pokémon.</li>
        <li><code>const struct ListManager *manager</code>: A pointer to a ListManager structure responsible for managing list operations such as swapping and reversing nodes.</li>
    </ul>
    <p><strong>Returns:</strong> The head pointer of the sorted (or reversed) linked list.</p>
</div>
<div class="function-explanation">
    <h2><code>struct Pokemon *deleteNodes(struct Pokemon *head)</code></h2>
    <p><strong>Description:</strong> This function traverses the linked list of Pokémon and frees the dynamically allocated memory for each node. After all nodes are freed, it returns <code>NULL</code> to indicate that the list is empty.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Pokemon *head</code>: A pointer to the head of the linked list of Pokémon.</li>
    </ul>
    <p><strong>Returns:</strong> <code>NULL</code>, indicating that the list has been deleted.</p>
</div>

<div class="function-explanation">
    <h2><code>void swap(struct Pokemon *ptr, struct Pokemon *ptr2, struct Pokemon *head)</code></h2>
    <p><strong>Description:</strong> This function swaps the data between two nodes in the linked list. It facilitates sorting by swapping the Pokémon information between the nodes pointed to by <code>ptr</code> and <code>ptr2</code>.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Pokemon *ptr</code>: A pointer to the first node in the linked list to swap.</li>
        <li><code>struct Pokemon *ptr2</code>: A pointer to the second node in the linked list to swap.</li>
        <li><code>struct Pokemon *head</code>: A pointer to the head of the linked list, though it is not used directly in this function.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>struct Pokemon *reverse(struct Pokemon *head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function reverses the order of nodes in the doubly linked list of Pokémon. It copies the Pokémon data to an array and then updates the list in reverse order by swapping the data between the nodes.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Pokemon *head</code>: A pointer to the head of the linked list of Pokémon.</li>
        <li><code>const struct ListManager *manager</code>: A pointer to the ListManager structure responsible for managing list operations.</li>
    </ul>
    <p><strong>Returns:</strong> The head pointer of the reversed linked list.</p>
</div>

<div class="function-explanation">
    <h2><code>void writeToFile(const struct Pokemon *head)</code></h2>
    <p><strong>Description:</strong> This function writes the details of the Pokémon in the linked list to a file called <code>pokemons.txt</code>. The file contains a header, followed by the Pokémon data in a table format, and ends with a footer.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>const struct Pokemon *head</code>: A pointer to the head of the linked list of Pokémon.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void freeTrie(struct Trie *trie)</code></h2>
    <p><strong>Description:</strong> This function recursively frees the dynamically allocated memory used to create a trie structure. It starts by checking if the current node is NULL, and if not, it traverses through each child node, recursively freeing memory for all descendant nodes before freeing the current node itself.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>struct Trie *trie</code>: A pointer to the root of the trie structure to be freed. The function will recursively free all nodes starting from this root.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<hr>

<section id="usage">
  <h2>Usage 🚀</h2>
  <p><strong>1. Compile the Program:</strong></p>
  <div class="code-block">make
  </div>
  
  <p><strong>2. Run the Program:</strong></p>
  <div class="code-block">./main
  </div>
</section>
</body>
</html>
