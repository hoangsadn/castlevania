#pragma once
#include "Item.h"
#define WIDTH_ITEM_MONEY_WHITE  30
#define HEIGHT_ITEM_MONEY_WHITE 30
class CItemMoneyWhite : public CItem
{
public:
	CItemMoneyWhite() :CItem()
	{
		AddAnimation(813, MONEY_WHITE);
		CurAnimation = animations[MONEY_WHITE];
		isDead = false;
		type = MONEY_WHITE;
		width = WIDTH_ITEM_MONEY_WHITE;
		height = HEIGHT_ITEM_MONEY_WHITE;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
