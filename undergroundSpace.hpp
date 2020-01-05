/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	UndergroundSpace class is derived from Space class. 
**              It overrides the getSpaceType functions, has its own
**              setPointers function and inherits everything else
**              the base Space class.
********************************************************************/

#include "space.hpp"

#ifndef KBIERMA_UNDERGROUNDSPACE_HPP
#define KBIERMA_UNDERGROUNDSPACE_HPP

class UndergroundSpace : public Space {
  private:
    Space *up;
  public:
    UndergroundSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn);
    ~UndergroundSpace() {};
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn);
    virtual string getSpaceType();
};

#endif
