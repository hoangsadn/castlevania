#include "PlayerWalkingState.h"



PlayerWalkingState::PlayerWalkingState()
{

	if (keyCode[DIK_RIGHT]&& !keyCode[DIK_LEFT]) 
		mStateName = WALKING_RIGHT;
	else if (keyCode[DIK_LEFT] && !keyCode[DIK_RIGHT])
		mStateName = WALKING_LEFT;

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
	if (keyCode[DIK_LEFT])
	{
		player->vx = -MARIO_WALKING_SPEED;
	}
	else if (keyCode[DIK_RIGHT])
	{
		player->vx = MARIO_WALKING_SPEED;
	}
	else
	{
		player->ChangeAnimation(new PlayerStandingState);
	}
}
