#include "Game.h"
#include"Track1.h"//remove later
#include<iostream>

Game::Game() :mainWindow(new sf::RenderWindow(sf::VideoMode(GameGlobals::SCREEN_W, GameGlobals::SCREEN_H), "Arcade Racing")), renderer(new Renderer()),
states(new std::stack<State*>)
{
	initWindow();
	initStates();
	
}

Game::~Game()
{
	delete mainWindow;
	delete renderer;

	while (!states->empty())
	{
		//delete states->top();
		states->pop();
		
	}
	delete states;
	
	
		
}

void Game::initWindow()
{

	//can read screen size etc from a file and set those vars here/create the window here with file input/settings
	mainWindow->setFramerateLimit(60);
	renderer->init();
}

void Game::initStates()
{
	states->push(new GameState(Track1())); //we should get this from prev state, a member of this is causing crash on delete
	//states->push(new TitleState());
}

void Game::updateDT()
{
	dt = Racing::Util::roundToDP(clock.restart().asSeconds(), 2);
}

void Game::pollSFEvents()
{
	
	while (mainWindow->pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			mainWindow->close();
		if (e.type == sf::Event::LostFocus)
			GameGlobals::isActiveWindow = false;
		if (e.type == sf::Event::GainedFocus)
			GameGlobals::isActiveWindow = true;

	}
}

void Game::renderCurrentState()
{
	mainWindow->clear();
	if (GameGlobals::isActiveWindow)
		if (!states->empty())
		{
			states->top()->handleInput(dt);
			states->top()->update(dt);
			states->top()->drawToTexture(*renderer);
			mainWindow->draw(*renderer->sprite);
			mainWindow->display();
		}
		
}

void Game::runGameLoop()
{
	while (mainWindow->isOpen())
	{
		updateDT();
		pollSFEvents();
		renderCurrentState();
	}
}
