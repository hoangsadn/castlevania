#pragma once
#include "Item.h"
class CItemInvincibility : public CItem
{
public:
	CItemInvincibility() :CItem()
	{
		AddAnimation(814, INVINCIBILITY);
		CurAnimation = animations[INVINCIBILITY];
		isDead = false;
		type = INVINCIBILITY;
		width = 33;
		height = 40;

	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};

