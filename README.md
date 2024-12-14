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
        <p>This structure defines the status of a Pokémon, indicating how many times it has been caught and seen:</p>
        <ul>
            <li><code>caught</code>: The number of times the Pokémon has been caught.</li>
            <li><code>seen</code>: The number of times the Pokémon has been seen by the player.</li>
        </ul>
    </div>
    <div class="structure-explanation">
        <h2>3. <code>struct PokemonManager</code></h2>
        <p>This structure manages the operations related to the linked list of caught Pokémon. It includes function pointers for various actions:</p>
        <ul>
            <li><code>addPtr</code>: A function pointer to the <code>add</code> function, responsible for adding new Pokémon to the list.</li>
            <li><code>sortPtr</code>: A function pointer to the <code>sort</code> function, responsible for sorting the Pokémon list.</li>
            <li><code>deleteNodesPtr</code>: A function pointer to the <code>deleteNodes</code> function, responsible for deleting nodes from the list.</li>
            <li><code>swapPtr</code>: A function pointer to the <code>swap</code> function, responsible for swapping Pokémon in the list based on sorting criteria.</li>
        </ul>
    </div>

<hr>

<h2>Function Definitions</h2>
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
        <h2><code>void hunt(char *, struct Pokemon *, const int *, void (*) (const int *, const int *, const int *), int *, int *, int *, int *, int *, struct Pokemon **, const struct PokemonManager *)</code></h2>
        <p><strong>Description:</strong> This function handles the hunting process where the player attempts to catch Pokémon. It interacts with various parameters to perform actions like attempting to catch a Pokémon, managing the player's inventory, and updating statistics.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><code>char *userName</code>: The name of the player.</li>
            <li><code>struct Pokemon *pokemonList</code>: A pointer to the list of Pokémon the player has encountered or caught.</li>
            <li><code>const int *inventory</code>: A pointer to the player's inventory of Poké Balls.</li>
            <li><code>void (*ballUseCallback)(const int *, const int *, const int *)</code>: A callback function that updates the usage of Poké Balls.</li>
            <li><code>int *caughtCount</code>: A pointer to the total count of Pokémon caught by the player.</li>
            <li><code>int *seenCount</code>: A pointer to the total count of Pokémon seen by the player.</li>
            <li><code>int *fleeCount</code>: A pointer to the number of Pokémon that have fled from the player.</li>
            <li><code>int *totalAttempts</code>: A pointer to the total number of attempts made by the player to catch Pokémon.</li>
            <li><code>int *remainingBalls</code>: A pointer to the number of remaining Poké Balls available to the player.</li>
            <li><code>struct Pokemon **pokemonListPtr</code>: A pointer to the list of Pokémon that will be updated after the hunt.</li>
            <li><code>const struct PokemonManager *manager</code>: A pointer to the manager that holds various function pointers for Pokémon-related operations.</li>
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
        <h2><code>void pokeCaught(struct Pokemon *, const int *, int *, int *, struct Pokemon **, const struct PokemonManager *)</code></h2>
        <p><strong>Description:</strong> This function handles the process of catching a Pokémon. It updates the player's inventory and Pokémon list, increases the catch count, and performs other relevant updates.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><code>struct Pokemon *pokemonList</code>: The list of Pokémon the player has caught.</li>
            <li><code>const int *ballInventory</code>: A pointer to the player's Poké Ball inventory.</li>
            <li><code>int *caughtCount</code>: A pointer to the count of Pokémon the player has caught.</li>
            <li><code>int *seenCount</code>: A pointer to the count of Pokémon the player has seen.</li>
            <li><code>struct Pokemon **pokemonListPtr</code>: A pointer to the Pokémon list that will be updated.</li>
            <li><code>const struct PokemonManager *manager</code>: A pointer to the Pokémon manager.</li>
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
