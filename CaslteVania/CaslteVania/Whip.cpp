#include "Whip.h"

CWhip * CWhip::_instance = NULL;

void CWhip::Update(float dt)
{
	CGameObject::Update(dt);

}
void CWhip::Init()
{
	CWhip::SetPosition(player->x, player->y);
	if (player->nx > 0)
		CWhip::ChangeAnimations(WHIP_ONE_LEFT);
	else
		CWhip::ChangeAnimations(WHIP_ONE_RIGHT);
}
void CWhip::ChangeAnimations(TYPE type)
{
	CurAnimation = animations[type];
}
void CWhip::Render()
{
	int alpha = 255;
	int posX, posY;
	CurAnimation->Render(player->x -28, player->y- 6, alpha);
	//RenderBoundingBox();
}
CWhip* CWhip::GetInstance()
{
	if (_instance == NULL)
		_instance = new CWhip();
	return _instance;

}
CWhip::~CWhip()
{
}
