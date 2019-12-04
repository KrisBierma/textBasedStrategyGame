



#include "space.hpp"
// #include "undergroundSpace.hpp"

#ifndef KBIERMA_UNDERGROUNDSPACE_HPP
#define KBIERMA_UNDERGROUNDSPACE_HPP

class UndergroundSpace : public Space {
  private:
    Space *up;
  public:
    UndergroundSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn);

    // UndergroundSpace();
    // ~UndergroundSpace();
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *upIn);

    // void setUpPointer(Space *upSpaceIn);

    virtual string getSpaceType();
};

#endif
