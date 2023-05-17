#pragma once
#include "Piece.h"
#include "Board.h"
class Board;
class Piece;
class Location;

class Queen : public Piece {
public:
	Queen(bool isWhite) : Piece(isWhite) {};
	bool validMove(Board board, Location& source, Location& dest) override;

};