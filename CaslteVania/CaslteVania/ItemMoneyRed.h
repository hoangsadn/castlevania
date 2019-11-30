#pragma once
#include "Item.h"
#define WIDTH_ITEM_MONEY_RED  30
#define HEIGHT_ITEM_MONEY_RED 30
class CItemMoneyRed : public CItem
{
public:
	CItemMoneyRed() :CItem()
	{
		AddAnimation(812, MONEY_RED);
		CurAnimation = animations[MONEY_RED];
		isDead = false;
		type = MONEY_RED;
		width = WIDTH_ITEM_MONEY_RED;
		height = HEIGHT_ITEM_MONEY_RED;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
