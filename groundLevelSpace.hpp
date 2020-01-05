/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	GroundLevelSpace class is derived from Space class. 
**              It overrides the getSpaceType functions, has its own
**              setPointers function and inherits everything else
**              the base Space class.
********************************************************************/

#include "space.hpp"

#ifndef KBIERMA_GROUNDLEVELSPACE_HPP
#define KBIERMA_GROUNDLEVELSPACE_HPP

class GndLvlSpace : public Space {
  public:
    GndLvlSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn);
    ~GndLvlSpace() {};
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn);
    virtual string getSpaceType();
};

#endif
