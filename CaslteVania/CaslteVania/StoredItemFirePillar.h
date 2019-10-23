#pragma once
#include "StoredItem.h"

class CStoredItemFirePillar : public CStoredItem
{
public:
	CStoredItemFirePillar(TYPE stored)
	{
		AddAnimation(301, FIRE_PILLAR);
		CurAnimation = animations[FIRE_PILLAR];
		isDead = false;
		this->stored = stored;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 32;
		bottom = top + 64;
	}
};