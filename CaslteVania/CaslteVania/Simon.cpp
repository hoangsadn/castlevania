#include "Simon.h"
#include "PlayerState.h"
#include "PlayerWalkingState.h"
#include "PlayerStandingState.h"
#include "PlayerHittingState.h"
#include "PlayerJumpingState.h"
#include "PlayerReciveItemState.h"
#include "PlayerHurtingState.h"
#include "PlayerDeadState.h"
#include "Brick.h"
#include "CheckPoint.h"
#include "Whip.h"
#define SIMON_POS_REPAWN_3 3084
#define SIMON_POS_REPAWN_4 4105
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

	AddAnimation(532, DEAD_LEFT);
	AddAnimation(533, DEAD_RIGHT);

	AddAnimation(534, STANDING_INTRO);
	tag = PLAYER;

}
CSimon * CSimon::GetInstance()
{
	if (_instance == NULL)
		_instance = new CSimon();
	return _instance;
}
void CSimon::HandleObject(LPGAMEOBJECT object)
{ 
	if (object != NULL)
	{
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
			case AXE:
				weaponTypeCarry = AXE;
				break;
			case HOLLY_WATER:
				weaponTypeCarry = HOLLY_WATER;
				break;
			case STOP_WATCH:
				weaponTypeCarry = STOP_WATCH;
				break;
			case MONEY_BLUE:
				point += 400;
				break;
			case MONEY_RED:
				point += 1000;
				break;
			case MONEY_WHITE:
				point += 700;
				break;
			case INVINCIBILITY:
				Invincibility = true;
				untouchTime = GetTickCount();
				break;
			case ROSARY:
				flashtime = GetTickCount();
				beta = 0;
				break;
			case DOUBLE_SHOT:
				DoubleShot = 2;
				break;
			case ROAST:
				health += 5;
				break;
			default:
				break;

			}
		}
		else if (object->tag == BOX)
		{
			switch (object->type)
			{
			case CHECKPOINT: case DOOR:
			{
				auto checkpoint = (CCheckPoint*)object;
				object->isDead = true;
				if (checkpoint->id == 2 || checkpoint->id == 7)
					IsTouchDoor = true;
				break;
			}
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
			default:
				break;
			}

		}
		else if (object->tag == ENEMY)
		{
			switch (object->type)
			{
			case BAT:
			{
				object->isBuring = true;
				break;
			}
			default:
				break;
			}
			if (untouchTime == 0 && !IsDead)
			{

				if (health == 1)
				{
					IsDead = true;
					ChangeAnimation(new PlayerDeadState());
				}
				else if (!IsOnStair)
				{
					ChangeAnimation(new PlayerHurtingState());
				}
				else untouchTime = GetTickCount();
				health--;
			}

		}
	}
}
void CSimon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects )
{
	
	// Calculate dx, dy 
	CGameObject::Update(dt);
	// Simple fall down
	if (!IsOnStair && !IsOnIntro)
		vy += SIMON_GRAVITY * dt;

	//jump to hole and dead 
	
	//update state
	state->Update();
	if (GetTickCount() - countTime > 1000 && !freeze)
	{
		playTime--;
		countTime = GetTickCount();
	}
	


	if (Invincibility)
	{
		//get Invincibility items , untouch 10s
		if (GetTickCount() - untouchTime > SIMON_INVINCIBILITY_TIME)
		{
			untouchTime = 0;
			Invincibility = false;
		}
	} 
		// hurting time
	else if (GetTickCount() - untouchTime > SIMON_UNTOUCHABLE_TIME)
		untouchTime = 0;
	if (GetTickCount() - flashtime > TIME_FLASH_SCREEN)
		flashtime = 0;
	if (!IsOnStair)
	{
		IsOnFootStair = false;
		IsOnTopStair = false;
	}
	if (!IsOnIntro) {
		if ((y > CAMERA->y + CAMERA->mHeight || playTime == 1)&&!IsDead)
		{
			IsDead = true;
			ChangeAnimation(new PlayerDeadState());
		}
		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();


		CalcPotentialCollisions(coObjects, coEvents);
		
		if (coEvents.size() == 0)
		{

			//clac obj with AABB
			for (UINT i = 0; i < coObjects->size(); i++)
			{
				if (IsCollisionAABB(GetRect(), coObjects->at(i)->GetRect()))
				{
					HandleObject(coObjects->at(i));
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

				HandleObject(e->obj);

				// clean up collision events
				for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
			}
		}
	}
}
void CSimon::Render()
{

	if (flashtime != 0)
	{
		beta = beta == 255 ? 0 : 255;
		LPDIRECT3DDEVICE9 d3ddv = GAME->GetDirect3DDevice();
		LPDIRECT3DSURFACE9 bb = GAME->GetBackBuffer();
		d3ddv->ColorFill(bb, NULL, D3DCOLOR_XRGB(beta, beta, beta));
		GAMELOG("alpha %d", alpha);
	}
		
	if (untouchTime != 0)
		alpha = alpha == 255 ? 115 : 255;
	else 
		alpha = 255;
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
	cam->map = Checkpoint;
	switch (Checkpoint)
	{
	case 1:
		SetPosition(BEGIN_MAP1, 0);
		break;
	case 2:
		SetPosition(BEGIN_MAP2, 0);
		break;
	case 3:
		SetPosition(SIMON_POS_REPAWN_3, 0);
		break;
	case 5:
		SetPosition(SIMON_POS_REPAWN_4, 0);
		break;
	default:
		break;
	}
	allow[JUMPING] = true;
	allow[WALKING] = true;
	allow[THROWING] = true;
	allow[HITTING] = true;
	IsTouchDoor = false;
	IsWalkingComplete = false;
	untouchTime = 0;
	IsDead = false;
	IsOnIntro = false;
	DoubleShot = 1;
	life = 3;
	nx = 1;
	whipType = 1;
	bullet = 100;
	numWeapon = 0;
	playTime = 300;
	weaponTypeCarry = STOP_WATCH;
	Invincibility = false;
	freeze = false;
	health = 2;
	bossHealth = 10;
	ChangeAnimation(new PlayerStandingState());
	countTime = GetTickCount();
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
	{
		if (keyCode[DIK_UP] && bullet != 0 && allow[THROWING] && weaponTypeCarry != NOTHING && !IsOnStair && numWeapon < DoubleShot)
		{
			bullet--;
			ChangeAnimation(new PlayerHittingState());
			if (weaponTypeCarry == KNIFE || weaponTypeCarry == AXE || weaponTypeCarry == HOLLY_WATER)
			{
				numWeapon++;
			}
			
			GAMELOG("THORWING %d", numWeapon);
			IsThrowing = true;
			break;
		}
		else if (allow[HITTING])
		{
			IsHitting = true;
			ChangeAnimation(new PlayerHittingState());
			break;
		}
		break;
	}
	case DIK_1:
	{
		Checkpoint = 1;
		Revival();
		break;
	}
	case DIK_2:
	{
		SetPosition(1350, 200);
		break;
	}
	case DIK_3:
	{
		cam->map = 2;
		Checkpoint = 2;
		SetPosition(0, 0);
		break;
	}
	case DIK_4:
	{
		cam->map = 3;
		Checkpoint = 3;
		SetPosition(SIMON_POS_REPAWN_3, 0);
		break;
		
	}
	case DIK_5:
	{
		cam->map = 4;
		Checkpoint = 3;
		SetPosition(BEGIN_MAP4, MAP_4_Y);
		break;
	}
	case DIK_6:
	{
		cam->map = 5;
		Checkpoint = 5;
		SetPosition(SIMON_POS_REPAWN_4+1000, 0);
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
		left = x + SIMON_EDIT_BBOX_X;
		top = y + SIMON_EDIT_BBOX_Y;
		right = x + SIMON_BIG_BBOX_WIDTH;
		bottom = y + SIMON_BIG_BBOX_HEIGHT;
	}
	else
	{
		left = x + SIMON_EDIT_BBOX_X;
		top = y + SIMON_EDIT_BBOX_Y;
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
		
		x += dx;
		y += dy;
		//GAMELOG("chay truoc %f %f ",x,y);


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
				IsJumping = true;
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

