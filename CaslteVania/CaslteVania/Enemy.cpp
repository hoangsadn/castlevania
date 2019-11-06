#include "Enemy.h"

void CEnemy::Render()
{
	CurAnimation->Render(x, y, 255);
	RenderBoundingBox();
}
void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
//	;
	CGameObject::Update(dt);
	//CollisonGroundWall(dt, coObjects);
}
void CEnemy::CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vy += SIMON_GRAVITY * dt;
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	// No collision occured, proceed normally

	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		// block 
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			auto object = e->obj;
			if (object->tag == GROUND)
			{
				
				

				x += min_tx * dx + nx * 0.2f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
				y += min_ty * dy + ny * 0.2;
	
				if (ny == 1)
				{
					y += dy;
				}
			
				if (nx != 0) vx = 0;
				vy = 0;
				IsJumping = false;
				//IsEndGround = false;
				if ((object->x + 8 > x) || ((object->x+ object->width) - 8 < x ) )
				{
					IsEndGround = true;
				}
			}
		}
		

	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}