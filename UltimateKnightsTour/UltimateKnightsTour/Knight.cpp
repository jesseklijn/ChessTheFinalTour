#include "stdafx.h"
#include "Knight.h"
#include <vector>


Knight::Knight(Tile startingTile)
{
	//Assign the knight to a tile that was given from input
	currentTile = startingTile;
	//Has been stepped on by the knight
	currentTile.hasBeenUsed = true;





}


Knight::~Knight()
{
	//Fallback method
}

void Knight::Move()
{
	//Check based on current tile where to go next
	Tile toMoveTo = Check(currentTile.connectedTiles);



	//Assign the knight to a tile that was given from input
	//currentTile = toMoveTo;

	//Has been stepped on by the knight
	//currentTile.hasBeenUsed = true;
}

Tile Knight::Check(vector<Tile> connectedTiles)
{


	cout << "Currenttile:" << "[" << currentTile.x << "/" << currentTile.y << "]" << endl;


	Tile mostEfficientTile;
	for (size_t i = 0; i < connectedTiles.size(); i++)
	{
		cout << "Test[" << i << "]: [" << connectedTiles[i].x << "/" << connectedTiles[i].y << "]" << connectedTiles[i].connectedTiles.size() << endl;

		if (i == 0) {
			mostEfficientTile = connectedTiles[i];
		}
		else {
			if (mostEfficientTile.connectedTiles.size() > connectedTiles[i].connectedTiles.size()) {
				mostEfficientTile = connectedTiles[i];
			}
		}


	}
	cout << "CheapestTile:" << "[" << mostEfficientTile.x << "/" << mostEfficientTile.y << "]" << mostEfficientTile.connectedTiles.size() << endl;

	return mostEfficientTile;
}
