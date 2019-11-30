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
#include <vector>
#include <sstream> //for to_string
#include "menu.hpp"
#include "space.hpp"
#include "spaceDescrip.hpp"
#include "displayRoundMenu.hpp"
#include "inputValidation.hpp"
// using std::to_string; 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;



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

    // instantiate spaces
    Space house;
    Space trees;
    Space zooEntry;

    // set pointers to space objects
    Space *houseP = &house;
    Space *treesP = &trees;
    Space *zooEntryP = &zooEntry;

    // set up backpack vector container with random-access iterator
    vector<string> backpack;
    bool hasBackpack = false;

    // set data on spaces
    // item actions: 0-nothing, 1-take, 2-flip, 3-push, 4-open, 5-listen, 6-read, 7-look, 8-it's a mess
    house.setData("house", true, "backpack", 1, nullptr, zooEntryP, nullptr, treesP);
    trees.setData("trees", true, "flowers", 1, nullptr, houseP, nullptr, nullptr); // add courtyard
    zooEntry.setData("zooEntry", true, "zoo map", 5, nullptr, nullptr, nullptr, houseP); // add stuff

    // set space descriptions
    house.setDescriptions("the house", "your backpack", "You're in front of the house. No need to go back inside; you're sure the key and treasure are somewhere on your uncle's 40 acre estate.", "Your backpack is sitting on a bench.", "You grab your backpack. It might come in handy.");
    trees.setDescriptions("the copse of trees", "some flowers", "It's cool in the small patch of trees.", "There are some pretty flowers along the path. They smell heavenly.", "Mmm. What will you do with these?!");
    zooEntry.setDescriptions("the zoo entrance", "the sounds", "There are trees overhead. The wind rustles through them.", "You think you hear something else.", "It's the sound of parrots squawking.");

    // add to vector list
    vector<Space*> spaceVector = {houseP, treesP, zooEntryP};
    int len = spaceVector.size();

    // print spaces
    for (int i = 0; i < len; i++) {
      // cout << spaceVector[i]->getSpaceName() << endl;
    }
       
    Space *currentSpace = &house;

    // display title, opening description, and directions
    cout << "The Search for the Key\n\n";
    cout << "long intro\n\n";
    cout << "Directions: You have " << numRounds << " hours to find the key. An hour is equal to a move from one space to another. Hope you win!\n";

    // loop for each turn
    while (!quit && currentRoundNum <= numRounds) {
      bool endRound = false;
      // display numRounds
      cout << endl << "******* Round " << currentRoundNum << "/" << numRounds << " *******" << endl;

      // description for current location
      cout << currentSpace->getSpaceDescription() << endl << endl;

      // loop menu and possible actions until user move's location
      while (!endRound) {
        // show roundMenu and get data from it and user's choice
        int *infoArray = displayRoundMenu(hasBackpack, currentSpace, backpack);
        int userChoiceForThisSpace = infoArray[0];
        int currentMenuNum = infoArray[1];
        int numForItem = infoArray[2];
        bool printBackpack = infoArray[3];
        bool dropItem = infoArray[4];

        // cout <<"user choice: "<<userChoiceForThisSpace<<endl;
        // cout <<"numForItem: "<<numForItem<<endl;

        int numPossibleMoves = currentSpace->getSpacePointers().size();

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
                cout << "I found it!\n";
                // cout << i << endl;
                currentSpace = i;
              }
            }
            currentRoundNum++;
            endRound = true;
          }

          // display backpack
          else if (printBackpack) {
            if (!backpack.empty()) {
              cout << "Your backpack is empty.\n";
            }
            else {
              for (auto i : backpack) {
                cout << i << " ";
              }
              cout << endl;              
            }
          }

          // drop item
          else if (dropItem) {
            cout << "in dropItem\n";

          }

          // do action on item
          else if (userChoiceForThisSpace == numForItem) {
            int actionNum = currentSpace->getItemActionNum();
            // cout << "in doAction\n";

            // get backpack
            if (currentSpace->getItemName() == "backpack") {
              hasBackpack = true;
            }
            // put item in backpack
            if (hasBackpack && actionNum == 1) {
              // mark as taken in object
              currentSpace->setItemTaken(true);

              // add to backpack container
              backpack.push_back(currentSpace->getItemName());
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
            cout << currentSpace->getItemDescriptionAfter();
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