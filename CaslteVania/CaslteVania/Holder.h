#pragma once
#include "GameObject.h"
class CAnimation;

class CHolder : public CGameObject
{
public:
	CAnimation* CurAnimation;
	bool ishitting;
	TYPE stored;
	CHolder() : CGameObject()
	{
		AddAnimation(701, EFFECT_DEAD);
		tag = HOLDER;
		ishitting = false;
		isBuring = false;
		isDead = false;
	}
	void DeadState();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();

	~CHolder();
};

