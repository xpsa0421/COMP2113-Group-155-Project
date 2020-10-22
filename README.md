# COMP2113-Project

A brief identification of the team members:
	juanb0510: Jun Han Bang
	xpsa0421: Sooa Park

A game description with basic game rules:
	The Typing Game is a game intended to improve a player's English typing skill in an entertaining and interactive way. Each time, a random word appears on the screen. By 	correctly typing the word, players can win points. They can repeatedly try until they type correctly. To win more points, players need to type as many words as they can 	within the time limit. Players with high scores will be recorded, and they can compete with friends, families, and themselves. With varying levels of difficulties, Typing 	  Game targets users of varying English typing levels. Levels have different time limits and length of words.
	
A list of features that you plan to implement:

	1. Generation of random game sets or events
	Words are saved in three one-dimensional arrays according to their difficulty (i.e. word length). Every time, a random number which corresponds to the index of a word 		array is generated. The program will then print the word at that index, outputting a different random word.

2. Data structures for storing game status
	string 	- user input, username
	int	- time(stopwatch), score, index
	array 	- to hold scores and usernames, a library containing to be outputted words

3. Dynamic memory management
	As we do not know the input length of the user, it is difficult to set the initial array size to hold user input. As dynamic memory management does not require the 		compiler to know the exact size of the array in advance, it can efficiently accept user input and store it in a designated variable.

4. File input/output (e.g., for loading/saving game status)
	Arrays of words are saved in a separate words file. For random word generation, the words file becomes the input file. One word is displayed on the screen at a time.
	Username and score for each game are saved in one separate scores file. For high score calculation, the scores file becomes the input. The list of high scores is then 		displayed.

5. Program codes in multiple files
	The main code is saved in a different file from supplementary codes such as codes that are used to calculate high scores as they are required at different times. Data such 	    as words, usernames, and scores are also saved in different files.
