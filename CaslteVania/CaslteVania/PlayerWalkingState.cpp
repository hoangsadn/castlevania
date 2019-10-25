#include "PlayerWalkingState.h"



PlayerWalkingState::PlayerWalkingState()
{
	player->allow[JUMPING] = true;
	player->ny = 1;
	if (player->nx > 0)
	{
		StateName = WALKING_RIGHT;
	}
	else
	{
		StateName = WALKING_LEFT;
	}
	player->stateBoundingBox = SIMON_BIG_BOUNDING_BOX;
}


PlayerWalkingState::~PlayerWalkingState()
{

}

void PlayerWalkingState::Update()
{
	this->HandleKeyBoard();
}
void PlayerWalkingState::HandleKeyBoard()
{

	if (keyCode[DIK_DOWN])
	{
		player->ChangeAnimation(new PlayerDowningState());
	}
	else if (keyCode[DIK_LEFT] && keyCode[DIK_RIGHT])
	{
		player->ChangeAnimation(new PlayerStandingState());
	}
	else if (keyCode[DIK_LEFT])
	{
		player->vx = -SIMON_WALKING_SPEED;
		player->nx = -1;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else if (keyCode[DIK_RIGHT])
	{
		player->vx = SIMON_WALKING_SPEED;
		player->nx = 1;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else
	{
		player->ChangeAnimation(new PlayerStandingState);
	}
}
