#ifndef FUNCTIONS
#define FUNCTIONS
#include <string>
using std::string;


void startScreen_UI();
void chooseWordList_UI();
void gameStart_UI();
void wordlistChange(int);
void chooseAction(int, int&);
void createNewArray(string, string*&, int&);
void setLevelAction(int, int&, string*&, string&, int&);
void receiveInput(string&);
void printWord(string*&, int&, string&);
bool compareWord(string, string);
void inputAction(string&, string&, string*&, int&, int, int&);
void scoreCalculation(int, int);

#endif
