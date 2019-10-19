#include "PlayerJumpingState.h"
void PlayerJumpingState::Update()
{
	
	if (player->vy <= 0)
	{
		player->ChangeAnimation(new PlayerFallingState());
		return;
	}
	this->HandleKeyBoard();
}
void PlayerJumpingState::HandleKeyBoard()
{

}
PlayerJumpingState::PlayerJumpingState()
{
	
	if (!player->IsJumping)
		player->vy = -MARIO_JUMP_SPEED_Y;
	player->IsJumping = true;
	if (player->nx > 0 )
		StateName = JUMPING_RIGHT;
	else
		StateName = JUMPING_LEFT;
}


PlayerJumpingState::~PlayerJumpingState()
{
}
