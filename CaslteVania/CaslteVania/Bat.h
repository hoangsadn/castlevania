#pragma once
#include "Enemy.h"
class CBat : public CEnemy
{
public:
	CBat() : CEnemy()
	{
		type = BAT;
		AddAnimation(909, BAT_LEFT);
		AddAnimation(910, BAT_RIGHT);
		timeDelay = 5000;
		nx = -1;
		vx = nx > 0 ? 0.1f : -0.1f;

		CurAnimation = nx > 0 ? animations[BAT_RIGHT] : animations[BAT_LEFT];
		width = 34;
		height = 32;
	}
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		//Bat doesnt touch the wall 
	}

	void UpdatePosition(float dt)
	{
		x += vx*dt;
		y += 1.2 * sin(x*0.03f) ;

	}

	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}

};