#pragma once
#include "GameObject.h"
#define GRAVITY_ITEM 0.04f
class CAnimation;

class CItem : public CGameObject
{
public:
	CItem() 
	{
		tag = ITEM;
		vy = GRAVITY_ITEM;
		timeDead = GetTickCount();
	};
	CAnimation* CurAnimation;
	DWORD timeDead;
	virtual	void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
};



