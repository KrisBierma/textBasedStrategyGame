/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma
** Date:	      11/19/19
** Description:	Wild animals fighting simulation. Five different animals
**              (elephant, bear, meerkats, spider and cat) have different
**              attack, defense, armor and strenght abilities. The user
**              chooses two animals, one is the attacker and one the 
**              defender, and they go for rounds until one animal dies.
**              The loser moves to the loser container (and leave their
**              group's container) and the winner goes to the back of 
**              their group's container.
********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <sstream>
#include <tuple>
// #include <algorithm>
#include "menu.hpp"
#include "space.hpp"
#include "spaceDescrip.hpp"
#include "displayRoundMenu.hpp"
#include "inputValidation.hpp"
#include "stairsSpace.hpp"
#include "aboveGroundSpace.hpp"
#include "undergroundSpace.hpp"
#include "groundLevelSpace.hpp"
using std::map;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::tuple;
// using std::remove_if;
using std::stringstream;

int chooseItemFromBackpack(vector<string> &backpack);
string makeCaptial(string wordIn);

int main() {
  // showStartMenu
  vector<string> menuChoices = {"1. Play game", "2. Exit"};
  vector<int> menuNumbers = {1, 2};
  Menu startMenu(menuChoices, menuNumbers);
  int userChoice = startMenu.getUserChoice();

  // playGame  
  bool quit = false;
  while (userChoice != 2 && !quit) {
    int numRounds = 36;
    int currentRoundNum = 1;

    // set up backpack vector container with random-access iterator
    vector<string> backpack;
    bool hasBackpack = false;

    // container to hold completed dependency actions (dependency items are checked in the backpack)
    // vector<string> dependencyVec;
    // dependency actions
    bool lightSwitchedOn = false;
    bool powerButtonPushed = false;

    // map to hold dropped items: key is item, value is space
    map<string, string> droppedItemsMap;

    // instantiate spaces
      GndLvlSpace trainStation;
      GndLvlSpace trainLocomotive;
      GndLvlSpace trainPassengerCar;
      GndLvlSpace chapelPews;
      GndLvlSpace chapelFront;
      StairsSpace chapelStairs;
      UndergroundSpace chapelSecretPassW;
      UndergroundSpace chapelSecretPassE;
      StairsSpace zooStairs;
      GndLvlSpace zooEntry;
      GndLvlSpace zooParrots;
      GndLvlSpace zooLlamas;
      GndLvlSpace house;
      GndLvlSpace courtyard;
      GndLvlSpace trees;
      GndLvlSpace libEntry;
      GndLvlSpace libOffice;
      StairsSpace libStairs;
      GndLvlSpace libWindowSeat;
      GndLvlSpace libStacks;
      UndergroundSpace libBasement;
      AboveGroundSpace libMapRoom;
      StairsSpace libMapRmStairs;
      AboveGroundSpace libSecretTower;

    // set pointers to space objects for use in main.cpp
      // Space *trainStationP = &trainStation;
      // Space *trainLocomotiveP = &trainLocomotive;
      // Space *trainPassengerCarP = &trainPassengerCar;
      // Space *chapelPewsP = &chapelPews;
      // Space *chapelFrontP = &chapelFront;
      // Space *chapelStairsP = &chapelStairs;
      // Space *chapelSecretPassWestP = &chapelSecretPassW;
      // Space *chapelSecretPassEastP = &chapelSecretPassE;
      // Space *zooStairsP = &zooStairs;
      // Space *zooEntryP = &zooEntry;
      // Space *zooParrotsP = &zooParrots;
      // Space *zooLlamasP = &zooLlamas;
      // Space *houseP = &house;
      // Space *courtyardP = &courtyard;
      // Space *treesP = &trees;
      // Space *libEntryP = &libEntry;
      // Space *libOfficeP = &libOffice;
      // Space *libStairsP = &libStairs;
      // Space *libWindowSeatP = &libWindowSeat;
      // Space *libStacksP = &libStacks;
      // Space *libBasementP = &libBasement;
      // Space *libMapRoomP = &libMapRoom;
      // Space *libMapRmStairsP = &libMapRmStairs;
      // Space *libSecretTowerP = &libSecretTower;

    // set pointers to derived classes for use in spaceDescrip.cpp
      GndLvlSpace *trainStationSpecificP = &trainStation;
      GndLvlSpace *trainLocomotiveSpecificP = &trainLocomotive;
      GndLvlSpace *trainPassengerCarSpecificP = &trainPassengerCar;
      GndLvlSpace *chapelPewsSpecificP = &chapelPews;
      GndLvlSpace *chapelFrontSpecificP = &chapelFront;
      StairsSpace *chapelStairsSpecificP = &chapelStairs;
      UndergroundSpace *chapelSecretPassWestSpecificP = &chapelSecretPassW;
      UndergroundSpace *chapelSecretPassEastSpecificP = &chapelSecretPassE;
      StairsSpace *zooStairsSpecificP = &zooStairs;
      GndLvlSpace *zooEntrySpecificP = &zooEntry;
      GndLvlSpace *zooParrotsSpecificP = &zooParrots;
      GndLvlSpace *zooLlamasSpecificP = &zooLlamas;
      GndLvlSpace *houseSpecificP = &house;
      GndLvlSpace *courtyardSpecificP = &courtyard;
      GndLvlSpace *treesSpecificP = &trees;
      GndLvlSpace *libEntrySpecificP = &libEntry;
      GndLvlSpace *libOfficeSpecificP = &libOffice;
      StairsSpace *libStairsSpecificP = &libStairs;
      GndLvlSpace *libWindowSeatSpecificP = &libWindowSeat;
      GndLvlSpace *libStacksSpecificP = &libStacks;
      UndergroundSpace *libBasementSpecificP = &libBasement;
      AboveGroundSpace *libMapRoomSpecificP = &libMapRoom;
      StairsSpace *libMapRmStairsSpecificP = &libMapRmStairs;
      AboveGroundSpace *libSecretTowerSpecificP = &libSecretTower;

      Space* trainStationP = dynamic_cast<Space*>(trainStationSpecificP);
      Space *trainLocomotiveP = dynamic_cast<Space*>(trainLocomotiveSpecificP);
      Space *trainPassengerCarP = dynamic_cast<Space*>(trainPassengerCarSpecificP);
      Space *chapelPewsP = dynamic_cast<Space*>(chapelPewsSpecificP);
      Space *chapelFrontP = dynamic_cast<Space*>(chapelFrontSpecificP);
      Space *chapelStairsP = dynamic_cast<Space*>(chapelStairsSpecificP);
      Space *chapelSecretPassWestP = dynamic_cast<Space*>(chapelSecretPassWestSpecificP);
      Space *chapelSecretPassEastP = dynamic_cast<Space*>(chapelSecretPassEastSpecificP);
      Space *zooStairsP = dynamic_cast<Space*>(zooStairsSpecificP);
      Space *zooEntryP = dynamic_cast<Space*>(zooEntrySpecificP);
      Space *zooParrotsP = dynamic_cast<Space*>(zooParrotsSpecificP);
      Space *zooLlamasP = dynamic_cast<Space*>(zooLlamasSpecificP);
      Space *houseP = dynamic_cast<Space*>(houseSpecificP);
      Space *courtyardP = dynamic_cast<Space*>(courtyardSpecificP);
      Space *treesP = dynamic_cast<Space*>(treesSpecificP);
      Space *libEntryP = dynamic_cast<Space*>(libEntrySpecificP);
      Space *libOfficeP = dynamic_cast<Space*>(libOfficeSpecificP);
      Space *libStairsP = dynamic_cast<Space*>(libStairsSpecificP);
      Space *libWindowSeatP = dynamic_cast<Space*>(libWindowSeatSpecificP);
      Space *libStacksP = dynamic_cast<Space*>(libStacksSpecificP);
      Space *libBasementP = dynamic_cast<Space*>(libBasementSpecificP);
      Space *libMapRoomP = dynamic_cast<Space*>(libMapRoomSpecificP);
      Space *libMapRmStairsP = dynamic_cast<Space*>(libMapRmStairsSpecificP);
      Space *libSecretTowerP = dynamic_cast<Space*>(libSecretTowerSpecificP);
// https://stackoverflow.com/questions/5662719/c-comparing-pointers-of-base-and-derived-classes

    // push ALL space object pointers to container
      vector<Space*> spaceVector = {trainStationP, trainLocomotiveP, trainPassengerCarP, chapelPewsP, chapelFrontP, chapelStairsP, chapelSecretPassWestP, chapelSecretPassEastP, zooStairsP, zooEntryP, zooParrotsP, zooLlamasP, houseP, courtyardP, treesP, libEntryP, libOfficeP, libStairsP, libWindowSeatP, libStacksP, libBasementP, libMapRoomP, libMapRmStairsP, libSecretTowerP};
    
    // tuple of derived class pointers
      tuple<GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, UndergroundSpace*, UndergroundSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, UndergroundSpace*, AboveGroundSpace*, StairsSpace*, AboveGroundSpace*> spaceTuple(trainStationSpecificP, trainLocomotiveSpecificP, trainPassengerCarSpecificP, chapelPewsSpecificP, chapelFrontSpecificP, chapelStairsSpecificP, chapelSecretPassWestSpecificP, chapelSecretPassEastSpecificP, zooStairsSpecificP, zooEntrySpecificP, zooParrotsSpecificP, zooLlamasSpecificP, houseSpecificP, courtyardSpecificP, treesSpecificP, libEntrySpecificP, libOfficeSpecificP, libStairsSpecificP, libWindowSeatSpecificP, libStacksSpecificP, libBasementSpecificP, libMapRoomSpecificP, libMapRmStairsSpecificP, libSecretTowerSpecificP);

    // set up spaces (data, descriptions, etc)
    setUpSpaceDescriptions(spaceTuple);  

    // starting space is the house
    Space *currentSpace = houseP;

    // display title, opening description, and directions
    cout << "\nThe Secret Treasure\n\n";
    cout << "long intro\n\n";
    cout << "Directions: You have " << numRounds << " hours to find the key. An hour is equal to a move from one space to another. Hope you win!\n";

    // dependency toggles
    bool flashlightOn = false;

    // loop for each turn
    while (!quit && currentRoundNum <= numRounds) {
      bool endRound = false;
      // display numRounds
      string stars = "*******";
      cout << endl << stars << " Round " << currentRoundNum << "/" << numRounds;
      cout << "  " << makeCaptial(currentSpace->getSpaceNameForPrinting());
      cout  << " " << stars << endl;

      // description for current location
      cout << currentSpace->getSpaceDescription();

      // item description
      if (currentSpace->isItemTaken() == false) {
        cout << endl << currentSpace->getItemDescription();
      }

      // loop menu and possible actions until user move's location
      while (!endRound && !quit) {
        // data array to be filled
        int infoArray[8];
        int numPossibleMoves = currentSpace->getSpacePointers().size();
        
        // show roundMenu and get data from it and user's choice
        string nameOfDroppedItem = displayRoundMenu(infoArray, hasBackpack, currentSpace, backpack, droppedItemsMap, numPossibleMoves, lightSwitchedOn, powerButtonPushed);

        int userChoiceForThisSpace = infoArray[0];
        int currentMenuNum = infoArray[1];
        int numForItem = infoArray[2];
        bool printBackpack = infoArray[3];
        bool dropItem = infoArray[4];
        int useItem = infoArray[5];
        int pickUpDroppedItem = infoArray[6];
        // int numOfDroppedItem = infoArray[7];


        // act according to user's choice
        if (userChoiceForThisSpace == currentMenuNum) {
          quit = true;
        }
        else {
          // move user
          if (userChoiceForThisSpace >= 1 && userChoiceForThisSpace <= numPossibleMoves) {

            // find the user's choice in the currentSpace's spacePointers (from class)
            vector<Space*> tempVec = currentSpace->getSpacePointers();
            string tempName = tempVec[userChoiceForThisSpace-1]->getSpaceName();

            // search through spaceVector (from main) to find the space that matches the user's move choice
            for (auto i : spaceVector) {
              if (i->getSpaceName() == tempName) {
                // cout << "I found it!\n";
                // cout << i << endl;

                // check if it's dependent on flashlight
                if (i->getSpaceDependency() == "flashlight" && !flashlightOn) {
                  cout << "It's too dark in there.\n";

                }
                else {
                  // cout << "space Depen: "<< i->getSpaceDependency() << endl;
                  // cout <<"flashlight on? "<<flashlightOn<<endl;
                  currentSpace = i;
                  currentRoundNum++;
                  endRound = true;                  
                }
              }
            }
          }

          // display backpack
          else if (printBackpack) {
            // cout <<"in printbackpack\n";
            if (backpack.empty()) {
              cout << "Your backpack is empty.\n";
            }
            else {
              cout << "You've got: ";
              if (backpack.size() == 1) {
                cout << backpack[0];
              }
              else {
                for (unsigned i = 0; i < backpack.size(); i++) {
                  cout << backpack[i] << ", ";
                }
                cout << backpack[backpack.size()];
              }
              cout << endl;              
            }
          }

          // drop item
          else if (dropItem) {
            cout << "What do you want to drop?\n";
            // get item to be dropped from user
            unsigned item = chooseItemFromBackpack(backpack);

            // if last number, do nothing
            if (item < backpack.size()) {
              // cout << backpack[item] << endl;

              // add to droppedItems container
              // key-item, value-current space
              droppedItemsMap.insert(pair<string, string>(backpack[item], currentSpace->getSpaceName()));

              // remove from backpack
              backpack.erase(backpack.begin()+item);

              // cout << "backpace size: "<<backpack.size()<<"  "<<backpack.empty();

              // delete
              map<string, string>::iterator itr;
              for (itr = droppedItemsMap.begin(); itr != droppedItemsMap.end(); ++itr) {
                cout << '\t' << itr->first << "\t" << itr->second << '\n';
              }
            }
          }

          // use item
          else if (useItem) {
            cout << "What do you want to use?\n";
            // get item to be used from user
            unsigned item = chooseItemFromBackpack(backpack);

            // if last num on menu, do nothing
            if (item < backpack.size()) {
              if (currentSpace->getSpaceDependency() == backpack[item] && currentSpace->getSpaceDependency() != "flashlight") {
                cout <<"Yes, use it here!\n";
                currentSpace->getDescriptionAfterDependency();
              }
              else if (backpack[item] == "flashlight") {
                flashlightOn = !flashlightOn;
                if (flashlightOn) {
                  cout << "The flashlight is on.\n";
                }
                else {
                  cout << "The flashlight is off.\n";
                }
              }
              else {
                cout << "That does nothing here.\n";
                //That's of no use here.
                //What good would that do?
              }
            }
          }

          // pick up dropped item
          else if (pickUpDroppedItem) {
            // add to backpack
            backpack.push_back(nameOfDroppedItem);
            // remove from droppedItem map
            map<string, string>::iterator itr;
            itr = droppedItemsMap.find(nameOfDroppedItem);
            droppedItemsMap.erase(itr);
          }

          // do action on item
          else if (userChoiceForThisSpace == numForItem) {
            int actionNum = currentSpace->getItemActionNum();

            // if itemAction isn't 1, add to dependencyVec
            // if (actionNum != 1) {
            //   dependencyVec.push_back()
            // }
            // mark finished dependencies
            if (currentSpace->getItemName() == "lightSwitch") {
              lightSwitchedOn = true;
            } 
            else if (currentSpace->getItemName() == "powerButton") {
              powerButtonPushed = true;
            }

            // get backpack
            if (currentSpace->getItemName() == "backpack") {
              hasBackpack = true;
              currentSpace->setItemTaken(true);
            }

            // put item in backpack unless it IS the backpack
            if (hasBackpack && actionNum == 1 && currentSpace->getItemName() != "backpack") {
              // mark as taken in object
              currentSpace->setItemTaken(true);

              // add to backpack container
              backpack.push_back(currentSpace->getItemName());
              // cout <<"empty? "<<backpack.empty()<<endl;

              for (string i:backpack) {
                // cout << i << " ";
              }
            }
            else if (actionNum == 2 || actionNum == 3) {
              currentSpace->setItemTaken(true);
            }
            else if (actionNum >= 4 || actionNum <= 7) {
              // do nothing
            }
            else if (actionNum == 8) {
              cout << "how to deal with this??\n";
            }
            // display info after taking action
            cout << currentSpace->getDescriptionAfterItem();
          }
        }        
      }
    }
  }

  // show replay menu if !quit

  return(0);
};


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


// print backpack; returns array index of choice 
int chooseItemFromBackpack(vector<string> &backpack) {
  vector<string> backpackMenuChoices;
  vector<int> backpackMenuNums;
  int currentMenuNum;

  for (unsigned i = 0; i < backpack.size(); i++) {
    string choice = toString(i+1) + ": ";
    choice += backpack[i];
    backpackMenuChoices.push_back(choice);
    backpackMenuNums.push_back(i+1);
    currentMenuNum = i+1;
  }
  // if (whichAction == "drop") {

  // }
  string choice = toString(currentMenuNum+1) + ": never mind";
  backpackMenuChoices.push_back(choice);
  backpackMenuNums.push_back(currentMenuNum+1);
 
  Menu backpackMenu(backpackMenuChoices, backpackMenuNums);
  int userChoice = backpackMenu.getUserChoice();
// cout <<"here\n";
  return userChoice-1;
}