/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	StairsSpace class is derived from Space class. 
**              It overrides the getSpaceType functions, has its own
**              setPointers function and inherits everything else
**              the base Space class.
**              It also has a location variable to determine if the 
**              stairs are above or below ground.
********************************************************************/
#include "space.hpp"

#ifndef KBIERMA_STAIRSSPACE_HPP
#define KBIERMA_STAIRSSPACE_HPP

class StairsSpace : public Space {
  private:
    Space *up;
    Space *down;
    int location; // 0=underGround, 1=aboveGround
  public:
    StairsSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn);
    ~StairsSpace() {};
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn);

    void setLocation(int locationIn);
    int getLocation();

    virtual string getSpaceType();
};

#endif