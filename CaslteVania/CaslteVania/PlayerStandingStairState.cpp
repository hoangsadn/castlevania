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

	player->vx = 0;
	player->vy = 0;
	//player->ny = 1;
	player->IsJumping = false;
	player->IsHitting = false;

	switch (PrevState)
	{
	
	case WALKING_STAIR_UP_RIGHT:
		StateName = STANDING_STAIR_UP_RIGHT;
		player->nx = 1;
		break;
	case WALKING_STAIR_UP_LEFT:
		StateName = STANDING_STAIR_UP_LEFT;
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
		player->ChangeAnimation(new PlayerWalkingStairState());

}