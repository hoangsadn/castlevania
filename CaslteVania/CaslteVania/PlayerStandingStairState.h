#pragma once
#include "PlayerState.h"


class PlayerStandingStairState : public PlayerState
{
public:
	void Update();
	void HandleKeyBoard();
	PlayerStandingStairState();
	~PlayerStandingStairState();
};

