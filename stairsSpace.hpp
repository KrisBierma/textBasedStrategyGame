




#include "space.hpp"
// #include "stairsSpace.hpp"

#ifndef KBIERMA_STAIRSSPACE_HPP
#define KBIERMA_STAIRSSPACE_HPP

// enum upOrDown {downStairs, upStairs};

class StairsSpace : public Space {
  private:
    Space *up;
    Space *down;
    // upOrDown location; ????
    int location; // 0=aboveGround, 1=underground
  public:
    StairsSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn, string spaceDescriptionAfterDependencyIn);
    // ~StairsSpace();
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn);

    // void setDownPointer(Space *downSpaceIn);
    // void location(upOrDown locationIn);
    void setLocation(int locationIn);
    int getLocation();

    virtual string getSpaceType();
};

#endif