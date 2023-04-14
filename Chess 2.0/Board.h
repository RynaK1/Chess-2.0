#pragma once

#include <iostream>
#include <vector>
#include <string>

class Board {
private:
	std::vector<std::vector<std::string>> board;
	int x;
	int y;
public:
	Board(int x, int y);
	void printBoard();
};


Board::Board(int x, int y) {
	this->x = x; 
	this->y = y; 
	board.reserve(x);
	fill(board.begin(), board.end(), vector<string>(y, " "));
}

void Board::printBoard() {
	for (int i = 0; i < x; i++) {
		cout << "| ";
		for (int j = 0; j < y; j++) {
			cout << board[i][j] << " |";
		}
		cout << endl << "---------------------------------" << endl;
	}
}