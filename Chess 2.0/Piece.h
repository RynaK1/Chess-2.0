#pragma once

struct Piece {
	bool skip;
	bool indef;
	bool multiDir;
	int x;
	int y;

	Piece(bool skip, bool indef, bool multiDir, int x, int y);
};

Piece::Piece(bool skip, bool indef, bool multiDir, int x, int y) {
	this->skip = skip;
	this->indef = indef;
	this->multiDir = multiDir;
	this->x = x;
	this->y = y;
}