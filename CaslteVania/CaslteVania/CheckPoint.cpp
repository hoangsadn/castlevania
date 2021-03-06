#include "CheckPoint.h"



CCheckPoint * CCheckPoint::_instance = NULL;

CCheckPoint::CCheckPoint()
{
	AddAnimation(303, DOOR_OPEN);
	AddAnimation(304, DOOR_CLOSE);
	AddAnimation(305, DOOR_OPENING);
	tag = BOX;
	this->type = CHECKPOINT;
	IsChangingMap = false;
}

void CCheckPoint::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = l + width;
	b = t + height;
}
void CCheckPoint::Render()
{
	if (IsChangingMap)
	{
		int alpha = 255;
		CurAnimation->Render(x, y, alpha);
	}
	RenderBoundingBox();
	
}

CCheckPoint* CCheckPoint::GetInstance()
{
	if (_instance == NULL)
		_instance = new CCheckPoint();
	return _instance;
}
CCheckPoint::~CCheckPoint()
{
}
