#include "PlayerJumpingState.h"
void PlayerJumpingState::Update()
{
	
	if (!(player->IsJumping))
	{
		player->ChangeAnimation(new PlayerStandingState());
	}

}
void PlayerJumpingState::HandleKeyBoard()
{

}
PlayerJumpingState::PlayerJumpingState()
{
	player->IsJumping = true;
	player->vy = -MARIO_JUMP_SPEED_Y;
	if (player->nx)
		StateName = JUMPING_RIGHT;
	else
		StateName = JUMPING_LEFT;
}


PlayerJumpingState::~PlayerJumpingState()
{
}
