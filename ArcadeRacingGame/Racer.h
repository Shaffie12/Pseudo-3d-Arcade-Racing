#ifndef RACER_H_
#define RACER_H_
#include "Drawable.h"
#include "GameGlobals.h"

enum direction { f, l, r }; //use class

class Racer :public Drawable
{
	public:
		
		Racer(sf::Vector2f startPosition);
		void drawElement(sf::RenderWindow& w);
		void changeDir(direction d);

	private:
		enum direction dir;
		sf::Texture playerTex;
		std::vector<sf::Sprite> playerSprites;

};

#endif 
