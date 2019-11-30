#pragma once
#include "Item.h"
#define WIDTH_ITEM_ROAST 32
#define HEIGHT_ITEM_ROAST 26
class CItemRoast : public CItem
{
public:
	CItemRoast() :CItem()
	{
		AddAnimation(818, ROAST);
		CurAnimation = animations[ROAST];
		isDead = false;
		type = ROAST;
		width = WIDTH_ITEM_ROAST;
		height = HEIGHT_ITEM_ROAST;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
