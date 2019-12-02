





#include "stairsSpace.hpp"

StairsSpace::StairsSpace() {};

// StairsSpace::~StairsSpace() {};

void StairsSpace::setData(string spaceNameIn, bool hasItemIn, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn) {
  spaceName = spaceNameIn;
  hasItem = hasItemIn;
  itemName = itemNameIn;
  itemActionNum = itemActionNumIn;
  north = northIn;
  east = eastIn;
  south = southIn;
  west = westIn;
  up = upIn;
  down = downIn;

  if (north != nullptr) {
    pointerHolder.push_back(north);
  }
  if (east != nullptr) {
    pointerHolder.push_back(east);
  }
  if (south != nullptr) {
    pointerHolder.push_back(south);
  }
  if (west != nullptr) {
    pointerHolder.push_back(west);
  }
  if (up != nullptr) {
    pointerHolder.push_back(up);
  }  
  if (down != nullptr) {
    pointerHolder.push_back(down);
  }

};

// void StairsSpace::location(upOrDown locationIn) {
//   location = locationIn;
// };


void StairsSpace::setLocation(string locationIn) {
  location = locationIn;
};


string StairsSpace::getSpaceType() {
  return "stairs";
};