/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	Space class is a pure vitual base. It has four 
**              derived classes: underground, above ground, ground
**              level, and stairs. Pointers link the spaces. 
**              The spaces have actions to do and/or items to
**              manipulate. There are 24 spaces.              
**              Space has many getters and setters for itself, the
**              item in it, the item it depends on, and other spaces
**              and/or items dependent on it.
********************************************************************/
#include <iostream>
#include <vector>
#include "space.hpp"
using std::vector;


/********************************************
 ** Function:     Space constructor
 ** Description:  Instantiates space class, setting its name and
                  descriptions and its dependencies to false by default
 ** Parameters:       Takes in the name, the name to be printed, the 
                      description and the description after its 
 **                   dependency is done.
 ** Pre-Conditions:   none
 ** Post-Conditions:  Creates a space object
 ********************************************/
Space::Space(string spaceNameIn, string printSpaceNameIn, string spaceDescriptionIn, string spaceDescriptionAfterDependencyIn) {
  spaceNameForPrinting = printSpaceNameIn;
  spaceDescription = spaceDescriptionIn;
  spaceDescriptionAfterDependency = spaceDescriptionAfterDependencyIn;
  spaceName = spaceNameIn;
  hasPtrDependency = false;
  hasDependency = false;
};


/********************************************
 ** Function:     Space deconstructor
 ** Description:  Destroys space class and its pointer vector
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  Destroys the space object
 ********************************************/
Space::~Space() {
  // delete pointerHolder vector
  vector<Space*>().swap(pointerHolder);
};


/********************************************
 ** Function:     space setters
 ** Description:  sets descriptions and its dependencies
 ********************************************/
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


/********************************************
 ** Function:     space getters
 ** Description:  gets space name, descriptions, pointers
 ********************************************/
string Space::getSpaceName() {
  return spaceName;
};

vector<Space*> Space::getSpacePointers() {
  return pointerHolder;
};

string Space::getSpaceNameForPrinting() {
  return spaceNameForPrinting;
};

string Space::getSpaceDescription() {
  return spaceDescription;
};

string Space::getSpaceDescriptAftDepend() {
  return spaceDescriptionAfterDependency;
};


/********************************************
 ** Function:     space's item dependency getters and setters
 ** Description:  tells whether the space has a dependency,
 **               sets/gets the Item class depedency, and
 **               sets when the dependency has been accomplished
 ********************************************/
bool Space::hasSpaceDependency() {
  return hasDependency;
};

Item* Space::getSpaceDependency() {
  return spaceDependency;
};

void Space::setItemDepenDone() {
  itemDepenDone = !itemDepenDone;
};

bool Space::getItemDepenDone() {
  return itemDepenDone;
};


/********************************************
 ** Function:     space's pointer dependency getters
 ** Description:  tells whether the space needs something 
 **               to happen for another space, and, if so,
 **               what that is and what the other space is
 ********************************************/
bool Space::getHasPointerDependency() {
  return hasPtrDependency;
};

Space* Space::getSpacePtrDepend() {
  return spacePtrDepend;
};

Item* Space::getItemPtrDependentOn() {
  return itemItsDependentOn;
};


/********************************************
 ** Function:     space's item getters and setters
 ** Description:  tells if the space has an item, what
 **               it is, and if it's been taken
 ********************************************/
bool Space::getHasItem() {
  return hasItem;
};

Item* Space::getItem() {
  return item;
};

// if item not in original space
bool Space::isItemTaken() {
  return itemTaken; // a getter
};

void Space::setItemTaken(bool yesOrNo) {
  itemTaken = yesOrNo;
};