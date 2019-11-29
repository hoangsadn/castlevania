#pragma once
#include "Holder.h"

class CHolderHiddenBrick : public CHolder
{
public:
	CHolderHiddenBrick(TYPE stored)
	{
		AddAnimation(307, HIDDEN_BRICK);
		AddAnimation(308, HIDDEN_BRICK_SMALL);
		CurAnimation = animations[HIDDEN_BRICK];
		this->stored = stored;
		type = HIDDEN_BRICK;
		width = 32;
		height = 32;

	}
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};