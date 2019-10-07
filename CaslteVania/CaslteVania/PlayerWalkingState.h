#pragma once
#include"PlayerState.h"
#include"Simon.h"
#include "PlayerStandingState.h"

class PlayerWalkingState : public PlayerState
{
public:
	void Update();
	void HandleKeyBoard();
	PlayerWalkingState();
	~PlayerWalkingState();
};


