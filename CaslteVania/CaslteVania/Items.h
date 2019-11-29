#pragma once
#include "ItemWhip.h"
#include "ItemBigHeart.h"
#include "ItemKnife.h"
#include "ItemAxe.h"
#include "ItemSmallHeart.h"
#include "ItemHollyWater.h"
#include "ItemMoneyBlue.h"
#include "ItemMoneyRed.h"
#include "ItemMoneyWhite.h"
#include "ItemInvincibility.h"
#include "ItemStopWatch.h"
#include "ItemRosary.h"
#include "ItemDoubleShot.h"
#include "ItemRoast.h"
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
		case MONEY_BLUE:
			return new CItemMoneyBlue();
		case MONEY_RED:
			return new CItemMoneyRed();
		case MONEY_WHITE:
			return new CItemMoneyWhite();
		case DOUBLE_SHOT:
			return new CItemDoubleShot();
		case ROSARY:
			return new CItemRosary();
		case STOP_WATCH:
			return new CItemStopWatch();
		case INVINCIBILITY:
			return new CItemInvincibility();
		case ROAST:
			return new CItemRoast();
		default:
			return NULL;
		}
	}
};
