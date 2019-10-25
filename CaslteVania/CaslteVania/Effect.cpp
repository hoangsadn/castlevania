#include "Effect.h"

Effect * Effect::_instance = NULL;


Effect::Effect()
{
	AddAnimation(701, EFFECT_DEAD);
	CurAnimation = animations[EFFECT_DEAD];
	tag = EFFECT;
}
void Effect::ChangeAnimations(TYPE type)
{
	CurAnimation = animations[type];
}
void Effect::Render()
{
	int alpha = 255;
	CurAnimation->Render(x, y, alpha);
	
}
Effect* Effect::GetInstance()
{
	if (_instance == NULL)
		_instance = new Effect();
	return _instance;

}

Effect::~Effect()
{

}
