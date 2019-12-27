#include "ScoreBroad.h"
#include "Simon.h"
#define ID_SPRITE_SCORE 90000
#define ID_SPRITE_HEALTH_SIMON 90001
#define HEIGHT_SCORE_BROAD 80
#define POS_X_HEALTH_BAR 109 
#define POS_Y_HEALTH_BAR 25 
#define POS_X_WEAPOINT 310 
#define POS_Y_WEAPOINT 26 
#define DISTANCE_BETWEEN_BLOOD 11
#define ID_AXE 40006
#define ID_HOLLY_WATER 40012
#define ID_KNIFE 40003
#define ID_STOP_WATCH 40020

CScoreBroad::CScoreBroad()
{
	
}

void CScoreBroad::Init()
{
	font = NULL;
	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3DDevice();

	AddFontResourceEx(L"font\\prstart.ttf", FR_PRIVATE, NULL);
	HRESULT result = D3DXCreateFont(
		d3ddv, 15, 0, FW_NORMAL, 1, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY, FF_DONTCARE, L"Press Start", &font);

	SetRect(&rect, 10, 10, SCREEN_WIDTH, HEIGHT_SCORE_BROAD);
	information = "SCORE_000000 TIME 0000 STAGE 00\n";
	information += "PLAYER                   =62\n";
	information += "ENEMY                   P=3\n";
	sprites = CSprites::GetInstance();
	ScoreBoard = sprites->Get(ID_SPRITE_SCORE);
	healthSimon = sprites->Get(ID_SPRITE_HEALTH_SIMON);
	
}
void CScoreBroad::Update(float dt)
{
	std::string scoreString = std::to_string(player->point);
	while (scoreString.length() < 6)
		scoreString = "0" + scoreString;

	
	std::string timeString = std::to_string(player->playTime);
	while (timeString.length() < 4)
		timeString = "0" + timeString;


	std::string stageString = std::to_string(player->Checkpoint);
	while (stageString.length() < 2)
		stageString = "0" + stageString;
	switch (player->weaponTypeCarry)
	{
	case KNIFE:
		idweapoint = ID_KNIFE;
		break;
	case STOP_WATCH:
		idweapoint = ID_STOP_WATCH;
		break;
	case AXE:
		idweapoint = ID_AXE;
		break;
	case HOLLY_WATER:
		idweapoint = ID_HOLLY_WATER;
		break;
	default:
		break;
	}

	information = "SCORE_" + scoreString + " TIME " + timeString + " STAGE " + stageString + "\n";
	information += "PLAYER                   =" + std::to_string(player->bullet) + "\n";
	information += "ENEMY                   P=" + std::to_string(player->life) + "\n";

	weapointSimon = sprites->Get(idweapoint);
	
}
void CScoreBroad::Render()
{
	
	
	
	ScoreBoard->Draw(CAMERA->x, CAMERA->y);
	if (font)
		font->DrawTextA(NULL, information.c_str(), -1, &rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	for (int i = 0 ; i < player->health ; i++)
		healthSimon->Draw(CAMERA->x + POS_X_HEALTH_BAR + i* DISTANCE_BETWEEN_BLOOD, CAMERA->y + POS_Y_HEALTH_BAR);
	if (player->weaponTypeCarry != NOTHING)
		weapointSimon->Draw(CAMERA->x + POS_X_WEAPOINT, CAMERA->y + POS_Y_WEAPOINT);

}
CScoreBroad::~CScoreBroad()
{
}
