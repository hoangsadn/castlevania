#pragma once
#include "GameObject.h"
#include "ItemWhip.h"
class CAnimation;

class CItem : public CGameObject
{
public:
	CItem() {};
	CAnimation* CurAnimation;
	TYPE type;
	bool isDead;
	virtual	void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL) {};
	virtual void Render();

};


class CItemWhip : public CItem
{
public:
	CItemWhip()
	{
		AddAnimation(601, MORNING_STAR);
		CurAnimation = animations[MORNING_STAR];
		isDead = false;
		type = MORNING_STAR;
	}
	void GetBoundingBox(float &left, float &top, float &right, float &bottom)
	{
		left = x;
		top = y;
		right = left + 32;
		bottom = top + 32;
	}
};
class CItems
{
public:
	CItems() {};
	~CItems() { };
	static CItem* CreateIteam(TYPE type)
	{
		switch (type)
		{
			case MORNING_STAR:
				return new CItemWhip();

			default:
				return NULL;
		}
	}
};
