#pragma once
#include "Rook.h"

bool Rook::validMove(Board board, Location& source, Location& dest)
{
	if (source.getRow() == dest.getRow()){
		if (source.getCol() < dest.getCol()) {
			for (int i = source.getCol() + 1; i < dest.getCol(); i++) {
				if (board[Location(source.getRow(), i)] != nullptr) {
					return 0;
				}
			}
			return 1;
		}
		else {
			for (int i = source.getCol() - 1; i > dest.getCol(); i--) {
				if (board[Location(source.getRow(), i)] != nullptr) {
					return 0;
				}
			}
			return 1;
		}
	}
	else if (source.getCol() == dest.getCol()){
		if (source.getRow() < dest.getRow()) {
			for (int i = source.getRow() + 1; i < dest.getRow(); i++) {
				if (board[Location(i, source.getCol())] != nullptr) {
					return 0;
				}
			}
			return 1;
		}
		else {
			for (int i = source.getRow() - 1; i > dest.getRow(); i--) {
				if (board[Location(i, source.getCol())] != nullptr) {
					return 0;
				}
			}
			return 1;
		}
	}
	return false;
}
