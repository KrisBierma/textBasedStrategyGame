/********************************************************************
** Program name:Animals in the Wild - Multi-level Survival (Project 4)
** Author:    	Kris Bierma
** Date:	      11/19/19
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
  public:
    Menu(vector<string> &vectorChoices, vector<int> &menuInput);
    ~Menu();
    void getMenu();
    int getUserChoice();
};

#endif
