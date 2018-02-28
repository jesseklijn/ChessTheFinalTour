#include "stdafx.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>
#include <algorithm> 
using namespace std;


//Call initializer
Board::Board(int x, int y)
{
	//Assign sizes
	xSize = x, ySize = y;




	//Initialize a 2d array of the board
	InitializeTileMap();

	cout << "Board size:  " << tileMap.size() << "/" << tileMap[0].size() << " \n";
	//Check bounds and create connection between tiles
	CreateConnections();

	//Display the board
	DisplayBoard();


}

//Call fallback
Board::~Board()
{
}

void Board::InitializeTileMap()
{
	//Initialize tileMap of board
	tileMap.resize(xSize, vector<Tile>(ySize));
}

void Board::CreateConnections()
{
	//Create connections for each tile
	for (size_t x = 0; x < xSize; x++)
	{
		for (size_t y = 0; y < ySize; y++)
		{
			//Give tiles a position for debugging
			tileMap[x][y].x = x;
			tileMap[x][y].y = y;

			int options = 0;

#pragma region Create amount 



			//Check for amount of connections
			if (CheckBounds(-2, -1, x, y) == true) {
				options++;
			}
			if (CheckBounds(-1, -2, x, y) == true) {
				options++;
			}
			if (CheckBounds(-2, 1, x, y) == true) {
				options++;
			}
			if (CheckBounds(-1, 2, x, y) == true) {
				options++;
			}
			if (CheckBounds(+1, 2, x, y) == true) {
				options++;
			}
			if (CheckBounds(+2, 1, x, y) == true) {
				options++;
			}
			if (CheckBounds(+2, -1, x, y) == true) {
				options++;
			}
			if (CheckBounds(+1, -2, x, y) == true) {

				options++;
			}
#pragma endregion
			//Initialize connections based on amount
			tileMap[x][y].connectedTiles.resize(options);

			options = 0;


		}
	}

	//Fill the connections
	for (size_t x = 0; x < xSize; x++)
	{
		for (size_t y = 0; y < ySize; y++)
		{
			//Create an increment to help assign connectedTiles 
			int increment = 0;

#pragma region Fill Tiles
			//Fill connections with tiles

			if (CheckBounds(-2, -1, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[-2 + x][-1 + y];
				increment++;
			}
			if (CheckBounds(-2, 1, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[-2 + x][1 + y];
				increment++;
			}
			if (CheckBounds(-1, -2, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[-1 + x][-2 + y];
				increment++;
			}

			if (CheckBounds(-1, 2, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[-1 + x][2 + y];
				increment++;
			}
			if (CheckBounds(1, 2, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[1 + x][2 + y];
				increment++;
			}
			if (CheckBounds(2, 1, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[2 + x][1 + y];
				increment++;
			}
			if (CheckBounds(2, -1, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[2 + x][-1 + y];
				increment++;
			}
			if (CheckBounds(1, -2, x, y) == true) {
				tileMap[x][y].connectedTiles[increment] = tileMap[1 + x][-2 + y];
				increment++;
			}
			increment = 0;

#pragma endregion
		}
	}

}

bool Board::CheckBounds(int xInc, int yInc, int x, int y)
{
	//Check bounds of x and y within tilemap
	if ((xInc + x) >= 0 & (xInc + x) < xSize && (yInc + y) >= 0 & (yInc + y) < ySize) {

		//printf("true \n");

		return true;

	}
	else {

		//printf("false \n");

		return false;

	}
}

void Board::DisplayBoard()
{
	//system("cls");
	for (size_t x = 0; x < xSize; x++)
	{
		for (size_t y = 0; y < ySize; y++)
		{
			
			cout << tileMap[x][y].hasBeenUsed;
			if (y == ySize - 1) {
				cout << "\n";
			}
			
		}
	}
}

