#pragma once
#include "Weapon.h"
class CSimon;

class CWhip : public CWeapon
{
private:
	static CWhip* _instance;
public:
	CWhip();
	int typeWhip;
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	void Init(int typeWhip);
	virtual void UpdatePosititon(DWORD dt);
	void ChangeAnimations(TYPE type);
	CWhip* GetInstance();

	~CWhip();
};

