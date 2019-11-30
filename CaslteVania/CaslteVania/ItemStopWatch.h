#pragma once
#include "Item.h"
#define WIDTH_ITEM_STOP_WATCH  30
#define HEIGHT_ITEM_STOP_WATCH 32
class CItemStopWatch : public CItem
{
public:
	CItemStopWatch() :CItem()
	{
		AddAnimation(816, STOP_WATCH);
		CurAnimation = animations[STOP_WATCH];
		isDead = false;
		type = STOP_WATCH;
		width = WIDTH_ITEM_STOP_WATCH;
		height = HEIGHT_ITEM_STOP_WATCH;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
};
