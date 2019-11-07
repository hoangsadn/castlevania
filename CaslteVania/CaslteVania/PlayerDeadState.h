#pragma once
#include "PlayerState.h"
#include "PlayerStandingState.h"
class PlayerDeadState : public PlayerState
{
public:
	PlayerDeadState()
	{
		player->vy = 0;
		player->vx = 0;

		if (player->nx > 0)
			StateName = DEAD_RIGHT;
		else
			StateName = DEAD_LEFT;

	}
	void Update()
	{
		this->HandleKeyBoard();
	}
	void HandleKeyBoard()
	{

	}

	~PlayerDeadState() {};
};

