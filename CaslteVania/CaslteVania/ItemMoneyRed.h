#pragma once
#include "Item.h"
class CItemMoneyRed : public CItem
{
public:
	CItemMoneyRed() :CItem()
	{
		AddAnimation(812, MONEY_RED);
		CurAnimation = animations[MONEY_RED];
		isDead = false;
		type = MONEY_RED;
		width = 30;
		height = 30;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
