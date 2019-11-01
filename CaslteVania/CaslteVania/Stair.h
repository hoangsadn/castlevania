#pragma once 
#include "GameObject.h"
#define STAIR_BBOX_WIDTH 40
#define STAIR_BBOX_HEIGHT 66

class CStair : public CGameObject
{
private:
	static CStair* _instance;
public:
	CStair(TYPE type) 
	{
		tag = BOX;
		this->type = type;
	}
	void GetBoundingBox(float &l, float &t, float &r, float &b)
	{
		l = x;
		t = y;
		r = l + STAIR_BBOX_WIDTH;
		b = t + STAIR_BBOX_HEIGHT;
	}
	void Render() 
	{
		RenderBoundingBox();
	}

	~CStair() {};
};

