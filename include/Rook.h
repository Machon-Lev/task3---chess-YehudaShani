#pragma once
#include "Piece.h"
#include "Board.h"

class Board;
class Piece;
class Location;


class Rook : public Piece {
public:
	Rook (bool isWhite) : Piece(isWhite) {};
	bool validMove(Board board, Location& source, Location& dest) override;
};