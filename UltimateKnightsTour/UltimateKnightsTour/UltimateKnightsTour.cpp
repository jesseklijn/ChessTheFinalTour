// UltimateKnightsTour.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Board.h"
#include "Knight.h"
#include <iostream>
using namespace std;




int main()
{
	//Create fields to be used
	int x = 5, y = 5;
	int xStart = 1, yStart = 2;

	//Loop through x and y values if specified as 4 or lower
	while (x < 5)
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
	while (y < 5)
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

	//Loop through start positions for the knight
	while (xStart <= -1)
	{
		//Ask for x size of board
		cout << "Please enter a desired Start Position.. \nX position ";
		cin >> xStart;

		//If value is not numeric
		if (!cin) {
			cin.clear();
			cin.ignore(999, '\n');
		}

		//Clear console
		system("cls");

	}
	while (yStart <= -1)
	{
		//Ask for x size of board
		cout << "Please enter a desired Start Position.. \nY position: ";
		cin >> yStart;

		//If value is not numeric
		if (!cin) {
			cin.clear();
			cin.ignore(999, '\n');
		}

		//Clear console
		system("cls");

	}

	//Create a board with appropiate sizes
	Board board(x, y);

	//Create a knight on the start positions requested
	Knight knight;

	board.tileMap[xStart][yStart].Use();

	//Start moving the knight
	while(knight.Move(board, board.tileMap[xStart][yStart]) == false) {

		printf("Solution has not been found \n");
	

	}
	


	//Wait for input and close console application
	system("PAUSE");
	return 0;
}

