

#include <iostream>
#include <sstream>
#include <vector>
#include "displayRoundMenu.hpp"
#include "menu.hpp"
#include "space.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

int* displayRoundMenu(bool hasBackpack, Space *currentSpace, vector<string> &backpack) {

  // create menu
  vector<string> spaceMenuChoices;
  int currentMenuNum = 1;

  string choice;
  // get possible spaces to move to
  vector<Space*> tempHolder = currentSpace->getSpacePointers();
  
  stringstream ss;
  for (unsigned j = 0; j < tempHolder.size(); j++) {
    ss.str("");   // clear streamstring
    ss << j+1;
    choice = "";
    choice += ss.str();
    choice += ": Go to ";
    // choice += to_string(j) + ": Go to ";
    choice += tempHolder[j]->getSpaceNameForPrinting();
    spaceMenuChoices.push_back(choice);
    currentMenuNum++;
  }
// cout <<"1."<< hasBackpack <<endl;
// cout << currentSpace->getHasItem()<<endl<<!currentSpace->isItemTaken()<<endl;
  // add item to menu if there is one and it's still in it's original location
  // and/or add item that have been dropped????????
  int numForItem;
  if (currentSpace->getHasItem() && !currentSpace->isItemTaken()) {
    // cout << "in add menu item\n";
    ss.str("");   // clear streamstring
    ss << currentMenuNum;
    choice = ss.str();
    // choice = to_string(currentMenuNum);
    choice += ": ";
    choice += currentSpace->getVerbForAction();
    choice += " ";
    choice += currentSpace->getItemNameForPrinting();
    // cout <<choice<<endl;
    spaceMenuChoices.push_back(choice);
    numForItem = currentMenuNum;
    currentMenuNum++;
// cout <<"before item descrip\n";
    cout << currentSpace->getItemDescription() << endl << endl;
  }

  // add seeBackpack and openBackpack to menu choices
  bool openBackpack = false, dropItem = false;
  int openBackpackNum, dropItemNum;
  if (hasBackpack) {
    ss.str("");   // clear streamstring
    ss << currentMenuNum;
    choice = ss.str() + ": Open backpack";
    spaceMenuChoices.push_back(choice);
    openBackpackNum = currentMenuNum;
    currentMenuNum++;
    // openBackpack = true;
  }
  if (hasBackpack && backpack.empty()) {
    ss.str("");   // clear streamstring
    ss << currentMenuNum;
    choice = ss.str() + ": Drop item";
    spaceMenuChoices.push_back(choice);
    dropItemNum = currentMenuNum;
    currentMenuNum++;
    // dropItem = true;
  }


  // add quit to menu choices
  ss.str("");   // clear streamstring
  ss << currentMenuNum;
  choice = ss.str() + ": I quit";
  // choice = to_string(currentMenuNum) + ": I give up. Quit the game.";
  spaceMenuChoices.push_back(choice);


  vector<int> spaceMenuNums;
  for (unsigned k = 1; k < spaceMenuChoices.size()+1; k++) {
    spaceMenuNums.push_back(k);
  }
  // cout << "numChoices: " <<spaceMenuNums.size()<<endl;
  // for (unsigned k = 0; k < spaceMenuChoices.size(); k++) {
  //   cout << spaceMenuNums[k] << " ";
  // }
  // cout <<endl;

  // instantiate roundMenu
  Menu roundMenu(spaceMenuChoices, spaceMenuNums);

  // array to pass back userChoice, currentMenuNum and the item's menu number
  cout << endl << endl;
  int userChoice = roundMenu.getUserChoice();
  cout << endl << endl;

  // if user choice = open backpack num
  if (userChoice == openBackpackNum) {
    openBackpack = true;
  }
  // if user choice = drop item num
  else if (userChoice == dropItemNum) {
    dropItem = true;
  }

  int infoArray[5] = {userChoice, currentMenuNum, numForItem, openBackpack, dropItem};
  int *arrayP = infoArray;

  return arrayP;
};