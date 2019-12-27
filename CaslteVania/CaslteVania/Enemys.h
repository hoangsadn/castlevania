#pragma once

#include "Ghost.h"
#include "BlackPanter.h"
#include "Bat.h"
#include "Aquaman.h"
#include "Boss.h"
class CEnemys
{
public:
	CEnemys() {};
	~CEnemys() {};

	static CEnemy* CreateEnemy(int enemyID)
	{
		switch (enemyID)
		{
		case 1: 
			return new CGhost();
		case 2: 
			return new CBlackPanther();
		case 3: 
			return new CBat();
		case 4:
			return new CAquaman();
		case 5: 
			return new Boss();
		default: return NULL;
		}
	}
};