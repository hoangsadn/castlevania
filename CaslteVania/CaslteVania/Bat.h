#pragma once
#include "Enemy.h"
#define TIME_REPAWN_BAT 5000
#define BAT_WIDTH  34
#define BAT_HEIGHT 32
class CBat : public CEnemy
{
public:
	CBat() : CEnemy()
	{
		type = BAT;
		AddAnimation(909, BAT_LEFT);
		AddAnimation(910, BAT_RIGHT);
		timeDelay = TIME_REPAWN_BAT;
		nx = -1;
		CurAnimation = nx > 0 ? animations[BAT_RIGHT] : animations[BAT_LEFT];
		width = BAT_WIDTH;
		height = BAT_HEIGHT;
	}
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		//Bat doesnt touch the wall 
	}

	void UpdatePosition(float dt)
	{
		
		if (!isBuring || !ishitting || !isDead )
		{
			CurAnimation = nx > 0 ? animations[BAT_RIGHT] : animations[BAT_LEFT];
			vx = nx > 0 ? 0.1f : -0.1f;
			x += vx * dt;
			y += 1.2 * sin(x*0.03f);
		}
	}

	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}

};