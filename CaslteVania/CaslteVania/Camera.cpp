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
	x = 0;
	y = 0;
	IsChangeMap = false;
}
void Camera::Update()
{
	if (!IsChangeMap)
	{
		switch (map)
		{
		case 1:
			if (this->x < BEGIN_MAP1)
			{
				this->x = BEGIN_MAP1;

			}
			else if (this->x > END_MAP1 - mWidth)
			{
				this->x = END_MAP1 - mWidth;
			}
			break;
		case 2:
		{
			if (this->x < BEGIN_MAP2)
			{
				this->x = BEGIN_MAP2;

			}
			else if (this->x > END_MAP2 - mWidth)
			{
				this->x = END_MAP2 - mWidth;
			}
			break;
		}
		case 3:
		{
			if (this->x < BEGIN_MAP3)
			{
				this->x = BEGIN_MAP3;

			}
			else if (this->x > END_MAP3 - mWidth)
			{
				this->x = END_MAP3 - mWidth;
			}
			break;
		}
		case 4:
		{
			if (this->x < BEGIN_MAP4)
			{
				this->x = BEGIN_MAP4;
			}
			else if (this->x > END_MAP4 - mWidth)
			{
				this->x = END_MAP4 - mWidth;
			}
			this->y = MAP_4_Y;
			break;
		}
		case 5:
		{
			if (this->x < BEGIN_MAP5)
			{
				this->x = BEGIN_MAP5;
			}
			else if (this->x > END_MAP5 - mWidth -10)
			{
				this->x = END_MAP5 - mWidth -10 ;
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
