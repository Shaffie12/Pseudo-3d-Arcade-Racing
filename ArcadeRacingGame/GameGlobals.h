#ifndef _GAME_GLOBALS_H_
#define _GAME_GLOBALS_H_

#include <SFML/System/Clock.hpp>
#include<SFML/Graphics/Sprite.hpp>
#include<vector>

	class GameGlobals
	{
	public:
		static const float SCREEN_W, SCREEN_H;
		static const int DT_MULTIPLIER;
		static bool isActiveWindow; //maybe getter and setter for this
		static float elapsedTime;
		


	};



#endif