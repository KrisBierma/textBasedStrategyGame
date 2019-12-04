

#include "item.hpp"
#include <iostream>
using std::cout;// de
using std::endl;// de

// Item::Item(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string originalSpIn, bool dependencyIn, string descripAfterDepIn) {

Item::Item(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDepIn) {
  name = nameIn;
  printName = printNameIn;
  actionNum = actionIn;
  // originalSpace = originalSpIn;
  description  = descripIn;
  descrtptionAfterUsed = descriptAfterIn;
  dependency = dependencyIn;
  descriptionAfterDepen = descripAfterDepIn;
};

Item::~Item() {};

string Item::getItemName() {
  return name;
};

string Item::getItemNameForPrinting() {
  return printName;
};

int Item::getItemActionNum() {
  return actionNum;
};

// bool Item::isItemTaken() {
//   return itemTaken;
// }; // a getter

// item actions: 0-nothing, 1-take, 2-flip, 3-push, 4-open, 5-listen, 6-read, 7-look, 8-it's a mess
string Item::getVerbForAction() {
switch (actionNum) {
    case 1:
      return "Take";
      break;
    case 2:
      return "Flip";
      break;
    case 3:
      return "Push";
      break;
    case 4:
      return "Open";
      break;
    case 5:
      return "Listen to";
      break;
    case 6:
      return "Read";
      break;
    case 7:
      return "Loop at";
      break;
    case 8:
      return "It's a mess";
      break;
  }
  return "not here";
};

string Item::getItemDescription() {
  return description;
};

string Item::getDescriptionAfterItem() {
  return descrtptionAfterUsed;
};

string Item::getDescriptionAfterDependency() {
  return descriptionAfterDepen;
};


