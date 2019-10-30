#include "Door.h"

CDoor * CDoor::_instance = NULL;

CDoor::CDoor()
{
	tag = BOX;
	type = DOOR;
}
void CDoor::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = l + DOOR_BBOX_WIDTH;
	b = t + DOOR_BBOX_HEIGHT;
}
void CDoor::Render()
{
	RenderBoundingBox();
}
CDoor* CDoor::GetInstance()
{
	if (_instance == NULL)
		_instance = new CDoor();
	return _instance;
}
CDoor::~CDoor()
{
}
