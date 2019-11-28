#pragma once
#include "GameObject.h"
class CAnimation;

class CEnemy : public CGameObject
{
public:
	float repawnPosX, repawnPosY;
	DWORD timeRepawn;
	DWORD timeDelay;
	CEnemy()
	{
		AddAnimation(701, EFFECT_DEAD);
		tag = ENEMY;
		isDead = false;
		isBuring = false;
		ishitting = false;
	};
	bool ishitting;
	bool IsEndGround;
	bool IsJumping;
	CAnimation* CurAnimation;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void UpdatePosition(float dt) {};
	virtual void Render();
	virtual void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects);

};