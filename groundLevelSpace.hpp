

#include "space.hpp"
// #include "groundLevelSpace.hpp"

#ifndef KBIERMA_GROUNDLEVELSPACE_HPP
#define KBIERMA_GROUNDLEVELSPACE_HPP

class GndLvlSpace : public Space {
  public:
    GndLvlSpace();
    // ~GndLvlSpace();
    void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn);

    virtual string getSpaceType();
    // virtual void setData(string spaceNameIn, bool hasItem, string itemNameIn, int itemActionNumIn, Space *northIn, Space *eastIn, Space *southIn, Space *westIn);
};

#endif
