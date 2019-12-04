

#include <iostream>
#include <string>
#include "item.hpp"
using std::string;

#ifndef KBIERMA_Toggle_HPP
#define KBIERMA_Toggle_HPP

class ItemToggle : public Item {
  protected:
    bool on = false;
    string wordForItemOn;
    string wordForItemOff;
  public:
    ItemToggle(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDep);

    // Toggle(string nameIn, string printNameIn, string actionIn, string originalSpIn, string descripIn, string descriptAfterIn, bool dependency);
    void setOn(); // toggle
    bool getOn();
    string getWordForItemOn();
    string getWordForItemOff();
};

#endif