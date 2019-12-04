


#include "space.hpp"
// #include "aboveGroundSpace.hpp"

#ifndef KBIERMA_ABOVEGROUNDSPACE_HPP
#define KBIERMA_ABOVEGROUNDSPACE_HPP

class AboveGroundSpace : public Space {
  private:
    Space *down;
  public:
    AboveGroundSpace();
    // ~AboveGroundSpace();
    void setPointers(Space *northIn, Space *eastIn, Space *southIn, Space *westIn, Space *downIn);

    void setDownPointer(Space *downSpaceIn);

    virtual string getSpaceType();
};

#endif