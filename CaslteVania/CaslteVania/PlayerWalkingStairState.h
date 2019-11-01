#pragma once
#include "PlayerState.h"
#include "PlayerStandingStairState.h"
class PlayerWalkingStairState :public PlayerState
{
public:
	PlayerWalkingStairState();
	void Update();
	void HandleKeyBoard();
	~PlayerWalkingStairState();
};

