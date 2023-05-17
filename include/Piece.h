#pragma once

class Board;
class Location;

class Piece {

	bool _isWhite;

public:
	Piece(bool isWhite) { _isWhite = isWhite; };
	virtual bool validMove(Board board, Location& source, Location& dest) = 0;
	bool isWhite() { return _isWhite; };

};