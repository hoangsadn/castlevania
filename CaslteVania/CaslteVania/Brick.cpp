#include "Brick.h"

CBrick * CBrick::_instance = NULL;
CBrick::CBrick() : CGameObject()
{
	tag = GROUND;
};
void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}
CBrick* CBrick::GetInstance()
{
	if (_instance == NULL)
		_instance = new CBrick();
	return _instance;

}
CBrick::~CBrick()
{
}
