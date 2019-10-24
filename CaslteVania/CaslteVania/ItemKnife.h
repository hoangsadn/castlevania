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
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 32;
		bottom = top + 18;
	}
};