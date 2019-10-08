#include "PlayerWalkingState.h"



PlayerWalkingState::PlayerWalkingState()
{
	if (player->nx > 0)
	{
		StateName = WALKING_RIGHT;
	}
	else
	{
		StateName = WALKING_LEFT;
	}
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
		player->vx = -MARIO_WALKING_SPEED;
		player->nx = -1;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else if (keyCode[DIK_RIGHT])
	{
		player->vx = MARIO_WALKING_SPEED;
		player->nx = 1;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else
	{
		player->ChangeAnimation(new PlayerStandingState);
	}
}
