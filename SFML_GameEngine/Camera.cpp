#include "Camera.h"

Camera::Camera()
{
	Position = Vec2<float>(0, 0);
	Angle = 0;
	Scale = 1;
}

Camera::Camera(float x, float y, float a, float s)
{
	Position = Vec2<float>(x, y);
	Angle = a;
	Scale = s;
}

Camera::Camera(Vec2<float> pos, float a, float s)
{
	Position = Vec2<float>(pos);
	Angle = a;
	Scale = s;
}
