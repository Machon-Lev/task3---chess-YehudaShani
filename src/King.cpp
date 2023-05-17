#include "King.h"
#include <cmath>

bool King::validMove(Board board, Location& source, Location& dest)
{
	if (source.getRow() == dest.getRow() && source.getCol() == dest.getCol())
		return false;
	if (abs(source.getRow() - dest.getRow()) <= 1 && abs(source.getCol() - dest.getCol()) <= 1)
		return true;
	return false;
}

