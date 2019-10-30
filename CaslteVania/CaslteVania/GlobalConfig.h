#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <dinput.h>
#include <WinUser.h>
#include <unordered_map>
#include "Camera.h"
#include <vector>
#include <iostream> 
#include <string> 
#include <unordered_set> 
#include <map>


/////define /////////
using namespace std;
////SIMON//////////////
#define SIMON_WALKING_SPEED		0.1f 

#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_JUMP_DEFLECT_SPEED 0.2f
#define SIMON_GRAVITY			0.002f
#define SIMON_DIE_DEFLECT_SPEED	 0.5f

#define SIMON_BIG_BOUNDING_BOX 222
#define SIMON_SMALL_BOUNDING_BOX 111



#define SIMON_BIG_BBOX_WIDTH  45
#define SIMON_BIG_BBOX_HEIGHT 63

#define SIMON_SMALL_BBOX_WIDTH  45
#define SIMON_SMALL_BBOX_HEIGHT 46

#define SIMON_STAND_HIT_BBOX_WIDTH_AND_HEIGHT 60

#define SIMON_UNTOUCHABLE_TIME 5000

//screen

#define SCREEN_WIDTH 500	
#define SCREEN_HEIGHT 500

#define TITLE_WIDTH 32
#define TITLE_HEIGHT 32


#define ID_TEX_SIMON 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
#define ID_TEX_WHIP 30
#define ID_TEX_TITLE 40
#define ID_TEX_FIRE_PILLAR 50


//////variable////

extern std::unordered_map<int, bool> keyCode; // manager info of keyboard have been pressed or not 
#define CAMERA Camera::GetInstance()
#define player CSimon::GetInstance()
#define GAME CGame::GetInstance()
extern std::unordered_map<int, bool> Allow;
//////////////
extern enum STATENAME
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
	RECIVE_RIGHT,
	RECIVE_LEFT,
	HURTED,
	HITTING,
	HITTING_STAND_LEFT,
	HITTING_STAND_RIGHT,
	HITTING_DOWN_LEFT,
	HITTING_DOWN_RIGHT,
	THROWING,
};
extern enum TAG
{
	PLAYER,
	WEAPON,
	ITEM,
	HOLDER,
	GROUND,
	EFFECT,
	BOX,
};

extern enum TYPE
{
	WHIP_ONE,
	WHIP_ONE_RIGHT,
	WHIP_ONE_LEFT,
	WHIP_TWO,
	WHIP_TWO_RIGHT,
	WHIP_TWO_LEFT,
	WHIP_THREE,
	WHIP_THREE_RIGHT,
	WHIP_THREE_LEFT,
	BRICK,
	NOTHING,
	KNIFE,
	KNIFE_LEFT,
	KNIFE_RIGHT,
	FIRE_PILLAR,
	MORNING_STAR,
	BIG_HEART,
	SMALL_HEART,
	CANDLE,
	EFFECT_DEAD,
	DOOR,
};


extern std::unordered_map<std::string, TYPE>   TYPEString;

#define ADDITEM(x)  TYPEString.insert(std::pair<std::string,TYPE>(#x,x));
class CGlobalConfig
{
public:
	CGlobalConfig() {};
	void TypeMapToString()
	{
		ADDITEM(KNIFE, "KNIFE");
		ADDITEM(MORNING_STAR, "MORNING_STAR");
		ADDITEM(NOTHING, "NOTHING");
		ADDITEM(KNIFE, "KNIFE");
		ADDITEM(FIRE_PILLAR, "FIRE_PILLAR");
		ADDITEM(BIG_HEART, "BIG_HEART");
		ADDITEM(SMALL_HEART, "SMALL_HEART");
		ADDITEM(CANDLE, "CANDLE");
		ADDITEM(EFFECT_DEAD, "EFFECT_DEAD");
		ADDITEM(DOOR, "DOOR");
		ADDITEM(BRICK, "BRICK");
	}
	~CGlobalConfig() {};
};
