#pragma once
#include "Weapon.h"
#define AXE_HEIGHT 28
#define AXE_WIDTH 30
class CAxe : public CWeapon
{
public:
	CAxe()
	{
		allowHit = true;
		AddAnimation(807, AXE_THORW);
		CurAnimation = animations[AXE_THORW];
		width = AXE_WIDTH;
		height = AXE_HEIGHT;
		vx = player->nx > 0? vx = 0.14 : vx = -0.14;
		vy = -0.38;
		x = player->x;
		y = player->y;
		type = AXE;
	}
	void GetBoundingBox(float &l, float &t, float &r, float &b)
	{
		l = x;
		t = y;
		r = l + width;
		b = t + height;
	}
	virtual void UpdatePosititon(DWORD dt)
	{
		if (x < CAMERA->x || x > CAMERA->x + CAMERA->mWidth || y > CAMERA->y+CAMERA->mHeight)
		{
			isDead = true;
			//GAMELOG("OK");
		}
		vy += 0.01;
		x += vx * dt;
		y += vy * dt;
		
	}
	~CAxe() {};
};