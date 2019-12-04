
#include <iostream>
#include <string>
using std::string;

#ifndef KBIERMA_ITEM_HPP
#define KBIERMA_ITEM_HPP

class Item {
  protected:
    string name;
    string printName;
    int actionNum;
    // string originalSpace;
    string description;
    string descrtptionAfterUsed;
    bool dependency = false;

    string descriptionAfterDepen;

    // bool itemTaken;

    // bool used = false;
  public:
    Item(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDep);
    ~Item();

    string getDescriptionAfterDependency();
    string getItemName();
    string getItemNameForPrinting();
    int getItemActionNum();

    // bool isItemTaken(); // a getter
    string getVerbForAction();
    string getItemDescription();
    string getDescriptionAfterItem();

    // void setItemTaken(bool yesOrNo);

    // void setUsed(); // toggle
    // bool getUsed();
};

#endif