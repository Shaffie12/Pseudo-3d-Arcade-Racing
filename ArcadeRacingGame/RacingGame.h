#ifndef _RACING_GAME_H_
#define _RACING_GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"

class RacingGame
{
	public:
		static float elapsedTime;

		RacingGame();
		~RacingGame();

		/*
		*should also have a copy constructorand copy assignment by convention, but since this should never be copied or assigned
		*there should only ever be 1 instance of this, maybe i 
		*should refactor it with this in mind, later ?
		*/

		void start();
		void gameLoop();
		void handleInput(sf::Event::KeyEvent e);
	private:
		//why use heap alloc for these?
		sf::RenderWindow* _MainWindow;
		Renderer* _Renderer;
		sf::Clock _Clock;
		


};

#endif

