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
		case 1:
			if (this->x < 0)
			{
				this->x = 0;

			}
			else if (this->x > 1500 - mWidth)
			{
				this->x = 1500 - mWidth;
			}
			break;
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
			if (this->x < 3074)
			{
				this->x = 3074;

			}
			else if (this->x > 4110 - mWidth)
			{
				this->x = 4110 - mWidth;
			}
			break;
		}
		case 4:
		{
			if (this->x < 3074)
			{
				this->x = 3074;
			}
			else if (this->x > 4110 - mWidth)
			{
				this->x = 4110 - mWidth;
			}
			this->y = 360;
			break;
		}
		case 5:
		{
			if (this->x < 4095)
			{
				this->x = 4095;
			}
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
