#include "stdafx.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>

using namespace std;


//Call initializer
Board::Board(int x, int y)
{
	//Assign sizes
	xSize = x, ySize = y;

	cout << "Board size:  " << xSize << "/" << ySize <<" \n";





}

//Call fallback
Board::~Board()
{
}
