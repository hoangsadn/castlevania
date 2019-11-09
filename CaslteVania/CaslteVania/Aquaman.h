#pragma once
#include "Enemy.h"
class CAquaman : public CEnemy
{
public:
	TYPE state;

	CAquaman() : CEnemy()
	{
		type = AQUAMAN;
		IsJumping = true;
		AddAnimation(911, AQUAMAN_STAND_LEFT);
		AddAnimation(912, AQUAMAN_STAND_RIGHT);
		AddAnimation(913, AQUAMAN_WALK_LEFT);
		AddAnimation(914, AQUAMAN_WALK_RIGHT);
		AddAnimation(915, AQUAMAN_FIRE_LEFT);
		AddAnimation(916, AQUAMAN_FIRE_RIGHT);
		
		CurAnimation = animations[AQUAMAN_STAND_LEFT];
		vy = -SIMON_JUMP_SPEED_Y;
		vx = 0;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		CGameObject::Update(dt);
		if (!IsJumping)
		{
			vx = -SIMON_WALKING_SPEED;
			CurAnimation = animations[AQUAMAN_WALK_LEFT];
		}
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 32;
		bottom = top + 64;
	}

};