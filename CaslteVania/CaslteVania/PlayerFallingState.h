#pragma once
#include "PlayerState.h"
#include "PlayerJumpingState.h"
class PlayerFallingState : public PlayerState
{
public:
	void Update();
	void HandleKeyBoard();
	PlayerFallingState();
	~PlayerFallingState();
};

