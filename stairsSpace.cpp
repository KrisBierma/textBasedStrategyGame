





#include "stairsSpace.hpp"

StairsSpace::StairsSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn) : Space(spaceNameIn, printSpaceNameIn, spaceDescrptionIn) {};


// StairsSpace::~StairsSpace() {};

void StairsSpace::setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn) {
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