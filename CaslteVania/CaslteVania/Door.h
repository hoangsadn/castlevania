#pragma once 
#include "GameObject.h"
#define DOOR_BBOX_WIDTH 40
#define DOOR_BBOX_HEIGHT 66

class CDoor : public CGameObject
{
private:
	static CDoor* _instance;
public:
	CDoor();
	void GetBoundingBox(float &l, float &t, float &r, float &b);
	void Render();
	CDoor *GetInstance();

	~CDoor();
};

