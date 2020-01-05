/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	Item class is a base class (not abstract) with one class derived
**              from it (ItemToggle). It is associated with a Space class.
**              There are 15 items in the game that can be picked up, manipulated,
**              and used to unlock spaces, other items, and ultimately win the game.
**              It has functions to get its name, action, and descriptions, which
**              are different depending on where in the game the player is.
********************************************************************/

#include "item.hpp"
#include <iostream>


/********************************************
 ** Function:     Item constructor
 ** Description:  Instantiates item class, setting its name and
                  descriptions
 ** Parameters:       Takes in the name, the name to be printed, the 
                      description, the description after its been 
 **                   manipulated, and its description after the 
 **                   dependency has been accomplised (it is it a
 **                   depdendency)
 ** Pre-Conditions:   none
 ** Post-Conditions:  Creates an item object
 ********************************************/
Item::Item(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDepIn) {
  name = nameIn;
  printName = printNameIn;
  actionNum = actionIn;
  description  = descripIn;
  descrtptionAfterUsed = descriptAfterIn;
  descriptionAfterDepen = descripAfterDepIn;
};

Item::~Item() {};


/********************************************
 ** Function:     item getters for its name
 ********************************************/
string Item::getItemName() {
  return name;
};

string Item::getItemNameForPrinting() {
  return printName;
};


/********************************************
 ** Function:     item getters for its action
 ********************************************/
int Item::getItemActionNum() {
  return actionNum;
};

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
      return "Look at";
      break;
    case 8:
      return "Sit on";
      break;
    case 9:
      return "Unlock";
      break;
  }
  return "not here";
};


/********************************************
 ** Function:     item getters for its description
 ********************************************/
string Item::getItemDescription() {
  return description;
};

string Item::getDescriptionAfterItem() {
  return descrtptionAfterUsed;
};

string Item::getDescriptionAfterDependency() {
  return descriptionAfterDepen;
};