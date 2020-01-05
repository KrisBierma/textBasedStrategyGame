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
#include <string>
#include <vector>
#include "item.hpp"
using std::vector;
using std::string;

#ifndef KBIERMA_SPACE_HPP
#define KBIERMA_SPACE_HPP

class Space {
  protected:
    // for the space
    string spaceName;
    string spaceNameForPrinting;
    string spaceDescription;
    string spaceDescriptionAfterDependency;

    // about the item in the space
    bool hasItem = false;
    Item *item;
    bool itemTaken = false;

    // about the item the space is dependent on
    bool hasDependency = false;
    Item *spaceDependency;
    bool itemDepenDone = false;

    // about the space's pointer that's dependent on something
    bool hasPtrDependency;
    Space *spacePtrDepend;
    Item *itemItsDependentOn;

    // other space's attached to the current space
    Space *north;
    Space *east;
    Space *south;
    Space *west;
    vector<Space*> pointerHolder;

  public:
    Space(string spaceNameIn, string printSpaceNameIn, string spaceDescriptionIn, string spaceDescriptionAfterDependencyIn);
    virtual ~Space();

    // object setters
    void setItem(bool hasItem, Item *itemIn);
    void setDependency(bool hasDependencyIn, Item *dependencyIn);
    void setPtrDependency(bool hasPtrDepIn, Space *spacePtrIn, Item *dependendOnIn);

    // space getters
    vector<Space*> getSpacePointers();
    string getSpaceName();
    string getSpaceNameForPrinting();
    string getSpaceDescription();
    string getSpaceDescriptAftDepend();

    // space's item dependency getters and setters
    bool hasSpaceDependency();
    Item* getSpaceDependency();
    void setItemDepenDone();
    bool getItemDepenDone();

    // space's pointer dependency getters
    bool getHasPointerDependency();
    Space* getSpacePtrDepend();
    Item* getItemPtrDependentOn();

    // space's item getters and setters
    bool getHasItem();
    bool isItemTaken(); // a getter
    void setItemTaken(bool yesOrNo);
    Item* getItem();

    virtual string getSpaceType() = 0;
};

#endif