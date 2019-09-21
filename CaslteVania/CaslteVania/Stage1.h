#include "Scene.h"
#include "ManagerScene.h"
#include "GlobalConfig.h"
#include <map>
#include "Simon.h"
#include "Brick.h"
#include "Ghost.h"
class Stage1 : public Scene
{
public:
	void LoadResources();
	void Update(float dt);
	void Render();
	void OnKeyDown(int KeyCode) ;
	void OnKeyUp(int KeyCode) ;
private:
	CMario *player;
	CGoomba *goomba;
	vector<LPGAMEOBJECT> objects;
};
