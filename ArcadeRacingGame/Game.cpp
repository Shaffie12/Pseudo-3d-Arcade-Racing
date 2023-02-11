#include "Game.h"


Game::Game() :mainWindow(new sf::RenderWindow(sf::VideoMode(GameGlobals::SCREEN_W, GameGlobals::SCREEN_H), "Arcade Racing")), renderer(new Renderer()),
states(new std::stack<State*>)
{
	srand(time(NULL));
	initWindow();
	initStates();
	
}

Game::~Game()
{
	delete mainWindow;
	delete renderer;

	while (!states->empty())
		states->pop();	
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
	FontsManager::GetInstance();
	SoundManager::GetInstance();
	setVolumesFromFile();
	TitleState* ts = new TitleState();
	username = &ts->userName.text.getString();
	states->push(ts);
	
	
}

void Game::setVolumesFromFile()
{ 
	SettingsSaveData soundSave;

	SoundManager::GetInstance()->menuNavigate.setVolume(soundSave.getSfxVolume()*100.0f);
	SoundManager::GetInstance()->menuSelect.setVolume(soundSave.getSfxVolume()*100.0f);
	SoundManager::GetInstance()->beep_1.setVolume(soundSave.getSfxVolume()*100.0f);
	SoundManager::GetInstance()->checkpoint.setVolume(soundSave.getSfxVolume()*100.0f);
	SoundManager::GetInstance()->explosion.setVolume(soundSave.getSfxVolume()*100.0f);

	SoundManager::GetInstance()->trackMusic1.setVolume(soundSave.getMusicVolume()*100.0f);
}

void Game::updateDT()
{
	dt = Racing::Util::roundToDP(clock.restart().asSeconds(), 2);
}

void Game::pollSFEvents()
{
	
	while (mainWindow->pollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
			mainWindow->close();
		if (sfEvent.type == sf::Event::LostFocus)
			GameGlobals::isActiveWindow = false;
		if (sfEvent.type == sf::Event::GainedFocus)
			GameGlobals::isActiveWindow = true;
		if(!states->empty())
			states->top()->handleInput(sfEvent);
	}
	
}

void Game::renderCurrentState()
{
	mainWindow->clear();
	if (GameGlobals::isActiveWindow)
		if (!states->empty())
		{
			if (!states->top()->exited)
			{
				states->top()->update(dt);
				states->top()->drawToTexture(*renderer);
				mainWindow->draw(*renderer->sprite);
				mainWindow->display();
			}
			else
			{
				int nextState = states->top()->nextState();
				

				if (nextState > 0) //means we will push a new state
				{
					State* s = getNextState(states->top());
					states->top()->exited = false;
					states->push(s);
				}	
				else //means we will pop the state only to get to a previous one
				{
					for (int i = 0; i > nextState; i--)
						states->pop();	
				}	
			}
			
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

State* Game::getNextState(State* currentState)
{
	if (GameState* gs = dynamic_cast<GameState*>(currentState))
	{
		if (gs->nextState() == 1)
		{
			if (username->toAnsiString() != "___")
				return new WinState(gs->raceTimer, username->toAnsiString());
			return new WinState(gs->raceTimer);
		}
		return new GameOverState();

	}
	else if (TitleState* gs = dynamic_cast<TitleState*>(currentState))
	{
		if (gs->nextState() == 1)
			return new GameState(Track1());
		else if (gs->nextState() == 2)
			return new LeaderboardState();
		else if (gs->nextState() == 3)
			return new OptionsState(SoundManager::GetInstance()->beep_1.getVolume()*0.01f,SoundManager::GetInstance()->trackMusic1.getVolume()*0.01f);

	}
}
	
