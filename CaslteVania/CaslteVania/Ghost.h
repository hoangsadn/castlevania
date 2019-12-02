#pragma once
#include "Enemy.h"
#define TIME_REPAWN_GHOST 5000
#define GHOST_WIDTH  34
#define GHOST_HEIGHT 64
#define GHOST_WALKING_SPEED 0.05
class CGhost : public CEnemy
{
public:
	

	CGhost() : CEnemy()
	{
		type = GHOST;
		AddAnimation(901, GHOST_LEFT);
		AddAnimation(902, GHOST_RIGHT);
		CurAnimation = animations[GHOST_LEFT];
		timeDelay = TIME_REPAWN_GHOST;
		vy = 0.0f;
		vx = -GHOST_WALKING_SPEED;
		width = GHOST_WIDTH;
		height = GHOST_HEIGHT;
	}
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	
};