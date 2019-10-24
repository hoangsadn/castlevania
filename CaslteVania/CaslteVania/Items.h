#pragma once
#include "ItemWhip.h"
#include "ItemBigHeart.h"
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
		case BIG_HEART:
			return new CItemBigHeart();
		default:
			return NULL;
		}
	}
};
