#include "stdafx.h"
#include "Knight.h"
#include <vector>
#include "Board.h"
#include "Windows.h"

Knight::Knight(Tile startingTile)
{
	//Assign the knight to a tile that was given from input
	currentTile = startingTile;






}


Knight::~Knight()
{
	//Fallback method
}

void Knight::Move(Board board)
{
	board.DisplayBoard();
	//Sleep(500);
	if (checkIfWon(board.tileMap) == false) {
		//Check based on current tile where to go next
		Tile toMoveTo = Check(currentTile.connectedTiles, board.tileMap);



		//Assign the knight to a tile that was given from input
		currentTile = toMoveTo;

		//Has been stepped on by the knight
		board.tileMap[currentTile.x][currentTile.y].Use();

		Move(board);
	}
	else {
		cout << "The knight has moved to all tiles once." << endl;
	}
}

Tile Knight::Check(vector<Tile> connectedTiles, vector<vector<Tile>> tileMap)
{


	cout << "Currenttile:" << "[" << currentTile.x << "/" << currentTile.y << "]" << endl;


	Tile winningCandidate;
	int winningCandidateSize = 9; //8 is the highest, and so the worst, putting it to 9 makes it so that all candidates will win.
	int candidateSize = 0;
	for (size_t x = 0; x < connectedTiles.size(); x++)
	{
		cout << "Current Candidate:" << "[" << tileMap[connectedTiles[x].x][connectedTiles[x].y].x << "/" << tileMap[connectedTiles[x].x][connectedTiles[x].y].y << "] " << tileMap[connectedTiles[x].x][connectedTiles[x].y].connectedTiles.size() << " [" << tileMap[connectedTiles[x].x][connectedTiles[x].y].hasBeenUsed << "]" << endl;
		
		if (tileMap[connectedTiles[x].x][connectedTiles[x].y].hasBeenUsed != true) {
			
			
			for (size_t i = 0; i < connectedTiles[x].connectedTiles.size(); i++)
			{
				if (tileMap[connectedTiles[x].x][connectedTiles[x].y].hasBeenUsed != true) {
					candidateSize++;
				}
			}



			if (winningCandidateSize > candidateSize) {
				winningCandidate = tileMap[connectedTiles[x].x][connectedTiles[x].y];
				winningCandidateSize = candidateSize;
				
			}
			//Reset candidate size
			candidateSize = 0;
			
		}
	}
	

	/*
	We want to return the cheapest tile from connectedTiles.size

	For each tile in connectedTiles, we need to check for:

	1. Has it been used? -> Yes?-Ignore,No?-Continue
	2. If it has not been used check for all connections of the connection whether they have been used or not.
	3. Create a new size with 0
	4. Have they been used? Yes?-Don't add them to the new size,No?-Add 1 to the size of the candidate tile
	5. All connections of the connection checked-> Is there an existing winning candidate?
	6. No?-Step 8, Yes?-Step 7
	7. Compare the winning candidates size > current candidate size
	8. Assign the winning candidate to the current candidate and assign new winning candidate size

	*/


 
	if (winningCandidateSize != 9) {
		cout << "Winner:" << "[" << tileMap[winningCandidate.x][winningCandidate.y].x << "/" << tileMap[winningCandidate.x][winningCandidate.y].y << "] " << tileMap[winningCandidate.x][winningCandidate.y].connectedTiles.size() << " [" << tileMap[winningCandidate.x][winningCandidate.y].hasBeenUsed << "]" << endl;
	}
	cout << endl;
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
