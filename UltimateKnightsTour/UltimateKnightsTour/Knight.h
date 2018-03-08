#pragma once
#include "Tile.h"
#include <iostream>
#include "Board.h"
using namespace std;
class Knight
{
public:

	Knight();
	~Knight();
	bool Move(Board board, Tile currentTile);
	Tile Check(vector<Tile> connectedTiles, vector<vector<Tile>> tileMap);
	bool checkIfWon(vector<vector<Tile>> tileMap);
};

