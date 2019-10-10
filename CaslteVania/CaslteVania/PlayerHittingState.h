#pragma once
#include "PlayerState.h"
#include "Simon.h"
#include "PlayerStandingState.h"
class PlayerHittingState : public PlayerState
{
private:
	STATENAME PrevAnimation;
public:
	void Update();
	void HandleKeyBoard();
	PlayerHittingState();
	~PlayerHittingState();
};

