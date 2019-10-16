#include "Camera.h"

Camera* Camera::__instance = NULL;



Camera * Camera::GetInstance()
{
	if (__instance == NULL)
		__instance = new Camera();
	return __instance;	
}
Camera::Camera()
{
}
void Camera::Update()
{
	if (this->x < 0)
	{
		this->x = 0;

	}
}
RECT Camera::GetBound()
{
	RECT bound;
	
	bound.left = x;
	bound.top = y;
	bound.right = x + mWidth;;
	bound.bottom = y + mHeight;
	return bound;
}




Camera::~Camera()
{
}
