#include "Whip.h"


CWhip * CWhip::_instance = NULL;
CWhip::CWhip()
{
	AddAnimation(600, WHIP_ONE_LEFT);
	AddAnimation(601, WHIP_TWO_LEFT);
	AddAnimation(602, WHIP_THREE_LEFT);
	AddAnimation(603, WHIP_ONE_RIGHT);
	AddAnimation(604, WHIP_TWO_RIGHT);
	AddAnimation(605, WHIP_THREE_RIGHT);
	tag = WEAPON;
	typeWhip = 1;
	type = WHIP;
}


void CWhip::Init(int typeWhip)
{

	this->typeWhip = typeWhip;
	isDead = false;
	int posX = player->nx > 0 ? player->x - 22 : player->x - 80;
	int	posY = player->nx > 0 ? player->y + 1 : player->y;
	SetPosition(posX, posY);

	switch (typeWhip)
	{
	case 1:
		if (player->nx > 0)
			CWhip::ChangeAnimations(WHIP_ONE_RIGHT);
		else
			CWhip::ChangeAnimations(WHIP_ONE_LEFT);
		break;
	case 2:
		if (player->nx > 0)
			CWhip::ChangeAnimations(WHIP_TWO_RIGHT);
		else
			CWhip::ChangeAnimations(WHIP_TWO_LEFT);
		break;
	case 3:
	{
		if (player->nx > 0)
			CWhip::ChangeAnimations(WHIP_THREE_RIGHT);
		else
			CWhip::ChangeAnimations(WHIP_THREE_LEFT);
		break;
	}
	default:
		typeWhip = 3;
		break;
	}

	CurAnimation->currentFrame = -1;			//switch animation in the last frame , must return to defaut
	CurAnimation->isLastFrame = false;

}
void CWhip::UpdatePosititon(DWORD dt)
{
	int posX = player->nx > 0 ? player->x - 22 : player->x - 80;
	int	posY = player->nx > 0 ? player->y + 1 : player->y;
	SetPosition(posX, posY);
	if (CurAnimation->isLastFrame)
		isDead = true;
}
void CWhip::ChangeAnimations(TYPE type)
{
	CurAnimation = animations[type];
}

void CWhip::GetBoundingBox(float &l, float &t, float &r, float &b)
{

	switch (typeWhip)
	{
	case 1:case 2:
		l = player->nx > 0 ? x + 76 : x + 35;
		t = y + 16;
		r = l + 56;
		b = t + 18;
		break;
	case 3:
		l = player->nx > 0 ? x + 72 : x + 3;
		t = y + 23;
		r = l + 88;
		b = t + 12;
		break;

	}
	if (CurAnimation->isLastFrame)
		allowHit = true;
	else allowHit = false;
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
