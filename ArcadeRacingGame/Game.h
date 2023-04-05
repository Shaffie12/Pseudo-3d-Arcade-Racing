#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "SoundManager.h"
#include "FontsManager.h"
#include "GameState.h"
#include "TitleState.h"
#include "LeaderboardState.h"
#include "OptionsState.h"
#include "GameOverState.h"
#include "WinState.h"
#include"Track1.h"
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
	const sf::String* username;
	sf::Joystick stick;

	void initWindow();
	void updateDT();
	void pollSFEvents();
	void renderCurrentState();
	void initStates();
	void setVolumesFromFile();
	void setControlsFromFile();
	State* getNextState(State* currentState);
	

};
#endif