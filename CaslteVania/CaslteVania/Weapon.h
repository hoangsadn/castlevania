#pragma once
#include "Simon.h"

class CWeapon : public CGameObject
{
public:

	CWeapon() : CGameObject()
	{
		tag = WEAPON;
		isDead = false;
	}
	CAnimation* CurAnimation;
	void GetBoundingBox(float &l, float &t, float &r, float &b) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void UpdatePosititon(DWORD dt) {};
	virtual void Render();

};