#pragma once
#include "Item.h"
class CItemMoneyWhite : public CItem
{
public:
	CItemMoneyWhite() :CItem()
	{
		AddAnimation(813, MONEY_WHITE);
		CurAnimation = animations[MONEY_WHITE];
		isDead = false;
		type = MONEY_WHITE;
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
