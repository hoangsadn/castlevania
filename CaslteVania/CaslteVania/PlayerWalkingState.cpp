#include "PlayerWalkingState.h"



PlayerWalkingState::PlayerWalkingState(DWORD timeFinish)
{
	timeWalk = GetTickCount();
	this->timeFinish = timeFinish;
	player->allow[JUMPING] = true;
	player->allow[STAIRING] = false;
	player->ny = 1;
	if (player->nx > 0)
	{
		StateName = WALKING_RIGHT;
		player->vx = SIMON_WALKING_SPEED;
	}
	else
	{
		StateName = WALKING_LEFT;
		player->vx = -SIMON_WALKING_SPEED;
	}
	player->stateBoundingBox = SIMON_BIG_BOUNDING_BOX;
}


PlayerWalkingState::~PlayerWalkingState()
{

}
void PlayerWalkingState::walking(DWORD dt)
{
	GAMELOG("x %f", player->x);
	if (player->x < dt)
	{
		
		if (player->x > dt - 10)
		{
			//get in the position
			player->allow[STAIRING] = true;
			player->IsWalkingComplete = true;
			player->ChangeAnimation(new PlayerStandingState());
			return;
		}
		player->nx = 1;
		player->ChangeAnimation(new PlayerWalkingState(dt));
	}
	else
	{
		if (player->x < dt + 10)
		{
			//get in the position
			player->allow[STAIRING] = true;
			player->IsWalkingComplete = true;
			player->ChangeAnimation(new PlayerStandingState());
			return;
		}
		player->nx = -1;
		player->ChangeAnimation(new PlayerWalkingState(dt));
		
		
	}
}
void PlayerWalkingState::Update()
{
	if (timeFinish != 0)
		walking(timeFinish);
	else 
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
		
		player->nx = -1;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else if (keyCode[DIK_RIGHT])
	{
		
		player->nx = 1;
		player->ChangeAnimation(new PlayerWalkingState());
	}
	else
	{
		player->ChangeAnimation(new PlayerStandingState);
	}
}
