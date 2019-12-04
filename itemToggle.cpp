

// #include "item.hpp"
#include "itemToggle.hpp"
#include <iostream>
using std::cout;// de
using std::endl;// de



ItemToggle::ItemToggle(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDepIn) : Item(actionIn, nameIn, printNameIn, descripIn, descriptAfterIn, descripAfterDepIn) {};

// ItemToggle::ItemToggle(string nameIn, string printNameIn, string actionIn, string originalSpIn, string descripIn, string descriptAfterIn, bool dependencyIn) {
//   name = nameIn;
//   printName = printNameIn;
//   action = actionIn;
//   originalSpace = originalSpIn;
//   description  = descripIn;
//   descrtptionAfterUsed = descriptAfterIn;
//   dependency = dependencyIn;
// };

// ItemToggle::~ItemToggle() {};

// toggle
void ItemToggle::setOn() {
  on = !on;
}; 

bool ItemToggle::getOn() {
  return on;
};

string ItemToggle::getWordForItemOn() {
  return wordForItemOn;
};

string ItemToggle::getWordForItemOff() {
  return wordForItemOff;
};
