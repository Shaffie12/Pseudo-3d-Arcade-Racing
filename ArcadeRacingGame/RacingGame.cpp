#include "RacingGame.h"
#include "Renderer.h"
#include "GameGlobals.h"


void RacingGame::start()
{

	sf::Event e;
	while (_MainWindow->isOpen())
	{
		while (_MainWindow->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				_MainWindow->close();
		}
		_MainWindow->clear();

		Renderer::drawLines(*_MainWindow);
		_MainWindow->display();

	}
}

RacingGame::RacingGame() :_MainWindow{ new sf::RenderWindow(sf::VideoMode(GameGlobals::screen_w,GameGlobals::screen_h),"Arcade Racing") } {}

RacingGame::~RacingGame() { delete _MainWindow; }