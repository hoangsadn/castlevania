#pragma once
#include "ItemWhip.h"
#include "ItemBigHeart.h"
#include "ItemKnife.h"
#include "ItemAxe.h"
#include "ItemSmallHeart.h"
#include "ItemHollyWater.h"
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
		case KNIFE:
			return new CItemKnife();
		case SMALL_HEART:
			return new CItemSmallHeart();
		case AXE:
			return new CItemAxe();
		case HOLLY_WATER:
			return new CItemHollyWater();
		default:
			return NULL;
		}
	}
};
