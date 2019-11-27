#include "Weapon.h"
#include "HolderFirePillar.h"

void CWeapon::Render()
{
	int alpha = 255;
	if (type != STOP_WATCH)
	{
		CurAnimation->Render(x, y, alpha);
		RenderBoundingBox();
	}
}

void CWeapon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	UpdatePosititon(dt);
	vector<LPGAMEOBJECT> coEvents;

	coEvents.clear();

	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (allowHit) 
		if (IsCollisionAABB(GetRect(),coObjects->at(i)->GetRect()))
		{
			coEvents.push_back(coObjects->at(i));
		}
	}

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		switch (coEvents.at(i)->tag)
		{
		case HOLDER: case ENEMY:
			
				coEvents.at(i)->isBuring = true;
				if (type == KNIFE)
					isDead = true;
				if (coEvents.at(i)->type == FIRE_BALL)
					isDead = true;
			if (player->freeze && coEvents.at(i)->tag == ENEMY)
				coEvents.at(i)->isDead = true;
			break;
		}
	}

}