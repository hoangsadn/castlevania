#pragma once
#include "Item.h"
#define WIDTH_ITEM_MONEY_BLUE  30
#define HEIGHT_ITEM_MONEY_BLUE 30
class CItemMoneyBlue: public CItem
{
public:
	CItemMoneyBlue() :CItem()
	{
		AddAnimation(811, MONEY_BLUE);
		CurAnimation = animations[MONEY_BLUE];
		isDead = false;
		type = MONEY_BLUE;
		width = WIDTH_ITEM_MONEY_BLUE;
		height = HEIGHT_ITEM_MONEY_BLUE;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
