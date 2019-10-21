#pragma once
#include "GameObject.h"
#define BRICK_BBOX_WIDTH  1600
#define BRICK_BBOX_HEIGHT 16

class CBrick : public CGameObject
{
private:
	static CBrick* _instance;
public:
	CBrick();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Render() {};
	CBrick* GetInstance();
	~CBrick();
};

