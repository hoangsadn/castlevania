#pragma once 
#include "Scene.h"
#include "Simon.h"

class CGameObject;
class CMario;
class CWhip;
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
	std::unordered_set <CGameObject*> objects;
	std::unordered_set <CGameObject*> PresentObjects;

};
