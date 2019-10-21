#pragma once
#include "GlobalConfig.h"
class PlayerState
{
public:

	PlayerState() {};
	
	virtual void HandleKeyBoard() = 0;
	virtual void Update() = 0;
	STATENAME StateName;
	STATENAME PrevState;
};
