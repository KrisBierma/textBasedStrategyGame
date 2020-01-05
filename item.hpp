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
    string description;
    string descrtptionAfterUsed;
    string descriptionAfterDepen;
  public:
    Item(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDep);
    ~Item();

    // item name
    string getItemName();
    string getItemNameForPrinting();

    // item action
    int getItemActionNum();
    string getVerbForAction();
    
    // item descriptions depending on user interaction
    string getItemDescription();
    string getDescriptionAfterItem();
    string getDescriptionAfterDependency();
};

#endif