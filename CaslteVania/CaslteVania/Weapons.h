#pragma once
#include "Knife.h"
#include "Axe.h"
#include "HollyWater.h"
#include "StopWatch.h"
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
		case STOP_WATCH:
			return new CStopWatch();
		default:
			return NULL;
		}
	}
};