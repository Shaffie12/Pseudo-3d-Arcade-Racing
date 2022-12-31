#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"
#include "SoundManager.h"
#include "GameState.h"
#include "TitleState.h"
#include "GameOverState.h"
#include "WinState.h"
#include"Track1.h"//remove later
#include<iostream>
#include "Util.h"
#include <memory>

class Game
{

public:
	Game();
	~Game();
	void runGameLoop();
private:
	sf::RenderWindow* mainWindow;
	sf::Event sfEvent;
	Renderer* renderer; 
	sf::Clock clock;
	float dt;
	std::stack<State*>* states;

	void initWindow();
	void updateDT();
	void pollSFEvents();
	void renderCurrentState();
	void initStates();
	State* getNextState(State* currentState);
	

};
#endif