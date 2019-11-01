#include "CheckPoint.h"

CCheckPoint * CCheckPoint::_instance = NULL;

CCheckPoint::CCheckPoint()
{
	tag = BOX;
	type = CHECKPOINT;
}
void CCheckPoint::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = l + CHECKPOINT_BBOX_WIDTH;
	b = t + CHECKPOINT_BBOX_HEIGHT;
}
void CCheckPoint::Render()
{
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
