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
		width = STAIR_BBOX_WIDTH;
		height = STAIR_BBOX_HEIGHT;
	}
	void GetBoundingBox(float &l, float &t, float &r, float &b)
	{
		l = x;
		t = y;
		r = l + width;
		b = t + height;
	}
	void Render() 
	{
		RenderBoundingBox();
	}

	~CStair() {};
};

