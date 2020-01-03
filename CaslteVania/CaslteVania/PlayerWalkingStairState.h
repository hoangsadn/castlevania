#pragma once
#include "PlayerState.h"
#include "PlayerStandingStairState.h"
#define STEP_STAIR 16

class PlayerWalkingStairState :public PlayerState
{
public:
	int PreX, PreY, PosX, PosY;

	PlayerWalkingStairState();
	void Update();
	void HandleKeyBoard();
	~PlayerWalkingStairState();
};

