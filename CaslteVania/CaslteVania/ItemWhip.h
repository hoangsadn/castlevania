#pragma once
#include "Item.h"
#define WIDTH_ITEM_MORNING_STAR  32
#define HEIGHT_ITEM_MORNING_STAR 32
class CItemWhip : public CItem
{
public:
	CItemWhip() :CItem()
	{
		AddAnimation(801, MORNING_STAR);
		CurAnimation = animations[MORNING_STAR];
		isDead = false;
		type = MORNING_STAR;
		width = WIDTH_ITEM_MORNING_STAR;
		height = HEIGHT_ITEM_MORNING_STAR;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};