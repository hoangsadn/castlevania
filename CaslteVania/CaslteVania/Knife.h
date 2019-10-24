#pragma once
#include "Weapon.h"
class CKnife : public CWeapon
{
public:
	CKnife();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void UpdatePosititon(DWORD dt);
	~CKnife() {};
};