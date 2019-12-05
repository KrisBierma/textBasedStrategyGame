/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma1
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
    int backpackLimit = 5;

    // map to hold dropped items: key is item, value is space
    map<string, string> droppedItemsMap;

    // instantiate items
      // remove idk
      Item *lightSwitchP = new ItemToggle(2, "lightSwitch", "the light switch", "There's a light switch on the wall.", "You flip the switch and can see a door on the other side of the room. It leads to the train!", "There's also a power button.");
      cout <<"--------------------------------\n";
      Item *powerButtonP = new ItemToggle(3, "powerButton", "the big, green power button", "", "Choo choo! The train goes around the property, passing the courtyard, a copse of trees and ending at the house.  As it stops you hear a rustling in the passenger car.", "idk");
      Item *crackersP = new Item(1, "crackers", "the crackers", "Someone left a small package of crackers in one of them.", "You take the crackers in case you get hungry later.", "You put a cracker up to the wire. The parrot flies over and grabs the cracker. A key falls through the wire and lands at your feet.");
      Item *flashlightP = new ItemToggle(1, "flashlight", "the flashlight", "As you walk down the aisle you notice a flashlight in one of the pews.", "You grab it just in case.", "Good thing you found this flashlight.");
      Item *doorP = new ItemToggle(4, "door", "the hidden door", "In the stone behind it, there's an outline of something like a door.", "You run your hand along the stone and something clicks. A door opens. It's dark inside.", "idk");
      Item *pushPinP = new ItemToggle(1, "pushPin", "the push pin", "As you're nearing the end, the light glints off something on the floor.", "You pick up a push pin.", "idk");
      Item *soundsP = new Item(5, "sounds", "the sounds", "You think you hear something else.", "It's the sound of parrots squawking.", "idk");
      Item *keyP = new Item(1, "key", "the key", "The parrots look like a snack would be welcome.", "You take the key.", "idk");
      Item *signP = new Item(6, "sign", "the sign", "There's a sign in front of them.", "Llamas are great pack animals, they're super smart and their fur is used to make all kinds of things. They're originally from South America.", "idk");
      Item *backpackP = new Item(1, "backpack", "your backpack", "Your backpack is sitting on a bench.", "You grab your backpack. It might come in handy.", "idk");
      Item *flowersP = new Item(1, "flowers", "the flowers", "There are some pretty flowers along the path. They smell heavenly.", "Mmm. Smells nice. I wonder what you will you do with them.", "idk");
      Item *displayCaseP = new Item(7, "", "a large glass display case", "There's a glass display case.", "Inside are signed first editions of C. S. Lewis's Chronicles of Narnia.", "idk");
      Item *paperP = new Item(1, "paper", "the piece of paper", "A piece of paper flutters to the floor.", "It has 912 written on it.", "The card says 912, which leads to the maps section. For some reason there's a map lying loose on top of the books.");
      Item *windowP = new Item(8, "windowSeat", "the window seat", "There's a comfortable window seat. The window affords an excellent view. Stop to take a look?", "With the binoculars you see a tower. It looks like it's part of the library. How do you get up there?", "idk");
      Item *mapP = new Item(1, "map", "a map", "", "You take the map.", "The map fits in it perfectly. You notice small holes in different counties, as though someone stuck pins to mark places.");
      Item *binocularsP = new Item(1, "binoculars", "a pair of binoculars", "There are binoculars hanging on a peg.", "You never know when you'll need to see better.", "You sit down. Aww. From the window you see something interesting. If only you could get a closer look.");
      // Item *keyHoleP = new Item();
      Item *libDoorP = new ItemToggle(9, "door", "a locked door", "At the top is a locked door.", "You put the key in the lock and it clicks open.", "idk");
      Item *treasureP = new Item(4, "box", "the treasure box", "Sittly jauntily on a small round table is a treasure box!", "Inside the box is Uncle's first edition books with a note. \"These are yours now. They're worth a great deal. Do you keep them, knowing you possess a fortune in knowledge and money, or do you trade them in for their value?\"", "idk");
    // libMapRoom->setItem(true, 8, "pushPin", "push pin", "Remembering the llamas (or maybe is was a lucky guess), you somehow need to mark South America.", "You push the pin into the map and hear something click. A section of the wall slides away revealing a short hallway with a locked door at the end of it.");
      // actionIn, nameIn, printNameIn, descripIn, descriptAfterIn, descripAfterDepIn

    // instantiate spaces
      Space *trainStationP = new GndLvlSpace("trainStation", "the train station", "Your uncle built a train station to house his dad's memorabilia. They loved building model trains together, but what they've got outside it something on a much grander scale.");
      Space *trainLocomotiveP = new GndLvlSpace("trainLoco", "the locomotive", "The locomotive is in half-scale -- big enough for you to sit in and small enough to be super interesting. There are dials, switches and an accelerator.");
      Space *trainPassengerCarP = new GndLvlSpace("trainPassCar", "the passenger car", "There are eight or ten seats.");
      Space *chapelPewsP = new GndLvlSpace("chapelPews", "the church entrance", "It's a replica of a Byzantine church. It's cool and quiet. There are pews and, further down, a dome and an ambo built into the wall.");
      Space *chapelFrontP = new GndLvlSpace("chapelFront", "the ambo", "The ambo is of dark wood and has steps leading up to it so the preacher can be seen from the furthest pew. In the stone behind it, there's an outline of something like a door. You run your hand along the stone and something clicks. A door opens. It's dark inside.");
      Space *chapelStairsP = new StairsSpace("chapelStairs", "the secret stairs", "The stairs lead to a secret passageway!");
      Space *chapelSecretPassWP = new UndergroundSpace("chapelSecretPassW", "the secret passageway", "The rough stone floor and walls continue around a corner.");
      Space *chapelSecretPassEP = new UndergroundSpace("chapelSecretPassE", "the corner", "The flashlight dimly lights the secret passage and reveals another set of stairs.");
      Space *zooStairsP = new StairsSpace("zooStairs", "the stairs", "The stairs go up. You push open the door at the top and see the zoo entrance.");
      Space *zooEntryP = new GndLvlSpace("zooEntry", "the zoo entrance", "There are trees overhead. The wind rustles through them.");
      Space *zooParrotsP = new GndLvlSpace("zooParrots", "the parrot enclosure", "There's a tall wooden structure enclosed with wire. Several parrots are in the habitat. One of the parrots has something in its mouth.");
      Space *zooLlamasP = new GndLvlSpace("zooLlama", "the llama enclosure", "A fenced in area houses several llamas.");
      Space *houseP = new GndLvlSpace("house", "the house", "You're in front of the house. No need to go back inside; you're sure the key and treasure are somewhere on your uncle's 40 acre estate.");
      Space *courtyardP = new GndLvlSpace("courtyard", "the courtyard", "There's a fountain in the middle and four pathways leading in all directions.");
      Space *treesP = new GndLvlSpace("trees", "the copse of trees", "It's cool in the small patch of trees.");
      Space *libEntryP = new GndLvlSpace("libEntry", "the library foyer","Your uncle was a great scholar and a voracious reader. He was also a collector of rare books and build his own library to house them.");
      Space *libOfficeP = new GndLvlSpace("libOffice", "the office", "The library office looks like a busy place. There are filing cabinets, a desk and stacks of paper everywhere.");
      Space *libStairsP = new StairsSpace("libStairs", "the library stairs", "The stairs are wide, wooden and might lead to anywhere.");
      Space *libWindowSeatP = new GndLvlSpace("libWinSeat", "a window seat", "A comfortable niche is in the wall.");
      Space *libStacksP = new GndLvlSpace("libStacks", "the library stacks", "The library stacks are grand. Your uncle really loved to read. There are a lot of aisles to look down. How do you know which one to choose?");
      Space *libBasementP = new UndergroundSpace("libBasementCloset", "a basement closet", "The closet is full of stuff.");
      Space *libMapRoomP = new AboveGroundSpace("libMapRoom", "the library's map room", "The map room is incredible! There are old maps with faded ink, fragments of maps, and maps that are modern and colorful. Most are framed. There's a frame that's empty.");
      Space *libMapRmStairsP = new StairsSpace("libMapRoomStairs", "secret stairs", "The stairs are narrow and steep, wooden steps that follow the square wall of the tower. They look old but are surprisingly clean.");
      Space *libSecretTowerP = new AboveGroundSpace("libSecretRoom", "the secret tower room", "Inside is the secret tower room. It's small and brightly lit. How did you not know about this?!");

    // set space pointers
      static_cast<GndLvlSpace*>(trainStationP)->setPointers(nullptr, courtyardP, trainLocomotiveP, nullptr);
      static_cast<GndLvlSpace*>(trainLocomotiveP)->setPointers(trainStationP, houseP, nullptr, trainPassengerCarP);
      static_cast<GndLvlSpace*>(trainPassengerCarP)->setPointers(nullptr, trainLocomotiveP, nullptr, nullptr);
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
      static_cast<GndLvlSpace*>(libEntryP)->setPointers(courtyardP, libStairsP, libOfficeP, libStacksP);
      static_cast<GndLvlSpace*>(libOfficeP)->setPointers(libEntryP, nullptr, nullptr, libBasementP);
      static_cast<StairsSpace*>(libStairsP)->setPointers(nullptr, nullptr, nullptr, nullptr, libMapRoomP, libEntryP);  // up and down
      static_cast<GndLvlSpace*>(libWindowSeatP)->setPointers(nullptr, libStacksP, nullptr, nullptr);
      static_cast<GndLvlSpace*>(libStacksP)->setPointers(nullptr, libEntryP, nullptr, libWindowSeatP);
      static_cast<UndergroundSpace*>(libBasementP)->setPointers(nullptr, nullptr, nullptr, nullptr, libOfficeP);  // goes up
      static_cast<AboveGroundSpace*>(libMapRoomP)->setPointers(nullptr, nullptr, libMapRmStairsP, libStairsP, libStairsP);//????
      static_cast<StairsSpace*>(libMapRmStairsP)->setPointers(nullptr, nullptr, nullptr, nullptr, libSecretTowerP, libMapRoomP);
      static_cast<AboveGroundSpace*>(libSecretTowerP)->setPointers(nullptr, nullptr, nullptr, nullptr, libMapRmStairsP);

    // set space items
      trainStationP->setItem(true, lightSwitchP);
      trainLocomotiveP->setItem(true, powerButtonP);
      trainPassengerCarP->setItem(true, crackersP);
      chapelPewsP->setItem(true, flashlightP);
      chapelFrontP->setItem(true, doorP);
      chapelSecretPassEP->setItem(true, pushPinP);
      zooParrotsP->setItem(true, keyP);
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
      libMapRoomP->setPtrDependency(true, libMapRmStairsP, pushPinP);
      libMapRmStairsP->setPtrDependency(true, libSecretTowerP, keyP);
      // libSecretTowerP->setPtrDependency(true, libMapRmStairsP, libDoorP);

    // set item dependencies
      chapelStairsP->setDependency(true, flashlightP);
      chapelSecretPassEP->setDependency(true, flashlightP);
      chapelSecretPassWP->setDependency(true, flashlightP);
      zooStairsP->setDependency(true, flashlightP);
      zooParrotsP->setDependency(true, crackersP);
      // libWindowSeatP->setDependency(true, binocularsP);
      libStacksP->setDependency(true, paperP);
      libMapRoomP->setDependency(true, mapP);
      // libMapRmStairsP->setDependency(true, libDoorP);
      // libSecretTowerP->setDependency(true, keyP);

    // push ALL space object pointers to container
      vector<Space*> spaceVector = {trainStationP, trainLocomotiveP, trainPassengerCarP, chapelPewsP, chapelFrontP, chapelStairsP, chapelSecretPassWP, chapelSecretPassEP, zooStairsP, zooEntryP, zooParrotsP, zooLlamasP, houseP, courtyardP, treesP, libEntryP, libOfficeP, libStairsP, libWindowSeatP, libStacksP, libBasementP, libMapRoomP, libMapRmStairsP, libSecretTowerP};
    
    // starting space is the house. sp = current space
    Space *sp = houseP;

    game.displayIntro();
    // cout <<static_cast<ItemToggle*>(s->getItemPtrDependentOn()->getOn()<<endl;

    // dependency toggles
    // bool flashlightOn = false;

    // loop for each turn
    while (!quit && game.getCurrentRoundNum() <= game.getCurrentRoundNum()) {
      bool endRound = false;

      // display new round header
      game.showNewRound(sp);

      // description for current location
      cout << sp->getSpaceDescription();
    // cout<<"...." << endl << sp->getHasPointerDependency() <<endl;
      // item description
      // cout <<sp->getHasItem()<<endl;
      // cout <<sp->isItemTaken()<<endl;
      if (sp->getHasItem() && sp->isItemTaken() == false) {
        cout << endl << endl << sp->getItem()->getItemDescription();
      }

      // loop menu and possible actions until user move's location
      while (!endRound && !quit) {     
        // show roundMenu and get data from it and user's choice
        game.displayRoundMenu(sp, backpack, droppedItemsMap);
        int userChoiceForThisSpace = game.getUserChoiceForThisSpace();
    // need this??
    // userChoiceForThisSpace == game.getCurrentMenuNum()
        // act according to user's choice
        if (game.getQuit()) {
          quit = true;
        }
        else {
          // cout <<"here\n"<<userChoiceForThisSpace << "  "<< game.getNumForItem()<<endl;
          // move user
          if (game.getMove()) {
            string tempName = game.getMoveWhere()->getSpaceName();

            // search through spaceVector (from main) to find the space that matches the user's move choice
            for (auto i : spaceVector) {
              if (i->getSpaceName() == tempName) {
                // cout << "I found it!\n";
                // cout << i << endl;
          // cout <<static_cast<ItemToggle*>(flashlightP)->getOn()<<endl;

                bool hasFlashlightDep = i->hasSpaceDependency() && i->getSpaceDependency()->getItemName() == "flashlight";
                bool hasOtherDep = i->hasSpaceDependency() && i->getSpaceDependency()->getItemName() != "flashlight";
                bool hasNoDep = !i->hasSpaceDependency();
                bool flashlightOn = static_cast<ItemToggle*>(flashlightP)->getOn();
                // check if it's dependent on flashlight
                if (hasFlashlightDep && !flashlightOn) {
                  cout << "It's too dark in there.\n";
                }
                else {
                  // if flashlight is on and not needed
                  if (flashlightOn && (hasOtherDep || hasNoDep)) {
                    cout << "The flashlight is still on.\n";
                  }
                  // cout << "space Depen: "<< i->getSpaceDependency() << endl;
                  // cout <<"flashlight on? "<<static_cast<ItemToggle*>(flashlightP)->getOn()<<endl;
                  sp = i;
                  game.updateRoundNum();
                  endRound = true;
                  // cout << "endRound\n";            
                }
              }
            }
          }

          // display backpack
          else if (game.getOpenBackpack()) {
            // cout <<"in printbackpack   size:"<<backpack.size()<<endl;
            if (backpack.empty()) {
              cout << endl << "Your backpack is empty.";
            }
            else {
              cout << "You've got: ";
              if (backpack.size() == 1) {
                cout << backpack[0];
              }
              else {
                for (unsigned i = 0; i < backpack.size()-1; i++) {
                  cout << backpack[i] << ", ";
                }
                cout << backpack[backpack.size()-1];
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
              droppedItemsMap.insert(pair<string, string>(backpack[item], sp->getSpaceName()));

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
            // cout <<"item: "<<item<<"  size: "<<backpack.size()<<endl;

            // if last num on menu, do nothing
            if (item < backpack.size()) {
              // cout <<"here\n";
              // check if it's the pushPin in mapRoom (only one with two dependencies)
              if(sp->getSpaceName() == "libMapRoom" && sp->getItemDepenDone() && backpack[item] == "pushPin") {
                cout << "There are so many holes already made. ";
                vector<string> mapMenuChoices = {"1. Asia", "2. Africa", "3. Europe", "3. Australia", "4. Antarctica", "5. North America", "3. South America"};
                vector<int> mapMenuNums = {1, 2, 3, 4, 5, 6, 7};
                Menu mapMenu(mapMenuChoices, mapMenuNums);

                int userChoice = mapMenu.getUserChoice();
                if (userChoice = 7) {
                  cout << "Remembering the llamas (or maybe is was a lucky guess), you push the pin into the only hole in South Amerca and hear something click. A section of the wall slides away revealing a short hallway with a locked door at the end of it.\n";
                  static_cast<ItemToggle*>(pushPinP)->setOn();;
                }
                else {
                  cout << "Hmm. Nothing happened.\n";
                }
              }

              else if (sp->hasSpaceDependency() && sp->getSpaceDependency()->getItemName() == backpack[item] && sp->getSpaceDependency()->getItemName() != "flashlight") {

                // cout <<"Yes, use it here!\n";
                // if a dependency for other info/actions, mark it done
                if (sp->hasSpaceDependency()) {
                  if (sp->getSpaceName() == "libMapRoom" && sp->getSpaceDependency()->getItemName() != "pushPinP") {
                    // do nothing bc map room is only room with two dependencies
                  }
                  else {
                    // cout << "curr-> " << sp->getItemDepenDone()<<endl;
                  sp->setItemDepenDone();
                    // cout << "curr-> " << sp->getItemDepenDone()<<endl;
                  }
                }

                // print description
                cout << endl << sp->getSpaceDependency()->getDescriptionAfterDependency();
                // remove from backpack
                backpack.erase(backpack.begin()+item);
                // cout<<"item: "<<item<<endl;
              }
              else if (backpack[item] == "flashlight") {
                cout <<"here\n";
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
            // cout << "else\n";
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
            int actionNum = sp->getItem()->getItemActionNum();
            string itemName = sp->getItem()->getItemName();
            
            // cout <<"take item\n";

            // get backpack
            if (itemName == "backpack") {
              // cout <<"in get backpack\n";
              // game.setHasBackpack();// delete in game.hpp
              sp->setItemTaken(true);
            }

            // put item in backpack unless it IS the backpack
            // 1-take
            if (game.getHasBackpack() && actionNum == 1 && itemName != "backpack") {
              // check if backpack is full
              if (backpack.size() < backpackLimit) {
                // mark as taken in object
                sp->setItemTaken(true);

                // add to backpack container
                backpack.push_back(itemName);                
              }
              else {
                cout << "Your backpack is full.\n";
              }
            }
            // 2-flip, 3-push, 4-open
            else if (actionNum >= 2 && actionNum <= 4) {
              // game over
              if (sp->getSpaceName() == "libSecretTowerP") {
                cout << "What will you do?\n";
                quit = true;
              }
              else {
                sp->setItemTaken(true);
                static_cast<ItemToggle*>(sp->getItem())->setOn();      
              }
              // cout <<"in actionNum 2-4\n";

            }
            // 5-listen, 6-read, 7-look, 8-sit on, 9-unlock
            else if (actionNum >= 5 || actionNum <= 9) {
              // do nothing
              // cout <<"in actionNum 5-7\n";
            }
            // else if (actionNum == 9) {
            //   cout << "how to deal with this??\n";
            // }
            // display info after taking action unless backpack is full
            if (backpack.size() < backpackLimit) {
              cout << endl << sp->getItem()->getDescriptionAfterItem();
            }
          }
        }        
      }
    }
  
    game.gameOver();

    // replayMenu
    if (!game.getQuit()) {
      vector<string> replayMenuC = {"1. Play again", "2. Quit"};
      vector<int> replayMenuN = {1, 2};
      Menu replayMenu(replayMenuC, replayMenuN);
      userChoice = replayMenu.getUserChoice();
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