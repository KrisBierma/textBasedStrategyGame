

#include <iostream>
#include <vector>
#include "space.hpp"
using std::vector;
using std::cout;// de
using std::endl;// de

// Space::Space(string spaceNameIn, string itemNameIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn) {
//   spaceName = spaceNameIn;
//   itemName = itemNameIn;
//   north = northIn;
//   east = eastIn;
//   south = southIn;
//   west = westIn;
//   up = upIn;
//   down = downIn;
// };

Space::~Space() {

};

// void Space::setData(string spaceNameIn, string itemNameIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn) {
//   spaceName = spaceNameIn;
//   itemName = itemNameIn;
//   north = northIn;
//   east = eastIn;
//   south = southIn;
//   west = westIn;
//   up = upIn;
//   down = downIn;
// };

void Space::setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn) {
  spaceName = spaceNameIn;
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

// gettters
string Space::getSpaceName() {
  return spaceName;
};

vector<Space*> Space::getSpacePointers() {
  return pointerHolder;
};

string Space::getSpaceNameForPrinting() {
  return spaceNameForPrinting;
};

string Space::getItemName() {
  return itemName;
};

string Space::getItemNameForPrinting() {
  return itemNameForPrinting;
};

bool Space::getHasItem() {
  return hasItem;
}

// item actions: 0-nothing, 1-take, 2-flip, 3-push, 4-open, 5-listen, 6-read, 7-look, 8-it's a mess
string Space::getVerbForAction() {
  switch (itemActionNum) {
    case 1:
      return "Take";
      break;
    case 2:
      return "Flip";
      break;
    case 3:
      return "Push";
      break;
    case 4:
      return "Open";
      break;
    case 5:
      return "Listen to";
      break;
    case 6:
      return "Read";
      break;
    case 7:
      return "Loop at";
      break;
    case 8:
      return "It's a mess";
      break;
  }
  return "not here";
};


string Space::getSpaceDescription() {
  return spaceDescrption;
};

string Space::getItemDescription() {
  return itemDescription;
};

string Space::getItemDescriptionAfter() {
  return afterActionDescription;
};

int Space::getItemActionNum() {
  return itemActionNum;
}


bool Space::isItemTaken() {
  return itemTaken; // a getter
}


void Space::setItemTaken(bool yesOrNo) {
  itemTaken = yesOrNo;
}

void Space::setDescriptions(string printSpaceNameIn, string printItemNameIn, string spaceDescrptionIn, string itemDescriptionIn, string afterActionDescriptionIn) {
  spaceNameForPrinting = printSpaceNameIn;
  itemNameForPrinting = printItemNameIn;
  spaceDescrption = spaceDescrptionIn;
  itemDescription = itemDescriptionIn;
  afterActionDescription = afterActionDescriptionIn;
};


void Space::printSpaces() {

}