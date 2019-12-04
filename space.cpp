

#include <iostream>
#include <vector>
#include "space.hpp"
using std::vector;
using std::cout;// de
using std::endl;// de

Space::~Space() {
  // delete pointerHolder vector
  vector<Space*>().swap(pointerHolder);
};

void Space::setDescriptions(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn) {
  spaceNameForPrinting = printSpaceNameIn;
  spaceDescrption = spaceDescrptionIn;
  spaceName = spaceNameIn;
};

void Space::setItem(bool hasItemIn, int itemActionNumIn, string itemNameIn, string printItemNameIn, string itemDescriptionIn, string descriptionAfterItemIn) {
  hasItem = hasItemIn;
  itemName = itemNameIn;
  itemNameForPrinting = printItemNameIn;
  itemDescription = itemDescriptionIn;
  itemActionNum = itemActionNumIn;
  descriptionAfterItem = descriptionAfterItemIn;
};

void Space::setDependency(bool hasDependencyIn, string spaceDependIn, string descripAfterDependIn) {
  hasDependency = hasDependencyIn;
  spaceDependency = spaceDependIn;
  descriptionAfterDependency = descripAfterDependIn;  
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

string Space::getDescriptionAfterItem() {
  return descriptionAfterItem;
};


string Space::getDescriptionAfterDependency() {
  return descriptionAfterDependency;
};

int Space::getItemActionNum() {
  return itemActionNum;
}

string Space::getSpaceDependency() {
  return spaceDependency;
}

bool Space::hasSpaceDependency() {
  if (spaceDependency == "") {
    return false;
  }
  return true;
}

bool Space::isItemTaken() {
  return itemTaken; // a getter
}


void Space::setItemTaken(bool yesOrNo) {
  itemTaken = yesOrNo;
}




// string Space::getSpaceType() {

// }