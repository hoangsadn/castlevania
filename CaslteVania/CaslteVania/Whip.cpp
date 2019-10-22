#include "Whip.h"
#include "StoredItemFirePillar.h"
#include <algorithm>

CWhip * CWhip::_instance = NULL;
CWhip::CWhip() :CGameObject()
{
	AddAnimation(600, WHIP_ONE_LEFT);
	AddAnimation(603, WHIP_ONE_RIGHT);
}
void CWhip::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	int posX = player->nx > 0 ? player->x - 22 : player->x - 80;
	int	posY = player->nx > 0 ? player->y + 1 : player->y;
	SetPosition(posX, posY);

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

		if (dynamic_cast<CStoredItemFirePillar *>(coEvents.at(i))) // if e->obj is Goomba 
		{
			CStoredItemFirePillar *FirePillar = dynamic_cast<CStoredItemFirePillar *>(coEvents.at(i));
			FirePillar->isDead = true;

		}
	}
}

void CWhip::Init()
{
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
	CurAnimation->Render(x, y, alpha);
	RenderBoundingBox();
}
void CWhip::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	if (CurAnimation->isLastFrame)
	{
		l = player->nx > 0 ? x + 76 : x + 35;
		t = y + 14;
		r = l + 56;
		b = t + 18;
	}
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
