
#include "groundLevelSpace.hpp"

GndLvlSpace::GndLvlSpace() {};

// GndLvlSpace::~GndLvlSpace() {};

void GndLvlSpace::setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn) {
  north = northIn;
  east = eastIn;
  south = southIn;
  west = westIn;

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

};

string GndLvlSpace::getSpaceType() {
  return "ground floor";
};