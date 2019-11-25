#pragma once
#include "Item.h"
class CItemStopWatch : public CItem
{
public:
	CItemStopWatch() :CItem()
	{
		AddAnimation(816, STOP_WATCH);
		CurAnimation = animations[STOP_WATCH];
		isDead = false;
		type = STOP_WATCH;
		width = 30;
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
