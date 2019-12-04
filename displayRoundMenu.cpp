

// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <map>
// #include "displayRoundMenu.hpp"
// #include "menu.hpp"
// #include "space.hpp"
// using std::map;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::pair;
// using std::vector;
// using std::string;
// using std::stringstream;

// // string toString(int numIn);

// string displayRoundMenu(int *infoArray, bool hasBackpack, Space *currentSpace, vector<string> &backpack, map<string, string> &droppedItemsMap, int numPossibleMoves, bool lightSwitchedOn, bool powerButtonPushed) {

//   // create menu
//   vector<string> spaceMenuChoices;
//   int currentMenuNum = 1;

//   string choice;
//   // get possible spaces to move to
//   vector<Space*> tempHolder = currentSpace->getSpacePointers();
//   for (unsigned j = 0; j < tempHolder.size(); j++) {
//     choice = "" + toString(j+1) + ": Go to ";
//     choice += tempHolder[j]->getSpaceNameForPrinting();
//     spaceMenuChoices.push_back(choice);
//     currentMenuNum++;
//   }

//   int numForItem;
//   map<int,string> droppedItemsMenuNums;  
//   // add backpack to menu if the currentSpace is house
//   // add current space's item to menu if there is one and it's still in it's original location and the user has a backpack and the current room's dependency is True
//   // add items that have been dropped in currentSpace
//   string thisName = currentSpace->getSpaceName();
//   if ((currentSpace->getHasItem() && !currentSpace->isItemTaken() && hasBackpack && !currentSpace->hasSpaceDependency())  || (thisName == "house" && !currentSpace->isItemTaken())) {
//     bool keepGoing = true;

//     if ((thisName == "trainLoco" && !lightSwitchedOn) || (thisName == "trainPassCar" && !powerButtonPushed)) {
//       keepGoing = false;
//       // cout << "keepgoing = false\n";
//     }
//     if (keepGoing) {
//       // cout <<"in keep going\n";
//       choice = toString(currentMenuNum) + ": ";
//       choice += currentSpace->getVerbForAction() + " ";
//       choice += currentSpace->getItemNameForPrinting();

//       spaceMenuChoices.push_back(choice);
//       numForItem = currentMenuNum;
//       currentMenuNum++;

//       // cout << currentSpace->getItemDescription();      
//     }
//   }
//   else {
//     // if no item available
//     numForItem = -1;
//   }
//   if (hasBackpack && !droppedItemsMap.empty()) {
//     // go through droppedItems map and find the ones dropped in current space, add them to the menu
//     map<string, string>::iterator itr;
//     for (itr = droppedItemsMap.begin(); itr != droppedItemsMap.end(); ++itr) {
//       if (itr->second == currentSpace->getSpaceName()) {
//         // add to menu
//         choice = toString(currentMenuNum) + ": Take the ";
//         choice += itr->first;
//         spaceMenuChoices.push_back(choice);
//         droppedItemsMenuNums.insert(pair<int,string>(currentMenuNum, itr->first));
//         currentMenuNum++;
//       }
//     }    
//   }

//   // add openBackpack, dropItem, and useItem to menu choices
//   bool openBackpack = false, dropItem = false, useItem = false, pickUpDroppedItem = false;
//   int openBackpackNum = -1, dropItemNum = -1, useItemNum = -1;
//   string nameOfDroppedItem;
//   if (hasBackpack) {
//     choice = toString(currentMenuNum) + ": Open backpack";
//     spaceMenuChoices.push_back(choice);
//     openBackpackNum = currentMenuNum;
//     currentMenuNum++;
//   }
//   if (hasBackpack && !backpack.empty()) {
//     choice = toString(currentMenuNum) + ": Drop item";
//     spaceMenuChoices.push_back(choice);
//     dropItemNum = currentMenuNum;
//     currentMenuNum++;
//     choice = toString(currentMenuNum) + ": Use item";
//     spaceMenuChoices.push_back(choice);
//     useItemNum = currentMenuNum;
//     currentMenuNum++;
//   }

//   // add quit to menu choices
//   choice = toString(currentMenuNum) + ": I quit";
//   spaceMenuChoices.push_back(choice);

//   vector<int> spaceMenuNums;
//   for (unsigned k = 1; k < spaceMenuChoices.size()+1; k++) {
//     spaceMenuNums.push_back(k);
//   }

//   // instantiate roundMenu
//   Menu roundMenu(spaceMenuChoices, spaceMenuNums);

//   // array to pass back userChoice, currentMenuNum and the item's menu number
//   cout << endl << endl;
//   int userChoice = roundMenu.getUserChoice();
//   cout << endl;

//   // cout <<"userChoice: "<<userChoice<<endl;

//   if (userChoice >= 1 && userChoice <= numPossibleMoves) {
  
//   }
//   else if (userChoice == openBackpackNum) {
//     // cout <<"openback=tru\n";
//     openBackpack = true;
//   }
//   else if (userChoice == dropItemNum) {
//     dropItem = true;
//   }
//   else if (userChoice == useItemNum) {
//     useItem = true;
//   }
//   else if (!droppedItemsMenuNums.empty()) {
//     // cout <<"in !dropped..\n";
//     // map<int, string>::iterator itr;
//     nameOfDroppedItem = droppedItemsMenuNums.find(userChoice)->second;
//     pickUpDroppedItem = true;
//     // cout << "....."<<nameOfDroppedItem<<endl;
//   }
//   else {
//     nameOfDroppedItem = "none";
//   }

//   infoArray[0] = userChoice;
//   infoArray[1] = currentMenuNum;
//   infoArray[2] = numForItem;
//   infoArray[3] = openBackpack;
//   infoArray[4] = dropItem;
//   infoArray[5] = useItem;
//   infoArray[6] = pickUpDroppedItem;
// // cout <<"end of displayRoundMenu\n";
//   return nameOfDroppedItem;
// };

// // string toString(int numIn) {
// //   stringstream ss;
// //   ss.str("");   // clear streamstring
// //   ss << numIn;
// //   return ss.str();
// // };
