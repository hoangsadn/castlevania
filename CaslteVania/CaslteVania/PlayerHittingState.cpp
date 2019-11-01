#include "PlayerHittingState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpingState.h"


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
	player->vx = 0;
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
		}

	}

}

PlayerHittingState::~PlayerHittingState()
{
}
