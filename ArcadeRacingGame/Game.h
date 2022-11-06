#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"

class Game
{
	sf::RenderWindow* _MainWindow;
	Renderer* _Renderer;
	sf::Clock _Clock;

};
#endif