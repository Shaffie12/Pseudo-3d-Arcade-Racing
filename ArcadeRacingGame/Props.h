#ifndef PROPS_H_
#define _PROPS_H_
#include "Drawable.h"
#include "GameGlobals.h"

class Props :public Drawable
{
	public:
		Props();
		void drawElement(sf::RenderWindow& w);
	private:
		std::vector<sf::Sprite> bgs;
		sf::Texture bgTex;


};


#endif 
