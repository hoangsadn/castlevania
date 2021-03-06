#include "PlayerWalkingStairState.h"
#include "PlayerWalkingState.h"



PlayerWalkingStairState::PlayerWalkingStairState()
{
	player->allow[JUMPING] = false;
	player->IsWalkingComplete = false;
	switch (player->stairDirection)
	{
	case 1:
		StateName = WALKING_STAIR_UP_RIGHT;
		player->vx = SIMON_STEP_STAIR_SPEED;
		player->vy = -SIMON_STEP_STAIR_SPEED;
		player->nx = 1;
		player->ny = 1;
		break;
	case 2: 
	{
		StateName = WALKING_STAIR_UP_LEFT;
		player->vx = -SIMON_STEP_STAIR_SPEED;
		player->vy = -SIMON_STEP_STAIR_SPEED;
		player->nx = -1;
		player->ny = 1;
		break;
	}
	case -1:
	{
		StateName = WALKING_STAIR_DOWN_RIGHT;
		player->vx = SIMON_STEP_STAIR_SPEED;
		player->vy = SIMON_STEP_STAIR_SPEED;
		player->nx = 1;
		player->ny = -1;
		break;
	}
	case -2:
	{
		StateName = WALKING_STAIR_DOWN_LEFT;
		player->vx = -SIMON_STEP_STAIR_SPEED;
		player->vy = SIMON_STEP_STAIR_SPEED;
		player->nx = -1;
		player->ny = -1;
		break;
	}
	default:
		StateName = WALKING_STAIR_UP_RIGHT;
		break;
	}
	player->IsOnStair = true;	
	PreX = player->x;
	PreY = player->y;
	


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
	if (player->CurAnimation->isLastFrame)
	{
		player->CurAnimation->isLastFrame = false;
		player->CurAnimation->currentFrame = -1;
		PosX = player->x;
		PosY = player->y;
		player->x = PosX;
		player->y = PosY;

		PosX += player->nx*(STEP_STAIR - abs((abs(PosX) - abs(PreX))));
		PosY -=  player->ny*(STEP_STAIR - abs((abs(PosY) - abs(PreY)))) ;

		player->x = PosX;
		player->y = PosY;
		player->dx = 0;
		player->dy = 0;

		this->HandleKeyBoard();
	}
}
void PlayerWalkingStairState::HandleKeyBoard()
{
	
	if (keyCode[DIK_UP] )
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
