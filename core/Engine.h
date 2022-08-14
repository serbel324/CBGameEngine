#pragma once

#include <vector>
#include <memory>

#include <util/Vec2.h>
#include <core/Graphics.h>
#include <core/Controller.h>
#include <core/Camera.h>

#include <SFML/Graphics.hpp>

namespace CBGE {

using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;

/* Main class, contains renderer, event handlers and main logic */
class Engine
{
public:
	Engine();
	~Engine();

private:
	Vec2<int> WindowSize;

	/* minimal time in ms for main_loop() iteration */
	float TickTime;


	Graphics::SPtr Gr;
	std::shared_ptr<sf::RenderWindow> Window;

	Controller::SPtr Control;


	/* ======== METHODS ======== */

	/* initialize SFML, create main Window */
	void SFMLInit();

	/* Set properties, load configs */
	void Config();

	/* reset all variables to initial values */
	void Init();

	/* update */
	void Tick();
	
	/* draw */
	void Render();

	/* handle Events */
	void Events();

	void KeyPressed(sf::Event::KeyEvent key);
	void MousePressed(sf::Event::MouseButtonEvent mouse);

	/* main loop iteration */
	void MainLoop();

	/* after main Window is closed */
	void Close();
};

}