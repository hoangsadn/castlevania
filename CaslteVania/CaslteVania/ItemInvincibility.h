#pragma once
#include "Item.h"
#define WIDTH_ITEM_INVINCIBILITY  33
#define HEIGHT_ITEM_INVINCIBILITY 40
class CItemInvincibility : public CItem
{
public:
	CItemInvincibility() :CItem()
	{
		AddAnimation(814, INVINCIBILITY);
		CurAnimation = animations[INVINCIBILITY];
		isDead = false;
		type = INVINCIBILITY;
		width = WIDTH_ITEM_INVINCIBILITY;
		height = HEIGHT_ITEM_INVINCIBILITY;

	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};

