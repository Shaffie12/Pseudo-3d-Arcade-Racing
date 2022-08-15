#ifndef _RACING_GAME_H_
#define _RACING_GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>

class RacingGame
{
	public:
		RacingGame();
		~RacingGame();

		void start();
	private:
		sf::RenderWindow* _MainWindow;


};

#endif // !_RACING_GAME_MAIN_H_

