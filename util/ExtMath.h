#pragma once
#include "Vec2.h"
#include <random>

/* Additional mathematical functions */
struct ExtMath
{
public:
	static float GetRandomFloat(float min, float max);
	static float GetRandomDouble(double min, double max);
	static int GetRandomInt(int min, int max);

	static double ToRadian(double a);
	static double ToDegrees(double a);

	/* weighted average */
	static float WeightedAverage(float a1, float p1, float a2, float p2);

	static float Hypot(float a1, float a2);
	static float Hypot(float x1, float y1, float x2, float y2);
	static float Hypot(Vec2<float> p1, Vec2<float> p2);

	/* Sigmoid function */
	static double Sigmoid(float x, float a);

	static int Sign(double a);

	static constexpr double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
};


