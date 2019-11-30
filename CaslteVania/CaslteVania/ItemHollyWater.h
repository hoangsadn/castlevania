#pragma once
#include "Item.h"
#define WIDTH_ITEM_HOLLY_WATER  32
#define HEIGHT_ITEM_HOLLY_WATER 26
class CItemHollyWater : public CItem
{
public:
	CItemHollyWater() :CItem()
	{
		AddAnimation(808, HOLLY_WATER);
		CurAnimation = animations[HOLLY_WATER];
		isDead = false;
		type = HOLLY_WATER;
		width = WIDTH_ITEM_HOLLY_WATER;
		height = HEIGHT_ITEM_HOLLY_WATER;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	
};
