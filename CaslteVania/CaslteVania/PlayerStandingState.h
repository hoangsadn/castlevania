#pragma once
#include"PlayerState.h"
#include "PlayerWalkingState.h"
#include "PlayerDowningState.h"
#include "Simon.h"

class PlayerStandingState : public PlayerState 
{
public:
	void Update();
	void HandleKeyBoard();
	PlayerStandingState();
	~PlayerStandingState();
};


