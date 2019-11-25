#pragma once
#include "Holder.h"

class CHolderCandle : public CHolder
{
public:
	CHolderCandle(TYPE stored)
	{
		AddAnimation(302, CANDLE);
		AddAnimation(306, CONNER_WALL);
		CurAnimation = animations[CANDLE];
		
		this->stored = stored;
		type = CANDLE;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 16;
		bottom = top + 32;
	}
};