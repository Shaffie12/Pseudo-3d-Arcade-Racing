#ifndef _RACING_GAME_H_
#define _RACING_GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"
#include "Drawable.h"
#include "Player.h"
#include "TrackData.h"
#include "Track.h"
#include "Background.h"
#include "Tree.h"
#include "UI.h"

class RacingGame
{
	public:
		//i think these should be static because there should only be 1 of these ever in a game
		
		Track track; 
		Player player;
		Background bg;
		UI ui;
		std::vector<Tree> roadsides;
		
		std::vector<Drawable> enemyCars;
		
		RacingGame();
		~RacingGame();

		/*
		*should also have a copy constructorand copy assignment by convention, but since this should never be copied or assigned
		*there should only ever be 1 instance of this, the player and the track
		*
		*/

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

