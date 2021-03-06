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
#define BACKGROUND_COLOR_WHITE D3DCOLOR_XRGB(255, 255, 255)


#define SIMON_WALKING_SPEED		0.1f 
#define SIMON_STEP_STAIR_SPEED 0.05f

#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_JUMP_DEFLECT_SPEED 0.2f
#define SIMON_GRAVITY			0.0015f
#define SIMON_DIE_DEFLECT_SPEED	 0.5f

#define SIMON_BIG_BOUNDING_BOX 222
#define SIMON_SMALL_BOUNDING_BOX 111



#define SIMON_BIG_BBOX_WIDTH  45
#define SIMON_BIG_BBOX_HEIGHT 63

#define SIMON_SMALL_BBOX_WIDTH  45
#define SIMON_SMALL_BBOX_HEIGHT 46

#define SIMON_STAND_HIT_BBOX_WIDTH_AND_HEIGHT 60

#define SIMON_UNTOUCHABLE_TIME 5000
#define SIMON_INVINCIBILITY_TIME 9000

//screen

#define SCREEN_WIDTH 550	
#define SCREEN_HEIGHT 475

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
	STANDING_INTRO,
	STANDING,
	STANDING_LEFT,
	STANDING_RIGHT,
	DOWNING,
	DOWNING_LEFT,
	DOWNING_RIGHT,
	RECIVE_RIGHT,
	RECIVE_LEFT,
	HURTING,
	HURTING_LEFT,
	HURTING_RIGHT,
	HITTING,
	HITTING_STAND_LEFT,
	HITTING_STAND_RIGHT,
	HITTING_DOWN_LEFT,
	HITTING_DOWN_RIGHT,
	THROWING,
	STAIRING,
	STANDING_STAIR_UP_LEFT,
	STANDING_STAIR_UP_RIGHT,
	WALKING_STAIR_UP_LEFT,
	WALKING_STAIR_UP_RIGHT,
	STANDING_STAIR_DOWN_LEFT,
	STANDING_STAIR_DOWN_RIGHT,
	WALKING_STAIR_DOWN_LEFT,
	WALKING_STAIR_DOWN_RIGHT,
	HITTING_STAIR_DOWN_LEFT,
	HITTING_STAIR_DOWN_RIGHT,
	HITTING_STAIR_UP_RIGHT,
	HITTING_STAIR_UP_LEFT,
	DEAD,
	DEAD_LEFT,
	DEAD_RIGHT,
};
extern enum TAG
{
	PLAYER,
	ENEMY,
	WEAPON,
	ITEM,
	HOLDER,
	GROUND,
	EFFECT,
	BOX,
};

extern enum TYPE
{
	TITLE_SCREEN,
	BAT_CASTLE_FLY,
	BAT_CASTLE_FLY_NOT_MOVE,
	CASTLE_SCREEN,
	HELICOPTER,
	BAT_INTRO_SMALL_FLY,
	WHIP,
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
	MONEY_BLUE,
	MONEY_RED,
	MONEY_WHITE,
	INVINCIBILITY,
	DOUBLE_SHOT,
	STOP_WATCH,
	ROSARY,
	ROAST,
	AXE,
	AXE_THORW,
	HOLLY_WATER,
	HOLLY_WATER_THROW,
	HOLLY_WATER_BURN,
	HIDDEN_BRICK,
	HIDDEN_BRICK_SMALL,
	HIDDEN_BRICK_BROKE,
	SMALL_HEART,
	CANDLE,
	CONNER_WALL,
	EFFECT_DEAD,
	DOOR,
	DOOR_OPEN,
	DOOR_CLOSE,
	DOOR_OPENING,
	CHECKPOINT,
	STAIR,
	STAIR_BOTTOM_LEFT,
	STAIR_BOTTOM_RIGHT,
	STAIR_TOP_LEFT,
	STAIR_TOP_RIGHT,
	BOSS,
	BOSS_HANG,
	BOSS_STAND,
	BOSS_MOVE,
	BOSS_ATTACK,
	BOSS_READY_ATTACK,
	GHOST,
	GHOST_LEFT,
	GHOST_RIGHT,
	BAT,
	BAT_LEFT,
	BAT_RIGHT,
	AQUAMAN,
	AQUAMAN_STAND,
	AQUAMAN_STAND_LEFT,
	AQUAMAN_STAND_RIGHT,
	AQUAMAN_WALK,
	AQUAMAN_WALK_LEFT,
	AQUAMAN_WALK_RIGHT,
	AQUAMAN_FIRE,
	AQUAMAN_FIRE_LEFT,
	AQUAMAN_FIRE_RIGHT,
	WATER,
	FIRE_BALL,
	FIRE_BALL_LEFT,
	FIRE_BALL_RIGHT,
	BLACKPANTHER,
	BLACKPANTHER_STAND_LEFT,
	BLACKPANTHER_STAND_RIGHT,
	BLACKPANTHER_RUN_LEFT,
	BLACKPANTHER_RUN_RIGHT,
	BLACKPANTHER_JUMP_LEFT,
	BLACKPANTHER_JUMP_RIGHT,
};


extern std::unordered_map<std::string, TYPE>   TYPEString;

#define ADDITEM(x)  TYPEString.insert(std::pair<std::string,TYPE>(#x,x));

extern std::unordered_map<std::string, STATENAME>   STATEString;

#define ADDSTATE(x)  STATEString.insert(std::pair<std::string,STATENAME>(#x,x));

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
		ADDITEM(CHECKPOINT, "CHECKPOINT");
		ADDITEM(BRICK, "BRICK");
		ADDITEM(GHOST, "GHOST");
		ADDITEM(BAT, "BAT");
		ADDITEM(BLACKPANTHER, "BLACKPANTHER");
		ADDITEM(AQUAMAN, "AQUAMAN");
		ADDITEM(AXE, "AXE");
		ADDITEM(HOLLY_WATER, "HOLLY_WATER");
		ADDITEM(MONEY_BLUE, "MONEY_BLUE");
		ADDITEM(MONEY_WHITE, "MONEY_WHITE");
		ADDITEM(MONEY_RED, "MONEY_RED");
		ADDITEM(INVINCIBILITY, "INVINCIBILITY");
		ADDITEM(DOUBLE_SHOT, "DOUBLE_SHOT");
		ADDITEM(STOP_WATCH, "STOP_WATCH");
		ADDITEM(ROSARY, "ROSARY");
		ADDITEM(ROAST, "ROAST");
		ADDITEM(STAIR, "STAIR");
		ADDITEM(STAIR_BOTTOM_LEFT, "STAIR_BOTTOM_LEFT");
		ADDITEM(STAIR_BOTTOM_RIGHT, "STAIR_BOTTOM_RIGHT");
		ADDITEM(STAIR_TOP_LEFT, "STAIR_TOP_LEFT");
		ADDITEM(STAIR_TOP_RIGHT, "STAIR_TOP_RIGHT");
		ADDITEM(HIDDEN_BRICK, "HIDDEN_BRICK");
		ADDITEM(HIDDEN_BRICK_SMALL, "HIDDEN_BRICK_SMALL");
	}
	~CGlobalConfig() {};
};
