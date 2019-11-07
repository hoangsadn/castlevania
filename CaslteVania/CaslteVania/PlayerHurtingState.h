#pragma once
#include "PlayerState.h"
#include "PlayerStandingState.h"
class PlayerHurtingState : public PlayerState
{
public:
	PlayerHurtingState()
	{
		player->vy = -SIMON_JUMP_SPEED_Y;

		player->IsJumping = true;

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

		player->untouchTime = GetTickCount();
	}
	void Update()
	{
		this->HandleKeyBoard();
		if (!player->IsJumping)
		{
			player->ChangeAnimation(new PlayerStandingState());
			return;
		}
	}
	void HandleKeyBoard()
	{

	}

	~PlayerHurtingState() {};
};

