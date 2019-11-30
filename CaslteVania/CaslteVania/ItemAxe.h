#pragma once
#include "Item.h"
#define WIDTH_ITEM_AXE  30
#define HEIGHT_ITEM_AXE 28
class CItemAxe : public CItem
{
public:
	CItemAxe() :CItem()
	{
		AddAnimation(806, AXE);
		CurAnimation = animations[AXE];
		isDead = false;
		type = AXE;
		width = WIDTH_ITEM_AXE;
		height = HEIGHT_ITEM_AXE;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
