

#include "undergroundSpace.hpp"

UndergroundSpace::UndergroundSpace() {};

// UndergroundSpace::~UndergroundSpace() {};

void UndergroundSpace::setData(string spaceNameIn, bool hasItemIn, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn) {
  spaceName = spaceNameIn;
  hasItem = hasItemIn;
  itemName = itemNameIn;
  itemActionNum = itemActionNumIn;
  north = northIn;
  east = eastIn;
  south = southIn;
  west = westIn;
  up = upIn;

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

};

// void UndergroundSpace::setUpPointer(Space *upSpaceIn) {
//   up = upSpaceIn;
// }

string UndergroundSpace::getSpaceType() {
  return "underground";
};