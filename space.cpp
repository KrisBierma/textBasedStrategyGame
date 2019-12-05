

#include <iostream>
#include <vector>
#include "space.hpp"
using std::vector;
using std::cout;// de
using std::endl;// de

Space::Space(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn) {
  spaceNameForPrinting = printSpaceNameIn;
  spaceDescrption = spaceDescrptionIn;
  spaceName = spaceNameIn;
  hasPtrDependency = false;
  hasDependency = false;
};

Space::~Space() {
  // delete pointerHolder vector
  vector<Space*>().swap(pointerHolder);
};

void Space::setItem(bool hasItemIn, Item *itemIn) {
  hasItem = hasItemIn;
  item = itemIn;
};

void Space::setDependency(bool hasDependencyIn, Item *dependencyIn) {
  hasDependency = hasDependencyIn;
  spaceDependency = dependencyIn;  
};

void Space::setPtrDependency(bool hasPtrDepIn, Space *spacePtrIn, Item *dependendOnIn) {
  hasPtrDependency = hasPtrDepIn;
  spacePtrDepend = spacePtrIn;
  itemItsDependentOn = dependendOnIn;
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

bool Space::getHasItem() {
  return hasItem;
}

//getter
bool Space::hasSpaceDependency() {
  return hasDependency;
}

// void Space::setItemDependFullfilled() {
//   // itemDependencyFulfilled = !itemDependencyFulfilled;
// };

// bool Space::isItemDependFullfilled() {
//   // return itemDependencyFulfilled;
//   // spaceDependency->
// };


Item* Space::getItem() {
  return item;
}

string Space::getSpaceDescription() {
  return spaceDescrption;
};

Item* Space::getSpaceDependency() {
  return spaceDependency;
}

bool Space::getHasPointerDependency() {\
  return hasPtrDependency;
};

Space* Space::getSpacePtrDepend() {
  return spacePtrDepend;
};

Item* Space::getItemPtrDependentOn() {
  return itemItsDependentOn;
};


// bool Space::hasSpaceDependency() {
//   if (spaceDependency == "") {
//     return false;
//   }
//   return true;
// }


// if item not in original space
bool Space::isItemTaken() {
  return itemTaken; // a getter
}


void Space::setItemTaken(bool yesOrNo) {
  itemTaken = yesOrNo;
}

void Space::setItemDepenDone() {
  itemDepenDone = !itemDepenDone;
};

bool Space::getItemDepenDone() {
  return itemDepenDone;
}



// string Space::getSpaceType() {

// }