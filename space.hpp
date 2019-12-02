
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
    string itemName;
    string itemNameForPrinting;
    string itemDescription;
    int itemActionNum;
    bool hasItem;
    bool itemTaken = false;

    // string afterActionDescription;

    string spaceDependency;
    string descriptionAfterDependency;    

    bool haveItemNeededInBackpack = false;

    Space *north;
    Space *east;
    Space *south;
    Space *west;
    vector<Space*> pointerHolder;

  public:
    // Space(string spaceNameIn, string itemNameIn, Space *north, Space *east, Space *south, Space *west, Space *up, Space *down);
    // virtual ~Space() = 0;
    ~Space();
    // void setData(string spaceNameIn, string itemNameIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn);
    
    // for groundFloor
    // virtual void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn);
    // // for underground or aboveGround
    // virtual void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upOrDownIn);
    // // for stairs
    // virtual void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn);


    // virtual void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn);

    void setDescriptions(string printSpaceNameIn, string printItemNameIn, string spaceDescrptionIn, string itemDescriptionIn, string spaceDepend, string descripAfterDepend);
    void setItemTaken(bool yesOrNo);

    vector<Space*> getSpacePointers();
    string getSpaceName();
    string getSpaceNameForPrinting();
    string getSpaceDescription();

    bool hasSpaceDependency();
    string getSpaceDependency();

    // bool getHasBackpack();
    string getItemName();
    string getItemNameForPrinting();
    int getItemActionNum();
    bool getHasItem();
    bool isItemTaken(); // a getter
    string getVerbForAction();
    string getItemDescription();
    string getDescriptionAfterDependency();

    virtual string getSpaceType() = 0;
};

#endif