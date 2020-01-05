/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	GroundLevelSpace class is derived from Space class. 
**              It overrides the getSpaceType functions, has its own
**              setPointers function and inherits everything else
**              the base Space class.
********************************************************************/
#include "groundLevelSpace.hpp"


/********************************************
 ** Function:     GndLvlSpace constructor
 ** Description:  Instantiates GndLvlSpace class, setting its name and
                  descriptions and its dependencies to false by default
 ** Parameters:       Takes in the name, the name to be printed, the 
                      description and the description after its 
 **                   dependency is done.
 ** Pre-Conditions:   none
 ** Post-Conditions:  Creates a GndLvlSpace object
 ********************************************/
GndLvlSpace::GndLvlSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn) : Space(spaceNameIn, printSpaceNameIn, spaceDescrptionIn, spaceDescriptionAfterDependencyIn) {};


/********************************************
 ** Function:     setPointers
 ** Description:  Sets pointer values for the four cardinal
 **               directions
 ** Parameters:       Space pointers for north, south, east, west
 ** Pre-Conditions:   none
 ** Post-Conditions:  Constructs the GndLvlSpace object
 ********************************************/
void GndLvlSpace::setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn) {
  north = northIn;
  east = eastIn;
  south = southIn;
  west = westIn;

  if (north != nullptr) {
    pointerHolder.push_back(north);
  }
  if (east != nullptr) {
    pointerHolder.push_back(east);
  }
  if (south != nullptr) {
    pointerHolder.push_back(south);
  }
  if (west != nullptr) {
    pointerHolder.push_back(west);
  }

};


/********************************************
 ** Function:     getSpaceType
 ** Description:  Returns the type of space
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns a string
 ********************************************/
string GndLvlSpace::getSpaceType() {
  return "groundFloor";
};