#pragma once
#include "PlayerState.h"
#include "PlayerStandingState.h"
class PlayerHurtingState : public PlayerState
{
public:
	PlayerHurtingState()
	{
		player->allow[JUMPING] = false;
		player->allow[HITTING] = false;
		player->vy = -SIMON_JUMP_SPEED_Y;
		player->y -= 4;
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
		player->stateBoundingBox = SIMON_BIG_BOUNDING_BOX;
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

