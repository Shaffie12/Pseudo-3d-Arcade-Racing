#ifndef _RACING_GAME_H_
#define _RACING_GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"
#include "Drawable.h"
#include "Player.h"
#include "Track1.h"
#include "Track.h"
#include "Background.h"
#include "UI.h"


class RacingGame
{
	public:
		RacingGame(TrackData td);
		~RacingGame();
		//static?
		Track track; 
		Player player;
		Background bg;
		UI ui;
		

		void start();
		void gameLoop();
		void handleInput();
		void drawAllElements(sf::RenderTarget* rt);
	private:
		sf::RenderWindow* _MainWindow;
		Renderer*_Renderer;
		sf::Clock _Clock;
		
		
		
		


};

#endif

