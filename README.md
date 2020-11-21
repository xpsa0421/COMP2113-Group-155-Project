# COMP2113-Project

### A brief identification of the team members:
juanb0510: Jun Han Bang 3035663033  <br />xpsa0421: Sooa Park 3035666401

### A game description with basic game rules:
Typing Game intends to improve a player's English typing skill in an entertaining and interactive way. A player is asked to type a word accurately, and by typing more words in a given time, he or she can gain a higher grade. The player can repeatedly try until he or she types correctly. Typing Game targets players of varying English typing levels with four levels of difficulties. The game asks a player to type harder and longer words in an increasingly shorter time period as the difficulty level increases. A player can personalise the word list as well - by  adding or removing words from the list.
	
	
### A list of features that you plan to implement:
#### 1. Generation of random game sets or events
Words are saved in four different dynamic arrays according to their difficulty (i.e. word length). Every time, a random number which corresponds to the index of a word array is generated. The program will then print a word at that index, outputting a random word. The array is then modified so that the same word will not appear.


#### 2. Data structures for storing game status
string filename         - filename of a selected difficulty word list <br />
string wordOutput       - word from a list<br />
string wordInput        - word from a player<br />
string *word_arr	- list of words to be asked<br />

int arr_size            - number of words in a list<br />
int time                - time for stopwatch<br />
int difficulty          - selected difficulty<br />
int count               - count of correct words<br />

bool flag               - flag to mark command execution<br />

#### 3. Dynamic memory management
Every time the game runs, a dynamic array containing words to be asked is created and freed. Since each difficulty level has varying number of words and players can update the word list during gameplay, the number of words will be different at every gameplay. With a dynamic memory management, the compiler does not need to know the exact size of the array (i.e. number of words in a list) in advance.

#### 4. File input/output (e.g., for loading/saving game status)
Words are saved in a separate words file (easy_words.txt, mediocre_words.txt etc). When adding or deleting words from a list, the word file becomes the input and output file. Any changes to the list are saved in the file to be kept for future gameplays. When creating a dynamic array of words to use for the game, the word file becomes the input file.

#### 5. Program codes in multiple files
There are in total four code files: functions.cpp, functions.h, typing_game_main.cpp, and Makefile. 'functions.cpp' contains all the function definitions to use in the game. 'functions.h' contains all function declarations. 'typing_game_main.cpp' contains the main function with variables. 'Makefile' contains code for program compilation.


### Non-standard C++ library
The program includes a non-standard header <unistd.h> in order to use the sleep() function. This function suspends any code execution for a set time. In the program, sleep() gives a player three seconds to get ready before the game begins.


### Compilation and execution instructions
Put all the files at one location. Open terminal at the location and type "make typing_game" to generate the executable typing_game. Type "./typing_game" to start the program. Type "make clean" to remove the executable gamefile and object codes.
