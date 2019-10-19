#include "PlayerDowningState.h"


PlayerDowningState::PlayerDowningState()
{
	player->vx = 0;
	player->ny = -1;

	if (player->nx > 0)
	{
		StateName = DOWNING_RIGHT;
	}
	else
		StateName = DOWNING_LEFT;
}

void PlayerDowningState::Update()
{
	this->HandleKeyBoard();
}
void PlayerDowningState::HandleKeyBoard()
{
	if (keyCode[DIK_LEFT] && keyCode[DIK_DOWN])
	{
		player->nx = -1;
		player->ChangeAnimation(new PlayerDowningState());
	}
	else if (keyCode[DIK_RIGHT] && keyCode[DIK_DOWN])
	{
		player->nx = 1;
		player->ChangeAnimation(new PlayerDowningState());

	}
	else if (keyCode[DIK_RIGHT]||keyCode[DIK_LEFT])
	{
		player->ChangeAnimation(new PlayerWalkingState());
	}
	
	else if (!(keyCode[DIK_DOWN]))
		player->ChangeAnimation(new PlayerStandingState());

}


PlayerDowningState::~PlayerDowningState()
{
	
}
