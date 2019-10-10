#include "PlayerHittingState.h"



PlayerHittingState::PlayerHittingState()
{
	player->IsHitting = true;
	PrevAnimation = player->state->StateName;
	if (player->nx > 0)
		StateName = HITTING_STAND_RIGHT;
	else
		StateName = HITTING_STAND_LEFT;
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

		switch (PrevAnimation)
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
		}

	}

}

PlayerHittingState::~PlayerHittingState()
{
}
