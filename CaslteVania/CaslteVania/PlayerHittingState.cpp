#include "PlayerHittingState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpingState.h"


PlayerHittingState::PlayerHittingState()
{
	player->IsHitting = true;
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

}

void PlayerHittingState::HandleKeyBoard()
{

}

void PlayerHittingState::Update()
{
	this->HandleKeyBoard();
	if (player->CurAnimation->isLastFrame)
	{
		player->IsHitting = false;
		player->CurAnimation->isLastFrame = false;
		player->CurAnimation->currentFrame = -1; //switch animation in the last frame , must return to defaut
		switch (PrevState)
		{
		case WALKING_LEFT : case WALKING_RIGHT : case STANDING_LEFT : case STANDING_RIGHT:
			player->ChangeAnimation(new PlayerStandingState());
			return;
		case JUMPING_LEFT: case JUMPING_RIGHT:
			player->ChangeAnimation(new PlayerJumpingState());
			return;
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
