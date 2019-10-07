#include "Camera.h"

Camera* Camera::__instance = NULL;

Camera::Camera(int width, int height)
{
	mWidth = width;
	mHeight = height;

	mPosition = D3DXVECTOR3(0, 0, 0);
}
void Camera::SetPosition(D3DXVECTOR3 pos)
{
	mPosition = pos;
}
void Camera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}
Camera * Camera::GetInstance()
{
	if (__instance == NULL)
		__instance = new Camera();
	return __instance;	
}
Camera::Camera()
{
}



Camera::~Camera()
{
}
