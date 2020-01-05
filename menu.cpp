/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description: Menu class creates reusable menus. It includes a constructor
**		          to initialze the menu with the user's options, a function
**		          to display the menu, a user-input validation function, and
**              a destructor to free up vector memory.	
********************************************************************/

#include "menu.hpp"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;


/********************************************
 ** Function:     Menu constructor
 ** Description:  Instantiates menu class, adding visual choices and the 
 **               choices to be entered by the user to vectors.
 ** Parameters:       Takes in a vector of strings representing the user's
 **                   choices and a vector of integers representing the 
 **                   valid input options.
 ** Pre-Conditions:   Both parameters must be vectors of the same length
 ** Post-Conditions:  Creates menu object
 ********************************************/
Menu::Menu(vector<string> &displayedChoices, vector<int> &menuInputIn) {
  menuSize = menuInputIn.size();
  for (int i = 0; i < menuSize; i++) {
    menuChoices.push_back(displayedChoices[i]);
    menuInput.push_back(menuInputIn[i]);
  }
}


/********************************************
 ** Function:     getMenu
 ** Description:  Prints the menu 
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Returns nothing.
 ********************************************/
/* Prints the menu. Has no parameters. Returns nothing. */
void Menu::getMenu() {
  for (string val : menuChoices) {
    cout << val << endl;
  }
}


/********************************************
 ** Function:     getUserChoice
 ** Description:  Validates the user's choice. 
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Returns the menu choice.
 ********************************************/
int Menu::getUserChoice() {
  string userChoice;
  bool isIntegerFlag;

  while (true) {
    getMenu();
    isIntegerFlag = true;
    getline(cin, userChoice);
    for (unsigned i = 0; i < userChoice.length(); i++) {
      if (!isdigit(userChoice[i])) {
        isIntegerFlag = false;
      };
    };

    // if validated integer
    if (isIntegerFlag && userChoice.length() != 0) {
      int numUserChoice = stoi(userChoice); // convert string to int
      for (int i = 0; i < menuSize; i++) {
        if (numUserChoice == menuInput[i]) {
          return numUserChoice;
        };
      };
    }
  cout << "\nPlease choose a valid menu option." << endl;      
  }
}

/********************************************
 ** Function:     Menu destructor
 ** Description:  Free menu class from memory leaks 
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  vectors are gone
 ********************************************/
Menu::~Menu() {
  // delete menuChoice and menuInput vectors
  vector<string>().swap(menuChoices);
  vector<int>().swap(menuInput);
};