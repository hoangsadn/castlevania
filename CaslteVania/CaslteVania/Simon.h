#pragma once
#include "GameObject.h"
#include "PlayerWalkingState.h"
#include "PlayerStandingState.h"
#include "PlayerJumpingState.h"
#include "PlayerHittingState.h"
class CAnimation;
class CMario : public CGameObject
{
private:
	static CMario* _instance;
public:
	PlayerState* state;
	bool IsJumping;
	bool IsHitting;
	CMario() : CGameObject() 
	{
	}
	void Revival();

	std::unordered_map<STATENAME, bool> allow;
	CAnimation* CurAnimation;
	static CMario* GetInstance();
	virtual void Update(DWORD dt, vector<CGameObject*> *colliable_objects = NULL);
	virtual void Render();
	void ChangeAnimation(PlayerState* newState);

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void OnKeyUp(int key);
	void OnKeyDown(int key);

};

