#pragma once
#include "Knife.h"

class CWeapons
{
public:
	CWeapons() {};
	~CWeapons() {};
	static CWeapon* CreateWeapon(TYPE type)
	{
		switch (type)
		{
		case KNIFE:
			return new CKnife();
			break;
		default:
			return NULL;
		}
	}
};