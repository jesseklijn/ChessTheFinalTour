#pragma once
#include "Tile.h"

class Board
{
public:
	Board(int x, int y);
	~Board();
	void InitializeTileMap();
	void CreateConnections();
	bool CheckBounds(int xInc, int yInc, int x, int y);
	void DisplayBoard();
	
	int xSize, ySize;
	std::vector<std::vector<Tile>> tileMap;

};

