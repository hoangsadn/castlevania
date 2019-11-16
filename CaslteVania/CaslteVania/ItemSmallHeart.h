#pragma once
#include "Item.h"
class CItemSmallHeart : public CItem
{
public:
	CItemSmallHeart() :CItem()
	{
		AddAnimation(805, SMALL_HEART);
		CurAnimation = animations[SMALL_HEART];
		isDead = false;
		type = SMALL_HEART;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		y += 0.4;
		x += 1.2*sin(y);
		
		if (GetTickCount() - timeDead > 4000)
			isDead = true;

		CollisonGroundWall(dt, coObjects);
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 16;
		bottom = top + 16;
	}
};
