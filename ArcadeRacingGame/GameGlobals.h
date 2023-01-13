#ifndef _GAME_GLOBALS_H_
#define _GAME_GLOBALS_H_
#include <string>
#include <SFML/System/Clock.hpp>
#include<SFML/Graphics/Sprite.hpp>
#include<vector>

class GameGlobals
{
public:
	static const float SCREEN_W, SCREEN_H, GAME_W, GAME_H, GAME_ASPECT;
	static bool isActiveWindow; 
	static float elapsedTime;
};
#endif

