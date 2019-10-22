#pragma once
#include "StoredItem.h"

class CStoredItemFirePillar : public CStoredItem
{
public:
	CStoredItemFirePillar()
	{
		AddAnimation(30001, FIRE_PILLAR);
		CurAnimation = animations[FIRE_PILLAR];
		isDead = false;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 32;
		bottom = top + 64;
	}
};