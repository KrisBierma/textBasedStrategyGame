/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	Game class holds information for game play, creates the
**              menu for each round, and displays game intro, round and
**              end game information.
********************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "game.hpp"
#include "menu.hpp"
#include "space.hpp"
#include "helpers.hpp"
#include "itemToggle.hpp"
#include "stairsSpace.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;


/********************************************************************
 * Getters and setters for the rounds
********************************************************************/
int Game::getTotalRounds() {
  return totalRounds;
}

int Game::getCurrentRoundNum() {
  return currentRoundNum;
}

void Game::updateRoundNum() {
  currentRoundNum++;
};


/********************************************************************
 * Getters and setters for menu relaying user choice to main.cpp
********************************************************************/
int Game::getUserChoiceForThisSpace() {
  return userChoiceForThisSpace;
};

Space* Game::getMoveWhere() {
  return moveWhere;
}

string Game::getNameOfDroppedItem() {
  return nameOfDroppedItem;
};

int Game::getNumForItem() {
  return numForItem;
};

bool Game::getMove() {
  return move;
};

bool Game::getPickUpDroppedItem() {
  return pickUpDroppedItem;
};

bool Game::getOpenBackpack() {
  return openBackpack;
};

bool Game::getDropItem() {
  return dropItem;
};

bool Game::getUseItem() {
  return useItem;
};

bool Game::getQuit() {
  return quit;
};


/********************************************************************
 * Getters and setters for game play
********************************************************************/
bool Game::getHasBackpack() {
  return hasBackpack;
}


/********************************************
 ** Function:     displayIntro
 ** Description:  displays title, opening description, and directions
 ** Parameters:   none 
 ** Pre-Conditions:   none
 ** Post-Conditions:  Displays intro
 ********************************************/
void Game::displayIntro() {
  cout << "\nThe Secret Treasure\n\n";
  cout << "Your wealthy uncle has died, and his enigmatic will says something about a key and his greatest treasure. The lawyer looks over his glasses at the ten of you, \"You know he liked a good challenge. He's given you 48 hours to find the key and the hidden treasure. If one of you hasn't, the treasure will be forfeit and given to charity.\"\n\nEveryone walks out of the mansion in shock (he was a great guy and he was very wealthy) and into the bright sunshine. The words \"key\" and \"greatest treasure\" are ringing through everyone's mind and, without a word, everyone scatters in different directions.\n\n";
  cout << "Directions: You have " << totalRounds << " hours to find the key. An hour is equal to a move from one space to another. Hope you win!\n\n";
  
  cout << "Press the Enter key to continue...";
  cin.get();
}


/********************************************
 ** Function:     showNewRound
 ** Description:  Shows a header at the start of each round
 **               with the round #, total possible rounds
 **               and space's name
 ** Parameters:   Pointer to the player's current space object
 ** Pre-Conditions:   none
 ** Post-Conditions:  Displays round header info
 ********************************************/
void Game::showNewRound(Space *currentSpace) {
  string stars = "*******";
  cout << endl << stars << " Round " << currentRoundNum << "/" << totalRounds;
  cout << "  " << makeCaptial(currentSpace->getSpaceNameForPrinting());
  cout  << " " << stars << endl;     
}


/********************************************
 ** Function:     resetOptions
 ** Description:  Resets variables for displaying menu
 **               and relaying user's choice back to main.cpp
 ** Parameters:   none
 ** Pre-Conditions:   none
 ** Post-Conditions:  resets menu variables
 ********************************************/
// reset for each round
void Game::resetOptions() {
  currentMenuNum = 1;
  move = false;
  pickUpDroppedItem = false;
  openBackpack = false;
  dropItem = false;
  useItem = false;
  quit = false;
  openBackpackNum = -1;
  pickUpDroppedItemNum = -1;
  dropItemNum = -1;
  nameOfDroppedItem = "";
  useItemNum = -1;
};


/********************************************
 ** Function:     displayRoundMenu
 ** Description:  Creates the menu for each round depending on input from main.cpp
 **               Includes spaces to move to, items to use, drop or see.
 **               Gets the user's choice and feeds back to main.
 ** Parameters:   Space pointer of current location of player,
 **               vector of items in the backpack, reference
 **               to map holding items dropped and where they
 **               were dropped
 ** Pre-Conditions:   none
 ** Post-Conditions:  
 ********************************************/
void Game::displayRoundMenu(Space *currentSpace, vector<string> backpack, map<string, string> &droppedItemsMap) {
  resetOptions();

  // create menu
  vector<string> spaceMenuChoices;

  string choice;
  // get possible spaces to move to
  Space *s = currentSpace;
  vector<Space*> tempHolder = currentSpace->getSpacePointers();
  numPossibleMoves = tempHolder.size();

  // add "go to" options to menu
  // if there's a ptr depend and it's not toggled on, don't add that pointer to menu
  if (s->getHasPointerDependency()) {
    Item *itemP = s->getItemPtrDependentOn();

    if (!static_cast<ItemToggle*>(itemP)->getOn()) {
      // find this space ptr in tempHolder
      for (unsigned k = 0; k < tempHolder.size(); k++) {
        if (tempHolder[k] == s->getSpacePtrDepend()) {
          // remove ptr from tempHolder
          tempHolder.erase(tempHolder.begin()+k);
        }
      }
      numPossibleMoves = tempHolder.size();
    }
  }

  // add option to move to spaces linked to current space
  string preposition = "";
  int loc = -1;
  if (s->getSpaceType() == "stairs") {
    // loc = stairsLocation: 0=underground, 1=aboveGround
    loc = static_cast<StairsSpace*>(s)->getLocation();
  };

  for (unsigned j = 0; j < tempHolder.size(); j++) {
    if (s->getSpaceType() == "stairs") {
      if ((loc == 0 && tempHolder[j]->getSpaceType() == "groundFloor") || (loc == 1 && tempHolder[j]->getSpaceType() == "aboveGround")) {
        preposition = "up to";
      }
      else {
        preposition = "down to";
      }
    }
    else {
      preposition = "to";
    }
    choice = "" + toString(j+1) + ": Go " + preposition + " ";
    choice += tempHolder[j]->getSpaceNameForPrinting();
    spaceMenuChoices.push_back(choice);
    currentMenuNum++;
  }

  // for holding dropped items to add to menu
  map<int,string> droppedItemsMenuNums;

  // add items if the space has one and it's not already taken
  bool addItemIf = s->getHasItem() && !s->isItemTaken();
  // add backpack to menu if the currentSpace is house
  bool addBackpack = s->getSpaceName() == "house";
  // add current space's item to menu if there is one and it's still in it's original location and the user has a backpack and the current room's dependency is false
  bool addItem = hasBackpack && !s->hasSpaceDependency();
  // add item if the space's depend is flashlight and it's on
  bool addFlashlight = s->hasSpaceDependency() && (s->getSpaceDependency()->getItemName() == "flashlight") && static_cast<ItemToggle*>(s->getSpaceDependency())->getOn();
  // add item if dependency is done, ex: show key if crackers given to parrot
  bool addItemAfterDepen = s->hasSpaceDependency() && s->getItemDepenDone();

  if (addItemIf && (addBackpack || addItem || addFlashlight || addItemAfterDepen)) {
    choice = toString(currentMenuNum) + ": ";
    choice += s->getItem()->getVerbForAction() + " ";
    choice += s->getItem()->getItemNameForPrinting();

    spaceMenuChoices.push_back(choice);
    numForItem = currentMenuNum;
    currentMenuNum++;
  }
  else {
    // if no item available
    numForItem = -1;
  }

  // add items that have been dropped in currentSpace
  if (hasBackpack && !droppedItemsMap.empty()) {
    // go through droppedItems map and find the ones dropped in current space, add them to the menu
    map<string, string>::iterator itr;
    for (itr = droppedItemsMap.begin(); itr != droppedItemsMap.end(); ++itr) {
      if (itr->second == currentSpace->getSpaceName()) {
        // add to menu
        choice = toString(currentMenuNum) + ": Take the ";
        choice += itr->first;
        spaceMenuChoices.push_back(choice);
        droppedItemsMenuNums.insert(pair<int,string>(currentMenuNum, itr->first));
        currentMenuNum++;
      }
    }    
  }

  // add openBackpack, dropItem, and useItem to menu choices
  if (hasBackpack) {
    choice = toString(currentMenuNum) + ": Open backpack";
    spaceMenuChoices.push_back(choice);
    openBackpackNum = currentMenuNum;
    currentMenuNum++;
  }
  if (hasBackpack && !backpack.empty()) {
    choice = toString(currentMenuNum) + ": Drop item";
    spaceMenuChoices.push_back(choice);
    dropItemNum = currentMenuNum;
    currentMenuNum++;
    choice = toString(currentMenuNum) + ": Use item";
    spaceMenuChoices.push_back(choice);
    useItemNum = currentMenuNum;
    currentMenuNum++;
  }

  // add quit to menu choices
  choice = toString(currentMenuNum) + ": I quit";
  spaceMenuChoices.push_back(choice);

  // to use in instantiating roundMenu
  vector<int> spaceMenuNums;
  for (unsigned k = 1; k < spaceMenuChoices.size()+1; k++) {
    spaceMenuNums.push_back(k);
  }

  // instantiate roundMenu
  Menu roundMenu(spaceMenuChoices, spaceMenuNums);

  // display menu, get user's choice
  int userChoice = roundMenu.getUserChoice();
  cout << endl;

  if (userChoice >= 1 && userChoice <= numPossibleMoves) {
    move = true;
    // find the user's choice in the currentSpace's spacePointers
    moveWhere = tempHolder[userChoice-1];
  }
  else if (userChoice == numForItem) {
    takeItem = true;
    if (s->getItem()->getItemName() == "backpack") {
      hasBackpack = true;
    }
  }
  else if (userChoice == openBackpackNum) {
    openBackpack = true;
  }
  else if (userChoice == dropItemNum) {
    dropItem = true;
  }
  else if (userChoice == useItemNum) {
    useItem = true;
  }
  else if (userChoice == currentMenuNum) {
    quit = true;
  }
  else if (!droppedItemsMenuNums.empty()) {
    nameOfDroppedItem = droppedItemsMenuNums.find(userChoice)->second;
    pickUpDroppedItem = true;
  }
  else {
    nameOfDroppedItem = "none";
  }

  userChoiceForThisSpace = userChoice;
};


/********************************************
 ** Function:     displayRanOutOfTime
 ** Description:  Display "out of turns" message
 ** Parameters:   none
 ** Pre-Conditions:   none
 ** Post-Conditions:  Displays message
 ********************************************/
void Game::displayRanOutOfTime() {
  cout << "It's been 48 hours and you ran out of time!\n\n";
};


/********************************************
 ** Function:     gameOver
 ** Description:  Displays game over
 ** Parameters:   none
 ** Pre-Conditions:   Game ends by win or running out of turns
 ** Post-Conditions:  displays game over
 ********************************************/
void Game::gameOver() {
  string stars = "*******";
  cout << stars << " Game over " << stars << endl << endl;
}

