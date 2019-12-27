#include "CheckPoint.h"
#define CHECKPOINT_3_SIMON_POS_Y 430
#define CHECKPOINT_4_SIMON_POS_X 3167
#define CHECKPOINT_4_SIMON_POS_Y 360
#define CHECKPOINT_5_SIMON_POS_X 3800
#define CHECKPOINT_1_SIMON_TAR 1500
#define CHECKPOINT_2_SIMON_TAR 3100
#define CHECKPOINT_7_SIMON_TAR 4110
#define CHECKPOINT_HEIGHT 2



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
		posTarX = CHECKPOINT_1_SIMON_TAR;
		break;
	case 2:
		posTarX = CHECKPOINT_2_SIMON_TAR;
		break;
	case 3:
		posMoveSimonX = CHECKPOINT_4_SIMON_POS_X;
		posMoveSimonY = CHECKPOINT_3_SIMON_POS_Y;
		height = CHECKPOINT_HEIGHT;
		break;
	case 4:
		
		posMoveSimonX = CHECKPOINT_4_SIMON_POS_X;
		posMoveSimonY = CHECKPOINT_4_SIMON_POS_Y;
		height = CHECKPOINT_HEIGHT;
		break;
	case 5:
		
		posMoveSimonX = CHECKPOINT_5_SIMON_POS_X;
		posMoveSimonY = CHECKPOINT_4_SIMON_POS_Y;
		height = CHECKPOINT_HEIGHT;
		break;
	case 6:

		posMoveSimonX = CHECKPOINT_5_SIMON_POS_X;
		posMoveSimonY = CHECKPOINT_3_SIMON_POS_Y;
		height = CHECKPOINT_HEIGHT;
		break;
	case 7: 
	{
		posTarX = CHECKPOINT_7_SIMON_TAR;
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
