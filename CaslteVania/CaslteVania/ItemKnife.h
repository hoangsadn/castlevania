#pragma once
#include "Item.h"
#define WIDTH_ITEM_KNIFE  32
#define HEIGHT_ITEM_KNIFE 18
class CItemKnife : public CItem
{
public:
	CItemKnife() :CItem()
	{
		AddAnimation(803, KNIFE);
		CurAnimation = animations[KNIFE];
		isDead = false;
		type = KNIFE;
		width = WIDTH_ITEM_KNIFE;
		height = HEIGHT_ITEM_KNIFE;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};