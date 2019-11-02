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
		player->nx = 1;
		break;
	case 2: 
	{
		StateName = WALKING_STAIR_UP_LEFT;
		player->vx = -SIMON_WALKING_SPEED;
		player->vy = -SIMON_WALKING_SPEED;
		player->nx = -1;
		break;
	}
	case -1:
	{
		StateName = WALKING_STAIR_DOWN_RIGHT;
		player->vx = SIMON_WALKING_SPEED;
		player->vy = SIMON_WALKING_SPEED;
		player->nx = 1;
		break;
	}
	case -2:
	{
		StateName = WALKING_STAIR_DOWN_LEFT;
		player->vx = -SIMON_WALKING_SPEED;
		player->vy = SIMON_WALKING_SPEED;
		player->nx = -1;
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
	
	if ((player->stairDirection == -1 || player->stairDirection == -2) && player->IsOnFootStair)
	{
		player->y -= 3;
		player->ChangeAnimation(new PlayerStandingState());
		return;
	}
	else if ((player->stairDirection == 1 || player->stairDirection == 2) && player->IsOnTopStair)
	{
		
		player->ChangeAnimation(new PlayerStandingState());
		return;
	}
	this->HandleKeyBoard();
}
void PlayerWalkingStairState::HandleKeyBoard()
{
	if (keyCode[DIK_UP])
	{
		if (player->stairDirection == -1)
		{
			player->IsOnFootStair = true;
			player->IsOnTopStair = false;
			player->stairDirection = 2;
		}
		else if (player->stairDirection == -2)
		{
			player->IsOnFootStair = true;
			player->IsOnTopStair = false;
			player->stairDirection = 1;
		}
		player->ChangeAnimation(new PlayerWalkingStairState());
	}
	else if (keyCode[DIK_DOWN])
	{
		if (player->stairDirection == 1)
		{
			player->stairDirection = -2;
			player->IsOnFootStair = false;
			player->IsOnTopStair = true;

		}
		else if (player->stairDirection == 2)
		{
			player->stairDirection = -1;
			player->IsOnFootStair = false;
			player->IsOnTopStair = true;
		}

		player->ChangeAnimation(new PlayerWalkingStairState());
	}
	else 
		player->ChangeAnimation(new PlayerStandingStairState());
}
