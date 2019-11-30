/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma
** Date:	      11/19/19
** Description:	Queue class builds a cicular queue object that contains
**              a head pointing to a queueNode struct. 
**              There is a constructor, destructor, and functions to 
**              add a node to the back, remove the front node, print
**              the whole list. There are also functions to check if  
**              there is a head, get the head and change the head.
********************************************************************/
#include <iostream>
#include "groupQueue.hpp"
using std::cout;
using std::endl;


/********************************************
 ** Function:     Queue constructor
 ** Description:  Instantiates queue class and sets head to nullptr.
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  Creates queue object
 ********************************************/
GroupQueue::GroupQueue() {
  head = nullptr;
};


/********************************************
 ** Function:     Queue destructor
 ** Description:  Deletes all list nodes and sets head to nullptr.
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  destroys queue object
 ********************************************/
GroupQueue::~GroupQueue() {
  if (isHead()) {
    CharNode *trash = head;
    CharNode *last = head->prev;
    while (head != last) {
      head = head->next;
      delete trash->animalObj;
      delete trash;
      trash = head;
    }
    delete head->animalObj;
    delete head;
  }
  head = nullptr;
};


/********************************************
 ** Function:     getter
 ********************************************/
Animal* GroupQueue::getHead() {
  return head->animalObj;
};


/********************************************
 ** Function:     isHead
 ** Description:  Checks to see if there is the list is empty
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  returns true/false
 ********************************************/
bool GroupQueue::isHead() {
  if (head != nullptr) {
    return true;
  }
  return false;
};


/********************************************
 ** Function:     changeHead
 ** Description:  Moves the head to the next node
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  returns nothing
 ********************************************/
void GroupQueue::changeHead() {
  head = head->next;
};


/********************************************
 ** Function:     addNodeEnd
 ** Description:  Adds a node to the back of the list
 ** Parameters:       user-entered integer
 ** Pre-Conditions:   none
 ** Post-Conditions:  returns nothing; adds a node to list
 ********************************************/
void GroupQueue::addNodeEnd(Animal *animalObj) {
  if (!isHead()) {
    head = new CharNode(animalObj, head, head);
    head->next = head->prev = head;
  }
  else {
    CharNode *last = head->prev;
    last->next = new CharNode(animalObj, head, last);
    CharNode *charPtr = last->next;
    charPtr->prev = last;
    charPtr->next = head;
    head->prev = charPtr;
  };
};


/********************************************
 ** Function:     removeNodeFront
 ** Description:  Removes the first node on the list
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  returns nothing; deletes the first node
 ********************************************/
void GroupQueue::removeNodeFront() {
  if (!isHead()) {
    cout << "The group is empty.\n";
  }
  else if (head->next == head) {
    delete head;
    head = nullptr;
  }
  else {
    CharNode *trash = head;
    CharNode *last = head->prev;
    head = head->next;
    head->prev = last;
    last->next = head;
    delete trash;
  }
};


/********************************************
 ** Function:     printQueue
 ** Description:  Prints the list
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  returns nothing
 ********************************************/
void GroupQueue::printQueue(int groupNumIn) {
  if (!isHead()) {
    cout << "The group is empty.\n";
  }
  else {
    if (groupNumIn == 0) {
      cout << "Losers: ";
    }
    else {
      cout << "Group " << groupNumIn << ": ";
    }
    CharNode *nodePtr = head;
    while (nodePtr->next != head) {
      cout << nodePtr->animalObj->getName() << "  ";
      nodePtr = nodePtr->next;
    }
    cout << nodePtr->animalObj->getName() << endl;
  }
};