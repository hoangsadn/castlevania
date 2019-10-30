#include "PlayerDowningState.h"


PlayerDowningState::PlayerDowningState()
{
	PrevState = player->state->StateName;
	player->vx = 0;
	player->ny = -1;
	if (player->stateBoundingBox != SIMON_SMALL_BOUNDING_BOX)
		player->y += 17;

	player->stateBoundingBox = SIMON_SMALL_BOUNDING_BOX;
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
		player->y -= 17;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	
	else if (!(keyCode[DIK_DOWN]))
	{
		player->y -= 17;
		player->ChangeAnimation(new PlayerStandingState());
	}
}


PlayerDowningState::~PlayerDowningState()
{
	
}
