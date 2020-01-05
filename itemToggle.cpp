/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	ItemToggle class is a derived class of Item.
**              It has a getter and setter for the toggle and the 
**              words that describe that (on/off, open/closed, in/out).
********************************************************************/
#include <iostream>
#include "itemToggle.hpp"


/********************************************
 ** Function:     Item constructor
 ** Description:  Instantiates ItemToggle class, setting its name and
                  descriptions (it takes in nothing new from its base class)
 ** Parameters:       Takes in the name, the name to be printed, the 
                      description, the description after its been 
 **                   manipulated, and its description after the 
 **                   dependency has been accomplised (it is it a
 **                   depdendency)
 ** Pre-Conditions:   none
 ** Post-Conditions:  Creates an item object
 ********************************************/
ItemToggle::ItemToggle(int actionIn, string nameIn, string printNameIn, string descripIn, string descriptAfterIn, string descripAfterDepIn) : Item(actionIn, nameIn, printNameIn, descripIn, descriptAfterIn, descripAfterDepIn) {};


/********************************************
 ** Function:     item getters/setter for its toggle
 ********************************************/
void ItemToggle::setOn() {
  on = !on;
}; 

bool ItemToggle::getOn() {
  return on;
};


/********************************************
 ** Function:     item getters/setter for its on/off words
 ********************************************/
void ItemToggle::setWordsForOnOff(string onIn, string offIn) {
  wordForItemOn = onIn;
  wordForItemOff = offIn;
};

string ItemToggle::getWordForItemOn() {
  return wordForItemOn;
};

string ItemToggle::getWordForItemOff() {
  return wordForItemOff;
};
