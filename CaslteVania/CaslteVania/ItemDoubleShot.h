#pragma once
#include "Item.h"
#define WIDTH_ITEM_DOUBLE_SHOT  28
#define HEIGHT_ITEM_DOUBLE_SHOT 28
class CItemDoubleShot : public CItem
{
public:
	CItemDoubleShot() :CItem()
	{
		AddAnimation(815, DOUBLE_SHOT);
		CurAnimation = animations[DOUBLE_SHOT];
		isDead = false;
		type = DOUBLE_SHOT;
		width = WIDTH_ITEM_DOUBLE_SHOT;
		height = HEIGHT_ITEM_DOUBLE_SHOT;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
