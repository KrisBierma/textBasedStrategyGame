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
// #include <tuple>
#include "menu.hpp"
#include "space.hpp"
#include "game.hpp"
#include "item.hpp"
#include "helpers.hpp"
#include "itemToggle.hpp"
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
// using std::tuple;
// using std::remove_if;
using std::stringstream;

int chooseItemFromBackpack(vector<string> &backpack);

int main() {
  // showStartMenu
  vector<string> menuChoices = {"1. Play game", "2. Exit"};
  vector<int> menuNumbers = {1, 2};
  Menu startMenu(menuChoices, menuNumbers);
  int userChoice = startMenu.getUserChoice();

  // playGame  
  bool quit = false;
  while (userChoice != 2 && !quit) {
    Game game;

    // set up backpack vector container
    vector<string> backpack;

    // map to hold dropped items: key is item, value is space
    map<string, string> droppedItemsMap;

    // instantiate items
      // remove idk
      Item *lightSwitchP = new ItemToggle(2, "lightSwitch", "the light switch", "There's a light switch on the wall.", "You flip the switch and can see a door on the other side of the room. It leads to the train!", "There's also a power button.");
      Item *powerButtonP = new ItemToggle(3, "powerButton", "the big, green power button", "", "Choo choo! The train goes around the property, passing the courtyard, a copse of trees and ending at the house.  As it stops you hear a rustling in the passenger car.", "idk");
      Item *crackersP = new Item(1, "crackers", "the crackers", "Someone left a small package of crackers in one of them.", "You take the crackers in case you get hungry later.", "You put a cracker up to the wire. The parrot flies over and grabs the cracker. A key falls through the wire and lands at your feet.");
      Item *flashlightP = new ItemToggle(1, "flashlight", "the flashlight", "As you walk down the aisle you notice a flashlight in one of the pews.", "You grab it just in case.", "Good thing you found this flashlight.");
      Item *doorP = new ItemToggle(4, "door", "a hidden door", "In the stone behind it, there's an outline of something like a door.", "You run your hand along the stone and something clicks. A door opens. It's dark inside.", "idk");
      Item *pushPinP = new Item(1, "pushPin", "a push pin", "As you're nearing the end, the light glints off something on the floor.", "You pick up a push pin.", "idk");
      Item *soundsP = new Item(5, "sounds", "the sounds", "You think you hear something else.", "It's the sound of parrots squawking.", "idk");
      Item *keyP = new Item(1, "key", "a key", "The parrots look like a snack would be welcome.", "You take the key.", "idk");
      Item *signP = new Item(6, "sign", "the sign", "There's a sign in front of them.", "Llamas are great pack animals, they're super smart and their fur is used to make all kinds of things. They're originally from South America.", "idk");
      Item *backpackP = new Item(1, "backpack", "your backpack", "Your backpack is sitting on a bench.", "You grab your backpack. It might come in handy.", "idk");
      Item *flowersP = new Item(1, "flowers", "the flowers", "There are some pretty flowers along the path. They smell heavenly.", "Mmm. Smells nice. I wonder what you will you do with them.", "idk");
      Item *displayCaseP = new Item(7, "", "a large glass display case", "There's a glass display case.", "Inside are signed first editions of C. S. Lewis's Chronicles of Narnia.", "idk");
      Item *paperP = new Item(1, "paper", "a piece of paper", "A piece of paper flutters to the floor.", "It has 912 written on it.", "The card says 912, which leads to the maps section.");
      Item *windowP = new Item(7, "windowSeat", "a window seat", "There's a comfortable window seat.", "With the binoculars you see a tower. It looks like it's part of the library. How do you get up there?", "idk");
      Item *mapP = new Item(1, "map", "a map", "For some reason there's a map lying loose on top of the books.", "You take the map.", "There's a frame that's empty.");
      Item *binocularsP = new Item(1, "binoculars", "a pair of binoculars", "There are binoculars hanging on a peg.", "You never know when you'll need to see better.", "You sit down. Aww. From the window you see something interesting. If only you could get a closer look.");
      // Item *keyHoleP = new Item();
      Item *libDoorP = new ItemToggle(8, "door", "a locked door", "At the top is a locked door.", "You put the key in the lock and it clicks open.", "idk");
      Item *treasureP = new Item(8, "box", "the treasure box", "There's a treasure box on a top in the middle.", "Inside the box is Uncle's first edition books with a note. \"These are yours now. They're worth a great deal. Do you keep them, knowing you possess a fortune in knowledge and money, or do you trade them in for their value?\"", "idk");
    // libMapRoom->setItem(true, 8, "pushPin", "push pin", "Remembering the llamas, you somehow need to mark South America.", "You push the pin into the map and hear something click. A section of the wall slides away revealing a short hallway with a locked door at the end of it.");
      // actionIn, nameIn, printNameIn, descripIn, descriptAfterIn, descripAfterDepIn

    // instantiate spaces
      Space *trainStationP = new GndLvlSpace("trainStation", "the train station", "Your uncle built a train station to house his dad's memorabilia. They loved building model trains together, but what they've got outside it something on a much grander scale.");
      Space *trainLocomotiveP = new GndLvlSpace("trainLoco", "a half scale locomotive", "The locomotive is big enough for you to sit in. There a lots of dials, switches and an accelerator.");
      Space *trainPassengerCarP = new GndLvlSpace("trainPassCar", "the passenger car", "There are eight or ten seats.");
      Space *chapelPewsP = new GndLvlSpace("chapelPews", "a replica of a Byzantine church", "The church is cool and quiet. There are pews and, further down, a dome and an ambo built into the wall.");
      // chapelFront->setDescriptions("chapelFront", "the ambo", "The ambo is of dark wood and has steps leading up to it so the preacher can be seen from the furthest pew.");
      Space *chapelFrontP = new GndLvlSpace("chapelFront", "the ambo", "The ambo is of dark wood and has steps leading up to it so the preacher can be seen from the furthest pew. In the stone behind it, there's an outline of something like a door. You run your hand along the stone and something clicks. A door opens. It's dark inside.");
      Space *chapelStairsP = new StairsSpace("chapelStairs", "the secret stairs", "There are stairs going down.");
      Space *chapelSecretPassWP = new UndergroundSpace("chapelSecretPassW", "the secret passageway", "There's a corner ahead.");
      Space *chapelSecretPassEP = new UndergroundSpace("chapelSecretPassE", "the end of the passage", "The flashlight dimly lights the secret passage.");
      Space *zooStairsP = new StairsSpace("zooStairs", "another set of stairs", "There stairs go up.");
      Space *zooEntryP = new GndLvlSpace("zooEntry", "the zoo entrance", "There are trees overhead. The wind rustles through them.");
      Space *zooParrotsP = new GndLvlSpace("zooParrots", "the parrot enclosure", "There's a tall wooden structure enclosed with wire. Several parrots are in the habitat. One of the parrots has something in its mouth.");
      Space *zooLlamasP = new GndLvlSpace("zooLlama", "the llama enclosure", "A fenced in area houses several llamas.");
      Space *houseP = new GndLvlSpace("house", "the house", "You're in front of the house. No need to go back inside; you're sure the key and treasure are somewhere on your uncle's 40 acre estate.");
      Space *courtyardP = new GndLvlSpace("courtyard", "the courtyard", "There's a fountain in the middle and four pathways leading in all directions.");
      Space *treesP = new GndLvlSpace("trees", "the copse of trees", "It's cool in the small patch of trees.");
      Space *libEntryP = new GndLvlSpace("libEntry", "the library foyer","Your uncle was a great scholar and a voracious reader. He was also a collector of rare books and build his own library to house them.");
      Space *libOfficeP = new GndLvlSpace("libOffice", "an office", "The library office looks like a busy place. There are filing cabinets, a desk and stacks of paper everywhere.");
      Space *libStairsP = new StairsSpace("libStairs", "the library stairs", "The stairs are wide, wooden and might lead to anywhere.");
      Space *libWindowSeatP = new GndLvlSpace("libWinSeat", "a window seat", "A comfortable niche is in the wall.");
      Space *libStacksP = new GndLvlSpace("libStacks", "the libary stacks", "The library stacks are grand. Your uncle really loved to read. There are a lot of aisles to look down.");
      Space *libBasementP = new UndergroundSpace("libBasementCloset", "a basement closet", "The closet is full of stuff.");
      Space *libMapRoomP = new AboveGroundSpace("libMapRoom", "the library's map room", "The map room is incredible! There are old maps with faded ink, fragments of maps, and maps that are modern and colorful. Most are framed.");
      Space *libMapRmStairsP = new StairsSpace("libMapRoomStairs", "secret stairs", "The stairs are narrow and steep, wooden steps that follow the square wall of the tower. They look old but are surprisingly clean.");
      Space *libSecretTowerP = new AboveGroundSpace("libSecretRoom", "the secret tower room", "Inside is the secret tower room. It's small and brightly lit. How did you not know about this?!");

    // set space pointers
      static_cast<GndLvlSpace*>(trainStationP)->setPointers(nullptr, courtyardP, trainLocomotiveP, nullptr);
      static_cast<GndLvlSpace*>(trainLocomotiveP)->setPointers(trainStationP, houseP, trainPassengerCarP, nullptr);
      static_cast<GndLvlSpace*>(trainPassengerCarP)->setPointers(trainLocomotiveP, nullptr, nullptr, nullptr);
      static_cast<GndLvlSpace*>(chapelPewsP)->setPointers(nullptr, chapelFrontP, courtyardP, nullptr);
      static_cast<GndLvlSpace*>(chapelFrontP)->setPointers(nullptr, chapelStairsP, nullptr, chapelPewsP);
      static_cast<StairsSpace*>(chapelStairsP)->setPointers(nullptr, nullptr, nullptr, nullptr, chapelSecretPassWP, chapelFrontP);
      static_cast<UndergroundSpace*>(chapelSecretPassWP)->setPointers(nullptr,chapelSecretPassEP, nullptr, nullptr, chapelStairsP); //goes up
      static_cast<UndergroundSpace*>(chapelSecretPassEP)->setPointers(nullptr, nullptr, nullptr, chapelSecretPassWP, zooStairsP); // goes up
      static_cast<StairsSpace*>(zooStairsP)->setPointers(nullptr, nullptr, nullptr, nullptr, zooEntryP, chapelSecretPassEP); // up and down
      static_cast<GndLvlSpace*>(zooEntryP)->setPointers(zooParrotsP, nullptr, zooLlamasP, houseP);
      static_cast<GndLvlSpace*>(zooParrotsP)->setPointers(nullptr, nullptr, zooEntryP, nullptr);
      static_cast<GndLvlSpace*>(zooLlamasP)->setPointers(zooEntryP, nullptr, nullptr, nullptr);
      static_cast<GndLvlSpace*>(houseP)->setPointers(nullptr, zooEntryP, nullptr, treesP);
      static_cast<GndLvlSpace*>(courtyardP)->setPointers(chapelPewsP, treesP, libEntryP, trainStationP);
      static_cast<GndLvlSpace*>(treesP)->setPointers(nullptr, houseP, nullptr, courtyardP);  
      static_cast<GndLvlSpace*>(libEntryP)->setPointers(courtyardP, libOfficeP, libStacksP, nullptr);
      static_cast<GndLvlSpace*>(libOfficeP)->setPointers(nullptr, libStairsP, libBasementP, libEntryP);
      static_cast<StairsSpace*>(libStairsP)->setPointers(nullptr, nullptr, nullptr, nullptr, libMapRoomP, libOfficeP);  // up and down
      static_cast<GndLvlSpace*>(libWindowSeatP)->setPointers(nullptr, libStacksP, nullptr, nullptr);
      static_cast<GndLvlSpace*>(libStacksP)->setPointers(libEntryP, nullptr, nullptr, libWindowSeatP);
      static_cast<UndergroundSpace*>(libBasementP)->setPointers(nullptr, nullptr, nullptr, nullptr, libOfficeP);  // goes up
      static_cast<AboveGroundSpace*>(libMapRoomP)->setPointers(libStairsP, libMapRmStairsP, nullptr, nullptr, libStairsP);//????
      static_cast<StairsSpace*>(libMapRmStairsP)->setPointers(nullptr, nullptr, nullptr, nullptr, libSecretTowerP, libMapRoomP);
      static_cast<AboveGroundSpace*>(libSecretTowerP)->setPointers(nullptr, nullptr, nullptr, nullptr, libMapRmStairsP);     

    // set space items
      trainStationP->setItem(true, lightSwitchP);
      trainLocomotiveP->setItem(true, powerButtonP);
      trainPassengerCarP->setItem(true, crackersP);
      chapelPewsP->setItem(true, flashlightP);
      chapelFrontP->setItem(true, doorP);
      chapelSecretPassEP->setItem(true, pushPinP);
      zooLlamasP->setItem(true, signP);
      houseP->setItem(true, backpackP);
      treesP->setItem(true, flowersP);  
      libEntryP->setItem(true, displayCaseP);
      libOfficeP->setItem(true, paperP);
      libWindowSeatP->setItem(true, windowP);
      libStacksP->setItem(true, mapP);
      libBasementP->setItem(true, binocularsP);
      // libMapRoomP->setItem(true, );
      libMapRmStairsP->setItem(true, libDoorP);
      libSecretTowerP->setItem(true, treasureP);

    // set space pointer dependencies
      // Ex: if the lightSwitchP isn't on, the trainLocoP won't show up when in the trainStation space's menu
      trainStationP->setPtrDependency(true, trainLocomotiveP, lightSwitchP);
      trainLocomotiveP->setPtrDependency(true, trainPassengerCarP, powerButtonP);
      chapelFrontP->setPtrDependency(true, chapelStairsP, doorP);
      libSecretTowerP->setPtrDependency(true, libMapRmStairsP, libDoorP);


    // push ALL space object pointers to container
      vector<Space*> spaceVector = {trainStationP, trainLocomotiveP, trainPassengerCarP, chapelPewsP, chapelFrontP, chapelStairsP, chapelSecretPassWP, chapelSecretPassEP, zooStairsP, zooEntryP, zooParrotsP, zooLlamasP, houseP, courtyardP, treesP, libEntryP, libOfficeP, libStairsP, libWindowSeatP, libStacksP, libBasementP, libMapRoomP, libMapRmStairsP, libSecretTowerP};
    
    // starting space is the house
    Space *currentSpace = houseP;

    game.displayIntro();

    // dependency toggles
    // bool flashlightOn = false;

    // loop for each turn
    while (!quit && game.getCurrentRoundNum <= game.getCurrentRoundNum) {
      bool endRound = false;

      // display new round header
      game.showNewRound(currentSpace);

      // description for current location
      cout << currentSpace->getSpaceDescription();

      // item description
      if (currentSpace->isItemTaken() == false) {
        cout << endl << currentSpace->getItem()->getItemDescription();
      }

      // loop menu and possible actions until user move's location
      while (!endRound && !quit) {
        // data array to be filled
        // int infoArray[8];
        // int numPossibleMoves = currentSpace->getSpacePointers().size();
        
        // show roundMenu and get data from it and user's choice
        game.displayRoundMenu(currentSpace, backpack, droppedItemsMap);
        int userChoiceForThisSpace = game.getUserChoiceForThisSpace();
// need this??
// userChoiceForThisSpace == game.getCurrentMenuNum()
        // act according to user's choice
        if (game.getQuit()) {
          quit = true;
        }
        else {
          // move user
          if (game.getMove()) {
            string tempName = game.getMoveWhere()->getSpaceName();

            // search through spaceVector (from main) to find the space that matches the user's move choice
            for (auto i : spaceVector) {
              if (i->getSpaceName() == tempName) {
                cout << "I found it!\n";
                // cout << i << endl;

                // check if it's dependent on flashlight
                if (i->getSpaceDependency()->getItemName() == "flashlight" && !static_cast<ItemToggle*>(flashlightP)->getOn()) {
                  cout << "It's too dark in there.\n";
                }
                else {
                  // cout << "space Depen: "<< i->getSpaceDependency() << endl;
                  // cout <<"flashlight on? "<<flashlightOn<<endl;
                  currentSpace = i;
                  game.updateRoundNum();
                  endRound = true;                  
                }
              }
            }
          }

          // display backpack
          else if (game.getOpenBackpack()) {
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
          else if (game.getDropItem()) {
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
          else if (game.getUseItem()) {
            cout << "What do you want to use?\n";
            // get item to be used from user
            unsigned item = chooseItemFromBackpack(backpack);

            // if last num on menu, do nothing
            if (item < backpack.size()) {
              if (currentSpace->getSpaceDependency()->getItemName() == backpack[item] && currentSpace->getSpaceDependency()->getItemName() != "flashlight") {
                cout <<"Yes, use it here!\n";
                currentSpace->getSpaceDependency()->getDescriptionAfterDependency();
              }
              else if (backpack[item] == "flashlight") {
                static_cast<ItemToggle*>(flashlightP)->setOn();
                if (static_cast<ItemToggle*>(flashlightP)->getOn()) {
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
          else if (game.getPickUpDroppedItem()) {
            // add to backpack
            backpack.push_back(game.getNameOfDroppedItem());
            // remove from droppedItem map
            map<string, string>::iterator itr;
            itr = droppedItemsMap.find(game.getNameOfDroppedItem());
            droppedItemsMap.erase(itr);
          }

          // do action on item
          else if (userChoiceForThisSpace == game.getNumForItem()) {
            int actionNum = currentSpace->getItem()->getItemActionNum();
            string itemName = currentSpace->getItem()->getItemName();
            // if itemAction isn't 1, add to dependencyVec
            // if (actionNum != 1) {
            //   dependencyVec.push_back()
            // }

            // mark finished dependencies
            // if (itemName == "lightSwitch") {
            //   lightSwitchedOn = true;
            // } 
            // else if (itemName == "powerButton") {
            //   powerButtonPushed = true;
            // }

            // get backpack
            if (itemName == "backpack") {
              game.setHasBackpack();
              currentSpace->setItemTaken(true);
            }

            // put item in backpack unless it IS the backpack
            if (game.getHasBackpack() && actionNum == 1 && itemName != "backpack") {
              // mark as taken in object
              currentSpace->setItemTaken(true);

              // add to backpack container
              backpack.push_back(itemName);
              // cout <<"empty? "<<backpack.empty()<<endl;

              // for (string i:backpack) {
                // cout << i << " ";
              // }
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
            cout << currentSpace->getItem()->getDescriptionAfterItem();
          }
        }        
      }
    }
  }

  // show replay menu if !quit

  return(0);
};





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