#pragma once
#include "GameObject.h"



class CAnimation;
class CWhip;
class PlayerState;
class CGameObject;

class CSimon : public CGameObject
{
private:
	static CSimon* _instance;

public:
	PlayerState* state;
	CWhip* whip;
	Camera * cam;
	int stateBoundingBox;
	bool IsJumping;
	bool IsHitting, IsThrowing;
	bool IsOnStair, IsOutStair;
	bool IsOnFootStair, IsOnTopStair;
	bool IsDead;
	bool IsTouchDoor;
	bool IsWalkingComplete;
	float posOfStair;
	int stairDirection;
	DWORD untouchTime;	//time hurting and enemy cant hurt more in this time 
	TYPE weaponTypeCarry;	
	int whipType;	// type of whip 1,2,3 
	int bullet;
	int alpha;		//for render
	int health;
	CSimon();
	void Revival();

	std::unordered_map<STATENAME, bool> allow;
	CAnimation* CurAnimation;
	static CSimon* GetInstance();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects);
	virtual void Render();
	void ChangeAnimation(PlayerState* newState);

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void OnKeyUp(int key);
	void OnKeyDown(int key);

};

