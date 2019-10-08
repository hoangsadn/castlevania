#pragma once
#include "PlayerStandingState.h"
#include "PlayerState.h"
#include "PlayerWalkingState.h"

class PlayerDowningState : public PlayerState
{
public:
	void Update();
	void HandleKeyBoard();
	PlayerDowningState();
	~PlayerDowningState();
};

