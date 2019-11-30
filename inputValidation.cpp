/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma
** Date:	      11/19/19
** Description:	Input validation includes a base function to validate user
**              input for a valid integer (positive, negative or either). 
**              Also validates for specific functions: int greater than 1
**              for an array size and int [1-50] for triangular number. 
********************************************************************/

#include <iostream>
#include <string>
#include "inputValidation.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;


/********************************************
 ** Function:     validateIntegers
 ** Description:  Base function to validate user input is an integer.
 **               Uses helper functions to validatewhether the int is 
 **               positive, negative, or either. 
 ** Parameters:       The specific request to the user to be printed
 **                   1 - positive nums only; 2 - negative nums only; 3 - pos or neg
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns the validated integer
 ********************************************/
int validateIntegers(string messageIn, int posNegBoth) {
  string userChoice;
  bool isIntegerFlag;
  bool isPos = 0, isNeg = 0;
  if (posNegBoth == 1) {
    isPos = true;
  }
  else if (posNegBoth == 2) {
    isNeg = true;
  };

  // loops until something is returned
  while (true) {
    isIntegerFlag = true;
    cout << messageIn;    // instructions to user
    getline(cin, userChoice);

    // check user input for integers
    if (isNeg) {
      if (userChoice[0] == '-') {
        isIntegerFlag = false;
      }
      else {
        isIntegerFlag = checkForNegNum(isIntegerFlag, userChoice);
      }
    }
    else if (isPos) {
      isIntegerFlag = checkForPosNum(isIntegerFlag, userChoice);
    }
    else {
      if (userChoice[0] == '-') {
        isIntegerFlag = checkForNegNum(isIntegerFlag, userChoice);
      }
      else {
        isIntegerFlag = checkForPosNum(isIntegerFlag, userChoice);
      }
    }

    // if the userChoice is an integer...
    if (isIntegerFlag && userChoice.length() != 0) {
      int numUserChoice = stoi(userChoice); // convert string to int
      return numUserChoice;
    }
    else {
      if (isPos) {
        cout << "The number must be a positive integer.\n";
      }
      else {
        cout << "The number must be an integer.\n";
      };
    }
  }
};


/********************************************
 ** Function:     checkForNegNum/checkForPosNum
 ** Description:  Helper functions for validateIntegers to vailidate number is
 **               positive, negative, or either, depending on requirements.
 ** Parameters:       The isIntegerFlag and userChoice from base function
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns true/false
 ********************************************/
bool checkForNegNum(bool isIntegerFlag, string userChoice) {
  for (unsigned i = 1; i < userChoice.length(); i++) {
    if (!isdigit(userChoice[i])) {
      isIntegerFlag = false;
    };
  };  
  return isIntegerFlag;
};


bool checkForPosNum(bool isIntegerFlag, string userChoice) {
  for (unsigned i = 0; i < userChoice.length(); i++) {
    if (!isdigit(userChoice[i])) {
      isIntegerFlag = false;
    };
  }; 
  return isIntegerFlag;
};


/********************************************
 ** Function:     validateStrings
 ** Description:  Validates a string isn't the enter key 
 ** Parameters:       The message to display to user
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns the string
 ********************************************/
string validateStrings(string messageIn) {
  string userChoice;
  while (true) {
    cout << messageIn;
    getline(cin, userChoice);
    if (userChoice.length() != 0 ) {
      return userChoice;
    }
  }
};