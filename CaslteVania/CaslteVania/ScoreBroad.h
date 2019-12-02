#pragma once
#include "GlobalConfig.h"
#include "Sprites.h"
class CSprites;
class CSprite;
class CScoreBroad 
{
private:
	ID3DXFont *font;
	RECT rect;
	string information;
	CSprites * sprites;
	CSprite * ScoreBoard;
	CSprite * healthSimon;
	CSprite * weapointSimon;
	int idweapoint;
public:
	CScoreBroad();
	void Init();
	void Update(float dt);
	void Render();
	~CScoreBroad();
};

