#pragma once
#include "PlayerState.h"
#include "Simon.h"
class PlayerHittingState : public PlayerState
{
	
public:
	void Update();
	void HandleKeyBoard();
	PlayerHittingState();
	~PlayerHittingState();
};

