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
	int typeWhip;
	void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	void Init(int typeWhip);
	void ChangeAnimations(TYPE type);
	CWhip* GetInstance();

	~CWhip();
};

