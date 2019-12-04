
// only has default contructor bc all spaces need to be instantiated before passing their pointers to other space object

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

#ifndef KBIERMA_SPACE_HPP
#define KBIERMA_SPACE_HPP

class Space {
  protected:
    string spaceName;
    string spaceNameForPrinting;
    string spaceDescrption;

    // bool hasBackpack = false;
    bool hasItem = false;
    string itemName;
    string itemNameForPrinting;
    string itemDescription;
    int itemActionNum;
    bool itemTaken = false;
    string descriptionAfterItem;

    bool hasDependency = false;
    string spaceDependency;
    string descriptionAfterDependency;    

    bool haveItemNeededInBackpack = false;

    Space *north;
    Space *east;
    Space *south;
    Space *west;
    vector<Space*> pointerHolder;

  public:
    ~Space();

    void setDescriptions(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn);

    void setItem(bool hasItem, int itemActionNumIn, string itemNameIn, string printItemNameIn, string itemDescriptionIn, string descriptionAfterItem);

    void setDependency(bool hasDependency, string spaceDepend, string descripAfterDepend);


    void setItemTaken(bool yesOrNo);

    vector<Space*> getSpacePointers();
    string getSpaceName();
    string getSpaceNameForPrinting();
    string getSpaceDescription();

    bool hasSpaceDependency();
    string getSpaceDependency();
    string getDescriptionAfterDependency();

    // bool getHasBackpack();
    string getItemName();
    string getItemNameForPrinting();
    int getItemActionNum();
    bool getHasItem();
    bool isItemTaken(); // a getter
    string getVerbForAction();
    string getItemDescription();
    string getDescriptionAfterItem();


    virtual string getSpaceType() = 0;
};

#endif