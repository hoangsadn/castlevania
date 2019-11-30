#pragma once
#include "Enemy.h"
#include "Simon.h"
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
		width = 64;
		height = 30;
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
		if (abs(abs(player->x) - abs(x)) < 100)
		{
			isSleep = false;
		}
		if (isRun&&!isSleep)
		{
			vx = nx < 0 ? -0.2 : 0.2;
			CurAnimation = nx < 0 ? animations[BLACKPANTHER_RUN_LEFT] : animations[BLACKPANTHER_RUN_RIGHT];
			isRun = false;
		}
		if (IsEndGround && !IsJumping)
		{

			CurAnimation = nx < 0 ? animations[BLACKPANTHER_JUMP_LEFT] : animations[BLACKPANTHER_JUMP_RIGHT];
			vy = -0.4;
			IsJumping = true;
			change = true;
			IsEndGround = false;

		}
		if (!IsJumping&& change)
		{
			nx = nx < 0 ? 1 : -1;
			vx = nx < 0 ? -0.2 : 0.2;
			CurAnimation = nx < 0 ? animations[BLACKPANTHER_RUN_LEFT] : animations[BLACKPANTHER_RUN_RIGHT];
			change = false;
		}
		
	}
};
