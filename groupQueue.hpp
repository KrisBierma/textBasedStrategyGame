/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma
** Date:	      11/19/19
** Description:	Queue class builds a circular queue object that contains
**              a head pointing to a queueNode struct. 
**              There is a constructor, destructor, and functions to 
**              add a node to the back, remove the front node, print
**              the whole list. There are also functions to check if  
**              there is a head, get the head and change the head.
********************************************************************/
#include "charNode.hpp"

#ifndef KBIERMA_GROUPQUEUE_HPP
#define KBIERMA_GROUPQUEUE_HPP

class GroupQueue {
  protected:
    CharNode *head;
  public:
    GroupQueue();
    ~GroupQueue();
    bool isHead();
    Animal* getHead();
    void changeHead();
    void addNodeEnd(Animal *animalObj);
    void removeNodeFront();
    void printQueue(int groupNumIn);
};

#endif