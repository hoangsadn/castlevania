#pragma once
#include "Item.h"
class CItemHollyWater : public CItem
{
public:
	CItemHollyWater() :CItem()
	{
		AddAnimation(808, HOLLY_WATER);
		CurAnimation = animations[HOLLY_WATER];
		isDead = false;
		type = HOLLY_WATER;
		width = 32;
		height = 26;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	
};
