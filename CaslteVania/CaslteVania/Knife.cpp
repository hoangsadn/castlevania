#include "Knife.h"
CKnife::CKnife()
{
	AddAnimation(803, KNIFE_RIGHT);
	AddAnimation(804, KNIFE_LEFT);
	if (player->nx > 0)
	{
		CurAnimation = animations[KNIFE_RIGHT];
		vx = 0.5;
	}
	else
	{
		CurAnimation = animations[KNIFE_LEFT];
		vx = -0.5;
	}
	type = KNIFE;

}
void CKnife::UpdatePosititon(DWORD dt)
{
	CGameObject::Update(dt);
	x += dx;
}
void CKnife::GetBoundingBox(float &l, float &t, float &r, float &b)
{			
	l = x;
	t = y;
	r = l + 32;
	b = t + 18;
}