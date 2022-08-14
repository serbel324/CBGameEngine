#include "Controller.h"

Controller::Controller() {
    W = A = S = D = false;
    Lmb = Rmb = false;
    MousePos.Set(0, 0);
}

void Controller::KeyPressed(sf::Event::KeyEvent& e)
{
    switch (e.code) {
    case sf::Keyboard::W:
        W = true;
        break;
    case sf::Keyboard::A:
        A = true;
        break;
    case sf::Keyboard::S:
        S = true;
        break;
    case sf::Keyboard::D:
        D = true;
        break;
    case sf::Keyboard::Space:
        Space = true;
        break;
    }
}

void Controller::KeyReleased(sf::Event::KeyEvent& e)
{
    switch (e.code) {
    case sf::Keyboard::W:
        W = false;
        break;
    case sf::Keyboard::A:
        A = false;
        break;
    case sf::Keyboard::S:
        S = false;
        break;
    case sf::Keyboard::D:
        D = false;
        break;
    case sf::Keyboard::Space:
        Space = false;
        break;
    }
}

void Controller::MouseMoved(sf::Event::MouseMoveEvent& e)
{
    MousePos.Set(e.x, e.y);
}

void Controller::MousePressed(sf::Event::MouseButtonEvent& e)
{
    switch (e.button) {
    case sf::Mouse::Left:
        Lmb = true;
        break;
    case sf::Mouse::Right:
        Rmb = true;
        break;
    }
}

void Controller::MouseReleased(sf::Event::MouseButtonEvent& e)
{
    switch (e.button) {
    case sf::Mouse::Left:
        Lmb = false;
        break;
    case sf::Mouse::Right:
        Rmb = false;
        break;
    }
}