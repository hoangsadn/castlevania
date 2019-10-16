#pragma once 
#include "Scene.h"
#include "Simon.h"
#include "Map.h"

class CGameObject;
class CMario;
class CWhip;
class Map;

class Stage1 : public Scene
{
public:
	Stage1();

	void LoadResources();
	void Update(float dt);
	void UpdatePlayer();
	void Render();
	void OnKeyDown(int Key) ;
	void OnKeyUp(int Key) ;
private:
	CMario *p;
	CWhip *whip;
	Map *map;
	Camera *camera;
	std::unordered_set <CGameObject*> objects;
	std::unordered_set <CGameObject*> PresentObjects;

};
