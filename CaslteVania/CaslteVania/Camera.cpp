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
	IsChangeMap = false;
}
void Camera::Update()
{
	if (!IsChangeMap)
	{
		switch (map)
		{
		case 2:
		{
			if (this->x < 0)
			{
				this->x = 0;

			}
			else if (this->x > 3084 - mWidth)
			{
				this->x = 3084 - mWidth;
			}
			break;
		}
		case 3: 
		{
			if (this->x < 3090)
			{
				this->x = 3090;

			}
			break;
		}
		case 4:
		{
			if (this->x < 3090)
			{
				this->x = 3090;
			}
			this->y = 360;
			break;
		}
		default:
			break;
		}
		
	}
	else
	{

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
