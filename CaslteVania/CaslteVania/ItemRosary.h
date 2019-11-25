#pragma once
#include "Item.h"
class CItemRosary : public CItem
{
public:
	CItemRosary() :CItem()
	{
		AddAnimation(817, ROSARY);
		CurAnimation = animations[ROSARY];
		isDead = false;
		type = ROSARY;
		width = 32;
		height = 32;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
