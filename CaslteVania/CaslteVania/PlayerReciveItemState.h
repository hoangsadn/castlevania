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
			player->ChangeAnimation(new PlayerStandingState());
		}
	}
	void HandleKeyBoard() {};
	PlayerReciveItemState()
	{
		player->vx = 0;
		if (player->nx > 0)
		{
			StateName = RECIVE_RIGHT;
		}
		else StateName = RECIVE_LEFT;
	}
	~PlayerReciveItemState();
};