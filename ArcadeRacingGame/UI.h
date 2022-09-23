#ifndef UI_H_
#define UI_H_
#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Track.h"
#include <string>

class UI : public Drawable
{
	public:
		UI();
		void drawElement(sf::RenderTarget& w);


	private:
		
		sf::Font textFont;
		sf::Text playerSpeed;
		sf::Text distanceTravelled;

};


#endif 
