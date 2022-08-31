#ifndef RACER_H_
#define RACER_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Track.h"

enum direction { f, l, r }; //use class

class Racer :public Drawable
{
	public:
		Racer(sf::Vector2f startPosition);
		void drawElement(sf::RenderWindow& w);
		void updateCurvature(float amount, bool add);
		float getCurvature();
		

	private:
		float playerCurvature = 0;
		sf::Texture playerTex;
		std::vector<sf::Sprite> playerSprites;

};

#endif 
