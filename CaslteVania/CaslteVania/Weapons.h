#pragma once
#include "Knife.h"
#include "Axe.h"
#include "HollyWater.h"
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
		case AXE:
			return new CAxe();
		case HOLLY_WATER:
			return new CHollyWater();
		default:
			return NULL;
		}
	}
};