

#include "spaceList.hpp"


SpaceList::SpaceList() {
  head = nullptr;
};

SpaceList::~SpaceList() {

};

bool SpaceList::isHead() {
  if (head != nullptr) {
    return true;
  }
  return false;
};

Space* SpaceList::getHead() {
  return head->spaceObj;
};

void SpaceList::addNode(Space *spaceObj) {

};

void SpaceList::printList() {

};

