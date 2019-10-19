#include "Simon.h"

CMario * CMario::_instance = NULL;
CMario::CMario() :CGameObject()
{
	AddAnimation(400, STANDING_RIGHT);		// idle right big
	AddAnimation(401, STANDING_LEFT);		// idle left big

	AddAnimation(500, WALKING_RIGHT);		// walk right big
	AddAnimation(501, WALKING_LEFT);		// walk left big

	AddAnimation(508, JUMPING_LEFT);		//jump left
	AddAnimation(509, JUMPING_RIGHT);	//jump right
	AddAnimation(400, FALLING_RIGHT);
	AddAnimation(401, FALLING_LEFT);

	AddAnimation(510, DOWNING_RIGHT);	 //down right
	AddAnimation(511, DOWNING_LEFT);		//down left

	AddAnimation(512, HITTING_STAND_LEFT);
	AddAnimation(513, HITTING_STAND_RIGHT);

	AddAnimation(514, HITTING_DOWN_RIGHT);
	AddAnimation(515, HITTING_DOWN_LEFT);
}
CMario * CMario::GetInstance()
{
	if (_instance == NULL)
		_instance = new CMario();
	return _instance;
}
void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	// Simple fall down
	
	// Calculate dx, dy 

	CGameObject::Update(dt);
	vy += MARIO_GRAVITY *dt;
	state->Update();

	if (y > 100)
	{
		y = 100;
		vy = 0;

		IsJumping = false;
	}


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

		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty * dy + ny * 0.4f;


		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;
		// Collision logic with Goombas
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
		}
	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];

}

void CMario::Render()
{
	int alpha = 255;
	CurAnimation->Render(x, y, alpha);
	RenderBoundingBox();
}

void CMario::ChangeAnimation(PlayerState * newState)
{
	delete state;
	state = newState;
	state->StateName = newState->StateName;
	CurAnimation = animations[newState->StateName];
}
void CMario::Revival()
{
	cam = CAMERA;
	UsingWhip = false;
	allow[JUMPING] = true;
	allow[WALKING] = true;
	SetPosition(0.0f, 0);
	nx = 1;
	ChangeAnimation(new PlayerStandingState());
}
void CMario::OnKeyDown(int key)
{
	switch (key)
	{
	case DIK_SPACE:
	{
		if (!IsJumping)
		{
			if ((keyCode[DIK_RIGHT]))

			{
				vx = MARIO_WALKING_SPEED;
				nx = 1;
				ChangeAnimation(new PlayerJumpingState());
			}
			else if ((keyCode[DIK_LEFT]))
			{
				vx = -MARIO_WALKING_SPEED;
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
		if (!IsHitting)
		{
			ChangeAnimation(new PlayerHittingState());
		}
		break;

	}
	}
	
}
void CMario::OnKeyUp(int key)
{

}

void CMario::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + MARIO_BIG_BBOX_WIDTH;
	bottom = y + MARIO_BIG_BBOX_HEIGHT;

}
