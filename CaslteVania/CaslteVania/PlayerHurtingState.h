#pragma once
#include "PlayerState.h"
#include "PlayerStandingState.h"
class PlayerHurtingState : public PlayerState
{
public:
	PlayerHurtingState() 
	{
		player->vy = -SIMON_JUMP_SPEED_Y;
		player->untouchTime = GetTickCount();
		if (player->nx > 0) 
		{
			player->vx = -SIMON_WALKING_SPEED;
			StateName = HURTING_RIGHT;
		}
		else
		{
			player->vx = SIMON_WALKING_SPEED;
			StateName = HURTING_LEFT;
		}
	}
	void Update() 
	{
		this->HandleKeyBoard();
		/*if (!player->IsJumping)
		{
			player->ChangeAnimation(new PlayerStandingState());
		}*/
	}
	void HandleKeyBoard() 
	{

	}
	
	~PlayerHurtingState() {};
};

