/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	Helper functions to add -s to the ending of plural 
**              words, capitalize the first letter of a string, and
**              convert an int to string.
********************************************************************/
#include <sstream>
#include "helpers.hpp"
using std::stringstream;


/********************************************
 ** Function:     convertEnding
 ** Description:  Helper function to main. Add -s to pluralize words
 ** Parameters:       The word and the number describing it
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns the singular or plural of the word
 ********************************************/
string convertEnding(string word, int num) {
  if (num == 1) {
    return word;
  }
  return word + 's';
};


/********************************************
 ** Function:     makeCaptial
 ** Description:  Helper function to capitalize the first letter of a string
 ** Parameters:       The string
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns the capitalized string
 ********************************************/
string makeCaptial(string wordIn) {
  char firstLetter = wordIn.at(0);
  wordIn.erase(0,1);
  return wordIn.insert(0, 1, toupper(firstLetter));
}


/********************************************
 ** Function:     toString
 ** Description:  Helper function to convert an int to string
 ** Parameters:       the int
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns the int as a string
 ********************************************/
string toString(int numIn) {
  stringstream ss;
  ss.str("");   // clear streamstring
  ss << numIn;
  return ss.str();
};