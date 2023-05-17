#pragma once
#include "Queen.h"

bool Queen::validMove(Board board, Location& source, Location& dest)
{
	Bishop bishop = Bishop(isWhite());
	Rook rook = Rook(isWhite());

	return bishop.validMove(board, source, dest) || rook.validMove(board, source, dest);
}
