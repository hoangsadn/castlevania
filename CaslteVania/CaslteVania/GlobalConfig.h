#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <dinput.h>
#include <WinUser.h>
#include <unordered_map>

/////define /////////

////MARIO//////////////
#define MARIO_WALKING_SPEED		0.1f 

#define MARIO_JUMP_SPEED_Y		0.3f
#define MARIO_JUMP_DEFLECT_SPEED 0.2f
#define MARIO_GRAVITY			0.001f
#define MARIO_DIE_DEFLECT_SPEED	 0.5f

#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_JUMP			300
#define MARIO_STATE_DIE				400
#define MARIO_STATE_DOWN			500
#define MARIO_STATE_STAND_HIT_RIGHT	600
#define MARIO_STATE_STAND_HIT_LEFT	700
#define MARIO_STATE_STAND_HIT		800


#define MARIO_ANI_BIG_IDLE_RIGHT		0
#define MARIO_ANI_BIG_IDLE_LEFT			1
#define MARIO_ANI_SMALL_IDLE_RIGHT		2
#define MARIO_ANI_SMALL_IDLE_LEFT		3


#define MARIO_ANI_BIG_WALKING_RIGHT			4
#define MARIO_ANI_BIG_WALKING_LEFT			5
#define MARIO_ANI_JUMP_LEFT					8
#define MARIO_ANI_JUMP_RIGHT				9
#define MARIO_ANI_SMALL_WALKING_RIGHT		6
#define MARIO_ANI_SMALL_WALKING_LEFT		7
#define MARIO_ANI_STAND_HIT_RIGHT		13
#define MARIO_ANI_STAND_HIT_LEFT		12



#define MARIO_ANI_DIE				8

#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2

#define MARIO_BIG_BBOX_WIDTH  33
#define MARIO_BIG_BBOX_HEIGHT 61

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 15

#define MARIO_STAND_HIT_BBOX_WIDTH_AND_HEIGHT 60

#define MARIO_UNTOUCHABLE_TIME 5000

//screen

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240



#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20


//////variable////

extern std::unordered_map<int, bool> keyCode; // manager info of keyboard have been pressed or not 

