/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	ItemToggle class is a derived class of Item.
**              It has a getter and setter for the toggle and the 
**              words that describe that (on/off, open/closed, in/out).
********************************************************************/

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

    void setOn(); // toggle
    bool getOn();
    void setWordsForOnOff(string onIn, string offIn);
    string getWordForItemOn();
    string getWordForItemOff();
};

#endif