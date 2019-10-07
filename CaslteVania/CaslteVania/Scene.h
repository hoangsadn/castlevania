#pragma once
#include "GlobalConfig.h"
class Scene
{
public:

	virtual void LoadResources() {};
	virtual void Update(float dt) {};
	virtual void Render() {};
	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
};
