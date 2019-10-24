#include "Holder.h"




CHolder::~CHolder()
{
}
void CHolder::Render() 
{
	CurAnimation->Render(x, y, 255);
	RenderBoundingBox();

}
void CHolder::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{

}
void CHolder::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	
}
