#pragma once
#include "Item.h"
class CItemBigHeart : public CItem
{
public:
	CItemBigHeart() :CItem()
	{
		AddAnimation(802, BIG_HEART);
		CurAnimation = animations[BIG_HEART];
		isDead = false;
		type = BIG_HEART;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 24;
		bottom = top + 20;
	}
};
