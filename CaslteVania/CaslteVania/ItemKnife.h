#pragma once
#include "Item.h"
class CItemKnife : public CItem
{
public:
	CItemKnife() :CItem()
	{
		AddAnimation(803, KNIFE);
		CurAnimation = animations[KNIFE];
		isDead = false;
		type = KNIFE;
		width = 32;
		height = 18;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};