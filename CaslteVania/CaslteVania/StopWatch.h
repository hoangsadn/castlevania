#pragma once
#include "Weapon.h"
class CStopWatch : public CWeapon
{
public:
	DWORD timeDead;
	CStopWatch()
	{
		allowHit = true;
		type = STOP_WATCH;
		timeDead = GetTickCount();
		player->freeze = true;
		x = player->x;
		y = player->y;
		width = 1;
		height = 1;

	}
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL) 
	{ 
		if (GetTickCount() - timeDead > 3000)
		{
			isDead = true;
			player->freeze = false;
		}
	};
	void GetBoundingBox(float &l, float &t, float &r, float &b)
	{
		l = x;
		t = y;
		r = l + width;
		b = t + height;
	}
	
	~CStopWatch() {};
};