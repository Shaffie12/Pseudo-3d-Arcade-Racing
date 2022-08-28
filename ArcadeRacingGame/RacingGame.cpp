#include "RacingGame.h"
#include "GameGlobals.h"
#include<iostream>


Player RacingGame::player(sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::SCREEN_H) -30));
Track RacingGame::track;

RacingGame::RacingGame() :_MainWindow(sf::VideoMode(GameGlobals::SCREEN_W,GameGlobals::SCREEN_H),"Arcade Racing")  , _Renderer( Renderer())
{ _MainWindow.setFramerateLimit(60);}


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
	GameGlobals::elapsedTime = Racing::Util::roundToDP(_Clock.restart().asSeconds(),2);
	_MainWindow.clear();
	if(GameGlobals::isActiveWindow)
		handleInput();
	//update the track based on distance 
	drawAllElements();

	_MainWindow.display();
}

void RacingGame::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		track.addSpeed(0.02, true);
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			track.offsetCenter(GameGlobals::elapsedTime, true);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			track.offsetCenter(GameGlobals::elapsedTime, false);
		*/
	}
	else
		track.addSpeed(0.02, false);
	
	
	
}

void RacingGame::drawAllElements()
{
	track.drawElement(_MainWindow);
	player.drawElement(_MainWindow);

	/*
	for (auto d : enemyCars)
		d.drawElement(_MainWindow);
		*/
}
	




