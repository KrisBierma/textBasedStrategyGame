

#include "space.hpp"
#include "stairsSpace.hpp"
#include "aboveGroundSpace.hpp"
#include "undergroundSpace.hpp"
#include "groundLevelSpace.hpp"
#include <tuple>
using std::tuple;

// vector<Space*> setUpSpaceDescriptions();

void setUpSpaceDescriptions(vector<Space*>&spaceVector,  tuple<GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, UndergroundSpace*, UndergroundSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, GndLvlSpace*, StairsSpace*, GndLvlSpace*, GndLvlSpace*, UndergroundSpace*, AboveGroundSpace*, StairsSpace*, AboveGroundSpace*>&spaceTupl);
// void setSpaceData_underGround(vector<UndergroundSpace*>&spaceVector);
// void setSpaceData_aboveGround(vector<AboveGroundSpace*>&spaceVector);
// void setSpaceData_groundLvl(vector<GndLvlSpace*>&spaceVector);
// void setSpaceData_stairs(vector<StairsSpace*>&spaceVector);