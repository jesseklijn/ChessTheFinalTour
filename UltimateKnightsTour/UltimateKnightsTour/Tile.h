#pragma once
#include <vector> 
class Tile
{
public:
	Tile();
	~Tile();
	std::vector<Tile> connectedTiles;
	int x = -1, y = -1;
	bool hasBeenUsed = false;
	bool hasMark = false;
	void Use();
	void UnUse();
};

