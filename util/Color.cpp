#include "Color.h"
#include <util/ExtMath.h>

#include <algorithm>

Color::Color(int r, int g, int b, int a)
{
	R = std::max(std::min(255, r), 0);
	G = std::max(std::min(255, g), 0);
	B = std::max(std::min(255, b), 0);
	A = std::max(std::min(255, a), 0);
}
Color::Color(int v)
{
	R = std::max(std::min(255, v), 0);
	G = std::max(std::min(255, v), 0);
	B = std::max(std::min(255, v), 0);
	A = 255;
}

Color::~Color()
{
}

Color Color::operator+(const Color& right) const
{
	return Color(R + right.R, G + right.G, B + right.B, A);
}

Color Color::operator+(const int right) const
{
	return Color(R + right, G + right, B + right, A);
}

Color Color::operator-(const Color& right) const
{
	return Color(R - right.R, G - right.G, B - right.B, A);
}

Color Color::operator-(const int right) const
{
	return Color(R - right, G - right, B - right, A);
}

Color Color::operator*(const float right) const
{
	return Color(R * right, G * right, B * right, A);
}

Color Color::GetRandom()
{
	return Color(
		ExtMath::GetRandomInt(0, 255), 
		ExtMath::GetRandomInt(0, 255), 
		ExtMath::GetRandomInt(0, 255)
	);
}
