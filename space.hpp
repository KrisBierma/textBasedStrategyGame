
// only has default contructor bc all spaces need to be instantiated before passing their pointers to other space object

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
    string spaceName;
    string spaceNameForPrinting;
    string spaceDescription;
    string spaceDescriptionAfterDependency;

    bool hasItem = false;
    Item *item;
    bool itemTaken = false;

    bool hasDependency = false;
    Item *spaceDependency;
    bool itemDepenDone = false;
    // string spaceDependency;
    // string descriptionAfterDependency;    

    // bool haveItemNeededInBackpack = false;

    bool hasPtrDependency;
    Space *spacePtrDepend;
    Item *itemItsDependentOn;

    Space *north;
    Space *east;
    Space *south;
    Space *west;
    vector<Space*> pointerHolder;

  public:
    Space(string spaceNameIn, string printSpaceNameIn, string spaceDescriptionIn, string spaceDescriptionAfterDependencyIn);
    ~Space();

    // void setDescriptions();

    void setItem(bool hasItem, Item *itemIn);

    void setDependency(bool hasDependencyIn, Item *dependencyIn);

    void setPtrDependency(bool hasPtrDepIn, Space *spacePtrIn, Item *dependendOnIn);

    // void setItemTaken(bool yesOrNo);

    vector<Space*> getSpacePointers();
    string getSpaceName();
    string getSpaceNameForPrinting();
    string getSpaceDescription();
    string getSpaceDescriptAftDepend();

    bool hasSpaceDependency();
    Item* getSpaceDependency();
    void setItemDepenDone();
    bool getItemDepenDone();
    // bool isItemDependFullfilled();//getter
    // string getDescriptionAfterDependency();

    bool getHasPointerDependency();
    Space* getSpacePtrDepend();
    Item* getItemPtrDependentOn();

    // bool getHasBackpack();
    // string getItemName();
    // string getItemNameForPrinting();
    // int getItemActionNum();
    bool getHasItem();
    bool isItemTaken(); // a getter
    void setItemTaken(bool yesOrNo);
    Item* getItem();
    // string getVerbForAction();
    // string getItemDescription();
    // string getDescriptionAfterItem();


    virtual string getSpaceType() = 0;
};

#endif