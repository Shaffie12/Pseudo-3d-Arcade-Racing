#include "RacingGame.h"
#include "GameGlobals.h"
#include<iostream>

float RacingGame::elapsedTime = 0;

RacingGame::RacingGame() :_MainWindow( new sf::RenderWindow(sf::VideoMode(GameGlobals::SCREEN_W,GameGlobals::SCREEN_H),"Arcade Racing") ) , _Renderer(new Renderer())
{ _MainWindow->setFramerateLimit(60); }
RacingGame::~RacingGame() { delete _MainWindow; delete _Renderer; }

void RacingGame::start()
{

	sf::Event e;
	while (_MainWindow->isOpen())
	{
		while (_MainWindow->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				_MainWindow->close();
			if (e.type == sf::Event::KeyPressed)
			{
				//i dont think this will work, because we need to sync with time dt; 
				//maybe we can set some bool here and then check for that each update cycle
				handleInput(e.key);
				std::cout << "key was pressed";
			}
		}
		

		//run the game update loop fn here
		gameLoop();


	}
}

void RacingGame::gameLoop()
{
	elapsedTime = _Clock.restart().asSeconds();
	_MainWindow->clear();
	//need to make sure to check if the window is in focus before checking for input
	
		
	_Renderer->drawLines(*_MainWindow);
	_MainWindow->display();
}

void RacingGame::handleInput(sf::Event::KeyEvent key)
{
	switch (key.code)
	{
		case(sf::Keyboard::W):
			_Renderer->addDist(elapsedTime);
			std::cout << _Renderer->getDist();
		break;

	default:
		break;

	}
}




