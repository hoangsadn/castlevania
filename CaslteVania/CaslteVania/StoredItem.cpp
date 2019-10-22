#include "StoredItem.h"




CStoredItem::~CStoredItem()
{
}
void CStoredItem::Render() 
{
	CurAnimation->Render(x, y, 255);
	RenderBoundingBox();

}
void CStoredItem::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{

}
void CStoredItem::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	
}
