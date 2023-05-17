#pragma once
#include "Bishop.h"

bool Bishop::validMove(Board board, Location& source, Location& dest)
{
	Location temp = source;
	bool goingDown;
	bool goingRight;
	int sourceRow = source.getRow();
	int sourceCol = source.getCol();
	int destRow = dest.getRow();
	int destCol = dest.getCol();

	if (sourceRow == destRow || sourceCol == destCol)
		return false;

	if (destRow > sourceRow)
		goingDown = true;
	else
		goingDown = false;
	if (destCol > sourceCol)
		goingRight = true;
	else
		goingRight = false;

	while (temp.getRow() != destRow) {
		if (goingDown)
			temp.setRow(temp.getRow() + 1);
		else
			temp.setRow(temp.getRow() - 1);

		if (goingRight)
			temp.setCol(temp.getCol() + 1);
		else
			temp.setCol(temp.getCol() - 1);

		if(temp.getRow() == destRow && temp.getCol() == destCol)
			return true;

		if (temp.getCol() < 0 || temp.getCol() > 7 || temp.getRow() < 0 || temp.getRow() > 7)
			return false;

		if (board[temp] != nullptr)
			return false;
	}

	return false;
}
