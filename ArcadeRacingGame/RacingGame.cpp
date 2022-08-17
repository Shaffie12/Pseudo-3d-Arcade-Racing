#include "RacingGame.h"
#include "GameGlobals.h"
#include<iostream>

float RacingGame::elapsedTime = 0;

RacingGame::RacingGame() :_MainWindow(sf::VideoMode(GameGlobals::SCREEN_W,GameGlobals::SCREEN_H),"Arcade Racing")  , _Renderer( Renderer())
{ _MainWindow.setFramerateLimit(60); }
RacingGame::~RacingGame() { }

void RacingGame::start()
{

	sf::Event e;
	while (_MainWindow.isOpen())
	{
		while (_MainWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				_MainWindow.close();
			if (e.type == sf::Event::LostFocus)
				GameGlobals::isActiveWindow = false;
			if (e.type == sf::Event::GainedFocus)
				GameGlobals::isActiveWindow = true;
			
		}

		gameLoop();

	}
}

void RacingGame::gameLoop()
{
	elapsedTime = _Clock.restart().asSeconds();
	_MainWindow.clear();
	if(GameGlobals::isActiveWindow)
		handleInput();
		
	_Renderer.drawLines(_MainWindow);
	_Renderer.drawSprites(_MainWindow);
	_MainWindow.display();
}

void RacingGame::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_Renderer.addDist(60*elapsedTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_Renderer.updateTrackFocus(0.5 * elapsedTime, true);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_Renderer.updateTrackFocus(0.5 * elapsedTime, false);

		//i might want to make a IRenderable interface
		
	}
	
	
}
	




