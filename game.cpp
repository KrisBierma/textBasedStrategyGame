

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
  return totalRounds;
}

int Game::getCurrentRoundNum() {
  return currentRoundNum;
}

void Game::displayIntro() {
  // display title, opening description, and directions
  cout << "\nThe Secret Treasure\n\n";
  cout << "long intro\n\n";
  cout << "Directions: You have " << totalRounds << " hours to find the key. An hour is equal to a move from one space to another. Hope you win!\n";
}

// display numRounds
void Game::showNewRound(Space *currentSpace) {
  string stars = "*******";
  cout << endl << stars << " Round " << currentRoundNum << "/" << totalRounds;
  cout << "  " << makeCaptial(currentSpace->getSpaceNameForPrinting());
  cout  << " " << stars << endl;  
}

void Game::updateRoundNum() {
  currentRoundNum++;
  // cout <<"in roundNum\n";
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

void Game::setHasBackpack() {
  hasBackpack = true;
};


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

  string choice;
  // get possible spaces to move to
  Space *s = currentSpace;
  vector<Space*> tempHolder = currentSpace->getSpacePointers();
  numPossibleMoves = tempHolder.size();

  // add "go to" options to menu
  // if there's a ptr depend and it's not toggled on, don't add that pointer to menu
  // cout <<"beforedep\n";
  if (s->getHasPointerDependency()) {
    Item *itemP = s->getItemPtrDependentOn();
    // cout <<itemP<<endl;
      // cout <<" in beforedep\n";
      // bool x = static_cast<ItemToggle*>(itemP)->getOn();
      // cout << "x: " <<x <<endl;
// cout <<static_cast<ItemToggle*>(itemP)->getOn()<<endl;
// cout <<!static_cast<ItemToggle*>(itemP)->getOn()<<endl;

    if (!static_cast<ItemToggle*>(itemP)->getOn()) {
      // find this space ptr in tempHolder
      // cout <<"in if\n";
      for (int k = 0; k < tempHolder.size(); k++) {
        // cout <<k<<endl;
        if (tempHolder[k] == s->getSpacePtrDepend()) {
          // remove ptr from tempHolder
          // cout <<"in erase  k: "<<k<<endl;
          tempHolder.erase(tempHolder.begin()+k);
// cout <<"after\n";
        }
      }
      numPossibleMoves = tempHolder.size();
    }
  }
  // cout << "\nsize: "<<tempHolder.size() <<endl;

  for (unsigned j = 0; j < tempHolder.size(); j++) {
    // if (tempHolder[j])
    choice = "" + toString(j+1) + ": Go to ";
    choice += tempHolder[j]->getSpaceNameForPrinting();
    spaceMenuChoices.push_back(choice);
    currentMenuNum++;
  }

// cout <<"there\n";
  // add items to menu
  map<int,string> droppedItemsMenuNums;


  // add items if the space has one and it's not already taken
  bool addItemIf = s->getHasItem() && !s->isItemTaken();
  // add backpack to menu if the currentSpace is house
  // bool addBackpackToMenu = s->getSpaceName() == "house" && !s->isItemTaken();
  bool addBackpack = s->getSpaceName() == "house";
  // add current space's item to menu if there is one and it's still in it's original location and the user has a backpack and the current room's dependency is True (or is it false???????)
  bool addItem = hasBackpack && !s->hasSpaceDependency();
  // add item if the space's depend is flashlight and it's on
  bool addFlashlight = s->hasSpaceDependency() && (s->getSpaceDependency()->getItemName() == "flashlight") && static_cast<ItemToggle*>(s->getSpaceDependency())->getOn();
  // bool addItem2 = hasBackpack;
  // add item if dependency is done, ex: show key if crackers given to parrot
  bool addItemAfterDepen = s->hasSpaceDependency() && s->getItemDepenDone();
// cout << "\nadditemafterdepn: "<< addItemAfterDepen <<endl;
// if (s->getHasItem()) {
// cout <<s->getItem()->getItemNameForPrinting()<<endl;

// }
  // add item if 
// cout << endl<<s->getHasItem()<<endl;
// if (s->getHasItem()) {
//   cout << s->isItemTaken()<<endl;
// }
// cout << s->hasSpaceDependency()<<endl;
// if (s->hasSpaceDependency()) {
//   cout <<"in if\n";
//   cout << (s->getSpaceDependency()->getItemName() == "flashlight")<<endl;
//   cout << (static_cast<ItemToggle*>(s->getSpaceDependency())->getOn())<<endl;
// }

  if (addItemIf && (addBackpack || addItem || addFlashlight || addItemAfterDepen)) {
  // if (addBackpackToMenu || addItem || addItemFlash || addItem2) {
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
// cout <<"numForItem\n";

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

// cout <<"hasBack\n";
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
  // cout << endl;

  // cout <<"userChoice: "<<userChoice<<endl;

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

void Game::gameOver() {
  cout << "Game over" << endl;
}