// UltimateKnightsTour.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Board.h"
#include <iostream>
using namespace std;




int main()
{
	int x = 5, y = 5;
	int input;

	//Loop through x and y values if specified as 0 or lower
	while (x <= 0)
	{
		//Ask for x size of board
		cout << "Please enter a desired size.. \nWidth: ";
		cin >> x;
		
		//If value is not numeric
		if (!cin) {
			cin.clear();
			cin.ignore(999, '\n');
		}
		
		//Clear console
		system("cls");
		
	}
	
	while (y <= 0)
	{
		//Ask for x size of board
		cout << "Please enter a desired size.. \nHeight: ";
		cin >> y;

		//If value is not numeric
		if (!cin) {
			cin.clear();
			cin.ignore(999, '\n');
		}

		//Clear console
		system("cls");

	}
	
	//Create a board with appropiate sizes
	Board board(x,y);
	
	//Wait for input and close console application
	system("PAUSE");
    return 0;
}

