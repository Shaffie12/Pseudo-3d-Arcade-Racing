#ifndef RACER_H_
#define RACER_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Track.h"


class Racer :public Drawable
{
	public:
		Racer(sf::Vector2f startPosition);
		void drawElement(sf::RenderTarget& w);
		void update(float amount, bool add);
		
		

	private:
		
		sf::Texture playerTex;
		std::vector<sf::Sprite> playerSprites;

};

#endif 
