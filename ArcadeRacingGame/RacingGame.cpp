#include "RacingGame.h"
#include "Renderer.h"
#include "GameGlobals.h"


RacingGame::RacingGame() :_MainWindow{ new sf::RenderWindow(sf::VideoMode(GameGlobals::screen_w,GameGlobals::screen_h),"Arcade Racing") } {}
RacingGame::~RacingGame() { delete _MainWindow; }

void RacingGame::start()
{

	sf::Event e;
	Renderer r;
	while (_MainWindow->isOpen())
	{
		while (_MainWindow->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				_MainWindow->close();
		}
		_MainWindow->clear();

		r.drawLines(*_MainWindow);
		_MainWindow->display();

	}
}



