#pragma once
#include"PlayerState.h"
#include"Simon.h"
#include "PlayerStandingState.h"
#include "PlayerDowningState.h"

class PlayerWalkingState : public PlayerState
{
public:
	DWORD timeWalk,timeFinish;
	void Update();
	void HandleKeyBoard();
	void walking(DWORD dt);
	PlayerWalkingState(DWORD timeFinish = 0);
	~PlayerWalkingState();
};


