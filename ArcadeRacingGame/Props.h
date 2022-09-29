#ifndef PROPS_H_
#define _PROPS_H_
#include "Drawable.h"
#include "GameGlobals.h"

class Props :public Drawable
{
	public:
		Props();
		void drawElement(sf::RenderTarget& w);
		void scroll(float amount);
	
	private:
		std::vector<sf::Sprite> allBgs;
		sf::Texture bgTex;
		std::vector<sf::Sprite> bg;




};


#endif 
