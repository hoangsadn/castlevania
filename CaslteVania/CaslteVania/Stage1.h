#pragma once 
#include "Scene.h"
#include "Simon.h"

//#include "GameObject.h"
class CGameObject;
class CMario;
class Stage1 : public Scene
{
public:
	Stage1();

	void LoadResources();
	void Update(float dt);
	void Render();
	void OnKeyDown(int Key) ;
	void OnKeyUp(int Key) ;
private:
	CMario *p;

	vector<CGameObject*> objects;
};
