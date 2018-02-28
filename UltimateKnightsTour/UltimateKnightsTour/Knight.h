#pragma once
#include "Tile.h"
#include <iostream>

using namespace std;
class Knight
{
public:

	Tile currentTile;
	Knight(Tile startingTile);
	~Knight();
	void Move();
	Tile Check(vector<Tile> connectedTiles);
};

