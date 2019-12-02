




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
    string location; // "up" "down"
  public:
    StairsSpace();
    // ~StairsSpace();
    void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn, Space *downIn);

    // void setDownPointer(Space *downSpaceIn);
    // void location(upOrDown locationIn);
    void setLocation(string locationIn);

    virtual string getSpaceType();
};

#endif