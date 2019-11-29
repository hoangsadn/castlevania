#pragma once
#include "Item.h"
class CItemRoast : public CItem
{
public:
	CItemRoast() :CItem()
	{
		AddAnimation(818, ROAST);
		CurAnimation = animations[ROAST];
		isDead = false;
		type = ROAST;
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
