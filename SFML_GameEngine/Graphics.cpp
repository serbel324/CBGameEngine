#include "Vec2.h"
#include "Graphics.h"
#include "ExtMath.h"

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

namespace CBGE {

Graphics::Graphics(std::shared_ptr<sf::RenderWindow> win, Vec2<int> ws)
{
	Window = win;
	FillColor = Color(0, 0, 0, 255);
	WindowSize = ws;
	SetDefaultCamera();
}

Graphics::Graphics(std::shared_ptr<sf::RenderWindow> win, Vec2<int> ws, Camera::SPtr cam)
{
	Window = win;
	FillColor = Color(0, 0, 0, 255);
	WindowSize = ws;
	Cam = cam;
}

void Graphics::DrawPoint(float x, float y)
{
	DrawPoint(Vec2<float>(x, y));
}
void Graphics::DrawPoint(Vec2<float> pos)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(1, 1));
	rectangle.setPosition(pos.X, pos.Y);

	rectangle.setFillColor(sf::Color(FillColor.R, FillColor.G, FillColor.B, FillColor.A));

	Window->draw(rectangle);
}

void Graphics::DrawCircle(float x, float y, float radius)
{
	DrawCircle(Vec2<float>(x, y), radius);
}
void Graphics::DrawCircle(Vec2<float> pos, float radius)
{
	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPosition(pos.X - radius, pos.Y - radius);

	circle.setFillColor(sf::Color(FillColor.R, FillColor.G, FillColor.B, FillColor.A));

	Window->draw(circle);
}

void Graphics::DrawBrokenLine(std::vector<Vec2<float>> t, Vec2<float> a, float s)
{
	for (int i = 1; i < t.size(); i++)
	{
		DrawLine(t[i - 1] * s + a, t[i] * s + a);
	}
}

void Graphics::DrawLine(Vec2<float> v1, Vec2<float> v2)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(v1.X, v1.Y), sf::Color(FillColor.R, FillColor.G, FillColor.B, FillColor.A)),
		sf::Vertex(sf::Vector2f(v2.X, v2.Y), sf::Color(FillColor.R, FillColor.G, FillColor.B, FillColor.A))
	};

	Window->draw(line, 2, sf::Lines);
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2)
{
	DrawLine(Vec2<float>(x1, y1), Vec2<float>(x2, y2));
}


void Graphics::DrawRect(float x, float y, float W, float h)
{
	DrawRect(Vec2<float>(x, y), Vec2<float>(W, h));
}

void Graphics::DrawRect(Vec2<float> pos, Vec2<float> size)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(size.X, size.Y));
	rectangle.setPosition(pos.X, pos.Y);

	rectangle.setFillColor(sf::Color(FillColor.R, FillColor.G, FillColor.B, FillColor.A));

	Window->draw(rectangle);
}

void Graphics::DrawTexture(sf::Texture& tex, float x, float y, float W, float h)
{
	DrawTexture(tex, Vec2<float>(x, y), Vec2<float>(W, h));
}

void Graphics::DrawTexture(sf::Texture& tex, Vec2<float> pos, Vec2<float> size)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);

	sf::Vector2u s = tex.getSize();

	sprite.setPosition(pos.X - size.X / 2, pos.Y - size.Y / 2);
	sprite.setScale(size.X / s.x, size.Y / s.y);
	Window->draw(sprite);
}

void Graphics::DrawTexture(sf::Texture& tex, Vec2<float> pos, Vec2<float> size, float a)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);

	sf::Vector2u s = tex.getSize();

	sprite.setPosition(pos.X - size.X / 2, pos.Y - size.Y / 2);
	sprite.setScale(size.X / s.x, size.Y / s.y);

	sprite.setOrigin(size.X / 2, size.Y / 2);
	sprite.setRotation(ExtMath::ToDegrees(a));

	Window->draw(sprite);
}

void Graphics::Present()
{
	Window->display();
}

void Graphics::SetFillColor(float r, float g, float b, float a)
{
	FillColor.R = r;
	FillColor.G = g;
	FillColor.A = b;
	FillColor.A = a;
}

void Graphics::SetFillColor(Color col)
{
	FillColor = col;
}

void Graphics::Fill()
{
	Camera::SPtr c = std::make_shared<Camera>();

	ApplyCamera(c);
	DrawRect(0, 0, Window->getSize().x, Window->getSize().y);
	ApplyCamera(Cam);
}

void Graphics::Clear()
{
	Window->clear();
}

void Graphics::FillText(const std::string& text, float x, float y, float size, sf::Font& font)
{
	sf::Text t;

	t.setFont(font);
	t.setString(text);
	t.setPosition(x, y);
	t.setCharacterSize(size);
	t.setFillColor(sf::Color(FillColor.R, FillColor.G, FillColor.B, FillColor.A));
	Window->draw(t);
}

void Graphics::ApplyCamera(Camera::SPtr cam)
{
	sf::View view;
	Vec2<float> p = cam->Position - WindowSize / 2;
	Vec2<float> s = WindowSize * cam->Scale;

	view.reset(sf::FloatRect(p.X, p.Y, s.X, s.Y));
	view.rotate(cam->Angle);
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

	Window->setView(view);
}

void Graphics::SetCamera(Camera::SPtr cam)
{
	Cam = cam;
}

void Graphics::SetDefaultCamera()
{
	Cam = std::make_shared<Camera>();
}

}