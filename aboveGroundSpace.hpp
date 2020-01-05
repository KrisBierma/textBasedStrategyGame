/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	AboveGroundSpace class is derived from Space class. 
**              It overrides the getSpaceType functions, has its own
**              setPointers function and inherits everything else
**              the base Space class.
********************************************************************/
#include "space.hpp"

#ifndef KBIERMA_ABOVEGROUNDSPACE_HPP
#define KBIERMA_ABOVEGROUNDSPACE_HPP

class AboveGroundSpace : public Space {
  private:
    Space *down;
  public:
    AboveGroundSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn);
    ~AboveGroundSpace() {};
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *downIn);
    virtual string getSpaceType();
};

#endif