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
	Camera(int width, int height);

	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);

	int GetHeight() { return mHeight; }
	int GetWidht() { return mWidth; }
	D3DXVECTOR3 GetPosition() { return mPosition; }
	static Camera* GetInstance();

	Camera();
	~Camera();
};


