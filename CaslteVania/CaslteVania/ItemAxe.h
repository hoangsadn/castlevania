#pragma once
#include "Item.h"
class CItemAxe : public CItem
{
public:
	CItemAxe() :CItem()
	{
		AddAnimation(806, AXE);
		CurAnimation = animations[AXE];
		isDead = false;
		type = AXE;
		width = 30;
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
