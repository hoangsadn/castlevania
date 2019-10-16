#pragma once

#include <d3dx9.h>
#include <d3d9.h>
class Camera
{
private:
	int mWidth;
	int mHeight;
	
	D3DXVECTOR3 mPosition;
	static Camera * __instance;

public:
	float x;
	float y;
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


