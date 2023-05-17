#pragma once
#include <string>
#include "Location.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"

using namespace std;

class Piece;
class Rook;
class Queen;
class King;
class Bishop;
class Location;

class Board {

	bool whiteTurn = true;
	Piece* board[8][8];

public:
	Board(string gameState);
	int movePiece(string move);
	bool causesSelfCheckmate(Location& source, Location& dest); //helper function
	bool causesOponentCheck();
	bool threatensKing();
	void applyMove(Location& source, Location& dest);
	Piece*& operator[](Location loc) { return board[loc.getRow()][loc.getCol()]; };
	int getRow(string move) { return move[1] - 'a'; };
	int getCol(string move) { return move[0] - '1'; };
};