#pragma once
#include "Holder.h"

class CHolderFirePillar : public CHolder
{
public:
	CHolderFirePillar(TYPE stored)
	{
		AddAnimation(301, FIRE_PILLAR);
		CurAnimation = animations[FIRE_PILLAR];
		this->stored = stored;
		type = FIRE_PILLAR;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};