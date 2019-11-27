#pragma once
#include "Enemy.h"
class CGhost : public CEnemy
{
public:
	CGhost() : CEnemy()
	{
		type = GHOST;
		AddAnimation(901, GHOST_LEFT);
		AddAnimation(902, GHOST_RIGHT);
		CurAnimation = animations[GHOST_LEFT];
		vy = 0.0f;
		vx = -SIMON_WALKING_SPEED;
		width = 34;
		height = 64;
	}
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	
};