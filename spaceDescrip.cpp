

#include <iostream>
#include <tuple>
#include "space.hpp"
#include "stairsSpace.hpp"
#include "aboveGroundSpace.hpp"
#include "undergroundSpace.hpp"
#include "groundLevelSpace.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::get;
using std::vector;
using std::string;
using std::tuple;

void setUpSpaceDescriptions(tuple<GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, UndergroundSpace*, UndergroundSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, UndergroundSpace*, AboveGroundSpace*, StairsSpace*, AboveGroundSpace*>&spaceTuple) {

  // get pointers from tuple
    GndLvlSpace *trainStation = get<0>(spaceTuple);
    GndLvlSpace *trainLocomotive = get<1>(spaceTuple);
    GndLvlSpace *trainPassCar = get<2>(spaceTuple);
    GndLvlSpace *chapelPews = get<3>(spaceTuple);
    GndLvlSpace *chapelFront = get<4>(spaceTuple);
    StairsSpace *chapelStairs = get<5>(spaceTuple);
    UndergroundSpace *chapelSecretPassW = get<6>(spaceTuple);
    UndergroundSpace *chapelSecretPassE = get<7>(spaceTuple);
    StairsSpace *zooStairs = get<8>(spaceTuple);
    GndLvlSpace *zooEntry = get<9>(spaceTuple);
    GndLvlSpace *zooParrots = get<10>(spaceTuple);
    GndLvlSpace *zooLlama = get<11>(spaceTuple);
    GndLvlSpace *house = get<12>(spaceTuple);
    GndLvlSpace *courtyard = get<13>(spaceTuple);
    GndLvlSpace *trees = get<14>(spaceTuple);
    GndLvlSpace *libEntry = get<15>(spaceTuple);
    GndLvlSpace *libOffice = get<16>(spaceTuple);
    StairsSpace *libStairs = get<17>(spaceTuple);
    GndLvlSpace *libWinSeat = get<18>(spaceTuple);
    GndLvlSpace *libStacks = get<19>(spaceTuple);
    UndergroundSpace *libBasementCloset = get<20>(spaceTuple);
    AboveGroundSpace *libMapRoom = get<21>(spaceTuple);
    StairsSpace *libMapRmStairs = get<22>(spaceTuple);
    AboveGroundSpace *libSecretTower = get<23>(spaceTuple); 

  
  
  // set pointers
    trainStation->setPointers(nullptr, courtyard, trainLocomotive, nullptr);
    trainLocomotive->setPointers(trainStation, house, trainPassCar, nullptr);
    trainPassCar->setPointers(trainLocomotive, nullptr, nullptr, nullptr);
    chapelPews->setPointers(nullptr, chapelFront, courtyard, nullptr);
    chapelFront->setPointers(nullptr, chapelStairs, nullptr, chapelPews);
    chapelStairs->setPointers(nullptr, nullptr, nullptr, nullptr, chapelSecretPassW, chapelFront);
    chapelSecretPassW->setPointers(nullptr,chapelSecretPassE, nullptr, nullptr, chapelStairs); //goes up
    chapelSecretPassE->setPointers(nullptr, nullptr, nullptr, chapelSecretPassW, zooStairs); // goes up
    zooStairs->setPointers(nullptr, nullptr, nullptr, nullptr, zooEntry, chapelSecretPassE); // up and down
    zooEntry->setPointers(zooParrots, nullptr, zooLlama, house);
    zooParrots->setPointers(nullptr, nullptr, zooEntry, nullptr);
    zooLlama->setPointers(zooEntry, nullptr, nullptr, nullptr);
    house->setPointers(nullptr, zooEntry, nullptr, trees);
    courtyard->setPointers(chapelPews, trees, libEntry, trainStation);
    trees->setPointers(nullptr, house, nullptr, courtyard);  
    libEntry->setPointers(courtyard, libOffice, libStacks, nullptr);
    libOffice->setPointers(nullptr, libStairs, libBasementCloset, libEntry);
    libStairs->setPointers(nullptr, nullptr, nullptr, nullptr, libMapRoom, libOffice);  // up and down
    libWinSeat->setPointers(nullptr, libStacks, nullptr, nullptr);
    libStacks->setPointers(libEntry, nullptr, nullptr, libWinSeat);
    libBasementCloset->setPointers(nullptr, nullptr, nullptr, nullptr, libOffice);  // goes up
    libMapRoom->setPointers(libStairs, libMapRmStairs, nullptr, nullptr, libStairs);//????
    libMapRmStairs->setPointers(nullptr, nullptr, nullptr, nullptr, libSecretTower, libMapRoom);
    libSecretTower->setPointers(nullptr, nullptr, nullptr, nullptr, libMapRmStairs);


  // set space descriptions
    // void setDescriptions(spaceNameIn, printSpaceNameIn, spaceDescrptionIn);
    trainStation->setDescriptions("trainStation", "the train station", "Your uncle built a train station to house his dad's memorabilia. They loved building model trains together, but what they've got outside it something on a much grander scale.");
    trainLocomotive->setDescriptions("trainLoco", "a half scale locomotive", "The locomotive is big enough for you to sit in. There a lots of dials, switches and an accelerator.");
    trainPassCar->setDescriptions("trainPassCar", "the passenger car", "There are eight or ten seats.");
    chapelPews->setDescriptions("chapelPews", "a replica of a Byzantine church", "The church is cool and quiet. There are pews and, further down, a dome and an ambo built into the wall.");
    // chapelFront->setDescriptions("chapelFront", "the ambo", "The ambo is of dark wood and has steps leading up to it so the preacher can be seen from the furthest pew.");
    chapelFront->setDescriptions("chapelFront", "the ambo", "The ambo is of dark wood and has steps leading up to it so the preacher can be seen from the furthest pew. In the stone behind it, there's an outline of something like a door. You run your hand along the stone and something clicks. A door opens. It's dark inside.");
    chapelStairs->setDescriptions("chapelStairs", "the secret stairs", "There are stairs going down.");
    chapelSecretPassW->setDescriptions("chapelSecretPassW", "the secret passageway", "There's a corner ahead.");
    chapelSecretPassE->setDescriptions("chapelSecretPassE", "the end of the passage", "The flashlight dimly lights the secret passage.");
    zooStairs->setDescriptions("zooStairs", "another set of stairs", "There stairs go up.");
    zooEntry->setDescriptions("zooEntry", "the zoo entrance", "There are trees overhead. The wind rustles through them.");
    zooParrots->setDescriptions("zooParrots", "the parrot enclosure", "There's a tall wooden structure enclosed with wire. Several parrots are in the habitat. One of the parrots has something in its mouth.");
    zooLlama->setDescriptions("zooLlama", "the llama enclosure", "A fenced in area houses several llamas.");
    house->setDescriptions("house", "the house", "You're in front of the house. No need to go back inside; you're sure the key and treasure are somewhere on your uncle's 40 acre estate.");
    courtyard->setDescriptions("courtyard", "the courtyard", "There's a fountain in the middle and four pathways leading in all directions.");
    trees->setDescriptions("trees", "the copse of trees", "It's cool in the small patch of trees.");
    libEntry->setDescriptions("libEntry", "the library foyer","Your uncle was a great scholar and a voracious reader. He was also a collector of rare books and build his own library to house them.");
    libOffice->setDescriptions("libOffice", "an office", "The library office looks like a busy place. There are filing cabinets, a desk and stacks of paper everywhere.");
    libStairs->setDescriptions("libStairs", "the library stairs", "The stairs are wide, wooden and might lead to anywhere.");
    libWinSeat->setDescriptions("libWinSeat", "a window seat", "A comfortable niche is in the wall. ");
    libStacks->setDescriptions("libStacks", "the libary stacks", "The library stacks are grand. Your uncle really loved to read. There are a lot of aisles to look down.");
    libBasementCloset->setDescriptions("libBasementCloset", "a basement closet", "The closet is full of stuff.");
    libMapRoom->setDescriptions("libMapRoom", "the library's map room", "The map room is incredible! There are old maps with faded ink, fragments of maps, and maps that are modern and colorful. Most are framed.");
    libMapRmStairs->setDescriptions("libMapRoomStairs", "secret stairs", "The stairs are narrow and steep, wooden steps that follow the square wall of the tower. They look old but are surprisingly clean.");
    libSecretTower->setDescriptions("libSecretRoom", "the secret tower room", "Inside is the secret tower room. It's small and brightly lit. How did you not know about this?!");

  // set item data
    // 1-take, 2-flip, 3-push, 4-open, 5-listen, 6-read, 7-look, 8-put
    
    // void setItem(hasItem, itemActionNumIn, itemNameIn, printItemNameIn, itemDescriptionIn, descriptionAfterItem);
    trainStation->setItem(true, 2, "lightSwitch", "the light switch", "There's a light switch on the wall.", "You flip the switch and can see a door on the other side of the room. It leads to the train!");
    trainLocomotive->setItem(true, 3, "powerButton", "the big, green power button", "", "Choo choo! The train goes around the property, passing the courtyard, a copse of trees and ending at the house.  As it stops you hear a rustling in the passenger car.");
    trainPassCar->setItem(true, 1, "crackers", "the crackers", "Someone left a small package of crackers in one of them.", "You take the crackers in case you get hungry later.");
    chapelPews->setItem(true, 1, "flashlight", "the flashlight", "As you walk down the aisle you notice a flashlight in one of the pews.", "You grab it just in case.");
    // chapelFront->setItem(true, 4, "door", "a hidden door", "In the stone behind it, there's an outline of something like a door.", "You run your hand along the stone and something clicks. A door opens. It's dark inside.");
    // chapelFront->setItem(true, 0, "", "", "In the stone behind it, there's an outline of something like a door. You run your hand along the stone and something clicks. A door opens. It's dark inside.", "");
    // chapelSecretPassW->setItem(true, 1, "pushPin", "a push pin", "");
    chapelSecretPassE->setItem(true, 1, "pushPin", "a push pin", "As you're nearing the end, the light glints off something on the floor.", "You pick up a push pin.");
    // zooStairs->setItem("", );
    zooEntry->setItem(true, 5, "sounds", "the sounds", "You think you hear something else.", "It's the sound of parrots squawking.");
    zooParrots->setItem(true, 1, "key", "a key", "The parrots look like a snack would be welcome.", "You take the key.");
    zooLlama->setItem(true, 6, "sign", "the sign", "There's a sign in front of them.", "Llamas are great pack animals, they're super smart and their fur is used to make all kinds of things. They're originally from South America.");
    house->setItem(true, 1, "backpack", "your backpack", "Your backpack is sitting on a bench.", "You grab your backpack. It might come in handy.");
    trees->setItem(true, 1, "flowers", "the flowers", "There are some pretty flowers along the path. They smell heavenly.", "Mmm. Smells nice. I wonder what you will you do with them.");  
    libEntry->setItem(true, 7, "", "a large glass display case", "There's a glass display case.", "Inside are signed first editions of C. S. Lewis's Chronicles of Narnia.");
    libOffice->setItem(true, 1, "paper", "a piece of paper", "A piece of paper flutters to the floor.", "It has 912 written on it.");
    libWinSeat->setItem(true, 7, "windowSeat", "a window seat", "There's a comfortable window seat.", "With the binoculars you see a tower. It looks like it's part of the library. How do you get up there?");
    libStacks->setItem(true, 1, "map", "a map", "For some reason there's a map lying loose on top of the books.", "You take the map.");
    libBasementCloset->setItem(true, 1, "binoculars", "a pair of binoculars", "There are binoculars hanging on a peg.", "You never know when you'll need to see better.");
    libMapRoom->setItem(true, 8, "pushPin", "push pin", "Remembering the llamas, you somehow need to mark South America.", "You push the pin into the map and hear something click. A section of the wall slides away revealing a short hallway with a locked door at the end of it.");
    libMapRmStairs->setItem(true, 8, "door", "a locked door", "At the top is a locked door.", "You put the key in the lock and it clicks open.");
    libSecretTower->setItem(true, 8, "box", "the treasure box", "There's a treasure box on a top in the middle.", "Inside the box is Uncle's first edition books with a note. “These are yours now. They're worth a great deal. Do you keep them, knowing you possess a fortune in knowledge and money, or do you trade them in for their value?”");

  // set dependency data
    // void setDependency(hasDependency, spaceDepend, descripAfterDepend);
    trainLocomotive->setDependency(true, "lightSwitch", "There's also a power button.");
    trainPassCar->setDependency(true, "powerButton", "");
    chapelStairs->setDependency(true, "flashlight", "Good thing you found this flashlight.");
    chapelSecretPassW->setDependency(true, "flashlight", "");
    chapelSecretPassE->setDependency(true, "flashlight", "");
    zooStairs->setDependency(true, "flashlight", "");
    zooParrots->setDependency(true, "crackers", "You put a cracker up to the wire. The parrot flies over and grabs the cracker. A key falls through the wire and lands at your feet.");
    libWinSeat->setDependency(true, "binoculars", "You sit down. Aww. From the window you see something interesting. If only you could get a closer look.");
    libStacks->setDependency(true, "card", "The card says 912, which leads to the maps section.");
    libMapRoom->setDependency(true, "map", "There's a frame that's empty.");
    libMapRmStairs->setDependency(true, "pushPin", "");
    libSecretTower->setDependency(true, "key", "");

    // int len = spaceVector.size();
  // // print spaces
  // for (int i = 0; i < len; i++) {
  //   // cout << spaceVector[i] <<endl;
  // }
};
