#pragma once
#include "GameObject.h"

#define SIMON_EDIT_BBOX_X 15
#define SIMON_EDIT_BBOX_Y 4
#define TIME_FLASH_SCREEN 400

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
	bool Invincibility;
	int Checkpoint;
	float posOfStair;
	int stairDirection;
	DWORD untouchTime, flashtime;	//time hurting and enemy cant hurt more in this time 
	TYPE weaponTypeCarry;	
	int whipType;	// type of whip 1,2,3 
	int bullet;
	int point;
	int alpha,beta;		//for render
	int health;
	bool freeze;
	CSimon();
	void Revival();

	std::unordered_map<STATENAME, bool> allow;
	CAnimation* CurAnimation;
	static CSimon* GetInstance();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	void CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects);
	virtual void Render();
	void ChangeAnimation(PlayerState* newState);

	void HandleObject(LPGAMEOBJECT object);

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void OnKeyUp(int key);
	void OnKeyDown(int key);

};

