#pragma once
#include "Enemy.h"
class CAquaman : public CEnemy
{
public:
	TYPE state;
	bool fire;
	float prePos;
	CAquaman() : CEnemy()
	{
		type = AQUAMAN;
		fire = false;
		IsJumping = true;
		AddAnimation(911, AQUAMAN_STAND_LEFT);
		AddAnimation(912, AQUAMAN_STAND_RIGHT);
		AddAnimation(913, AQUAMAN_WALK_LEFT);
		AddAnimation(914, AQUAMAN_WALK_RIGHT);
		AddAnimation(915, AQUAMAN_FIRE_LEFT);
		AddAnimation(916, AQUAMAN_FIRE_RIGHT);
		state = AQUAMAN_STAND;
		nx = 1;
		CurAnimation = nx < 0 ? animations[AQUAMAN_STAND_LEFT] : animations[AQUAMAN_STAND_RIGHT];
		vy = -SIMON_JUMP_SPEED_Y;
		vx = 0;
	}
	void UpdatePosition(float dt)
	{
		CGameObject::Update(dt);
		if (!IsJumping && state == AQUAMAN_STAND)
		{
			prePos = x;
			vx = nx < 0 ? -SIMON_WALKING_SPEED : SIMON_WALKING_SPEED;
			CurAnimation = nx < 0 ? animations[AQUAMAN_WALK_LEFT] : animations[AQUAMAN_WALK_RIGHT];
			state = AQUAMAN_WALK;
			
		}

		if (state == AQUAMAN_WALK && abs(abs(prePos) - abs(x)) > 150)
		{
			vx = 0;
			prePos = x;
			state = AQUAMAN_FIRE;
			CurAnimation = nx < 0 ? animations[AQUAMAN_FIRE_LEFT] : animations[AQUAMAN_FIRE_RIGHT];

		}
		else if (state ==  AQUAMAN_FIRE && CurAnimation->isLastFrame)
		{
			CurAnimation->isLastFrame = false;
			CurAnimation->currentFrame = -1;
			nx = nx > 0 ? -1 : 1;
			fire = false;
			vx = nx < 0 ? -SIMON_WALKING_SPEED : SIMON_WALKING_SPEED;
			state = AQUAMAN_WALK;
			CurAnimation = nx < 0 ? animations[AQUAMAN_WALK_LEFT] : animations[AQUAMAN_WALK_RIGHT];
			
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