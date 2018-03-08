#include "stdafx.h"
#include "Knight.h"
#include <vector>
#include "Board.h"
#include "Windows.h"

Knight::Knight()
{

}


Knight::~Knight()
{
	//Destructor
}

bool Knight::Move(Board board, Tile currentTile)
{
	Sleep(50);
	//Check if Knight has finished its tour (or not)



	Tile toMoveTo = Check(board.tileMap[currentTile.x][currentTile.y].connectedTiles, board.tileMap);

	//Has been stepped on by the knight
	board.tileMap[currentTile.x][currentTile.y].Use();
	//Update display
	board.DisplayBoard();

	if (checkIfWon(board.tileMap) == true) {
		return true;
	}
	//system("PAUSE");
		for (size_t i = 0; i < toMoveTo.connectedTiles.size(); i++)
		{
			if (Move(board, toMoveTo) == true)
			{
				return true;
			}
			else {

			}


		}
		board.tileMap[currentTile.x][currentTile.y].UnUse();
		return false;
}

Tile Knight::Check(vector<Tile> connectedTiles, vector<vector<Tile>> tileMap)
{

	Tile winningCandidate;

	int winningCandidateSize = 9; //8 is the highest, and so the worst, putting it to 9 makes it so that all candidates will win.
	int candidateSize = 0;
	//Get the winning tile
	for (size_t x = 0; x < connectedTiles.size(); x++)
	{

		if (tileMap[connectedTiles[x].x][connectedTiles[x].y].hasBeenUsed != true) {

			for (size_t i = 0; i < tileMap[connectedTiles[x].x][connectedTiles[x].y].connectedTiles.size(); i++)
			{
				if (tileMap[connectedTiles[x].x][connectedTiles[x].y].hasBeenUsed != true) {
					candidateSize++;

				}
			}



			if (winningCandidateSize > candidateSize) {
				winningCandidate = tileMap[connectedTiles[x].x][connectedTiles[x].y];
				winningCandidateSize = candidateSize;

			}


			cout << "Possible winner:" << "[" << tileMap[connectedTiles[x].x][connectedTiles[x].y].x << "/" << tileMap[connectedTiles[x].x][connectedTiles[x].y].y << "]" << candidateSize << endl;
		}
		candidateSize = 0;
	}


	cout << "Candidate:" << "[" << winningCandidate.x << "/" << winningCandidate.y << "]" << winningCandidateSize << endl;


	return winningCandidate;
}

bool Knight::checkIfWon(vector<vector<Tile>> tileMap)
{
	for (size_t x = 0; x < tileMap.size(); x++)
	{
		for (size_t y = 0; y < tileMap[0].size(); y++)
		{
			if (tileMap[x][y].hasBeenUsed == false) {
				return false;
			}
		}
	}
	return true;
}
