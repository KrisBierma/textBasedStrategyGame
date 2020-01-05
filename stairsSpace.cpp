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
#include "stairsSpace.hpp"


/********************************************
 ** Function:     StairsSpace constructor
 ** Description:  Instantiates StairsSpace class, setting its name and
                  descriptions and its dependencies to false by default
 ** Parameters:       Takes in the name, the name to be printed, the 
                      description and the description after its 
 **                   dependency is done.
 ** Pre-Conditions:   none
 ** Post-Conditions:  Creates a StairsSpace object
 ********************************************/
StairsSpace::StairsSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn) : Space(spaceNameIn, printSpaceNameIn, spaceDescrptionIn, spaceDescriptionAfterDependencyIn) {};


/********************************************
 ** Function:     setPointers
 ** Description:  Sets pointer values for the four cardinal
 **               directions plus up and down
 ** Parameters:       Space pointers for north, south, east, west, up and down
 ** Pre-Conditions:   none
 ** Post-Conditions:  Constructs the GndLvlSpace object
 ********************************************/
void StairsSpace::setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn) {
  north = northIn;
  east = eastIn;
  south = southIn;
  west = westIn;
  up = upIn;
  down = downIn;

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
  if (up != nullptr) {
    pointerHolder.push_back(up);
  }  
  if (down != nullptr) {
    pointerHolder.push_back(down);
  }

};


/********************************************
 ** Function:     setter and getter for location
 ** Description:  Location is above or below ground, for use in
 **               determing prepositions in relation to its pointers
 ** Parameters:       0 for below ground or 1 for above ground
 ** Pre-Conditions:   none
 ** Post-Conditions:  gets or sets the location
 ********************************************/
void StairsSpace::setLocation(int locationIn) {
  location = locationIn;
};

int StairsSpace::getLocation() {
  return location;
}


/********************************************
 ** Function:     getSpaceType
 ** Description:  Returns the type of space
 ** Parameters:       none
 ** Pre-Conditions:   none
 ** Post-Conditions:  Returns a string
 ********************************************/
string StairsSpace::getSpaceType() {
  return "stairs";
};