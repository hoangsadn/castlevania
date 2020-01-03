#pragma once
#include "Weapon.h"
#define FIRE_BALL_WIDTH  14
#define FIRE_BALL_HEIGHT 12
class CFireBall : public CWeapon
{
public:
	bool ishitting;
	CFireBall(int nx) 
	{
		AddAnimation(917, FIRE_BALL_LEFT);
		AddAnimation(918, FIRE_BALL_RIGHT);
		CurAnimation = nx > 0 ? animations[FIRE_BALL_RIGHT] : animations[FIRE_BALL_LEFT];
		vx = nx > 0 ? 0.02 : -0.02;
		width = FIRE_BALL_WIDTH;
		height = FIRE_BALL_HEIGHT;
		ishitting = false;
		isBuring = false;
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
		
		if (isBuring)
		{
			LPANIMATION ani = new CAnimation(50);
			ani->Add(50001);
			ani->Add(50002);
			ani->Add(50003);
			CurAnimation = ani;
			isBuring = false;
			ishitting = true;
			vy = 0;
			vx = 0;
		}
		if (ishitting && CurAnimation->isLastFrame)
		{
			CurAnimation->isLastFrame = false;
			CurAnimation->currentFrame = -1;
			isDead = true;
			ishitting = false;

		}
		CGameObject::Update(dt);
		x += dx;
		y += dy;
	}
	~CFireBall() {};
};
