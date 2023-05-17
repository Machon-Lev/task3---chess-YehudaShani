#pragma once
#include "Piece.h"
#include "Board.h"


class Board;
class Piece;
class Location;


class King : public Piece{
public:
	King(bool isWhite) : Piece(isWhite) {};
	bool validMove(Board board, Location& source, Location& dest) override;

};