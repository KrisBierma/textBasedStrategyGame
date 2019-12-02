
#include "groundLevelSpace.hpp"

GndLvlSpace::GndLvlSpace() {};

// GndLvlSpace::~GndLvlSpace() {};

void GndLvlSpace::setData(string spaceNameIn, bool hasItemIn, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn) {
  spaceName = spaceNameIn;
  hasItem = hasItemIn;
  itemName = itemNameIn;
  itemActionNum = itemActionNumIn;
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