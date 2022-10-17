#include "RacingGame.h"
#include "GameGlobals.h"
#include<iostream>

//this would be a state, chosen track data passed in and into the track

RacingGame::RacingGame(TrackData td) :_MainWindow(new sf::RenderWindow(sf::VideoMode(GameGlobals::SCREEN_W, GameGlobals::SCREEN_H), "Arcade Racing")), _Renderer(new Renderer()),
player(sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::GAME_H)-30)), track(Track1(td.)), bg(), ui()
{	
	roadsides.push_back(Tree());
	_MainWindow->setFramerateLimit(60);
	_Renderer->init();
	
}

RacingGame::~RacingGame() { delete _MainWindow; }

void RacingGame::start()
{

	sf::Event e;
	while (_MainWindow->isOpen())
	{
		while (_MainWindow->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				_MainWindow->close();
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
	_MainWindow->clear();
	if(GameGlobals::isActiveWindow)
		handleInput();
	
	drawAllElements(_MainWindow);

	_MainWindow->display();
}

void RacingGame::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		track.addSpeed(0.02, true);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			track.addPlayerOffset(0.012, true);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			track.addPlayerOffset(0.012, false);
			
		
	}
	else
		track.addSpeed(0.02, false);
	
	
	
}

void RacingGame::drawAllElements(sf::RenderTarget* rt)
{
	_Renderer->rtx->clear();
	
	track.drawElement(*_Renderer->rtx); 
	player.drawElement(*_Renderer->rtx); 
	bg.drawElement(*_Renderer->rtx); 
	//draw the road obj
	ui.drawElement(*_Renderer->rtx);

	
	_Renderer->rtx->display();
	_Renderer->sprite->setTexture(_Renderer->rtx->getTexture());
	_Renderer->sprite->setScale(sf::Vector2f(2, 2)); //scale using dimensions instead
	rt->draw(*_Renderer->sprite);
	
	
	



}
	




