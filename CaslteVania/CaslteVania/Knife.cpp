#include "Knife.h"
#define KNIFE_WIDTH 32
#define KNIFE_HEIGHT 18 
CKnife::CKnife()
{
	allowHit = true;
	AddAnimation(803, KNIFE_RIGHT);
	AddAnimation(804, KNIFE_LEFT);
	width = KNIFE_WIDTH;
	height = KNIFE_HEIGHT;
	if (player->nx > 0)
	{
		CurAnimation = animations[KNIFE_RIGHT];
		vx = SIMON_WALKING_SPEED;
	}
	else
	{
		CurAnimation = animations[KNIFE_LEFT];
		vx = -SIMON_WALKING_SPEED;
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