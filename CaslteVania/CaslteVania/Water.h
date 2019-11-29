#pragma once
#include "Weapon.h"
class CWater : public CWeapon
{
public:
	CWater(int id )
	{
		AddAnimation(702, WATER);
		CurAnimation = animations[WATER];
		width = 14;
		height = 12;
		tag = ENEMY;
		type = WATER;
		switch (id)
		{
		case 1:
			vx = 0.03;
			vy = -0.05;
			break;
		case 2:
			vx = 0.005;
			vy = -0.07;
			break;

		case 3:
			vx = -0.03;
			vy = -0.05;
			break;
		default:
			break;
		}

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
		vy += 0.003;
		CGameObject::Update(dt);
		x += dx;
		y += dy;
		if (y > CAMERA->y + CAMERA->mHeight- 200)
			isDead = true;
	}
	~CWater() {};
};
