#pragma once
#include "Item.h"
class CItemDoubleShot : public CItem
{
public:
	CItemDoubleShot() :CItem()
	{
		AddAnimation(815, DOUBLE_SHOT);
		CurAnimation = animations[DOUBLE_SHOT];
		isDead = false;
		type = DOUBLE_SHOT;
		width = 28;
		height = 28;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
