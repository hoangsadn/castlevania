#pragma once
#include "Simon.h"

class CSimon;

class CWhip : public CGameObject
{
private:
	static CWhip* _instance;
public:
	CWhip();
	CAnimation* CurAnimation;
	void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	void Init();
	void ChangeAnimations(TYPE type);
	CWhip* GetInstance();

	~CWhip();
};

