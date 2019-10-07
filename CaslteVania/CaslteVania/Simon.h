#pragma once
#include "GameObject.h"
#include "PlayerWalkingState.h"
#include "PlayerStandingState.h"
class CAnimation;
class CMario : public CGameObject
{
private:
	static CMario* _instance;
	int untouchable;
public:
	PlayerState* state;

	CMario() : CGameObject() 
	{
		untouchable = 0;
	}

	CAnimation* CurAnimation;
	static CMario* GetInstance();
	virtual void Update(DWORD dt, vector<CGameObject*> *colliable_objects = NULL);
	virtual void Render();
	void ChangeAnimation(PlayerState* newState);

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void OnKeyUp(int key);
	void OnKeyDown(int key);

};

