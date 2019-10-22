#pragma once
#include "GameObject.h"
class CAnimation;

class CStoredItem : public CGameObject
{
public:
	CAnimation* CurAnimation;
	bool isDead;
	CStoredItem() : CGameObject() {}
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();

	~CStoredItem();
};

