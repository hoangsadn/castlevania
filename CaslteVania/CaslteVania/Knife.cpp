#include "Knife.h"
CKnife::CKnife()
{
	allowHit = true;
	AddAnimation(803, KNIFE_RIGHT);
	AddAnimation(804, KNIFE_LEFT);
	width = 32;
	height = 18;
	if (player->nx > 0)
	{
		CurAnimation = animations[KNIFE_RIGHT];
		vx = 0.2;
	}
	else
	{
		CurAnimation = animations[KNIFE_LEFT];
		vx = -0.2;
	}
	x = player->x;
	y = player->y;
	type = KNIFE;

}
void CKnife::UpdatePosititon(DWORD dt)
{
	CGameObject::Update(dt);
	x += dx;
	//GAMELOG("RUNNING");
	if (x < CAMERA->x || x > CAMERA->x + CAMERA->mWidth)
	{
		isDead = true;
		//GAMELOG("OK");
	}

}
void CKnife::GetBoundingBox(float &l, float &t, float &r, float &b)
{			
	l = x;
	t = y;
	r = l + width;
	b = t + height;
}