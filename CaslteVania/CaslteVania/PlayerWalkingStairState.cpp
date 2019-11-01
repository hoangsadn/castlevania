#include "PlayerWalkingStairState.h"

#include "PlayerWalkingState.h"



PlayerWalkingStairState::PlayerWalkingStairState()
{
	switch (player->stairDirection)
	{
	case 1:
		StateName = WALKING_STAIR_UP_RIGHT;
		player->vx = SIMON_WALKING_SPEED;
		player->vy = -SIMON_WALKING_SPEED;
		break;
	case 2: 
	{
		StateName = WALKING_STAIR_UP_LEFT;
		player->vx = -SIMON_WALKING_SPEED;
		player->vy = -SIMON_WALKING_SPEED;
		break;
	}
	default:
		StateName = WALKING_STAIR_UP_RIGHT;
		break;
	}
	player->IsOnStair = true;
}


PlayerWalkingStairState::~PlayerWalkingStairState()
{

}

void PlayerWalkingStairState::Update()
{
	this->HandleKeyBoard();
	if (player->stairDirection == -1 || player->stairDirection == -2)
	if(player->IsOnTopStair)
	{
		player->ChangeAnimation(new PlayerStandingState());
		return;
	}
	
}
void PlayerWalkingStairState::HandleKeyBoard()
{
	if (player->IsOnStair)
		if (!keyCode[DIK_UP])
			player->ChangeAnimation(new PlayerStandingStairState());
}
