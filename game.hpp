
#include "space.hpp"
#include <map>
#include <vector>
using std::vector;
using std::map;

#ifndef kbierma_game_hpp
#define kbierma_game_hpp

class Game {
  private:
    // string name = "The Secret Treasure";
    int totalRounds = 36;
    int currentRoundNum = 1;

    bool hasBackpack = false;

    // for menu
    int currentMenuNum;
    int numForItem;
    int userChoiceForThisSpace;
    int numPossibleMoves; // updated getSpacePointers() in case one is removed for dependency not being met

    // possible menu options:
    bool move = false;
    bool takeItem = false;
    bool pickUpDroppedItem = false;
    bool openBackpack = false;
    bool dropItem = false;
    bool useItem = false;
    bool quit = false;
    void resetOptions();

    Space *moveWhere;
    int openBackpackNum = -1;
    int pickUpDroppedItemNum = -1;
    int dropItemNum = -1;
    string nameOfDroppedItem;
    int useItemNum = -1;

  public:
    Game();
    ~Game();
    void displayIntro();
    // int getStartMenu();
    int getTotalRounds();
    int getCurrentRoundNum();
    int getCurrentMenuNum();
    int getUserChoiceForThisSpace();
    int getNumPossibleMoves();
    Space* getMoveWhere();
    string getNameOfDroppedItem();
    int getNumForItem();
    bool getHasBackpack();

    // menu options
    bool getMove();
    bool getPickUpDroppedItem();
    bool getOpenBackpack();
    bool getDropItem();
    bool getUseItem();
    bool getQuit();

    void setHasBackpack();

    void updateRoundNum();
    void showNewRound(Space *currentSpace);
    void displayRoundMenu(Space *currentSpaced, vector<string> backpack, map<string, string> &droppedItemsMap);

    void gameOver();
};

#endif