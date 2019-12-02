#pragma once 
#include "Scene.h"
#include "Map.h"
#include "ScoreBroad.h"
#define END_OF_MAP_2 3084
#define END_OF_MAP_3 4084
#define SPEED_CAMERA 0.1
#define GAME_FONT "font\\prstart.ttf"
class CGameObject;
class CSimon;
class CWhip;
class Map;
class CBrick;
class CScoreBroad;

class PlayStage : public Scene
{
public:

	PlayStage();
	int ChangeMapProc;
	void LoadResources(int level);
	void ChangeMap(float dt);
	void Update(float dt);
	void UpdateObject(float dt);
	void UpdatePlayer(float dt);
	void RepawnEnemy();
	void Render();
	void OnKeyDown(int Key) ;
	void OnKeyUp(int Key) ;

private:
	
	CScoreBroad *scoreboard;
	CSimon *p;
	CWhip *whip;
	Map *map;
	Camera *camera;
	//Grid * grid;
	int level;
	bool loadDone;

	//std::unordered_set <CGameObject*> objects;
	std::unordered_set <CGameObject*> PresentObjects;
	std::unordered_set <CGameObject*> RepawnObjects;
};
