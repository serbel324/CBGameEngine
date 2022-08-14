#include "ExtMath.h"

#include <cstdlib>
#include <random>
#include <cmath>

int ExtMath::GetRandomInt(int min, int max)
{
	if (max <= min)
	{
		return min;
	}

	static std::mt19937_64 randomizer(std::time(0));
	unsigned long long base = randomizer(); /* in range [0; ULLONG_MAX) */
	long long normalized = base % (max - min);
	return normalized + min;
}

float ExtMath::GetRandomFloat(float min, float max) {
	return GetRandomDouble(min, max);
}

float ExtMath::GetRandomDouble(double min, double max) {
	if (max <= min)
	{
		return min;
	}

	static std::mt19937_64 randomizer(std::time(0));
	long double base = randomizer(); /* in range [0; ULLONG_MAX) */
	long double maxr = ULLONG_MAX;
	long double normalized = base / maxr; /* in range [0; 1) */
	return normalized * (max - min) + min;
}


double ExtMath::ToRadian(double a)
{
	return (a * PI / 180);
}

double ExtMath::ToDegrees(double a)
{
	return (a * 180 / PI);
}

float ExtMath::WeightedAverage(float a1, float p1, float a2, float p2)
{
	return (a1 * p1 + a2 * p2) / (p1 + p2);
}

float ExtMath::Hypot(float a1, float a2)
{
	return(sqrt(a1 * a1 + a2 * a2));
}

float ExtMath::Hypot(float x1, float y1, float x2, float y2)
{
	return(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
float ExtMath::Hypot(Vec2<float> p1, Vec2<float> p2) {
	return(sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2)));
}

double ExtMath::Sigmoid(float x, float a)
{
	return 1 / (1 + exp(-x * a));
}

int ExtMath::Sign(double a)
{
	if (a == 0)	return 0;
	if (a > 0) return 1;
	return -1;
}