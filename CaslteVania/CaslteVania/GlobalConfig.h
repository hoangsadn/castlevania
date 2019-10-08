#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <dinput.h>
#include <WinUser.h>
#include <unordered_map>
#include "Camera.h"
#include <vector>
/////define /////////
using namespace std;
////MARIO//////////////
#define MARIO_WALKING_SPEED		0.1f 

#define MARIO_JUMP_SPEED_Y		0.1f
#define MARIO_JUMP_DEFLECT_SPEED 0.2f
#define MARIO_GRAVITY			0.0001f
#define MARIO_DIE_DEFLECT_SPEED	 0.5f




#define MARIO_ANI_DIE				8


#define MARIO_BIG_BBOX_WIDTH  33
#define MARIO_BIG_BBOX_HEIGHT 61

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 15

#define MARIO_STAND_HIT_BBOX_WIDTH_AND_HEIGHT 60

#define MARIO_UNTOUCHABLE_TIME 5000

//screen

#define SCREEN_WIDTH 1536
#define SCREEN_HEIGHT 365



#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20


//////variable////

extern std::unordered_map<int, bool> keyCode; // manager info of keyboard have been pressed or not 
#define camera Camera::GetInstance()
#define player CMario::GetInstance()
#define GAME CGame::GetInstance()
extern std::unordered_map<int, bool> Allow;
//////////////
extern enum StateName
{
	WALKING,
	WALKING_LEFT,
	WALKING_RIGHT,
	JUMPING,
	JUMPING_RIGHT,
	JUMPING_LEFT,
	FALLING,
	FALLING_LEFT,
	FALLING_RIGHT,
	STANDING,
	STANDING_LEFT,
	STANDING_RIGHT,
	DOWNING,
	DOWNING_LEFT,
	DOWNING_RIGHT,
	HURTED,
	HITTING,
	HITTING_LEFT,
	HITTING_RIGHT,
};
