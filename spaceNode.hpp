

#include "space.hpp"

struct SpaceNode {
  Space *spaceObj;
  SpaceNode *north;
  SpaceNode *east;
  SpaceNode *south;
  SpaceNode *west;
  SpaceNode *up;
  SpaceNode *down;

  SpaceNode(Space *spaceObjIn, SpaceNode *northIn, SpaceNode *eastIn, SpaceNode *southIn, SpaceNode *westIn, SpaceNode *upIn, SpaceNode *downIn) {
    spaceObj = spaceObjIn;
    north = northIn;
    east = eastIn;
    south = southIn;
    west = westIn;
    up = upIn;
    down = downIn;
  };
};