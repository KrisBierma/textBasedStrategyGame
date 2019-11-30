
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
    string itemName;
    string itemNameForPrinting;
    string itemDescription;
    int itemActionNum;
    bool hasItem;
    bool itemTaken = false;

    string afterActionDescription;

    bool haveItemNeededInBackpack = false;

    Space *north;
    Space *east;
    Space *south;
    Space *west;
    Space *up;
    Space *down;
    vector<Space*> pointerHolder;

  public:
    // Space(string spaceNameIn, string itemNameIn, Space *north, Space *east, Space *south, Space *west, Space *up, Space *down);
    ~Space();
    // void setData(string spaceNameIn, string itemNameIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn);
    void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn);
    void setDescriptions(string printSpaceNameIn, string printItemNameIn, string spaceDescrptionIn, string itemDescriptionIn, string afterActionDescriptionIn);
    void setItemTaken(bool yesOrNo);

    vector<Space*> getSpacePointers();
    string getSpaceName();
    string getSpaceNameForPrinting();
    string getSpaceDescription();

    // bool getHasBackpack();
    string getItemName();
    string getItemNameForPrinting();
    int getItemActionNum();
    bool getHasItem();
    bool isItemTaken(); // a getter
    string getVerbForAction();
    string getItemDescription();
    string getItemDescriptionAfter();

    void printSpaces();
};

#endif