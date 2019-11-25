#pragma once
#include "Item.h"
class CItemWhip : public CItem
{
public:
	CItemWhip() :CItem()
	{
		AddAnimation(801, MORNING_STAR);
		CurAnimation = animations[MORNING_STAR];
		isDead = false;
		type = MORNING_STAR;
		width = 32;
		height = 32;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};