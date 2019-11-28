#include "PlayerHittingState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpingState.h"
#include "PlayerWalkingStairState.h"
#include "PlayerStandingStairState.h"
PlayerHittingState::PlayerHittingState()
{
	player->allow[JUMPING] = false;
	player->allow[THROWING] = false;
	player->allow[HITTING] = false;
	
	PrevState = player->state->StateName;
	
	if (player->nx > 0)
	{
		if (player->ny < 0)
			StateName = HITTING_DOWN_RIGHT;
		else
			StateName = HITTING_STAND_RIGHT;
	}
	else
	{
		if (player->ny < 0)
			StateName = HITTING_DOWN_LEFT;
		else
			StateName = HITTING_STAND_LEFT;
	}
	if (player->IsOnStair)
	{
		player->vy = 0;
		switch (player->stairDirection)
		{

		case 1:
			StateName = HITTING_STAIR_UP_RIGHT;
			player->nx = 1;
			break;
		case 2:
		{
			StateName = HITTING_STAIR_UP_LEFT;
			player->nx = -1;
			break;
		}
		case -1:
		{
			StateName = HITTING_STAIR_DOWN_RIGHT;
			player->nx = 1;
			break;
		}
		case -2:
		{
			StateName = HITTING_STAIR_DOWN_LEFT;
			player->nx = -1;
			break;
		}
		}
	}
	player->vx = 0;
	if (PrevState == DOWNING_LEFT || PrevState == DOWNING_RIGHT)
	{
		player->stateBoundingBox = SIMON_SMALL_BOUNDING_BOX;
	}else
	player->stateBoundingBox = SIMON_BIG_BOUNDING_BOX;

}

void PlayerHittingState::HandleKeyBoard()
{

}

void PlayerHittingState::Update()
{
	this->HandleKeyBoard();
	if (player->CurAnimation->isLastFrame)
	{
		player->allow[HITTING] = true;
		player->allow[THROWING] = true;
		player->CurAnimation->isLastFrame = false;
		player->CurAnimation->currentFrame = -1; //switch animation in the last frame , must return to defaut
		switch (PrevState)
		{
		case WALKING_LEFT : case WALKING_RIGHT : case STANDING_LEFT : case STANDING_RIGHT:
			player->ChangeAnimation(new PlayerStandingState());
			return;
		case JUMPING_LEFT: case JUMPING_RIGHT:
			if (player->vy >= 0)
			{
				player->ChangeAnimation(new PlayerFallingState());
				return;
			}
			else 
			{
				player->ChangeAnimation(new PlayerJumpingState());
				return;
			}
		case DOWNING_LEFT: case DOWNING_RIGHT:
			player->ChangeAnimation(new PlayerDowningState());
			return;

		case FALLING_LEFT: case FALLING_RIGHT:
			player->ChangeAnimation(new PlayerFallingState());
			return;
		case WALKING_STAIR_DOWN_LEFT: case WALKING_STAIR_DOWN_RIGHT: case WALKING_STAIR_UP_LEFT: case WALKING_STAIR_UP_RIGHT:
			player->ChangeAnimation(new PlayerWalkingStairState());
			return;
		case STANDING_STAIR_DOWN_LEFT: case STANDING_STAIR_DOWN_RIGHT: case STANDING_STAIR_UP_LEFT: case STANDING_STAIR_UP_RIGHT:
		{
			player->ChangeAnimation(new PlayerStandingStairState());
			return;
		}
		default:
			player->ChangeAnimation(new PlayerStandingState());
			return;
		}

	}

}

PlayerHittingState::~PlayerHittingState()
{
}
