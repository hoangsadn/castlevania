#pragma once
#include "Enemy.h"
#define BOSS_WIDTH 100
#define BOSS_HEIGHT 46
struct xy
{
	float x, y;
};


class Boss : public CEnemy
{

public:
	DWORD waitTime;
	bool isActive, isGetSimonPos, isGetPosAttack, isAttackSimon, isGetCpoint;
	TYPE state;
	CAnimation* EffectHit;
	vector <xy > PosBossAttack;
	xy BossPos, SimonPos, BossPrePos, CPos;

	Boss() : CEnemy()
	{
		type = BOSS;
		AddAnimation(919, BOSS_HANG);
		AddAnimation(920, BOSS_MOVE);
		CurAnimation = animations[BOSS_HANG];
		state = BOSS_HANG;
		width = BOSS_WIDTH;
		height = BOSS_HEIGHT;
		isActive = false;
		isGetPosAttack = false;
		xy k;
		k.x = 5150;
		k.y = 150;
		PosBossAttack.push_back(k);
		k.x = 5350;
		PosBossAttack.push_back(k);
		k.x = 5400;
		PosBossAttack.push_back(k);
		k.x = 5150;
		k.y = 250;
		PosBossAttack.push_back(k);
		k.x = 5350;
		PosBossAttack.push_back(k);
		k.x = 5400;
		PosBossAttack.push_back(k);
		
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void UpdatePosition(float dt);
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects) {};
	void MoveStraight(float x1, float y1, float x2, float y2);
	void MoveCurved(float x1, float y1, float x2, float y2, float x3, float y3);
	void RepareToMove();

	int Slerp(int n1, int n2, float perc);
	float Lerp(float a, float b, float f);

	~Boss();
};

