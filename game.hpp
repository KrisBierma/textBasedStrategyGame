/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	Game class holds information for game play, creates the
**              menu for each round, and displays game intro, round and
**              end game information.
********************************************************************/
#include "space.hpp"
#include <map>
#include <vector>
using std::vector;
using std::map;

#ifndef kbierma_game_hpp
#define kbierma_game_hpp

class Game {
  private:
    int totalRounds = 48;
    int currentRoundNum = 1;

    bool hasBackpack = false;

    // for menu creation
    int currentMenuNum;
    int numForItem;
    int userChoiceForThisSpace;
    int numPossibleMoves; // updated getSpacePointers() in case one is removed for dependency not being met
    Space *moveWhere;

    // possible menu options:
    bool move = false;
    bool takeItem = false;
    bool pickUpDroppedItem = false;
    bool openBackpack = false;
    bool dropItem = false;
    bool useItem = false;
    bool quit = false;
    void resetOptions();

    // value for menu
    int openBackpackNum = -1;
    int pickUpDroppedItemNum = -1;
    int dropItemNum = -1;
    string nameOfDroppedItem;
    int useItemNum = -1;

  public:
    void displayIntro();
    int getTotalRounds();
    int getCurrentRoundNum();
    int getUserChoiceForThisSpace();
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

    void updateRoundNum();
    void showNewRound(Space *currentSpace);
    void displayRoundMenu(Space *currentSpaced, vector<string> backpack, map<string, string> &droppedItemsMap);

    void displayRanOutOfTime();
    void gameOver();
};

#endif