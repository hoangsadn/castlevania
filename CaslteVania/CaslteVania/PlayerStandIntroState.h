#pragma once
#include "PlayerStandingState.h"
#include "PlayerState.h"


class PlayerStandIntroState : public PlayerState
{
public:
	void Update()
	{
		
	}
	void HandleKeyBoard() {};
	PlayerStandIntroState()
	{
		player->allow[HITTING] = false;
		player->allow[THROWING] = false;
		player->allow[JUMPING] = false;
		player->vx = 0;
		StateName = STANDING_INTRO;
		//player->freeze = true;
	}
	~PlayerStandIntroState() {};
};