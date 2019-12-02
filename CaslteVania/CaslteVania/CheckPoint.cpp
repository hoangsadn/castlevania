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
	height = CHECKPOINT_BBOX_HEIGHT;
	width = CHECKPOINT_BBOX_WIDTH;
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
void CCheckPoint::Init()
{
	switch (id)
	{
	case 1:
		posTarX = 1500;
		break;
	case 2:
		posTarX = 3100;
		break;
	case 3:
		posMoveSimonX = 3167;
		posMoveSimonY = 430;
		height = 2;
		break;
	case 4:
		
		posMoveSimonX = 3167;
		posMoveSimonY = 360;
		height = 2;
		break;
	case 5:
		
		posMoveSimonX = 3800;
		posMoveSimonY = 360;
		height = 2;
		break;
	case 6:

		posMoveSimonX = 3800;
		posMoveSimonY = 430;
		height = 2;
		break;
	case 7: 
	{
		posTarX = 4140;
		break;
	}
	default:
		break;
	}
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
