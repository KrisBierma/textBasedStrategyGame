/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma
** Date:	      11/19/19
** Description:	A CharNode struct for CharList class. 
**              Has pointers to next node, previous node, holds an 
**              animal object, and includes a constructor with those
**              three parameters.
********************************************************************/
#include "animal.hpp"

struct CharNode {
  Animal *animalObj;
  CharNode *next;
  CharNode *prev;
  CharNode(Animal *animalIn, CharNode *nextIn, CharNode *prevIn) {
    animalObj = animalIn;
    next = nextIn;
    prev = prevIn;
  };
};