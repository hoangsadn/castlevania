#pragma once 
#include "GameObject.h"
#define CHECKPOINT_BBOX_WIDTH 40
#define CHECKPOINT_BBOX_HEIGHT 66

class CCheckPoint : public CGameObject
{
private:
	static CCheckPoint* _instance;
public:
	int id;
	float posTarX, posTarY;
	float posMoveSimonX, posMoveSimonY;
	bool IsChangingMap;
	CAnimation* CurAnimation;
	CCheckPoint();
	void Init();
	void GetBoundingBox(float &l, float &t, float &r, float &b);	
	void Render();
	CCheckPoint *GetInstance();

	~CCheckPoint();
};

