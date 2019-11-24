#pragma once
#include "GameObject.h"
class Effect : public CGameObject
{
private:
	static Effect* _instance;
public:
	CAnimation* CurAnimation;
	void ChangeAnimations(TYPE type);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) 
	{
		left = x;
		top = y;
		right = left + 42;
		bottom = top + 44;
	};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL) {};
	virtual void Render();
	Effect* GetInstance();
	Effect();
	~Effect();
};

