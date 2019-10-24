#pragma once
#include "GameObject.h"
class CAnimation;

class CHolder : public CGameObject
{
public:
	CAnimation* CurAnimation;

	TYPE stored;
	CHolder() : CGameObject()
	{
		tag = HOLDER;
	}
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();

	~CHolder();
};

