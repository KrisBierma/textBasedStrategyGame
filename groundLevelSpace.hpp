

#include "space.hpp"
// #include "groundLevelSpace.hpp"

#ifndef KBIERMA_GROUNDLEVELSPACE_HPP
#define KBIERMA_GROUNDLEVELSPACE_HPP

class GndLvlSpace : public Space {
  public:
    GndLvlSpace(string spaceNameIn, string printSpaceNameIn, string spaceDescrptionIn);
    // ~GndLvlSpace();
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn);

    virtual string getSpaceType();
};

#endif
