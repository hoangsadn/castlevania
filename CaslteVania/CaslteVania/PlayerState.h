#pragma once
#include "GlobalConfig.h"
class PlayerState
{
public:

	PlayerState() {};
	
	virtual void HandleKeyBoard() = 0;
	virtual void Update() = 0;
	//enum StateName
	//{
	//	WALKING_LEFT,
	//	WALKING_RIGHT,
	//	JUMPING_LEFT,
	//	FALLING_LEFT,
	//	FALLING_RIGHT,
	//	STANDING_LEFT,
	//	STANDING_RIGHT,
	//	DOWN,
	//	HURTED,
	//	HITTING,
	//};
	
	int mStateName;
	
};
