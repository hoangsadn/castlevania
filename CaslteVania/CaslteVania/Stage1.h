#pragma once 
#include "Scene.h"
#include "Map.h"
class CGameObject;
class CSimon;
class CWhip;
class Map;
class CBrick;

class Stage1 : public Scene
{
public:
	Stage1();

	void LoadResources();
	void LoadObjects();
	void Update(float dt);
	void UpdateObject(float dt);
	void UpdatePlayer(float dt);
	void Render();
	void OnKeyDown(int Key) ;
	void OnKeyUp(int Key) ;
private:
	CSimon *p;
	CWhip *whip;
	Map *map;
	Camera *camera;
	std::unordered_set <CGameObject*> objects;
	

	std::unordered_set <CGameObject*> PresentObjects;

};
