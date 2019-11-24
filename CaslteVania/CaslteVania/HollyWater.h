#pragma once
#include "Weapon.h"
class CHollyWater : public CWeapon
{
public:
	DWORD timeDead;
	CHollyWater()
	{
		allowHit = true;
		AddAnimation(809, HOLLY_WATER_THROW);
		AddAnimation(810, HOLLY_WATER_BURN);
		CurAnimation = animations[HOLLY_WATER_THROW];
		width = 32;
		height = 26;

		vx = player->nx > 0 ? vx = 0.12 : vx = -0.12;
		vy = -0.09;
		x = player->x;
		y = player->y+ 20;

		type = HOLLY_WATER;
		timeDead = GetTickCount();
	}
	void GetBoundingBox(float &l, float &t, float &r, float &b)
	{
		l = x;
		t = y;
		r = l + width;
		b = t + height;
	}
	void UpdatePosititon(DWORD dt)
	{
		
		if (x < CAMERA->x || x > CAMERA->x + CAMERA->mWidth || y > CAMERA->y + CAMERA->mHeight)
		{
			isDead = true;
			//GAMELOG("OK");
		}
		if (GetTickCount() - timeDead > 10000)
			isDead = true;
		vy += 0.004;
		CGameObject::Update(dt);
	//	CollisonGroundWall(dt, coObjects);

	}
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
	{
		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		// turn off collision when die 
		CalcPotentialCollisions(coObjects, coEvents);

		// reset untouchable timer if untouchable time has passed
		// No collision occured, proceed normally

		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else
		{
			// block 
			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
			x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
			y += min_ty * dy + ny * 0.4f;

			vx = 0;
			vy = 0;
			CurAnimation = animations[HOLLY_WATER_BURN];
		}
		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
	~CHollyWater() {};
};