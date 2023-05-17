#pragma once
#include "Board.h"
#include <typeinfo>


Board::Board(string gameState)
{
	int i = 0;
	int j = 0;
	for (int k = 0; k < 64; k++)
	{
		if (gameState[k] == '#')
			board[i][j] = nullptr;

		else {
			switch(gameState[k])
			{ 
				case 'R':
					board[i][j] = new Rook(true);
					break;
				case 'K':
					board[i][j] = new King(true);
					break;
				case 'B':
					board[i][j] = new Bishop(true);
					break;
				case 'Q':
					board[i][j] = new Queen(true);
					break;
					
				case 'r':
					board[i][j] = new Rook(false);
					break;
				case 'k':
					board[i][j] = new King(false);
					break;
				case 'b':
					board[i][j] = new Bishop(false);
					break;
				case 'q':
					board[i][j] = new Queen(false);
					break;
			}
		}
		j++;
		if (j == 8) {
			j = 0;
			i++;
		}
	}
}

int Board::movePiece(string move)
{
	int sourceX = move[0] - 'a';
	int sourceY = move[1] - '1';
	int destX = move[2] - 'a';
	int destY = move[3] - '1';
	Location source(sourceX, sourceY);
	Location dest(destX, destY);

	if (board[sourceX][sourceY] == nullptr) // no piece in source
	{
		return 11;
	}
	if (board[sourceX][sourceY]->isWhite() != whiteTurn) // wrong turn
	{
		return 12;
	}
	if (board[destX][destY] != nullptr && board[destX][destY]->isWhite() == whiteTurn) // dest is same color
	{
		return 13;
	}
	if (!board[sourceX][sourceY]->validMove(*this, source, dest)) // invalid move
	{
		return 21;
	}
	if (causesSelfCheckmate(source, dest)) // causes self checkmate
	{
		return 31;
	}
	applyMove(source, dest);
	if (causesOponentCheck())
		return 41;

	return 42;
}

bool Board::causesSelfCheckmate(Location& source, Location& dest)
{
	//save pieces at source and dest
	Piece* sourcePiece = (*this)[source];
	Piece* destPiece = (*this)[dest];

	//apply move
	applyMove(source, dest);

	//check if causes checkmate
	bool checkmate = threatensKing();

	//undo move
	(*this)[source] = sourcePiece;
	(*this)[dest] = destPiece;
	whiteTurn = !whiteTurn;

	return checkmate;
}

bool Board::causesOponentCheck()
{
	whiteTurn = !whiteTurn;
	bool isCheck = threatensKing();
	whiteTurn = !whiteTurn;
	return isCheck;
}

void Board::applyMove(Location& source, Location& dest) {
	whiteTurn = !whiteTurn;
	board[dest.getRow()][dest.getCol()] = board[source.getRow()][source.getCol()];
	board[source.getRow()][source.getCol()] = nullptr;
}

bool Board::threatensKing() {
	Location kingLoc(0,0);
	Location temp(0, 0);
	Piece* currentPiece;
	for (int i = 0; i < 8; i++) // find king
	{
		for (int j = 0; j < 8; j++)
		{
			temp.setRow(i);
			temp.setCol(j);
			currentPiece = (*this)[temp];
			if (currentPiece != nullptr && currentPiece->isWhite() != whiteTurn && typeid(*currentPiece) == typeid(King))
			{
				kingLoc.setRow(i);
				kingLoc.setCol(j);
				break;
			}
			
		}
	}
	for (int i = 0; i < 8; i++) // check if any piece can move to king
	{
		for (int j = 0; j < 8; j++)
		{
			temp.setRow(i);
			temp.setCol(j);
			currentPiece = (*this)[temp];
			if (currentPiece != nullptr && currentPiece->isWhite() == whiteTurn && currentPiece->validMove(*this, temp, kingLoc))
			{
				return true;
			}

		}
	}
	return false;
}
