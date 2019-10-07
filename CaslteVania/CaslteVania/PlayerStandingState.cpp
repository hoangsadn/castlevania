#include "PlayerStandingState.h"



PlayerStandingState::PlayerStandingState()
{
	player->vx = 0;

	if (player->nx > 0)
	{
		mStateName = STANDING_RIGHT;
	}
	else mStateName = STANDING_LEFT;
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
	if (keyCode[DIK_LEFT] || keyCode[DIK_RIGHT])
	{
		player->ChangeAnimation(new PlayerWalkingState());
	}
	
}