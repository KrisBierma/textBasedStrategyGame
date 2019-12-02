

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

// void setSpaceData_underGround(vector<UndergroundSpace*>&spaceVector) {
//   UndergroundSpace *chapelSecretPassW = spaceVector[0];
//   UndergroundSpace *chapelSecretPassE = spaceVector[1];
//   UndergroundSpace *libBasementCloset = spaceVector[2];
//   chapelSecretPassW->setData("chapelSecretPass", true, "push pin", 1, nullptr,chapelSecretPassE, nullptr, nullptr, chapelStairs); //goes up
//   chapelSecretPassE->setData("chapelSecretPass", true, "push pin", 1, nullptr, nullptr, nullptr, chapelSecretPassW, zooStairs); // goes up
// };

// void setSpaceData_aboveGround(vector<AboveGroundSpace*>&spaceVector) {
//     AboveGroundSpace *libMapRoom = spaceVector[0];
//     AboveGroundSpace *libSecretTower = spaceVector[1];

// };

// void setSpaceData_groundLvl(vector<GndLvlSpace*>&spaceVector) {
//     GndLvlSpace *trainStation = spaceVector[0];
//     GndLvlSpace *trainLocomotive = spaceVector[1];
//     GndLvlSpace *trainPassCar = spaceVector[2];
//     GndLvlSpace *chapelPews = spaceVector[3];
//     GndLvlSpace *chapelFront = spaceVector[4];
//     GndLvlSpace *zooEntry = spaceVector[5];
//     GndLvlSpace *zooParrots = spaceVector[6];
//     GndLvlSpace *zooLlama = spaceVector[7];
//     GndLvlSpace *house = spaceVector[8];
//     GndLvlSpace *courtyard = spaceVector[9];
//     GndLvlSpace *trees = spaceVector[10];
//     GndLvlSpace *libEntry = spaceVector[11];
//     GndLvlSpace *libOffice = spaceVector[12];
//     GndLvlSpace *libWinSeat = spaceVector[13];
//     GndLvlSpace *libStacks = spaceVector[14];

//     trainStation->setData("trainStation", true, "light switch", 2, nullptr, courtyard, trainLocomotive, nullptr);
//     trainLocomotive->setData("trainLoco", true, "power button", 3, trainStation, house, trainPassCar, nullptr);
//     trainPassCar->setData("trainPassCar", true, "crackers", 1, trainLocomotive, nullptr, nullptr, nullptr);
//     chapelPews->setData("chapelPews", true, "flashlight", 1, nullptr, chapelFront, courtyard, nullptr);
//     chapelFront->setData("chapelFront", true, "secret door", 4, nullptr, chapelStairs, nullptr, chapelPews);
//     chapelStairs->setData("chapelStairs", false, "", -1, chapelSecretPassW, nullptr, nullptr, chapelFront);
// };

// void setSpaceData_stairs(vector<StairsSpace*>&spaceVector) {
//   StairsSpace *chapelStairs = spaceVector[0];
//   StairsSpace *zooStairs = spaceVector[1];
//   StairsSpace *libMapRmStairs = spaceVector[2];
//   StairsSpace *libStairs = spaceVector[3];

// };

void setUpSpaceDescriptions(vector<Space*>&spaceVector,  tuple<GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, UndergroundSpace*, UndergroundSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, UndergroundSpace*, AboveGroundSpace*, StairsSpace*, AboveGroundSpace*>&spaceTuple) {
  // get space pointers from parameter
    Space *trainStationSp = spaceVector[0];
    Space *trainLocomotiveSp = spaceVector[1];
    Space *trainPassCarSp = spaceVector[2];
    Space *chapelPewsSp = spaceVector[3];
    Space *chapelFrontSp = spaceVector[4];
    Space *chapelStairsSp = spaceVector[5];
    Space *chapelSecretPassWSp = spaceVector[6];
    Space *chapelSecretPassESp = spaceVector[7];
    Space *zooStairsSp = spaceVector[8];
    Space *zooEntrySp = spaceVector[9];
    Space *zooParrotsSp = spaceVector[10];
    Space *zooLlamaSp = spaceVector[11];
    Space *houseSp = spaceVector[12];
    Space *courtyardSp = spaceVector[13];
    Space *treesSp = spaceVector[14];
    Space *libEntrySp = spaceVector[15];
    Space *libOfficeSp = spaceVector[16];
    Space *libStairsSp = spaceVector[17];
    Space *libWinSeatSp = spaceVector[18];
    Space *libStacksSp = spaceVector[19];
    Space *libBasementClosetSp = spaceVector[20];
    Space *libMapRoomSp = spaceVector[21];
    Space *libMapRmStairsSp = spaceVector[22];
    Space *libSecretTowerSp = spaceVector[23];

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

  // set data on spaces
  // item actions: 0-nothing, 1-take, 2-flip, 3-push, 4-open, 5-listen, 6-read, 7-look, 8-put, 9-sit
    trainStation->setData("trainStation", true, "light switch", 2, nullptr, courtyard, trainLocomotive, nullptr);
    trainLocomotive->setData("trainLoco", true, "power button", 3, trainStation, house, trainPassCar, nullptr);
    trainPassCar->setData("trainPassCar", true, "crackers", 1, trainLocomotive, nullptr, nullptr, nullptr);
    chapelPews->setData("chapelPews", true, "flashlight", 1, nullptr, chapelFront, courtyard, nullptr);
    chapelFront->setData("chapelFront", true, "secret door", 4, nullptr, chapelStairs, nullptr, chapelPews);
    chapelStairs->setData("chapelStairs", false, "", -1, nullptr, nullptr, nullptr, nullptr, chapelSecretPassW, chapelFront);
    chapelSecretPassW->setData("chapelSecretPass", true, "push pin", 1, nullptr,chapelSecretPassE, nullptr, nullptr, chapelStairs); //goes up
    chapelSecretPassE->setData("chapelSecretPass", true, "push pin", 1, nullptr, nullptr, nullptr, chapelSecretPassW, zooStairs); // goes up
    zooStairs->setData("zooStairs", false, "", -1, nullptr, nullptr, nullptr, nullptr, zooEntry, chapelSecretPassE); // up and down
    zooEntry->setData("zooEntry", true, "zoo map", 5, zooParrots, nullptr, zooLlama, house);
    zooParrots->setData("zooParrots", true, "key", 1, nullptr, nullptr, zooEntry, nullptr);
    zooLlama->setData("zooLlama", true, "sign", 6, zooEntry, nullptr, nullptr, nullptr);
    house->setData("house", true, "backpack", 1, nullptr, zooEntry, nullptr, trees);
    courtyard->setData("courtyard", false, "", -1, chapelPews, trees, libEntry, trainStation);
    trees->setData("trees", true, "flowers", 1, nullptr, house, nullptr, courtyard);  
    libEntry->setData("libEntry", true, "display case", 6, courtyard, libOffice, libStacks, nullptr);
    libOffice->setData("libOffice", true, "card", 1, nullptr, libStairs, libBasementCloset, libEntry);
    libStairs->setData("libStairs", false, "", -1, nullptr, nullptr, nullptr, nullptr, libMapRoom, libOffice);  // up and down
    libWinSeat->setData("libWinSeat", true, "window seat", 9, nullptr, libStacks, nullptr, nullptr);
    libStacks->setData("libStacks", true, "map", 1, libEntry, nullptr, nullptr, libWinSeat);
    libBasementCloset->setData("libBaseClos", true, "binoculars", 1, nullptr, nullptr, nullptr, nullptr, libOffice);  // goes up
    libMapRoom->setData("libMapRoom", true, "wall", 4, libStairs, libMapRmStairs, nullptr, nullptr, libStairs);//????
    libMapRmStairs->setData("libMapRmStairs", true, "door", 4, nullptr, nullptr, nullptr, nullptr, libSecretTower, libMapRoom);
    libSecretTower->setData("libSecretTower", true, "treasure", 1, nullptr, nullptr, nullptr, nullptr, libMapRmStairs);
  // void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn


  // set space descriptions
  trainStationSp->setDescriptions("the train station", "the light switch", "Your uncle built a train station to house his dad’s memorabilia. They loved building model trains together, but what they’ve got outside it something on a much grander scale.", "There’s a light switch on the wall.", "", "You flip the switch and can see a door on the other side of the room. It leads to the train!");
  trainLocomotiveSp->setDescriptions("a half scale locomotive", "The locomotive is big enough for you to sit in. There a lots of dials, switches and an accelerator.", "the big, green button", "There’s also a power button.", "light::bool???", "Choo choo! The train goes around the property, passing the courtyard, a copse of trees and ending at the house.  As it stops you hear a rustling in the passenger car.");
  trainPassCarSp->setDescriptions("the passenger car", "the crackers", "There are eight or ten seats.", "Someone left a small package of crackers in one of them.", "button::bool??", "You take the crackers in case you get hungry later.");
  chapelPewsSp->setDescriptions("a replica of a Byzantine church", "the flashlight", "The church is cool and quiet. There are pews and, further down, a dome and an ambo built into the wall.", "As you walk down the aisle you notice a flashlight in one of the pews.", "", "You grab it just in case.");
  chapelFrontSp->setDescriptions("the ambo", "", "The ambo is of dark wood. In the stone behind it, there’s an outline of something like a door.", "", "", "You run your hand along the stone and something clicks. A door opens. It’s dark inside.");
  chapelStairsSp->setDescriptions("the secret stairs", "", "There are stairs going down.", "", "flashlight", "");
  chapelSecretPassWSp->setDescriptions("the secret passageway", "There's a corner ahead", "It's dark in here. Good thing you have a flashlight", "", "flashlight", "");
  chapelSecretPassESp->setDescriptions("the other end of the passage", "a push pin", "The flashlight dimly lights the secret passage.", "As you’re nearing the end, the light glints off something on the floor.", "flashlight", "You pick up a push pin.");
  zooStairsSp->setDescriptions("another set of stairs", "", "There are stairs going up.", "", "flashlight", "");
  zooEntrySp->setDescriptions("the zoo entrance", "the sounds", "There are trees overhead. The wind rustles through them.", "You think you hear something else.", "", "It's the sound of parrots squawking.");
  zooParrotsSp->setDescriptions("the parrot enclosure", "a key", "There's a tall wooden structure enclosed with wire. Several parrots are in the habitat. One of the parrots has something in its mouth.", "The parrots look like a snack would be welcome.", "crackers", "");
  zooLlamaSp->setDescriptions("the llama enclosure", "a sign", "A fenced in area houses several llamas.", "There’s a sign in front of them.", "", "Llamas are great pack animals, they’re super smart and their fur is used to make all kinds of things. They’re originally from South America.");
  houseSp->setDescriptions("the house", "your backpack", "You're in front of the house. No need to go back inside; you're sure the key and treasure are somewhere on your uncle's 40 acre estate.", "Your backpack is sitting on a bench.", "", "You grab your backpack. It might come in handy.");
  courtyardSp->setDescriptions("the courtyard", "", "There’s a fountain in the middle and four pathways leading in all directions.", "", "", "");
  treesSp->setDescriptions("the copse of trees", "some flowers", "It's cool in the small patch of trees.", "There are some pretty flowers along the path. They smell heavenly.", "", "Mmm. Smells nice. I wonder what you will you do with them.");
  // libEntrySp->setDescriptions();
  // libOfficeSp->setDescriptions();
  // libStairsSp->setDescriptions();
  // libWinSeatSp->setDescriptions();
  // libStacksSp->setDescriptions();
  // libBasementClosetSp->setDescriptions();
  // libMapRoomSp->setDescriptions();
  // libMapRmStairsSp->setDescriptions();
  // libSecretTowerSp->setDescriptions();

  // setDescriptions(printSpaceNameIn, printItemNameIn, spaceDescrptionIn, itemDescriptionIn, spaceDepend, descripAfterDepend);


  // int len = spaceVector.size();
  // // print spaces
  // for (int i = 0; i < len; i++) {
  //   // cout << spaceVector[i] <<endl;
  // }
};
