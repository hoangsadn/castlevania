#pragma once

#include <d3dx9.h>
#include <d3d9.h>

#define BEGIN_MAP1 0
#define END_MAP1 1500
#define BEGIN_MAP2 0
#define END_MAP2 3084
#define BEGIN_MAP3 3074
#define END_MAP3 4110
#define BEGIN_MAP4 3074
#define END_MAP4 4110
#define MAP_4_Y 400 
#define BEGIN_MAP5 4095
#define END_MAP5 5642
class Camera
{
private:
	
	
	D3DXVECTOR3 mPosition;
	static Camera * __instance;

public:
	float x;
	float y;
	int map;
	int mWidth;
	int mHeight;
	bool IsChangeMap;
	void SetCamPos(float x, float y) { this->x = x; this->y = y; };
	void SetRect(int width,int height) { mWidth = width; mHeight = height; };
	RECT GetBound();

	int GetHeight() { return mHeight; }
	int GetWidht() { return mWidth; }
	void Update();
	static Camera* GetInstance();

	Camera();
	~Camera();
};


