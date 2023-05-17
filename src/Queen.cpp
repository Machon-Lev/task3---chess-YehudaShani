#pragma once
#include "Queen.h"

bool Queen::validMove(Board board, Location& source, Location& dest)
{
	/*
	* The queen can move like a bishop or a rook.
	* If the move is valid for either of them, it is valid for the queen.
	*/
	Bishop bishop = Bishop(isWhite());
	Rook rook = Rook(isWhite());

	return bishop.validMove(board, source, dest) || rook.validMove(board, source, dest); 
}
