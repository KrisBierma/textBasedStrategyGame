/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description: Menu class creates reusable menus. It includes a constructor
**		          to initialze the menu with the user's options, a function
**		          to display the menu, a user-input validation function, and
**              a destructor to free up vector memory.	
********************************************************************/
#include <string>
#include <vector>
using std::vector;
using std::string;

#ifndef KBIERMA_MENU_HPP
#define KBIERMA_MENU_HPP

class Menu {
  private:
    int userChoice;
    int menuSize;
    vector<string> menuChoices;
    vector<int> menuInput;
    void getMenu();
  public:
    Menu(vector<string> &vectorChoices, vector<int> &menuInput);
    ~Menu();
    int getUserChoice();
};

#endif
