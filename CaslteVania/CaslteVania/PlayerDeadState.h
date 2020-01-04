#pragma once
#include "PlayerState.h"
#include "PlayerStandingState.h"
class PlayerDeadState : public PlayerState
{
public:
	DWORD timedead;
	
	PlayerDeadState()
	{
		player->allow[THROWING] = false;
		player->allow[HITTING] = false;
		player->allow[JUMPING] = false;
		timedead = GetTickCount();
		player->vy = 0;
		player->vx = 0;

		if (player->nx > 0)
			StateName = DEAD_RIGHT;
		else
			StateName = DEAD_LEFT;

	}
	void Update()
	{
	
		this->HandleKeyBoard();
		if (GetTickCount() - timedead > 2000)
		{
			player->Revival();
			player->life--;
		}
		GAMELOG("DEAD %d", GetTickCount() - timedead);
	}
	void HandleKeyBoard()
	{

	}

	~PlayerDeadState() {};
};

