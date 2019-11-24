#pragma once
#include "GameObject.h"
class CAnimation;

class CEnemy : public CGameObject
{
public:
	CEnemy()
	{
		AddAnimation(701, EFFECT_DEAD);
		tag = ENEMY;
		isDead = false;

	};
	bool IsEndGround;
	bool IsJumping;
	CAnimation* CurAnimation;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	virtual void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects);

};