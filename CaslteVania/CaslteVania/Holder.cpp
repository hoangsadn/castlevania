#include "Holder.h"




CHolder::~CHolder()
{
}
void CHolder::DeadState()
{
	CurAnimation = animations[EFFECT_DEAD];

}
void CHolder::Render() 
{
	CurAnimation->Render(x, y, 255);
//	RenderBoundingBox();

}
void CHolder::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (isBuring)
	{
		LPANIMATION ani = new CAnimation(100);	
		ani->Add(50001);
		ani->Add(50002);
		ani->Add(50003);
		CurAnimation = ani;
		isBuring = false;
		ishitting = true;
	}
	if (ishitting && CurAnimation->isLastFrame)
	{
		CurAnimation->isLastFrame = false;
		CurAnimation->currentFrame = -1;
		isDead = true;
		ishitting = false;
	}
}
void CHolder::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	
}
