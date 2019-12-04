
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
// convert ending to add -s
string convertEnding(string word, int num) {
  if (num == 1) {
    return word;
  }
  return word + 's';
};

string makeCaptial(string wordIn) {
  char firstLetter = wordIn.at(0);
  wordIn.erase(0,1);
  return wordIn.insert(0, 1, toupper(firstLetter));
}

string toString(int numIn) {
  stringstream ss;
  ss.str("");   // clear streamstring
  ss << numIn;
  return ss.str();
};