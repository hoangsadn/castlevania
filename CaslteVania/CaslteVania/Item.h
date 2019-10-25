#pragma once
#include "GameObject.h"
class CAnimation;

class CItem : public CGameObject
{
public:
	CItem() 
	{
		tag = ITEM;
		vy = 0.04;
		timeDead = GetTickCount();
	};
	CAnimation* CurAnimation;
	TYPE Type;
	DWORD timeDead;
	virtual	void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
};



