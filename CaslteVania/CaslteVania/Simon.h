#pragma once
#include "GameObject.h"
#include "GlobalConfig.h"

class CMario : public CGameObject
{
	int level;
	int hitting = -1;
	int untouchable;
	DWORD untouchable_start;
	bool jumping = true;
public:
	CMario() : CGameObject()
	{
		level = MARIO_LEVEL_BIG;
		untouchable = 0;
	}
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void OnKeyUp(int keyCode){}
	void OnKeyDown(int KeyCode) {}

};