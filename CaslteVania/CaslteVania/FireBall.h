#pragma once
#include "Weapon.h"
#define FIRE_BALL_WIDTH  14
#define FIRE_BALL_HEIGHT 12
class CFireBall : public CWeapon
{
public:
	CFireBall(int nx) 
	{
		AddAnimation(917, FIRE_BALL_LEFT);
		AddAnimation(918, FIRE_BALL_RIGHT);
		CurAnimation = nx > 0 ? animations[FIRE_BALL_RIGHT] : animations[FIRE_BALL_LEFT];
		vx = nx > 0 ? 0.02 : -0.02;
		width = FIRE_BALL_WIDTH;
		height = FIRE_BALL_HEIGHT;
		tag = ENEMY;
		type = FIRE_BALL;
	}
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b) 
	{
		l = x;
		t = y;
		r = l + width;
		b = t + height;
	}
	void UpdatePosititon(DWORD dt)
	{
		CGameObject::Update(dt);
		x += dx;
		y += dy;
	}
	~CFireBall() {};
};
