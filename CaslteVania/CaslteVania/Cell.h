#pragma once
#include "GameObject.h"

class Cell
{
public:
	int posX, posY;
	std::unordered_set<LPGAMEOBJECT> objects;
	std::unordered_set<LPGAMEOBJECT> CannotTouchObjects;

	Cell(int x, int y) 
	{
		this->posX = x;
		this->posY = y;
	}
	~Cell() {};
};