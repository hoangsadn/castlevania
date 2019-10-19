#include "PlayerFallingState.h"

void PlayerFallingState::Update()
{
	if (!player->IsJumping)
	{
		player->ChangeAnimation(new PlayerStandingState());
		return;
	}
	this->HandleKeyBoard();
}
void PlayerFallingState::HandleKeyBoard()
{

}

PlayerFallingState::PlayerFallingState()
{

	if (player->nx > 0)
		StateName = FALLING_RIGHT;
	else
		StateName = FALLING_LEFT;
}


PlayerFallingState::~PlayerFallingState()
{
}
