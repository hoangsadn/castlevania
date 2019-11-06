#include "Simon.h"
#include "PlayerState.h"
#include "PlayerWalkingState.h"
#include "PlayerStandingState.h"
#include "PlayerHittingState.h"
#include "PlayerJumpingState.h"
#include "PlayerReciveItemState.h"
#include "PlayerHurtingState.h"
#include "Brick.h"
#include "Whip.h"
CSimon * CSimon::_instance = NULL;
CSimon::CSimon() :CGameObject()
{
	AddAnimation(400, STANDING_RIGHT);		// idle right big
	AddAnimation(401, STANDING_LEFT);		// idle left big

	AddAnimation(500, WALKING_RIGHT);		// walk right big
	AddAnimation(501, WALKING_LEFT);		// walk left big

	AddAnimation(508, JUMPING_LEFT);		//jump left
	AddAnimation(509, JUMPING_RIGHT);		//jump right
	AddAnimation(400, FALLING_RIGHT);
	AddAnimation(401, FALLING_LEFT);

	AddAnimation(510, DOWNING_RIGHT);	 //down right
	AddAnimation(511, DOWNING_LEFT);		//down left

	AddAnimation(512, HITTING_STAND_LEFT);
	AddAnimation(513, HITTING_STAND_RIGHT);

	AddAnimation(514, HITTING_DOWN_RIGHT);
	AddAnimation(515, HITTING_DOWN_LEFT);

	AddAnimation(516, RECIVE_RIGHT);
	AddAnimation(517, RECIVE_LEFT);

	AddAnimation(518, STANDING_STAIR_UP_RIGHT);
	AddAnimation(519, STANDING_STAIR_UP_LEFT);

	AddAnimation(520, WALKING_STAIR_UP_RIGHT);
	AddAnimation(521, WALKING_STAIR_UP_LEFT);

	AddAnimation(522, STANDING_STAIR_DOWN_RIGHT);
	AddAnimation(523, STANDING_STAIR_DOWN_LEFT);

	AddAnimation(524, WALKING_STAIR_DOWN_RIGHT);
	AddAnimation(525, WALKING_STAIR_DOWN_LEFT);

	AddAnimation(526, HITTING_STAIR_UP_RIGHT);
	AddAnimation(527, HITTING_STAIR_UP_LEFT);
	AddAnimation(528, HITTING_STAIR_DOWN_RIGHT);
	AddAnimation(529, HITTING_STAIR_DOWN_LEFT);

	AddAnimation(530, HURTING_RIGHT);
	AddAnimation(531, HURTING_LEFT);

	tag = PLAYER;

}
CSimon * CSimon::GetInstance()
{
	if (_instance == NULL)
		_instance = new CSimon();
	return _instance;
}
void CSimon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{

	// Calculate dx, dy 
	CGameObject::Update(dt);
	// Simple fall down
	if (!IsOnStair)
		vy += SIMON_GRAVITY * dt;

	//update state
	state->Update();


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();


	CalcPotentialCollisions(coObjects, coEvents);

	if (GetTickCount() - untouchTime > SIMON_UNTOUCHABLE_TIME)
	{
		untouchTime = 0;
	}
	if (!IsOnStair)		
	{
		IsOnFootStair = false;
		IsOnTopStair = false;
	}
	if (coEvents.size() == 0)
	{
		
		//clac obj with AABB
		for (UINT i = 0; i < coObjects->size(); i++)
		{
			if (IsCollisionAABB(GetRect(), coObjects->at(i)->GetRect()))
			{
				if (coObjects->at(i)->tag == ITEM)
				{
					coObjects->at(i)->isDead = true;
					switch (coObjects->at(i)->type)
					{
					case MORNING_STAR:
						whipType = whipType != 3 ? whipType + 1 : 3;
						ChangeAnimation(new PlayerReciveItemState());
						break;
					case BIG_HEART:
						bullet += 5;
						break;
					case SMALL_HEART:
						bullet++;
						break;
					case KNIFE:
						weaponTypeCarry = KNIFE;
						break;
					}
				}
				else if (coObjects->at(i)->tag == BOX)
				{
					switch (coObjects->at(i)->type)
					{
					case STAIR_BOTTOM_RIGHT:
						IsOnFootStair = true;
						stairDirection = 1;
						break;
					case STAIR_BOTTOM_LEFT:
						IsOnFootStair = true;
						stairDirection = 2;
						break;
					case STAIR_TOP_RIGHT:
						IsOnTopStair = true;
						stairDirection = -1;
						break;
					case STAIR_TOP_LEFT:
						IsOnTopStair = true;
						stairDirection = -2;
						break;
					}
				}
				
			}

		}
	}
	else {

		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// Collision logic with SweepAABB
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			auto object = e->obj;
			if (object->tag == ITEM)
			{
				object->isDead = true;
				switch (object->type)
				{
				case MORNING_STAR:
					whipType = whipType != 3 ? whipType + 1 : 3;
					ChangeAnimation(new PlayerReciveItemState());
					break;
				case BIG_HEART:
					bullet += 5;
					break;
				case SMALL_HEART:
					bullet++;
					break;
				case KNIFE:
					weaponTypeCarry = KNIFE;
					break;
				}
			}
			else if (object->tag == BOX)
			{
				switch (object->type)
				{
				case CHECKPOINT:
					object->isDead = true;
					break;

				case STAIR_BOTTOM_RIGHT:
					IsOnFootStair = true;
					posOfStair = object->x;
					stairDirection = 1;
					break;
				case STAIR_BOTTOM_LEFT:
					IsOnFootStair = true;
					posOfStair = object->x;
					stairDirection = 2;
					break;
				case STAIR_TOP_RIGHT:
					IsOnTopStair = true;
					posOfStair = object->x;
					stairDirection = -1;
					break;
				case STAIR_TOP_LEFT:
					IsOnTopStair = true;
					posOfStair = object->x;
					stairDirection = -2;
					break;
				}

			}
			else if (object->tag == ENEMY)
			{
				if (untouchTime == 0)
				{
					ChangeAnimation(new PlayerHurtingState());
					IsJumping = true;
				}
			}

			// clean up collision events

			for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];

		}
	}
}
void CSimon::Render()
{
	int alpha = 255;
	CurAnimation->Render(x, y, alpha);
	RenderBoundingBox();
}

void CSimon::ChangeAnimation(PlayerState * newState)
{
	delete state;
	state = newState;
	state->StateName = newState->StateName;
	CurAnimation = animations[newState->StateName];
}
void CSimon::Revival()
{
	cam = CAMERA;
	allow[JUMPING] = true;
	allow[WALKING] = true;
	allow[THROWING] = true;
	allow[HITTING] = true;
	untouchTime = 0;
	SetPosition(0.0f, 0);
	nx = 1;
	whipType = 1;
	bullet = 5;
	weaponTypeCarry = KNIFE;
	ChangeAnimation(new PlayerStandingState());
}
void CSimon::OnKeyDown(int key)
{
	switch (key)
	{
	case DIK_SPACE:
	{
		if (!IsJumping && allow[JUMPING])
		{
			if ((keyCode[DIK_RIGHT]))
			{
				vx = SIMON_WALKING_SPEED;
				nx = 1;
				ChangeAnimation(new PlayerJumpingState());
			}
			else if ((keyCode[DIK_LEFT]))
			{
				vx = -SIMON_WALKING_SPEED;
				nx = -1;
				ChangeAnimation(new PlayerJumpingState());
			}
			else
			{
				ChangeAnimation(new PlayerJumpingState());
			}
		}
		break;
	}
	case DIK_C:

		if (keyCode[DIK_UP] && bullet != 0 && allow[THROWING] && weaponTypeCarry != NOTHING && !IsOnStair)
		{
			bullet--;
			ChangeAnimation(new PlayerHittingState());
			IsThrowing = true;
			break;
		}
		else if (allow[HITTING])
		{
			IsHitting = true;
			ChangeAnimation(new PlayerHittingState());
			break;
		}
	}


}
void CSimon::OnKeyUp(int key)
{

}

void CSimon::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (stateBoundingBox == SIMON_BIG_BOUNDING_BOX)
	{
		left = x + 15;
		top = y + 4;
		right = x + SIMON_BIG_BBOX_WIDTH;
		bottom = y + SIMON_BIG_BBOX_HEIGHT;
	}
	else
	{
		left = x + 15;
		top = y + 4;
		right = x + SIMON_SMALL_BBOX_WIDTH;
		bottom = y + SIMON_SMALL_BBOX_HEIGHT;
	}

}
void CSimon::CollisonGroundWall(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	// No collision occured, proceed normally
	

	if (coEvents.size() == 0)
	{
		//if (CurAnimation->isLastFrame )
		//	GAMELOG("%f %f", x, y);
		x += dx;
		y += dy;
		

	}
	else
	{

		// block 
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		if (!IsOnStair)
		{
			IsJumping = false;
			
			x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
			y += min_ty * dy + ny * 0.4f;
			if (ny == 1)
			{
 				y += dy;
			}
			if (nx != 0) vx = 0;
			if (ny == -1) vy = 0;
		}
		else
		{
			x += dx; 
			y += dy;
		}
		

	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

