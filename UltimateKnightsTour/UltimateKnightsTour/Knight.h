#pragma once
#include "Tile.h"
#include <iostream>
#include "Board.h"
using namespace std;
class Knight
{
public:

	Tile currentTile;
	Knight(Tile startingTile);
	~Knight();
	void Move(Board board);
	Tile Check(vector<Tile> connectedTiles, vector<vector<Tile>> tileMap);
	bool checkIfWon(vector<vector<Tile>> tileMap);
	std::vector<Tile> path;
};

