#pragma once
#include <vector> 
class Tile
{
public:
	Tile();
	~Tile();
	std::vector<Tile> connectedTiles;
};

