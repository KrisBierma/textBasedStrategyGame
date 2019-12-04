

#include "undergroundSpace.hpp"

UndergroundSpace::UndergroundSpace() {};

// UndergroundSpace::~UndergroundSpace() {};

void UndergroundSpace::setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn) {
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