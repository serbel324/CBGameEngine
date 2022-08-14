#pragma once
#include "Vec2.h"

#include <memory>

class Camera
{
public:
	Camera();
	Camera(float x, float y, float a = 0, float s = 1);
	Camera(Vec2<float> pos, float a = 0, float s = 1);

	Vec2<float> Position;
	float Angle;
	float Scale;

	typedef std::shared_ptr<Camera> SPtr;
};
