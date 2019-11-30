#pragma once
#include "Item.h"
#define WIDTH_ITEM_BIG_HEART  24
#define HEIGHT_ITEM_BIG_HEART 20
class CItemBigHeart : public CItem
{
public:
	CItemBigHeart() :CItem()
	{
		AddAnimation(802, BIG_HEART);
		CurAnimation = animations[BIG_HEART];
		isDead = false;
		type = BIG_HEART;
		width = WIDTH_ITEM_BIG_HEART;
		height = HEIGHT_ITEM_BIG_HEART;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
