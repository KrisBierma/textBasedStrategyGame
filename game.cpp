

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "displayRoundMenu.hpp"
#include "menu.hpp"
#include "space.hpp"
#include "game.hpp"
#include "helpers.hpp"
#include "itemToggle.hpp"
//whre is itemLight.hpp ?????

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::vector;

Game::Game() {

};

Game::~Game() {

};

int Game::getTotalRounds() {
  return totolRounds;
}

int Game::getCurrentRoundNum() {
  return currentRoundNum;
}

void Game::displayIntro() {
  // display title, opening description, and directions
  cout << "\nThe Secret Treasure\n\n";
  cout << "long intro\n\n";
  cout << "Directions: You have " << totolRounds << " hours to find the key. An hour is equal to a move from one space to another. Hope you win!\n";
}

// display numRounds
void Game::showNewRound(Space *currentSpace) {
  string stars = "*******";
  cout << endl << stars << " Round " << currentRoundNum << "/" << totolRounds;
  cout << "  " << makeCaptial(currentSpace->getSpaceNameForPrinting());
  cout  << " " << stars << endl;  
}

void Game::updateRoundNum() {
  currentRoundNum++;
};

int Game::getUserChoiceForThisSpace() {
  return userChoiceForThisSpace;
};

int Game::getCurrentMenuNum() {
  return currentMenuNum;
}

int Game::getNumPossibleMoves() {
  return numPossibleMoves;
}

Space* Game::getMoveWhere() {
  return moveWhere;
}

string Game::getNameOfDroppedItem() {
  return nameOfDroppedItem;
};

int Game::getNumForItem() {
  return numForItem;
};

bool Game::getHasBackpack() {
  return hasBackpack;
}

bool Game::setHasBackpack() {
  hasBackpack = true;
};


void Game::resetOptions() {
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


void Game::displayRoundMenu(Space *currentSpace, vector<string> backpack, map<string, string> &droppedItemsMap) {
  resetOptions();

  // create menu
  vector<string> spaceMenuChoices;
  // int currentMenuNum = 1;

  string choice;
  // get possible spaces to move to
  Space *s = currentSpace;
  vector<Space*> tempHolder = currentSpace->getSpacePointers();
  numPossibleMoves = tempHolder.size();

  // add "go to" options to menu
  // if there's a ptr depend and it's not toggled on, don't add that pointer to menu
  if (s->getHasPointerDependency) {
    Item *itemP = s->getItemPtrDependentOn();
    if (!static_cast<ItemToggle*>(itemP)->getOn()) {
      // find this space ptr in tempHolder
      for (int k = 0; k < tempHolder.size(); k++) {
        if (tempHolder[k] == s->getSpacePtrDepend()) {
          // remove ptr from tempHolder
          tempHolder.erase(tempHolder.begin()+k);
        }
      }
      numPossibleMoves = tempHolder.size();
    }
  }
  for (unsigned j = 0; j < tempHolder.size(); j++) {
    // if (tempHolder[j])
    choice = "" + toString(j+1) + ": Go to ";
    choice += tempHolder[j]->getSpaceNameForPrinting();
    spaceMenuChoices.push_back(choice);
    currentMenuNum++;
  }


  // add items to menu
  int numForItem;
  map<int,string> droppedItemsMenuNums;
  // add backpack to menu if the currentSpace is house
  // add current space's item to menu if there is one and it's still in it's original location and the user has a backpack and the current room's dependency is True
  // add items that have been dropped in currentSpace
  if ((s->getHasItem() && !s->isItemTaken() && hasBackpack && !s->hasSpaceDependency())  || (s->getSpaceName() == "house" && !s->isItemTaken())) {
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


  // add dropped items to menu
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
  // int openBackpackNum = -1, dropItemNum = -1, useItemNum = -1;
  // string nameOfDroppedItem;
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


  vector<int> spaceMenuNums;
  for (unsigned k = 1; k < spaceMenuChoices.size()+1; k++) {
    spaceMenuNums.push_back(k);
  }

  // instantiate roundMenu
  Menu roundMenu(spaceMenuChoices, spaceMenuNums);

  // display menu, get user's choice
  cout << endl << endl;
  int userChoice = roundMenu.getUserChoice();
  cout << endl;

  // cout <<"userChoice: "<<userChoice<<endl;

  if (userChoice >= 1 && userChoice <= numPossibleMoves) {
    move = true;
    // find the user's choice in the currentSpace's spacePointers
    moveWhere = tempHolder[userChoice-1];
  }
  else if (userChoice == openBackpackNum) {
    // cout <<"openback=tru\n";
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
    // cout <<"in !dropped..\n";
    // map<int, string>::iterator itr;
    nameOfDroppedItem = droppedItemsMenuNums.find(userChoice)->second;
    pickUpDroppedItem = true;
    // cout << "....."<<nameOfDroppedItem<<endl;
  }
  else {
    nameOfDroppedItem = "none";
  }

  userChoiceForThisSpace = userChoice;
};