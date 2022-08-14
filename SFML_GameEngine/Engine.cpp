#include "Engine.h"

#include <fstream>
#include <cstdlib>
#include <ctime>

#include <chrono>

Engine::Engine()
{
	Config();
	SFMLInit();

	Gr = std::make_shared<Graphics>(Window, WindowSize);
	Camera::SPtr cam = std::make_shared<Camera>(WindowSize / 2, 0, 1); /* Camera with center in upper left Angle */
	Gr->ApplyCamera(cam);

	Init();

	while (Window->isOpen())
	{
		MainLoop();
	}

	Close();
}

Engine::~Engine()
{
}

void Engine::SFMLInit()
{
	Window = std::make_shared<sf::RenderWindow>(
		sf::VideoMode(WindowSize.X, WindowSize.Y), 
		"Unnamed", 
		sf::Style::Close);
}

void Engine::Config()
{
	/* default screen resolution is 800x800 */
	WindowSize = Vec2<int>(800, 800);
	TickTime = 10;
}

void Engine::Init()
{
	Control = std::make_shared<Controller>();
}

void Engine::Tick()
{
}

void Engine::Render()
{
	Gr->SetFillColor(Color(20));
	Gr->Fill();

	/* ...  */

	Gr->Present();
}


void Engine::Events()
{
	sf::Event e;
	while (Window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			Window->close();
			break;
		case sf::Event::KeyPressed:
			KeyPressed(e.key);
			Control->KeyPressed(e.key);
			break;
		case sf::Event::KeyReleased:
			Control->KeyPressed(e.key);
			break;
		case sf::Event::MouseButtonPressed:
			Control->MousePressed(e.mouseButton);
			break;
		case sf::Event::MouseButtonReleased:
			Control->MouseReleased(e.mouseButton);
			break;
		case sf::Event::MouseMoved:
			Control->MouseMoved(e.mouseMove);
			break;
		}
	}
}

void Engine::KeyPressed(sf::Event::KeyEvent key)
{
	if (key.code == sf::Keyboard::Escape)
	{
		Window->close();
	}
}

void Engine::MousePressed(sf::Event::MouseButtonEvent mouse)
{
}

void Engine::MainLoop()
{
	sf::Clock clock;

	Events();
	Tick();
	Render();

	sf::Time t = clock.getElapsedTime();

	if (t.asMilliseconds() < TickTime)
	{
		sf::sleep(sf::milliseconds(TickTime - t.asMilliseconds()));
	}
}

void Engine::Close()
{
}
