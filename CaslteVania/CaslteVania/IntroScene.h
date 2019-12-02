#pragma once
#include "Scene.h"
#include "Animations.h"
class CSimon;
class CAnimation;
class CAnimations;

class IntroScene : public Scene
{
public:
	CSimon *p;
	std::unordered_map<int, CAnimation*> animations;
	CAnimation* TitleScreen;
	CAnimation* BatFly;
	CAnimation* CastleScreen;
	CAnimation* helicopter;
	CAnimation* bat;
	DWORD time;
	float posHeliX, posHeliY, posBatX, posBatY;
	int ProcessScene;
	IntroScene();
	void Update(float dt);
	void Render();
	void OnKeyDown(int keyCode) ;
	void AddAnimation(int aniId, TYPE type);
	~IntroScene();
};

