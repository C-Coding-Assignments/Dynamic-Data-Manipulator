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
    <li><a href="#word-frequency-analyzer">Word Frequency Analyzer</a></li>
    <li><a href="#linked-list-manipulator">Linked List Manipulator</a></li>
    <li><a href="#matrix-processor">Matrix Processor</a></li>
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

<h2>Function Explanations</h2>
    <div class="function-explanation">
        <h2>1. <code>validRegion(char *region)</code></h2>
        <p>This function checks whether the user has entered a valid Pokémon region. It converts the first character to uppercase and the rest to lowercase before comparing it against known regions (Kanto, Johto, Hoenn, Sinnoh). It returns <code>true</code> if the region is valid, otherwise <code>false</code>.</p>
    </div>
    <div class="function-explanation">
        <h2>2. <code>menu()</code></h2>
        <p>This function displays the main menu of the Pokémon adventure game. It presents the available options for the user to interact with, including options to hunt, view Pokémon caught, sort Pokémon, see statistics, and more.</p>
    </div>
    <div class="function-explanation">
        <h2>3. <code>getSelection(char *input)</code></h2>
        <p>This function retrieves the user's input for their menu selection. It ensures that the input is properly capitalized and formatted for further processing. The user is prompted to make a choice from the available menu options.</p>
    </div>
    <div class="function-explanation">
        <h2>4. <code>hunt(...)</code></h2>
        <p>The <code>hunt</code> function facilitates the process of catching a Pokémon. It randomly selects a Pokémon based on the chosen region (Kanto, Johto, Hoenn, or Sinnoh). The user is then prompted to choose a ball to throw in an attempt to catch the Pokémon. If successful, the Pokémon is added to the user's collection. This function handles all logic related to the hunting mechanics and ball usage.</p>
    </div>
    <div class="function-explanation">
        <h2>5. <code>balls(const int *pokeBalls, const int *greatBall, const int *ultraBall)</code></h2>
        <p>This function displays the user's current inventory of Poké Balls, Great Balls, and Ultra Balls. It shows how many of each ball the user has available to catch Pokémon.</p>
    </div>
    <div class="function-explanation">
        <h2>6. <code>add(struct Pokemon **head, const struct Pokemon *pokemons, const int *random)</code></h2>
        <p>This function is responsible for adding a newly caught Pokémon to the player's linked list of Pokémon. The Pokémon is dynamically allocated and inserted at the end of the list. The function returns the updated head of the linked list.</p>
    </div>
    <div class="function-explanation">
        <h2>7. <code>pokeCaught(...)</code></h2>
        <p>The <code>pokeCaught</code> function is called when a Pokémon is successfully caught. It updates the catch and seen statistics, congratulates the player, and adds the Pokémon to the player's collection (linked list).</p>
    </div>
    <div class="function-explanation">
        <h2>8. <code>pokeRan(...)</code></h2>
        <p>This function handles the scenario where a Pokémon escapes the player's attempt to catch it. It updates the seen statistics and informs the player that the Pokémon has run away.</p>
    </div>
    <div class="function-explanation">
        <h2>9. <code>pokemonCaught(const struct Pokemon *head)</code></h2>
        <p>This function displays all the Pokémon the player has caught so far. It traverses the linked list of caught Pokémon and prints their names, along with the total number of Pokémon caught.</p>
    </div>
    <div class="function-explanation">
        <h2>10. <code>stats(const int *caught, const int *seen)</code></h2>
        <p>The <code>stats</code> function displays the player's catch statistics. It shows how many Pokémon the player has caught and seen, and calculates the player's catch rate based on the total caught and seen Pokémon.</p>
    </div>
    <div class="function-explanation">
        <h2>11. <code>inventory(const int *pokeBall, const int *greatBall, const int *ultraBall)</code></h2>
        <p>This function prints out the player's ball inventory, showing how many Poké Balls, Great Balls, and Ultra Balls the player has. This helps the player manage their resources for hunting Pokémon.</p>
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
