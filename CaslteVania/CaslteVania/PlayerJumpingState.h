#pragma once
#include "PlayerState.h"
#include "Simon.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
class PlayerJumpingState : public PlayerState
{
public:
	void Update();
	void HandleKeyBoard();
	PlayerJumpingState();
	~PlayerJumpingState();
};