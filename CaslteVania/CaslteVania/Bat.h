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
		CurAnimation = animations[BAT_RIGHT];
	}
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		//Bat doesnt touch the wall 
	}

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		x += 0.1f*dt;
		y += 1.2 * sin(x*0.03f) ;

	}

	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 32;
		bottom = top + 32;
	}

};