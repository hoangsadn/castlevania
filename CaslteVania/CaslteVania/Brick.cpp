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
	r = l + width;
	b = t + height;
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
