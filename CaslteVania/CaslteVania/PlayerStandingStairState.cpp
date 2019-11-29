#include "PlayerStandingStairState.h"
#include "Simon.h"
#include "PlayerWalkingStairState.h"
#include "PlayerStandingState.h"

PlayerStandingStairState::PlayerStandingStairState()
{
	PrevState = player->state->StateName;
	player->allow[JUMPING] = false;
	player->allow[DOWNING] = false;
	player->allow[WALKING] = false;
	player->allow[HITTING] = true;
	player->allow[THROWING] = true;
	player->IsWalkingComplete = false;
	player->vx = 0;
	player->vy = 0;

	player->IsJumping = false;
	player->IsHitting = false;

	switch (PrevState)
	{
	
	case WALKING_STAIR_UP_RIGHT: case HITTING_STAIR_UP_RIGHT:
		StateName = STANDING_STAIR_UP_RIGHT;
		player->nx = 1;
		break;
	case WALKING_STAIR_UP_LEFT: case HITTING_STAIR_UP_LEFT:
		StateName = STANDING_STAIR_UP_LEFT;
		player->nx = -1;
		break;
	case WALKING_STAIR_DOWN_RIGHT: case HITTING_STAIR_DOWN_RIGHT:
		StateName = STANDING_STAIR_DOWN_RIGHT;
		player->nx = 1;
		break;
	case WALKING_STAIR_DOWN_LEFT: case HITTING_STAIR_DOWN_LEFT:
		StateName = STANDING_STAIR_DOWN_LEFT;
		player->nx = -1;
		break;
	}
	player->IsOnStair = true;
	player->stateBoundingBox = SIMON_BIG_BOUNDING_BOX;

}


PlayerStandingStairState::~PlayerStandingStairState()
{
}

void PlayerStandingStairState::Update()
{
	
	this->HandleKeyBoard();
}

void PlayerStandingStairState::HandleKeyBoard()
{
	if (keyCode[DIK_UP])
	{
		if (player->stairDirection == -1)
		{
			player->IsOnFootStair = true;
			player->IsOnTopStair = false;
			player->stairDirection = 2;
		}
		else if (player->stairDirection == -2)
		{
			player->IsOnFootStair = true;
			player->IsOnTopStair = false;
			player->stairDirection = 1;
		}
		player->ChangeAnimation(new PlayerWalkingStairState());
	}
	else if (keyCode[DIK_DOWN])
	{
		if (player->stairDirection == 1)
		{
			player->stairDirection = -2;
			player->IsOnFootStair = false;
			player->IsOnTopStair = true;

		}
		else if (player->stairDirection == 2)
		{
			player->stairDirection = -1;
			player->IsOnFootStair = false;
			player->IsOnTopStair = true;
		}
		
		player->ChangeAnimation(new PlayerWalkingStairState());
	}

}