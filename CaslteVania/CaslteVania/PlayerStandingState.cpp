#include "PlayerStandingState.h"
#include "PlayerWalkingStairState.h"

PlayerStandingState::PlayerStandingState()
{

	player->allow[JUMPING] = true;
	player->allow[DOWNING] = true;
	player->allow[WALKING] = true;
	player->allow[HITTING] = true;
	player->allow[THROWING] = true;

	player->vx = 0;
	player->ny = 1;
	player->IsJumping = false;
	player->IsHitting = false;
	
	player->IsOnStair = false;
	
	if (player->nx > 0)
	{
		StateName = STANDING_RIGHT;
	}
	else StateName= STANDING_LEFT;
	player->stateBoundingBox = SIMON_BIG_BOUNDING_BOX;

}


PlayerStandingState::~PlayerStandingState()
{
}

void PlayerStandingState::Update()
{
	this->HandleKeyBoard();
}

void PlayerStandingState::HandleKeyBoard()
{
	if (keyCode[DIK_LEFT] && keyCode[DIK_RIGHT])
	{
		player->ChangeAnimation(new PlayerStandingState());
	}
	else if (keyCode[DIK_LEFT] || keyCode[DIK_RIGHT])
	{
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else if (keyCode[DIK_DOWN] && player->IsOnTopStair)
	{
		if (player->allow[STAIRING])
			player->ChangeAnimation(new PlayerWalkingStairState());
		else
			player->ChangeAnimation(new PlayerWalkingState(player->posOfStair));
	}
	else if (keyCode[DIK_UP] && player->IsOnFootStair)
	{
		
		if (player->allow[STAIRING])
			player->ChangeAnimation(new PlayerWalkingStairState());
		else 
			player->ChangeAnimation(new PlayerWalkingState(player->posOfStair));
	}
	else if (keyCode[DIK_DOWN])
	{
		player->ChangeAnimation(new PlayerDowningState());
	}
	
}