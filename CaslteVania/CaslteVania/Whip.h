#pragma once
#include "Simon.h"
class CWhip : public CGameObject
{
private:
	static CWhip* _instance;
public:
	CWhip() : CGameObject() 
	{

	}
	CAnimation* CurAnimation;
	void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual void Update(float dt);
	virtual void Render();
	void Init();
	void ChangeAnimations(TYPE type);
	CWhip* GetInstance();
	~CWhip();
};

