#pragma once
#include "Item.h"
class CItemMoneyBlue: public CItem
{
public:
	CItemMoneyBlue() :CItem()
	{
		AddAnimation(811, MONEY_BLUE);
		CurAnimation = animations[MONEY_BLUE];
		isDead = false;
		type = MONEY_BLUE;
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
