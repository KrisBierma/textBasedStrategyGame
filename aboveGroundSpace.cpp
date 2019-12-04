



#include "aboveGroundSpace.hpp"

AboveGroundSpace::AboveGroundSpace(){};

// AboveGroundSpace::~AboveGroundSpace() {};

void AboveGroundSpace::setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *downIn) {
  north = northIn;
  east = eastIn;
  south = southIn;
  west = westIn;
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
  if (down != nullptr) {
    pointerHolder.push_back(down);
  }

};


string AboveGroundSpace::getSpaceType() {
  return "aboveGround";
};