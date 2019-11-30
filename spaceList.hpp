

#include "spaceNode.hpp"

#ifndef KBIERMA_SPACELIST_HPP
#define KBIERMA_SPACELIST_HPP


class SpaceList {
  protected:
    SpaceNode *head;
  public:
    SpaceList();
    ~SpaceList();
    bool isHead();
    Space* getHead(); //??
    void addNode(Space *spaceObj);
    void printList();
};

#endif