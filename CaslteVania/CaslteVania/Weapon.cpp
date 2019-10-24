#include "Weapon.h"
#include "HolderFirePillar.h"

void CWeapon::Render()
{
	int alpha = 255;
	CurAnimation->Render(x, y, alpha);
	RenderBoundingBox();
}

void CWeapon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	UpdatePosititon(dt);
	vector<LPGAMEOBJECT> coEvents;

	coEvents.clear();

	for (UINT i = 0; i < coObjects->size(); i++)
	{
		float l1, t1, r1, b1, l2, t2, r2, b2;

		GetBoundingBox(l1, t1, r1, b1);

		coObjects->at(i)->GetBoundingBox(l2, t2, r2, b2);
		if (IsCollision(l1, t1, r1, b1, l2, t2, r2, b2))
		{
			coEvents.push_back(coObjects->at(i));
		}
	}

	for (UINT i = 0; i < coEvents.size(); i++)
	{

		if (dynamic_cast<CHolderFirePillar *>(coEvents.at(i))) // if e->obj is Goomba 
		{
			CHolderFirePillar *FirePillar = dynamic_cast<CHolderFirePillar *>(coEvents.at(i));
			FirePillar->isDead = true;
			isDead = true;
		}
	}

}