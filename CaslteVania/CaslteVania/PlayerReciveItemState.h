#pragma once
#include "PlayerStandingState.h"
#include "PlayerState.h"


class PlayerReciveItemState : public PlayerState
{
public:
	void Update()
	{
		if (player->CurAnimation->isLastFrame)
		{
			player->CurAnimation->currentFrame = -1;
			player->CurAnimation->isLastFrame = false;
			player->freeze = false;
			player->ChangeAnimation(new PlayerStandingState());
		}
	}
	void HandleKeyBoard() {};
	PlayerReciveItemState()
	{
		player->allow[HITTING] = false;
		player->allow[THROWING] = false;
		player->allow[JUMPING] = false;

		player->vx = 0;
		if (player->nx > 0)
		{
			StateName = RECIVE_RIGHT;
		}
		else StateName = RECIVE_LEFT;
		player->freeze = true;
	}
	~PlayerReciveItemState();
};