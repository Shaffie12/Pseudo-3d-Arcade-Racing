#ifndef _RACING_GAME_H_
#define _RACING_GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"
#include "Drawable.h"
#include "Player.h"
#include "Track.h"
#include "TrackData.h"
#include "Background.h"
#include "UI.h"

//this is the game state
//when start is pressed, create one of these with the track data selected, in main or previous state
//states class will hold globals such as chosen track
class RacingGame
{
	public:
		RacingGame(TrackData data);
		~RacingGame();
		//static?
		Track track; 
		Player player;
		Background bg;
		UI ui;
		std::vector<RoadObject> road_objects;
		
	
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

