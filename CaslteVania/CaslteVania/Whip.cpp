#include "Whip.h"

CWhip * CWhip::_instance = NULL;
CWhip::CWhip() :CGameObject()
{
	AddAnimation(600, WHIP_ONE_LEFT);
	AddAnimation(603, WHIP_ONE_RIGHT);
}
void CWhip::Update(float dt)
{

}

void CWhip::Init()
{
	CWhip::SetPosition(player->x, player->y);
	if (player->nx > 0)
		CWhip::ChangeAnimations(WHIP_ONE_RIGHT);
	else
		CWhip::ChangeAnimations(WHIP_ONE_LEFT);
	CurAnimation->currentFrame = -1;			//switch animation in the last frame , must return to defaut
}
void CWhip::ChangeAnimations(TYPE type)
{
	CurAnimation = animations[type];
}
void CWhip::Render()
{
	int alpha = 255;
	int posX = player->nx > 0 ? player->x - 22 : player->x - 80;
	int	posY = player->nx > 0 ? player->y +1 : player->y;
	CurAnimation->Render(posX, posY, alpha);
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
