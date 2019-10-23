#include "Item.h"

void CItem::Render()
{
	CurAnimation->Render(x, y, 255);
	RenderBoundingBox();
}
