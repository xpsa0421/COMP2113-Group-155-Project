// functions.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// game start UI
void startScreen_UI() {
  cout <<"\t\t*********************************************\n";
  cout <<"\t\t*                                           *\n";
  cout <<"\t\t*         \033[1;33mWelcome to the Typing Game!\033[0m       *\n";
  cout <<"\t\t*            \033[3mSooa Park & Juan Bang\033[0m          *\n";
  cout <<"\t\t*                                           *\n";
  cout <<"\t\t*                                           *\n";
  cout <<"\t\t*          \033[1mChoose Action(enter 1/2/3)\033[0m       *\n";
  cout <<"\t\t*               1. Play Game                *\n";
  cout <<"\t\t*               2. Edit Words               *\n";
  cout <<"\t\t*               3. Exit Game                *\n";
  cout <<"\t\t*                                           *\n";
  cout <<"\t\t*********************************************\n";
}

// wordlist change UI
void chooseWordList_UI(){
  cout <<"\t\t\033[1mChoose a word list to change\033[0m\n";
  cout <<"\t\t1. Easy\t  2. Mediocore\t3. Gosu  4. Ssap Gosu\n";
}

// Game start UI
void gameStart_UI(){
  cout << "\t\t\tGame starts in...\033[0m" << endl;
  for(int i = 3; i >0; i--){
    cout << "\t\t\t\t      " << i << endl;
    sleep(1.5);
  }
  system("clear");
}

// function to handle word list
void wordlistChange(int difficulty) {
  // variables
  fstream wordfile;
  string filename   = "";   // filename of a word list
  int command       = 0;    // selected action
  string word       = "";   // word from a list
  bool flag         = true; // flag to mark command execution

  // open a corresponding difficulty word list
  switch (difficulty) {
    case 1: filename = "easy_words.txt"; break;
    case 2: filename = "mediocre_words.txt"; break;
    case 3: filename = "gosu_words.txt"; break;
    case 4: filename = "ssapgosu_words.txt"; break;
  }
  wordfile.open(filename.c_str(), ios::in|ios::app);

  // player enters 1, 2, or 3 to choose what to do with the list
  cout << "\n\t\t\033[1mChoose Action\033[0m\n\t\t1. View list  2. Add words  3. Delete words" << endl;
  cin >> command;

  while (flag == true) {
    switch (command) {
      case 1: // display word list
        system("clear");
        cout << "\n\033[1mWord list\033[0m" << endl;
        getline(wordfile, word);
        cout << word;
        while (getline(wordfile, word)) {
          if (word.length() == 0) break;
            cout << ", " << word;
        }
        break;

      {
      case 2: // add a word to list
        string word_to_add = "";   // word entered by user to add
        bool exist         = true; // flag to check if word exists in list

        cout << "\n\033[1mEnter a word to add: \033[0m";
        getline(cin.ignore(), word_to_add);

        // check if the word exists in the list
        while (exist == true) {
          exist = false;
          while (getline(wordfile, word)) {
            if (word == word_to_add) {
              cout << "\033[1;31m\n" << word_to_add << " already exists in the list.\033[0m\nPlease enter a different word: ";
              getline(cin, word_to_add);
              exist = true;
              break;
            }
          }
          // move the cursor back to the top of the file
          wordfile.clear();
          wordfile.seekg(0);
        }

        // check if the word length is appropriate to the selected difficulty
        while (difficulty == 1 && (word_to_add.length() < 3 || word_to_add.length() > 5)) {
          cout << "\n\033[1;31mOops! Your word is inappropriate for Easy level.\033[0m\n" <<
          "Please enter a word with 3-5 characters: ";
          getline(cin, word_to_add);
        }

        while (difficulty == 2 && (word_to_add.length() < 5 || word_to_add.length() > 7)) {
          cout << "\n\033[1;31mOops! Your word is inappropriate for Mediocre level.\033[0m\n" <<
          "Please enter a word with 5-7 characters: ";
          getline(cin, word_to_add);
        }

        while (difficulty == 3 && word_to_add.length() < 8) {
          cout << "\n\033[1;31mOops! Your word is inappropriate for Gosu level.\033[0m\n" <<
          "Please enter a word with over 8 characters: ";
          getline(cin, word_to_add);
        }

        while (difficulty == 4 && word_to_add.length() < 10) {
          cout << "\n\033[1;31mOops! Your word is inappropriate for Ssap Gosu level.\033[0m\n" <<
          "Please enter a word with over 10 characters: ";
          getline(cin, word_to_add);
        }

        // the word is now good to be added
        wordfile << word_to_add << endl;
        cout << "\033[1;32m" << word_to_add << " is successfully added to the list\033[0m";

        break;
      }

      {
      case 3: // delete a word from the list
        string word_to_delete = "";     // word entered by user to delete
        bool exist            = false;  // flag to mark command execution
        ofstream temp;
        temp.open("temp.txt");          // file to temporarily save the words to keep

        cout << "\n\033[1mEnter a word to delete: \033[0m";
        getline(cin.ignore(), word_to_delete);

        // copy words to the temporary file except for the word to delete
        while (getline(wordfile, word)) {
          if (word != word_to_delete)
            temp << word << endl;
          else
            exist = true; // word to delete exists in the list
        }

        if (exist == true)
          cout << "\033[1;32m" << word_to_delete << " is successfully deleted from the list\033[0m";
        else
          cout << "\033[1;31m" << word_to_delete << " is not in the list\033[0m";

        // replace the word list file with the newly created file
        temp.close();
        wordfile.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        wordfile.open(filename.c_str(), ios::in|ios::app);
      }
    }

    wordfile.clear();
    wordfile.seekg(0);

    cout << "\n\n\n\033[1mChoose Action\033[0m\n1. View list  2. Add words  3. Delete words  4. Play game" << endl;
    cin >> command;

    // end editing word list
    if (command == 4)
        flag = false;

    // when invalid input entered
    if (command < 1 || command > 4) {
      cout << "\033[31mPlease enter a number between 1 to 4: \033[31m";
      cin >> command;
    }
  }
  wordfile.close();
}

// choose Action function
void chooseAction(int command, int &difficulty){
  bool flag = false; // flag to mark command execution

  while (flag == false) {
    switch (command) {
      case 1: // play game
        flag = true;
        break;

      case 2: // edit words
        chooseWordList_UI();
        // receive input until valid input is entered
        while (difficulty < 1 || difficulty > 4)
          cin >> difficulty;
        wordlistChange(difficulty);
        flag = true;
        break;

      case 3: // exit game
        cout << "\n\033[3mGame successfully ended.\033[0m\n";
        flag = true;
        exit(0);

      default: // invalid input entered
        cout << "\t\t\033[1;31mPlease enter a number between 1 to 3: \033[0m";
        cin >> command;
        break;
    }
  }
}

// function to create a dynamic array of words of the chosen difficulty
void createNewArray(string filename, string*& word_arr, int& arr_size) {
  // variables
  string word;       // word from a list
  ifstream wordfile; // file containing words of the chosen difficulty
  wordfile.open(filename.c_str());

  // calculate arr_size
  while (getline(wordfile, word)) {
  if (word.length() == 0) break;
    arr_size++;
  }

  // create new array using dynamic array for arr_size;
  word_arr = new string[arr_size];

  wordfile.clear();
  wordfile.seekg(0);

  // add words in the file to a word string array
  for (int i = 0; i < arr_size; i++) {
    getline(wordfile, word);
    word_arr[i] = word;
  }
  wordfile.close();
}

// game set level
void setLevelAction(int difficulty, int &time, string*& word_arr, string &filename, int &arr_size){
  bool flag = false; // flag to mark command execution

  while (flag == false) {
    switch (difficulty) {
      case 1: // difficulty easy
        cout << "\t\t\t\033[1;32mDifficulty set to Easy" << endl;
        flag = true;
        time = 50;
        filename = "easy_words.txt";
        createNewArray(filename, word_arr, arr_size);
        break;

      case 2: // difficulty mediocre
        cout << "\t\t\t\033[1;32mDifficulty set to Mediocre" << endl;
        flag = true;
        time = 40;
        filename = "mediocre_words.txt";
        createNewArray(filename, word_arr, arr_size);
        break;

      case 3: // difficulty gosu
        cout << "\t\t\t\033[1;32mDifficulty set to Gosu" << endl;
        flag = true;
        time = 30;
        filename = "gosu_words.txt";
        createNewArray(filename, word_arr, arr_size);
        break;

      case 4: // difficulty ssap gosu
        cout << "\t\t\t\033[1;32mDifficulty set to Ssap Gosu" << endl;
        flag = true;
        time = 20;
        filename = "ssapgosu_words.txt";
        createNewArray(filename, word_arr, arr_size);
        break;

      default: // if invalid input entered
        cout << "\t\t\033[1;32mPlease enter a number between 1 to 4: \033[0m";
        cin >> difficulty;
    }
  }
}

// receive input function
void receiveInput(string &wordInput){
  cout << "\t\t";
  getline(cin, wordInput);
}

// display a random word for player to type
// remove the word from the list
void printWord(string* &word_arr, int &arr_size, string &wordOutput) {
    srand(time(NULL));
    int i = rand() % (arr_size);
    wordOutput = word_arr[i];

    // replace the used word with the last word of the array
    word_arr[i] = word_arr[arr_size-1];
    arr_size--;

    cout << "\t\t\033[1mPlease type the word: " << wordOutput << "\033[0m" << endl;
}

// compare if user input is the same as given word
bool compareWord(string wordInput, string wordOutput){
  if(wordInput == wordOutput)
    return true;
  else
    return false;
}

// input Action function
void inputAction(string &wordInput, string &wordOutput, string* &word_arr, int &arr_size, int time, int &count){
  // variables
  bool flag         = false;
  bool flag_loop    = false;
  bool flag_compare = false;
  // counter to skip first loop
  int counter       = 0;
  int counter_word  = 0;

  // introduce
  cout << "\n\t\033[1;33m  You have " << time <<" seconds to type as many words as you can.\n";
  gameStart_UI();
  // game start
  cout << "\n\t\t\033[1;33mGame Start!\033[0m\n";
  receiveInput(wordInput);

  // measure start time
  auto t1 = chrono::high_resolution_clock::now();
  while(flag == false){
    // match format
    cout << "\n\n";

    printWord(word_arr, arr_size, wordOutput);         // output
    receiveInput(wordInput);                           // input
    flag_compare = compareWord(wordInput, wordOutput); // check first input(false)

    while(flag_compare == false){
      cout << "\n\n\t\t\033[1;31mWrong, type the word again: \033[0m" << wordOutput << endl;
      receiveInput(wordInput);
      flag_compare = compareWord(wordInput, wordOutput);

      // check time in loop
      auto t3 = chrono::high_resolution_clock::now();
      int duration_wrong = chrono::duration_cast<microseconds>(t3 -  t1).count() / 1000000;
      if(duration_wrong >= time){
        flag_loop = true;
        break;
      }
    }

    // counter to count the number of words correct
    counter++;

    if(flag_loop == true) break; // break if the user is in the loop
    auto t2 = chrono::high_resolution_clock::now(); // get end time

    // calculate duration
    int duration = chrono::duration_cast<microseconds>(t2 - t1).count() / 1000000;
    if(duration >= time){ // break if duration is long
      flag = true;
    }
  }

  // update count
  count = counter;
  // free memory when time is over
  delete [] word_arr;
}

// score calculation function
void scoreCalculation(int count, int difficulty){
  /*
  standard for easy        : 40++ -> A+ decrease by 10
               mediocre    : 40++ -> A+ decrease by 5
               gosu        : 30++ -> A+ decrease by 5
               ssap gosu   : 10++ -> A+ decrease by 2
  */

  system("clear");
  cout <<"\n\n\n\n\n\n\t\t\033[1m*********************************************\n";
  cout << "\n\n\n\t\tYou have correctly typed " << count << " words.\n";

  if(difficulty == 1){
    switch (count / 10){
      case 0:
        cout << "\t\tYour score is E" << endl;
        break;
      case 1:
        cout << "\t\tYour score is D" << endl;
        break;
      case 2:
        cout << "\t\tYour score is C" << endl;
        break;
      case 3:
        cout << "\t\tYour score is B" << endl;
        break;
      case 4:
        cout << "\t\tYour score is A" << endl;
        break;
      default:
        cout << "\t\tYour score is A+" << endl;
        break;
    }
  }

  if(difficulty == 2 || difficulty == 3) {
    switch (count / 5){
      case 0:
        cout << "\t\tYour score is F" << endl;
        break;
      case 1:
        cout << "\t\tYour score is E" << endl;
        break;
      case 2:
        cout << "\t\tYour score is D" << endl;
        break;
      case 3:
        cout << "\t\tYour score is C" << endl;
        break;
      case 4:
        cout << "\t\tYour score is B" << endl;
        break;
      case 5:
        cout << "\t\tYour score is A" << endl;
        break;
      default:
        cout << "\t\tYour score is A+" << endl;
        break;
      }
  }

  if(difficulty == 4){
    switch (count / 2){
      case 0:
        cout << "\t\tYour score is C" << endl;
        break;
      case 1:
        cout << "\t\tYour score is B" << endl;
        break;
      case 2:
        cout << "\t\tYour score is A" << endl;
        break;
      default:
        cout << "\t\tYour score is A+" << endl;
        break;
    }
  }

  cout <<"\n\n\n\t\t*********************************************\033[0m\n";
}
