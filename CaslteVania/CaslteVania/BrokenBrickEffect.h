#pragma once
#include "Weapon.h"
class CBrokenBrickEffect: public CWeapon
{
public:
	int posRespawnX, posRepawnY;
	CBrokenBrickEffect(int id)
	{
		AddAnimation(703, HIDDEN_BRICK_BROKE);
		CurAnimation = animations[HIDDEN_BRICK_BROKE];
		width = 32;
		height = 32;
		type = HIDDEN_BRICK_BROKE;
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
			vy = -0.04;
			break;
		case 4 :
			vx = -0.03;
			vy = -0.06;
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
		if ( y > posRepawnY + 120)
			isDead = true;
	}
	~CBrokenBrickEffect() {};
};
