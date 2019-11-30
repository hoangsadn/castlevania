#pragma once
#include "Item.h"
#define WIDTH_ITEM_ROSARY  32
#define HEIGHT_ITEM_ROSARY 32
class CItemRosary : public CItem
{
public:
	CItemRosary() :CItem()
	{
		AddAnimation(817, ROSARY);
		CurAnimation = animations[ROSARY];
		isDead = false;
		type = ROSARY;
		width = WIDTH_ITEM_ROSARY;
		height = HEIGHT_ITEM_ROSARY;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
