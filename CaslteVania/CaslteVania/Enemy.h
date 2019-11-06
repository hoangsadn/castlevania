#pragma once
#include "GameObject.h"
class CAnimation;

class CEnemy : public CGameObject
{
public:
	CEnemy()
	{
		tag = ENEMY;
		isDead = false;

	};
	bool IsEndGround;
	bool IsJumping;
	CAnimation* CurAnimation;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects);

};