#include "Whip.h"

CWhip * CWhip::_instance = NULL;

void CWhip::Update(float dt)
{
	CGameObject::Update(dt);

}
void CWhip::ChangeAnimations(TYPE type)
{
	CurAnimation = animations[type];
}
void CWhip::Render()
{
	int alpha = 255;
	CurAnimation->Render(player->x, player->y, alpha);
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
