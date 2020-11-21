#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include "functions.h"
using namespace std;
using namespace std::chrono;

// main code starts here
int main() {
  // variables
  string *word_arr  = nullptr;  // list of words to be asked
  int arr_size      = 0;        // number of words in a list
  string filename   = "";       // filename of a word list
  int time          = 0;        // time for stopwatch
  int difficulty    = 0;        // selected difficulty
  string wordOutput = "";       // word from a list
  string wordInput  = "";       // word from a player
  bool flag         = false;    // flag to mark command execution
  int count         = 0;        // count of words correct

  // display mainscreen UI
  startScreen_UI();

  // user types 1, 2, or 3 to 1: Play game 2: Edit words 3: Exit game
  int command;
  cin >> command;

  // choose action
  chooseAction(command, difficulty);

  // game starts here
  cout << "\n\t\t\033[1mPlease select your difficulty level:\033[0m\n\t\t1. Easy  2. Mediocre  3. Gosu  4. Ssap Gosu " << endl << endl;
  cin >> difficulty;

  // set level for game
  setLevelAction(difficulty, time, word_arr, filename, arr_size);
  // display game start UI
  gameStart_UI();
  // main game begins here
  inputAction(wordInput, wordOutput, word_arr, arr_size, time, count);
  // calculate score
  scoreCalculation(count, difficulty);

  return 0;
}
