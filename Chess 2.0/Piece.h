#pragma once

#include <string>

class Piece {
private:
	std::string name;
public:
	virtual void move() = 0;
};