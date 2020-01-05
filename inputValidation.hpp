/********************************************************************
** Program name:The Secret Treasure, A Text-Based Game (Project 5)
** Author:    	Kris Bierma
** Date:	      12/6/19
** Description:	Input validation includes a base function to validate user
**              input for a valid integer (positive, negative or either). 
**              Also validates for specific functions: int greater than 1
**              for an array size and int [1-50] for triangular number. 
********************************************************************/

#include <iostream>
#include <string>
using std::string;

#ifndef KBIERMA_INPUTVALIDATION_HPP
#define KBIERMA_INPUTVALIDATION_HPP

int validateIntegers(string message, int posNegBoth);   // 1 - positive nums only; 2 - negative nums only; 3 - pos or neg
bool checkForNegNum(bool isIntegerFlag, string userChoice);
bool checkForPosNum(bool isIntegerFlag, string userChoice);
string validateStrings(std::string message);

#endif