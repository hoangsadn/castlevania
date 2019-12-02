#pragma once
#include "Enemy.h"
#include "Simon.h"
#define BLACKPANTHER_WIDTH  64
#define BLACKPANTHER_HEIGHT 30
#define BLACKPANTHER_ACTIVE_DISTANCE 100
#define BLACKPANTHER_RUNNING_SPEED 0.2
#define BLACKPANTHER_JUMPING_SPEED -0.4
class CBlackPanther : public CEnemy
{
public:
	bool isRun;
	bool isSleep;
	bool change;
	bool JUMP;
	CBlackPanther() : CEnemy()
	{
		type = BLACKPANTHER;
		AddAnimation(903, BLACKPANTHER_STAND_LEFT);
		AddAnimation(904, BLACKPANTHER_STAND_RIGHT);
		AddAnimation(905, BLACKPANTHER_RUN_LEFT);
		AddAnimation(906, BLACKPANTHER_RUN_RIGHT);
		AddAnimation(907, BLACKPANTHER_JUMP_LEFT);
		AddAnimation(908, BLACKPANTHER_JUMP_RIGHT);
		nx = -1;
		CurAnimation = nx > 0 ? animations[BLACKPANTHER_STAND_RIGHT]:animations[BLACKPANTHER_STAND_LEFT];
		vy = 0.0f;
		vx = 0.0f;
		IsEndGround = false;
		isRun = true; 
		isSleep = true;
		JUMP = true;
		width = BLACKPANTHER_WIDTH;
		height = BLACKPANTHER_HEIGHT;
	}
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	void UpdatePosition(float dt)
	{
		CGameObject::Update(dt);
		if (abs(abs(player->x) - abs(x)) < BLACKPANTHER_ACTIVE_DISTANCE)
		{
			isSleep = false;
		}
		if (isRun&&!isSleep)
		{
			vx = nx < 0 ? -BLACKPANTHER_RUNNING_SPEED : BLACKPANTHER_RUNNING_SPEED;
			CurAnimation = nx < 0 ? animations[BLACKPANTHER_RUN_LEFT] : animations[BLACKPANTHER_RUN_RIGHT];
			isRun = false;
		}
		if (IsEndGround && !IsJumping)
		{

			CurAnimation = nx < 0 ? animations[BLACKPANTHER_JUMP_LEFT] : animations[BLACKPANTHER_JUMP_RIGHT];
			vy = BLACKPANTHER_JUMPING_SPEED;
			IsJumping = true;
			change = true;
			IsEndGround = false;

		}
		if (!IsJumping&& change)
		{
			nx = nx < 0 ? 1 : -1;
			vx = nx < 0 ? -BLACKPANTHER_RUNNING_SPEED : BLACKPANTHER_RUNNING_SPEED;
			CurAnimation = nx < 0 ? animations[BLACKPANTHER_RUN_LEFT] : animations[BLACKPANTHER_RUN_RIGHT];
			change = false;
		}
		
	}
};
