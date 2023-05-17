#include "Location.h"

Location::Location(int row, int col)
{
	_row = row;
	_col = col;
}
Location Location::operator=(Location loc)
{
	return Location(loc.getRow(), loc.getCol());
}
int Location::getRow()
{
	return _row;
}

int Location::getCol()
{
	return _col;
}

void Location::setRow(int row)
{
	_row = row;
}

void Location::setCol(int col)
{
	_col = col;
}