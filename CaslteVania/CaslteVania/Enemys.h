#pragma once

#include "Ghost.h"
#include "BlackPanter.h"
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
	
		default: return NULL;
		}
	}
};