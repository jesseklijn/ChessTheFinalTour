// UltimateKnightsTour.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	int x = 0, y = 0;
	int input;
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
	
	//TODO: Call board to be initialized

	//Wait for input and close console application
	system("PAUSE");
    return 0;
}

